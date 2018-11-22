/*
 Name:		Test1.ino
 Created:	11/21/2018 5:40:57 PM
 Author:	Yordan
*/

#include "ADS1256.h"

ADS1256 ads;

// the setup function runs once when you press reset or power the board
void setup() 
{
	Serial.begin( 115200 );
	ads.init( 5, 14, 25, 1700000 );
	Serial.println( ads.speedSPI );
}

// the loop function runs over and over again until power down or reset
void loop() 
{
	

	ads.readInputToAdcValuesArray();

	for( int i = 0; i <= 7; i++ )
	{
		Serial.print( ads.adcValues[ i ] );   // Raw ADC integer value +/- 23 bits
		Serial.print( "      " );
	}
	Serial.println();

	delay( 500 );
}
