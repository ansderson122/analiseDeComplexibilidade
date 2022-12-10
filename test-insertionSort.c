#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.c"
#include "ordenacao.h"

void *testInsertionSort(int *i[2]){
	clock_t tempo,aux; 
    int* vetor = criaVetor(*i[0]);
    tempo = clock();
    insertionSort(vetor, *i[0]);
    tempo = clock() - tempo;
    *i[1] += tempo;
    free(vetor);    
}

int main(void){
	clock_t aux = 0;
    printf("Teste para o InsertionSort\n\n");
    int i,j,*entrada[2],tempos[10];
    for(i = 10; i <= 1000000; i=i*10){
        printf("Vetor tamanho %d:\n",i);
		entrada[0] = &i;
		
        for(j = 0; j < 10; j++){
        	tempos[j] = 0;
			entrada[1] = &tempos[j];
        	testInsertionSort(entrada);           
        }
		
		
		printf("Os tempos de execucao foram:");
		imprimeVetor(tempos, 10); 		
    	aux = media(tempos,10);
        printf("\nTempo medio de execucao: %lf milissegundos\n\n", ((double)aux)/((CLOCKS_PER_SEC/1000)));
        aux = 0;
		
		
    }

    return 1;
}
