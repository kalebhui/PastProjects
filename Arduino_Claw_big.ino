#include <NewPing.h>   // include the NewPing library for this program

#define VCC_PIN 13

#define TRIGGER_PIN 12 // sonar trigger pin will be attached to Arduino pin 12

#define ECHO_PIN 11 // sonar echo pint will be attached to Arduino pin 11

#define GROUND_PIN 10

#define MAX_DISTANCE 200 // fmaximum distance set to 200 cm

#include <Servo.h> //include the servo library for this program
boolean open = true;
int pos = 0; 
Servo myservo; //create servo object to control a servo

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // initialize NewPing



void setup() //do the following things once

{

  Serial. begin(9600);  // set data transmission rate to communicate with computer

  pinMode(ECHO_PIN, INPUT) ;  

  pinMode(TRIGGER_PIN, OUTPUT) ;

  pinMode(GROUND_PIN, OUTPUT);  // tell pin 10 it is going to be an output

  pinMode(VCC_PIN, OUTPUT);  // tell pin 13 it is going to be an output

  digitalWrite(GROUND_PIN,LOW); // tell pin 10 to output LOW (OV, or ground)

  digitalWrite(VCC_PIN, HIGH) ; // tell pin 13 to output HIGH (+5V)

  myservo.attach(8);

   for (pos = 0; pos <= 180; pos += 3) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15); }
open = true;
}



void loop() // do the following things forever

{

  delay(100); // wait for this number of milliseconds

  int DISTANCE_IN_CM = sonar.ping_cm(); // read the sonar sensor, using a variable

  Serial.print("Ping: "); //print "Ping:" on the computer display

  Serial.print(DISTANCE_IN_CM); //print the value of the variable next

  Serial.println("cm"); //print "cm" after that, then go to next line

  if(DISTANCE_IN_CM <= 30 && open == true) // when distance is less than 10 cm

  {

                        // waits 15ms for the servo to reach the position
    for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);
    }
      
    open = false;

    Serial.print("close"); //print the word "close"

    Serial.println(""); //print nothing, go to next line
    
    delay(7000); // return to original position in 1000 ms
    
  }
  
  if(DISTANCE_IN_CM <= 25 && open == false) // when distance is less than 10 cm

  {

    for (pos = 0; pos <= 180; pos += 2) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
    
    open = true;

    Serial.print("open"); //print the word "open"

    Serial.println(""); //print nothing, go to next line
    
  }
  
}
