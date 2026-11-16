#include <16F877.h>
#fuses XT, NOWDT
#use delay(clock=4MHz)

#include <lcd_c.c>
#include <kbd_d 4x4.c>
#include <Lee_Num16b.c>

#use standard_io(B)

int8 pos,valor,seg;

void main (){
   port_b_pullups(TRUE);
   lcd_init();
   kbd_init();
   output_low(PIN_B1);
   
   printf(lcd_putc, "\fMEMORIA\nEEPROM");
   delay_ms(500);
   printf(lcd_putc, "\fB1:ESCRIBIR\nB2:LEER");
   delay_ms(500);
   
   while (true){
   
      if (input(PIN_B3)==0){   
         printf(lcd_putc, "\fTECLEA 3\nTIEMPOS:");
         delay_ms(500);
         for(pos=0;pos<3;pos++){
            do {
               printf(lcd_putc, "\fTIEMPO: %u\n",pos+1);
               valor = lee_num16b();
               delay_ms(100);
               if (valor < 1 || valor > 10) {
                   printf(lcd_putc, "\fFUERA DE RANGO");
                   delay_ms(1000);
               }
            } while (valor < 1 || valor > 10);
            
            write_eeprom(pos,valor);
        }
         printf(lcd_putc, "\fFIN DE LA\nLECTURA");
         delay_ms(1000);
         printf(lcd_putc, "\fB1:ESCRIBIR\nB2:LEER");
      }
      
      if (input(PIN_B4)==0){
         for(pos=0;pos<3;pos++){
            valor=read_eeprom(pos);
            printf(lcd_putc, "\fTIEMPO: %u: %us",pos+1,valor);
            
            output_high(PIN_B1);
            for(seg=0;seg<valor;seg++){
            printf(lcd_putc, "\nSEGUNDOS: %u",seg+1);
            delay_ms(1000);
            }
            output_low(PIN_B1);
            
            printf(lcd_putc, "\fFIN DEL\nTIEMPO %u",pos+1);
            printf(lcd_putc, "\nPAUSA 2 SEG.");
            delay_ms(1000);
         }
         printf(lcd_putc, "\fFIN DE LA\nLECTURA");
         delay_ms(500);
         printf(lcd_putc, "\fB1:ESCRIBIR\nB2:LEER");
      }
   }
}
