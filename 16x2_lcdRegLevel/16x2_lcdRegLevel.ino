void lcd_data(unsigned char data){
  PORTD = data;
  PORTB |= (1<<PB0);        // RS = 1
  PORTB &= (~(1<<PB1));     // RW = 0
  PORTB |= (1<<PB2);        // EN = 1
  _delay_ms(10);            // wait 10 ms
  PORTB &= (~(1<<PB2));     // EN = 0
}

void lcd_cmd(unsigned char cmd){
  PORTD = cmd;
  PORTB &= (~(1<<PB0));     // RS = 0
  PORTB &= (~(1<<PB1));     // RW = 0
  PORTB |= (1<<PB2);        // EN = 1
  _delay_ms(10);            // wait 10 ms
  PORTB &= (~(1<<PB2));     // EN = 0
}

void lcd_string(const unsigned char *str, unsigned char length){
  char i = 0;
  for (i=0; i<length; i++) {
    lcd_data(str[i]);
  }
}

void lcd_init(){
  lcd_cmd(0x38);          // sets LCD in 16x2 format
  lcd_cmd(0x06);          // autoincrement the cursor
  lcd_cmd(0x0C);          // dsiplay on, cursor off
  lcd_cmd(0x01);          // clear screen
}




void setup() {
  // put your setup code here, to run once:
  DDRD = 0xFF;
  DDRB |= (1<<DDB0) | (1<<DDB1) | (1<<DDB2);
  lcd_init();
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd_cmd(0x80);
  lcd_string("EMBEDDED", 8);
  lcd_cmd(0xC0);
  lcd_string("SYSTEM", 6);
}
