/*
  firmware_robov3_left_foot
 */
#include <Servo.h>
#include <Wire.h>
Servo servoa,servob,servoc,servod,servoe;

int power,powernew,powermin,powermax;
int powersleep,powersleepnew,powersleepmin,powersleepmax;
int powertimeout,powertimeoutnew,powertimeoutmin,powertimeoutmax;

int posa,posanew,posamin,posamax;
int posb,posbnew,posbmin,posbmax;
int posc,poscnew,poscmin,poscmax;
int posd,posdnew,posdmin,posdmax;
int pose,posenew,posemin,posemax;


int led = 13; // Pin 13
boolean ledstate=0;
int Powerpin = 3;

void setup()
{
  //pinMode(led, OUTPUT); // Set pin 13 as digital out
  pinMode(Powerpin, OUTPUT);

  // Start up serial connection for monitor process
  Serial.begin(115200); // baud rate
  Serial.flush();

  // Start up i2c connection
  Wire.begin(2);
  Wire.onReceive(receiveEvent);


  servoa.attach(5,750,2800);
  servob.attach(6,750,2800);
  servoc.attach(9,750,2800);
  servod.attach(10,750,2800);
  servoe.attach(11,750,2800);
  powernew=240;
  power=240;
  powermin=0;
  powermax=255;
  powersleepnew=0;
  powersleep=0;
  powersleepmin=0;
  powersleepmax=50;
  powertimeoutnew=500;
  powertimeout=2000;
  powertimeoutmin=100;
  powertimeoutmax=4500;

  posanew=posa=50;
  posamin=0;
  posamax=180;
  posbnew=posb=160;
  posbmin=0;
  posbmax=180;
  poscnew=posc=0;
  poscmin=0;
  poscmax=180;
  posdnew=posd=180;
  posdmin=0;
  posdmax=180;
  posenew=pose=140;
  posemin=0;
  posemax=180;

  servoa.write(posa);  
  servob.write(posb);
  servoc.write(posc);
  servod.write(posd);
  servoe.write(pose);

  Serial.print("con2: setup completed."); 

  //commands 1.servoa.servob.servoc.servod.servoe.power-3digit.10*powersleep-1digit.100*powertimeout-1digit
  ////2.050.160.000.180.140.255.0.8

}

void loop()
{	
  digitalWrite(led, ledstate);
  if(ledstate==0)
    ledstate=1;
  else
    ledstate=0;

  //write servos
  if(posa!=posanew || posb!=posbnew || posc!=poscnew || posd!=posdnew || pose!=posenew){ 

    if (powernew > powermax)
      powernew=powermax;
    if (powernew < powermin)
      powernew=powermin;
    //poweron
    analogWrite(Powerpin,powernew);
    power=powernew;
    Serial.print("con1 command received:");
    //Serial.println(posanew);
    //Serial.println(posbnew);
    //Serial.println(poscnew);
    //Serial.println(posdnew);
    //Serial.println(posenew);
    //Serial.println(powernew);
    //Serial.println(powersleepnew);
    //Serial.println(powertimeoutnew);

    if(posa!=posanew){
      //if big than max then overrite
      if (posanew > posamax)
        posanew=posamax;
      //if small than min then overrite
      if (posanew < posamin)
        posanew=posamin;

      servoa.write(posanew);
      posa=posanew;
    }  
    if(posb!=posbnew){
      //if big than max then overrite
      if (posbnew > posbmax)
        posbnew=posbmax;
      //if small than min then overrite
      if (posbnew < posbmin)
        posbnew=posbmin;

      servob.write(posbnew);
      posb=posbnew;
    }
    if(posc!=poscnew){
      //if big than max then overrite
      if (poscnew > poscmax)
        poscnew=poscmax;
      //if small than min then overrite
      if (poscnew < poscmin)
        poscnew=poscmin;
      servoc.write(poscnew);
      posc=poscnew;
    }
    if(posd!=posdnew){
      //if big than max then overrite
      if (posdnew > posdmax)
        posdnew=posdmax;
      //if small than min then overrite
      if (posdnew < posdmin)
        posdnew=posdmin;
      servod.write(posdnew);
      posd=posdnew;
    }
    if(pose!=posenew){

      //if big than max then overrite
      if (posenew > posemax)
        posenew=posemax;
      //if small than min then overrite
      if (posenew < posemin)
        posenew=posemin;
      servoe.write(posenew);
      pose=posenew;
    }

    if (powertimeoutnew > powertimeoutmax)
      powertimeoutnew=powertimeoutmax;
    if (powertimeoutnew < powertimeoutmin)
      powertimeoutnew=powertimeoutmin;
    //power off
    //delay(powertimeoutnew);
    powertimeout=powertimeoutnew;

  }

  if (powertimeout==0){
    if (powersleepnew > powersleepmax)
      powersleepnew=powersleepmax;
    if (powersleepnew < powersleepmin)
      powersleepnew=powersleepmin;
    analogWrite(Powerpin,powersleepnew);
    powersleep=powersleepnew;
  }

  if(powertimeout > 0)
    powertimeout=powertimeout-1;
    
  //if (powertimeout!=0)
  //Serial.println(powertimeout);
  delay(1);
}

void receiveEvent(int howMany)
{
  String input = "";


  // Read any wire input
  while (Wire.available() > 0)
  {
    input += (char)  Wire.read(); // Read in one char at a time
    delay(5); // Delay for 5 ms so the next char has time to be received
  }
  //Serial.println("con1: "+input.substring(0));
  if (input.substring(0, 1) == "2")
  {

    //get servo a position
    posanew=input.substring(2,5).toInt();
    posbnew=input.substring(6,9).toInt();
    poscnew=input.substring(10,13).toInt();
    posdnew=input.substring(14,17).toInt();
    posenew=input.substring(18,21).toInt();

    powernew=input.substring(22,25).toInt();
    powersleepnew=10*input.substring(26,27).toInt();
    powertimeoutnew=500*input.substring(28,29).toInt();

    //accept command
    Serial.println("con2: accepted");
    //Serial.println(input.substring(0));

  }
  else if (input != "")
  {
    Serial.print("con2: Command not accepted from controller1.");
  }

}