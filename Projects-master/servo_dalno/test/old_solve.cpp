#include <Arduino.h>
#include <Servo.h> // подключаем библиотеку для работы с сервоприводом

#define trigPin 13
#define echoPin 12

int DIST;
struct point_t {
    int tic[2];
    int d=100000;
    int flag;
}; //Тут стоит точка с запятой!

 point_t P;
 int ROT[360*2];
 int flag=0;

Servo servo; // объявляем переменную servo типа "servo"

int scan(int old_d=DIST){
  if (DIST ==  0)DIST=100;
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  Serial.print(distance);Serial.print(":");Serial.println(DIST);
  if(old_d>distance){  flag=flag || 1; return distance ;}
  else  return old_d ;
}

void rotate(){
  int i=0;
  while (i<360) {
      /* code */
       servo.write(i); // передает значения для вала сервопривода
       if(P.flag){
          if(P.d != scan()){P.d=DIST;P.tic[0]=0;P.tic[1]=0};
          else {P.tic[0]++;}
        }
       else DIST=scan();
       i++;
       delay(10); // задержка в одну секунду
    }

    while (i>0) {
        /* code */
         servo.write(i); // передает значения для вала сервопривода
         DIST=scan();
         i--;
         delay(10); // задержка в одну секунду
      }
}
void setup() {
   servo.attach(11); // привязываем сервопривод к аналоговому выходу 11
   Serial.begin(9600); // подключаем монитор порта
Serial.println("test");
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  DIST=100;
}

void loop() {
rotate();

Serial.println("dist");
Serial.println(DIST);
}
