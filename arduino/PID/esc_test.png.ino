#include <Servo.h>

Servo esc_1; //아두이노로 컨트롤하는 bldc모터의 경우
Servo esc_2; //서보 라이브러리를 통해 쉽게 조작할 수 있다.
Servo esc_3;
Servo esc_4;


int black = 0; //모터로 들어가는 초기값은 0. 즉 최소값.
int red = 0;


void setup() {

  Serial.begin(9600); //시리얼 통신으로 조작한다.
  esc_1.attach(3, 1000, 2000); //이런식으로 서보를 선언해줘야 컨트롤이 가능하다.
  esc_2.attach(5, 1000, 2000); //나는 6번, 7번에 연결했다.
  esc_3.attach(6, 1000, 2000);
  esc_4.attach(10, 1000, 2000);

  Serial.setTimeout(50); //아래 parseInt로 값을 받는게 있는데, 이게 기본 딜레이가 1초가 있다. 그걸 50ms로 설정해주는 것. 속도를 빠르게 하기 위함.


  esc_1.write(0); //초기값은 무조건 0!!! 캘리브레이션과 다르다.
  esc_2.write(0);
  esc_3.write(0);
  esc_4.write(0);


}

void loop() {


  esc_1.write(red);
  //esc_2.write(red);
  esc_3.write(red);
  //esc_4.write(red);

  Serial.print(red);
  Serial.println('\t');
}


void serialEvent()
{
  while (Serial.available()) {
    red = Serial.parseInt();
  }
}

