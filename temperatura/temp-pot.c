#include <16F877.h>
#device adc=10
#fuses XT, NOWDT
#use delay(clock=4MHz)
#include <lcd_c.c>
#use standard_io(B)

int1 salida=0;
int16 valor_temp, valor_pot;
float conversion, conversion1;
   
void main (){
   port_b_pullups(TRUE);
   lcd_init();
   
   setup_adc(ADC_CLOCK_INTERNAL);
   setup_adc_ports(AN0_AN1_AN3);
   
   printf(lcd_putc, "WELCOME");
   delay_ms(500);
   
   while (true){
      
      if (input(PIN_B1) == 0) {
         salida++;
         printf(lcd_putc, "\f");
         delay_ms(300);
      }

   
      if (salida == 1) {
         set_adc_channel(0);
         delay_us(20);
         valor_temp = read_adc();
         conversion=((5.0 * valor_temp) / 1023.0)*100;
         
         lcd_gotoxy(1,1);
         printf(lcd_putc, "ADC = %4lu",valor_temp);
         printf(lcd_putc, "\nTEMP = %01.2g\337",conversion);
         
         delay_ms(100);
      }
      
      if (salida == 0) {
         set_adc_channel(1);
         delay_us(20);
         valor_pot = read_adc();
         conversion1=((1.5 * valor_pot) / 308.0);
         
         lcd_gotoxy(1,1);
         printf(lcd_putc, "ADC = %4lu",valor_pot);
         printf(lcd_putc, "\nPOT = %01.2gV",conversion1); 
         
         delay_ms(100);
      }
   }
}
