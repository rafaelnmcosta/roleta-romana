#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct soldado {
    char nome[50];
	struct soldado *proximo;
	struct soldado *anterior;
} tipoSoldado;

typedef struct lista{
    tipoSoldado *inicio;
    tipoSoldado *fim;
    int tamanho;
} tipoLista;

//Prototipos de função
tipoLista criaLista(tipoLista* lista);
tipoSoldado *aloca(char *nome);
void insereSoldado(tipoSoldado* novoSoldado, tipoLista* lista);
void removeSoldado(tipoSoldado* soldadoExcluido, tipoLista* lista);
tipoSoldado* defineInicio(tipoLista* lista, char *inicio);
void roleta(int n, char* sentido, tipoLista* lista, tipoSoldado* soldadoInicial);

void imprimeLista(tipoLista* lista);
/* ----------------------------------------------- */

tipoLista criaLista(tipoLista* lista) {
	lista->inicio = NULL;
	lista->fim = NULL;
	lista->tamanho = 0;
    return *lista;
}

tipoSoldado* aloca(char *nome) {
	tipoSoldado *novoSoldado = (tipoSoldado*)malloc(sizeof(tipoSoldado));
	strcpy(novoSoldado->nome, nome);
	novoSoldado->anterior = NULL;
	novoSoldado->proximo = NULL;
	return novoSoldado;
}

void insereSoldado(tipoSoldado* novoSoldado, tipoLista* lista){

    tipoSoldado* primeiroSoldado;
    tipoSoldado* ultimoSoldado;
    primeiroSoldado = lista->inicio;
    ultimoSoldado = lista->fim;

    if(lista->tamanho == 0){
        lista->tamanho = lista->tamanho+1;
        lista->inicio = novoSoldado;
        lista->fim = novoSoldado;
        novoSoldado->anterior = novoSoldado;
        novoSoldado->proximo = novoSoldado;
    }
    else if(lista->tamanho == 1){
        lista->tamanho = lista->tamanho+1;
        novoSoldado->anterior = lista->fim;
        novoSoldado->proximo = lista->inicio;
        lista->fim = novoSoldado;
        primeiroSoldado->anterior = novoSoldado;
        primeiroSoldado->proximo = novoSoldado;
    }
    else{
        lista->tamanho = lista->tamanho+1;
        novoSoldado->anterior = lista->fim;
        novoSoldado->proximo = lista->inicio;
        lista->fim = novoSoldado;
        primeiroSoldado->anterior = novoSoldado;
        ultimoSoldado->proximo = novoSoldado;
    }
}

void removeSoldado(tipoSoldado* soldadoExcluido, tipoLista* lista){
    tipoSoldado *auxAnterior, *auxProximo;
    
    if(soldadoExcluido == lista->inicio){
        lista->inicio = lista->inicio->proximo;
    }
    if(soldadoExcluido == lista->fim){
        lista->fim = lista->fim->anterior;
    }
    
    auxAnterior = soldadoExcluido->anterior;
    auxProximo = soldadoExcluido->proximo;

    auxAnterior->proximo = auxProximo;
    auxProximo->anterior = auxAnterior;

    lista->tamanho = lista->tamanho-1;

    free(soldadoExcluido);
}

tipoSoldado* defineInicio(tipoLista* lista, char *inicioRoleta){

    tipoSoldado* aux = lista->inicio;

    while(aux != lista->fim){
        if(strcmp(aux->nome, inicioRoleta) == 0){
            return aux;
        }else{
            aux = aux->proximo;
        }
    }
    if(strcmp(aux->nome, inicioRoleta) == 0){
        return aux;
    }else{
        printf("O soldado informado não existe!");
    }
}

void roleta(int n, char* sentido, tipoLista* lista, tipoSoldado* soldadoInicial){
    int i;

    if(lista->tamanho == 1){
        printf("\nSoldado Sortudo: %s\n", soldadoInicial->nome);
    }
    else{
        
        tipoSoldado* soldadoRemovido = soldadoInicial;
        tipoSoldado* proxRemovido;

        if(strcmp(sentido, "h") == 0){
            for(i=1; i<n; i++){
                soldadoRemovido = soldadoRemovido->proximo;
            }
            proxRemovido = soldadoRemovido->proximo;
        }
        else if(strcmp(sentido, "a") == 0){
            for(i=1; i<n; i++){
                soldadoRemovido = soldadoRemovido->anterior;
            }
            proxRemovido = soldadoRemovido->anterior;
        }

        printf("%s", soldadoRemovido->nome);
        removeSoldado(soldadoRemovido, lista);
        roleta(n, sentido, lista, proxRemovido);
    }
}

void imprimeLista(tipoLista* lista){
    tipoSoldado* aux = lista->inicio;
    int i;

    for(i=0; i<lista->tamanho; i++){
        printf("%s ", aux->nome);
        aux = aux->proximo;
    }
}

int main(){
    int n, nAux;
    int verificador = 1;
    char sentido[1];
    char inicioRoleta[50];
    tipoLista lista;
    
    lista = criaLista(&lista);

    printf("Entre com (n>0):");
    scanf("%d", &n);

    if(n<=0){
        printf("\nn invalido!\n");
        //Termina o programa caso o n seja inválido
        return 0;
    }

    nAux = n;

    printf("\nSentido (h - horario e a - anti-horario): ");
    scanf("%s", sentido);

    if(strcmp(sentido, "h") != 0 && strcmp(sentido, "a") != 0){
        printf("\nSentido invalido!\n");
        //Termina o programa caso o sentido seja inválido
        return 0;
    }

    printf("\nNome dos soldados (FIM para encerrar):\n");
    while(verificador == 1){

        char auxnome[50];
        scanf("%s", auxnome);

        if(strcmp(auxnome, "FIM")==0){
            verificador = 0;
        }
        else{
            tipoSoldado* novoSoldado;
            novoSoldado = aloca(auxnome);
            insereSoldado(novoSoldado, &lista);
        }
    }

    printf("\nNome do soldado para comecar a roleta romana: ");
    scanf("%s", inicioRoleta);

    tipoSoldado* soldadoInicial = defineInicio(&lista, inicioRoleta);

    printf("\nOrdem de saida: ");
    roleta(nAux, sentido, &lista, soldadoInicial);

    return 0;
}