=====================Example1===============================
#include <Servo.h>		// include the servo library
Servo servoMotor;       // creates an instance of the servo object to control a servo
int servoPin = 3;       // Control pin for servo motor
 
void setup() {
  Serial.begin(9600);       // initialize serial communications
  servoMotor.attach(servoPin);  // attaches the servo on pin 3 to the servo object
} 
 
void loop()
{
  int analogValue = analogRead(A0); // read the analog input
  Serial.println(analogValue);      // print it
 
  // if your sensor's range is less than 0 to 1023, you'll need to
  // modify the map() function to use the values you discovered:
  int servoAngle = map(analogValue, 0, 1023, 0, 179);
 
  // move the servo using the angle from the sensor:
  servoMotor.write(servoAngle);
}

=====================Example2===============================
/*
Arduino Servo Test sketch
*/
#include <Servo.h>
Servo servoMain; // Define our Servo

void setup()
{
   servoMain.attach(10); // servo on digital pin 10
}

void loop()
{
   servoMain.write(45);  // Turn Servo Left to 45 degrees
   delay(1000);          // Wait 1 second
   servoMain.write(0);   // Turn Servo Left to 0 degrees
   delay(1000);          // Wait 1 second
   servoMain.write(90);  // Turn Servo back to center position (90 degrees)
   delay(1000);          // Wait 1 second
   servoMain.write(135); // Turn Servo Right to 135 degrees
   delay(1000);          // Wait 1 second
   servoMain.write(180); // Turn Servo Right to 180 degrees
   delay(1000);          // Wait 1 second
   servoMain.write(90);  // Turn Servo back to center position (90 degrees)
   delay(1000);          // Wait 1 second   
}

=====================Example3===============================
// Controlling a servo position using a potentiometer (variable resistor)
// by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>
#include <Servo.h>
Servo myservo; // create servo object to control a servo
int potpin = 0; // analog pin used to connect the potentiometer
int val; // variable to read the value from the analog pin
void setup()
{
 myservo.attach(9); // attaches the servo on pin 9 to the servo object
}
void loop()
{
 val = analogRead(potpin);   // reads the value of the
          // potentiometer (value between
          // 0 and 1023)
 val = map(val, 0, 1023, 0, 179);  // scale it to use it with
          // the servo (value between 0 and
          // 180)
 myservo.write(val);     // sets the servo position according
          // to the scaled value
 delay(15);       // waits for the servo to get there
}