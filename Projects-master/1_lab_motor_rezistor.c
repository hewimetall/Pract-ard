//#include <Stepper.h>
#include <Arduino.h>
#define PIN_LED     11
#define PIN_POT     A0
#include <Stepper.h>

const int IN1 = 3;
const int IN2 = 4;
const int IN3 = 5;
const int IN4 = 6 ;

const int stepsPerRevolution = 200; // шагов за один оборот

Stepper myStepper(stepsPerRevolution, IN1, IN2, IN3, IN4);
 int stepCount = 0;  // number of steps the motor has taken
void setup()
{    Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  // Пин с переменным резистором является входом
  pinMode(PIN_POT, INPUT);
  Serial.println("Hello ");

}

void loop(){
 int sensorReading = analogRead(A0);
 int motorSpeed = map(sensorReading, 0, 1023, 0, 255);
 if (motorSpeed > 0) {
   Serial.println("Rezistor: ");Serial.println(sensorReading);
   Serial.println("Step moto: ");Serial.println( motorSpeed);

   myStepper.setSpeed(motorSpeed);
   myStepper.step(stepsPerRevolution / 100);
}
}
 
