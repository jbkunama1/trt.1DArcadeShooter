# Audio-Erweiterung für trt.1DArcadeShooter

Diese Anleitung zeigt, wie du das Projekt mit I2S-Audio nachrüsten kannst.

## Benötigte Hardware

| Komponente | Menge | Hinweise |
|---|---|---|
| ESP32-S3 | 1 | Ersetzt ESP32 NodeMCU |
| MAX98357A I2S-Verstärker | 1 | Oder ähnlicher I2S DAC |
| Lautsprecher | 1 | 4Ω, 3W |
| Jumper-Kabel | 1 | Zum Verdrahten |

## Pin-Belegung (ESP32-S3)

| Funktion | GPIO |
|---|---|
| LED-Strip Data | GPIO 7 |
| Button Rot | GPIO 15 |
| Button Grün | GPIO 16 |
| Button Blau | GPIO 17 |
| Menu-Button | GPIO 18 |
| I2S BCLK | GPIO 4 |
| I2S LRC | GPIO 5 |
| I2S DIN | GPIO 6 |

## Verdrahtung MAX98357A

```
ESP32-S3     MAX98357A
  GPIO 4  ──> BCLK
  GPIO 5  ──> LRC
  GPIO 6  ──> DIN
  3.3V    ──> VDD
  GND     ──> GND
            SD  ──> Lautsprecher (+)
            GND ──> Lautsprecher (-)
```

## Code-Änderungen

1. **FastLED Pin ändern:**
   ```cpp
   #define LED_PIN 7  // Statt 2
   ```

2. **Button-Pins ändern:**
   ```cpp
   #define BUTTON_RED 15
   #define BUTTON_GREEN 16
   #define BUTTON_BLUE 17
   #define MENU_BUTTON 18
   ```

3. **I2S-Audio einbinden:**
   ```cpp
   #include <driver/i2s.h>
   
   // I2S Konfiguration
   i2s_config_t i2s_config = {
     .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_TX),
     .sample_rate = 22050,
     .bits_per_sample = I2S_BITS_PER_SAMPLE_16BIT,
     .channel_format = I2S_CHANNEL_FMT_ONLY_LEFT,
     .communication_format = I2S_COMM_FORMAT_STAND_I2S,
     .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1,
     .dma_buf_count = 8,
     .dma_buf_len = 1024,
     .use_apll = false
   };
   
   i2s_pin_config_t pin_config = {
     .bck_io_num = 4,
     .ws_io_num = 5,
     .data_out_num = 6,
     .data_in_num = I2S_PIN_NO_CHANGE
   };
   
   void setupAudio() {
     i2s_driver_install(I2S_NUM_0, &i2s_config, 0, NULL);
     i2s_set_pin(I2S_NUM_0, &pin_config);
   }
   
   void playTone(int frequency, int duration) {
     // Einfache Ton-Erzeugung
     uint16_t sample = (uint16_t)(32767 * sin(2 * PI * frequency / 22050));
     size_t bytes_written;
     i2s_write(I2S_NUM_0, &sample, sizeof(sample), &bytes_written, portMAX_DELAY);
   }
   ```

4. **Audio im Spiel nutzen:**
   ```cpp
   void fireProjectile(int color) {
     // ... bestehender Code ...
     playTone(440 + (color * 200), 100); // Ton beim Schießen
   }
   
   void updateGame() {
     // ... bestehender Code ...
     if (treffer) {
       playTone(880, 200); // Explosionston
     }
   }
   ```

## Hinweise

- Der ESP32 (NodeMCU) unterstützt I2S nur eingeschränkt – ein ESP32-S3 wird empfohlen
- Audio-Code ist im aktuellen Projekt **nicht** enthalten, um Kompatibilität zu gewährleisten
- Bei Fragen: Originalprojekt konsultieren (1D-RGB-Invaders)

## Alternative: Einfacher Buzzer

Für einfache Soundeffekte ohne I2S:

```cpp
#define BUZZER_PIN 15

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
}

void playBeep() {
  tone(BUZZER_PIN, 1000, 100); // 1kHz, 100ms
}
```

Verdrahtung:
```
ESP32 GPIO 15 ──> Buzzer (+)
ESP32 GND     ──> Buzzer (-)
```