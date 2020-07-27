#define Nx 4
#define Ny 4
int sensorPin=0;
unsigned long timing; // velum time poin
long int Sold; //valuem set 0 step
//y[Ny][Nx];
#define N (5)

long int filter(unsigned long t=6000)
  {
    long int sum=0;
    long int i=0;
    for ( i=0 ; millis() - timing < t ; i++){
      sum+=  (analogRead(sensorPin)+analogRead(sensorPin)+analogRead(sensorPin)+analogRead(sensorPin)+analogRead(sensorPin)-5*Sold)/3;
    }
    timing = millis();
    return sum/i;

  }

long int date()
  {
    static long int m[N];
    static long int n;
    long int a=filter(1000);
    m[n]=a;
    n=(n+1)%N;
    a=0;
    for(int j=0;j<N;j++){a=a+m[j];Serial.println(a);}
    return a;
  }

void setup(){
Serial.begin(9600);
Sold=analogRead(sensorPin);
}
void loop(){
  Serial.println(date()/30);
}
