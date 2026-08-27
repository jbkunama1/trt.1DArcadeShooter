# Gehäuse und Aufbau – trt.1DArcadeShooter

Dieser Anhang beschreibt sinnvolle Aufbauvarianten für ein robustes, unterrichtstaugliches Gerät.

## Ziel

Der Aufbau soll:

- stabil im Unterricht nutzbar sein
- übersichtlich verdrahtet sein
- leicht wartbar bleiben
- optional optisch ansprechend wirken

## Variante 1: Breadboard-Aufbau

Geeignet für:

- ersten Prototyp
- Unterrichtsprojekt mit kurzer Bauzeit
- Fehlersuche und Umbauten

Vorteile:

- schneller Aufbau
- keine Lötarbeit nötig
- einfaches Umstecken

Nachteile:

- wenig robust
- wackelige Kontakte möglich
- ungeeignet für Dauerbetrieb

Empfehlung:

- kurze Jumper verwenden
- Strip und Netzteil sauber fixieren
- Buttons auf stabiler Platte montieren

## Variante 2: Lochraster / Streifenraster

Geeignet für:

- dauerhafte Nutzung
- schulische Projektarbeit
- sauberes Kabelmanagement

Vorteile:

- stabiler als Breadboard
- gut reparierbar
- professioneller Eindruck

Empfehlung:

- LED-Strip über Schraubklemmen oder Stiftleisten anschließen
- Buttons mit Litzen und Schrumpfschlauch anschließen
- Netzteil und ESP32 getrennt befestigen

## Variante 3: Eigenes Gehäuse

Geeignet für:

- Präsentation
- längerfristige Nutzung
- Turniere oder Vorführungen

Mögliche Materialien:

- Sperrholz / Multiplex
- Acrylglas
- 3D-Druck-Gehäuse

Aufbauidee:

- LED-Strip frontal oder seitlich sichtbar
- Arcade-Buttons ergonomisch auf der Front
- ESP32 und Netzteil im Inneren sicher verschraubt
- optional Klarsichtdeckel für Technik-Showcase

## Mechanische Hinweise

- LED-Strip auf eine ebene Fläche kleben oder schrauben
- Buttons in Abständen montieren, die mit zwei Fingern gut erreichbar sind
- Zugentlastung für Kabel vorsehen
- Kanten entgraten oder abrunden

## Elektrische Hinweise

- Netzteil separat vom Controller führen
- GND aller Komponenten gemeinsam verbinden
- 5V-Versorgung des Strips nicht über das ESP32-Board führen
- falls möglich, Sicherung oder Schalter in die Zuleitung einbauen

## Unterrichtliche Aufgaben

1. Zeichne ein Gehäuse im Maßstab 1:2
2. Plane die Position von Buttons, Display und Strip
3. Begründe, warum ein Breadboard für den Dauereinsatz problematisch ist
4. Vergleiche 3 Gehäusevarianten nach Kosten, Aufwand und Stabilität

## Abnahmekriterien

- Gerät steht stabil
- alle Buttons sind gut erreichbar
- Kabel sind geordnet und zugentlastet
- Strip bleibt auch bei häufigem Spielen zuverlässig verbunden
