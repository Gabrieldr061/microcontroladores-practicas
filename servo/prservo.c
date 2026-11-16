#include <16F877.h>
#fuses XT, NOWDT
#use delay(clock=4MHz)
#use standard_io(B)

void mover_servo(int16 ancho) {
   output_high(PIN_E0);
   delay_us(ancho);
   output_low(PIN_E0);
   delay_us(20000 - ancho);
}

void main() {
   int i;

   while (true) {
      // 0 grados (aprox. 1 ms de pulso)
      for (i = 0; i < 50; i++) {
         mover_servo(2000); // 1 ms
      }
      delay_ms(1000);
      
      for (i = 0; i < 50; i++) {
         mover_servo(1000); // 1 ms
      }
      delay_ms(1000);
   }
}

