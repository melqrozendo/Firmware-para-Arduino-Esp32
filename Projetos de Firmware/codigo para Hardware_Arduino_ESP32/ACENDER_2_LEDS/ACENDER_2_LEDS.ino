int led1=8;
int led2=7;
void setup() {
 pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);

}

void loop() {
  digitalWrite(led1,1);
  delay(100);
  digitalWrite(led1,0);
  delay(100);
  digitalWrite(led2,1);
  delay(100);
  digitalWrite(led2,0);
  delay(100);

}
