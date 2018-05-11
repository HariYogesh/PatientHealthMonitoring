/////////////////////////////////////////////////////////////////////////////////////////////////////
///  Project Name : PatientHealthMonitoring
//
//  Target Board : atmega32
//
//  Date Created : 06-Apr-18 11:09:28 AM
//
//  Libraries Included : -->wifiadvanced 
/////////////////////////////////////////////////////////////////////////////////////////////////////

#define cloudid "Hari1311"
#define INTERNET WIFI

#include<avr/io.h>
#include<util/delay.h>

#include "adc.h"
#include "serial.h"
#include "clobous.h"
#include "lcd.h"


int main()
{
	 lcd_init();
	 adc_init();	//initializing the ADC
	 lcd_string("welcome");
     serial_init(9600);
     serial_select(2);
     wifi_init();
     wifi_connect("JioFi2_17F9CF","mnms7zi2si");
	 _delay_ms(1000);
	 lcd_clear();
	 lcd_string("wifi_contd");
	 _delay_ms(1000);
	
	int a;
	while (1)
	{
		lcd_clear();
	    a = adc_read(0);  
		a=a*0.488;
		lcd_string("temp=");
		lcd_gotoxy(6,0);
		lcd_num(a);
		lcd_string(" *c");
		data_update("temp",a);
		

		// write your code


	}

}
