/****************************************************************************************************************************
    React_Generic.h

    React_Generic is a library for ESP32, ESP8266, Protenta_H7, STM32F7, etc.

    Based on and modified from :

    1) Reactduino   (https://github.com/Reactduino/Reactduino)
    2) ReactESP     (https://github.com/mairas/ReactESP)

    Built by Khoi Hoang https://github.com/khoih-prog/React_Generic

    Version: 2.1.0

    Version Modified By   Date      Comments
    ------- -----------  ---------- -----------
    2.1.0    K Hoang     23/03/2022 Initial porting and coding to support ESP32, ESP8266, RP2040, STM32, nRF52, Teensy 4.x
 *****************************************************************************************************************************/

#pragma once

#ifndef REACT_GENERIC_H_
#define REACT_GENERIC_H_

#include <Arduino.h>

#if (defined(NRF52840_FEATHER) || defined(NRF52832_FEATHER) || defined(NRF52_SERIES) || defined(ARDUINO_NRF52_ADAFRUIT) || \
      defined(NRF52840_FEATHER_SENSE) || defined(NRF52840_ITSYBITSY) || defined(NRF52840_CIRCUITPLAY) || \
      defined(NRF52840_CLUE) || defined(NRF52840_METRO) || defined(NRF52840_PCA10056) || defined(PARTICLE_XENON) || \
      defined(MDBT50Q_RX) || defined(NINA_B302_ublox) || defined(NINA_B112_ublox) )
#include <Adafruit_TinyUSB.h>

#define REACT_GENERIC_USING_NRF52             true

#elif ( defined(__arm__) && defined(TEENSYDUINO) && defined(__IMXRT1062__) )

// For Teensy 4.0/4.1
#if defined(ARDUINO_TEENSY41)
  #warning Using Teensy 4.1

  #ifndef BOARD_NAME
    #define BOARD_NAME                        "Teensy 4.1"
  #endif
#else
  #warning Using Teensy 4.0

  #ifndef BOARD_NAME
    #define BOARD_NAME                        "Teensy 4.0"
  #endif
#endif

#define REACT_GENERIC_USING_TEENSY4           true
#endif

#include "React_Generic.hpp"
#include "React_Generic_Impl.h"

#endif      // REACT_GENERIC_H_
