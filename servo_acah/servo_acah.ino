#include <Servo.h>

Servo myservo;
int pos = 90;
//const int pwm1 = 2 ; //initializing pin 2 as pwm
//const int pwm2 = 3;
const int in_1 = 8 ;//PWM left motor
const int in_2 = 9 ;//DR left motor
const int in_3 = 10;//PWM right motor
const int in_4 = 11;//DR right motor

void setup() {
  
 Serial.begin(9600); //communication between arduino and raspberry pi
 myservo.attach(4);  // pin for servo
 //pinMode(pwm1,OUTPUT); //we have to set PWM pin as output
 //pinMode(pwm2,OUTPUT);
 pinMode(in_1,OUTPUT); //Logic pins are also set as output
 pinMode(in_2,OUTPUT);
 pinMode(in_3,OUTPUT);
 pinMode(in_4,OUTPUT);
 
}

void loop() {
  readingmarker();
}
  
void readingmarker(){

  if (Serial.available()){
    String payload = Serial.readStringUntil('\r\n');
    int cmd = payload.toInt();
    
    if (cmd == 1){
       Face();
    }
    
    else if (cmd == 0){
       stopmarker();
    }

    else if (cmd == 2){
       Left();
    }

    else if (cmd == 3){
       Right();
    }

  } 

  
  
  }

  
void stopmarker(){
  
   //stopping the motor
   digitalWrite(in_1,LOW);
   digitalWrite(in_2,LOW);
   digitalWrite(in_3,LOW);
   digitalWrite(in_4,LOW);
   //analogWrite(pwm1,1);
   //analogWrite(pwm2,1);
   
   for (pos = 90; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees 
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  
  for (pos = 180; pos >= 90; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  
  }

  
void Left(){
    myservo.write(180);              // tell servo to go to position in variable 'pos'
    delay(15);    
  //analogWrite(pwm1,1);
  //analogWrite(pwm2,1);
  }
  
  
void Right(){
    myservo.write(0);              // tell servo to go to position in variable 'pos'
    delay(15);    
  //analogWrite(pwm1,1);
  //analogWrite(pwm2,1);
  }
  

void Face(){
     for (pos = 45; pos <= 135; pos += 1) { // goes from 0 degrees to 180 degrees 
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  
  for (pos = 135; pos >= 40; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  
  }

  
void Stop()
{
  //stopping the motor
   digitalWrite(in_1,LOW);
   digitalWrite(in_2,LOW);
   digitalWrite(in_3,LOW);
   digitalWrite(in_4,LOW);
   //analogWrite(pwm1,1);
   //analogWrite(pwm2,1);

   delay(50);
  
  }
