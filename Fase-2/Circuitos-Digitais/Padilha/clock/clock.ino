//essa eh a merda de um oscilador, vulgo clock
void setup() {
  // put your setup code here, to run once:
  pinMode(11, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(7, INPUT);

}

void loop() {
  digitalWrite(11, HIGH);
  delay(2000);
  digitalWrite(11, LOW);
  delay(2000);
  
  digitalWrite(8, HIGH);
  delay(1000);
  digitalWrite(8, LOW);
  delay(1000);
  
  digitalWrite(2, HIGH);
  delay(500);
  digitalWrite(10, LOW);
  delay(500);

}
