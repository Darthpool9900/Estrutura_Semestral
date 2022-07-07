#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

typedef struct No {
    int valor;
    struct No *proximo;
} No;
typedef struct {
    No *inicio, *fim;
    int tam;
} Lista;

/// inserção no início da lista
void inserirInicio(Lista *lista, int valor) {
    No *novo = (No*)malloc(sizeof(No)); // cria um novo nó
    novo->valor = valor;// (*novo).valor = valor

    if(lista->inicio == NULL) { // a lista está vazia
        novo->proximo = NULL;
        lista->inicio = novo;
        lista->fim = novo;
    } else { // a lista não está vazia
        novo->proximo = lista->inicio;
        lista->inicio = novo;
    }
    lista->tam++;
}
// remover um elemento da lista
void remover(Lista *lista, int valor) {
    No *inicio = lista->inicio; // ponteiro para o início da lista
    No * noARemover = NULL; // ponteiro para o nó a ser removido

    if(inicio != NULL && lista->inicio->valor == valor) { // remover 1º elemento
        noARemover = lista->inicio;
        lista->inicio = noARemover->proximo;
        if(lista->inicio == NULL)
            lista->fim = NULL;
    } else { // remoção no meio ou no final
        while(inicio != NULL && inicio->proximo != NULL && inicio->proximo->valor != valor) {
            inicio = inicio->proximo;
        }
        if(inicio != NULL && inicio->proximo != NULL) {
            noARemover = inicio->proximo;
            inicio->proximo = noARemover->proximo;
            if(inicio->proximo == NULL) // se o último elemento for removido
                lista->fim = inicio;
        }
    }
    if(noARemover) {
        free(noARemover); // libera a memória do nó
        lista->tam--; // decrementa o tamanho da lista
    }
}

// imprimir a lista
void imprimir(Lista *lista) {
    No *inicio = lista->inicio;
    printf("Tamanho da lista: %d\n", lista->tam);
    while(inicio != NULL) {
        printf("%d ", inicio->valor);
        inicio = inicio->proximo;
    }
    printf("\n\n");
}

/*void search_dynamic(int valor,struct lista *p){//Busca número dentro da lista
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
}*/


int main(){
   setlocale(LC_ALL, "Portuguese");
   struct Lista *create;
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
            inserirInicio(create,a);
        }else if(case_resp==2){
            printf("Digite um valor:");
            scanf("%d",&a);
            remover(create,a);
        }else if(case_resp==3){
            
        }else if(case_resp==4){
            imprimir(create);
        }else if(case_resp==5){
            return 0;
        }

        printf("\nDeseja continuar:");
        scanf("%d",&loop);

    }while(loop==1);

    return 0;
}
