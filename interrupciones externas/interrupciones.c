#include <16f877.h>
#fuses XT,NOWDT
#Use delay (clock=4MHz)

#include <lcd_D.c>
#use standard_io(B)

int t; |
int1 x=0; 


#INT_TIMER0 

void Rutina_para_el_Temporizador_0()
{
      if(x==0)
      {
      t=0; 
      printf(lcd_putc,"\nGirando");
      lcd_gotoxy(14,2);
      output_high(PIN_B1); 
      set_timer0(254);
      }
      
      if(x==1)
      {
      printf(lcd_putc,"\nParo   ");
      output_toggle(PIN_B1);
      set_timer0(255); 
   
      }
      x++; 

}

void main ()
{
   lcd_init(); 
   output_Low(PIN_B1);
   setup_timer_0(RTCC_EXT_L_TO_H | RTCC_DIV_1); 
   
   enable_interrupts(INT_TIMER0); 
   enable_interrupts(GLOBAL); 
   set_timer0(255); 
   
   printf(lcd_putc,"\f1:Girar  2:Parar");
   
   while(true)
   {
      if(x == 1)
      {
         printf(lcd_putc,"%2us",t);
         delay_ms(1000);
         t++;
         lcd_gotoxy(14,2); 

      }
   }
}
