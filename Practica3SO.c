#include <stdio.h>

int main() {

    float pila[4] = {0, 0, 0, 0};
    float numero = 0;

    do {

        printf("Hola, ponga un numero");
        printf("4. %f", pila[3]);
        printf("3. %f", pila[2]);
        printf("2. %f", pila[1]);
        printf("1. %f", pila[0]);

        scanf("%f", &numero);
    }
    while (0 == 0);

    return 0;
}

/*void hola(int numero){
    
    if (pila[0] == 0) {
        
    }
    else if (pila[2] == 0){
        
    }
    else if (pila[2] == 0){
        
    }
    else if (pila[3] == 0){
        
    }

    return;
}*/