/****************************************************************************************************************************
  minimal.ino
  React_Generic is a library for ESP32, ESP8266, Protenta_H7, STM32F7, etc.

  Based on and modified from :

  1) Reactduino   (https://github.com/Reactduino/Reactduino)
  2) ReactESP     (https://github.com/mairas/ReactESP)

  Built by Khoi Hoang https://github.com/khoih-prog/React_Generic
*****************************************************************************************************************************/

#include <Arduino.h>
#include <React_Generic.h>

using namespace react_generic;

#if defined(ESP32)
  #define LED_PIN         2
#elif defined(LED_BUILTIN)
  #define LED_PIN         LED_BUILTIN
#elif !defined(LED_BUILTIN)
  #define LED_PIN         13
#endif

int led_state = 0;

React_Generic app;

void setup()
{
  Serial.begin(115200);

  while (!Serial);

  delay(500);

  Serial.print("Starting React_Generic minimal on ");

#if ( defined(ESP32) || defined(ESP8266) )
  Serial.println(ARDUINO_BOARD);
#else
  Serial.println(BOARD_NAME);
#endif

  Serial.println(REACT_GENERIC_VERSION);

  pinMode(LED_PIN, OUTPUT);

  Serial.println("Setting up timed reactions");

  // toggle LED every 400 ms
  app.onRepeat(400, [] ()
  {
    led_state = !led_state;
    digitalWrite(LED_PIN, led_state);
  });

  // Additionally, toggle LED every 1020 ms.
  // This adds an irregularity to the LED blink pattern.
  app.onRepeat(1020, [] ()
  {
    led_state = !led_state;
    digitalWrite(LED_PIN, led_state);
  });
}

void loop()
{
  app.tick();
}
