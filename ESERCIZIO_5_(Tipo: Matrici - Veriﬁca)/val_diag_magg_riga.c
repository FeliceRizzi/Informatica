/*ESERCIZIO 5 (Tipo: Matrici - Veriﬁca)
Un ﬁle denominato matrice.txt contiene una matrice di valori ﬂoat di dimensioni NxN
(con N deﬁnito tramite #deﬁne).
Si scriva un programma C89 che veriﬁchi se per ogni riga, il valore dell'elemento sulla
diagonale principale è maggiore o uguale alla somma degli altri valori sulla stessa riga.
L'output deve essere un unico Sì o NO.*/

#include <stdio.h>
#include <stdlib.h>
#define N 3

int main () {
FILE *fp;
int i,j,k,l, flag = 1;
float val_diag, somma = 0;
float matrice[N][N];
char nomefile[50];

printf("Inserisci il nome del file:");
scanf("%49s", nomefile);

fp = fopen(nomefile, "r");

if(fp == NULL){
    printf("ERRORE: impossibile aprire il file.\n");
    return -1;
}

for(i= 0; i< N;i++){
    for(j = 0; j < N;j++){
        fscanf(fp, "%f", &matrice[i][j]);
    }
}
fclose(fp);


for(i = 0; i <N;i++){
    somma = 0.0;

    for(j = 0; j<N;j++){
        if(j != i){
            somma += matrice[i][j];
        }
    }
    if(matrice[i][i] < somma){
        flag = 0;
        break;
    }
}

if (flag == 1){
    printf("SI.\n");
}else{
    printf("NO.\n");
}

return 0;
}
