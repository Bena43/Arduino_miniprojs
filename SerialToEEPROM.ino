/*
 SerialToEEPROM
 through the Serial, the Arduino recieves 2 commands:
 read address - reads the data stored at the mentioned address from the EEPROM
 write address data - writes data on the EEPROM, located at the mentioned address.

 EEPROM has only 8 bits per address, so the maximum value that can be stored is 255.

 Created by Yehonatan Ben Harush, 15/2/2019
 */


#include <EEPROM.h>
void setup() 
{
for (int i=0;i<1024;i++)
  EEPROM.write(i,i); // optional, sets initial values for all addresses on the EEPROM
  Serial.begin(9600);
}
int address;
int data;
String serialInput = "";

void loop() 
{
  serialInput = Serial.readString(); // recieving the command from the user at the Serial
  if(serialInput.startsWith("write")) {
    address = serialInput.substring(serialInput.indexOf(' ') +1).toInt(); // gets the substring within the <brackets>, and converts to int - write <address> data
    data = serialInput.substring(serialInput.indexOf(' ', serialInput.indexOf(' ') + 1)).toInt(); // gets the substring within the <brackets>, and converts to int - write address <data>
    Serial.println(data); 
    EEPROM.write(address,data); 
  } else if(serialInput.startsWith("read")) {
    address = serialInput.substring(serialInput.indexOf(' ') +1).toInt();  // gets the substring within the <brackets>, and converts to int - read <address> 
    Serial.println(EEPROM.read(address));
  }
}
