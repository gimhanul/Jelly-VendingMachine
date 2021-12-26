#define FIVE 6
int cntfive;
int done=0;

void setup() {
  pinMode(FIVE, INPUT);
  Serial.begin(9600);

}

void loop() {
  int five = digitalRead(FIVE);
  if(five) {
     Serial.println("오백원");
     done+=500;
     delay(1000);
  }
}
