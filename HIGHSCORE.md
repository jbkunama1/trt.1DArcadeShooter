# Persistenter Highscore – trt.1DArcadeShooter

Diese Ergänzung zeigt, wie du den Highscore dauerhaft speicherst, sodass er nach einem Neustart erhalten bleibt.

## Ziel

Der Highscore soll:

- nach Power-Off erhalten bleiben
- beim Start geladen werden
- optional über das Webinterface zurückgesetzt werden können

## Sinnvolle Speicheroptionen

### EEPROM

Gut für:

- kleine Datenmengen
- einfache Speicherung eines einzelnen Highscores

### SPIFFS / LittleFS

Gut für:

- mehrere Datensätze
- strukturierte Dateien
- spätere Erweiterungen

Empfehlung für dieses Projekt:

- zuerst EEPROM für den einfachen Highscore
- später LittleFS für mehrere Highscores oder Statistiken

## Beispiel mit EEPROM

```cpp
#include <EEPROM.h>

#define EEPROM_SIZE 16
#define HIGHSCORE_ADDR 0

void setupStorage() {
  EEPROM.begin(EEPROM_SIZE);
}

int loadHighScore() {
  int value = 0;
  EEPROM.get(HIGHSCORE_ADDR, value);
  return value;
}

void saveHighScore(int value) {
  EEPROM.put(HIGHSCORE_ADDR, value);
  EEPROM.commit();
}
```

## Einbindung in die Spiellogik

Beim Start:

- `highScore = loadHighScore();`

Beim Spielende:

- wenn `score > highScore`, dann `saveHighScore(score);`

## Optional: Reset-Funktion

Über den Menu-Button oder das Webinterface:

- Highscore auf 0 setzen
- sofort speichern
- Anzeige aktualisieren

## Unterrichtliche Lernziele

- persistente Speicherung verstehen
- Unterschied zwischen RAM und Flash erklären
- mit Zustandsspeicherung und Datenintegrität arbeiten

## Erweiterungsideen

- Top-3-Highscores speichern
- Spielernamen speichern
- Statistiken je Level
- Export als JSON-Datei

## Abnahmekriterien

- Highscore überlebt Neustart
- keine falschen Werte nach Reset
- Speicherung erfolgt nur bei Bedarf
- Webinterface zeigt korrekten Stand
