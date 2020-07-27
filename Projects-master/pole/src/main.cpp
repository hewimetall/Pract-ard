#include <Arduino.h>
int i[2];
void setup() {
  Serial.begin(115200);
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  i[0]=(analogRead(A0) /100);

    if(!(i[0])){
      Serial.println("yes");
    }
    if((i[0]) && i[0]!=i[1]){
      Serial.println("not");
    }
    i[1]=i[0];
}
