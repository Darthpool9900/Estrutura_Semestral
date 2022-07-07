#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

struct lista{
    int dado;
    struct lista *prox;
};

    struct lista *create;

void insert(int Valor,struct lista *p){//Insere Valor dentro da lista
    struct lista *aux;
    aux = (struct lista *)malloc(sizeof(struct lista));
    aux -> dado = Valor;
    aux -> prox = p -> prox;
    for(int i = 0; i<aux; i++){
        if(aux->dado==Valor){
            printf("Repetido");
        }
    }
    p -> prox = aux;

    printf("\nInserido:%d",p->dado);
}

void remover(struct lista *p,int Valor){//Busca e remove elemento da lista
    struct lista *aux,*aux_2;
    aux = p;
    aux_2 = p-> prox;
    while(q!=NULL&&q->dado!=Valor){//Verifica se a próxima posição é vazia
        aux = aux_2;
    }
    if(aux_2 != NULL){//Verifica e realoca os elementos de posição
        aux->prox=aux_2->prox;
        free(aux_2);
    }
}

