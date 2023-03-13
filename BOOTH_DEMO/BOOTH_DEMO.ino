
#include "FlexCAN.h"
#include "kinetis_flexcan.h"
#include "Metro.h"
#include "Arduino.h"

#include <Wire.h>


// Flexcan
FlexCAN Can0(1000000);
// Message Structure - Little Endian
// Bytes 0-1 : uint16_t - 
// Bytes 2-3 : uint16_t - 
// Bytes 4-7 : uint32_t - POT_data
// 
// To evaluate after transmission all variables will be divided by 100 and cast
// to a float32.
static CAN_message_t msg{.id=0x300, .ext=1, .len=4}; //ID is 0, and is an extended frame

// Timer
Metro timer = Metro(250); // 4hz

//Potentiometer
#define Pot_Pin 18 //SDA pin on Torpedo board

// Led 
const int LED_PIN = 13;
bool led_status;

// Data for casting into msg
int32_t POT_data;

unsigned char *POT_data_array = 0x00000000;
uint32_t mid_val = 500;

void setup() {
    Serial.begin(9600);
    Serial.println("Setup start");
    
    pinMode(LED_PIN, OUTPUT);

    Can0.begin();
    Wire.begin();
    
    delay(1000);
   
    Serial.println("Setup complete"); 
}

void loop() {


    if (timer.check()) {

      

        // read Potentiometer
       POT_data = analogRead(Pot_Pin);
      
      if (POT_data < mid_val-200){
        POT_data = -2000; //assuming it sends -2000 rpm (reverse)
      }
      else if(POT_data > mid_val+200){
        POT_data = 2000; // assuming it sends 2000 rpm
      }
      else{
        POT_data = 0;
        }


        Serial.print("RPM: ");
        Serial.println(POT_data);


        // Blink LED 
        POT_data = POT_data / 2;
        led_status = true != led_status;
        digitalWrite(LED_PIN, led_status);
        
        // Build can frame by casting into char arrays
        POT_data_array = reinterpret_cast<unsigned char *>(&POT_data);
        msg.buf[3] = POT_data_array[3];
        msg.buf[2] = POT_data_array[2];
        msg.buf[1] = POT_data_array[1];
        msg.buf[0] = POT_data_array[0];
  
               
        if(Can0.write(msg)){
          Serial.println("Can Frame Sent");
        }
    }   
}
