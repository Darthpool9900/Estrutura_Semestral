#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct no
{
	int dado;
	struct no *proximo;
}no;

struct no *inicio = NULL;
struct no *contador;
struct no *Lista;



void insere(int i)
{
	struct no *aux;

	aux=(struct no*)malloc (sizeof(struct no));
	aux->dado=i;
	aux->proximo=NULL;


	struct no *index;
    	index = inicio;
    	while(index != NULL)
    	{
        	if(i == index->dado)
        	{
            	printf("Valor repetido.\n");
            	return;
        	}
        	index = index->proximo;
    	}
	if(contador==NULL)
	{
    	inicio = aux;
    	Lista = aux;
	}
	else
	{
    	Lista -> proximo = aux;
    	Lista =aux;
	}

	contador++;
	printf("\nElemento inserido.\n");

}



void remover(int i)
{
	struct no *atual=inicio, *anterior=NULL;

	if(inicio==NULL)
	{
    	printf("Lista Vazia.");
    	return;
	}
	if(inicio->dado==i)
	{
    	inicio=inicio->proximo;
    	free(atual);
    	atual=inicio;
    	contador--;
    	printf("\nElemento removido.\n");
	}
	while(atual!=NULL && i>=atual->dado)
	{
    	if(atual->dado==i)
    	{
        	anterior->proximo=atual->proximo;
        	free(atual);
        	atual=anterior->proximo;
        	contador--;
        	printf("\nElemento removido.\n");
        	return;
    	}
    	else
    	{
        	anterior=atual;
        	atual=atual->proximo;
    	}

	}
	printf("Valor não encontrado.\n");
}

void buscar(int i)
{
	struct no *aux;
	if (Lista==NULL)
	{
    	printf("Lista vazia.");
    	return;
	}
	if(Lista!=NULL){
	for(aux=inicio; aux!=NULL; aux=aux->proximo)
	{
    	if(aux->dado==i)
    	{
        	printf("Valor %d encontrado!",aux->dado);
        	return;
    	}
	}
	}
	printf("Valor nao encontrado.\n");
}

void imprimir()
{
	struct no *aux;
	if(Lista==NULL)
	{
    	printf("\nLista vazia.\n");
    	return;
	}
	aux = inicio;
	printf("\nLista:\n");
	while (aux != NULL)
	{
    	printf("%d ",aux->dado);
    	aux = aux->proximo;

	}
	printf("\n");
}

int main()
{
	setlocale(LC_ALL,"PORTUGUESE");
	int i, op;

	while (op!=5)
	{
    	 printf("-------------------------\n");
    printf("1 - Inserir um valor\n");
    printf("2 - Remover um valor\n");
    printf("3 - Buscar um valor\n");
    printf("4 - Listar\n");
    printf("5 - Sair\n");
    printf("-------------------------\n");
    printf("Operação: ");

    	scanf("%d",&op);

    	switch(op)
    	{
    	case 1:
        	printf("\nInsira um valor: ");
        	scanf("%d",&i);
        	printf("\n");
        	insere(i);
        	printf("\n\n");
        	break;

    	case 2:
        	printf("\nInsira o valor que deseja remover: ");
        	scanf("%d",&i);
        	printf("\n");
        	remover(i);
        	printf("\n\n");
        	break;

    	case 3:
        	printf("\nInsire o valor que deseja buscar: ");
        	scanf("%d",&i);
        	printf("\n");
        	buscar(i);
        	printf("\n\n");
        	break;

    	case 4:
        	imprimir();
        	break;


    	}
	}
	printf("\n");
	return;
}
