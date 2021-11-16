#include <stdlib.h>
#include <Stepper.h>

#define CONNECT 7;

const int stepsPerRevolution = 64;
int exe;
// flag -> 다른 아두이노와 통신이 들어왓는가
int flag = 0;

// 결선 1, 2, 3, 4 차례로 8, 9, 10, 11
Stepper myStepper3(stepsPerRevolution, 11,9,10,8);
Stepper myStepper4(stepsPerRevolution, 6,4,5,3);  
void setup() {
  
  Serial.begin(9600);
  myStepper1.setSpeed(500);
  myStepper2.setSpeed(500);
  
}
void loop() {

  if(
  
  //flag를 1로 임의로 설정
  flag = 1;
  
  if(flag==1){
    //3, 4
    exe = (rand()%2)+3;
//    Serial.print(exe);
//    Serial.print("번 모터가 우측 방향으로 돌고 있습니다\n");
  }
  
  // 시계 반대 방향으로 한바퀴 회전
  switch(exe){
    case 3:
      for(int i=0; i<32; i++) {  // 64 * 32 = 2048 한바퀴
        myStepper3.step(stepsPerRevolution);
      } 
      break;
    case 4:
      for(int i=0; i<32; i++) {  
        myStepper4.step(stepsPerRevolution);
      } 
      break;
    default:
      break;
  }
  delay(500);
}
