#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No* prox;
} No;

typedef struct {
    No* inicio;
    No* fim;
    int tamanho;
} Fila;

void inicializaFila(Fila* fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
}

int dequeue(Fila* fila) {
    if (fila->inicio == NULL) {
        printf("Fila vazia\n");
        return -1; 
    }

    No* temp = fila->inicio;
    int dado = temp->dado;
    fila->inicio = fila->inicio->prox;

    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    free(temp);
    fila->tamanho--;
    return dado;
}

int main() {
    Fila fila;
    inicializaFila(&fila);


    return 0;
}