#include <16f628a.h>

#fuses INTRC_IO
#fuses NOWDT
#fuses NOMCLR
#fuses PUT
#fuses NOLVP
#fuses NOPROTECT
#fuses NOCPD
#fuses NOBROWNOUT
/*#BYTE TRISA=0x85
#BYTE PORTA=0x05
#BYTE TRISB=0x86
#BYTE PORTB=0x06*/
#use fast_io(b)
#use delay(clock=4M)

void pwm_servo(int pin,int periodo,long alto);
void main()
{
   set_tris_b(0);
   output_low(48);
   long pwm=100;
   while(true)
   {
      pwm_servo(pin_b0,20,pwm);
      pwm+=100;      
      if(pwm>=3000)
         {pwm=100;}
   }
}
void pwm_servo(int pin,int periodo,long alto)
{
  //pwm a 50hz ancho de pulso 20ms
  long bajo;
  int a;
  bajo=20000-alto;
  for(a=0;a<periodo;a++)
  {
     output_high(pin);
     delay_us(alto);
     output_low(pin);
     delay_us(bajo);
  }
}
