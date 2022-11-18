# React_Generic

[![arduino-library-badge](https://www.ardu-badge.com/badge/React_Generic.svg?)](https://www.ardu-badge.com/React_Generic)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/React_Generic.svg)](https://github.com/khoih-prog/React_Generic/releases)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/React_Generic.svg)](http://github.com/khoih-prog/React_Generic/issues)
![C++](https://img.shields.io/badge/language-C++-blue.svg)
[![license: MIT](https://img.shields.io/badge/license-MIT-brightgreen.svg)](https://opensource.org/licenses/MIT)

---
---

## Table of Contents

* [Why do we need this React_Generic library](#why-do-we-need-this-React_Generic-library)
  * [Features](#features)
  * [Currently supported Boards](#currently-supported-boards)
* [Changelog](changelog.md)
* [Prerequisites](#prerequisites)
* [Installation](#installation)
  * [Use Arduino Library Manager](#use-arduino-library-manager)
  * [Manual Install](#manual-install)
  * [VS Code & PlatformIO](#vs-code--platformio)
* [HOWTO Use](#howto-use)
  * [Blink](#Blink)
  * [Why Bother?](#Why-Bother)
  * [Advanced callback support](#Advanced-callback-support)
* [API](#API)
  * [Namespace use](#Namespace-use)
  * [Event Registration Functions](#Event-Registration-Functions)
  * [Management functions](#Management-functions)
* [Examples](#examples)
  * [Original Examples](#original-examples)
    * [ 1. minimal](examples/minimal)
    * [ 2. torture_test](examples/torture_test)
  * [multiFileProject Examples](#multiFileProject-examples)
    * [ 1. multiFileProject](examples/multiFileProject) 
* [Issues](#issues)
* [TO DO](#to-do)
* [DONE](#done)
* [Contributions and Thanks](#contributions-and-thanks)
* [Contributing](#contributing)
* [License](#license)
* [Copyright](#copyright) 
  
---
---

### Why do we need this [React_Generic library](https://github.com/khoih-prog/React_Generic)

#### Features

By 

- [Andrew Carter](https://github.com/AndrewCarterUK)
- [Matti Airas](https://github.com/mairas)
- [Khoi Hoang](https://github.com/khoih-prog)

An asynchronous programming library for the generic microcontrollers using the Arduino framework. Currently supporting ESP32, ESP8266, SAMD21/SAMD51, RP2040, STM32, nRF52, Teensy 4.x

The library is at the core of the [SensESP](https://github.com/SignalK/SensESP) project but is completely generic and can be used for standalone projects without issues.

This library gets much of its inspiration (and some code) from [`Reactduino`](https://github.com/Reactduino/Reactduino). `React_Generic`, however, has been internally re-implemented for maintainability and readability, and has significantly better performance when there are lots of defined reactions. It also supports arbitrary callables as callbacks, allowing parametric creation of callback functions.

#### Currently supported Boards

This [**React_Generic** library](https://github.com/khoih-prog/React_Generic) currently supports these following boards:

 1. **ESP32**
 
 2. **ESP8266**
 
 3. **WT32_ETH01 (ESP32 + LAN8720A)**
 
 4. **STM32F/L/H/G/WB/MP1 boards with built-in Ethernet LAN8742A** such as :

  - **Nucleo-144 (F429ZI, F767ZI)**
  - **Discovery (STM32F746G-DISCOVERY)**
  - **All STM32 boards (STM32F/L/H/G/WB/MP1) with 32K+ Flash, with Built-in Ethernet**
  
 5. **STM32F4/F7 boards using Ethernet LAN8720** such as :

  - **Nucleo-144 (F429ZI, NUCLEO_F746NG, NUCLEO_F746ZG, NUCLEO_F756ZG)**
  - **Discovery (DISCO_F746NG)**
  - **STM32F4 boards (BLACK_F407VE, BLACK_F407VG, BLACK_F407ZE, BLACK_F407ZG, BLACK_F407VE_Mini, DIYMORE_F407VGT, FK407M1)** 
  
  `Note: Must use with STM32 core v2.2.0-`
  
 6. **SAMD21/SAMD51**
 
 7. **nRF52 boards**, such as **AdaFruit Feather nRF52832, nRF52840 Express, BlueFruit Sense, Itsy-Bitsy nRF52840 Express, Metro nRF52840 Express, NINA_B302_ublox, NINA_B112_ublox, etc.**
 
 8. **Teensy 4.1 using QNEthernet Library**
 
 9. **RASPBERRY_PI_PICO** using [**arduino-pico core v2.5.2+**](https://github.com/earlephilhower/arduino-pico)
  

---
---

## Prerequisites

 1. [`Arduino IDE 1.8.19+` for Arduino](https://github.com/arduino/Arduino). [![GitHub release](https://img.shields.io/github/release/arduino/Arduino.svg)](https://github.com/arduino/Arduino/releases/latest)
 2. [`ESP32 Core 2.0.4+`](https://github.com/espressif/arduino-esp32) for ESP32-based boards. [![Latest release](https://img.shields.io/github/release/espressif/arduino-esp32.svg)](https://github.com/espressif/arduino-esp32/releases/latest/)
 3. [`ESP8266 Core 3.0.2+`](https://github.com/esp8266/Arduino) for ESP8266-based boards. [![Latest release](https://img.shields.io/github/release/esp8266/Arduino.svg)](https://github.com/esp8266/Arduino/releases/latest/).
 4. [`Adafruit nRF52 v1.3.0+`](https://github.com/adafruit/Adafruit_nRF52_Arduino) for nRF52 boards such as Adafruit NRF52840_FEATHER, NRF52832_FEATHER, NRF52840_FEATHER_SENSE, NRF52840_ITSYBITSY, NRF52840_CIRCUITPLAY, NRF52840_CLUE, NRF52840_METRO, NRF52840_PCA10056, PARTICLE_XENON, **NINA_B302_ublox**, etc. [![GitHub release](https://img.shields.io/github/release/adafruit/Adafruit_nRF52_Arduino.svg)](https://github.com/adafruit/Adafruit_nRF52_Arduino/releases/latest)
 5. [`Teensy core v1.57+`](https://www.pjrc.com/teensy/td_download.html) for Teensy (4.1, 4.0, 3.6, 3.5, 3,2, 3.1, 3.0) boards.
 6. [`ArduinoCore-mbed mbed_rp2040, mbed_nano, mbed_portenta core 3.3.0+`](https://github.com/arduino/ArduinoCore-mbed) for Arduino (Use Arduino Board Manager) **Portenta_H7, RP2040-based boards, such as Nano_RP2040_Connect, RASPBERRY_PI_PICO**. [![GitHub release](https://img.shields.io/github/release/arduino/ArduinoCore-mbed.svg)](https://github.com/arduino/ArduinoCore-mbed/releases/latest)
 7. [`Earle Philhower's arduino-pico core v2.5.2+`](https://github.com/earlephilhower/arduino-pico) for RP2040-based boards such as **RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, etc. [![GitHub release](https://img.shields.io/github/release/earlephilhower/arduino-pico.svg)](https://github.com/earlephilhower/arduino-pico/releases/latest)
 8. [`Arduino SAM DUE core v1.6.12+`](https://github.com/arduino/ArduinoCore-sam) for SAM DUE ARM Cortex-M3 boards.
 9. [`Arduino SAMD core 1.8.13+`](https://github.com/arduino/ArduinoCore-samd) for SAMD ARM Cortex-M0+ boards. [![GitHub release](https://img.shields.io/github/release/arduino/ArduinoCore-samd.svg)](https://github.com/arduino/ArduinoCore-samd/releases/latest)
10. [`Adafruit SAMD core 1.7.10+`](https://github.com/adafruit/ArduinoCore-samd) for SAMD ARM Cortex-M0+ and M4 boards (Nano 33 IoT, etc.). [![GitHub release](https://img.shields.io/github/release/adafruit/ArduinoCore-samd.svg)](https://github.com/adafruit/ArduinoCore-samd/releases/latest)
11. [`Seeeduino SAMD core 1.8.3+`](https://github.com/Seeed-Studio/ArduinoCore-samd) for SAMD21/SAMD51 boards (XIAO M0, Wio Terminal, etc.). [![Latest release](https://img.shields.io/github/release/Seeed-Studio/ArduinoCore-samd.svg)](https://github.com/Seeed-Studio/ArduinoCore-samd/releases/latest/)

---
---

## Installation

### Use Arduino Library Manager

The best and easiest way is to use `Arduino Library Manager`. Search for `React_Generic`, then select / install the latest version.
You can also use this link [![arduino-library-badge](https://www.ardu-badge.com/badge/React_Generic.svg?)](https://www.ardu-badge.com/React_Generic) for more detailed instructions.

### Manual Install

1. Navigate to [React_Generic](https://github.com/khoih-prog/React_Generic) page.
2. Download the latest release `React_Generic-main.zip`.
3. Extract the zip file to `React_Generic-main` directory 
4. Copy the whole `React_Generic-main` folder to Arduino libraries' directory such as `~/Arduino/libraries/`.

### VS Code & PlatformIO:

1. Install [VS Code](https://code.visualstudio.com/)
2. Install [PlatformIO](https://platformio.org/platformio-ide)
3. Install [**React_Generic** library](https://registry.platformio.org/libraries/khoih-prog/React_Generic) by using [Library Manager](https://registry.platformio.org/libraries/khoih-prog/React_Generic/installation). Search for React_Generic in [Platform.io Author's Libraries](https://platformio.org/lib/search?query=author:%22Khoi%20Hoang%22)
4. Use included [platformio.ini](platformio/platformio.ini) file from examples to ensure that all dependent libraries will installed automatically. Please visit documentation for the other options and examples at [Project Configuration File](https://docs.platformio.org/page/projectconf.html)

---
---

## HOWTO Use

### Blink

If you have worked with the Arduino framework before, it is likely that you will have come across the [blink sketch](https://www.arduino.cc/en/tutorial/blink). This is a simple program that flashes an LED every second, and it looks something like this:

```cpp
#include <Arduino.h>

void setup() 
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() 
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}
```

Using React_Generic, the sketch can be rewritten to the following:

```cpp
#include <React_Generic.h>

using namespace react_generic;

React_Generic app;

setup() 
{
  pinMode(LED_BUILTIN, OUTPUT);

  app.onRepeat(1000, [] () 
  {
      static bool state = false;
      digitalWrite(LED_BUILTIN, state = !state);
  });
}

void loop() 
{
  app.tick();
}
```

Instead of directly defining the program logic in the `loop()` function, _reactions_ are defined in the `setup()` function. A reaction is a function that is executed when a certain event happens. In this case, the event is that the function should repeat every second, as defined by the `onRepeat()` method call. The second argument to the `onRepeat()` method is a [lambda function](http://en.cppreference.com/w/cpp/language/lambda) that is executed every time the reaction is triggered. If the syntax feels weird, you can also use regular named functions instead of lambdas.

The `app.tick()` call in the `loop()` function is the main loop of the program. It is responsible for calling the reactions that have been defined. You can also add additional code to the `loop()` function, any delays or other long-executing code should be avoided.

---

### Why Bother?

Charlie wants to make a simple program which echoes data on the `Serial` port. Their Arduino sketch will looks like this:

```cpp
#include <Arduino.h>

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    if (Serial.available() > 0) 
    {
        Serial.write(Serial.read());
    }

    yield();
}
```

This works, but Charlie decides that they would like to blink the built-in LED every time it processes data. Now, their sketch looks like this:

```cpp
#include <Arduino.h>

void setup()
{
    Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
    if (Serial.available() > 0) 
    {
        Serial.write(Serial.read());

        digitalWrite(LED_BUILTIN, HIGH);
        delay(20);
        digitalWrite(LED_BUILTIN, LOW);
    }

    yield();
}
```

The problem with this sketch is that whilst the LED is blinking, Charlie's program is not relaying data from the Serial port. The longer Charlie blinks the LED for, the slower the rate of transfer.

To solve this problem, Charlie refactors their code to look something like this:

```cpp
#include <Arduino.h>

uint32_t start;
bool blink = false;

void setup()
{
    Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
    if (Serial.available() > 0) 
    {
        Serial.write(Serial.read());

        blink = true;
        start = millis();
        digitalWrite(LED_BUILTIN, HIGH);
    }

    if (blink && millis() - start > 1000) 
    {
        blink = false;
        digitalWrite(LED_BUILTIN, LOW);
    }

    yield();
}
```

This solves Charlie's problem, but it's quite verbose. Using React_Generic, Charlie can write the same script like this:

```c++
#include <React_Generic.h>

using namespace react_generic;

React_Generic app;

void setup() 
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);

  app.onAvailable(&Serial, [] () 
  {
    Serial.write(Serial.read());
    digitalWrite(LED_BUILTIN, HIGH);

    app.onDelay(1000, [] () { digitalWrite(LED_BUILTIN, LOW); });
  });
}

void loop() 
{
  app.tick();
}
```

---

### Advanced callback support

Callbacks can be not just void pointers but any callable supported by `std::function`. This means they can use lambda captures or argument binding using `std::bind`. For example, the following code creates 20 different repeating reactions updating different fields of an array:

```c++
static int timer_ticks[20];

for (int i=0; i<20; i++) 
{
  timer_ticks[i] = 0;
  int delay = (i+1)*(i+1);
  app.onRepeat(delay, [i]() 
  {
    timer_ticks[i]++;
  });
}
```

---
---

## API

### Namespace use

Note that beginning of React_Generic 2.0.0, the React_Generic library has been wrapped in
a `React_Generic` namespace.
This is to avoid name conflicts with other libraries.

The impact to the user is that they need to define the namespace when using the library.
This can be done either globally by placing the following statement in the source code right after the `#include` statements:

    using namespace react_generic;

or by using the `react_generic::` prefix when using the library:

    react_generic::React_Generic app;

### Event Registration Functions

All of the registration functions return a `Reaction` object pointer. This can be used to store and manipulate
the reaction. `react_callback` is a typedef for `std::function<void()>` and can therefore be any callable supported by the C++ standard template library.

```cpp
DelayReaction app.onDelay(uint32_t t, react_callback cb);
```

Delay the execution of a callback by `t` milliseconds.

```cpp
RepeatReaction app.onRepeat(uint32_t t, react_callback cb);
```

Repeatedly execute a callback every `t` milliseconds.

```cpp
StreamReaction app.onAvailable(Stream *stream, react_callback cb);
```

Execute a callback when there is data available to read on an input stream (such as `&Serial`).

```cpp
ISRReaction app.onInterrupt(uint8_t pin_number, int mode, react_callback cb);
```

Execute a callback when an interrupt number fires. This uses the same API as the `attachInterrupt()` Arduino function.

```cpp
TickReaction app.onTick(react_callback cb);
```

Execute a callback on every tick of the event loop.

### Management functions

```cpp
void Reaction::remove();
```

Remove the reaction from the execution queue.

*Note*: Calling `remove()` for `DelayReaction` objects is only safe if the reaction has not been triggered yet. Upon triggering, the `DelayReaction` object is deleted and any pointers to it will be invalidated


---
---

### Examples:

#### Original Examples

 1. [`minimal`](examples/minimal): A minimal example with two timers switching the LED state.
 2. [`torture_test`](examples/torture_test): A stress test of twenty simultaneous repeat reactions as well as a couple of interrupts, a stream, and a tick reaction. For kicks, try changing `NUM_TIMERS` to 200. Program performance will be practically unchanged!

#### multiFileProject Examples

- [`multiFileProject`](examples/multiFileProject)

---
---


### Issues ###

Submit issues to: [React_Generic issues](https://github.com/khoih-prog/React_Generic/issues)

---

### TO DO

1. Bug Searching and Killing
2. Support more types of boards

### DONE

 1. Add support to **Arduino SAMD21 (ZERO, MKR, NANO_33_IOT, etc.)**
 2. Add support to **Adafruit SAMD21 (Itsy-Bitsy M0, Metro M0, Feather M0 Express, etc.)**.
 3. Add support to **Adafruit SAMD51 (Itsy-Bitsy M4, Metro M4, Grand Central M4, Feather M4 Express, etc.)**.
 4. Add support to **Adafruit nRF52 ( Feather nRF52832, nRF52840 Express, BlueFruit Sense, Itsy-Bitsy nRF52840 Express, Metro nRF52840 Express, NINA_B302_ublox, NINA_B112_ublox, etc.**.
 5. Add support to RP2040-based boards such as RASPBERRY_PI_PICO, using [**Arduino-mbed RP2040** core](https://github.com/arduino/ArduinoCore-mbed)
 6. Add support to RP2040-based boards such as RASPBERRY_PI_PICO, using [**Earle Philhower's arduino-pico** core](https://github.com/earlephilhower/arduino-pico)
 7. Add support to Teensy

---
---

### Contributions and Thanks

Many thanks for everyone for bug reporting, new feature suggesting, testing and contributing to the development of this library.

1. Based on and modified from [Andrew Carter's Reactduino](https://github.com/Reactduino/Reactduino)
2. Based on and modified from [Matti Airas' ReactESP](https://github.com/mairas/ReactESP)


<table>
  <tr>
    <td align="center"><a href="https://github.com/AndrewCarterUK"><img src="https://github.com/AndrewCarterUK.png" width="100px;" alt="AndrewCarterUK"/><br /><sub><b>⭐️ Andrew Carter</b></sub></a><br /></td>
    <td align="center"><a href="https://github.com/mairas"><img src="https://github.com/mairas.png" width="100px;" alt="mairas"/><br /><sub><b>⭐️ Matti Airas</b></sub></a><br /></td>
  </tr> 
</table>

---

### Contributing

If you want to contribute to this project:
- Report bugs and errors
- Ask for enhancements
- Create issues and pull requests
- Tell other people about this library

---
---

### License

- The library is licensed under [MIT](https://github.com/khoih-prog/React_Generic/blob/main/LICENSE)

---


## Copyright


- Copyright 2017- Andrew Carter
- Copyright 2019- Matti Airas
- Copyright 2022- Khoi Hoang

  
