#include <Servo.h>


#define TR 0
#define MR 1
#define DR 2
#define TL 3
#define ML 4
#define DL 5
#define RX 11
#define TX 12
#define LEDPin 13

int deg = 0;

Servo myservo[6];

void setServo(int ID);


void setup()
{
  for(int i = 0; i < 6; i++){
    pinMode(i+2,  OUTPUT);
    myservo[i].attach(i+2);
  }

  //LEDPin
  pinMode(LEDPin, OUTPUT);
  digitalWrite(LEDPin, 1);

  for(int i = 0;i < 6;i++){
    setServo(i,deg);
  }
}


  

void loop(){
  setServo(DR,-15);
  setServo(DL,-15);
  for(deg;deg <= 30;deg++){
    setServo(TR,-deg);
    setServo(TL,deg);
    setServo(MR,-deg);
    setServo(ML,deg);
    delay(10);
  }
  setServo(DR,0);
  setServo(DL,0);
  setServo(DR,15);
  setServo(DL,15);
  for(deg;deg >= -30;deg--){
    setServo(TR,-deg);
    setServo(TL,deg);
    setServo(MR,-deg);
    setServo(ML,deg);
    delay(10);
  }
  setServo(DL,0);
  setServo(DR,0);
}


void setServo(int ID , int degree){
  myservo[ID].write(degree + 90);
}
