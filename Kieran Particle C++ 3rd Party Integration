/*
This program will Play a tune when the function is called from 3rd party software.
It will also log when the temperature exceeds 80*F to a Facebook post
Created by Kieran Bessert 03/03/2020
Last edited 03/03/2020
*/
// This #include statement was automatically added by the Particle IDE.
#include <Grove_4Digit_Display.h>
#define CLK D4                                      //pins definitions for TM1637 and can be changed to other ports
#define DIO D5
TM1637 tm1637(CLK,DIO);

// This #include statement was automatically added by the Particle IDE.
#include <Grove_Temperature_And_Humidity_Sensor.h>
#define DHTPIN 	A0                                  // set pin
DHT dht(DHTPIN);
int f;

const int BUZZER=D2;
const int melody[]={1900,2550,2550,1900,1900,2550,2550,1900};    // notes in the tune
const int noteDurations[]={4,8,8,4,4,8,8,4};                      // note Length

void setup() {
    pinMode(BUZZER, OUTPUT);
    Particle.function("notification", tune);
    
    dht.begin();
	
    tm1637.init();
    tm1637.set(BRIGHTEST);                     //BRIGHT_TYPICAL = 2,BRIGHT_DARKEST = 0,BRIGHTEST = 7;
    tm1637.point(POINT_ON);
	
	Particle.variable("Tempurature", f);
}

void loop() {
	delay(2500);                                    // Wait a few seconds between measurements.
                                                    // The sensor reads data slowly.
	f = dht.getTempFarenheit();                     //Read Temp in Farenheit
	dispNum(f);
}

int tune (String play)
{
    for (int thisNote = 0; thisNote < 8; thisNote++) {          // ergodic all notes
            int noteDuration = 1000/noteDurations[thisNote];    // calculate the note duration
            tone(BUZZER, melody[thisNote], noteDuration);       // let speaker sonds
            int pauseBetweenNotes = noteDuration * 1.30;        // set a minimum time between notes
            delay(pauseBetweenNotes);                           // delay for the while
            noTone(BUZZER);                                     // stop the tone playing:
            }
    return 0;
}

void dispNum(int num)                            //display a integer value less then 1000
{
    tm1637.display(0, (f / 1000));
    tm1637.display(1, ((f % 1000) / 100));
    tm1637.display(2, ((f % 100) / 10));
    tm1637.display(3, (f % 10));
    delay(2500);
}
