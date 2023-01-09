#include <Arduino.h>
#include "Arduino.h"
#include "running_average.hpp"
#include "watchdog.h"
#include <Metro.h>
#include <Wire.h>
#include "sensor_functions.h"
#include "lcd_functions.h"
#include "batteryStatus.hpp"


static constexpr float framerate = 100;
extern Running_Average<uint32_t, SAMPLES_PER_SECOND> avg_pressure;
extern Running_Average<float, SAMPLES_PER_SECOND> avg_temperature;
extern Running_Average<float, SAMPLES_PER_SECOND> avg_humidity;


Metro timer = Metro(1000/SAMPLES_PER_SECOND);
uint8_t timerCounter;
uint16_t lcdCounter = 0;
boolean lcdMode = false;


void setup() {
 
Serial.begin(9600);
    delay(1000);
    Serial.println("Setup start"); 

 timerCounter = 0;

pinMode( 10, OUTPUT);

 setupMPL();

   setup_lcd(); //IDK if LCD will be ready in time. 

}



void loop() {


  digitalWrite(10, LOW);
  Serial.println("LED off ");
  delay (1000);
  
  digitalWrite(10, HIGH);
  Serial.println("LED on");
  delay(1000);
  

KickDog();
    if(timer.check() == 1) {
      timerCounter++;

      // read humidity and temperature
      measureHIH7120();
      avg_humidity.AddSample(humidity());
      avg_temperature.AddSample(temp());

      // read pressure
      readPressureMPL();
      avg_pressure.AddSample(pressure());

      // publish once every second
      if (timerCounter == SAMPLES_PER_SECOND) {
        // -- Replace with FlexCAN transmission 
        Serial.println("Reading...");
        Serial.print("Humidity: ");
        Serial.println(avg_humidity.Average());
        Serial.print("Temperature: ");
        Serial.println(avg_temperature.Average());
        Serial.print("Pressure: ");
        Serial.println(avg_pressure.Average());
		
		//Print out battery voltages --- Is this needed? How do you send a frame to multiple devices? Can 

		Serial.print("Battery 1: ");
		Serial.println(batteryVoltage[0]);
		Serial.print("Battery 2: ");
		Serial.println(batteryVoltage[1]);
		Serial.print("Battery 3: ");
		Serial.println(batteryVoltage[2]);
		Serial.print("Battery 4: ");
		Serial.println(batteryVoltage[3]);

        lcdCounter++;

        if(lcdCounter%6 == 0){
            lcdMode = !lcdMode;
        }

        //Alternate data displayed to LCD every six seconds
        if(lcdMode == true){
            display_to_lcd(avg_temperature.Average(), avg_humidity.Average(), avg_pressure.Average());
        } 
        else {
            display_voltages_to_lcd(batteryVoltage[0], batteryVoltage[1], batteryVoltage[2], batteryVoltage[3]);
        }


        timerCounter = 0;
      }
    }

}