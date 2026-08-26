# Schaltplan – trt.1DArcadeShooter

## Übersicht

```
                    +------------------+
                    |   5V-Netzteil    |
                    |   (≥3A)          |
                    +--------+---------+
                             |
              +--------------+--------------+
              |              |              |
         +----+----+    +----+----+    +----+----+
         |  ESP32  |    | LED-Strip |   | Buttons |
         | NodeMCU |    | WS2812B   |   | 4×±     |
         +---------+    +-----------+   +---------+
```

## Detaillierte Verdrahtung

### ESP32 NodeMCU

```
ESP32 NodeMCU:
┌─────────────────────────┐
│  GPIO 2  ──[330Ω]──┐    │
│  GPIO 4  ──────────┼──┐ │
│  GPIO 5  ──────────┼──┼─┤
│  GPIO 12 ──────────┼──┼─┼─┐
│  GPIO 13 ──────────┼──┼─┼─┼─┐
│  5V      ──────────┼──┼─┼─┼─┼──┐ (nur für Buttons!)
│  GND     ──────────┴──┴─┴─┴─┴──┴──┐
└─────────────────────────┬──────────┘
                          │
                    +-----+-----+
                    |  GND Bus  |
                    +-----+-----+
                          │
         +----------------+----------------+
         |                |                |
    +----+----+      +----+----+      +----+----+
    | LED-Strip |      | Buttons |      | 5V Bus |
    | VCC ──────┼──────> 5V     |      | (extern)|
    | DIN ──────┼──────> GPIO 2 |      +--------+
    | GND ──────┼──────> GND    |
    +-----------+      +---------+
```

### LED-Strip (WS2812B)

```
LED-Strip:
┌─────────────────────────────────┐
│  VCC (5V) ──> 5V (extern, ≥3A) │
│  DIN      ──> GPIO 2 (über 330Ω)│
│  GND      ──> GND (gemeinsam)   │
└─────────────────────────────────┘

Wichtig:
- 5V NICHT vom ESP32 nehmen!
- Alle GNDs verbinden
- 330Ω Vorwiderstand in Datenleitung
```

### Buttons

```
Button Rot (GPIO 4):
┌─────────────┐
│  Button     │
│  ┌───┐      │
│  │   │──────┼──> GPIO 4
│  └───┘      │
│     │       │
│     └───────┼──> GND
└─────────────┘
(Interner Pull-Up aktiviert)

Gleich für alle 4 Buttons:
- Rot:   GPIO 4
- Grün:  GPIO 5
- Blau:  GPIO 12
- Menu:  GPIO 13
```

## Stromversorgung

### LED-Strip Berechnung

WS2812B LEDs benötigen bis zu **60mA pro LED** bei voller Helligkeit (Weiß³).

Beispiel: 120 LEDs Strip
- Maximal: 120 × 60mA = **7,2A**
- Empfohlenes Netzteil: **5V, 10A**
- Bei niedriger Helligkeit (25%): 5V, 3A reicht

### ESP32 Stromversorgung

- ESP32 über USB oder 5V-Pin
- Buttons können über ESP32 5V versorgt werden (geringer Strom)
- LED-Strip **immer separat** über externes Netzteil

## Sicherheitshinweise

1. **Nie 5V vom ESP32 für den Strip nehmen** – Überlastung!
2. **Alle GNDs verbinden** – sonst keine korrekte Logik
3. **330Ω Vorwiderstand** – schützt LED-Strip Data-Eingang
4. **Elko (1000µF) parallel zu Strip** – puffert Stromspitzen
5. **Feste Verbindungen** – Löten oder gute Steckverbindungen

## Fehlersuche

| Problem | Mögliche Ursache | Lösung |
|---|---|---|
| LEDs leuchten nicht | 5V fehlt | Netzteil prüfen |
| Nur erste LED leuchtet | Data-Verbindung defekt | Lötstelle prüfen |
| Zufällige Farben | GND nicht verbunden | Alle GNDs verbinden |
| ESP32 startet nicht | USB defekt | Anderes Kabel testen |
| Buttons reagieren nicht | Pull-Up fehlt | Code prüfen (INPUT_PULLUP) |