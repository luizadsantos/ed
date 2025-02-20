#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int codigo;
    char *nome;
} Profissao;

Profissao* aloca_profissao(unsigned int tamanho_nome) {

    Profissao *p = (Profissao *)malloc(sizeof(Profissao));
    if (p == NULL) {
        return NULL; 
    }

    p->nome = (char *)malloc(tamanho_nome * sizeof(char));
    if (p->nome == NULL) {
        free(p); 
        return NULL; 
    }

    return p; 
}