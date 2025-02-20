#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
   char mnc[3];
   char nm[101]; 
   int pnt;
} std;

int getpts(const char *m) {
   if (strcmp(m, "SS") == 0) return 6;
   if (strcmp(m, "MS") == 0) return 5;
   if (strcmp(m, "MM") == 0) return 4;
   if (strcmp(m, "MI") == 0) return 3;
   if (strcmp(m, "II") == 0) return 2;
   if (strcmp(m, "SR") == 0) return 1;
   return 0;
}

int cmp(const void *a, const void *b) {
   std *x = (std *)a;
   std *y = (std *)b;
   
   if (x->pnt != y->pnt)
       return y->pnt - x->pnt;
   
   return strcmp(x->nm, y->nm);
}

int main() {
   int amt;
   scanf("%d", &amt);
   
   if (amt < 1 || amt > 500)
       return 1;
       
   std *cls = malloc(amt * sizeof(std));
   
   for (int i = 0; i < amt; i++) {
       scanf("%s %[^\n]", cls[i].mnc, cls[i].nm);
       getchar();
       
       if (strlen(cls[i].nm) > 100) {
           free(cls);
           return 1;
       }
       
       cls[i].pnt = getpts(cls[i].mnc);
   }
   
   qsort(cls, amt, sizeof(std), cmp);
   
   for (int i = 0; i < amt; i++) {
       printf("%s %s\n", cls[i].mnc, cls[i].nm);
   }
   
   free(cls);
   return 0;
}