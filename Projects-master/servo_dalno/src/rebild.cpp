#include <Arduino.h>
#include <Servo.h> // подключаем библиотеку для работы с сервоприводом
Servo servo; // объявляем переменную servo типа "servo"
#define trigPin 13
#define echoPin 12
void rotateReturn(unsigned long t=1);
void setup() {
   servo.attach(11); // привязываем сервопривод к аналоговому выходу 11
   Serial.begin(9600); // подключаем монитор порта
   Serial.println("test");
   pinMode(trigPin, OUTPUT);
   pinMode(echoPin, INPUT);
}

void loop() {
  rotateReturn(5);
//  Serial.print(":");Serial.print(P.tic);Serial.println(P.d);
}
