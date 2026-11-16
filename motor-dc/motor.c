#include <16f877.h>
#fuses XT,NOWDT
#use delay (clock = 4MHz)

#use standard_io(b)

void main (){
    port_b_pullups(true);                                                       //activa los pullups del puerto b.
    output_low(pin_B3);  
    output_low(pin_B4);  
    int estado = 0;                                                             //variable para el cambio giro.

    do{ 
        if (input(pin_B0) == 0 && estado != 1){                                 //(!= 1 "significa para que no es igual a")
            output_low(pin_B3);
            output_high(pin_B4);
            estado = -1;                                                         
        }

        if (input(pin_B1) == 0){
            output_low(pin_B3);
            output_low(pin_B4);
            estado = 0;  
        }

        if (input(pin_B2) == 0 && estado != -1){
            output_high(pin_B3);
            output_low(pin_B4);
            estado = 1;  
        }
    }while (TRUE);
}

