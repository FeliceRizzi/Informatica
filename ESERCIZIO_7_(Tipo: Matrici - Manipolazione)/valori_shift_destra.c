/*ESERCIZIO 7 (Tipo: Matrici - Manipolazione)
Un ﬁle denominato matrice.txt contiene una matrice di valori ﬂoat di dimensioni 10x15
(#deﬁne).Traslare a destra di 1 posizione tutte e sole le righe di indice pari
(in Informatica lo 0 è considerato pari).
I valori che fuoriescono vengano riportati nello stesso ordine dall'altra parte.*/

#include <stdlib.h>
#include <stdio.h>
#define R 10
#define C 15

int main (){
FILE *fp;
int i, j;
float matrice[R][C];
char nomefile[50];
float temp;

printf("Digita il nome del file:");
scanf("%49s", nomefile);
fp = fopen(nomefile, "r");

if(fp == NULL){
    printf("ERRORE: file non trovato.\n");

    return -1;
}

for(i = 0; i < R;i++){
    for(j = 0; j < C;j++){
        fscanf(fp, "%f", &matrice[i][j]);
        printf("%.1f ", matrice[i][j]);
    }
    printf("\n");
}
fclose(fp);

for(i=0; i < R;i+=2){
    temp=matrice[i][C-1];
    for(j = C -1; j > 0;j--){
            matrice[i][j] = matrice[i][j-1];

    }
    matrice[i][0] = temp;;
}

printf("\n-----MATRICE DOPO TRASLAZIONE -----\n");
for(i = 0; i < R;i++){
    for(j = 0;j< C;j++){
        printf("%6.2f ", matrice[i][j]);
    }
    printf("\n");
}



return 0;
}
