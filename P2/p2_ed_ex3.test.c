// Test file path: c:\Users\luiza\projects\ed\p2_ed_ex3.test.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "p2_ed_ex3.c" 


size_t bytes_alocados() {
    size_t bytes = 0;
    Profissao *p = aloca_profissao(10); 
    if (p != NULL) {
        bytes = sizeof(Profissao) + (strlen(p->nome) * sizeof(char));
        free(p->nome);
        free(p);
    }
    return bytes;
}

void test_bytes_alocados() {
    size_t expected_bytes = sizeof(Profissao) + (10 * sizeof(char));
    size_t actual_bytes = bytes_alocados();
    if (actual_bytes == expected_bytes) {
        printf("Teste de bytes alocados: Passou\n");
    } else {
        printf("Teste de bytes alocados: Falhou. Esperado: %lu, Obtido: %lu\n", expected_bytes, actual_bytes);
    }
}

int main() {
    test_bytes_alocados();
    return 0;
}