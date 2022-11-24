/****************************************************************************************************************************
    React_Generic_Debug.h

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

#ifndef REACT_GENERIC_DEBUG_H
#define REACT_GENERIC_DEBUG_H

#ifdef REACT_GENERIC_DEBUG_PORT
  #define DBG_PORT_REACT      REACT_GENERIC_DEBUG_PORT
#else
  #define DBG_PORT_REACT      Serial
#endif

// Change _REACT_GENERIC_LOGLEVEL_ to set tracing and logging verbosity
// 0: DISABLED: no logging
// 1: ERROR: errors
// 2: WARN: errors and warnings
// 3: INFO: errors, warnings and informational (default)
// 4: DEBUG: errors, warnings, informational and debug

#ifndef _REACT_GENERIC_LOGLEVEL_
  #define _REACT_GENERIC_LOGLEVEL_       1
#endif

/////////////////////////////////////////////////////////

#define REACT_PRINT_MARK      REACT_PRINT("[REACT] ")
#define REACT_PRINT_SP        DBG_PORT_REACT.print(" ")
#define REACT_PRINT_SP0X      DBG_PORT_REACT.print(" 0x")

#define REACT_PRINT           DBG_PORT_REACT.print
#define REACT_PRINTLN         DBG_PORT_REACT.println
#define REACT_PRINTF          DBG_PORT_REACT.printf

/////////////////////////////////////////////////////////

#define REACT_DEBUG(...)                if(_REACT_GENERIC_LOGLEVEL_>3) { REACT_PRINTF(__VA_ARGS__); }
#define REACT_SSL_DEBUG(...)        if(_REACT_GENERIC_LOGLEVEL_>3) { REACT_PRINTF(__VA_ARGS__); }

#define REACT_ASSERT( a )       do{ if(!(a)){REACT_PRINTF("ASSERT: %s %u \n", __FILE__, __LINE__);}}while(0)

/////////////////////////////////////////////////////////

#define REACT_LOGERROR(x)         if(_REACT_GENERIC_LOGLEVEL_>0) { REACT_PRINT_MARK; REACT_PRINTLN(x); }
#define REACT_LOGERROR0(x)        if(_REACT_GENERIC_LOGLEVEL_>0) { REACT_PRINT(x); }
#define REACT_LOGERROR1(x,y)      if(_REACT_GENERIC_LOGLEVEL_>0) { REACT_PRINT_MARK; REACT_PRINT(x); REACT_PRINT_SP; REACT_PRINTLN(y); }
#define REACT_HEXLOGERROR1(x,y)   if(_REACT_GENERIC_LOGLEVEL_>0) { REACT_PRINT_MARK; REACT_PRINT(x); REACT_PRINT_SP0X; REACT_PRINTLN(y, HEX); }
#define REACT_LOGERROR2(x,y,z)    if(_REACT_GENERIC_LOGLEVEL_>0) { REACT_PRINT_MARK; REACT_PRINT(x); REACT_PRINT_SP; REACT_PRINT(y); REACT_PRINT_SP; REACT_PRINTLN(z); }
#define REACT_HEXLOGERROR2(x,y,z) if(_REACT_GENERIC_LOGLEVEL_>0) { REACT_PRINT_MARK; REACT_PRINT(x); REACT_PRINT_SP0X; REACT_PRINT(y, HEX); REACT_PRINT_SP0X; REACT_PRINTLN(z, HEX); }
#define REACT_LOGERROR3(x,y,z,w)  if(_REACT_GENERIC_LOGLEVEL_>0) { REACT_PRINT_MARK; REACT_PRINT(x); REACT_PRINT_SP; REACT_PRINT(y); REACT_PRINT_SP; REACT_PRINT(z); REACT_PRINT_SP; REACT_PRINTLN(w); }

/////////////////////////////////////////////////////////

#define REACT_LOGWARN(x)          if(_REACT_GENERIC_LOGLEVEL_>1) { REACT_PRINT_MARK; REACT_PRINTLN(x); }
#define REACT_LOGWARN0(x)         if(_REACT_GENERIC_LOGLEVEL_>1) { REACT_PRINT(x); }
#define REACT_LOGWARN1(x,y)       if(_REACT_GENERIC_LOGLEVEL_>1) { REACT_PRINT_MARK; REACT_PRINT(x); REACT_PRINT_SP; REACT_PRINTLN(y); }
#define REACT_HEXLOGWARN1(x,y)    if(_REACT_GENERIC_LOGLEVEL_>1) { REACT_PRINT_MARK; REACT_PRINT(x); REACT_PRINT_SP0X; REACT_PRINTLN(y, HEX); }
#define REACT_LOGWARN2(x,y,z)     if(_REACT_GENERIC_LOGLEVEL_>1) { REACT_PRINT_MARK; REACT_PRINT(x); REACT_PRINT_SP; REACT_PRINT(y); REACT_PRINT_SP; REACT_PRINTLN(z); }
#define REACT_HEXLOGWARN2(x,y,z)  if(_REACT_GENERIC_LOGLEVEL_>1) { REACT_PRINT_MARK; REACT_PRINT(x); REACT_PRINT_SP0X; REACT_PRINT(y, HEX); REACT_PRINT_SP0X; REACT_PRINTLN(z, HEX); }
#define REACT_LOGWARN3(x,y,z,w)   if(_REACT_GENERIC_LOGLEVEL_>1) { REACT_PRINT_MARK; REACT_PRINT(x); REACT_PRINT_SP; REACT_PRINT(y); REACT_PRINT_SP; REACT_PRINT(z); REACT_PRINT_SP; REACT_PRINTLN(w); }

/////////////////////////////////////////////////////////

#define REACT_LOGINFO(x)          if(_REACT_GENERIC_LOGLEVEL_>2) { REACT_PRINT_MARK; REACT_PRINTLN(x); }
#define REACT_LOGINFO0(x)         if(_REACT_GENERIC_LOGLEVEL_>2) { REACT_PRINT(x); }
#define REACT_LOGINFO1(x,y)       if(_REACT_GENERIC_LOGLEVEL_>2) { REACT_PRINT_MARK; REACT_PRINT(x); REACT_PRINT_SP; REACT_PRINTLN(y); }
#define REACT_HEXLOGINFO1(x,y)    if(_REACT_GENERIC_LOGLEVEL_>2) { REACT_PRINT_MARK; REACT_PRINT(x); REACT_PRINT_SP0X; REACT_PRINTLN(y, HEX); }
#define REACT_LOGINFO2(x,y,z)     if(_REACT_GENERIC_LOGLEVEL_>2) { REACT_PRINT_MARK; REACT_PRINT(x); REACT_PRINT_SP; REACT_PRINT(y); REACT_PRINT_SP; REACT_PRINTLN(z); }
#define REACT_HEXLOGINFO2(x,y,z)  if(_REACT_GENERIC_LOGLEVEL_>2) { REACT_PRINT_MARK; REACT_PRINT(x); REACT_PRINT_SP0X; REACT_PRINT(y, HEX); REACT_PRINT_SP0X; REACT_PRINTLN(z, HEX); }
#define REACT_LOGINFO3(x,y,z,w)   if(_REACT_GENERIC_LOGLEVEL_>2) { REACT_PRINT_MARK; REACT_PRINT(x); REACT_PRINT_SP; REACT_PRINT(y); REACT_PRINT_SP; REACT_PRINT(z); REACT_PRINT_SP; REACT_PRINTLN(w); }

/////////////////////////////////////////////////////////

#define REACT_LOGDEBUG(x)         if(_REACT_GENERIC_LOGLEVEL_>3) { REACT_PRINT_MARK; REACT_PRINTLN(x); }
#define REACT_LOGDEBUG0(x)        if(_REACT_GENERIC_LOGLEVEL_>3) { REACT_PRINT(x); }
#define REACT_LOGDEBUG1(x,y)      if(_REACT_GENERIC_LOGLEVEL_>3) { REACT_PRINT_MARK; REACT_PRINT(x); REACT_PRINT_SP; REACT_PRINTLN(y); }
#define REACT_HEXLOGDEBUG1(x,y)   if(_REACT_GENERIC_LOGLEVEL_>3) { REACT_PRINT_MARK; REACT_PRINT(x); REACT_PRINT_SP0X; REACT_PRINTLN(y, HEX); }
#define REACT_LOGDEBUG2(x,y,z)    if(_REACT_GENERIC_LOGLEVEL_>3) { REACT_PRINT_MARK; REACT_PRINT(x); REACT_PRINT_SP; REACT_PRINT(y); REACT_PRINT_SP; REACT_PRINTLN(z); }
#define REACT_HEXLOGDEBUG2(x,y,z) if(_REACT_GENERIC_LOGLEVEL_>3) { REACT_PRINT_MARK; REACT_PRINT(x); REACT_PRINT_SP0X; REACT_PRINT(y, HEX); REACT_PRINT_SP0X; REACT_PRINTLN(z, HEX); }
#define REACT_LOGDEBUG3(x,y,z,w)  if(_REACT_GENERIC_LOGLEVEL_>3) { REACT_PRINT_MARK; REACT_PRINT(x); REACT_PRINT_SP; REACT_PRINT(y); REACT_PRINT_SP; REACT_PRINT(z); REACT_PRINT_SP; REACT_PRINTLN(w); }

/////////////////////////////////////////////////////////

#endif    //REACT_GENERIC_DEBUG_H
