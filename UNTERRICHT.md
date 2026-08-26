# Unterrichtsmaterial – trt.1DArcadeShooter

## Einsatz im Unterricht

Das Projekt eignet sich für verschiedene Fächer und Klassenstufen:

| Fach | Klasse | Kompetenzen |
|---|---|---|
| Technik | 8–10 | Schaltpläne, Stromkreise, Löten |
| Informatik | 9–11 | Programmierung, Algorithmen, Web-Entwicklung |
| WBS/BO | 7–9 | Projektplanung, Dokumentation |
| Medienbildung | 7–9 | Spielmechanik, UI/UX |

## Projektphasen (4–6 Wochen)

### Woche 1: Einführung & Planung

**Ziele:**
- Projekt verstehen
- Hardware-Liste erstellen
- Zeitplan machen

**Aktivitäten:**
- Video zeigen (1D RGB Invaders)
- Schaltplan besprechen
- Einkaufsliste gemeinsam erstellen

**Material:**
- README.md
- SCHALTPLAN.md

### Woche 2: Hardware aufbauen

**Ziele:**
- ESP32 einrichten
- Erste LED zum Leuchten bringen
- Buttons testen

**Aktivitäten:**
- Arduino IDE installieren
- FastLED-Testprogramm
- Button-Test mit Serial Monitor

**Code-Beispiel (LED-Test):**
```cpp
#include <FastLED.h>

#define LED_PIN 2
#define NUM_LEDS 120

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(50);
}

void loop() {
  leds[0] = CRGB::Red;
  FastLED.show();
  delay(1000);
  FastLED.clear();
  FastLED.show();
  delay(1000);
}
```

### Woche 3: Spiellogik verstehen

**Ziele:**
- Code-Struktur verstehen
- Spielmechanik analysieren
- Eigene Ideen entwickeln

**Aktivitäten:**
- Code gemeinsam lesen
- Flowchart zeichnen
- Schwierigkeitsgrade diskutieren

**Aufgaben:**
1. Zeichne ein Flowchart des Spiels
2. Erkläre, wie Kollisionserkennung funktioniert
3. Überlege: Wie wird das Spiel schwerer?

### Woche 4: Eigene Anpassungen

**Ziele:**
- Code modifizieren
- Eigene Features implementieren
- Testen und Debuggen

**Ideen für Anpassungen:**

| Schwierigkeit | Aufgabe |
|---|---|
| Einfach | Farben ändern, Helligkeit anpassen |
| Mittel | Neue Gegner-Typen, Power-Ups |
| Schwer | Zweispieler-Modus, Sound |

**Beispiel (Farbe ändern):**
```cpp
// Spieler statt weiß jetzt gelb
leds[playerPos] = CRGB::Yellow;

// Gegner statt RGB auch Cyan/Magenta
if (enemies[i].color == 0) leds[ledIndex] = CRGB::Cyan;
```

### Woche 5: Dokumentation

**Ziele:**
- README schreiben
- Schaltplan dokumentieren
- Präsentation vorbereiten

**Checkliste:**
- [ ] Hardware-Liste vollständig
- [ ] Schaltplan verständlich
- [ ] Code-Kommentare vorhanden
- [ ] Fehlerbehebung dokumentiert

### Woche 6: Präsentation & Wettbewerb

**Ziele:**
- Projekt vorstellen
- Highscore-Wettbewerb
- Reflexion

**Ablauf:**
1. Jede Gruppe stellt ihr Projekt vor (5 Min)
2. Gemeinsamer Highscore-Wettbewerb
3. Reflexion: Was war schwierig? Was lief gut?

## Differenzierung

### Für schnelle Schüler

- **Zusätzliche Features:**
  - Power-Ups (Mehrfachschuss, Unverwundbarkeit)
  - Boss-Kämpfe alle 5 Level
  - Partikel-Effekte bei Explosionen
  
- **Optimierung:**
  - Speichernutzung reduzieren
  - Frame-Rate erhöhen
  - Web-Interface erweitern

### Für langsamere Schüler

- **Vereinfachungen:**
  - Vorgegebene Code-Snippets
  - Schritt-für-Schritt-Anleitung
  - Partnerarbeit

- **Reduzierte Ziele:**
  - Nur 1 Button statt 3
  - Feste Gegner-Farbe
  - Kein Web-Interface

## Bewertung

| Kriterium | Punkte | Beschreibung |
|---|---|---|
| Hardware funktioniert | 20 | LEDs, Buttons, WLAN |
| Code läuft | 30 | Spiel startet, spielbar |
| Eigene Anpassung | 20 | Mindestens 1 Feature geändert |
| Dokumentation | 20 | README, Schaltplan |
| Präsentation | 10 | Vorstellung vor Klasse |
| **Gesamt** | **100** | |

## Arbeitsblätter (Vorlagen)

### Arbeitsblatt 1: Schaltplan verstehen

**Aufgabe:** Zeichne die Verdrahtung nach

```
ESP32 GPIO 2 ──[330Ω]──> LED-Strip DIN
ESP32 GPIO 4 ──> Button Rot
ESP32 GPIO 5 ──> Button Grün
ESP32 GPIO 12 ──> Button Blau
ESP32 GPIO 13 ──> Menu-Button
ESP32 GND ──> Alle GNDs verbinden
ESP32 5V ──> Buttons (optional)
Extern 5V ──> LED-Strip VCC
```

**Fragen:**
1. Warum braucht der LED-Strip ein eigenes Netzteil?
2. Wozu dient der 330Ω-Widerstand?
3. Was passiert, wenn GND nicht verbunden ist?

### Arbeitsblatt 2: Code-Analyse

**Aufgabe:** Lies den Code und beantworte:

```cpp
void updateGame() {
  if (!gameRunning) return;
  
  // Gegner bewegen
  for (int i = 0; i < MAX_ENEMIES; i++) {
    if (enemies[i].active) {
      enemies[i].pos -= enemies[i].speed;
      // ...
    }
  }
}
```

**Fragen:**
1. Was macht `if (!gameRunning) return;`?
2. Warum wird `enemies[i].pos -= enemies[i].speed;` verwendet?
3. Was passiert bei `gameRunning = false;`?

### Arbeitsblatt 3: Eigene Idee

**Aufgabe:** Entwickle ein eigenes Feature

**Template:**
```
Feature-Name: _______________

Beschreibung:
_________________________________
_________________________________

Umsetzung (Code-Idee):
_________________________________
_________________________________

Schwierigkeit: □ Einfach  □ Mittel  □ Schwer
```

## Sicherheit im Unterricht

**Hinweise:**
- Löten nur unter Aufsicht
- 5V-Netzteile sind ungefährlich, aber Kurzschlüsse vermeiden
- Heiße Lötkolben nicht berühren
- Immer erst Strom aus, dann umbauen

**Checkliste vor dem Einschalten:**
- [ ] Alle GNDs verbunden?
- [ ] 5V nicht mit GPIO verbunden?
- [ ] Keine blanken Kabelenden?
- [ ] Netzteil richtig gepolt?

## Links & Ressourcen

- **Originalprojekt:** https://github.com/worksasdesigned/1D-RGB-Invader
- **FastLED-Doku:** https://fastled.io/
- **ESP32-Tutorials:** https://randomnerdtutorials.com/esp32-tutorials/
- **Wokwi-Simulator:** https://wokwi.com/ (ESP32 online testen)