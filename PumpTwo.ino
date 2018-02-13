//    Program to use millis command/function to make a simple timer


//      Ronald Kiefer
//      October 2, 2014
//
//
//



  #define  minutesTime  2    // minutes to run pump  

  float  x=0.0;             // serial monitor variable
  
  int ledPin =  13;      // the number of the LED pin

  int ledState = LOW;            

  long intervalTime = 60000 *minutesTime+10000;           // interval at which to turn off led or pump

void setup() {
                                 // set the digital pin as output:
  pinMode(ledPin, OUTPUT); 
  Serial.begin(9600);           //  allow use of serial monitor
  
      digitalWrite (ledPin, ledState);  // delay before pump turns on
      delay(10000);
      ledState = HIGH;
      digitalWrite  (ledPin, ledState);   //pump turn on
}


void loop()
{
  
  Serial.println ("time");
  delay (1000);
  Serial.println  (x);  //  send to serial monitor the time
  delay (1000);
  Serial.println ("interval");
  Serial.println  ((intervalTime-10000)/1000);
  delay (1000);
  
  
  // here is where you'd put code that needs to be running all the time.
      
  
  
    static int y = 1;                    //    trip to make loop run only one time
  
    unsigned long currentMillis = millis();                //  tech to get time from start of program
    x=millis() /  1000 -10;               // calculate time
    if((currentMillis  > intervalTime)  &&  ( y=1)) {                //  determine if time is up and trip to run once
   
   
   
      if (ledState == HIGH)    // change of variable for state of led
          ledState = LOW;
    
     
     

                                                    // set the LED with the ledState of the variable:
          digitalWrite(ledPin, ledState);
    
          y = 2;                                        //   trip to make loop run once
    
  }
  
}

