#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/examples/i2c_master_example.h"

#define EEPROM_DEVICE_ADDRESS 0x50
#define HIGH_ADDRESS_EEPROM   0x00
#define LOW_ADDRESS_EEPROM    0x00

void EEPROM_WriteByte(uint16_t memAddress, uint8_t data) {
    uint8_t buffer[3];
    buffer[0] = (memAddress >> 8) & 0xFF;  // Adresse haute
    buffer[1] = memAddress & 0xFF;         // Adresse basse
    buffer[2] = data;

    while(!I2C_Open(EEPROM_DEVICE_ADDRESS));
    I2C_WriteNBytes(EEPROM_DEVICE_ADDRESS, buffer, 3);
    while(I2C_BUSY == I2C_Close());
    __delay_ms(5); // Temps de programmation
}

uint8_t EEPROM_ReadByte(uint16_t memAddress) {
    uint8_t buffer[2];
    uint8_t readData = 0;
    buffer[0] = (memAddress >> 8) & 0xFF;
    buffer[1] = memAddress & 0xFF;

    while(!I2C_Open(EEPROM_DEVICE_ADDRESS));
    I2C_WriteNBytes(EEPROM_DEVICE_ADDRESS, buffer, 2);
    I2C_ReadNBytes(EEPROM_DEVICE_ADDRESS, &readData, 1);
    while(I2C_BUSY == I2C_Close());

    return readData;
}

void main(void) {
    SYSTEM_Initialize();

    //EEPROM_WriteByte(0x12, 0x40); // Modifiez l'adresse à 0x12 comme vous l'avez mentionné

    uint8_t result = EEPROM_ReadByte(0x12); // Lire de la même adresse
    printf("0x%x\r", result);

    while(1);
}