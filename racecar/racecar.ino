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

//IR sensors
#define IR_LEFT 0  //left IR sensor analog input pin
#define IR_RIGHT 1 //right IR sensor analog input pin

/********************
 * Value Definitions*
 ********************/

#define FULL_THRUST 255 //full speed is PWM max value (255)
#define NO_THRUST 0 //zero speed is PWM min value (0)

bool forward = true;

int leftIR_Val = 0; //left IR sensor's ADC value
int rightIR_Val = 0; //right IR sensor's ADC value

int leftPWMVal = 0; //left motor's PWM Value
int rightPWMVal = 0; //right motor's PWM Value

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
