#include <stdio.h>
#include <stdlib.h>

void rotinaLeitura(){
    
}

void strLen(char *teste){
    int tam = 0;
    while (*teste != 0){
        teste += sizeof(char); 
        tam++;
    }
    printf("o tamanho da string é: %d",tam);
}

int main(){
    strLen(str);
}
// too tired to properly think