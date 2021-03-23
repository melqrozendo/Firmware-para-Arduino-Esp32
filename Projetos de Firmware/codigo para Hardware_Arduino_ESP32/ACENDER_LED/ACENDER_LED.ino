int led1=8;
void setup() {
 pinMode(8, OUTPUT);

}

void loop() {
  digitalWrite(led1,1);
  delay(100);
  digitalWrite(led1,0);
  delay(2000);

}
