void setup() {
  // put your setup code here, to run once:
  DDRB |= (1<<DDB5);

}

void loop() {
  // put your main code here, to run repeatedly:
  PORTB |= (1<<PB5);
  delay(1000);
  PORTB &= ~(1<<PB5);
  delay(1000);

}
