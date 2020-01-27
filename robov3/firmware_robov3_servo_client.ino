/*
  Servo client
  */
 #include <Servo.h>
Servo servoa,servob,servoc,servod,servoe,servof;
int posa,posamin,posamax;
int posb,posbmin,posbmax;
int posc,poscmin,poscmax;
int posd,posdmin,posdmax;
int pose,posemin,posemax;
int posf,posfmin,posfmax;

 int led = 13; // Pin 13
 
 void setup()
 {
     pinMode(led, OUTPUT); // Set pin 13 as digital out
 
     // Start up serial connection
     Serial.begin(115200); // baud rate
     Serial.flush();
     servoa.attach(3);
     servob.attach(5);
     servoc.attach(6);
     servod.attach(9);
     servoe.attach(10);
     servof.attach(11);
     posa=100;posamin=15;posamax=179;
     posb=30;posbmin=15;posbmax=179;
     posc=120;poscmin=15;poscmax=179;
     posd=179;posdmin=15;posdmax=179;
     pose=30;posemin=15;posemax=179;
     posf=90;posfmin=15;posfmax=179;
     
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
         if (input.substring(0, 2) == "1a")
         {
              //Serial.println(input.substring(2));
              //get servo a position
              posa=input.substring(2).toInt();
              //if big than max then overrite
              if (posa > posamax)
              posa=posamax;
              //if small than min then overrite
              if (posa < posamin)
              posa=posamin;
         }
         else if (input.substring(0, 2) == "1b")
         {
              //Serial.println(input.substring(2));
              //get servo a position
              posb=input.substring(2).toInt();
              //if big than max then overrite
              if (posb > posbmax)
              posb=posbmax;
              //if small than min then overrite
              if (posb < posbmin)
              posb=posbmin;
         }
         else if (input.substring(0, 2) == "1c")
         {
              //Serial.println(input.substring(2));
              //get servo a position
              posc=input.substring(2).toInt();
              //if big than max then overrite
              if (posc > poscmax)
              posc=poscmax;
              //if small than min then overrite
              if (posc < poscmin)
              posc=poscmin;
         }
	else if (input.substring(0, 2) == "1d")
         {
              //Serial.println(input.substring(2));
              //get servo a position
              posd=input.substring(2).toInt();
              //if big than max then overrite
              if (posd > posdmax)
              posd=posdmax;
              //if small than min then overrite
              if (posd < posdmin)
              posd=posdmin;
         }
	else if (input.substring(0, 2) == "1e")
         {
              //Serial.println(input.substring(2));
              //get servo a position
              pose=input.substring(2).toInt();
              //if big than max then overrite
              if (pose > posemax)
              pose=posemax;
              //if small than min then overrite
              if (pose < posemin)
              pose=posemin;
         }
	else if (input.substring(0, 2) == "1f")
         {
              //Serial.println(input.substring(2));
              //get servo a position
              posf=input.substring(2).toInt();
              //if big than max then overrite
              if (posf > posfmax)
              posf=posfmax;
              //if small than min then overrite
              if (posf < posfmin)
              posf=posfmin;
         }
         else if (input != "")
         {
           Serial.print("Command not accepted from controller1: ");
           Serial.println(input.substring(0, 2));
         }
    
    //digitalWrite(led, HIGH); // on
    //write servos
    servoa.write(posa);  
    servob.write(posb);
    servoc.write(posc);
    servod.write(posd);
    servoe.write(pose);
    servof.write(posf);
 }