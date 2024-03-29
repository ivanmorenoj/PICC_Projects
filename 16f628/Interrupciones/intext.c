#include <16f628a.h>

#fuses INTRC//_IO
#fuses NOWDT
#fuses NOMCLR
#fuses NOPUT
#fuses NOLVP
#fuses NOPROTECT
#fuses NOCPD
#fuses NOBROWNOUT
#BYTE TRISA=0x85
#BYTE PORTA=0x05
#BYTE TRISB=0x86
#BYTE PORTB=0x06
#use delay(clock=4000000)

#int_ext
void atender_int_ext()
{
   porta=1;
   delay_ms(500);
   Porta=0;
   delay_ms(500);
}

void main()
{
   trisa=0b00000000;
   trisb=0b00000001;
   ext_int_edge(0,l_to_h);
   enable_interrupts(int_ext);
   enable_interrupts(global);
   while(true)
   {
      portb=0b11111110;
      delay_ms(200);
      portb=0;
      delay_ms(200);
   }
}
