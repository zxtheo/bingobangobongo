#include <Servo.h>

int bpm = 0; 
Servo myservoo, myservot;
void setup() {
  // put your setup code here, to run once:
  myservoo.attach(10); 
  myservot.attach(11);

  Serial.begin(9600);
Serial.println("Hi!, I am Arduino");
}

void bongo(){
  long delayTime = (60000/bpm)/2;
  for (int i = 135; i >=45; i-=1.5){
    myservoo.write(i);            
  }
  
  for (int i = 135; i >=45; i-=1.5){
    myservot.write(i);
  }
  delay(delayTime);
  for (int i = 45; i <=135; i+= 1.5){
    myservoo.write(i);             
  }
  for (int i = 45; i <=135; i+= 1.5){
    myservot.write(i);             
  }
  delay(delayTime);
}

int char1;
int char2;
int char3;


void loop() {
  bongo();

  if (Serial.available() > 0) {

    char1 = Serial.parseInt();
    bpm = char1;
    }
}
