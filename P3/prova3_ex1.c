#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char firstname[51];
    char lastname[51];
    int height;
    int weight;
} profgirafales;

int the1(const void *a, const void *b) {
    profgirafales *p1 = (profgirafales *)a;
    profgirafales *p2 = (profgirafales *)b;

    int height1 = 180;
    int weight1 = 75;

 
    int heightdiff1 = abs(p1->height - height1);
    int heightdiff2 = abs(p2->height - height1);
    
    if (heightdiff1 != heightdiff2)
        return heightdiff1 - heightdiff2;

    if ((p1->weight <= weight1 && p2->weight > weight1) ||
        (p2->weight <= weight1 && p1->weight > weight1)) {
        return p1->weight <= weight1 ? -1 : 1;
    }

    int weightdiff1 = abs(p1->weight - weight1);
    int weightdiff2 = abs(p2->weight - weight1);
    
    if (weightdiff1 != weightdiff2)
        return weightdiff1 - weightdiff2;

 
    int comp = strcmp(p1->lastname, p2->lastname);
    if (comp != 0)
        return comp;

    return strcmp(p1->firstname, p2->firstname);
}

int main() {
    int cont;
    scanf("%d", &cont);

    if (cont < 2 || cont > 100)
        return 1;

    profgirafales *prop = malloc(cont * sizeof(profgirafales));

    for (int i = 0; i < cont; i++) {
        scanf("%s %s %d %d", prop[i].firstname, prop[i].lastname, &prop[i].height, &prop[i].weight);

        if (strlen(prop[i].firstname) > 50 || strlen(prop[i].lastname) > 50) {
            free(prop);
            return 1;
        }
    }

    qsort(prop, cont, sizeof(profgirafales), the1);

    for (int i = 0; i < cont; i++) {
        printf("%s, %s\n", prop[i].lastname, prop[i].firstname);
    }

    free(prop);
    return 0;
}