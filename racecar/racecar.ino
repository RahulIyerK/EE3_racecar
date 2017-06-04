/******************
 * Pin Definitions*
 ******************/

//left motor
#define LEFT_MOTOR_PINA 3 //direction select pin A
#define LEFT_MOTOR_PINB 2 //direction select pin B
#define LEFT_MOTOR_PWM 5   //PWM output pin

//right motor
#define RIGHT_MOTOR_PINA 6 //direction select pin A
#define RIGHT_MOTOR_PINB 8 //direction select pin B
#define RIGHT_MOTOR_PWM 9  //PWM output pin

//IR sensors
#define IR_LEFT A1  //left IR sensor analog input pin
#define IR_RIGHT A0 //right IR sensor analog input pin

//constant to turn
#define KP 1.5

#define hall 4
#define LED 13


/********************
 * Value Definitions*
 ********************/
//#define leftBase 170;
//#define rightBase 90;

//#define leftBase 100;
//#define rightBase 60;

  #define leftBase 140;
  #define rightBase 80;
/////////////////////////////////////////////////////////////

void setup() {
  // put your setup code here, to run once:
  pinMode(IR_LEFT, INPUT);
  pinMode(IR_RIGHT, INPUT);
  
  pinMode (LEFT_MOTOR_PINA, OUTPUT);
  pinMode (LEFT_MOTOR_PINB, OUTPUT);
  pinMode (LEFT_MOTOR_PWM, OUTPUT);

  pinMode (RIGHT_MOTOR_PINA, OUTPUT);
  pinMode (RIGHT_MOTOR_PINB, OUTPUT);
  pinMode (RIGHT_MOTOR_PWM, OUTPUT);

  Serial.begin(38400);

  
  //forwards
  digitalWrite(LEFT_MOTOR_PINA, HIGH);
  digitalWrite(LEFT_MOTOR_PINB, LOW);


  digitalWrite(RIGHT_MOTOR_PINA, LOW);
  digitalWrite(RIGHT_MOTOR_PINB, HIGH);

  analogWrite(LEFT_MOTOR_PWM, 200);
  analogWrite(RIGHT_MOTOR_PWM, 200);


  pinMode (hall, INPUT);
  pinMode (LED, OUTPUT);

  delay(500);


  
}

//left range
//770 - 790

//right range
//950 - 970

void loop() {
  
  digitalWrite(LED, digitalRead(hall) );
  
  
  int leftVal, rightVal;
  leftVal = analogRead(IR_LEFT);
  rightVal = analogRead(IR_RIGHT);

  int diff = rightVal - leftVal;

  int leftSpeed = leftBase;
  int rightSpeed = rightBase;
  
  if(diff < -20)
  {
    //leftSpeed += -KP * diff;
    leftSpeed = leftBase;
    rightSpeed -= -KP * diff;
  }
  else if(diff > 0)
  {
   // rightSpeed += KP * diff;
   rightSpeed = rightBase;
   leftSpeed -= KP * diff;
  }
  else
  {
    rightSpeed = rightBase;
    leftSpeed = leftBase;
  }
  Serial.print(diff);
  Serial.print(" ");
  Serial.print(leftSpeed);
  Serial.print(" ");
  Serial.println(rightSpeed);

  leftSpeed = constrain(leftSpeed, 40, 200);
  rightSpeed = constrain(rightSpeed, 40, 200);
  
  analogWrite(LEFT_MOTOR_PWM, leftSpeed);
  analogWrite(RIGHT_MOTOR_PWM, rightSpeed);

}
