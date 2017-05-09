/******************
 * Pin Definitions*
 ******************/
 
//IR sensors
#define IR_LEFT 0  //left IR sensor analog input pin
#define IR_RIGHT 1 //right IR sensor analog input pin

/********************
 * Value Definitions*
 ********************/

int leftIR_Val = 0; //left IR sensor's ADC value
int rightIR_Val = 0; //right IR sensor's ADC value


/////////////////////////////////////////////////////////////

void setup() {
  Serial.begin(38400);
  
  pinMode (IR_LEFT, INPUT);
  pinMode (IR_RIGHT, INPUT);
}

void loop() {
  leftIR_Val = analogRead(IR_LEFT); //read the value for the left IR LED
  rightIR_Val = analogRead(IR_RIGHT); //read the value for the right IR LED

  //print the data to the serial monitor
  Serial.print (leftIR_Val);
  Serial.print(" ");
  Serial.println(rightIR_Val);

  delay(1); //suggested "delay in between reads for stabilitiy" (Arduino AnalogReadSerial example)
}
