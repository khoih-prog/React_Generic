/****************************************************************************************************************************
  multiFileProject.h
  React_Generic is a library for ESP32, ESP8266, Protenta_H7, STM32F7, etc.
  
  Based on and modified from :
  
  1) Reactduino   (https://github.com/Reactduino/Reactduino)
  2) ReactESP     (https://github.com/mairas/ReactESP)
  
  Built by Khoi Hoang https://github.com/khoih-prog/React_Generic
*****************************************************************************************************************************/

// To demo how to include files in multi-file Projects

#pragma once

#define _TEENSY41_ASYNC_TCP_LOGLEVEL_       1

// Can be included as many times as necessary, without `Multiple Definitions` Linker Error
#include <React_Generic.hpp>        // https://github.com/khoih-prog/React_Generic
