#include <16f628a.h>

#fuses INTRC_IO
#fuses NOWDT
#fuses NOMCLR
#fuses PUT
#fuses NOLVP
#fuses NOPROTECT
#fuses NOCPD
#fuses BROWNOUT
#BYTE TRISA=0x85
#BYTE PORTA=0x05
#BYTE TRISB=0x86
#BYTE PORTB=0x06
#use delay(clock=4M)

void main()
{
   Trisa=0;
   Trisb=0;
   Portb=0;
   setup_timer_0(RTCC_INTERNAL | T0_DIV_256);
   int time=0,leds=0;
   while(true)
   {
      set_timer0(0);
      while(get_timer0()<255);
      time++;
      if (time==15)
      {
         leds++;      
         Portb=leds;
         time=0;
      }
   }
}
