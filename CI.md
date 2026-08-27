# GitHub Actions / CI – trt.1DArcadeShooter

Diese Ergänzung zeigt, wie du das Repository mit einer einfachen CI aufwertest. So werden Änderungen automatisch geprüft.

## Ziel

Die CI soll:

- Code auf offensichtliche Fehler prüfen
- Dokumentation konsistent halten
- bei Pull Requests und Commits automatisch laufen

## Sinnvolle Checks

Für dieses Projekt bieten sich an:

- Markdown-Lint
- C++ Syntax-Check / Build-Versuch
- Dateistruktur-Check
- optional Secrets-Scan

## Beispiel-Workflow

```yaml
name: ci

on:
  push:
  pull_request:

jobs:
  check:
    runs-on: ubuntu-latest
    steps:
      - name: Checkout
        uses: actions/checkout@v4

      - name: Set up Python
        uses: actions/setup-python@v5
        with:
          python-version: '3.12'

      - name: Lint Markdown
        run: |
          pip install markdownlint-cli
          markdownlint "**/*.md" --ignore node_modules

      - name: Basic C++ check
        run: |
          echo "Hier kann später ein Build oder ein Syntaxcheck ergänzt werden."
```

## Empfehlung für dein Repo

Für den Anfang reicht ein schlanker Workflow mit:

- Checkout
- Markdown-Lint
- optional Dateilistenprüfung

Später kannst du ergänzen:

- Arduino-Compile-Check
- PlatformIO-Build
- automatische Release-Erstellung

## Unterrichtlicher Mehrwert

- Schüler sehen, wie professionelle Repositories gepflegt werden
- Fehler werden früh sichtbar
- gute Dokumentation wird automatisch belohnt

## Abnahmekriterien

- Workflow läuft bei jedem Push
- Fehler werden als rote Checks angezeigt
- README und Anhänge bleiben sauber formatiert
- CI-Status ist im Repository sichtbar
