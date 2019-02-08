void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}
void fast(){
  // a function that makes the fast blinks (frequency of 1 full blink per second)
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);                    
  digitalWrite(LED_BUILTIN, LOW); 
  delay(500); 
}
void slow(){
  // a function that makes the slow blinks (frequency of 1 full blink per 4 seconds)
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(2000);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(2000);
}

void loop() {
int i=0; // counter of how many full blinks has been since the beginning of the current loop
for (;i<5;i++){fast();} // 5 fast blinks
for(;i<10;i++){slow();} // 5 slow blinks
}
