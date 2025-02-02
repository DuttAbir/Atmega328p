unsigned int capture;

void setup() {
  // put your setup code here, to run once:
  sei();        //enable global interrupt 

  TIMSK1 |= (1<<ICIE1);       //enable timer 1

  TCCR1A &= (~(1<<WGM10)) & (~(1<<WGM11));
  TCCR1B &= (~(1<<WGM12)) & (~(1<<WGM13));       //timer in normal mode

  TCCR1B |= (1<<CS10) | (1<<CS12);        //set prescaler of 1024
  TCCR1B &= (~(1<<CS11));

  TCNT1 = 0;        //set initial value of timer 1

  TCCR1B |= (1<<ICES1);       //capture on rising edge

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

}

ISR(TIMER1_CAPT_vect){
  capture = ICR1;       //capture input capture reg value
  Serial.print(capture);
  Serial.print("\n");
}
