/*Un file matrice.txt contiene una matrice di valori float di dimensioni 12 × 10.
Stampare a video le coordinate (r, c) di ciascuna cella che abbia valore minore
delle celle immediatamente sopra, sotto, a destra e a sinistra
e che sia maggiore della media di tutte le celle della matrice.*/

 #include <stdio.h>
 #include <stdlib.h>
 #define R 12
 #define C 10

 int main () {
 FILE *fp;
 int i,j, trovato = 0;
 float riga_media, media;
 float matrice [R][C];
 float minore;
 float riga_somma = 0;
 float tot_somma = 0;

 fp=fopen("matrice5.txt", "r");
 if(fp == NULL) {
    printf("ERRORE: File non aperto correttamente.\n");
    return -1;
 }
 printf("Il file matrice5.txt è stato aperto correttamente.\n");

for (i = 0; i< R;i++){
    for(j = 0; j < C; j++){
        fscanf(fp, "%f", &matrice[i][j]);
    }
}

// Inserimento valori nella matrice + somma righe
printf("Valori salvati nella matrice.\n");
for (i = 0; i< R;i++){
    riga_somma = 0;
    for(j = 0; j < C; j++){
        printf("%.2f  ", matrice[i][j]);
        riga_somma += matrice[i][j];
    }
    printf("\n");
    tot_somma += riga_somma;
}
printf("Totale somma righe %.2f\n", tot_somma);
fclose(fp);

//Calcolo MEDIA
media = tot_somma / (R*C);

//Troviamo valore
for(i = 1; i < (R-1); i++){
    for(j = 1; j <(C-1); j++){
        if((matrice[i][j] < matrice[i-1][j]) &&
           (matrice[i][j] < matrice[i+1][j]) &&
           (matrice[i][j] < matrice[i][j-1]) &&
           (matrice[i][j] < matrice[i][j+1])  &&
           (matrice[i][j] > media)){
            printf("(%d, %d), -> %.2f\n", i,j,matrice[i][j]);
            trovato = 1;
        }
    }

}
if(!trovato){
    printf("Nessuna cella soddisfa le condizioni.\n");
}
 return 0;
 }
