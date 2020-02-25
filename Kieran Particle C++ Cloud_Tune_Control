/*
This program will play one of 2 tunes when called from the cloud.
Created by Kieran Bessert 02/18/2020
Last edited 02/18/2020
*/

const int melody1[]={1900,2550,2550,1900,1900,2550,2550,1900};    // notes in the tune 1
const int melody2[]={550,900,900,550,550,900,900,550};            // notes in the tune 2
const int noteDurations1[]={4,8,8,4,4,8,8,4};                      // note Length
const int noteDurations2[]={8,4,4,8,8,4,4,8};                      // note Length
const int BUZZER=D4;

void setup() {
    pinMode(BUZZER, OUTPUT);
    
    Particle.function("Play",tune_Function);
}

void loop() {
    
}

int tune_Function(String choice) {
    int mytune = choice.toInt();
    
    if (mytune == 0){
            for (int thisNote = 0; thisNote < 8; thisNote++) {      // ergodic all notes
            int noteDuration = 1000/noteDurations1[thisNote];       // calculate the note duration
            tone(BUZZER, melody1[thisNote], noteDuration);          // let speaker sonds
            int pauseBetweenNotes = noteDuration * 1.30;            // set a minimum time between notes
            delay(pauseBetweenNotes);                               // delay for the while
            noTone(BUZZER);                                         // stop the tone playing:
        }
        return 0;
    }
    else if (mytune == 1){
            for (int thisNote = 0; thisNote < 8; thisNote++) {      // ergodic all notes
            int noteDuration = 1000/noteDurations2[thisNote];       // calculate the note duration
            tone(BUZZER, melody2[thisNote], noteDuration);          // let speaker sonds
            int pauseBetweenNotes = noteDuration * 1.30;            // set a minimum time between notes
            delay(pauseBetweenNotes);                               // delay for the while
            noTone(BUZZER);                                         // stop the tone playing:
        }
        return 1;
    }
    else{
        return -1;
    }
}
