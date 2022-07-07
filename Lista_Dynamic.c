#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

struct lista{
    int dado;
    struct lista *prox;
};

    struct lista *create;

void insert_dynamic(int Valor,struct lista *p){//Insere Valor dentro da lista
    struct lista *aux;
    aux = (struct lista *)malloc(sizeof(struct lista));
    aux -> dado = Valor;
    aux -> prox = p -> prox;
    
    p -> prox = aux;

    printf("\nInserido:%d",p->dado);
}

void remove_dynamic(struct lista *p,int Valor){//Busca e remove elemento da lista
    struct lista *aux,*aux_2;
    aux = p;
    aux_2 = p-> prox;
    while(aux_2!=NULL&&aux_2->dado!=Valor){//Verifica se a próxima posição é vazia
        aux = aux_2;
    }
    if(aux_2 != NULL){//Verifica e realoca os elementos de posição
        aux->prox=aux_2->prox;
        free(aux_2);
    }
}

void search_dynamic(int valor,struct lista *p){//Busca número dentro da lista
    struct lista *aux;
    aux = p;
    if(aux==NULL){
        printf("\nLista vazia");
    }else{
        while(aux!=NULL && aux->dado!=valor){//Busca o número dentro da lista
            aux = aux->prox;
            if(aux->dado==valor){
                printf("\nAchei:%d",aux->dado);
                return;
            }else{
                printf("\nNúmero não encontrado");
                return;
            }
        }
    }
}

void printf_dynamic(struct lista *p){//Imprime lista inteira
struct lista *aux;
    for(aux = p-> prox;aux!=NULL;aux = aux->prox){
        printf("\nNúmero:%d",aux->dado);
    }
}

int main(){
   setlocale(LC_ALL, "Portuguese");
    int a, case_resp,loop;
    do{
    printf("-------------------------\n");
    printf("-          1-Inserir    -\n");
    printf("-          2-Remover    -\n");
    printf("-          3-Buscar     -\n");
    printf("-          4-Listar     -\n");
    printf("-          5-sair       -\n");
    printf("-------------------------\n");
    scanf("%d",&case_resp);

        if(case_resp==1){
            printf("Digite um valor:");
            scanf("%d",&a);
            insert_dynamic(a,create);
        }else if(case_resp==2){
            printf("Digite um valor:");
            scanf("%d",&a);
            remove_dynamic(create,a);
        }else if(case_resp==3){
            printf("Digite um valor:");
            scanf("%d",&a);
            search_dynamic(create,a);
        }else if(case_resp==4){
            printf_dynamic(create);
        }else if(case_resp==5){
            return 0;
        }

        printf("\nDeseja continuar:");
        scanf("%d",&loop);

    }while(loop==1);

    return 0;
}
