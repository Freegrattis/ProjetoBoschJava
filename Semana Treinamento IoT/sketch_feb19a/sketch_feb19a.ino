int vermelho = 10;
int amarelo = 9;
int verde = 8;

int pushbutton = 2;
int led = 13; 
bool estadoled = 0;

void setup() {  
  pinMode(vermelho, OUTPUT);
  pinMode(amarelo, OUTPUT);
  pinMode(verde, OUTPUT);
  
  pinMode(pushbutton, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  
}
void loop() {  
  if (digitalRead(pushbutton) == LOW){
    estadoled = !estadoled; // troca o estado do LED
    digitalWrite(led, estadoled);
    while (digitalRead(pushbutton) == LOW);
    delay(100);
  /*
  digitalWrite(vermelho, LOW);
  digitalWrite(amarelo, HIGH);
  digitalWrite(verde, LOW);
 
  delay(2000);
 
  digitalWrite(amarelo, LOW);
  digitalWrite(vermelho, HIGH);
 
  delay(5000);  
 
  digitalWrite(verde, HIGH);
  digitalWrite(vermelho, LOW);

  delay(5000);*/
   
}
}
