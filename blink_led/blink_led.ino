    /*
      Blink
      Turns on an LED on for one second, then off for one second, repeatedly.
     
      This example code is in the public domain.
     */
     
    // Pin 13 has an LED connected on most Arduino boards.
    // give it a name:
    int led1 = 12;
    int led2 = 13;
    int diff = 0;
     
    // the setup routine runs once when you press reset:
    void setup() {                
      // initialize the digital pin as an output.
      pinMode(led1, OUTPUT);  
      pinMode(led2, OUTPUT);     
    }
     
    // the loop routine runs over and over again forever:
    void loop() {
      digitalWrite(led1, HIGH);
      if(diff == 1){
         digitalWrite(led2, HIGH);
         diff = 0;
      }
      else
      diff = diff + 1;
      delay(1); 
      
      // wait for a second
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);// turn the LED on (HIGH is the voltage level)
      delay(1);               // wait for a second
    }
