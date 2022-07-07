//Trabalho 1º Bimestre - Listas Sequenciais e Dinâmicas
//Estrutura de Dados I - Prof. Albino Szesz Jr.
//Rafael Zachesky de Oliveira RA: 21010026
//Reinaldo Calixto Junior RA: 21010226


#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#define TAM 3
int lista[TAM], cont =0,aux_org;

int List_Insert_Static(int Valor){//Função utilizada para inserir valores dentro de uma lista que utiliza vetores
    int aux;
    int menor = cont -1;

    if(cont==TAM){//Verifica se está vázio
        printf("\nLista cheia");
        return;
    }else{
        for(aux=0;aux<cont;aux++){
            if(lista[aux]==Valor){//Verifica se o valor já foi inserido
                printf("\nElemento não inserido pois elemento %d já está na lista",lista[aux]);
                return;
            }
        }
                lista[cont] = Valor;
                
                    printf("\n=======================================================");
                    printf("\n||   Elemento %d inserido e alocado para posição %d  ||",lista[cont],cont);
                    printf("\n=======================================================");
                    cont++;
        
    }
            
        
    Org_Val(); 
}

void Org_Val(){//Rotina para organizar Valores em Ordem numémrica
    for (int j = 1; j < cont; ++j) {
      int x = lista[j];
      int i;
      for (i = j-1; i >= 0 && lista[i] > x; --i) 
         lista[i+1] = lista[i];
         lista[i+1] = x;
   }
}

void Remove_Static(int valor){//Remove valor selelcionado de um fila que utiliza vetores
    int i, marcador;
    for(i = 0; i < cont; i++){
        if(lista[i] == valor){//Identifica e compara se o valor do vetor é igual ao inserido
            marcador = i;
        }
    }
    for(i = marcador; i < cont; i++){
        lista[i] = lista[i + 1];//Altera a posição do valor do vetor posterior ao excluído
    }
    cont--;
}
void Search_Static(int valor){//Busca valor em uma lista que utiliza vetores
    int aux;
    if(cont==0){//Verifica se já existe uma lista
         printf("\n=======================================================");
         printf("\n||                     Lista vazia                    ||");
         printf("\n=======================================================");
        return;
    }
    for(aux=0;aux<cont;aux++){
        if(lista[aux]==valor){//Verifica se achou valor
            printf("\n=======================================================");
            printf("\n||            Encontrado:%d na posição %d             ||",lista[aux],aux);
            printf("\n=======================================================");
            return;
        }else{
            printf("\n=======================================================");
            printf("\n||              Nenhum elemento encontrado           ||");
            printf("\n=======================================================");
        }
    }
}

void Static_Print(){//Imprime uma lista que utiliza Vetores
    int aux;
    if(cont==0){
        printf("\n=======================================================");
        printf("\n||                     Lista vazia                    ||");
        printf("\n=======================================================");
    }
    for(aux=0;aux<cont;aux++){
        printf("\n=======================================================");
        printf("\n||                    Número:%d                      ||",lista[aux]);
        if(aux==cont-1){
            printf("\n=======================================================");
        }
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
            List_Insert_Static(a);
        }else if(case_resp==2){
            printf("Digite um valor:");
            scanf("%d",&a);
            Remove_Static(a);
        }else if(case_resp==3){
            printf("Digite um valor:");
            scanf("%d",&a);
            Search_Static(a);
        }else if(case_resp==4){
            Static_Print();
        }else if(case_resp==5){
            return 0;
        }

        printf("\nDeseja continuar:");
        scanf("%d",&loop);

    }while(loop==1);

    return 0;
}
