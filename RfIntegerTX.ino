#include <VirtualWire.h> // Library Required

int TX_PIN = 3;// Tell Arduino on which pin you would like to Transmit data NOTE should be a PWM Pin
int TX_ID = 3; // Transmitter ID address

struct roverRemoteData// Data Structure 
{
int    TX_ID;      // Initialize a storage place for the outgoing TX ID
int    Sensor1Data;// Initialize a storage place for the first integar that you wish to Send 
int    Sensor2Data;// Initialize a storage place for the Second integar that you wish to Send
int    Sensor3Data;// Initialize a storage place for the Third integar that you wish to Send
int    Sensor4Data;// Initialize a storage place for the Forth integar that you wish to Send


};

void setup() {
              Serial.begin(9600);// Begin Serial port at a Buad speed of 9600bps 
              vw_setup(2000);// Setup and Begin communication over the radios at 2000bps( MIN Speed is 1000bps MAX 4000bps)
              vw_set_tx_pin(TX_PIN);// Set Tx Pin
              pinMode(2, OUTPUT);
              digitalWrite(2, HIGH);
              }
void loop()
{
  struct roverRemoteData payload;// In this section is where you would load the data that needs to be sent.
  
  // If you want to read a analog pin and transmit its value you can do it as follows by removing the "//" 
  payload.TX_ID = TX_ID; // Set the Radio Address 
  payload.Sensor1Data =100;// analogRead(Sensor1Pin);
  payload.Sensor2Data =1;// analogRead(Sensor2Pin);
  payload.Sensor3Data =1;// analogRead(Sensor3Pin);
  payload.Sensor4Data =1;// analogRead(Sensor4Pin);
 
  
  
  vw_send((uint8_t *)&payload, sizeof(payload)); // Send the data 
  vw_wait_tx();// Wait for all data to be sent 
  

}

