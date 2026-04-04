

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define R 3
#define C 4
#define N 200

int main() {
int i,j, soglia, count;
float m21[R][C];
float m22[R][C];
int matrice [R][C];
char nomefile1[50];
char nomefile2[50];
FILE *fp1, *fp2;
float diff;

printf("Inserisci il nome del file:");
scanf("%s", nomefile1);
fp1 = fopen(nomefile1,"r");
if(fp1 == NULL){
    printf("ERRORE: file non trovato.\n");
    return -1;
}
printf("Aperto file %s\n", nomefile1);

for(i = 0; i<R;i++){
    for(j = 0; j<C;j++){
     fscanf(fp1, "%f",&m21[i][j]);

    }
}
fclose(fp1);

printf("Inserisci il nome del secondo file:");
scanf("%s",nomefile2);

fp2 = fopen(nomefile2,"r");

if(fp2 == NULL){
    printf("ERRORE: impossibile aprire il file %s\n", nomefile2);
    return -1;
}

for(i = 0; i< R;i++){
    for(j = 0; j<C;j++){
        fscanf(fp2,"%f", &m22[i][j]);
    }
}
fclose(fp2);

count = 0;

for(i = 0; i<R;i++){

    for(j = 0; j<C;j++){
        diff = m22[i][j] - m21[i][j];

        if(m22[i][j] >= 1.0){
            matrice[i][j] = 1;
            count++;
        }
        if(diff <= -1.0){
            matrice[i][j] = -1;
            count++;
        }
        else{
            matrice[i][j] = 0;
        }

        }
    }

soglia = (R * C * 70 + (100 - 1)) / 100;

if(count >= soglia){
    printf("Temperatura aumentata.\n");

} else {
    printf("Temperatura non aumentata.\n");
}





return 0;
}
