#include <16F877.h>
#fuses XT, NOWDT
#use delay(clock=4MHz)

#use standard_io(B)

#include <lcd_d.c>

int16 carga_T1=3016;
int cuenta;

#INT_TIMER1
void Interrupciones_Timer1 (){
   output_toggle(PIN_B1);
   set_timer1(carga_T1);
   cuenta++;
   printf(lcd_putc, "\fTiempo: %3.1gs",(float)cuenta*0.5);
}

void main (){
   output_high(PIN_B1);
   setup_timer_1(T1_INTERNAL | T1_DIV_BY_8);
   
   lcd_init();
   enable_interrupts(INT_TIMER1); 
   enable_interrupts(GLOBAL);
   set_timer1(carga_T1);
   printf(lcd_putc, "\fTiempo: %3.1gs",(float)cuenta*0.5);
   
   while (true);
}
