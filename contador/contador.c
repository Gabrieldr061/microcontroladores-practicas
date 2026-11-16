#include <16F877.H>
#fuses XT, NOWDT
#use delay (clock=4MHz)

#use standard_io(B) //declaramos los puertos como entradas y salidas.
#use standard_io(c)

void main (){
   int cont=0;
   port_b_pullups(true); //activamos los pullups del puerto B.
   
   while(true){ //ciclo infinito.
      
      if (input(pin_b0)==0){ //para identificar el estado de mi boton y para iniciar.
      
         for(cont=0;cont<16;cont++){ //ciclo para que se incremente el contador.
            output_c(cont); // le doy salida por todo el puerto C para los leds.
            delay_ms(500); //delay de medio segundo.
         }
         cont=0; //volvemos a hacer 0 la constante para que se pueda volver a repetir.
      }
   }
}


