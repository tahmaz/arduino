//i2c Master Code(UNO)
#include <Wire.h>

void setup()
{
  Serial.begin(9600);
  
  Wire.begin();
}

void loop()
{
  while(Serial.available())
  {
    char c = Serial.read();
    
    if(c == 'H')
    {
      Wire.beginTransmission(5);
      Wire.write('H');
      Wire.endTransmission();
    }
    else if(c == 'L')
    {
      Wire.beginTransmission(5);
      Wire.write('L');
      Wire.endTransmission();
    }
  }
}

====================================================
#include <Wire.h>
#include <Servo.h>
Servo servoa,servob,servoc,servod,servoe,servof; // create servo object to control a servo
int posa,posb,posc,posd,pose,posf;


void setup()
{
 servoa.attach(3); // attaches the servo on pin 9 to the servo object
 servob.attach(5);
 servoc.attach(6);
 servod.attach(9);
 servoe.attach(10);
 servof.attach(11);
 
 posa=90;
 posb=90;
 posc=90;
 posd=90;
 pose=90;
 posf=90;
 
 Wire.begin(5);
 Wire.onReceive(receiveEvent);
  
 pinMode(13,OUTPUT);
 digitalWrite(13,LOW);
}

void loop()
{
 //val = map(val, 0, 1023, 0, 179);
 servoa.write(posa);     // sets the servo position according
 servob.write(posb);
 servoc.write(posc);
 servod.write(posd);
 servoe.write(pose);
 servof.write(posf);

 delay(10);       // waits for the servo to get there
}

void receiveEvent(int howMany)
{
  while(Wire.available())
  {
    char c = Wire.read();
    
    if(c == 'H')
    {
      digitalWrite(13,HIGH);
    }
    else if(c == 'L')
    {
      digitalWrite(13,LOW);
    }
  }
}