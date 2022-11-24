/****************************************************************************************************************************
  multiFileProject.ino
  React_Generic is a library for ESP32, ESP8266, Protenta_H7, STM32F7, etc.

  Based on and modified from :

  1) Reactduino   (https://github.com/Reactduino/Reactduino)
  2) ReactESP     (https://github.com/mairas/ReactESP)

  Built by Khoi Hoang https://github.com/khoih-prog/React_Generic
*****************************************************************************************************************************/

// To demo how to include files in multi-file Projects

#define REACT_GENERIC_VERSION_MIN_TARGET      "React_Generic v2.1.0"
#define REACT_GENERIC_VERSION_MIN             2001000

#include "multiFileProject.h"

// To be included only in main(), .ino with setup() to avoid `Multiple Definitions` Linker Error
#include <React_Generic.h>        // https://github.com/khoih-prog/React_Generic

using namespace react_generic;

void setup()
{
  Serial.begin(115200);

  while (!Serial);

  delay(500);

  Serial.println("\nStart multiFileProject on ");

#if ( defined(ESP32) || defined(ESP8266) )
  Serial.println(ARDUINO_BOARD);
#else
  Serial.println(BOARD_NAME);
#endif

  Serial.println(REACT_GENERIC_VERSION);

#if defined(REACT_GENERIC_VERSION_MIN)

  if (REACT_GENERIC_VERSION_INT < REACT_GENERIC_VERSION_MIN)
  {
    Serial.print("Warning. Must use this example on Version equal or later than : ");
    Serial.println(REACT_GENERIC_VERSION_MIN_TARGET);
  }

#endif

  Serial.print("You're OK now");
}

void loop()
{
  // put your main code here, to run repeatedly:
}
