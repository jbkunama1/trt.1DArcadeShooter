# Zweispieler-Modus – trt.1DArcadeShooter

Diese Ergänzung beschreibt einen einfachen 2-Spieler-Modus als sinnvolle Weiterentwicklung des Projekts.

## Idee

Statt nur einer Spielerseite gibt es zwei Spielbereiche:

- Spieler 1 links
- Spieler 2 rechts
- Ziele oder Projektile laufen über denselben Strip

Alternativ kann man auch zwei getrennte Strip-Segmente nutzen und daraus ein Duell machen.

## Spielvarianten

### Variante A: Gemeinsamer Strip

- beide Spieler teilen sich denselben LED-Strip
- Gegner kommen von beiden Seiten
- jeder Spieler hat eigene Buttons und eigene Projektile

### Variante B: Geteilte Zonen

- linker Bereich = Spieler 1
- rechter Bereich = Spieler 2
- jeder verteidigt seine Zone

### Variante C: Direktduell

- Schüsse treffen sich in der Mitte
- schnellere Reaktion gewinnt
- optional Power-Ups in der Mitte

## Hardware-Erweiterung

Für den Zweispieler-Modus brauchst du zusätzlich:

- 3 weitere Farb-Buttons
- optional 1 zweiten Menu-/Start-Button
- ausreichend freie GPIOs
- ggf. längeren LED-Strip

## Beispiel-Pinbelegung

Wenn du den Basisaufbau erweiterst, kannst du z. B. so vorgehen:

- Spieler 1 Rot: GPIO 4
- Spieler 1 Grün: GPIO 5
- Spieler 1 Blau: GPIO 12
- Spieler 1 Menu: GPIO 13

- Spieler 2 Rot: GPIO 14
- Spieler 2 Grün: GPIO 15
- Spieler 2 Blau: GPIO 16
- Spieler 2 Menu: GPIO 17

Prüfe vorher, ob deine konkrete ESP32-Boardvariante diese Pins sauber unterstützt.

## Software-Umbau

Der sauberste Weg ist:

1. Spielerstatus als Struktur anlegen
2. Buttons pro Spieler getrennt auswerten
3. Projektile mit Besitzerfeld versehen
4. Treffer- und Score-Logik pro Spieler speichern

Beispielstruktur:

```cpp
struct PlayerState {
  int pos;
  int score;
  bool buttonPressed;
};

PlayerState player1;
PlayerState player2;
```

## Unterrichtlicher Mehrwert

- sehr gutes Thema für Zustandsautomaten
- ideal für Teamarbeit und Pair Programming
- gut geeignet für Wettkampf-Szenarien

## Abnahmekriterien

- beide Spieler können unabhängig schießen
- Treffer werden korrekt zugeordnet
- kein Button beeinflusst den anderen Spieler ungewollt
- Spiel bleibt bei zwei aktiven Spielern stabil
