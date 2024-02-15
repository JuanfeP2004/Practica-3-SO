#define PI 3.14159265358979323846

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

        system("clear");
        printf("Hola, ponga un numero u operacion (+,-,*,/,pow2,sqrt,powy,cos,sin,tan,pi) o comando (borrar,salir)\n");
        printf("4. %f\n", pila[3]);
        printf("3. %f\n", pila[2]);
        printf("2. %f\n", pila[1]);
        printf("1. %f\n", pila[0]);

        scanf("%s", &texto);
        
        for (int i = 0; texto[i] != '\0'; i++) {
            if(texto[i] == '.') continue;
            if(texto[i] == '-' && i == 0 && texto[i+1] != '\0') {
                continue;
            }
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
            else if(strcmp(texto, "cos") == 0) {
                pila[0] = cosf(pila[0]);
            }
            else if(strcmp(texto, "sin") == 0) {
                pila[0] = sin(pila[0]);
            }
            else if(strcmp(texto, "tan") == 0) {
                pila[0] = tan(pila[0]);
            }
            else if(strcmp(texto, "pow2") == 0) {
                pila[0] = pila[0] * pila[0];
            }
            else if(strcmp(texto, "powy") == 0) {
                pila[0] = powf(pila[1], pila[0]);
                limpiar = 1;
            }
            else if(strcmp(texto, "sqrt") == 0) { 
                pila[0] = sqrtf(pila[0]);
            }
            else if(strcmp(texto, "pi") == 0) {
                pila[0] = (float) PI;
            }

            if(limpiar == 1) {
                pila[1] = pila[2];
                pila[2] = pila[3];
                pila[3] = 0;
            }
        }

        if(strcmp(texto, "borrar") == 0)
        {
            pila[0] = 0;
            pila[0] = pila[1];
            pila[1] = pila[2];
            pila[2] = pila[3];
            pila[3] = 0;
        }
        else if(strcmp(texto, "salir") == 0) break;      
    }
    while (0 == 0);

    return 0;
}