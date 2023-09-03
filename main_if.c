#include "mcc_generated_files/mcc.h"  // Inclure les fichiers générés par MCC

// Définition des macros pour les LEDs (DEL en français)
#define DEL1 IO_RA0_LAT  // Définition pour la LED 1
#define DEL2 IO_RA1_LAT  // Définition pour la LED 2
#define DEL3 IO_RA2_LAT  // Définition pour la LED 3

// Initialisation des compteurs pour chaque LED
int compteur1 = 0;
int compteur2 = 0;
int compteur3 = 0;

void main(void) {
    SYSTEM_Initialize();  // Initialisation du système

    // Allumer toutes les LEDs au départ
    DEL1 = 1;
    DEL2 = 1;
    DEL3 = 1;

    // Boucle infinie
    while (1) {
        // Si le compteur pour DEL3 atteint 500ms, basculer l'état de la LED 3
        if (compteur3 == 500) {
            DEL3 = !DEL3;  // Bascule l'état de la LED 3
            compteur3 = 0;  // Réinitialiser le compteur
        }
        // Si le compteur pour DEL2 atteint 250ms, basculer l'état de la LED 2
        else if (compteur2 == 250) {
            DEL2 = !DEL2;  // Bascule l'état de la LED 2
            compteur2 = 0;  // Réinitialiser le compteur
        }
        // Si le compteur pour DEL1 atteint 125ms, basculer l'état de la LED 1
        else if (compteur1 == 125) {
            DEL1 = !DEL1;  // Bascule l'état de la LED 1
            compteur1 = 0;  // Réinitialiser le compteur
        }
        else {
            // Si aucun des compteurs n'a atteint sa valeur cible, incrémenter tous les compteurs
            compteur1++;
            compteur2++;
            compteur3++;
        }

        __delay_ms(1);  // Délai de 1ms pour le comptage
    }
}