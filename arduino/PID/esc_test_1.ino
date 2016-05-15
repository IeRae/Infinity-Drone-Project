#include <Servo.h>

Servo front, back, left, right;
int sig_front=0, sig_back=0, sig_left=0, sig_right=0,r1=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  front.attach(3,1000,2000);
  back.attach(5,1000,2000);
  left.attach(6,1000,2000);
  right.attach(10,1000,2000);
  front.write(0);
  back.write(0);
  left.write(0);
  right.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  sig_front=constrain(sig_front,0,179);
  sig_back=constrain(sig_back,0,179);
  sig_left=constrain(sig_left,0,179);
  sig_right=constrain(sig_right,0,179);
  
  Serial.setTimeout(50); //아래 parseInt로 값을 받는게 있는데, 이게 기본 딜레이가 1초가 있다. 그걸 50ms로 설정해주는 것. 속도를 빠르게 하기 위함.
  
  front.write(sig_front);
  back.write(sig_back);
  left.write(sig_left);
  right.write(sig_right);
}

void serialEvent()
{
  while (Serial.available()) {
    sig_front = Serial.parseInt();
    sig_back = Serial.parseInt();
    sig_left = Serial.parseInt();
    sig_right = Serial.parseInt();
    r1=Serial.parseInt();
  }
}
