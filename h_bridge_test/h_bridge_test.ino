/******************
 * Pin Definitions*
 ******************/

//left motor
#define LEFT_MOTOR_PINA 11 //direction select pin A
#define LEFT_MOTOR_PINB 10 //direction select pin B
#define LEFT_MOTOR_PWM 9   //PWM output pin

//right motor
#define RIGHT_MOTOR_PINA 8 //direction select pin A
#define RIGHT_MOTOR_PINB 7 //direction select pin B
#define RIGHT_MOTOR_PWM 3  //PWM output pin

/********************
 * Value Definitions*
 ********************/

#define FULL_THRUST 255 //full speed is PWM max value (255)
#define NO_THRUST 0 //zero speed is PWM min value (0)

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

}

void loop() {

  //forwards
  digitalWrite(LEFT_MOTOR_PINA, HIGH);
  digitalWrite(LEFT_MOTOR_PINB, LOW);

  digitalWrite(RIGHT_MOTOR_PINA, HIGH);
  digitalWrite(RIGHT_MOTOR_PINB, LOW);
  
  for (int i = NO_THRUST; i <= FULL_THRUST; i++)
  {
    analogWrite(LEFT_MOTOR_PWM, i);
    analogWrite(RIGHT_MOTOR_PWM, i);
  }
  for (int i = FULL_THRUST; i >= NO_THRUST; i--)
  {
    analogWrite(LEFT_MOTOR_PWM, i);
    analogWrite(RIGHT_MOTOR_PWM, i);
  }


  //backwards
  digitalWrite(LEFT_MOTOR_PINA, LOW);
  digitalWrite(LEFT_MOTOR_PINB, HIGH);

  digitalWrite(RIGHT_MOTOR_PINA, LOW);
  digitalWrite(RIGHT_MOTOR_PINB, HIGH);
  
  for (int i = NO_THRUST; i <= FULL_THRUST; i++)
  {
    analogWrite(LEFT_MOTOR_PWM, i);
    analogWrite(RIGHT_MOTOR_PWM, i);
  }
  for (int i = FULL_THRUST; i >= NO_THRUST; i--)
  {
    analogWrite(LEFT_MOTOR_PWM, i);
    analogWrite(RIGHT_MOTOR_PWM, i);
  }

}
