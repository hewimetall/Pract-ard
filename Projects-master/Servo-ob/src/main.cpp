#include <Arduino.h>
#define T(X) Serial.println(#X)
#define Ne(X) Serial.println(X)
int sensorPin=A0;
int ServoPin=6;

long int var(){
  long int i=0;
  long int sum=0;
  int currentValue, prevValue;
  unsigned int timing=millis();
  for ( i=0 ; millis() - timing <  6000 ; i++){
    currentValue = digitalRead(sensorPin);
      if (currentValue != prevValue) {
        // А вот теперь спокойно считываем значение, считая, что нестабильность исчезла
        currentValue = digitalRead(sensorPin);
        sum+=1;
      }
      prevValue = currentValue;
  }
  if(!(sum/40) || sum == 0){
    return sum;
  }

  return sum/40;
}
void cryt(int value){
  int   wait ,i = 10;
  long int sum;
//    for(i = 255;i>159;i=i-10) {

      analogWrite(ServoPin,value);
      delay(wait);
      Serial.print(value);Serial.print(":");Serial.println(var());

//    }

}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
      pinMode(6, OUTPUT);      // установка порта на выход
}

void loop() {
  int x;
/*  for(;;){
  if (Serial.available() > 0) {
                     // считываем принятый байт:
  x = Serial.read();
  }
} */
  x=5;
  x=3.44*x+10.41;
  cryt(x);
}
