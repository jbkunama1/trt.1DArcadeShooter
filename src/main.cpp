/*
 * trt.1DArcadeShooter
 * 1D-Arcade-Shooter für ESP32 (NodeMCU) mit WS2812B-LED-Strip
 * 
 * Basierend auf: 1D-RGB-Invaders von worksasdesigned
 * Portierung: ESP32-S3 → ESP32 (NodeMCU), Audio entfernt
 * 
 * Pin-Belegung:
 * - LED-Strip Data: GPIO 2
 * - Button Rot: GPIO 4
 * - Button Grün: GPIO 5
 * - Button Blau: GPIO 12
 * - Menu-Button: GPIO 13
 */

#include <FastLED.h>
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <ArduinoJson.h>

// ==================== KONFIGURATION ====================

#define LED_PIN 2
#define BUTTON_RED 4
#define BUTTON_GREEN 5
#define BUTTON_BLUE 12
#define MENU_BUTTON 13

#define NUM_LEDS 120          // Anzahl LEDs im Strip
#define LED_TYPE WS2812B
#define COLOR_ORDER GRB
#define BRIGHTNESS 128        // 0-255

#define PLAYER_START_POS 5    // Spieler startet bei LED 5
#define ENEMY_START_POS 100   // Gegner startet bei LED 100

// ==================== GLOBALE VARIABLEN ====================

CRGB leds[NUM_LEDS];

// Spieler
int playerPos = PLAYER_START_POS;
int playerColor = 0; // 0=Rot, 1=Grün, 2=Blau

// Gegner
struct Enemy {
  int pos;
  int color; // 0=Rot, 1=Grün, 2=Blau
  int length; // Anzahl LEDs
  int speed; // Pixel pro Frame
  bool active;
};

#define MAX_ENEMIES 15
Enemy enemies[MAX_ENEMIES];
int activeEnemies = 0;

// Projektile
struct Projectile {
  int pos;
  int color;
  int speed;
  bool active;
};

#define MAX_PROJECTILES 10
Projectile projectiles[MAX_PROJECTILES];

// Spielstatus
bool gameRunning = false;
int level = 1;
int score = 0;
int highScore = 0;
unsigned long lastFrameTime = 0;
int frameDelay = 50; // ms zwischen Frames (niedriger = schneller)

// Buttons
bool btnRedPressed = false;
bool btnGreenPressed = false;
bool btnBluePressed = false;
bool btnMenuPressed = false;

// Web-Server
AsyncWebServer server(80);
bool wifiStarted = false;

// ==================== FUNKTIONEN ====================

void setupLEDs() {
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.clear();
  FastLED.show();
}

void setupButtons() {
  pinMode(BUTTON_RED, INPUT_PULLUP);
  pinMode(BUTTON_GREEN, INPUT_PULLUP);
  pinMode(BUTTON_BLUE, INPUT_PULLUP);
  pinMode(MENU_BUTTON, INPUT_PULLUP);
}

void resetGame() {
  playerPos = PLAYER_START_POS;
  score = 0;
  level = 1;
  activeEnemies = 0;
  
  // Alle Projektile deaktivieren
  for (int i = 0; i < MAX_PROJECTILES; i++) {
    projectiles[i].active = false;
  }
  
  // Ersten Gegner spawnen
  spawnEnemy();
}

void spawnEnemy() {
  if (activeEnemies >= MAX_ENEMIES) return;
  
  // Nächsten freien Slot finden
  int slot = -1;
  for (int i = 0; i < MAX_ENEMIES; i++) {
    if (!enemies[i].active) {
      slot = i;
      break;
    }
  }
  
  if (slot == -1) return;
  
  // Gegner konfigurieren
  enemies[slot].pos = ENEMY_START_POS;
  enemies[slot].color = random(0, 3); // 0=Rot, 1=Grün, 2=Blau
  enemies[slot].length = 1 + (level / 2); // Wird mit Level länger
  enemies[slot].speed = 1 + (level / 3); // Wird mit Level schneller
  enemies[slot].active = true;
  activeEnemies++;
}

void updateGame() {
  if (!gameRunning) return;
  
  // Gegner bewegen
  for (int i = 0; i < MAX_ENEMIES; i++) {
    if (enemies[i].active) {
      enemies[i].pos -= enemies[i].speed;
      
      // Game Over wenn Gegner Spieler erreicht
      if (enemies[i].pos <= playerPos + enemies[i].length) {
        gameRunning = false;
        if (score > highScore) highScore = score;
        level = 1;
      }
    }
  }
  
  // Projektile bewegen
  for (int i = 0; i < MAX_PROJECTILES; i++) {
    if (projectiles[i].active) {
      projectiles[i].pos += projectiles[i].speed;
      
      // Projektil entfernen wenn außerhalb
      if (projectiles[i].pos >= NUM_LEDS) {
        projectiles[i].active = false;
      }
      
      // Kollision mit Gegnern prüfen
      for (int j = 0; j < MAX_ENEMIES; j++) {
        if (enemies[j].active && 
            projectiles[i].pos >= enemies[j].pos &&
            projectiles[i].pos < enemies[j].pos + enemies[j].length &&
            projectiles[i].color == enemies[j].color) {
          
          // Treffer! Gegner entfernen
          enemies[j].active = false;
          activeEnemies--;
          projectiles[i].active = false;
          score += 10;
          
          // Nächster Gegner
          if (activeEnemies == 0) {
            level++;
            frameDelay = max(20, frameDelay - 5); // Schneller pro Level
            spawnEnemy();
            spawnEnemy(); // Mehr Gegner pro Level
          }
          break;
        }
      }
    }
  }
  
  // Neue Gegner spawnen wenn alle besiegt
  if (activeEnemies == 0 && gameRunning) {
    spawnEnemy();
    spawnEnemy();
  }
}

void drawGame() {
  FastLED.clear();
  
  // Spieler zeichnen
  leds[playerPos] = CRGB::White;
  
  // Gegner zeichnen
  for (int i = 0; i < MAX_ENEMIES; i++) {
    if (enemies[i].active) {
      for (int j = 0; j < enemies[i].length; j++) {
        int ledIndex = enemies[i].pos + j;
        if (ledIndex >= 0 && ledIndex < NUM_LEDS) {
          if (enemies[i].color == 0) leds[ledIndex] = CRGB::Red;
          else if (enemies[i].color == 1) leds[ledIndex] = CRGB::Green;
          else if (enemies[i].color == 2) leds[ledIndex] = CRGB::Blue;
        }
      }
    }
  }
  
  // Projektile zeichnen
  for (int i = 0; i < MAX_PROJECTILES; i++) {
    if (projectiles[i].active) {
      if (projectiles[i].pos >= 0 && projectiles[i].pos < NUM_LEDS) {
        if (projectiles[i].color == 0) leds[projectiles[i].pos] = CRGB::Red;
        else if (projectiles[i].color == 1) leds[projectiles[i].pos] = CRGB::Green;
        else if (projectiles[i].color == 2) leds[projectiles[i].pos] = CRGB::Blue;
      }
    }
  }
  
  FastLED.show();
}

void fireProjectile(int color) {
  if (!gameRunning) return;
  
  // Nächstes freies Projektil finden
  for (int i = 0; i < MAX_PROJECTILES; i++) {
    if (!projectiles[i].active) {
      projectiles[i].pos = playerPos + 1;
      projectiles[i].color = color;
      projectiles[i].speed = 3 + (level / 2);
      projectiles[i].active = true;
      break;
    }
  }
}

void checkButtons() {
  // Buttons auslesen (LOW = gedrückt bei INPUT_PULLUP)
  bool redNow = (digitalRead(BUTTON_RED) == LOW);
  bool greenNow = (digitalRead(BUTTON_GREEN) == LOW);
  bool blueNow = (digitalRead(BUTTON_BLUE) == LOW);
  bool menuNow = (digitalRead(MENU_BUTTON) == LOW);
  
  // Flankenerkennung (nur bei Loslassen auslösen)
  if (!btnRedPressed && redNow) {
    fireProjectile(0); // Rot
  }
  if (!btnGreenPressed && greenNow) {
    fireProjectile(1); // Grün
  }
  if (!btnBluePressed && blueNow) {
    fireProjectile(2); // Blau
  }
  if (!btnMenuPressed && menuNow) {
    // Spiel starten/stoppen
    gameRunning = !gameRunning;
    if (gameRunning) {
      resetGame();
    }
  }
  
  // Status speichern
  btnRedPressed = redNow;
  btnGreenPressed = greenNow;
  btnBluePressed = blueNow;
  btnMenuPressed = menuNow;
}

void setupWebServer() {
  // Access Point starten
  WiFi.softAP("1DArcadeShooter", "arcade123");
  wifiStarted = true;
  
  // Web-Server Routen
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    String html = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>1D Arcade Shooter</title>
  <style>
    body { font-family: Arial, sans-serif; background: #1a1a1a; color: #fff; padding: 20px; }
    h1 { color: #00ff00; }
    .stat { margin: 10px 0; font-size: 1.2em; }
    button { padding: 15px 30px; font-size: 1.2em; margin: 10px; cursor: pointer; }
    .btn-start { background: #00ff00; color: #000; border: none; }
    .btn-stop { background: #ff0000; color: #fff; border: none; }
  </style>
</head>
<body>
  <h1>🕹️ 1D Arcade Shooter</h1>
  <div class="stat">🎮 Spiel: <span id="gameStatus">STOP</span></div>
  <div class="stat">🏆 Score: <span id="score">0</span></div>
  <div class="stat">📊 Level: <span id="level">1</span></div>
  <div class="stat">👑 Highscore: <span id="highScore">0</span></div>
  <button class="btn-start" onclick="startGame()">▶️ Start</button>
  <button class="btn-stop" onclick="stopGame()">⏹️ Stop</button>
  <script>
    function updateStats() {
      fetch('/api/status').then(r => r.json()).then(data => {
        document.getElementById('gameStatus').textContent = data.running ? 'LÄUFT' : 'STOP';
        document.getElementById('score').textContent = data.score;
        document.getElementById('level').textContent = data.level;
        document.getElementById('highScore').textContent = data.highScore;
      });
    }
    function startGame() { fetch('/api/start'); updateStats(); }
    function stopGame() { fetch('/api/stop'); updateStats(); }
    setInterval(updateStats, 1000);
    updateStats();
  </script>
</body>
</html>
)rawliteral";
    request->send(200, "text/html", html);
  });
  
  server.on("/api/status", HTTP_GET, [](AsyncWebServerRequest *request){
    String json = "{\"running\":" + String(gameRunning ? "true" : "false") + 
                  ",\"score\":" + String(score) + 
                  ",\"level\":" + String(level) + 
                  ",\"highScore\":" + String(highScore) + "}";
    request->send(200, "application/json", json);
  });
  
  server.on("/api/start", HTTP_GET, [](AsyncWebServerRequest *request){
    gameRunning = true;
    resetGame();
    request->send(200, "text/plain", "OK");
  });
  
  server.on("/api/stop", HTTP_GET, [](AsyncWebServerRequest *request){
    gameRunning = false;
    request->send(200, "text/plain", "OK");
  });
  
  server.begin();
}

void setup() {
  Serial.begin(115200);
  
  setupLEDs();
  setupButtons();
  setupWebServer();
  
  // Begrüßungseffekt
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Green;
    FastLED.show();
    delay(10);
  }
  delay(500);
  FastLED.clear();
  FastLED.show();
  
  Serial.println("1D Arcade Shooter gestartet!");
  Serial.println("WLAN: 1DArcadeShooter / arcad123");
  Serial.println("Web-Interface: http://192.168.4.1");
}

void loop() {
  // Buttons prüfen
  checkButtons();
  
  // Spiel aktualisieren (mit Frame-Rate-Begrenzung)
  unsigned long currentTime = millis();
  if (currentTime - lastFrameTime >= frameDelay) {
    updateGame();
    drawGame();
    lastFrameTime = currentTime;
  }
  
  // Kurze Pause
  delay(5);
}