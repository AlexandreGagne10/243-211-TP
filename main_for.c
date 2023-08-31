#include "mcc_generated_files/mcc.h"

#define DEL1 IO_RA0_LAT
#define DEL2 IO_RA1_LAT
#define DEL3 IO_RA2_LAT

int compteur1 = 0;
int compteur2 = 0;
int compteur3 = 0;

void main(void) {
    SYSTEM_Initialize();
    // Allumer toutes les LED au départ
    DEL1 = 1;
    DEL2 = 1;
    DEL3 = 1;

    int compteur1 = 0, compteur2 = 0, compteur3 = 0;

    while (1) { // Boucle infinie
        compteur1++;
        compteur2++;
        compteur3++;

        // Pour DEL1 (1Hz)
        for (; compteur1 >= 500; compteur1 = 0) {
            DEL3 = !DEL3;
        }

        // Pour DEL2 (2Hz)
        for (; compteur2 >= 250; compteur2 = 0) {
            DEL2 = !DEL2;
        }

        // Pour DEL3 (4Hz)
        for (; compteur3 >= 125; compteur3 = 0) {
            DEL1 = !DEL1;
        }
        __delay_ms(1);  // Délai de 1ms pour le comptage
    }
}