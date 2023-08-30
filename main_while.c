#include "mcc_generated_files/mcc.h"

#define DEL1 IO_RA0_LAT
#define DEL2 IO_RA1_LAT
#define DEL3 IO_RA2_LAT

int compteur1 = 0;
int compteur2 = 0;
int compteur3 = 0;

void main(void)
{
   SYSTEM_Initialize();

   // Allumer toutes les LED au départ
   DEL1 = 1;
   DEL2 = 1;
   DEL3 = 1;

   while (1) {
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
       __delay_ms(1);  // Délai de 1ms pour le comptage
   }
}