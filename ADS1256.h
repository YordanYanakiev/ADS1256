/*
 Name:		ADS1256.h
 Created:	11/21/2018 5:24:56 PM
 Author:	Yordan
 Editor:	http://www.visualmicro.com
*/

#ifndef _ADS1256_h
#define _ADS1256_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


#include "SPI.h"
#include "esp32-hal-gpio.h"

class ADS1256
{
	public:
		uint8_t pinCS;
		uint8_t pinRDY;
		uint8_t pinRESET;
		uint32_t speedSPI;
		
		unsigned long adcValues[ 8 ];
		unsigned long adc_Raws[ 8 ] = { 0,0,0,0,0,0,0,0 };
		byte mux[ 8 ] = { 0x08,0x18,0x28,0x38,0x48,0x58,0x68,0x78 };
		
		ADS1256();

		void init( uint8_t _pinCS, uint8_t _pinRDY, uint8_t _pinRESET, uint32_t _speedSPI );
		void readInputToAdcValuesArray();

		void readInputPEAKSToAdcValuesArray( int repeats );


	private:
	
};


#endif

