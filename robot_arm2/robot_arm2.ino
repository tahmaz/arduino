/*Zeno Modiff 
Joystick Controlled Servo
www.youtube.com/ZenoModiff 
sreeramzeno@gmail.com 
feel free to contact 
support me by subscribing to my channel */
#include <Servo.h>
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

int joy1Ypin = 0;
int joy1Xpin = 1;
int joy2Ypin = 2;
int joy2Xpin = 3;

int s1min=15,s1max=180;
int s2min=40,s2max=180;
int s3min=0,s3max=180;
int s4min=20,s4max=180;

int joy1Ycalibration = 2;
int joy1Xcalibration = 11;
int joy2Ycalibration = 31;
int joy2Xcalibration = 15;

int s1pos = 90;
int s2pos = 90;
int s3pos = 90;
int s4pos = 90;

void setup()

{
  Serial.begin(9600);
  servo1.attach(3);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(9);  
}

void loop ()

{
  int a = analogRead(joy1Ypin) + joy1Ycalibration;
  int b = analogRead(joy1Xpin) + joy1Xcalibration;
  int c = analogRead(joy2Ypin) + joy2Ycalibration;
  int d = analogRead(joy2Xpin) + joy2Xcalibration;

  s1pos = s1pos + map(a, 0, 1023, -2, 2);
  s2pos = s2pos + map(b, 0, 1023, 2, -2);
  s3pos = s3pos + map(c, 0, 1023, -2, 2);
  s4pos = s4pos + map(d, 0, 1023, 2, -2);

  if(s1pos < s1min)
    s1pos = s1min;
  if (s1pos > s1max)
    s1pos = s1max;

  if(s2pos < s2min)
    s2pos = s2min;
  if (s2pos > s2max)
    s2pos = s2max;

  if(s3pos < s3min)
    s3pos = s3min;
  if (s3pos > s3max)
    s3pos = s3max;

  if(s4pos < s4min)
    s4pos = s4min;
  if (s4pos > s4max)
    s4pos = s4max;
/*
  Serial.print(a);
  Serial.print(",");
  Serial.print(s1pos);
  Serial.print("\t");
  
  Serial.print(b);
  Serial.print(",");
  Serial.print(s2pos);
  Serial.print("\t");
  
  Serial.print(c);
  Serial.print(",");
  Serial.print(s3pos);
  Serial.print("\t");
  
  Serial.print(d);
  Serial.print(",");
  Serial.println(s4pos);
*/
  servo1.write(s1pos);
  servo2.write(s2pos);
  servo3.write(s3pos);
  servo4.write(s4pos);
  
  delay(10);
 }
