# Wokwi-Simulation – trt.1DArcadeShooter

Mit dieser Anleitung kannst du das Spiel im Browser simulieren, bevor du echte Hardware aufbaust. Das ist ideal zum Testen, Vorführen und für den Unterricht.

## Ziele

- Spiel ohne Hardware ausprobieren
- Pin-Belegung und Button-Logik testen
- Unterrichtsszenarien ohne Bauteile vorbereiten

## Vorbereitung

Nutze die vorhandene Firmware aus `src/main.cpp` und übertrage sie in ein Wokwi-Projekt. Die wichtigsten Einstellungen sind dieselben wie im realen Aufbau:

- LED-Strip Data: GPIO 2
- Button Rot: GPIO 4
- Button Grün: GPIO 5
- Button Blau: GPIO 12
- Menu-Button: GPIO 13

## Aufbau in Wokwi

Empfohlener Aufbau:

- ESP32 DevKit
- 1 adressierbarer LED-Strip (WS2812/NeoPixel)
- 3 Farb-Buttons
- 1 Menu-Button

## Schrittweise Einrichtung

1. **Neues Wokwi-Projekt starten**
   - ESP32 auswählen
   - NeoPixel-Strip hinzufügen
   - 4 Buttons hinzufügen

2. **Pins im Code anpassen**
   - Nutze dieselben GPIOs wie im Hauptprojekt
   - Wenn Wokwi bestimmte Pins nicht sauber simuliert, weiche auf typische ESP32-Pins aus

3. **Button-Verhalten prüfen**
   - In der Simulation drücken
   - Im Serial Monitor ausgeben lassen
   - Debounce testen

4. **LED-Ausgabe prüfen**
   - Spielerposition, Gegnerposition und Treffer visualisieren
   - Strip-Länge ggf. kleiner wählen für bessere Übersicht

## Hinweise für den Unterricht

- Für die Simulation reichen oft 30 bis 60 LEDs völlig aus
- Schüler können vorab Programmierfehler erkennen
- Wokwi eignet sich gut als Hausaufgabe oder Flipped-Classroom-Übung

## Bekannte Einschränkungen

- Webserver-Funktionen können in der Simulation abweichen
- WLAN und reale Stromversorgung lassen sich nur begrenzt abbilden
- Timing-Verhalten kann leicht vom echten ESP32 abweichen

## Erweiterungsideen

- Zweites Projekt nur mit vereinfachter Version
- Zusätzliche LEDs für Lebensanzeige
- Serielle Debug-Ausgaben für Unterricht und Fehlersuche

## Abnahmekriterien

- Simulation startet ohne Fehlermeldung
- Buttons lösen Schuss und Start aus
- Gegner bewegen sich entlang der Leiste
- Treffer werden sichtbar ausgelöst
