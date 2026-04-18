/* ESERCIZIO 10 (Tipo: File - Codiﬁca Morse)
Un ﬁle di testo denominato Morse.txt contiene la codiﬁca in alfabeto Morse delle 26
lettere dell'alfabeto e delle 10 cifre. Ogni riga contiene una lettera o cifra, uno spazio e
la codiﬁca in codice Morse (da 1 a 5 caratteri, ciascuno può essere '.' o '-'). Vedere
esempio sotto. L'alfabeto Morse non fa distinzione tra le maiuscole e le minuscole.

Si scriva un programma C89 che apra un ﬁle di testo (il cui nome venga richiesto
all'utente) e lo traduca in codice Morse, salvandolo in un altro ﬁle (il cui nome venga
richiesto all'utente). Le lettere/cifre di una parola/numero vengono scritte convertite
separate da UNO spazio. Le parole da TRE spazi. I caratteri non-lettera e non-cifra
vengano semplicemente ignorati (quindi anche i ritorni a capo).*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MORSE 36
#define RIGA 100

int main () {
FILE *fp_morse, *fp_input, *fp_output;
int i,j, indice, k,c;
char morse[36][6];
char nomefile_morse[50], nomefile_input[50], nomefile_output[50];
char riga[RIGA];
char simbolo;
printf("Digita nome del file contenente codice morse:");
scanf("%49s", nomefile_morse);
fp_morse = fopen(nomefile_morse, "r");
if(fp_morse == NULL){
    printf("ERRORE: impossibile trovare il file.\n");
}
printf("File aperto correttamente.\n");

printf("Digita nome del file da convertire in codice morse:");
scanf("%49s", nomefile_input);
fp_input = fopen(nomefile_input, "r");
if(fp_input == NULL){
    printf("ERRORE: impossibile trovare il file.\n");
}
printf("File aperto correttamente.\n");

printf("Digita nome del file in cui salvare il testo in codice morse:");
scanf("%49s", nomefile_output);

fp_output = fopen(nomefile_output, "w");
if(fp_output == NULL){
    printf("ERRORE: impossibile trovare il file.\n");
}
printf("File aperto correttamente.\n");


for(i = 0; i < MORSE;i++){
    fgets(riga, RIGA, fp_morse);
    simbolo = riga[0];

    if(simbolo >= 'A' && simbolo <= 'Z'){
        indice = simbolo -'A';
    } else{
        indice = 26 +(simbolo - '0');
    }
    j = 2;
    k = 0;

    while(riga[j] != '\n' && riga[j] != '\0'){
        morse[indice][k] = riga[j];
        j++;
        k++;
    }
    morse[indice][k] = '\0';
}
fclose(fp_morse);

while((c = fgetc(fp_input)) != EOF){
    c = toupper(c);

    if(c >= 'A' && c <= 'Z'){
        fprintf(fp_output, "%s ", morse[c-'A']);
    }else if (c >= '0' && c <= '9'){
        fprintf(fp_output, "%s ", morse[26+ (c -'0')]);
    }else if (c == ' '){
        fprintf(fp_output, "   ");
    }
}
fclose(fp_input);
fclose(fp_output);
return 0;
}
