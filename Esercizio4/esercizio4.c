/*Un file, il cui nome viene richiesto all'utente, contiene numeri interi; non è noto quanti siano, ma si
sa che al massimo i valori diversi sono 200 (#define). Calcolare la media float dei valori escludendo
ogni ripetizione (ogni valore contato una sola volta). Esempio: se il file contiene 8 6 4 6, il
programma restituisce la media di 8, 6 e 4. */

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int main () {
FILE *fp;
int i,j, flag = 0;
float media;
char nomefile[50];
int vett [MAX];
int val_unici[MAX];
int n_vett;
int n_unici = 0;
float somma = 0;


printf("Digita il nome del file da aprire:");
scanf("%s",nomefile);
fp=fopen(nomefile,"r");

if(fp == NULL){
    printf("ERRORE: file non trovato.\n");
    return -1;
}

printf("Il file %s è stato aperto correttamente.\n", nomefile);

n_vett= 0;

while(n_vett < MAX && fscanf(fp, "%d", &vett[n_vett]) == 1){
    n_vett++;
}
fclose(fp);

for(i=0;i<n_vett;i++){
    flag = 0;

        for(j= 0;j<n_unici;j++){
            if(vett[i] == val_unici[j]){
                flag = 1; // già controllato
                break;
            }
        }
        //Se non visto aggiungo a val_unici
    if (flag == 0){
        val_unici[n_unici] = vett[i];
        n_unici++;
    }
}

//Calcolo somma
for(i = 0; i< n_unici;i++){
    somma = somma + val_unici[i];
}
//Calcolo della media
if ( n_unici > 0){
    media = somma / n_unici;
    printf("La median dei valori unici trovati e' %.2f\n", media);
} else {
    printf("Nessun numero valido trovato.\n");
    }


return 0;
}
