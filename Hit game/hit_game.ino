const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
}

==================
const int led1 = 2;
const int led2 = 3;
const int led3 = 4;
const int led4 = 5;
const int led5 = 6;
const int led6 = 7;

const int startbutton =  A0;
const int button1 =  8;
const int button2 =  9;
const int button3 =  10;
const int button4 =  11;
const int button5 =  12;
const int button6 =  13;

int startbuttonState = 0;
int button1State = 0;
int button2State = 0;
int button3State = 0;
int button4State = 0;
int button5State = 0;
int button6State = 0;

void setup()
{
  Serial.begin(9600); 
  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  
  pinMode(startbutton, INPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  pinMode(button5, INPUT);
  pinMode(button6, INPUT);
}

void loop()
{
  // read the state of the pushbutton value:
  startbuttonState = digitalRead(startbutton);
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (startbuttonState == HIGH) {
    // turn LED on:
    digitalWrite(led1, HIGH);
    //Serial.print(startbuttonState);
  } else {
    // turn LED off:
    digitalWrite(led1, LOW);
  }
}

===================
int hitcount = 0;

int leds[] = {2, 3, 4, 5, 6, 7};
int ledcount = 6;

const int startbutton =  A0;
int buttons[] = {8, 9, 10, 11, 12, 13};
int buttoncount = 6;

int startbuttonState = 0;
int buttonstates[] = {0, 0, 0, 0, 0, 0};

int ranNum = 0;

void setup()
{
  Serial.begin(9600); 
  
  for (int thisPin = 0; thisPin < ledcount; thisPin++) {
    pinMode(leds[thisPin], OUTPUT);
  }
  
  pinMode(startbutton, INPUT);
  for (int thisPin = 0; thisPin < buttoncount; thisPin++) {
    pinMode(buttons[thisPin], INPUT);
  }

}

void loop()
{
    buttonstates[0] = digitalRead(startbutton);
	if (digitalRead(startbutton) == HIGH) {
    	startbuttonState = 1;
    //Serial.print(startbuttonState);
  } else {
    	startbuttonState = 0;
  }
  

  	ranNum = random(0,6);
  	digitalWrite(leds[ranNum], HIGH);
  	delay(1000);
  	digitalWrite(leds[ranNum], LOW);
  

}

==============With start button====
int hitcount = 0;
int hitfinishcount = 0;

int leds[] = {2, 3, 4, 5, 6, 7};
int ledcount = 6;

const int startbutton =  A0;
int buttons[] = {8, 9, 10, 11, 12, 13};
int buttoncount = 6;

int startbuttonState = 0;
int ranNum = 0;

void setup()
{
  Serial.begin(9600); 
  
  for (int thisPin = 0; thisPin < ledcount; thisPin++) {
    pinMode(leds[thisPin], OUTPUT);
  }
  
  pinMode(startbutton, INPUT);
  for (int thisPin = 0; thisPin < buttoncount; thisPin++) {
    pinMode(buttons[thisPin], INPUT);
  }

}

void loop()
{
	if (digitalRead(startbutton) == HIGH && startbuttonState == 0) {
    	startbuttonState = 1;
        delay(500);
    	Serial.println("GO!!!");
 	 } 
  
	if (startbuttonState == 1) {
  		ranNum = random(0,6);
  		digitalWrite(leds[ranNum], HIGH);
		int del = 0;
		while(del < 1000){
			if(digitalRead(buttons[ranNum])){
				digitalWrite(leds[ranNum], LOW);
				hitcount ++;
				break;
			}
          	delay(1);
			del ++;
		}
  		digitalWrite(leds[ranNum], LOW);
		
		if(hitfinishcount > 29){
			Serial.print("Finish, Your score is: ");
			Serial.println(hitcount);
			startbuttonState = 0;
			hitfinishcount = 0;
			hitcount = 0;
		}
			
		hitfinishcount ++;
    }
  
}

===================Reset button is start button=========================
int hitcount = 0;
int hitfinishcount = 0;

int leds[] = {2, 3, 4, 5, 6, 7};
int ledcount = 6;

const int startbutton =  A0;
int buttons[] = {8, 9, 10, 11, 12, 13};
int buttoncount = 6;

int startbuttonState = 1;

int ranNum = 0;

void setup()
{
  Serial.begin(9600); 
  
  for (int thisPin = 0; thisPin < ledcount; thisPin++) {
    pinMode(leds[thisPin], OUTPUT);
  }
  
  pinMode(startbutton, INPUT);
  for (int thisPin = 0; thisPin < buttoncount; thisPin++) {
    pinMode(buttons[thisPin], INPUT);
  }
  
  Serial.println("GO!!!"); 

}

void loop()
{
  
	if (startbuttonState == 1) {
  		ranNum = random(0,6);
  		digitalWrite(leds[ranNum], HIGH);
		int del = 0;
		while(del < 1000){
			if(digitalRead(buttons[ranNum])){
				digitalWrite(leds[ranNum], LOW);
				hitcount ++;
              	Serial.print("score is: ");
			    Serial.println(hitcount);
				break;
			}
          	delay(1);
			del ++;
		}
  		digitalWrite(leds[ranNum], LOW);
		
		if(hitfinishcount > 29){
			Serial.print("Finish, Your score is: ");
			Serial.println(hitcount);
			startbuttonState = 0;
			hitfinishcount = 0;
			hitcount = 0;
		}
			
		hitfinishcount ++;
    }
  
}

================9 button========
int hitcount = 0;
int hitfinishcount = 0;

int leds[] = {2, 3, 4, 5, 6, 7, 8, 9, 10};
int ledcount = 9;

int buttons[] = {13, 12, 11, A5, A4, A3, A2, A1, A0};
int buttoncount = 9;

int startbuttonState = 1;

int ranNum = 0;

void setup()
{
  Serial.begin(9600); 
  
  for (int thisPin = 0; thisPin < ledcount; thisPin++) {
    pinMode(leds[thisPin], OUTPUT);
  }
  
  for (int thisPin = 0; thisPin < buttoncount; thisPin++) {
    pinMode(buttons[thisPin], INPUT);
  }
  
  Serial.println("GO!!!"); 

}

void loop()
{
  
	if (startbuttonState == 1) {
  		ranNum = random(0,ledcount);
  		digitalWrite(leds[ranNum], HIGH);
		int del = 0;
		while(del < 1000){
			if(digitalRead(buttons[ranNum])){
				digitalWrite(leds[ranNum], LOW);
				hitcount ++;
              	Serial.print("score is: ");
			    Serial.println(hitcount);
				break;
			}
          	delay(1);
			del ++;
		}
  		digitalWrite(leds[ranNum], LOW);
		
		if(hitfinishcount > 29){
			Serial.print("Finish, Your score is: ");
			Serial.println(hitcount);
			startbuttonState = 0;
			hitfinishcount = 0;
			hitcount = 0;
		}
			
		hitfinishcount ++;
    }
  
}

=================version 1.2============
int hitfinishcount = 0;

int leds[] = {2, 3, 4, 5, 6, 7, 8, 9, 10};
int ledcount = 9;

int buttons[] = {13, 12, 11, A5, A4, A3, A2, A1, A0};
int buttoncount = 9;

int startbuttonState = 1;

int ranNum = 0;
unsigned long del = 0;
unsigned long Seconds = 0;

void setup()
{
  Serial.begin(9600); 
  
  for (int thisPin = 0; thisPin < ledcount; thisPin++) {
    pinMode(leds[thisPin], OUTPUT);
  }
  
  for (int thisPin = 0; thisPin < buttoncount; thisPin++) {
    pinMode(buttons[thisPin], INPUT);
  }
  
  Serial.println("GO!!!"); 

}

void loop()
{

	if (startbuttonState == 1) {
  		ranNum = random(0,ledcount);
  		digitalWrite(leds[ranNum], HIGH);	
		while(1){
			if(digitalRead(buttons[ranNum])){
				digitalWrite(leds[ranNum], LOW);
                Seconds = del/1000;
              	Serial.print("score is: ");
			    Serial.print(Seconds);
                Serial.println(" sec");
				break;
			}
          	delay(1);
			del ++;
		}
  		digitalWrite(leds[ranNum], LOW);
		
		if(hitfinishcount > 29){
			Serial.print("Finish, Your score is: ");
			Serial.print(Seconds);
            Serial.println(" sec");
			startbuttonState = 0;
			hitfinishcount = 0;
		}
			
		hitfinishcount ++;
    }
  
}