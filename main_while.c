#include "mcc_generated_files/mcc.h"

// D�finition des macros pour les LEDs (DEL en fran�ais)
#define DEL1 IO_RA0_LAT  // D�finition pour la LED 1
#define DEL2 IO_RA1_LAT  // D�finition pour la LED 2
#define DEL3 IO_RA2_LAT  // D�finition pour la LED 3

// Initialisation des compteurs pour chaque LED
int compteur1 = 0;
int compteur2 = 0;
int compteur3 = 0;

void main(void)
{
   SYSTEM_Initialize();

   // Allumer toutes les LED au d�part
   DEL1 = 1;
   DEL2 = 1;
   DEL3 = 1;

   // Boucle infinie
   while (1) {
       // Incrementer chaque compteur
       compteur1++;
       compteur2++;
       compteur3++;

       // Pour DEL1 (1Hz)
       while (compteur1 >= 500) {
           DEL3 = !DEL3;
           compteur1 = 0;
       }

       // Pour DEL2 (2Hz)
       while (compteur2 >= 250) {
           DEL2 = !DEL2;
           compteur2 = 0;
       }

       // Pour DEL3 (4Hz)
       while (compteur3 >= 125) {
           DEL1 = !DEL1;
           compteur3 = 0;
       }
       __delay_ms(1);  // D�lai de 1ms pour le comptage
   }
}