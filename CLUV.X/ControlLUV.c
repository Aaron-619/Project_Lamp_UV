#include <xc.h>
#include<stdbool.h>
// CONFIG
#pragma config FOSC = INTRCIO   // Oscilador interno de 4Mhz.
#pragma config WDTE = OFF       // Desavilitamos el Watchdog guardian.
#pragma config PWRTE = ON       // Activamos el Power-Up Timer.
#pragma config MCLRE = ON       // Activamos el MCLRE para el botón de reset.
#pragma config BOREN = OFF      // Desactivamos el Brown-out .
#pragma config CP = OFF         // Deasactivamos el código de Protección.
#pragma config CPD = OFF        // Desactivamos el bit de código de protección.

#define _XTAL_FREQ 4000000      // Definimos el oscilador interno.

void main(void) {
    ANSEL &= ~0x0F;     // Desactivamos las entradas analogicas.
    CMCON = 0x07;       // Desactivamos el comparador.
    bool flag = false;  // Inicializamos la bandera como falso.
    
    // Configuración de puertos
    TRISIObits.TRISIO0 = 1;       // Configuramos el puerto TRISIO0 como entrada.
    TRISIObits.TRISIO1 = 0;       // Configuramos el puerto TRISO1 como salida.
    GPIObits.GP1 = 0;             // El puerto GP1 se inicializa apagado.       
    TRISIObits.TRISIO2 = 0;       // Configuramos el puerto TRISIO2 como entrada.
    GPIObits.GP2 = 0;             // El puerto GP2 se inicializa apagado. 
    TRISIObits.TRISIO4 = 0;       // Configuramos el puerto TRISIO4 como entrada.
    GPIObits.GP4 = 0;             // El puerto GP4 se inicializa apagado. 
    TRISIObits.TRISIO5 = 0;       // Configuramos el puerto TRISIO5 como entrada.
    GPIObits.GP5 = 0;             // El puerto GP5 se inicializa apagado. 
    while(1){
        if(GPIObits.GPIO0 == 1){
            while(GPIObits.GPIO0 == 1);
            while(flag == false){
            __delay_ms(500);      // Un tiempo de espera de 500milisegundos.
            GPIObits.GP1 = 1;     // Se manda un 1 al puerto GP1. 
            GPIObits.GP2 = 1;     // Se manda un 1 al puerto GP2. 
            GPIObits.GP4 = 1;     // Se manda un 1 al puerto GP4. 
            GPIObits.GP5 = 1;     // Se manda un 1 al puerto GP5. 
            if(GPIObits.GPIO0 == 1){
                while(GPIObits.GPIO0 == 1);
                flag = true;      
            }
            
            }
            __delay_ms(500);    // Un tiempo de espera de 500milisegundos.
            GPIObits.GP1 = 0;   // Se manda un 0 al puerto GP1. 
            GPIObits.GP2 = 0;   // Se manda un 0 al puerto GP2. 
            GPIObits.GP4 = 0;   // Se manda un 0 al puerto GP4. 
            GPIObits.GP5 = 0;   // Se manda un 0 al puerto GP5. 
            break;

        }
       
    }
    return;
}




















