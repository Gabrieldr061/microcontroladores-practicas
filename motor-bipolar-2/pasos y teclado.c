#include <16f877.h>
#fuses XT, NOWDT  
#use delay (clock = 4MHz)

#include <lcd_c.c>
#use standard_io(b)
#use standard_io(d)
#use standard_io(c)
#include <kbd_d 4x4.C>
#include <Lee_Num16b.C>

void main (){
    lcd_init();
    kbd_init();
    port_b_pullups(true);
    signed int x=7;
    int16 grados, Npasos, Cpasos=0;
    int pasos[8] = {0b00001001, 0b00001000, 0b00001010, 0b00000010, 0b00000110, 0b00000100, 0b00000101, 0b00000001};
    
    while(true){
      do{
       printf(lcd_putc, "\fGRADOS 0-360: \n");
       grados = Lee_Num16b();
      if (grados<0 || grados>360){
         printf(lcd_putc, "\f");
         printf(lcd_putc, "GRADOS \nNO VALIDOS");
         delay_ms(1000);
      }
      }while(grados<0 || grados>360);
       
     Npasos=grados/0.9;
     
     if (input(pin_B7)==1){
      printf(lcd_putc, "\f");
      printf(lcd_putc, "POSICIONANDO:...");
      for(Cpasos=0; Cpasos<Npasos; Cpasos++){
         x++;
            if (x == 8){
               x=0;
            }
         output_b(pasos[x]);
            delay_ms(50);
         }
         printf(lcd_putc, "\f");
         printf(lcd_putc, "PASOS:%lu", Npasos);
         printf(lcd_putc, "\nGRADOS: %3.1g", ((float)Npasos*0.9));
         delay_ms(2000);
      }
     
      if (input(pin_b7)==0){
         printf(lcd_putc, "\f");
         printf(lcd_putc, "POSICIONANDO:...");
         for(Cpasos=0; Cpasos<Npasos; Cpasos++){
            x--;
            if (x==-1){
               x=7;
            }
         output_b(pasos[x]);
            delay_ms(50);
         }
         printf(lcd_putc, "\f");
         printf(lcd_putc, "PASOS:%lu", Npasos);
         printf(lcd_putc, "\nGRADOS: %3.1g", ((float)Npasos*0.9));
         delay_ms(2000);
      }
   }
}
