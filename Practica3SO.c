#include <stdio.h>

int main() {

    float pila[4] = {0, 0, 0, 0};
    float numero = 0;
    int size = 4;

    do {

        printf("Hola, ponga un numero\n");
        printf("4. %f\n", pila[3]);
        printf("3. %f\n", pila[2]);
        printf("2. %f\n", pila[1]);
        printf("1. %f\n", pila[0]);

        scanf("%f", &numero);
        
        for(int i = 0; i < size; i = i+1){
            if(pila[i] == 0) {
                pila[i] = numero;
                break;
            }
        }
    }
    while (0 == 0);

    return 0;
}