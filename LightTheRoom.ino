/* 
   Light the room
   This program is turning on the LED on the board, as long as the room is dark.

   compunents:
   LED, Photoresistor, 6 wires, 220 ohm resistor, 10k ohm resistor, breadboard, Arduino Uno.

   Created by Yehonatan Ben-Harush February 2019.
   Hebrew demonstration video:
   https://youtu.be/w8Bf1UlwXX0
 */


//Variables
int THvalue;          // Store threshold value from photoresistor (0-1023)

void setup(){
  Serial.begin(9600); // Set the serial
 pinMode(6, OUTPUT);  // Set pin 6 as an output for the LED
 pinMode(A0, INPUT);// Set pin A0 as an input for the photoresistor
}

void loop(){
  THvalue = analogRead(A0);
  Serial.println(THvalue); // Print the value of the photoresistor to the serial in order to set the thershod value
  if (THvalue > 700){
    digitalWrite(6, LOW);  //if the room is light, turn led off
  }
  else{
    digitalWrite(6, HIGH); //if the room is dark, turn led on
  }
 }
