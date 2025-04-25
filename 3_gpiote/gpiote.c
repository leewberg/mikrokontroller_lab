#include "gpiote.h"

void gpioteInit(){
    //skal bruke 5 kanaler: 1 til BUTTON 1, resten til LED sub firsyningspinne. forsyningsspenning skal veksle hver gang oppgaven aktiveres. initverdi på PGIOTE-kanaler er opp til oss
    //lytter til button 1, settes i event modus, polaritet HI-to-lo
    GPIOTE->CONFIG[0] = (1<<0) | (13<<8) | (2<<16);

    //configurerer LED-pins
    GPIOTE->CONFIG[1] = (3 <<0) | (17<<8) | (3<<16);
    GPIOTE->CONFIG[2] = (3 <<0) | (18<<8) | (3<<16);
    GPIOTE->CONFIG[3] = (3 <<0) | (19<<8) | (3<<16);
    GPIOTE->CONFIG[4] = (3 <<0) | (20<<8) | (3<<16);
}