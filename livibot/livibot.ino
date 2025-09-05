/********************************
LiviBot v9.0
Desenvolvido por André e Lívia
Setembro/2024
andlsouza@gmail.com
*********************************
hardware utilizado:
placa: Arduino UNO R3
display: LCD 2x16
buzzer passivo.
*********************************/

#include <LiquidCrystal.h>
#include "notas.h"
#include "melodias.h"

#define pinV0 5 //contraste lcd por pwm
#define pinBuz 6 //pino do buzzer
#define pinLed1 8
#define pinLed2 9

LiquidCrystal lcd(2,3,4,10,11,12,13);

void setup() {
  // put your setup code here, to run once:
  pinMode(pinV0, OUTPUT);
  analogWrite(pinV0,110); //contraste lcd: min 0 - max 150
  lcd.begin(16,2);
  pinMode(pinBuz, OUTPUT);
  pinMode(pinLed1, OUTPUT);
  pinMode(pinLed2, OUTPUT);
}

void piscaLeds()
{
  digitalWrite(pinLed1, LOW);
  digitalWrite(pinLed2, LOW);
  delay(100);
  digitalWrite(pinLed1, HIGH);
  digitalWrite(pinLed2, HIGH); 
}

void blink(int vezes)
{
  int i = 0;
  int v = 0;

  digitalWrite(pinLed1, LOW);
  digitalWrite(pinLed2, LOW);

  for(v=0; v<vezes; v++)
  {

    for(i=0; i<10; i++)
      {
        if((i==0)||(i==2)||(i==4)||(i==6)||(i==8))
          {
          digitalWrite(pinLed1, HIGH);
          digitalWrite(pinLed2, LOW);
          }
          else
            {
            digitalWrite(pinLed1, LOW);
            digitalWrite(pinLed2, HIGH);
            }
      delay(100);
      }

  }

  delay(100);
  digitalWrite(pinLed1, HIGH);
  digitalWrite(pinLed2, HIGH); 
}

void piscaLedsFast()
{
  digitalWrite(pinLed1, LOW);
  digitalWrite(pinLed2, LOW);
  delay(10);
  digitalWrite(pinLed1, HIGH);
  digitalWrite(pinLed2, HIGH);
  delay(10);
}

void piscaLedsMs(int ms)
{
  digitalWrite(pinLed1, HIGH);
  digitalWrite(pinLed2, HIGH);
  delay(ms/2);
  digitalWrite(pinLed1, LOW);
  digitalWrite(pinLed2, LOW);
  delay(ms/2);
}

void tocaBeep()
{
  int ritmo = 2; //1 = velocidade normal, 2 = velocidade 2x, 4 = velocidade 4x.
  int ralenta = 1; //velocidade / 1
  for(int nota = 0; nota< qtdNotasBeep * 2; nota += 2){
    int duracao = (beep[nota + 1]*ralenta) / ritmo;
    tone(pinBuz, beep[nota], duracao);
    delay(duracao);
  }
  noTone(pinBuz);
}

void tocaKKK()
{
  int ritmo = 2; //1 = velocidade normal, 2 = velocidade 2x, 4 = velocidade 4x.
  int ralenta = 1; //velocidade / 1
  for(int nota = 0; nota< qtdNotasKKK * 2; nota += 2){
    int duracao = (kkk[nota + 1]*ralenta) / ritmo;
    tone(pinBuz, kkk[nota], duracao);
    delay(duracao);
  }
  noTone(pinBuz);
}

void tocaMission()
{
  int ritmo = 1; //1 = velocidade normal, 2 = velocidade 2x, 4 = velocidade 4x.
  int ralenta = 1; //velocidade / 1

  for(int nota = 0; nota< qtdNotasMission * 2; nota += 2){
    int duracao = (mission[nota + 1]*ralenta) / ritmo;
    tone(pinBuz, mission[nota], duracao);
    //delay(duracao);
    piscaLedsMs(duracao);
  }

  noTone(pinBuz);
}

void tocaTfc()
{
  int ritmo = 2; //1 = velocidade normal, 2 = velocidade 2x, 4 = velocidade 4x.
  int ralenta = 3; //velocidade / 3

  for(int nota = 0; nota< qtdNotasTfc * 2; nota += 2){
    int duracao = (tfc[nota + 1]*ralenta) / ritmo;
    tone(pinBuz, tfc[nota], duracao);
    //delay(duracao);
    piscaLedsMs(duracao);
  }

  noTone(pinBuz);
}

void piada01()
{ 
  lcd.print("Vou te contar");
  lcd.setCursor(0,1);
  lcd.print("uma piada...");
  tocaBeep();
  delay(6000);
  lcd.clear();

  piscaLeds();

  lcd.print("Qual cidade");
  lcd.setCursor(0,1);
  lcd.print("nao tem taxi?");
  tocaBeep();
  delay(12000);
  lcd.clear();

  piscaLeds();

  lcd.print("Uberlandia!");
  lcd.setCursor(0,1);
  lcd.print("kkkkkkkkkkk");
  tocaKKK();
  delay(6000);
  lcd.clear();

  piscaLeds();
}

void piada02()
{
  lcd.print("Vou te contar");
  lcd.setCursor(0,1);
  lcd.print("outra piada...");
  tocaBeep();
  delay(6000);
  lcd.clear();

  piscaLeds();

  lcd.print("Qual e o mercado");
  lcd.setCursor(0,1);
  lcd.print("que voa?");
  tocaBeep();
  delay(12000);
  lcd.clear();

  piscaLeds();

  lcd.print("O super-mercado!");
  lcd.setCursor(0,1);
  lcd.print("kkkkkkkkkkk");
  tocaKKK();
  delay(6000);
  lcd.clear();

  piscaLeds();
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(pinLed1, HIGH);
  digitalWrite(pinLed2, HIGH);

  //escreve texto de boas vindas:
  lcd.print("Ola!");
  lcd.setCursor(0,1);
  lcd.print("Seja bem vindo!");
  tocaBeep(); //toca 3 beeps
  delay(6000);
  //blink(8); //aproximadamente 8s...
  lcd.clear();

  lcd.print("Feira de");
  lcd.setCursor(0,1);
  lcd.print("Ciencias do");
  tocaBeep(); //toca 3 beeps
  delay(6000);
  lcd.clear();

  lcd.print("Colegio Tema");
  lcd.setCursor(0,1);
  lcd.print("28/09/2024");
  tocaBeep(); //toca 3 beeps
  delay(6000);
  lcd.clear();

  lcd.print("Sou a LiviBot!");
  lcd.setCursor(0,1);
  lcd.print("A robozinha");
  tocaBeep(); //toca 3 beeps
  delay(6000);
  lcd.clear();

  lcd.print("que alegra");
  lcd.setCursor(0,1);
  lcd.print("as pessoas!");
  tocaBeep(); //toca 3 beeps
  //delay(5000);
  blink(6); //aproximadamente 6s...
  lcd.clear();

  //conta piada 1:
  piada01();

  piscaLeds();

  lcd.print("Agora vou tocar");
  lcd.setCursor(0,1);
  lcd.print("uma musica...");
  tocaBeep();
  delay(4000);

  piscaLeds();

  //toca música:
  tocaTfc();
  delay(500); //tempo depois da música
  lcd.clear(); //limpa display apenas após a música...

  piscaLeds();

  lcd.print("Conhecia essa?");
  lcd.setCursor(0,1);
  lcd.print("E dos anos 80!");
  tocaBeep();
  delay(6000);
  lcd.clear();

  piscaLeds();

  //conta piada 2:
  piada02();

  piscaLeds();

  lcd.print("Agora vou tocar");
  lcd.setCursor(0,1);
  lcd.print("outra musica...");
  tocaBeep();
  delay(4000);

  piscaLeds();

  //toca outra música:
  tocaMission();
  delay(500); //tempo depois da música
  lcd.clear(); //limpa display apenas após a música...

  piscaLeds();

  lcd.print("Gostou?");
  lcd.setCursor(0,1);
  lcd.print("Muito obrigada!");
  tocaBeep();
  delay(6000);
  lcd.clear();

  piscaLeds();

  //volta para o início (texto de boas vindas)...
}
