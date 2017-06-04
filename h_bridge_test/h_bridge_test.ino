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

/********************
 * Value Definitions*
 ********************/

#define FULL_THRUST 200 //full speed is PWM max value (255)
#define NO_THRUST 50 //zero speed is PWM min value (0)

int leftPWMVal = 0; //left motor's PWM Value
int rightPWMVal = 0; //right motor's PWM Value

/////////////////////////////////////////////////////////////

void setup() {
  pinMode (LEFT_MOTOR_PINA, OUTPUT);
  pinMode (LEFT_MOTOR_PINB, OUTPUT);
  pinMode (LEFT_MOTOR_PWM, OUTPUT);

  pinMode (RIGHT_MOTOR_PINA, OUTPUT);
  pinMode (RIGHT_MOTOR_PINB, OUTPUT);
  pinMode (RIGHT_MOTOR_PWM, OUTPUT);

  Serial.begin(38400);
}

void loop() {

  //forwards
  digitalWrite(LEFT_MOTOR_PINA, HIGH);
  digitalWrite(LEFT_MOTOR_PINB, LOW);


  digitalWrite(RIGHT_MOTOR_PINA, LOW);
  digitalWrite(RIGHT_MOTOR_PINB, HIGH);
  
  //analogWrite(LEFT_MOTOR_PWM, 200);
  //analogWrite(RIGHT_MOTOR_PWM, 112);
  analogWrite(LEFT_MOTOR_PWM, 100);
  analogWrite(RIGHT_MOTOR_PWM, 60);

}
