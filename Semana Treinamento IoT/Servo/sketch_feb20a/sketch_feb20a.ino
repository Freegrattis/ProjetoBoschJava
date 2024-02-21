#include <Servo.h>

#define SERVO 9

Servo s; 
int pos; 
int esquerda = 5;
int direita = 3;
int pushbutton = 4;
void setup() { 

  s.attach(9);
  Serial.begin(9600);
  s.write(0);
  
  pinMode(pushbutton, INPUT);
  digitalWrite(pushbutton, HIGH);
  
}
void loop() {
  pos=digitalRead(pushbutton);  
   if(pos==0) 
    {
      Serial.println(pos);
       s.write(60);  //Move o servo para o angulo de 60 graus
       delay(15);          //Delay para o servo atingir a posiçao
    }

    
  
  }
