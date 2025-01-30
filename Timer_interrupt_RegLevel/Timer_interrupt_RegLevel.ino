void setup() {
  // put your setup code here, to run once:

  DDRB |= (1<<DDB5);      //set pb5 as o/p

  sei();      //global interrupt enable

  TIMSK1 |= (1<<TOIE1);    //enable timer/interrupt 1 in te TIMSK register


  //to use the timer in normal mode WGM13,12,11,10 needs to be reset
  TCCR1A &= (~(1<<WGM10)) & (~(1<<WGM11));   //wgm10 & 11 is available in TCCR1A register

  TCCR1B &= (~(1<<WGM12)) & (~(1<<WGM13));   //wgm12 & 13 is available in TCCR1B register

  //to set the prescaler for timer CS12,11,10 available on TCCR1B are used
  TCCR1B |= (1<<CS12) | (1<<CS10);      //to set the prescaler to 1024 CS10 & 12 is set and CS11 is reset
  TCCR1B &= (~(1<<CS11));

  /*
  The system clock is 16 MHz
  The clock frequency becomes 16000000/1024 = 15625 Hz
  Time for each Tick is 1/15625 = 0.00064 sec = 64 us
  For 1000 us(1 sec) to elapse the count is 1000/64 = 15625
  65535 - 15625 = 49910 will be period value for a 1 sec interrupt period
  */

  TCNT1 = 49910;      //period value for timer1 is loaded to TCNT1 reg
}

void loop() {
  // put your main code here, to run repeatedly:

}


ISR(TIMER1_OVF_vect){
  PORTB ^= (1<<PB5);    // toggle pb5
  TCNT1 = 49910;      //reset timer 1 
}

