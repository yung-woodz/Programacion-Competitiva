#include<stdio.h>

int main(){

    char caracter = 'Z';
    printf("%c", caracter);
    //Se le pueden asignar dos condiciones: true o false
    int entero;//definir como entero
    entero = 5;
    float decimal;
    decimal = 0.5;//decimal <- 0.5
    printf("El numero entero es: %d", entero); //Escribir
    //%d para enteros
    //%f para decimales/flotantes
    //%c para 1 caracter
    //%s para cadena de caracteres/string

    scanf("%d", &entero);

    //Tipos de operadores condicionales 
    //<=   >=   <   >   !=   ==
    if(entero == decimal){
        printf("Son iguales");
    }else if(entero > decimal){
        printf("Entero es mayor");
    }else{
        printf("No son iguales");
    }

    int i;
    for(i=0; i<10; i++){
        printf("%d", i);
    }



    return 0;
}