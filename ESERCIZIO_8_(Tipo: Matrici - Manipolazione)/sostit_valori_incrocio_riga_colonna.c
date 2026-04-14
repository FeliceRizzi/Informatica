/*ESERCIZIO 8 (Tipo: Matrici - Manipolazione)
Un ﬁle denominato matrice.txt contiene una matrice di valori ﬂoat di dimensioni 10x15
(#deﬁne). Si scriva un programma in linguaggio C (C89) che PRIMA legga tutta la matrice e la
memorizzi e POI vada a sostituire i valori nelle celle che si trovano all'incrocio tra righe
dispari e colonne pari con il valor medio delle celle della colonna stessa. Le altre righe
e colonne non devono essere modiﬁcate.

NOTA: la prima riga e la prima colonna hanno indice 0 e quindi sono pari.*/

#include <stdio.h>
#include <stdlib.h>
#define R 10
#define C 15

int main () {
FILE *fp;
int i,j;
float matrice[R][C];
char nomefile[50];
float matrice_media_colonne[C];
float somma_col;
float media;
printf("Inserisci il nome del file:");
scanf("%49s", nomefile);

fp = fopen(nomefile, "r");

if (fp == NULL){
    printf("ERRORE: file non trovato.\n");
    return -1;
}

for(i = 0; i < R;i++){
    for(j = 0; j < C; j++){
        fscanf(fp, "%f", &matrice[i][j]);
    }
}

fclose(fp);

for(i = 0; i < C; i++){
    somma_col = 0.0;
    for(j = 0; j < R; j++){
        somma_col += matrice[j][i];
    }
    media = somma_col / R;
    matrice_media_colonne[i] = media;
}

for(i = 0; i < R; i++){
    for(j = 0; j < C; j++){
        if(i % 2 != 0 && j % 2 == 0){
            matrice[i][j] = matrice_media_colonne [j];
        }
        printf("%.1f ", matrice[i][j]);
    }
    printf("\n");
}









return 0;
}
