#include <ros.h>
#include <std_msgs/UInt16.h>

ros::NodeHandle nh;

int motorSpeed = 50;

#define motor1Direction 9
#define motor1Speed 8
#define motor2Direction 7
#define motor2Speed 6
#define motor3Direction 2
#define motor3Speed 3
#define motor4Direction 4
#define motor4Speed 5

void motor_cmd(const std_msgs::UInt16& cmd_msg)
{
  switch(cmd_msg.data)
  {
    case 1 : runMotor();
    break;
    case 2 : leftMotor();
    break;
    case 3 : rightMotor();
    break;
    case 4 : reverseMotor();
    break;
    case 5 : stopMotor();
    break;
  }
}

void runMotor()
{
  digitalWrite(motor1Direction, LOW);
  analogWrite(motor1Speed, motorSpeed);
  digitalWrite(motor2Direction, HIGH);
  analogWrite(motor2Speed, motorSpeed);
  
  digitalWrite(motor3Direction, HIGH);
  analogWrite(motor3Speed, motorSpeed);
  digitalWrite(motor4Direction, LOW);
  analogWrite(motor4Speed, motorSpeed);
}

void leftMotor()
{
  digitalWrite(motor1Direction, HIGH);
  analogWrite(motor1Speed, 0);
  digitalWrite(motor2Direction, HIGH);
  analogWrite(motor2Speed, motorSpeed);
  
  digitalWrite(motor3Direction, HIGH);
  analogWrite(motor3Speed, motorSpeed);
  digitalWrite(motor4Direction, HIGH);
  analogWrite(motor4Speed, 0);
}

void rightMotor()
{
  digitalWrite(motor1Direction, LOW);
  analogWrite(motor1Speed, motorSpeed);
  digitalWrite(motor2Direction, HIGH);
  analogWrite(motor2Speed, 0);

  digitalWrite(motor3Direction, LOW);
  analogWrite(motor3Speed, 0);
  digitalWrite(motor4Direction, LOW);
  analogWrite(motor4Speed, motorSpeed);
}

void stopMotor()
{
  digitalWrite(motor1Direction, HIGH);
  analogWrite(motor1Speed, 0);
  digitalWrite(motor2Direction, HIGH);
  analogWrite(motor2Speed, 0);

  
  digitalWrite(motor3Direction, HIGH);
  analogWrite(motor3Speed, 0);
  digitalWrite(motor4Direction, HIGH);
  analogWrite(motor4Speed, 0);
}

void reverseMotor()
{
  digitalWrite(motor1Direction, HIGH);
  analogWrite(motor1Speed, motorSpeed);
  digitalWrite(motor2Direction, LOW);
  analogWrite(motor2Speed, motorSpeed);
  
  digitalWrite(motor3Direction, LOW);
  analogWrite(motor3Speed, motorSpeed);
  digitalWrite(motor4Direction, HIGH);
  analogWrite(motor4Speed, motorSpeed);
}

ros::Subscriber<std_msgs::UInt16> sub("motor", motor_cmd);

void setup() {
  pinMode(motor1Direction, OUTPUT);
  pinMode(motor1Speed, OUTPUT);
  pinMode(motor2Direction, OUTPUT);
  pinMode(motor2Speed, OUTPUT);
  pinMode(motor3Direction, OUTPUT);
  pinMode(motor3Speed, OUTPUT);
  pinMode(motor4Direction, OUTPUT);
  pinMode(motor4Speed, OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
}

void loop() {
  nh.spinOnce();
  
  delay(1);
}
