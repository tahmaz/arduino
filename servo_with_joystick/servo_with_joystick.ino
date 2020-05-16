#include <Servo.h>
Servo servo1;
Servo servo2;
int joyX = 0;
int joyY = 1;

int joyVal;

void setup()

{
  servo1.attach(10);
  servo2.attach(11);
  
}

void loop ()

{
  joyVal = analogRead(joyX);
  joyVal = map (joyVal, 0, 1023, 0, 180);
  servo1.write(joyVal);

  joyVal = analogRead(joyY);
  joyVal = map (joyVal, 0, 1023, 0, 180);
  servo2.write(joyVal);
  delay(10);
 }
