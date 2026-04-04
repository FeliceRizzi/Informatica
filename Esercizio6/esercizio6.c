/* Un file di lunghezza ignota, il cui nome viene richiesto all'utente, contiene un testo
senza punteggiatura composto da più righe di soli caratteri alfabetici.
Cifrare il testo parola per parola e scrivere il risultato in output.txt,
mantenendo la stessa struttura (spazi, ritorni a capo) e convertendo tutto in minuscolo.
La cifratura scambia le lettere a coppie partendo da sinistra;
se la parola ha un numero dispari di caratteri l'ultimo non viene scambiato.
Esempio: ciao a voi tutti → icoa a oiv uttti.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 200

int main () {
FILE *fp, *fo;
int i,j,k, len;
char parola_cifrata;
char nomefile[50];
char testo[N];
char parola[N];
char temp;

printf("Inserisci il nome del file da aprire:");
scanf("%s",nomefile);

fp= fopen(nomefile, "r");
if(fp == NULL){
    printf("ERRORE: file non trovato.\n");

    return EXIT_FAILURE;
}

printf("File aperto correttamente.\n");
//Creazione del file
fo = fopen("output.txt", "w");
if(fo == NULL){
    printf("ERRORE: impossibile creare il file output.txt");
return EXIT_FAILURE;
}
printf("File output.txt creato correttamente.\n");

while(fgets(testo,N,fp)){
    printf("DEBUG: letto riga %s", testo);
    // Conversione riga in minuscolo
    for(i = 0; testo[i]!= '\0';i++){
    testo[i] = tolower(testo[i]);
    }
    printf("DEBUG: Dopo minuscolo %s", testo);
//Estrazione parola (fino a spazio o fine riga)
i = 0;
while(testo[i] != '\0'){

//Caso 1 spazio
if(testo[i] == ' '){
    fprintf(fo," ");
    i++;
    continue;
}//Caso 2 a capo
if(testo[i] == '\n'){
    fprintf(fo,"\n");
    i++;
    continue;
} // Caso 3 fine riga
j = 0;
while (testo[i] != ' ' && testo[i] != '\n' && testo[i] != '\0'){
    parola[j] = testo[i];
    i++;
    j++;
}
parola[j] = '\0';

len = strlen(parola);

if(len % 2 == 0){
    for(k=0;k<len;k+=2){
    temp = parola[k];
    parola[k] = parola[k+1];
    parola[k+1] = temp;
    }
} else {
    for(k = 0; k< len -1; k+=2){
    temp = parola[k];
    parola[k] = parola[k+1];
    parola[k+1] = temp;

    }

}
fprintf(fo, "%s", parola);
}
}
return 0;
}
