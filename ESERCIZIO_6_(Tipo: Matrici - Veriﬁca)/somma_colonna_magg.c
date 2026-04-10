/* ESERCIZIO 6 (Tipo: Matrici - Veriﬁca)
Un ﬁle contiene una matrice RxC (R righe e C colonne, #deﬁne) di numeri reali separati
da spazi.
Calcolare la somma di ciascuna colonna e veriﬁcare che ciascun risultato sia pari al
doppio di quello della colonna precedente. Se tutte le veriﬁche danno esito positivo
venga visualizzato un unico Sì, altrimenti un unico NO. */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define R 3
#define C 4

int main () {
FILE *fp;
int i,j,flag = 1;
char nomefile[50];
float matrice[R][C];
float somma[C];
/*printf("Digita il nome del file:");
scanf("%49s", nomefile);*/

//fp = fopen(nomefile, "r");
fp = fopen("matrice_es6.txt", "r");
if(fp == NULL){
    printf("ERRORE: file non trovato.\n");
    return -1;
}

for(i = 0; i < R; i++){
    for(j = 0; j < C; j++){
        fscanf(fp,"%f", &matrice[i][j]);

    }
}
fclose(fp);
for(i = 0; i < C;i++){
    somma[i] = 0.0;
    for(j = 0; j < R; j++){
        somma[i] += matrice[j][i];
    }
}

for(j = 1; j < C;j++){
    if(fabs(somma[j] - 2*somma[j-1]) > 0.0001){
        flag = 0;
        break;

    }

}


if(flag == 1){
    printf("SI\n");
}else {
    printf("NO\n");
}


return 0;
}
