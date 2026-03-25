/* Dato un file con una mrice Rx C di interi, stampare le coordinate delle celle non
di bordo le cui 8 celle adiacenti hanno tutte lo stesso valore */

#include <stdio.h>
#include <stdlib.h>
#define R 5
#define C 5

int main () {
FILE *fp;
int i,j,k,l;
char nomefile[50];
int m[R][C];
int primoVicino;
int tuttiUguali;
// APERTURA FILE
printf("Inserisci il nome del file:");
scanf("%s",nomefile);

fp = fopen(nomefile,"r");

if(fp == NULL){
    printf("ERRORE: file non trovato\n");
    return -1;
}
printf("File aperto e pronto alla lettura\n");
// Aggiunta valori alla m

for(i=0;i<R;i++){

    for(j=0;j<C;j++){
        fscanf(fp,"%d",&m[i][j]);

    }
}
fclose(fp);
for(i = 0;i<R;i++){
    printf("\n");
    for(j=0;j<C;j++){
        printf("%d ",m[i][j]);
    }

}
printf("\n Celle che hanno i vicini tutti uguali tra loro: ");

for (i=1;i<R-1;i++){
    for(j=1;j<C-1;j++){
     primoVicino = m[i-1][j-1];
     tuttiUguali = 1;
     for(l= -1;l<=1;l++){
        for(k=-1;k<=1;k++){
            if(l == 0 && k == 0){
                continue;
            }
            if(m[i+l][j+k] != primoVicino){
                tuttiUguali = 0;
            }
        }
     }
    if(tuttiUguali == 1){
        printf("%d %d\n",i,j);
    }
}
}

return EXIT_SUCCESS;
}
