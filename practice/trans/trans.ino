#define CN 6

int before = 0;

void setup() {
  pinMode(CN, INPUT);
}

void loop() {
  int ox = digitalRead(CN);
    
  if(before != ox) {
    if(ox==1) {
      //여기서 모터 돌리기
    }
    before ^= 1;
  }
  delay(1000);
}
