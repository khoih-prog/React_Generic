#include <Arduino.h>
#include <ReactESP.h>

using namespace reactesp;

#if defined(ESP32)
  #define LED_PIN         2
#elif defined(LED_BUILTIN)
  #define LED_PIN         LED_BUILTIN
#elif !defined(LED_BUILTIN)
  #define LED_PIN         13
#endif

#if ( ARDUINO_ESP32C3_DEV )
  // To be changed according to board and architecture
  #define OUT_PIN           2
  #define INPUT_PIN1        2
  #define INPUT_PIN2        2
#else
  // To be changed according to board and architecture
  #define OUT_PIN           14        // Pin D14 mapped to pin GPIO14/HSPI_SCK/ADC16/TOUCH6/TMS of ESP32
  #define INPUT_PIN1        15        // Pin D15 mapped to pin GPIO15/HSPI_SS/ADC13/TOUCH3/TDO of ESP32
  #define INPUT_PIN2        16        // Pin D16 mapped to pin GPIO16/TX2 of ESP32
#endif

#define NUM_TEST_TIMERS   20

int tick_counter = 0;
int timer_ticks[NUM_TEST_TIMERS];

ReactESP app;

void reporter() 
{
  Serial.print("Timer ticks:");
  
  for (int i = 0; i < NUM_TEST_TIMERS; i++) 
  {
    Serial.print("   "); Serial.print(timer_ticks[i]); 
    timer_ticks[i] = 0;
  }
  
  Serial.println();
  
#if defined(ESP32)
  //Serial.printf("Free mem: %d\n", system_get_free_heap_size());
  Serial.printf("Free mem: %d\n", esp_get_free_heap_size());
#endif
  
  Serial.print("Ticks per second: ");
  Serial.println(tick_counter);
  
  tick_counter = 0;
}

void setup_timers(ReactESP &app) 
{
  // create twenty timers

  for (int i = 0; i < NUM_TEST_TIMERS; i++) 
  {
    timer_ticks[i] = 0;
    //int delay = (i + 1) * (i + 1);
    int delay = (i + 1) * 2;
    
    app.onRepeat(delay, [i]() 
    {
      timer_ticks[i]++;
    });
  }

  // create one more timer to report the counted ticks

  app.onRepeat(1000, reporter);
}

void setup_io_pins(ReactESP &app) 
{
  static ISRReaction* ire2 = nullptr;
  static int out_pin_state = 0;


  // change OUT_PIN state every 900 ms
  pinMode(OUT_PIN, OUTPUT);
  
  app.onRepeat(900, [] () 
  {
    out_pin_state = !out_pin_state;
    digitalWrite(OUT_PIN, out_pin_state);
  });

  auto reporter = [] (int pin) 
  {
    Serial.print("Change state of Pin "); Serial.println(pin);
  };

  // create an interrupt that always reports if PIN1 is rising
  app.onInterrupt(INPUT_PIN1, RISING, std::bind(reporter, INPUT_PIN1));

  // every 9s, toggle reporting PIN2 falling edge
  app.onRepeat(9000, [&app, &reporter]() 
  {
    if (ire2 == nullptr) 
    {
      ire2 = app.onInterrupt(INPUT_PIN2, FALLING, std::bind(reporter, INPUT_PIN2));
    } 
    else 
    {
      ire2->remove();
      ire2 = nullptr;
    }
  });

}

void setup_serial(ReactESP &app) 
{
  // if something is received on the serial port, turn the led off for one second
  app.onAvailable(Serial, [&app] () 
  {
    static int reaction_counter = 0;

    Serial.write(Serial.read());
    digitalWrite(LED_PIN, HIGH);

    reaction_counter++;

    int current = reaction_counter;

    app.onDelay(1000, [current] () 
    {
      if (reaction_counter == current) 
      {
        digitalWrite(LED_PIN, LOW);
      }
    });
  });
}

void setup_tick(ReactESP &app) 
{
  // increase the tick counter on every tick
  app.onTick([]() 
  {
    tick_counter++;
  });
}

void setup() 
{
  Serial.begin(115200);
  while (!Serial);

  delay(500);
  Serial.print("Starting ReactESP torture_test on "); 

#if ( defined(ESP32) || defined(ESP8266) )
  Serial.println(ARDUINO_BOARD);
#else  
  Serial.println(BOARD_NAME);
#endif
  
  pinMode(LED_PIN, OUTPUT);

  setup_timers(app);
  setup_io_pins(app);
  setup_serial(app);
  setup_tick(app);
}

void loop() 
{
  app.tick();

#if ( ARDUINO_ESP32C3_DEV )
  // For WDT
  //yield();
#endif
}
