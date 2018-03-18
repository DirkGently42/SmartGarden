
//This file was written before I got some of the hardware I needed to complete the project.
//Thus, some of this is untested, and subject to change.
//Most notably, I have yet to test the SoftwarSerial class.
//The current implementation is from looking at Arduino Implementation.


#include <SoftwareSerial.h>

#define rx_pin 8
#define tx_pin 9
#define W_pin 0
#define T_pin 1
#define H_pin 2
#define L_pin 3
#define Delay_Time 3000

SoftwareSerial mySerial(rx_pin, tx_pin);

int Water_Sensor_Read = 0;
int Temp_Sensor_Read = 0;
int Humid_Sensor_Read = 0;
int Light_Sensor_Read = 0;


void setup() {
  // put your setup code here, to run once:
  serial.begin(9600);
  serial.println("AT");

  mySerial.begin(30800);
  mySerial.println("AT");

}

void loop() {

 Water_Sensor_Read = analogRead(W_pin); //Reads from water sensor, sends byte that was read, pauses before next read for 3 seconds
 BT_Sender(Water_Sensor_Read);          //Not sure what the delay time needs to be - further testing needed to configure for latency
 delay(Delay_Time);                     //Want the recipient to have plenty of time to wait for next sensor read
                                        // recipient script will need to be designed to recieve the sensor data in the proper order
 
 Temp_Sensor_Read = analogRead(T_pin); // Temperature
 BT_Sender(Temp_Sensor_Read);
 delay(Delay_Time);
 
 Humid_Sensor_Read = analogRead(H_pin); // Humidity
 BT_Sender(Humid_Sensor_Read);
 delay(Delay_Time);
 
 Light_Sensor_Read = analogRead(L_pin); // Light 
 BT_Sender(Light_Sensor_Read);
 delay(Delay_Time);

}

void BT_Sender(int Sensor_Value){ //Generic function for sending any sensor value via BlueTooth
   mySerial.write(Sensor_Value);
}

