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
int joyX1 = 0;
int joyY1 = 1;
int joyX2 = 2;
int joyY2 = 3;

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
  int a = analogRead(joyX1);
  int b = analogRead(joyY1);
  int c = analogRead(joyX2);
  int d = analogRead(joyY2);

  Serial.print(a);
  Serial.print("\t");
  Serial.print(b);
  Serial.print("\t");
  Serial.print(c);
  Serial.print("\t");
  Serial.println(d);

  servo1.write(map(a, 0, 1023, 0, 180));
  servo2.write(map(b, 0, 1023, 0, 180));
  servo3.write(map(c, 0, 1023, 0, 180));
  servo4.write(map(d, 0, 1023, 0, 180));
  
  delay(10);
 }
