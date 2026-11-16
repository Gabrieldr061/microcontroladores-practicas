#include <16f877.h>
#fuses XT, NOWDT  
#use delay (clock = 4MHz)

#include <lcd_d.c>
#use standard_io(b)

void main (){

    lcd_init();
    port_b_pullups(true);
    signed int x=0;
    int bandera=0;
    signed int16 Npasos=0;
    int pasos[8] = {1, 5, 4, 12, 8, 10, 2, 3};
    printf(lcd_putc, "PRESIONE \nIZQ. O DER.");
    inicio:
    while(true){
         
      if (input(pin_b6)==0 && bandera != -1){
         x=7;
         bandera = 1;
         printf(lcd_putc, "\f");
         do{
            x--;
            Npasos--;
            if (Npasos==0)
            Npasos=400;
            if (x==-1)
               x=7;
            output_b(pasos[x]);
            delay_ms(50);
               printf(lcd_putc, "\f");
               printf(lcd_putc, "GIRANDO IZQ.");
               printf(lcd_putc, "\nx= %d", x);
         }while(input(pin_B7) == 1 );
         
         if(input(pin_B7) == 0){
         bandera = 0;
         
      }
   }
   
   if (input(pin_b5)==0 && bandera != 1){
         x=0;
         bandera = -1;
         printf(lcd_putc, "\f");
         do{
            x++;
            Npasos++;
            if (Npasos==400)
            Npasos=0;
            if (x==8)
               x=0;
            output_b(pasos[x]);
            delay_ms(50);
               printf(lcd_putc, "\f");
               printf(lcd_putc, "GIRANDO IZQ.");
               printf(lcd_putc, "\nx= %d", x);
         }while(input(pin_B7) == 1 );
         
         if(input(pin_B7) == 0){
         bandera = 0;
         
      }
   }
   if (input(pin_b7)==0){
      bandera=0;
      printf(lcd_putc, "\f");
      printf(lcd_putc, "MOTOR EN\nPARO");
      delay_ms(1000);
      printf(lcd_putc, "\fPRESIONE \nIZQ. O DER.");
   }
}
}
