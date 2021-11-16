#include <stdlib.h>
#include <Stepper.h>

#define CONNECT 7
#define HANUL 2

const int stepsPerRevolution = 64;
int exe;
// flag -> 다른 아두이노와 통신이 들어왓는가

// 결선 1, 2, 3, 4 차례로 8, 9, 10, 11
Stepper myStepper1(stepsPerRevolution, 11,9,10,8);
Stepper myStepper2(stepsPerRevolution, 6,4,5,3);  
void setup() {
  Serial.begin(9600);
  myStepper1.setSpeed(500);
  myStepper2.setSpeed(500);
  pinMode(HANUL, INPUT);
  pinMode(CONNECT, OUTPUT);
}
void loop() {
  
  int flag = digitalRead(HANUL);

  Serial.println(flag);
  
  if(flag==1){
    Serial.println("통신됨");
    //랜덤으로 4개중 하나 돌리기
    exe = (rand()%4)+1;
    //Serial.print(exe);
    if(exe>2){
      digitalWrite(CONNECT, 1);
    }
    Serial.print(exe);
    Serial.print("번 모터가 우측 방향으로 돌고 있습니다\n");
  }
  
  // 시계 반대 방향으로 한바퀴 회전
  switch(exe){
    case 1:
      for(int i=0; i<32; i++) {  // 64 * 32 = 2048 한바퀴
        myStepper1.step(stepsPerRevolution);
      } 
      break;
    case 2:
      for(int i=0; i<32; i++) {  
        myStepper2.step(stepsPerRevolution);
      } 
      break;
    default:
      break;
  }
  
//   delay(1000);
   flag=0;
  
}
