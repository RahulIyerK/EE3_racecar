#define hall 4
#define LED 13

void setup() {
  // put your setup code here, to run once:
  pinMode (hall, INPUT);
  pinMode (LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  digitalWrite(LED, digitalRead(hall) );
}
