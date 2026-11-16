#include <16f877.h>
#fuses XT,NOWDT
#use delay (clock = 4MHz)

#use standard_io(B)

void main (){
   port_b_pullups(true);
   int16 Npasos=0;
   int x=0;
   int pasos[8] = {0b00001001, 0b00001000, 0b00001010, 0b00000010, 0b00000110, 0b00000100, 0b00000101, 0b00000001};
   
   while(true){
      if (input(pin_b0)==0){
         for (Npasos=0; Npasos<400; Npasos++){
            output_C(pasos[x]);
            delay_ms(50);
            
            x++;
            if (x==8)
            x=0;
         }
      }
   }
}
