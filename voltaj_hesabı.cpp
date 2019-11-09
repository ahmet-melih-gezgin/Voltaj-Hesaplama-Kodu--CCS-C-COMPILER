#include<16f877a.h>
#device ADC=8
#use delay(clock=4000000)

#fuses XT,NOWDT,NOPUT,NOLVP,NOCPD,NOPROTECT,NODEBUG,NOBROWNOUT,NOWRT

#use fast_io(b)
#use fast_io(a)

#define use_portb_lcd TRUE

#include <lcd.c>
#include "max6675.c"

unsigned long int deger;
float voltaj;
float akim;

void main()
{
 set_tris_a(0x20);
 set_tris_b(0x00);
 
 setup_adc(adc_clock_div_32);
 setup_adc_ports(ALL_ANALOG);
 lcd_init();

 while(true){
 
set_adc_channel(4);
delay_us(20);


deger=read_adc();
voltaj=deger/51.0*(11.85);
akim=voltaj/0.9090909091;
//printf(lcd_putc,"\f AHMET");
printf(lcd_putc,"\f Akim=%fmA ", akim);
printf(lcd_putc,"\n Voltaj=%fV ", voltaj);

delay_ms(100);
 }
 
 


}

