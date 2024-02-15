#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main() {

    float pila[4] = {0, 0, 0, 0};
    char texto[] = "texto";
    float numero;
    int esNumero = 1;
    int size = 4;

    int limpiar;

    do {

        limpiar = 0;
        esNumero = 1;

        printf("Hola, ponga un numero o (+,-,*,/)\n");
        printf("4. %f\n", pila[3]);
        printf("3. %f\n", pila[2]);
        printf("2. %f\n", pila[1]);
        printf("1. %f\n", pila[0]);

        scanf("%s", &texto);
        
        for (int i = 0; texto[i] != '\0'; i++) {
            if(texto[i] == '.') continue;
            if(!isdigit(texto[i])) {
                esNumero = 0;
                break;
            }
        }

        if(esNumero == 1){
            
            numero = (float) atof(texto);

            for(int i = 0; i < size; i = i+1) {
                if(pila[i] == 0) {
                    pila[3] = pila[2];
                    pila[2] = pila[1];
                    pila[1] = pila[0];
                    pila[0] = numero;
                    break;
                }
            }
        }
        else {

            if(strcmp(texto, "+") == 0) {
                pila[0] = pila[1] + pila[0];
                limpiar = 1;
            }
            else if(strcmp(texto, "-") == 0) {
                pila[0] = pila[1] - pila[0];
                limpiar = 1;
            }
            else if(strcmp(texto, "*") == 0) {
                pila[0] = pila[1] * pila[0];
                limpiar = 1;
            }
            else if(strcmp(texto, "/") == 0) {
                if(pila[0] != 0) pila[0] = pila[1] / pila[0];
                limpiar = 1;
            }
            /*else if(strcmp(texto, "cos")) cos(pila[0]);
            else if(strcmp(texto, "sin")) sin(pila[0]);
            else if(strcmp(texto, "tan")) tan(pila[0]);
            else if(strcmp(texto, "pow2")) pila[0] = pila[0] * pila[0];
            else if(strcmp(texto, "powy")) {
                powf(pila[1], pila[0]);
                limpiar = 1;
            }
            else if(strcmp(texto, "sqrt")) sqrtf(pila[0]);*/

            if(limpiar == 1) {
                pila[1] = pila[2];
                pila[2] = pila[3];
                pila[3] = 0;
            }
        }

        if(strcmp(texto, "salir") == 0) break;
        system("clear");      
    }
    while (0 == 0);

    return 0;
}