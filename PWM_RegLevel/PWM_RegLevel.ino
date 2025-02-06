void setup() {
  // put your setup code here, to run once:
  TCCR1B &= (~(1<<WGM13));
  TCCR1B |= (1<<WGM12);
  TCCR1A |= (1<<WGM10) | (1<<WGM11);       //enabling fast PWM 10 bit mode

  TCCR1A |= (1<<COM1A1);
  TCCR1A &= (~(1<<COM1A0));       //enable non-inverting pwm mode

  /*
  system clock 16MHz
  16\64 = 250KHz
  */

  TCCR1B |= (1<<CS10) | (1<<CS11);
  TCCR1B &= (~(1<<CS12));       //set prescaler of 64, freq of pwm 16MHz/64 = 250KHz

  DDRB |= (1<<DDB1);       //set pb1 as outout

}
unsigned int i = 0;
void loop() {
  // put your main code here, to run repeatedly:
  for (i=0; i<1024; i++) {
    OCR1A = i;       
    delay(5);
  }
  delay(2000);
  for (i=1023; i>0; i--) {
    OCR1A = i;
    delay(5);
  }
  delay(2000);
}
