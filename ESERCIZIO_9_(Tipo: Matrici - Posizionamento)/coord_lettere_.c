/*ESERCIZIO 9 (Tipo: Matrici - Posizionamento)
Un ﬁle di lunghezza ignota, il cui nome viene richiesto all'utente, contiene per ogni riga
le coordinate (due interi) seguite da un carattere alfabetico. L'elemento di coordinate
(0,0) si identiﬁca come la prima riga del ﬁle.

Scrivere un programma C89 che collochi nella matrice (di dimensioni deﬁnite tramite
#deﬁne) ciascuno dei caratteri alle coordinate corrispondenti. Se una coppia di
coordinate si riferisce a una cella che non fa parte della matrice, il programma deve
visualizzare quella riga preceduta da "ERRORE" e passare alla riga successiva.
Alla ﬁne stampare a video la matrice. */

#include <stdio.h>
#include <stdlib.h>
#define R 10
#define C 15

int main () {
FILE *fp;
int i, j;
char nomefile[50];
int riga, colonna;
char carattere;
char matrice[R][C];
printf("Digita il nome del file:");
scanf("%49s", nomefile);

fp = fopen(nomefile, "r");
if(fp == NULL){
    printf("ERRORE: Impossibile aprire il file.\n");
    return -1;
}

for(i = 0; i < R;i++){
    for(j = 0;j<C;j++){
        matrice[i][j] = '.';
    }
}

while(fscanf(fp, "%d %d %s", &riga, &colonna, &carattere)== 3){
    if(riga >= 0 && riga < R && colonna >= 0 && colonna < C) {
        matrice[riga][colonna] = carattere;
    } else {
        printf("ERRORE: %d %d %c\n", riga, colonna, carattere);
    }
}
fclose(fp);

for(i = 0; i < R;i++){
    for(j = 0; j < C;j++){
        printf("%c ", matrice[i][j]);
    }
    printf("\n");
}
return 0;
}
