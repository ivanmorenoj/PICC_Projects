#include <16f628a.h>
#fuses INTRC_IO
#fuses NOWDT
#fuses NOMCLR
#fuses NOPUT
#fuses NOLVP
#fuses NOPROTECT
#fuses NOCPD
#fuses NOBROWNOUT
#use delay(clock=4M)
#BYTE TRISA=0x85
#BYTE PORTA=0x05
#BYTE TRISB=0x86
#BYTE PORTB=0x06

#use fast_io(b)
#use fast_io(a)

void main()
{
   set_tris_b(0);
   set_tris_a(255);
   output_b(0);
   int8 a;
   while(true)
   {
      for(a=0;a<16;a++)
      {
         output_b(a);
         delay_ms(100);
      }
   }
}
