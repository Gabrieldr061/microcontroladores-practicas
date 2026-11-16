#include <16F877.h>
#fuses XT, NOWDT
#use delay(clock=4MHz)

#use standard_io(B)

int cargatimer0;

#INT_TIMER0
void Rutina_para_el_Temporizador_0(){
   set_timer0(cargatimer0); 
   output_toggle(PIN_B0);
}

void main (){
   port_b_pullups(TRUE);
   setup_timer_0(RTCC_INTERNAL | RTCC_DIV_256); 
   
   enable_interrupts(INT_TIMER0); 
   enable_interrupts(GLOBAL);
   
   while (true){
      if(input(pin_b4)==0){
         cargatimer0=190;
   
      }
      
      if(input(pin_b5)==0){
         cargatimer0=228;
      }
      
      if(input(pin_b6)==0){
         cargatimer0=247;
      }
   }
}
