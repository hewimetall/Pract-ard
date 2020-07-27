#include <Arduino.h>
#include <Servo.h> // подключаем библиотеку для работы с сервоприводом

struct servo_date {
  //Creat class Servo
  Servo servo1;
  Servo servo2;
  int Pin[2];
};
struct d_Os{
  float I[3];//Intensivnost  x 0 y
  int PinR[3];// Output R x 0 y
};
struct point{
  int e[3];//x o y
  int vec[2]; // dx dy
  int n[2];
};
class osvesh {
private:
//date
  servo_date Ser_D; //Creat 2 class Servo
  d_Os Date_I; // input I[3] and PinR[3]
/////////////////////////////////////////////////////////
  //func
  int init(int a); // this f init Pin class servo1 servo +
  int update(); // update date
  point obr(); // norm znachenie
/////////////////////////////////////////////////////////
public:
//date
point P;
  ///////////////////////////////////////////////////////
// F

  int rotate(int step); // rotate
  int error(String mess,String Log_e );
  osvesh (int servo1_Pin,int servo2_Pin, // pin's use for  creat class Servo.
    int PinR_X , int PinR_0 ,  int PinR_Y // Pin's use out Rezistor
  );//constr +
  virtual ~osvesh ();
};
