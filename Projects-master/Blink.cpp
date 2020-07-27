#include "HX711.h"
#include <Arduino.h>
// HX711.DOUT	- pin #A1
// HX711.PD_SCK	- pin #A0
#define N 2
HX711 scale(A1, A0);		// parameter "gain" is ommited; the default value 128 is used by the library
long int calib=0;

long read_average(byte n) {
	long sum = 0;
	for (byte i = 0; i < n; i++) {
		sum += scale.read()/100;
	}
	return sum / n;
}

long s_av(byte n)
{
  long sum = 0;
	for (byte i = 0; i < n; i++) {
		sum +=calib-read_average( 10);
	}
	return sum / n;
}
void setup() {
  Serial.begin(38400);
  Serial.println("HX711 Demo");
  calib=(read_average( 15));

}

void loop() {
  int a=(s_av(10)-1)/ 4.3;
  Serial.println(a);
}
