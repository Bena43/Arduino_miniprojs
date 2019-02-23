/*
 ButtonsPotentiometerConditions

  The following sketch uses 1 potentiometer, 2 buttons, and 2 leds.
  if the potentiometer's analog value is below TH, both lights are off.
  if its above:
  if ledA's button,buttonPin is being pushed, the led in on, and when not pushed, the led is off.
  if ledB's button, switchPin has been pushed, change the state. if state equals 1, led is on. state equals 0 means led is off.
  
  Hebrew Youtube toturial:
   https://youtu.be/_UeG8UfAS18
 Created by Yehonatan Ben Harush, 21/2/2019
 */

int potPin = A0;    // select the input pin for the potentiometer
int ledA = 12;   // select the pin for the LED
int ledB = 13;   // select the pin for the LED
int buttonPin=3;
int switchPin = 4;         // the number of the input pin
int potTH=500;
int val = 0;       // variable to store the value coming from the sensor
int buttonState = 0;         // variable for reading the pushbutton status
int state = HIGH;      // the current state of the output pin
int reading;           // the current reading from the input pin
int previous = LOW;    // the previous reading from the input pin
long time = 0;         // the last time the output pin was toggled
long debounce = 200;   // the debounce time, increase if the output flickers


void setup() {
  pinMode(ledA, OUTPUT);  // declare the ledPin as an OUTPUT
  pinMode(ledB, OUTPUT);  // declare the ledPin as an OUTPUT
  pinMode(buttonPin, INPUT);
  pinMode(4, INPUT_PULLUP);
  pinMode(switchPin, INPUT);
  Serial.begin(9600);  
}

void loop() {
  
  reading = digitalRead(switchPin);

  if (reading == HIGH && previous == LOW && millis() - time > debounce) {
    if (state == HIGH)
      state = LOW;
    else
      state = HIGH;

    time = millis();    
  }


  previous = reading;
  
  int sensorVal = digitalRead(4);
  buttonState = digitalRead(buttonPin);
  val = analogRead(potPin);    // read the value from the sensor
  Serial.println(val);
  if (val>potTH){
    if (buttonState == HIGH) {
    // turn ledA on:
    digitalWrite(ledA, HIGH);
    } 
    else {
    // turn ledA off:
    digitalWrite(ledA, LOW);
    }
  if(state==1)
  digitalWrite(ledB, HIGH);  // turn the ledPin on  
  else
  digitalWrite(ledB, LOW);  // turn the ledPin on  
  //}
  
  
  } 
  
  else
  {
  digitalWrite(ledA, LOW);  // turn the ledPin on
  digitalWrite(ledB, LOW);  // turn the ledPin on
  }
}
