/*ESERCIZIO 4 (Tipo: Matrici - Veriﬁca)
Un ﬁle contiene una matrice di RxC numeri interi con R e C noti a priori (#deﬁne)
separati da spazi.
Si scriva un programma C89 che veriﬁchi se ogni cella contiene la somma dei valori
delle celle che la precedono a sinistra nella stessa riga. Il programma deve solo scrivere
a video VERIFICATO o NON VERIFICATO.*/

#include <stdio.h>
#include <stdlib.h>
#define R 5
#define C 5

int main () {
FILE *fp;
int i, j,k,l;
char nomefile[50];
int matrice[R][C];
int somma = 0;
int verificato = 1;
printf("Inserisci il nome del file:");
scanf("%49s", nomefile);

fp=fopen(nomefile, "r");

if(fp == NULL){
    printf("ERRORE: file non trovato.\n");
    return -1;
}

for (i = 0; i < R; i++){
    for(j = 0; j < C;j++){
        fscanf(fp, "%d", &matrice[i][j]);
    }
}
fclose(fp);

for (i = 0; i < R && verificato; i++){
    somma = 0;
    for(j = 0; j < C; j++){
        if(j >0){
            if(matrice[i][j] != somma){
                verificato = 0;
                break;
            }
        }
        somma +=matrice[i][j];
    }
}
if(verificato){
    printf("Verificato\n");
}else{
    printf("Non verificato.\n");
}

return 0;
}
