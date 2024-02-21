#include <Servo.h> //INCLUSÃO DA BIBLIOTECA NECESSÁRIA
 
Servo servo; //OBJETO DO TIPO SERVO
 
const int pinoPOT = A0;
const int pinoServo = 3; 
 
int leA0;   
  
void setup(){
  servo.attach(pinoServo); 
  pinMode(pinoPOT, INPUT); //DEFINE A PORTA COMO ENTRADA 
} 
void loop(){ 
  leA0 = analogRead(pinoPOT); 
  leA0 = map(leA0, 0, 1023, 0, 180); 
  servo.write(leA0); 
  delay(0.5);
}
