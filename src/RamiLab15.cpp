/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/ramikhosho/RamiLab15/src/RamiLab15.ino"
#include "oled-wing-adafruit.h"
// #include "WatchDog_WCL.h"

void setup();
void loop();
void resetDisplay();
#line 4 "/Users/ramikhosho/RamiLab15/src/RamiLab15.ino"
SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

OledWingAdafruit display;

#define WD D5


void setup()
{
  Serial.begin(9600);
  display.setup();
  display.setTextSize(1);
  display.setTextColor(WHITE);

  if (System.resetReason() == RESET_REASON_WATCHDOG)
  {
    resetDisplay();
    display.println("Watchdog Reset!");
    Serial.println("Watchdog Reset!");
    display.display();
  }
  else
  {
    resetDisplay();
    display.println("Other Reset!");
    Serial.println("Other Reset!");
    display.display();
  }

  pinMode(WD, INPUT_PULLUP);

  delay(1000);

  Watchdog.init(WatchdogConfiguration().timeout(5000));
  Watchdog.start();
  Watchdog.refresh();
}
void loop()
{
  display.loop();
  if (digitalRead(WD) == LOW)
  {
    resetDisplay();
  }
  else
  {
    Watchdog.refresh();
  }
}

void resetDisplay()
{
  display.clearDisplay();
  display.setCursor(0, 0);
}