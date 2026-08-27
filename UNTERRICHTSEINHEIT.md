# Unterrichtseinheit: trt.1DArcadeShooter – 1D-Arcade-Shooter mit ESP32 und WS2812B

## Rahmendaten

| Merkmal | Beschreibung |
|---|---|
| Fach | Technik (Wahlpflichtfach) / Informatik (Wahlfach) |
| Schulart | Realschule, Sekundarstufe I |
| Bildungsplan | Baden-Württemberg 2016 |
| Klassenstufe | 8–10 (empfohlen: 9 oder 10) |
| Zeitumfang | 4 Unterrichtsstunden (à 45 Minuten) |
| Lerngruppe | 12–20 Schüler:innen (Partnerarbeit empfohlen) |
| Vorkenntnisse | Grundlagen Elektronik, einfache Programmierung (Arduino/ESP32), EVA-Prinzip |
| Medien | ESP32 NodeMCU, WS2812B-Strip, Buttons, Breadboard, Computer mit Arduino IDE |

## Bildungsplanbezug

### Technik (Wahlpflichtfach) – Klassen 7/8/9

**Inhaltsbezogene Kompetenzen (3.2.2 Systeme und Prozesse):**

- Die Schülerinnen und Schüler analysieren technische Systeme und beschreiben das Zusammenwirken der Teilsysteme.
- Sie erkennen, dass die Steuerungstechnik in unserer technisierten Welt in allen Lebensbereichen von zentraler Bedeutung ist.
- Die Schülerinnen und Schüler nutzen Steuerungen bei der Lösung von technischen Aufgabenstellungen und lernen dabei das Eingabe – Verarbeitung – Ausgabe – Prinzip (EVA) kennen.

**Prozessbezogene Kompetenzen:**

- **Erkenntnisgewinnung:** technische Informationen aus verschiedenen Quellen sammeln und strukturiert auswerten
- **Kommunikation:** Schaltpläne, Diagramme und Fließbilder mit und ohne Computerunterstützung normorientiert erstellen
- **Herstellung und Nutzung:** konstruktive Lösungen für technische Probleme entwickeln, den Arbeitsablauf planen, strukturieren und optimieren
- **Bewertung:** eigene technische Objekte und Modelle kriterienorientiert bewerten, den eigenen Arbeitsprozess reflektieren und bewerten

### Informatik (Wahlfach) – Klasse 8

**Inhaltsbezogene Kompetenzen (3.1.2 Algorithmen):**

- Die Schülerinnen und Schüler können logische Verknüpfungen (UND, ODER, NICHT) in Bedingungen von Schleifen und Verzweigungen verwenden.
- Sie können Zufallszahlen in eigenen Programmen verwenden (z. B. um Spielverlauf abwechslungsreicher zu gestalten).
- Sie können eine indexbasierte Datenstruktur zur Speicherung und Verarbeitung gleichartiger Daten verwenden.
- Sie können grundlegende Algorithmen auf einer indexbasierten Datenstruktur implementieren.
- Sie können Unterprogramme verwenden, um Programmcode zu strukturieren und redundanten Code zu vermeiden.

**Prozessbezogene Kompetenzen:**

- **Modellieren und Implementieren:** Abläufe in einer Programmiersprache implementieren, geeignete Codebausteine auswählen, adaptieren und einbauen
- **Strukturieren und Vernetzen:** gleichartige Daten in geeigneten Datenstrukturen zusammenfassen, Handlungsschritte chronologisch ordnen
- **Kommunizieren und Kooperieren:** eigenen und fremden Programmcode kommentieren und dokumentieren, arbeitsteilig im Team planen, strukturieren, ausführen, reflektieren und präsentieren
- **Analysieren und Bewerten:** durch Analyse Erkenntnisse über das Verhalten von informatischen Systemen gewinnen, Lösungsansätze vergleichen und bewerten

### Informatik (Wahlfach) – Klasse 9

**Inhaltsbezogene Kompetenzen (3.2.2 Algorithmen):**

- Die Schülerinnen und Schüler lernen die Syntax der schon bekannten algorithmischen Grundbausteine kennen und wenden diese in neuen Kontexten an.
- Sie lernen logische Verknüpfungen und Wahrheitstafeln kennen und nutzen boolesche Ausdrücke in Bedingungen von Schleifen oder Verzweigungen.
- Sie nutzen Variablen mit unterschiedlichen Datentypen wie auch Arrays zur Speicherung und Verarbeitung gleichartiger Daten.
- Sie nutzen Unterprogramme mit Parametern und Rückgabewerten.
- Sie beschreiben Anforderungen an Unterprogramme und entwerfen geeignete Testroutinen, um ihre Implementierungen zu testen.

### Leitperspektiven

| Leitperspektive | Umsetzung im Projekt |
|---|---|
| Medienbildung (MB) | Umgang mit digitalen Werkzeugen, Programmierung, Web-Interface, Dokumentation |
| Berufliche Orientierung (BO) | Fachspezifische und handlungsorientierte Zugänge zur Arbeits- und Berufswelt, Einschätzung eigener Fähigkeiten |
| Bildung für nachhaltige Entwicklung (BNE) | Ökologisch und ökonomisch verantwortungsbewusst mit Material und Energie umgehen |
| Verbraucherbildung (VB) | Qualität der Konsumgüter, Chancen und Risiken der Lebensführung |

## Lernziele

### Grobziel

Die Schülerinnen und Schüler entwickeln in Partnerarbeit einen 1D-Arcade-Shooter mit ESP32 und WS2812B-LED-Strip. Sie analysieren das technische System, implementieren die Spiellogik in C++ und dokumentieren ihren Arbeitsprozess.

### Feinziele

Nach der Unterrichtseinheit können die Schülerinnen und Schüler:

1. **Technisches System analysieren**
   - das EVA-Prinzip auf das Projekt anwenden
   - das Zusammenwirken von Teilsystemen beschreiben
   - Sicherheitsaspekte beim Umgang mit Strom und Elektronik nennen und beachten

2. **Programmierung anwenden**
   - Variablen, Arrays und Unterprogramme in C++ nutzen
   - logische Verknüpfungen in Bedingungen einsetzen
   - Zufallszahlen für Spielmechanik verwenden
   - Schleifen und Verzweigungen für Spielablauf implementieren

3. **Projekt dokumentieren und präsentieren**
   - Schaltplan normorientiert erstellen
   - Code kommentieren und strukturieren
   - Arbeitsprozess reflektieren und Ergebnisse präsentieren

## Unterrichtsverlauf

### Stunde 1: Einführung und Hardware-Aufbau

| Phase | Zeit | Inhalt | Methode |
|---|---|---|---|
| Einstieg | 10 Min | Video zeigen, Problemstellung klären | Plenum, Impuls |
| Erarbeitung 1 | 15 Min | EVA-Prinzip auf das Projekt anwenden, Schaltplan analysieren | Partnerarbeit, Arbeitsblatt |
| Erarbeitung 2 | 15 Min | Hardware aufbauen: ESP32, LED-Strip, Buttons verbinden | Gruppenarbeit, praktische Arbeit |
| Sicherung | 5 Min | Sicherheitsregeln wiederholen, erste Funktionstests | Plenum, Checkliste |

**Hausaufgabe (optional):**
- Code aus dem Repository herunterladen und in Arduino IDE öffnen
- Board-Einstellungen prüfen

### Stunde 2: Programmierung – Grundlagen und Spielmechanik

| Phase | Zeit | Inhalt | Methode |
|---|---|---|---|
| Wiederholung | 5 Min | EVA-Prinzip, Sicherheitsregeln | Plenum |
| Erarbeitung 1 | 20 Min | Code-Analyse: Variablen, Arrays, Unterprogramme identifizieren | Partnerarbeit, Code-Reading |
| Erarbeitung 2 | 15 Min | Spiellogik verstehen: Gegner, Projektile, Kollision | Gruppenarbeit, Arbeitsblatt |
| Sicherung | 5 Min | Erste Programmieraufgabe: Farben ändern | Einzelarbeit, Live-Coding |

### Stunde 3: Programmierung – Erweiterung und Debugging

| Phase | Zeit | Inhalt | Methode |
|---|---|---|---|
| Einstieg | 5 Min | Feedback zur Hausaufgabe, Probleme besprechen | Plenum |
| Erarbeitung 1 | 20 Min | Eigene Anpassung implementieren | Partnerarbeit, Programmierung |
| Erarbeitung 2 | 15 Min | Testen und Debugging | Gruppenarbeit, Testprotokoll |
| Sicherung | 5 Min | Zwischenstand sichern, Code kommentieren | Einzelarbeit, Dokumentation |

### Stunde 4: Dokumentation, Präsentation und Wettbewerb

| Phase | Zeit | Inhalt | Methode |
|---|---|---|---|
| Einstieg | 5 Min | Ziel der Stunde klären | Plenum |
| Erarbeitung 1 | 15 Min | Schaltplan und Code-Dokumentation erstellen | Partnerarbeit, Dokumentation |
| Erarbeitung 2 | 10 Min | Highscore-Wettbewerb | Gruppenarbeit, Wettbewerb |
| Präsentation | 10 Min | Ergebnisse vorstellen, Reflexion | Plenum, Kurzpräsentation |
| Sicherung | 5 Min | Bewertung, Feedback, Ausblick | Plenum, Feedbackbogen |

## Differenzierung

### Für schnelle Schüler:innen

- Zweispieler-Modus vorbereiten
- Highscore-System mit EEPROM ergänzen
- Partikel-Effekte oder Zusatzfeatures planen
- Web-Interface oder CI-Doku vertiefen

### Für langsamere Schüler:innen

- vorgegebene Code-Snippets nutzen
- Schritt-für-Schritt-Anleitung folgen
- Partnerarbeit mit stärkeren Peers
- reduzierte Ziele: nur 1 Button oder feste Gegnerfarbe

### Für Schüler:innen mit sonderpädagogischem Förderbedarf

- große Buttons und klare Farbcodes
- reduzierte Komplexität und langsame Geschwindigkeit
- visuelle Hilfen und einfache Sprache
- Unterstützung durch Peers

## Bewertung

| Kriterium | Punkte | Beschreibung |
|---|---|---|
| Hardware funktioniert | 20 | LEDs, Buttons, WLAN korrekt verdrahtet |
| Code läuft | 30 | Spiel startet, ist spielbar, keine Abstürze |
| Eigene Anpassung | 20 | Mindestens 1 Feature geändert oder erweitert |
| Dokumentation | 20 | Schaltplan, Code-Kommentare, Arbeitsprozess |
| Präsentation | 10 | Kurzpräsentation, Reflexion, Feedback |
| **Gesamt** | **100** | |

## Material und Ressourcen

### Für die Lehrkraft

- Repository: https://github.com/jbkunama1/trt.1DArcadeShooter
- Arbeitsblätter und Bewertungsraster
- Lösungshinweise für typische Fehler

### Für die Schüler:innen

- Hardware-Set pro Gruppe:
  - ESP32 NodeMCU-32S
  - WS2812B LED-Strip
  - 3 Arcade-Buttons
  - 1 Menu-Button
  - Breadboard
  - Jumper-Kabel
  - 5V-Netzteil
  - 330Ω Widerstand

- Software:
  - Arduino IDE
  - FastLED
  - ESPAsyncWebServer
  - ESPAsyncTCP

## Sicherheitshinweise

- Nie 5V vom ESP32 für den LED-Strip nehmen
- Alle GNDs verbinden
- 330Ω Vorwiderstand in der Datenleitung verwenden
- Feste Verbindungen herstellen
- Vor dem Einschalten alle Verbindungen prüfen

## Anhang: Arbeitsblätter

### Arbeitsblatt 1: EVA-Prinzip und Schaltplan

**Aufgabe 1:** Ordne die Komponenten dem EVA-Prinzip zu.

**Aufgabe 2:** Zeichne die Verdrahtung nach.

**Aufgabe 3:** Beantworte die Fragen zum Strom, GND und Vorwiderstand.

### Arbeitsblatt 2: Code-Analyse

**Aufgabe 1:** Lies den Code und beschreibe die Funktion der Spielschleife.

**Aufgabe 2:** Identifiziere Variablen, Arrays, Unterprogramme, Schleifen und Verzweigungen.

**Aufgabe 3:** Finde logische Verknüpfungen im Code.

### Arbeitsblatt 3: Eigene Anpassung

**Aufgabe:** Entwickle eine eigene Anpassung für das Spiel und dokumentiere Idee, Umsetzung und Test.

## Anhang: Testprotokoll

| Test | Ergebnis | Bemerkung |
|---|---|---|
| LEDs leuchten |  |  |
| Buttons reagieren |  |  |
| Code kompiliert |  |  |
| Spiel startet |  |  |
| Webinterface erreichbar |  |  |

## Anhang: Feedbackbogen

- Was lief gut?
- Was war schwierig?
- Was würdest du anders machen?
- Was hast du gelernt?

## Quellen

- Bildungsplan 2016 Baden-Württemberg, Technik: https://www.bildungsplaene-bw.de/,Lde/BP2016BW_ALLG_SEK1_T
- Bildungsplan 2016 Baden-Württemberg, Informatik: https://www.bildungsplaene-bw.de/,Lde/BP2016BW_ALLG_SEK1_INFWF
- Bildungsplan 2016 Baden-Württemberg, Systeme und Prozesse: https://www.bildungsplaene-bw.de/BP2016BW_ALLG_SEK1_T_IK_7-8-9_02
- Bildungsplan 2016 Baden-Württemberg, Algorithmen Klasse 8: https://www.bildungsplaene-bw.de/BP2016BW_ALLG_SEK1_INFWF_IK_8_02
- Bildungsplan 2016 Baden-Württemberg, Algorithmen Klasse 9: https://www.bildungsplaene-bw.de/BP2016BW_ALLG_SEK1_INFWF_IK_9_02
