/*
  firmware_robov3_right_hand
  */
 #include <Servo.h>
Servo servoa,servob,servoc,servod,servoe;

int power,powernew,powermin,powermax;
int powersleep,powersleepnew,powersleepmin,powersleepmax;
int powertimeout,powertimeoutnew,powertimeoutmin,powertimeoutmax;

int posa,posanew,posamin,posamax;
int posb,posbnew,posbmin,posbmax;
int posc,poscnew,poscmin,poscmax;
int posd,posdnew,posdmin,posdmax;
int pose,posenew,posemin,posemax;


 //int led = 13; // Pin 13
 int Powerpin = 3;
 
 void setup()
 {
     //pinMode(led, OUTPUT); // Set pin 13 as digital out
     pinMode(Powerpin, OUTPUT);
 
     // Start up serial connection
     Serial.begin(115200); // baud rate
     Serial.flush();
     servoa.attach(5);
     servob.attach(6);
     servoc.attach(9);
     servod.attach(10);
     servoe.attach(11);
     powernew=240;power=240;powermin=0;powermax=255;
	 powersleepnew=0;powersleep=0;powersleepmin=0;powersleepmax=50;
	 powertimeoutnew=500;powertimeout=500;powertimeoutmin=100;powertimeoutmax=999;
     
     posanew=posa=40;posamin=15;posamax=179;
     posbnew=posb=60;posbmin=15;posbmax=179;
     poscnew=posc=40;poscmin=15;poscmax=179;
     posdnew=posd=40;posdmin=15;posdmax=179;
     posenew=pose=179;posemin=15;posemax=179;
     
    servoa.write(posa);  
    servob.write(posb);
    servoc.write(posc);
    servod.write(posd);
    servoe.write(pose);
    
    //commands con1.servoa.servob.servoc.servod.servoe.power.powersleep.powertimeout.custom
    //con3.040.060.040.000.000.255.000.800.000
    //con3.090.090.090.000.000.255.000.800.000
    //con3.180.180.040.000.000.255.000.800.000
     
 }
 
 void loop()
 {
     String input = "";
 
     // Read any serial input
     while (Serial.available() > 0)
     {
         input += (char) Serial.read(); // Read in one char at a time
         delay(5); // Delay for 5 ms so the next char has time to be received
     }
         if (input.substring(0, 4) == "con3")
         {
              
              //Serial.println(input.substring(0,4));
              //get servo a position
              posanew=input.substring(5,8).toInt();
              posbnew=input.substring(9,12).toInt();
              poscnew=input.substring(13,16).toInt();
              posdnew=input.substring(17,20).toInt();
              posenew=input.substring(21,24).toInt();
              
              powernew=input.substring(25,28).toInt();
			  powersleepnew=input.substring(29,32).toInt();
			  powertimeoutnew=input.substring(33,36).toInt();
			  
              //if big than max then overrite
              if (posanew > posamax)
              posanew=posamax;
              //if small than min then overrite
              if (posanew < posamin)
              posanew=posamin;
              //if big than max then overrite
              if (posbnew > posbmax)
              posbnew=posbmax;
              //if small than min then overrite
              if (posbnew < posbmin)
              posbnew=posbmin;
              //if big than max then overrite
              if (poscnew > poscmax)
              poscnew=poscmax;
              //if small than min then overrite
              if (poscnew < poscmin)
              poscnew=poscmin;
              //if big than max then overrite
              if (posdnew > posdmax)
              posdnew=posdmax;
              //if small than min then overrite
              if (posdnew < posdmin)
              posdnew=posdmin;
              //if big than max then overrite
              if (posenew > posemax)
              posenew=posemax;
              //if small than min then overrite
              if (posenew < posemin)
              posenew=posemin;
			  
			  if (powernew > powermax)
              powernew=powermax;
              if (powernew < powermin)
              powernew=powermin;
			  
			  if (powersleepnew > powersleepmax)
              powersleepnew=powersleepmax;
              if (powersleepnew < powersleepmin)
              powersleepnew=powersleepmin;
			  
			  if (powertimeoutnew > powertimeoutmax)
              powertimeoutnew=powertimeoutmax;
              if (powertimeoutnew < powertimeoutmin)
              powertimeoutnew=powertimeoutmin;
         }
         else if (input != "")
         {
           Serial.print("Command not accepted from controller1: ");
           Serial.println(input.substring(0));
         }
    
    
  
    //digitalWrite(led, HIGH); // on
    //write servos
    if(posa!=posanew || posb!=posbnew || posc!=poscnew || posd!=posdnew || pose!=posenew){ 
			//poweron
			analogWrite(Powerpin,powernew);
			power=powernew;
    
		if(posa!=posanew){
			servoa.write(posanew);
			posa=posanew;
		}  
		if(posb!=posbnew){
			servob.write(posbnew);
			posb=posbnew;
		}
		if(posc!=poscnew){
			servoc.write(poscnew);
			posc=poscnew;
		}
		if(posd!=posdnew){
			servod.write(posdnew);
			posd=posdnew;
		}
		if(pose!=posenew){
			servoe.write(posenew);
			pose=posenew;
		}
    //power off
    delay(powertioutnew);
    analogWrite(Powerpin,powersleepnew);
    }
	else(powersleep!=powersleepnew){
		analogWrite(Powerpin,powersleepnew);
		powersleep=powersleepnew;
	}
	
 }