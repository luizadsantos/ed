#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *stack;
    int size;
    int weight;
} Wookie;

void push(Wookie *w, int role) {
    w->stack = realloc(w->stack, (w->size + 1) * sizeof(int));
    w->stack[w->size] = role;
    w->size++;
    w->weight += role;
}

int compare(const void *a, const void *b) {
    Wookie *w1 = (Wookie *)a;
    Wookie *w2 = (Wookie *)b;
    return w2->weight - w1->weight;
}

int nowookie(Wookie *wookies, int n) {
    for (int i = 0; i < n; i++) {
        if (wookies[i].size == 0) {
            return i;
        }
    }
    return -1;
}

int rightwookie(Wookie *wookies, int n, int role) {

    for (int i = 0; i < n; i++) {
        if (wookies[i].size > 0) {
            int top = wookies[i].stack[wookies[i].size - 1];
            if (top >= role) {
                return i;
            }
        }
    }
    return -1;
}

int main() {
    int n;
    scanf("%d", &n);
    
    if (n == 0) {
        int role;
        printf("Os Wookies foram para o lado sombrio da força!\n");
        while (scanf("%d", &role) != EOF) {
            printf("%d ", role);
        }
        printf("\n");
        return 0;
    }

    Wookie *wookies = malloc(n * sizeof(Wookie));
    for (int i = 0; i < n; i++) {
        wookies[i].stack = NULL;
        wookies[i].size = 0;
        wookies[i].weight = 0;
    }

    int *leftbehind = NULL;
    int numleft = 0;
    
    int role;
    while (scanf("%d", &role) != EOF) {

        int zero = nowookie(wookies, n);
        if (zero != -1) {
            push(&wookies[zero], role);
            continue;
        }
        

        int theones = rightwookie(wookies, n, role);
        if (theones != -1) {
            push(&wookies[theones], role);
        } else {

            leftbehind = realloc(leftbehind, (numleft + 1) * sizeof(int));
            leftbehind[numleft++] = role;
        }
    }


    qsort(wookies, n, sizeof(Wookie), compare);

    for (int i = 0; i < n; i++) {
        printf("[");
        for (int j = 0; j < wookies[i].size; j++) {
            printf("%d", wookies[i].stack[j]);
            if (j < wookies[i].size - 1) printf(", ");
        }
        printf("]");
        if (i < n - 1) printf(" ");
    }
    printf("\n");

    if (numleft > 0) {
        for (int i = 0; i < numleft; i++) {
            printf("%d", leftbehind[i]);
            if (i < numleft - 1) printf(" ");
        }
        printf("\n");
    } else {
        printf("A força está com os Wookies!\n");
    }

    for (int i = 0; i < n; i++) {
        free(wookies[i].stack);
    }
    free(wookies);
    free(leftbehind);
    
    return 0;
}