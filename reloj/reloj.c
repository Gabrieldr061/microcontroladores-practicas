#include <16F877.h>
#fuses XT, NOWDT
#use delay(clock=4MHz)

#include <lcd_c.c>
#include <ds1302 en A.c>

int segundos,minutos,horas,Nu_dia,mes,anio,No_dia;
char N_mes[4], N_dia[4];

void dia (int No_dia){
if (No_dia == 1) N_dia = "DOM";
if (No_dia == 2) N_dia = "LUN";
if (No_dia == 3) N_dia = "MAR";
if (No_dia == 4) N_dia = "MIE";
if (No_dia == 5) N_dia = "JUE";
if (No_dia == 6) N_dia = "VIE";
if (No_dia == 7) N_dia = "SAB";
}

void meses (int mes){
   if (mes == 1) N_mes = "ENE";
   if (mes == 2) N_mes = "FEB";
   if (mes == 3) N_mes = "MAR";
   if (mes == 4) N_mes = "ABR";
   if (mes == 5) N_mes = "MAY";
   if (mes == 6) N_mes = "JUN";
   if (mes == 7) N_mes = "JUL";
   if (mes == 8) N_mes = "AGO";
   if (mes == 9) N_mes = "SEP";
   if (mes == 10) N_mes = "OCT";
   if (mes == 11) N_mes = "NOV";
   if (mes == 12) N_mes = "DIC";
}

#INT_TIMER1
void Interrupciones_Timer1 (){
   set_timer1(3036);
   rtc_get_time(horas,minutos,segundos);
   lcd_gotoxy(1,1);
   printf(lcd_putc, "%02u:%02u:%02u",horas,minutos,segundos);
}

void main (){
   lcd_init();
   rtc_init();
   
   setup_timer_1(T1_INTERNAL | T1_DIV_BY_8);
   enable_interrupts(INT_TIMER1); 
   enable_interrupts(GLOBAL);
   set_timer1(3036);
   
   rtc_get_time(horas,minutos,segundos);
   rtc_get_date(Nu_dia,mes,anio,No_dia);
   
   dia(No_dia);
   meses(mes);
   lcd_gotoxy(1,1);
   printf(lcd_putc, "%02u:%02u:%02u",horas,minutos,segundos);
   lcd_gotoxy(1,2);
   printf(lcd_putc, "%s/%02u/%s/%lu",N_dia,Nu_dia,N_mes,(int16)anio+2000);
   
   while(true){
      delay_ms(2000);
   }
}
