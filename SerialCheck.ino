void setup() {
Serial.begin(9600); // set the baud rate as 9600
pinMode(13,OUTPUT); // set the 13th pin as an output pin
}

int Serial_state; // global variable that recieves the commands from the serial

void loop() {
if (Serial.available()>0)       // as long as the serial works,
  Serial_state = Serial.read(); // set Serial_state as the input that is recieved from the serial. 
if (Serial_state == '1')        // if serial recieves 1 as an input
  digitalWrite(13,HIGH);        // turn on the led
if (Serial_state == '0')        // if serial recieves 0 as an input
  digitalWrite(13,LOW);         // turn of the light
}
