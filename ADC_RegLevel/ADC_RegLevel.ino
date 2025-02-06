void setup() {
  // put your setup code here, to run once:

  /*******************PWM configuratio***************/
  TCCR1B &= (~(1<<WGM13));
  TCCR1B |= (1<<WGM12);
  TCCR1A |= (1<<WGM10) | (1<<WGM11);       //enabling fast PWM 10 bit mode

  TCCR1A |= (1<<COM1A1);
  TCCR1A &= (~(1<<COM1A0));       //enable non-inverting pwm mode

  /*
  system clock 16MHz
  16\64 = 250KHz
  */

  TCCR1B &= (~(1<<CS12));       //set prescaler of 64, freq of pwm 16MHz/64 ~ 250KHz
  TCCR1B |= (1<<CS11) | (1<<CS10);
 

  DDRB |= (1<<DDB1);       //set pb1 as outout

  /*******************ADC configuratio***************/

  sei();        //enable global interrupt 

  ADMUX |= (1<<REFS0);        //reference voltge to AVCC
  ADMUX &= (~(1<<REFS1));
  
  ADMUX &= (~(1<<ADLAR));           //right alignment of adc bits

  ADCSRA |= (1<<ADEN) | (1<<ADIE) | (1<<ADATE) | (1<<ADPS2);
  ADCSRA &= (~(1<<ADPS0)) & (~(1<<ADPS1));        //enable adc and set prescaler to 16. so the adc clock will be 16MHz/16 = 1MHz

  
  ADMUX &= (~(1<<MUX0)) & (~(1<<MUX1)) & (~(1<<MUX2)) & (~(1<<MUX3));         //enable adc 0 channel

  //Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println(ADC);
  //delay(1000);
  ADCSRA |= (1<<ADSC);          //start adc conversion
}

ISR(ADC_vect){
  OCR1A = ADC;		//0-1023
  delayMicroseconds(10);
}