#include <Adafruit_GFX.h>
#include <Adafruit_GrayOLED.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_I2CDevice.h>

#include <Adafruit_SSD1306.h>

#include <Fonts/FreeSans9pt7b.h>
 
// Definição do display
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET 4
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
 
// Conexoes
#define BUZZER 9
#define BOTAO_ATIRA 3
#define BOTAO_DESCE 11
#define BOTAO_SOBE  12
 
// Notas musicais
const int c = 261;
const int d = 294;
const int e = 329;
const int f = 349;
const int g = 391;
const int gS = 415;
const int a = 440;
const int aS = 455;
const int b = 466;
const int cH = 523;
const int cSH = 554;
const int dH = 587;
const int dSH = 622;
const int eH = 659;
const int fH = 698;
const int fSH = 740;
const int gH = 784;
const int gSH = 830;
const int aH = 880;
 
// Imagem do xWing
const unsigned char PROGMEM xwing [] = {
  0x00, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x3F, 0xF0, 0x3C, 0x00, 0x3C, 0x00, 0xFF, 0x00, 0x7F, 0xFF,
  0x7F, 0xFF, 0xFF, 0x00, 0x3C, 0x00, 0x3C, 0x00, 0x1F, 0xF0, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00
};
 
// Imagem do Stormtrooper na tela inicial
const unsigned char PROGMEM storm [] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x7F, 0xFE, 0x00, 0x00, 0x00, 0x07, 0x80, 0x01, 0xE0, 0x00, 0x00, 0x0C,
  0x00, 0x00, 0x20, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x30, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x20, 0x00, 0x00, 0x04, 0x00, 0x00, 0x20, 0x00, 0x00, 0x04, 0x00, 0x00, 0x60, 0x00, 0x00,
  0x02, 0x00, 0x00, 0x40, 0x00, 0x00, 0x02, 0x00, 0x00, 0x40, 0x00, 0x00, 0x01, 0x00, 0x00, 0x40,
  0x00, 0x00, 0x01, 0x00, 0x00, 0x40, 0x00, 0x00, 0x01, 0x00, 0x00, 0x7F, 0xE0, 0x00, 0x01, 0x00,
  0x00, 0x7F, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x7F, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0xD7, 0xFF, 0xFF,
  0xE1, 0x00, 0x01, 0xBF, 0xFC, 0x1F, 0xFA, 0x80, 0x01, 0xBF, 0xF1, 0xCF, 0xFA, 0x80, 0x01, 0x3F,
  0xC2, 0x37, 0xF7, 0x80, 0x01, 0xEF, 0x9C, 0x01, 0xE7, 0xC0, 0x01, 0xE0, 0x70, 0x06, 0x06, 0x80,
  0x01, 0xE0, 0xC0, 0x03, 0x06, 0x80, 0x01, 0xFF, 0x80, 0x01, 0xFF, 0x80, 0x01, 0xF8, 0x00, 0x00,
  0x1D, 0xC0, 0x03, 0x70, 0x00, 0x80, 0x0C, 0x60, 0x05, 0xB0, 0x07, 0xF0, 0x08, 0x90, 0x09, 0x10,
  0x1F, 0xF8, 0x09, 0xD0, 0x0B, 0x90, 0x1F, 0x7C, 0x03, 0xF0, 0x0F, 0xC0, 0xFC, 0x0F, 0x07, 0x90,
  0x0D, 0x43, 0xC0, 0x03, 0x07, 0x90, 0x05, 0x64, 0x00, 0x00, 0xCF, 0x10, 0x07, 0xFC, 0x00, 0x00,
  0x26, 0x10, 0x01, 0x80, 0x00, 0x00, 0x10, 0x20, 0x01, 0x00, 0x00, 0x00, 0x0E, 0x40, 0x01, 0x80,
  0x07, 0xF0, 0x01, 0x80, 0x00, 0x80, 0x07, 0xC8, 0x00, 0x80, 0x00, 0x80, 0x0B, 0xE8, 0x00, 0x80,
  0x00, 0x87, 0x97, 0xE9, 0xE0, 0x80, 0x00, 0x87, 0xDF, 0xEF, 0xA0, 0x80, 0x00, 0x4B, 0xFF, 0xFF,
  0xA0, 0x80, 0x00, 0x6B, 0xDF, 0xFB, 0xA3, 0x00, 0x00, 0x24, 0x97, 0xE8, 0x24, 0x00, 0x00, 0x1E,
  0x1F, 0xC0, 0x2C, 0x00, 0x00, 0x07, 0xF8, 0x1F, 0xF0, 0x00, 0x00, 0x00, 0x0F, 0xF8, 0x00, 0x00
};
 
// Variaveis de controle do jogo
int pontos = 0;
int vidas = 5;
int nivel = 1;
unsigned long inicio = 0;   // início do jogo atual
unsigned long tempo = 0;    // instante atual
unsigned long tininiv = 0;  // quando o nível atual começou
 
// tiros do xWing
// obs: no display o eixo x é vertical e o eixo y é horizontal
int xw_tirox = 0;          // posição vertical do tiro do xwing
int xw_tiroy = 0;          // posição horizontal do tiro do xwing
bool xw_atirando = false;  // true se tiro do xwing no display
 
// tiros da estrela da morte
bool ds_armartiro = true;       // estrela da morte deve programar atirar
unsigned long ds_horatiro = 0;  // quando vai atirar
int ds_veltiros = 3;            // velocidade do tiro da estrela da morte
int ds_tiros = 0;               // numero de tiros no display
int ds_tirox[4] = { 95, 95, 95, 95 };
int ds_tiroy[4] = { 0, 0, 0, 0 };
 
// posição (vertical) do xwing
int xw_x = 30;   
 
// posição da estrela da morte
int ds_dir = 0;                 // direção da movimentação
int ds_y = 95;                  // posição horizontal da estrela da morte
int ds_x = 8;                   // posição vertical da estrela da morte
int ds_velx = 1;                // velocidade vertical da estrela da morte
int ds_diametro = 10;           // diametro da estrela da morte
 
// Iniciação
void setup()   {
 
  // Colocar pullup nos botões
  pinMode(BOTAO_SOBE, INPUT_PULLUP); //UP BUTTON
  pinMode(BOTAO_DESCE, INPUT_PULLUP); //DOWN BUTTON
  pinMode(BOTAO_ATIRA, INPUT_PULLUP); //TRIGGER BUTTON
 
  // Iniciar o display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
 
  // Tela inicial
  display.clearDisplay();
  display.setTextSize(0);
  display.drawBitmap(6, 0, storm, 48, 48, 1);
  display.setFont(&FreeSans9pt7b);
  display.setTextColor(WHITE);
  display.setCursor(65, 14);
  display.println("xWing");
  display.setFont();
  display.setCursor(65, 17);
  display.setTextSize(0);
  display.println("vs");
  display.setFont(&FreeSans9pt7b);
  display.setCursor(65, 39);
  display.println("Death");
  display.setFont();
  display.setCursor(65, 42);
  display.println("star ");
  display.display();
 
  // Marcha imperial
  delay(300);
  beep(a, 500);
  beep(a, 500);
  beep(a, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 650);
  delay(1000);
 
  inicio = millis();
}
 
// Loop principal
void loop() {
 
  if (vidas > 0) {
    display.clearDisplay();
    desenha_estrelas();
 
    // trata mudança de nível
    tempo = millis();
    if ((tempo - tininiv) > 50000) {
      tininiv = tempo;
      nivel = nivel + 1;
      ds_veltiros = ds_veltiros + 1; // tiros mais rápidos
      if (nivel % 2 == 0) {
        ds_velx = ds_velx + 1;
        ds_diametro = ds_diametro - 1;
      }
      tone(BUZZER, 500, 300);
      delay(300);
      tone(BUZZER, 1000, 200);
      delay(200);
    }
 
    // trata tiros da estrela da morte
    if (ds_armartiro) {
      ds_horatiro = millis() + random(400, 1200);
      ds_armartiro = false;
    }
    if (ds_horatiro < tempo)
    {
      ds_armartiro = true;
      ds_atira();
    }
    desenha_dstiros();
 
    // trata botão sobe
    if (digitalRead(BOTAO_SOBE) == 0 && xw_x >= 2) {
      xw_x = xw_x - 2;
    }
 
    // trata botão desce
    if (digitalRead(BOTAO_DESCE) == 0 && xw_x <= 46) {
      xw_x = xw_x + 2;
    }
 
    // trata botão atira
    if (digitalRead(BOTAO_ATIRA) == 0 && !xw_atirando) {
      xw_atirando = true;
      xw_tiroy = 6;
      xw_tirox = xw_x + 8;
      tone(9, 1200, 20);
    }
    if (xw_atirando == 1) {
      // Move e desenha o tiro
      xw_tiroy = xw_tiroy + 8 ;
      display.drawLine(xw_tiroy, xw_tirox, xw_tiroy + 4, xw_tirox, 1);
    }
    if (xw_tiroy > 128) {
      xw_atirando = false;  // tiro saiu da tela
    }
 
    // desenha o xwing
    display.drawBitmap(4, xw_x, xwing, 16, 16, 1);
     
    // desenha a estrela da morte
    display.fillCircle(ds_y, ds_x, ds_diametro, 1);
    display.fillCircle(ds_y + 2, ds_x + 3, ds_diametro / 3, 0);
     
    // informações
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(33, 57);
    display.println("pontos:");
    display.setCursor(74, 57);
    display.println(pontos);
    display.setCursor(33, 0);
    display.println("vidas:");
    display.setCursor(68, 0);
    display.println(vidas);
    display.setCursor(110, 0);
    display.println("N:");
    display.setCursor(122, 0);
    display.println(nivel);
    display.setCursor(108, 57);
    display.println((tempo-inicio) / 1000);
    display.display();
 
    // move a estrela da morte
    if (ds_dir == 0) {
      ds_x = ds_x + ds_velx;
    } else {
      ds_x = ds_x - ds_velx;
    }
    if (ds_x >= (64 - ds_diametro)) {
      ds_dir = 1;
    }
    if (ds_x <= ds_diametro) {
      ds_dir = 0;
    }
 
    // verifica se tiro acertou a estrela da morte
    if ((xw_tirox >= (ds_x - ds_diametro)) && (xw_tirox <= (ds_x + ds_diametro))) {
      if ((xw_tiroy > (ds_y - ds_diametro)) && (xw_tiroy < (ds_y + ds_diametro)))
      {
        xw_tiroy = -20;
        tone(9, 500, 20);
        pontos = pontos + 1;
        xw_atirando = false;
      }
    }
 
    // verifica se algum tiro da estrela da morte acertou o xwing
    int pos = xw_x + 8;
    for (int i = 0; i < 4; i++) {
      if ((ds_tiroy[i] >= (pos - 8)) && (ds_tiroy[i] <= (pos + 8))) {
        if ((ds_tirox[i] < 12) && (ds_tirox[i] > 4)) {
          ds_tirox[i] = -50;
          ds_tiroy[i] = -50;
          tone(9, 100, 100);
          vidas = vidas - 1;
          if (i == 3) {
            ds_tiros = 0;
          }
          if (vidas == 0) {
            break;
          }
        }
      }
    }
 
    if (ds_tirox[3] < 1) {
      ds_tiros = 0;
      ds_tirox[3] = 200;
    }
 
    if (vidas == 0) {
      game_over();
    }
  } else {
     
    // aguarda apertar ATIRA para começar outro jogo
    if (digitalRead(BOTAO_ATIRA) == 0)
    {
      tone(BUZZER, 280, 300);
      delay(300);
      tone(BUZZER, 250, 200);
      delay(200);
      tone(BUZZER, 370, 300);
      delay(300);
      reinicia();
      inicio = millis();
    }
  }
}
 
// Reinicia o jogo
void reinicia() {
  xw_tiroy = 0;
  xw_tirox = 0;
  xw_atirando = false;
  ds_x = 8;
  ds_dir = 0;
  pontos = 0;
 
  ds_veltiros = 3;
  ds_velx = 1;
  ds_diametro = 12;
 
  ds_armartiro = true;
  ds_horatiro = 0;
  ds_tiros = 0;
  for (int i = 0; i < 4; i++) {
    ds_tirox[i] = 95;
    ds_tiroy[i] = 0;
  }
 
  vidas = 5;
  nivel = 1;
  tempo = 0;
  tininiv = 0;
}
 
// Toca uma nota
void beep(int note, int duration) {
  tone(BUZZER, note, duration);
  delay(duration);
  noTone(BUZZER);
  delay(50);
}
 
// Desenha as estrelas ao fundo
void desenha_estrelas() {
  display.drawPixel(50, 30, 1);
  display.drawPixel(30, 17, 1);
  display.drawPixel(60, 18, 1);
  display.drawPixel(55, 16, 1);
  display.drawPixel(25, 43, 1);
  display.drawPixel(100, 43, 1);
  display.drawPixel(117, 52, 1);
  display.drawPixel(14, 49, 1);
  display.drawPixel(24, 24, 1);
  display.drawPixel(78, 36, 1);
  display.drawPixel(80, 57, 1);
  display.drawPixel(107, 11, 1);
  display.drawPixel(150, 11, 1);
  display.drawPixel(5, 5, 1);
  display.drawPixel(8, 7, 1);
  display.drawPixel(70, 12, 1);
  display.drawPixel(10, 56, 1);
  display.drawPixel(70, 25, 1);
}
 
// Estrela da morte atira
void ds_atira() {
  if (ds_tiros < 4) {
    ds_tirox[ds_tiros] = 95;
    ds_tiroy[ds_tiros] = ds_x;
    ds_tiros = ds_tiros + 1;
  }
}
 
// Desenha tiros da Estrela da morte
void desenha_dstiros() {
  for (int i = 0; i < ds_tiros; i++) {
    if (ds_tirox[i] >= 0) {
      display.drawCircle(ds_tirox[i], ds_tiroy[i], 2, 1);
      ds_tirox[i] = ds_tirox[i] - ds_veltiros;
    }
  }
}
 
// Desenha a tela de fim do jogo
void game_over() {
  tone(BUZZER, 200, 300);
  delay(300);
  tone(BUZZER, 250, 200);
  delay(200);
  tone(BUZZER, 300, 300);
  delay(300);
       
  display.clearDisplay();
  display.setFont();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(7, 10);
  display.println("GAME OVER!");
  display.setTextSize(1);
  display.setCursor(7, 30);
  display.println("pontos:");
  display.setCursor(50, 30);
  display.println(pontos);
  display.setCursor(7, 40);
  display.println("nivel:");
  display.setCursor(44, 40);
  display.println(nivel);
  display.setCursor(7, 50);
  display.println("tempo(s):");
  display.setCursor(66, 50);
  display.println((tempo - inicio) / 1000);
  display.display();
}
