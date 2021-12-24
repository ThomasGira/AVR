#ifndef F_CPU
#define F_CPU 1600000UL // Frequency of controller
#endif

#include <avr/io.h>
#include <util/delay.h>

#define ReadMode_U8   0xD1u  // DS1307 ID
#define WriteMode_U8  0xD0u  // DS1307 ID

void init(void){
    I2C_Init();     //Initialize I2C Module
    I2C_Start();    //Start I2C

    I2C_Write(WriteMode_U8); //Connect to device by sending its ID on the I2C BUS
    
    //Perform any other additional steps to initialize device

    I2C_Stop();
}

const char* parse(void){
}

int main(void){
    while(1){

    }
}