#include <16F877A.h>
#fuses XT,NOWDT
#use delay(clock=4 MHz)
#use rs232(baud=9600, xmit=pin_c6, rcv=pin_c7) // Siempre después del delay
#include <lcd_d.c>

#use standard_io(B) 
   
char estado, recibido;

#INT_RDA
void Interrupcion_RDA()
{
   estado = getc();
}

void main ()
{
   lcd_init();
   
   enable_interrupts(INT_RDA);
   enable_interrupts(GLOBAL);
   
   while (TRUE)
   {
      if (estado == 'I')
      {
         output_high(pin_b1);
      
      }
      if (estado == 'P')
      {
         output_low(pin_b0);
         output_low(pin_b1);
      }
      if (estado == 'D')
      {
         output_high(pin_b0);
      }
   }
}
