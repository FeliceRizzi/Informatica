/*ESERCIZIO 2 (Tipo: Matrici - Ricerca)
Un ﬁle contiene una matrice di RxC numeri interi con R e C noti a priori (#deﬁne)
separati da spazi. Si scriva un programma C89 che identiﬁchi le celle di valori negativi, circondate da 8
numeri positivi. Visualizzare le coordinate (r, c) di queste celle. */

#include <stdio.h>
#include <stdlib.h>
#define N 5
int main () {
FILE *fp;
int i,j;
char nomefile[50];
int matrice[N][N];

printf("Digita il nome del file:");
scanf("%49s", nomefile);

fp = fopen(nomefile, "r");

if(fp == NULL){
    printf("ERRORE: impossibile aprire il file.\n");
    return -1;
}
printf("File %s aperto correttamente.\n", nomefile);

for(i = 0; i< N; i++){
    for ( j = 0; j <N;j++){
        fscanf(fp, "%d", &matrice[i][j]);
    }
}
fclose(fp);

for(i = 1;i < N - 1; i++){
    for(j = 1; j < N - 1; j++){

        if(matrice[i][j] < 0){
            if((matrice[i-1][j-1] > 0) &&
               (matrice[i-1][j]   > 0) &&
               (matrice[i-1][j+1] > 0) &&
               (matrice[i][j+1]   > 0) &&
               (matrice[i+1][j+1] > 0) &&
               (matrice[i+1][j]   > 0) &&
               (matrice[i+1][j-1] > 0) &&
               (matrice[i][j-1]   > 0)){
                printf("Coord: %d %d\n", i, j);
                    }
                }
            }
        }
return 0;
}


