#include <Servo.h>

#define SERVO 6

Servo s; 
int pos; 

int pushbutton = 7;
int led = 10; 
bool estadoled = 0;

void setup() { 

  s.attach(SERVO);
  Serial.begin(9600);
  s.write(0);
  
  pinMode(11,OUTPUT); 
  pinMode(pushbutton, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  
}
void loop() { 
  
  int buttonState=digitalRead(pushbutton);
  if (buttonState == LOW){
    trocaled();
    som();
    
    while (digitalRead(pushbutton) == LOW);
    delay(100);

   }
}

void trocaled(){
  estadoled = !estadoled; // troca o estado do LED
  digitalWrite(led, estadoled);
  delay(10);
}


void som(){
  int tempo = 40;
  tone(11,392,tempo); //SOL
  delay(tempo);
}
