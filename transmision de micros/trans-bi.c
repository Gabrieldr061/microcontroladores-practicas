#include <16F877A.h>
#fuses XT,NOWDT
#use delay(clock=4 MHz)
#use rs232(baud=9600, xmit=pin_c6, rcv=pin_c7) // Siempre después del delay
#include <lcd_d.c>

#use standard_io(B) 

char recibido = 'N';

#INT_RDA
void Interrupcion_RDA()
{
   recibido = getc();
}

void main()
{
   char estado;
   
   lcd_init();
   port_b_pullups(TRUE);
   
   enable_interrupts(INT_RDA);
   enable_interrupts(GLOBAL);
   
   printf(lcd_putc,"\fParo");
   estado = 'P';
   putc(estado);

   while (TRUE)
   {
      if ((input(PIN_B0)== 0) && (estado == 'P'))
      {
         printf(lcd_putc,"\fIzquierda");
         estado = 'I';
         putc(estado);
         printf(lcd_putc,"\nEnviado...");
         delay_ms(200);
      }
      
      if ((input(PIN_B1)== 0) && (estado != 'P'))
      {
         printf(lcd_putc,"\fParo");
         estado = 'P';
         putc(estado);
         printf(lcd_putc,"\nEnviado...");
         delay_ms(200);
      }
      
      if ((input(PIN_B2)== 0) && (estado == 'P'))
      {
         printf(lcd_putc,"\fDerecha");
         estado = 'D';
         putc(estado);
         printf(lcd_putc,"\nEnviado...");
         delay_ms(200);
      }
      
      if (recibido == 'S')
      {
         printf(lcd_putc,"\fRecibido");
         delay_ms(1000);
         printf(lcd_putc,"\n        ");
         recibido = 'N';
      }
   }
}
