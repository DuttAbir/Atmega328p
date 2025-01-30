void setup() {
  // put your setup code here, to run once:

  DDRB |= (1<<DDB5);    //PB5 as o/p

  SREG |= (1<<7); //gloabl interrupt enable, set 7th bit of SREG register

  EIMSK |= (1<<INT0) | (1<<INT1);   //enable external intrrupt int0 and int1 on EIMSK register

  EICRA |= (1<<ISC10) | (1<<ISC11) | (1<<ISC00) | (1<<ISC01);   //generate interrupt request on rising edge of both int1 and int0 

}

void loop() {
  // put your main code here, to run repeatedly:
  

}

//interrupt handler for int0
ISR(INT0_vect){
  PORTB |= (1<<PB5);
}

//interrupt handler for int1
ISR(INT1_vect){
  PORTB &= (~(1<<PB5));
}
