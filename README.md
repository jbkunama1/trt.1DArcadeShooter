# trt.1DArcadeShooter

Ein 1D-Arcade-Shooter für ESP32 (NodeMCU) mit WS2812B-LED-Strip. Inspiriert von Space Invaders – aber in einer Dimension!

## Spielprinzip

- Gegner-LEDs kommen von rechts auf dich zu
- Du steuerst eine LED (dein Schiff) am linken Ende
- Mit 3 Buttons (Rot, Grün, Blau) schießt du Projektile in der passenden Farbe
- Nur farbgleiche Treffer zerstören den Gegner
- Mit jedem Level: mehr Gegner, schneller, länger

## Hardware

| Komponente | Menge | Hinweise |
|---|---|---|
| ESP32 (NodeMCU-32S) | 1 | Auch ESP32-S3 möglich |
| WS2812B LED-Strip | 1 | 60–240 LEDs, 5V |
| Arcade-Button Rot | 1 | 60mm empfohlen |
| Arcade-Button Grün | 1 | 60mm empfohlen |
| Arcade-Button Blau | 1 | 60mm empfohlen |
| Menu-Button | 1 | 12mm Taster |
| 5V-Netzteil | 1 | ≥3A, USB-C oder DC |
| Breadboard + Kabel | 1 | Zum Verdrahten |

## Pin-Belegung (ESP32 NodeMCU)

| Funktion | GPIO | Hinweis |
|---|---|---|
| LED-Strip Data | GPIO 2 | 330Ω Vorwiderstand empfohlen |
| Button Rot | GPIO 4 | Mit 10kΩ Pull-Down gegen GND |
| Button Grün | GPIO 5 | Mit 10kΩ Pull-Down gegen GND |
| Button Blau | GPIO 12 | Mit 10kΩ Pull-Down gegen GND |
| Menu-Button | GPIO 13 | Mit 10kΩ Pull-Down gegen GND |
| 5V LED-Strip | 5V (extern) | **Nicht** über ESP32! |
| GND (alle) | GND | Gemeinsam verbinden |

## Verdrahtung

```
ESP32 NodeMCU:
  GPIO 2  ──[330Ω]──> DIN (LED-Strip)
  GPIO 4  ──> Button Rot (andere Seite → GND)
  GPIO 5  ──> Button Grün (andere Seite → GND)
  GPIO 12 ──> Button Blau (andere Seite → GND)
  GPIO 13 ──> Menu-Button (andere Seite → GND)
  5V      ──> VCC (LED-Strip, extern!)
  GND     ──> GND (LED-Strip, Buttons, extern)
```

**Wichtig:** Der LED-Strip wird **direkt vom 5V-Netzteil** versorgt, nicht über den ESP32! Alle GNDs müssen gemeinsam verbunden sein.

## Software

### Benötigte Bibliotheken (Arduino IDE)

1. **FastLED** (≥3.7.0)
2. **ESPAsyncWebServer** (GitHub: https://github.com/me-no-dev/ESPAsyncWebServer)
3. **ESPAsyncTCP** (GitHub: https://github.com/me-no-dev/ESPAsyncTCP)

Installation:
- Bibliotheksverwalter → FastLED suchen → installieren
- Für ESPAsyncWebServer: ZIP von GitHub herunterladen → Bibliothek → ZIP-Bibliothek hinzufügen

### Code kompilieren und hochladen

1. `src/main.cpp` in Arduino IDE öffnen
2. Board: **ESP32 Dev Module** wählen
3. Port wählen
4. Kompilieren und hochladen

### Web-Interface

Nach dem Start öffnet das Projekt einen WLAN-Access-Point:
- **SSID:** `1DArcadeShooter`
- **Passwort:** `arcade123`

Im Browser: `http://192.168.4.1`

Dort kannst du:
- Spiel starten/stoppen
- Schwierigkeitsgrad einstellen
- Highscores ansehen

## Spielsteuerung

| Button | Funktion |
|---|---|
| Rot | Rotes Projektil schießen |
| Grün | Grünes Projektil schießen |
| Blau | Blaues Projektil schießen |
| Menu | Spiel starten / Menü navigieren |

## Schwierigkeitsgrade

| Level | Gegner | Geschwindigkeit | Projektil-Geschwindigkeit |
|---|---|---|---|
| 1 | 3 | Langsam | Langsam |
| 2 | 5 | Mittel | Mittel |
| 3 | 7 | Schnell | Schnell |
| 4+ | 10+ | Sehr schnell | Sehr schnell |

Mit jedem Level werden die Gegner **länger** (mehr LEDs) und **schneller**.

## Erweiterungen und Anhänge

- [Wokwi-Simulation](WOKWI.md)
- [Gehäuse und Aufbau](GEHAEUSE.md)
- [Zweispieler-Modus](ZWEISPIELER.md)
- [Persistenter Highscore](HIGHSCORE.md)
- [GitHub Actions / CI](CI.md)
- [Audio-Erweiterung](AUDIO.md)

## Lizenz

MIT – basiert auf 1D-RGB-Invaders von worksasdesigned.

## Credits

- Originalkonzept: worksasdesigned (1D RGB Invaders)
- Portierung auf ESP32 NodeMCU (ohne Audio): Daniel Lienhard