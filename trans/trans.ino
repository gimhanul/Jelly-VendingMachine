#define CN 6

int before = 0;

void setup() {
  pinMode(CN, INPUT);
}

void loop() {
  int ox = digitalRead(CN);
    
  if(before != ox) {
    before ^= 1;
  }
  delay(1000);
}
