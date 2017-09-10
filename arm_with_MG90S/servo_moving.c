#include <Servo.h>

int mouthServoPin = 9;
int verticalServoPin = 10;
 
Servo mouthServo;  
Servo verticalServo; 
int servoAngle = 0;   // servo position in degrees
 
void setup()
{
//  logger.Init();
  Serial.begin(9600);  
  
  mouthServo.attach(mouthServoPin);
  verticalServo.attach(verticalServoPin);

}
 
 
void loop()
{

  moveMouth(0, 135, 50);
  moveMouth(135, 45, 50);
  
}


/*
 * This is for control the mouth servo
 */
void moveMouth(int fromAngle,  int toAngle, int duration){
  move(mouthServo, fromAngle, toAngle, duration);
}

/*
 * This is for control the vertial servo
 */
void moveVertical(int fromAngle,  int toAngle, int duration){
  move(verticalServo, fromAngle, toAngle, duration);
}


/*
 * These are the basic function for moving servo
 * move
 * - If from>to, it would decrease angle
 * - If from<to, it will increase angle
 * - If from=to, it would keep stay there
 */
void move(Servo servo, int fromAngle,  int toAngle, int duration){  
  if(fromAngle < toAngle){
      for(servoAngle = fromAngle; servoAngle < toAngle ; servoAngle++){                                  
        servo.write(servoAngle);              
        delay(duration);                  
      }
  }else if(fromAngle>toAngle){
       for(servoAngle = fromAngle; servoAngle > toAngle; servoAngle--){                                  
          servo.write(servoAngle);              
          delay(duration);                  
       }
  }else{
      servo.write(fromAngle);
      delay(duration);
  }
  
}




