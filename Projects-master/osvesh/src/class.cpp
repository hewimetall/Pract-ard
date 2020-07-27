#include "class.hpp"
osvesh::osvesh (int servo1_Pin,int servo2_Pin, // pin's use for  creat class Servo.
  int PinR_X , int PinR_0 ,  int PinR_Y // Pin's use out Rezistor
){

  Ser_D.Pin[0]=servo1_Pin;
  Ser_D.Pin[0]=servo2_Pin;

  Date_I.PinR[0]=PinR_X;
  Date_I.PinR[1]=PinR_0;
  Date_I.PinR[2]=PinR_Y;

}

int osvesh::init(int a){
  Ser_D.servo1.attach(Ser_D.Pin[0]);
  Ser_D.servo1.attach(Ser_D.Pin[1]);

  pinMode(Date_I.PinR[0], INPUT);
  pinMode(Date_I.PinR[1], INPUT);
  pinMode(Date_I.PinR[2], INPUT);

  return 0;
}

int osvesh::update(){
  P.e[0]=analogRead(Date_I.PinR[0]);
  P.e[1]=analogRead(Date_I.PinR[1]);
  P.e[2]=analogRead(Date_I.PinR[2]);
  P.vec[0]=P.e[0];-P.e[1]; // dx
  P.vec[1]=P.e[2]-P.e[1]; // dy

  error(String(Pvec.[1]), String(Pvec.[0]),1);

  P.n[0]=P.vec[0]/abs(P.vec[0]);
  P.n[0]=P.vec[0]/abs(P.vec[0]);
  return 0;
}

osvesh::error(String mess,String Log_e ,int l){
  Serial.println();
  Serial.print(Log_e+"::");
  Serial.println(mess);
  Serial.println();
}
