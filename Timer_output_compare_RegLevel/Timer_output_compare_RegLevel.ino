void setup() {
  // put your setup code here, to run once:

  sei();        //enable global interrupt enable pin
  TIMSK1 |= (1<<OCIE1A);      //enable timer 1 in TIMSK1 reg

  TCCR1A &= (~(1<<WGM10)) & (~(1<<WGM11));        //normal operation mode
  TCCR1B &= (~(1<<WGM12)) & (~(1<<WGM13));

  TCCR1A |= (1<<COM1A0);        //toggle OC0A on comapre match
  TCCR1A &= (~(1<<COM1A1));

  TCCR1B |= (1<<CS12) | (1<<CS10);        //prescaler to 1024
  TCCR1B &= (~(1<<CS11));

  TCNT1 = 0;        //set intial value of timer 1

  /*
  System clock is 16MHz,
  Clock frequency 16000000/1024 = 15625Hz,
  Time for 1 tick is 1/15625 = 64us,
  For 1000ms(1sec) to elapse the count is 1000ms/64us = 15625
  */

  OCR1A = 15625;        //load period of the timer to the OC reg

  DDRB |= (1<<DDB1);      //congigure pb1 as output

}

void loop() {
  // put your main code here, to run repeatedly:

}

ISR(TIMER1_COMPA_vect){
  TCNT1 = 0;
  OCR1A = 15625;
}
