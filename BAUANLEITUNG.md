# Bauanleitung – trt.1DArcadeShooter

## Schritt-für-Schritt zum fertigen Spiel

### Schritt 1: Hardware besorgen

**Einkaufsliste:**

| Teil | Menge | Wo | Preis ca. |
|---|---|---|---|
| ESP32 NodeMCU-32S | 1 | Amazon, AliExpress | 8–12€ |
| WS2812B LED-Strip | 1 | Amazon, AliExpress | 15–25€ (2m, 120 LEDs) |
| Arcade-Button Rot 60mm | 1 | Amazon, AliExpress | 5–8€ |
| Arcade-Button Grün 60mm | 1 | Amazon, AliExpress | 5–8€ |
| Arcade-Button Blau 60mm | 1 | Amazon, AliExpress | 5–8€ |
| Taster 12mm | 1 | Amazon, AliExpress | 1–2€ |
| 5V-Netzteil 10A | 1 | Amazon, AliExpress | 15–20€ |
| Breadboard | 1 | Amazon, AliExpress | 3–5€ |
| Jumper-Kabel | 1 Set | Amazon, AliExpress | 5–8€ |
| 330Ω Widerstand | 1 | Amazon, AliExpress | 1–2€ |
| **Gesamt** | | | **~60–80€** |

### Schritt 2: ESP32 einrichten

1. **Arduino IDE installieren** (https://www.arduino.cc/en/software)
2. **ESP32-Board-Paket installieren:**
   - Datei → Voreinstellungen
   - Zusätzliche Boardverwalter-URLs: `https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json`
   - Werkzeuge → Board → Boardverwalter → "ESP32" suchen → installieren
3. **Bibliotheken installieren:**
   - Werkzeuge → Bibliotheken verwalten
   - "FastLED" suchen → installieren (≥3.7.0)
   - "ESPAsyncWebServer" → ZIP von GitHub herunterladen → Bibliothek → ZIP-Bibliothek hinzufügen
   - "ESPAsyncTCP" → ZIP von GitHub herunterladen → Bibliothek → ZIP-Bibliothek hinzufügen
   - "ArduinoJson" → installieren (≥6.0)

### Schritt 3: Code hochladen

1. `src/main.cpp` in Arduino IDE öffnen
2. Board einstellen:
   - Werkzeuge → Board → "ESP32 Dev Module"
   - Werkzeuge → Flash Mode → "DIO"
   - Werkzeuge → Flash Frequency → "80MHz"
   - Werkzeuge → Upload Speed → "115200"
3. ESP32 über USB anschließen
4. Werkzeuge → Port → richtigen Port wählen
5. Kompilieren (✓) und Hochladen (→)

### Schritt 4: Verdrahten

**Reihenfolge:**

1. **LED-Strip vorbereiten:**
   - 3 Adigen Kabel an Strip löten/stecken (VCC, DIN, GND)
   - 330Ω Widerstand in DIN-Leitung einfügen
   
2. **Buttons anschließen:**
   - Jeden Button mit 2 Kabeln verbinden
   - Eine Seite → GPIO (4, 5, 12, 13)
   - Andere Seite → GND
   
3. **ESP32 anschließen:**
   - GPIO 2 → LED-Strip DIN (über 330Ω)
   - GPIO 4, 5, 12, 13 → Buttons
   - 5V → Button-Versorgung (optional)
   - GND → Alle GNDs verbinden
   
4. **Netzteil anschließen:**
   - 5V → LED-Strip VCC
   - GND → LED-Strip GND + ESP32 GND

### Schritt 5: Testen

1. **Netzteil einschalten**
2. **Begrüßungseffekt:** Alle LEDs sollten einmal grün aufleuchten
3. **WLAN testen:**
   - Handy/PC → WLAN "1DArcadeShooter" verbinden (Passwort: `arcade123`)
   - Browser → `http://192.168.4.1`
   - Web-Interface sollte erscheinen
4. **Buttons testen:**
   - Menu-Button drücken → Spiel sollte starten
   - Farb-Buttons drücken → Projektile sollten schießen

### Schritt 6: Gehäuse bauen (optional)

**3D-Druck:**
- STL-Dateien von Originalprojekt (1D-RGB-Invaders) anpassen
- Aussparungen für Buttons und LED-Strip vorsehen

**Holzgehäuse:**
- Multiplex-Platte (12mm)
- Fräsen oder Sägen für LED-Strip
- Buttons von oben montieren

**Acrylglas:**
- LED-Strip hinter diffuses Acrylglas setzen
- Effekt: Gleichmäßige Lichtlinie

### Schritt 7: Spiel kalibrieren

Im Web-Interface oder Code anpassen:

| Parameter | Wirkung | Wertebereich |
|---|---|---|
| `BRIGHTNESS` | LED-Helligkeit | 0–255 |
| `NUM_LEDS` | Strip-Länge | 30–240 |
| `frameDelay` | Spielgeschwindigkeit | 20–100ms |
| `PLAYER_START_POS` | Spieler-Position | 3–10 |
| `ENEMY_START_POS` | Gegner-Start | 80–150 |

## Tipps für den Unterricht

### Technikunterricht (Klasse 8–10)

- **Schaltplan verstehen:** Stromkreise, Pull-Up-Widerstände
- **LED-Strip Ansteuerung:** Datenprotokolle, Timing
- **Stromberechnung:** Ohmsches Gesetz, Leistung

### Informatikunterricht (Klasse 9–11)

- **Spiellogik:** Zustandsautomaten, Kollisionserkennung
- **Web-Interface:** HTTP, JSON, APIs
- **Optimierung:** Frame-Rate, Speichernutzung

### Medienbildung (Klasse 7–9)

- **Spielmechanik:** Difficulty-Curve, Feedback
- **UI/UX:** Web-Interface Design
- **Dokumentation:** README schreiben

## Fehlerbehebung

| Problem | Lösung |
|---|---|
| LEDs flackern | Netzteil stärker (10A), Elko parallel |
| Buttons reagieren nicht | Code: INPUT_PULLUP prüfen |
| WLAN nicht sichtbar | ESP32 neu starten |
| Web-Interface leer | Browser-Cache leeren |
| Spiel zu langsam | `frameDelay` reduzieren |
| Spiel zu schnell | `frameDelay` erhöhen |

## Erweiterungsideen

- **Zweispieler-Modus:** Zweiter Button-Block
- **Sound:** Buzzer oder I2S-Audio (siehe AUDIO.md)
- **Highscore-System:** EEPROM oder SPIFFS
- **Effekte:** Partikel bei Explosionen
- **Boss-Kämpfe:** Größere Gegner mit mehr Leben