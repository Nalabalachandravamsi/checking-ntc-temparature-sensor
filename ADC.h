void port_intialization();
void temp_sensor_intialization();
void result();
void delay1(char);



void port_intialization(){
  volatile char *dirf,*inf,*dirk,*outk;
  dirf=0x30;inf=0x29;outk=0x108;dirk=0x107;
  *dirf=0x00;*dirk=0xff;
}
void temp_sensor_intialization(){
  volatile char *ADMUX1 = 0x7c;
  volatile char *ADCSRB1 = 0x7b;
  volatile char *ADCSRA1 = 0x7a; 
  *ADMUX1 = 0X00;     // enable ADC0
  *ADCSRB1 = 0X00;   // making ADC in free running mode
  *ADCSRA1 = 0Xc7;   // enable ADC,start bit and prescaler=128
}
void result(){
  volatile char *ADCSRA1 = 0x7a;
  volatile char *outk=0x108;
  volatile char *DATA_REGISTER = 0x79;
  while((*ADCSRA1 & 0x40)){  // waitibg for start bit to become zero
    *outk = 0x01;
    delay1(2);
  }
  *outk=0x02;
}
void delay1(char num){
  volatile long i;
  while(num){
    for(i=0;i<80000;i++);
    num--;
  }
}
