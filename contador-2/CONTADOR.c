#include <16f877.h>
#fuses XT, NOWDT
#use delay (clock = 4 MHz)

#include <lcd_c.c>                                                              //se agrego la libreria para LCD.

#use standard_io(b) 

void main (){
   port_b_pullups(true);
   int16 cuenta;
   lcd_init();                                                                  //inicializamos el lcd.
   printf(lcd_putc, "HOLA");                                                    //escribimos lo que queremos en el lcd.
   printf(lcd_putc, "\nPRECIONAR BOTON");
   
   while (true){
   
      if (input(pin_b0) == 0){
         
         for(cuenta=0;cuenta<16;cuenta++){
         printf(lcd_putc, "\fPASOS:%lu", cuenta);                               //imprimimos los resultados en el lcd.
         delay_ms(500);
         }
      }
   }
}
