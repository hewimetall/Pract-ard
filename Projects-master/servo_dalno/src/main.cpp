#include <Arduino.h>
#include <Servo.h> // подключаем библиотеку для работы с сервоприводом
extern Servo servo; // объявляем переменную servo типа "servo"
#define TRIG_PIN 13
#define ECHO_PIN 12
#define OTLADKA 1;
struct point_t {
    int tic=0;
    int d=2000;
}P; //Тут стоит точка с запятой!

int scan(){
  int duration, distanceCm;
//Задаем короткий импульс LOW заблаговременно, чтобы обеспечить чистый импульс HIGH:
 digitalWrite(TRIG_PIN, LOW);
 delayMicroseconds(2);
 digitalWrite(TRIG_PIN, HIGH);
 delayMicroseconds(10); digitalWrite(TRIG_PIN, LOW);
 duration = pulseIn(ECHO_PIN,HIGH);
// Преобразуем время в расстояние
 distanceCm = duration / 29.1 / 2 ;
 if (distanceCm <= 0){ Serial.println("Out of range in scan for var distanceCm ");
 return -1;
 }
 else {
#ifdef OTLADKA
   Serial.print(distanceCm);
   Serial.println(" cm");
#endif

   return distanceCm;
 }
}
//f obr date
int dalnom() {
  int distance=scan();
if(distance==-1){ return 0;}
else{
  //Serial.print(distance);
  //Serial.println(" cm");
  if(P.d<0){ P.d=1000;return -1 ;}
  if(P.d>distance){
    P.d=distance;
    P.tic=0;
  }
  else { P.tic++; }
}
  return 0;
}
//f for ratate servo 0-180 deg or dalnom , which write on P.d .
void rotate(){
  for(int i = 0; i < 180; i++) {
    /* code */
     servo.write(i); // передает значения для вала сервопривода
     if(dalnom()==-1){ Serial.print("dalnom error -1");}
     delay(10);
   }
}
// f step return on position min dalnom
void rotateReturn(unsigned long t=1){
  rotate();
  ///// trace P.tic
    Serial.print("P.tic::");
    Serial.print(P.tic);
    Serial.print(":P.d:");
    Serial.println(P.d);
  //////
  for (int  i = 0; i <= P.tic; i++) {
    servo.write(180-i); // передает значения для вала сервопривода
    delay(10);
  }
  P.d=2000;
  delay(t*1000);
}
