#include <Servo.h>

#define SERVO 6

Servo s; 
int pos; 

int pushbutton2=12;
int pushbutton = 7;


void setup() { 

  s.attach(SERVO);
  Serial.begin(9600);
  s.write(0);
  
 
  pinMode(pushbutton2, INPUT); 
  pinMode(pushbutton, INPUT_PULLUP);

  
}
void loop() { 
  if(digitalRead(pushbutton2)==0){

    pos += 5;
    s.write(pos);
    Serial.println(digitalRead(pushbutton2));
  }
}
