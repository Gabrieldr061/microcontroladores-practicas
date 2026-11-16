#include <16F877.h>
#fuses XT, NOWDT
#use delay(clock=4MHz)

#include <lcd_c.c>

#INT_RB
void interrupciones_RB (){

   if (input(pin_b4)==0){
      printf(lcd_putc,"\n!!PARO!!");
      output_toggle(pin_b0);
      while(input(pin_b4)==0){}
   }
   
   if (input(pin_b5)==0){
      output_toggle(pin_b0);
      printf(lcd_putc,"\n!!PARO!!");
      delay_ms(1000);
   }
}

void main (){

   enable_interrupts(GLOBAL);
   port_b_pullups(true);
   lcd_init();
   int16 contador=0;
   int i=0;
   printf(lcd_putc,"\fCONTADOR \n0 - 15");
   
   while(true){

      if (input(pin_b0)==0){
         enable_interrupts(INT_RB);
         for(i=0;i<15;i++){
            contador++;
            printf(lcd_putc,"\fCUENTA:%lu",contador);
            delay_ms(500);
         }
         contador=0;
         disable_interrupts(INT_RB);
         printf(lcd_putc,"\fCONTADOR \n0 - 15");
      }
   }
}

