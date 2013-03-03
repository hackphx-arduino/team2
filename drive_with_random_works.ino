//int switchPinBlack = 5;     //black button
int y=4;        //variable set to neutral value
int x=4;
int z=4;
#include <Shieldbot.h>

Shieldbot shieldbot = Shieldbot();
void setup() {
  Serial.begin(9600);   
  //pinMode (switchPinBlack, INPUT); // black button
  digitalWrite (2, HIGH);// run voltage through black button
  attachInterrupt( 0, blackpush, FALLING); // when black button is pressed, interrupt
  digitalWrite (3, HIGH);
  attachInterrupt( 1, redpush, FALLING);
  shieldbot.setMaxSpeed(225);
  Serial.println("setup");
  randomSeed(analogRead(0));
}

void loop() {
 // while (y==4){ // may be redundant
  //  delay (1000);
  z= random (1,3);
    
  if (y==9){ //If black button is pressed, drive one wheel
    if (z==1){
      shieldbot.drive(50,0);
      
    }
    else if (z==2) {
      shieldbot.drive(0,50);
      
    }
   
 
    delay(500);
    y = 4;
    x = 4;
  }
  else if (y==4){
    shieldbot.drive(0,0);
    
    
  }
  else if (y==6){ //If black button is pressed, drive one wheel
     if (z==1){
      shieldbot.drive(50,0);
      
    }
    else if (z==2) {
      shieldbot.drive(0,50);
      
    }
   
 
    delay(500);
    y = 4;
    x = 4;
  }
  else {
    shieldbot.drive(0,0);
    
  }
    
}

  
  
  void blackpush(){
  y= 9;
  
  }  
  void redpush(){
    y= 6;
  }
