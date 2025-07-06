#include <NewPing.h>


#define MAX_FORWARD_MOTOR_SPEED 75
#define MAX_MOTOR_TURN_SPEED_ADJUSTMENT 50

#define IR_SENSOR_RIGHT 2
#define IR_SENSOR_LEFT 3

//Right motor
int enableRightMotor=5;
int rightMotorPin1=7;
int rightMotorPin2=8;

//Left motor
int enableLeftMotor=6;
int leftMotorPin1=9;
int leftMotorPin2=10;


void setup()
{
  // put your setup code here, to run once:
  pinMode(enableRightMotor, OUTPUT);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);
  
  pinMode(enableLeftMotor, OUTPUT);
  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);

  pinMode(IR_SENSOR_RIGHT, INPUT);
  pinMode(IR_SENSOR_LEFT, INPUT);
  rotateMotor(0,0);   
  }


void loop()
{
  int rightIRSensorValue = digitalRead(IR_SENSOR_RIGHT);
  int leftIRSensorValue = digitalRead(IR_SENSOR_LEFT);

  //NOTE: If IR sensor detects the hand then its value will be LOW else the value will be HIGH
  
  //If right sensor detects hand, then turn right. We increase left motor speed and decrease the right motor speed to turn towards right
  if (rightIRSensorValue == LOW && leftIRSensorValue == HIGH )
  {
      rotateMotor(MAX_FORWARD_MOTOR_SPEED - MAX_MOTOR_TURN_SPEED_ADJUSTMENT, MAX_FORWARD_MOTOR_SPEED + MAX_MOTOR_TURN_SPEED_ADJUSTMENT ); 
        /*digitalWrite(rightMotorPin1,LOW);
        digitalWrite(rightMotorPin2,HIGH);
        digitalWrite(leftMotorPin1,HIGH);
        digitalWrite(leftMotorPin2,LOW);
        analogWrite(enableRightMotor, abs(125));
        analogWrite(enableLeftMotor, abs(125));*/
  }
 //If left sensor detects hand, then turn left. We increase right motor speed and decrease the left motor speed to turn towards left
  else if (rightIRSensorValue == HIGH && leftIRSensorValue == LOW )
  {
      rotateMotor(MAX_FORWARD_MOTOR_SPEED + MAX_MOTOR_TURN_SPEED_ADJUSTMENT, MAX_FORWARD_MOTOR_SPEED - MAX_MOTOR_TURN_SPEED_ADJUSTMENT); 
       /* digitalWrite(rightMotorPin1,HIGH);
        digitalWrite(rightMotorPin2,LOW);
        digitalWrite(leftMotorPin1,LOW);
        digitalWrite(leftMotorPin2,HIGH);
        analogWrite(enableRightMotor, abs(125));
        analogWrite(enableLeftMotor, abs(125));*/ 
  }
  //If distance is between min and max then go straight
  else if (rightIRSensorValue == HIGH && leftIRSensorValue == HIGH )
  {
    rotateMotor(MAX_FORWARD_MOTOR_SPEED, MAX_FORWARD_MOTOR_SPEED);
  }
  //stop the motors
  else 
  {
    rotateMotor(0, 0);
  }
}
void rotateMotor(int rightMotorSpeed, int leftMotorSpeed)
{
  if (rightMotorSpeed < 0)
  {
    digitalWrite(rightMotorPin1,LOW);
    digitalWrite(rightMotorPin2,HIGH);
  }
  else if (rightMotorSpeed > 0)
  {
    digitalWrite(rightMotorPin1,HIGH);
    digitalWrite(rightMotorPin2,LOW);      
  }
  else
  {
    digitalWrite(rightMotorPin1,LOW);
    digitalWrite(rightMotorPin2,LOW);      
  }

  if (leftMotorSpeed <0)
  {
    digitalWrite(leftMotorPin1,LOW);
    digitalWrite(leftMotorPin2,HIGH);     
  }
  else if (leftMotorSpeed > 0)
  {
    digitalWrite(leftMotorPin1,HIGH);
    digitalWrite(leftMotorPin2,LOW);      
  }
  else 
  {
digitalWrite(leftMotorPin1,LOW);
    digitalWrite(leftMotorPin2,LOW);      
  }
  
  analogWrite(enableRightMotor, abs(rightMotorSpeed));
  analogWrite(enableLeftMotor, abs(leftMotorSpeed));    
}
