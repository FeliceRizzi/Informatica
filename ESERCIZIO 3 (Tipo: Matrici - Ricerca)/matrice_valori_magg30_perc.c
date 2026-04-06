/* ESERCIZIO 3 (Tipo: Matrici - Ricerca)
Un ﬁle contiene una matrice di RxC numeri interi con R e C noti a priori (#deﬁne)
separati da spazi.
Si scriva un programma C89 che determini il valore medio di tutte le celle e stampi a
video le coordinate (r, c) delle celle con valori minori o uguali al 30% di questo valore.*/

#include <stdlib.h>
#include <stdio.h>
#define R 5
#define C 5

int main () {
FILE *fp;
int i,j, somma = 0, totale = 0;
float media, soglia;
char nomefile[50];
char matrice[R][C];
printf("Inserisci il nome del file:");
scanf("%49s", nomefile);

fp = fopen(nomefile, "r");

if(fp == NULL){
    printf("ERRORE: file non trovato\n");
    return -1;
}

printf("File aperto correttamente.\n");

for (i = 0; i < R;i++){
    for(j = 0; j < C;j++){
    fscanf(fp, "%d", &matrice[i][j]);
    }
}

for(i = 0; i < R; i++){
    somma = 0;
    for(j = 0; j < C; j++){
        somma = somma + matrice[i][j];
    }
    totale = somma + totale;
}

media = (float)totale / (R*C);
soglia = media * 0.3;

for(i = 0;i< R; i++){
    for(j = 0; j < C; j++){
        if ( matrice[i][j] <= soglia){
            printf("Coord: %d %d\n", i, j);
        }
    }
}


return 0;
}


