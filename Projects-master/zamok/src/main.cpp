#include <Arduino.h>
int i=0;
#define MicroD 11
#define MicroA A0
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(8, INPUT);
pinMode(10, INPUT);
pinMode(9, INPUT);

pinMode(A0, OUTPUT);
pinMode(11, OUTPUT);

}
void test(){
  auto _a=0;
  auto a=analogRead(MicroA);
  /*if(a!=_a){
    Serial.println(a);
  }
  _a=a;*/
  Serial.println(-a+392);

}
void loop() {
// put your main code here, to run repeatedly
/*  digitalWrite(8, 1);
  digitalWrite(9, 1);
  digitalWrite(10, 1);
  delay(100);
  digitalWrite(8,  0);
*/
//Serial.println(analogRead(A0));
test();

//Serial.println(digitalRead(11));
}
