//Árvores
#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int chave;
    struct No* pai;
    struct No* direita;
    struct No* esquerda;
} Nodo;

Nodo* criarNodo(int chave){
    Nodo* nodo = (Nodo *) malloc(sizeof(Nodo));
    nodo->chave = chave;
    nodo->pai = NULL;
    nodo->esquerda = NULL;
    nodo->direita = NULL;
    return nodo;
}

void nivel(Nodo* no){
    Nodo* aux = no;
    int i = 0;
    while(aux->pai){
        i++;
        aux = aux->pai;
    }
    printf("O nível do seu nodo é : %d",i);
}

void buscar(){

}

int buscarProfundidade(Nodo* raiz,int profundidade,int maior){
    if(raiz){
        if(profundidade > maior){
        buscarProfundidade(raiz->esquerda,profundidade+1,profundidade+1);
        }
        printf("profundidade atual: %d",);
        buscarProfundidade(raiz->direita,profundidade+1);
    } else{}
}




int main(){

}