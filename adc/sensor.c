#include <16F877.h>
#device adc=10
#fuses XT, NOWDT
#use delay(clock=4MHz)
#include <lcd_c.c>

void main (){
   lcd_init();
   int16 valor_leido;
   float conversion;
   
   setup_adc(ADC_CLOCK_INTERNAL);
   setup_adc_ports(AN0);
   
   while (true){
      set_adc_channel(0);
      delay_us(20);
      valor_leido = read_adc();
      conversion=((5 * valor_leido) / 1023.0)*100;
      
      lcd_gotoxy(1,1);
      printf(lcd_putc, "ADC = %4lu",valor_leido);
      printf(lcd_putc, "\nTEMP = %01.2g°",conversion);
      
      delay_ms(100);
   }
}
