//essa eh a merda de um oscilador, vulgo clock
void setup() {
  // put your setup code here, to run once:
  pinMode(10, OUTPUT);

}

void loop() {
  digitalWrite(10, HIGH);
  delay(2000);
  digitalWrite(10, LOW);
  delay(2000);
  // put your main code here, to run repeatedly:

}
