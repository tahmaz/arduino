/ Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;
int led1 = 5;

int inPin1 = 10;
int inPin2 = 11;
int inPin3 = 12;

int reset=0;
int val1 = 0;     // variable for reading the pin status
int val2 = 0;
int val3 = 0;

String code="";
int butres1=0;
int butres2=0;
int butres3=0;


// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  pinMode(led1, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  
  
  val1 = digitalRead(inPin1);  // read input value
  if (val1 == LOW) {         // check if the input is HIGH (button released)
    code.concat("1");
    reset=0;
    delay(400);
  }
  
  val2 = digitalRead(inPin2);  // read input value
  if (val2 == LOW) {         // check if the input is HIGH (button released)
    code.concat("2");
    reset=0;
    delay(400);
  }

  
  val3 = digitalRead(inPin3);  // read input value
  if (val3 == LOW){          // check if the input is HIGH (button released)
    code.concat("3");
    
    if(code=="1123")
    digitalWrite(led1, HIGH);
    
    reset=0;
    delay(400); 
  }
  
  
  reset=reset+1;
  if (reset > 100){
    reset=0;
    code="";
    if(digitalRead(led)){
       digitalWrite(led, LOW);
    }
    else{
       digitalWrite(led, HIGH);
    }
    digitalWrite(led1, LOW);
  }
  
  if(code.length()>10)
  code="";
  
  delay(30);  
  
}