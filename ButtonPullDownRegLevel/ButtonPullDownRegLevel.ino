void setup() {
  // put your setup code here, to run once:
  DDRB |= (1<<DDB5);      //set pb5 as op
  DDRD &= ~(1<<DDD2);     //set pd2 as ip

}

void loop() {
  // put your main code here, to run repeatedly:
  if (PIND & (1<<PIND2)) {
    PORTB |= (1<<PB5);
  }
  else {
    PORTB &= ~(1<<PB5);
  }

}
