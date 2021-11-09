#define FIVE 6
#define ONE 7
int cntfive, cntone;

void setup() {
  pinMode(FIVE, INPUT);
  pinMode(ONE, INPUT);
  Serial.begin(9600);

}

void loop() {
  int five = digitalRead(FIVE);
  int one = digitalRead(ONE);
  if(one) {
    if(five) {
      Serial.println("오백원");
      delay(1000);
    }
    else  {
      Serial.println("백원");
      delay(500);
    }
  }
}
