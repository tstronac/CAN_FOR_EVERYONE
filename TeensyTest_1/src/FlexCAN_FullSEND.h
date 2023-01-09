#include <Arduino.h>
#include <Metro.h>
#include <FlexCAN.h>


Metro sysTimer = Metro(1);// milliseconds

FlexCAN CANbus(500000);

static CAN_message_t tx_msg, rx_msg;
static uint8_t hex[17] = "0123456789abcdef";
int txCount,rxCount;
unsigned int txTimer,rxTimer;

const int transmitledPin = 13;

static uint8_t message_array [8];
static uint8_t store_array [8];
//*****************CAN TRANMISSION**************************

//send and recieve data, alot of this needs to go

void can_tx(void)
{
  // service software timers based on Metro tick
  if ( sysTimer.check() ) {
    if ( txTimer ) {
      --txTimer;
    }
  }

  // if not time-delayed, read CAN messages and print 1st byte

  
  // insert a time delay between transmissions
  if ( !txTimer ) {
    // if frames were received, print the count
    if ( rxCount ) {
      Serial.write('=');
      Serial.print(rxCount);
      rxCount = 0;
    }

    //This will need to be changed. 
    //Need a proper ID
    //Proper Message structure 
    txTimer = 100;//milliseconds
    tx_msg.len = 8;
    tx_msg.id = 0x222;
    

// //Move Data to transmit buffer
    for(int idx=0; idx<4; ++idx ) {
      tx_msg.buf[idx] = (uint8_t)message_array[idx];
    }

//SEND Data 
    
    digitalWrite(transmitledPin, 1);
    Serial.println(".");
    
     txCount = 6;
    digitalWrite(transmitledPin, 1);
    Serial.println(".");
    while ( txCount-- ) {
      CANbus.write(tx_msg);
      tx_msg.buf[0]++;
    }

    Serial.println("Sent");  
    digitalWrite(transmitledPin, 0);
    // time delay to force some rx data queue use
    rxTimer = 3;//milliseconds
  }
}
// -------------------------------------------------------------




// *******************CAN recieving***************************** 

// CANbus.read will continue reading until the ring buffer is empty


void can_rx(void){

  // service software timers based on Metro tick
if ( sysTimer.check() ) {
    if ( rxTimer ) {
      --rxTimer;
    }
  }


  if ( !rxTimer ) {
    while ( CANbus.read(rx_msg) ) {
      
      Serial.write(rx_msg.buf[0]);
     
      rxCount++; //Counts number of messages 
    }
  }

}

// -------------------------------------------------------------


//********************READ CAN RX*******************************

void read_rx_buff(){
    for (int i = 0; i < 8; i++)
    rx_msg.buf[i] =  store_array[i];
}

// -------------------------------------------------------------
