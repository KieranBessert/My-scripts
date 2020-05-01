// Code to make Particle device read the ambient tempurature in Farenheit.
// Then display the reading in the cloud and on LED display.
// Coded by Kieran A Bessert 2/27/2020
// Last edited 3/3/2020

#include <Grove_Temperature_And_Humidity_Sensor.h>  // This #include statement was automatically added by the Particle IDE.
#define DHTPIN 	A0                                  // set pin
DHT dht(DHTPIN);

#include <Grove_4Digit_Display.h>                   // This #include statement was automatically added by the Particle IDE.
#define CLK D4                                      //pins definitions for TM1637 and can be changed to other ports
#define DIO D5
TM1637 tm1637(CLK,DIO);

int f;

void setup() {
	dht.begin();
	
    tm1637.init();
    tm1637.set(BRIGHT_TYPICAL);                     //BRIGHT_TYPICAL = 2,BRIGHT_DARKEST = 0,BRIGHTEST = 7;
    tm1637.point(POINT_ON);
	
	Particle.variable("Tempurature", f);
}

void loop() {
	delay(2000);                                    // Wait a few seconds between measurements.
                                                    // The sensor reads data slowly.
	f = dht.getTempFarenheit();                     //Read Temp in Farenheit
	dispNum(f);
}

void dispNum(int num)                            //display a integer value less then 1000
{
    tm1637.display(0, (f / 1000));
    tm1637.display(1, ((f % 1000) / 100));
    tm1637.display(2, ((f % 100) / 10));
    tm1637.display(3, (f % 10));
    delay(2000);
}
