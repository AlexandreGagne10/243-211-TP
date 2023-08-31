void main(void) {
    SYSTEM_Initialize();
    DEL1 = 1;
    DEL2 = 1;
    DEL3 = 1;
    while (1) {
        if (compteur1 == 500) {
            DEL3 = !DEL3;
            compteur1 = 0;
        }
        else if (compteur2 == 250) {
            DEL2 = !DEL2;
            compteur2 = 0;
        }
        else if (compteur3 == 125) {
            DEL1 = !DEL1;
            compteur3 = 0;
        }
        else {
            compteur1++;
            compteur2++;
            compteur3++;
        }
        __delay_ms(1);
    }
}