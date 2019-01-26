/********************HEADER********************
    PROJECT: Useless Box
    AUTHOR: Lucas E. Mori
    COURSE: CONTROL AND AUTOMATION ENGINEERING
    LATEST MODIFICATION: 02/11/2018
***********************************************/

/*********************SETUP*********************
  coverS - 160    CLOSE DOOR
  coverS - 40     OPEN DOOR
  handS - 0       CLOSE HAND
  handS - 163     OPEN HAND
  leitura < 20    ACTIVATED LEVER
  leitura > 1000  DISABLED LEVER
************************************************/

const coverSc = 160;  // SETUP CLOSE DOOR
const coverSo = 40;   // SETUP OPEN DOOR
const handSc = 0;     // SETUP CLOSE HAND
const handSo = 163;   // SETUP OPEN HAND

#define blueLed A0
#define greenLed A1
#define lever A2
#include <Servo.h>
Servo handS;
Servo coverS;
int posH = 0;
int posC = 0;
float leituraalavanca;
int tb = 0;
long randNumber;
int lotado = 0;

//--------------------basic--move--------------------
void simpleClose()
{
  //Moving door abrindo
  for (posC = coverSc; posC >= coverSo; posC -= 3)
  {
    coverS.write(posC);
    delay(15);
  }
  //Moving hand
  for (posH = handSc; posH <= handSo; posH += 4)
  {
    handS.write(posH);
    delay(15);
  }
  //hiding hand
  for (posH = handSo; posH >= handSc; posH -= 4)
  {
    handS.write(posH);
    delay(15);
  }
  //hiding door
  for (posC = coverSo; posC <= coverSc; posC += 3)
  {
    coverS.write(posC);
    delay(15);
  }
}
//----------------------------------------------------

//open and wait, then move finger and wait, then switch of and hide
void simpleClose2()
{
  //Moving door
  for (posC = coverSc; posC >= coverSo; posC -= 3)
  {
    coverS.write(posC);
    delay(15);
  }
  delay(800);
  //Moving hand
  for (posH = 0; posH <= 100; posH += 4)
  {
    handS.write(posH);
    delay(15);
  }
  delay(1000);
  //Moving hand
  for (posH = 100; posH <= handSo; posH += 4)
  {
    handS.write(posH);
    delay(15);
  }
  //hiding hand
  for (posH = handSo; posH >= handSc; posH -= 5)
  {
    handS.write(posH);
    delay(15);
  }
  //hiding door
  for (posC = coverSo; posC <= coverSc; posC += 3)
  {
    coverS.write(posC);
    delay(15);
  }
}
//----------------------------------------

//open door then close it many times, wait, then quickly reopen, switch off and hide.
void crazydoor()
{
  //Moving door
  for (posC = coverSc; posC >= coverSo; posC -= 3)
  {
    coverS.write(posC);
    delay(15);
  }
  //hiding door
  for (posC = coverSo; posC <= coverSc; posC += 5)
  {
    coverS.write(posC);
    delay(15);
  }
  //Moving door
  for (posC = coverSc; posC >= coverSo; posC -= 3)
  {
    coverS.write(posC);
    delay(15);
  }
  //hiding door
  for (posC = coverSo; posC <= coverSc; posC += 15)
  {
    coverS.write(posC);
    delay(15);
  }
  delay(700);
  //Moving door
  for (posC = coverSc; posC >= coverSo; posC -= 3)
  {
    coverS.write(posC);
    delay(15);
  }
  delay(700);
  //hiding door
  for (posC = coverSo; posC <= coverSc; posC += 5)
  {
    coverS.write(posC);
    delay(15);
  }
  //Moving door
  for (posC = coverSc; posC >= coverSo; posC -= 8)
  {
    coverS.write(posC);
    delay(15);
  }
  //Moving hand
  for (posH = handSc; posH <= handSo; posH += 3)
  {
    handS.write(posH);
    delay(15);
  }
  //hiding hand
  for (posH = handSo; posH >= handSc; posH -= 3)
  {
    handS.write(posH);
    delay(15);
  }
  //hiding door
  for (posC = coverSo; posC <= coverSc; posC += 15)
  {
    coverS.write(posC);
    delay(15);
  }
}


//open door,move finger very slowly forward and back to hiding very slowly, then quickly close door
void slow()
{
  //Moving door
  for (posC = coverSc; posC >= coverSo; posC -= 1)
  {
    coverS.write(posC);
    delay(30);
  }
  //Moving hand
  for (posH = handSc; posH < handSo; posH += 1)
  {
    handS.write(posH);
    delay(30);
  }
  //hiding hand
  for (posH = handSo; posH >= handSc; posH -= 1)
  {
    handS.write(posH);
    delay(30);
  }
  //hiding door
  for (posC = coverSo; posC <= coverSc; posC += 1)
  {
    coverS.write(posC);
    delay(30);
  }
}
//----------------------------------------

//--------------------serious--------------------
void serious() {

  //Moving door
  for (posC = coverSc; posC >= coverSo; posC -= 3)
  {
    coverS.write(posC);
    delay(15);
  }
  //Moving hand
  for (posH = 0; posH <= 70; posH += 1)
  {
    handS.write(posH);
    delay(15);
  }
  delay(800);
  //hiding door
  for (posC = coverSo; posC <= 60; posC += 3)
  {
    coverS.write(posC);
    delay(15);
  }
  //hiding door
  for (posC = 60; posC <= 90; posC += 3)
  {
    coverS.write(posC);
    delay(15);
  }
  //moving door
  for (posC = 90; posC >= coverSo; posC -= 3)
  {
    coverS.write(posC);
    delay(15);
  }
  //Moving hand
  for (posH = handSc; posH <= handSo; posH += 4)
  {
    handS.write(posH);
    delay(15);
  }
  //hiding hand
  for (posH = handSo; posH >= handSc; posH -= 4)
  {
    handS.write(posH);
    delay(15);
  }
  //hiding door
  for (posC = coverSo; posC <= coverSc; posC += 1)
  {
    coverS.write(posC);
    delay(15);
  }
}
//----------------------------------------
void setup()
{
  pinMode(blueLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(lever, INPUT_PULLUP);
  handS.attach(9);
  coverS.attach(10);
  handS.write(0);
  delay(1000);
  coverS.write(coverSc);
  randomSeed(analogRead(A5));
}
void loop()
{
  leituraalavanca = analogRead(lever);
  if (leituraalavanca < 20)
  {
    randNumber = random(0, 5);
    delay(100);
    switch (randNumber)
    {
      case 0:
        analogWrite(blueLed, 255);
        simpleClose();
        analogWrite(blueLed, 0);
        break;
      case 1:
        analogWrite(greenLed, 255);
        crazydoor();
        analogWrite(greenLed, 0);
        break;
      case 2:
        analogWrite(blueLed, 255);
        simpleClose2();
        analogWrite(blueLed, 0);
        break;
      case 3:
        analogWrite(greenLed, 255);
        slow();
        analogWrite(greenLed, 0);
        break;
      case 4:
        analogWrite(greenLed, 255);
        analogWrite(blueLed, 255);
        serious();
        analogWrite(greenLed, 0);
        analogWrite(blueLed, 0);
        break;
    }
  }
}//fim do loop