#pragma once

#ifndef REACT_GENERIC_H_
#define REACT_GENERIC_H_

#include <Arduino.h>

#include <forward_list>
#include <functional>
#include <queue>

#if (defined(NRF52840_FEATHER) || defined(NRF52832_FEATHER) || defined(NRF52_SERIES) || defined(ARDUINO_NRF52_ADAFRUIT) || \
      defined(NRF52840_FEATHER_SENSE) || defined(NRF52840_ITSYBITSY) || defined(NRF52840_CIRCUITPLAY) || \
      defined(NRF52840_CLUE) || defined(NRF52840_METRO) || defined(NRF52840_PCA10056) || defined(PARTICLE_XENON) || \
      defined(MDBT50Q_RX) || defined(NINA_B302_ublox) || defined(NINA_B112_ublox) )
  #include <Adafruit_TinyUSB.h>
  
  #define REACT_GENERIC_USING_NRF52				true
  
#elif ( defined(__arm__) && defined(TEENSYDUINO) && defined(__IMXRT1062__) )

  // For Teensy 4.0/4.1
  #if defined(ARDUINO_TEENSY41)
    #warning Using Teensy 4.1
    
    #ifndef BOARD_NAME
      #define BOARD_NAME          				"Teensy 4.1"
    #endif
  #else
    #warning Using Teensy 4.0
    
    #ifndef BOARD_NAME
      #define BOARD_NAME          				"Teensy 4.0"
    #endif
  #endif  

  #define REACT_GENERIC_USING_TEENSY4			true
#endif

#include "React_Generic.hpp"
#include "React_Generic_Impl.h""

#endif		// REACT_GENERIC_H_
