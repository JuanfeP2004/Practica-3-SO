#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    float pila[4] = {0, 0, 0, 0};
    char texto[] = "texto";
    float numero;
    int esNumero = 1;
    int size = 4;

    do {

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
        //printf("%s", texto);

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
            switch (texto[0])
                {
                case '+':
                    pila[0] = pila[1] + pila[0];
                    break;
                case '-':
                    pila[0] = pila[1] - pila[0];
                    break;
                case '*':
                    pila[0] = pila[1] * pila[0];
                    break;
                case '/':
                    if(pila[0] != 0)
                        pila[0] = pila[1] / pila[0];
                    break;            
                default:

                    break;
                }

            pila[1] = pila[2];
            pila[2] = pila[3];
            pila[3] = 0;
        }

        system("clear");
    }
    while (0 == 0);

    return 0;
}