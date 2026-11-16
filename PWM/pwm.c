#include <16F877.h>
#fuses XT, NOWDT
#use delay(clock=4MHz)

#use standard_io(B)

int valor_T0 = 26;
int16 ancho = 0;

#INT_TIMER0

void Rutina_para_el_Temporizador_0(){
   set_timer0(valor_T0);
   
   if(ancho > 0){
      output_high(pin_b7);
      delay_us(ancho);
      output_low(pin_b7);
   }
}

void main (){
   port_b_pullups(TRUE);
   setup_timer_0(RTCC_INTERNAL | RTCC_DIV_2); 
   
   enable_interrupts(GLOBAL);
   enable_interrupts(INT_TIMER0); 
   set_timer0(valor_T0);
   output_low(pin_b7);
   
   while (true){
   
      if ((input(pin_b0)==0) && (ancho<=450)){
         ancho+=10;
         delay_ms(20);
      }
      
      if ((input(pin_b2)==0) && (ancho >= 10)){
         ancho-=10;
         delay_ms(20);
      }
   }
}
