#include <stdlib.h>
#include <Stepper.h>
#define CI 12
#define CO 13

int before = 0;
const int stepsPerRevolution = 64;
int exe;

// flag -> 다른 아두이노와 통신이 들어왓는가
// 결선 1, 2, 3, 4 차례로 8, 9, 10, 11
Stepper myStepper1(stepsPerRevolution, A3,A1,A2,A0);
Stepper myStepper2(stepsPerRevolution, 3,A5,2,A4);  
Stepper myStepper3(stepsPerRevolution, 7,5,6,4);
Stepper myStepper4(stepsPerRevolution, 11,9,10,8);

void spin(){
  //랜덤으로 4개중 하나 돌리기
    exe = (rand()%4)+1;
    Serial.print(exe);
    Serial.print("번 모터가 우측 방향으로 돌고 있습니다\n");

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
    case 3:
      for(int i=0; i<32; i++) {  
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
  delay(1000);
}

void setup() {
  Serial.begin(9600);
  myStepper1.setSpeed(500);
  myStepper2.setSpeed(500);
  myStepper3.setSpeed(500);
  myStepper4.setSpeed(500);
  pinMode(CI, INPUT);
  pinMode(CO, OUTPUT);
}

void loop() {
  int ox = 0;
  ox = digitalRead(CI);
  if(ox==1){
    Serial.println("값이 들어왔습니다");
    spin();
    digitalWrite(CO, 1);
    }
  else{
    Serial.println("값이 안 들어왔습니다");
    digitalWrite(CO, 0);
  }
  ox = 0;
}
