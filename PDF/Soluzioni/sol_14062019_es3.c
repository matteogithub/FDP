/*
Scrivere un programma in C che prenda in ingresso (da tastiera)
un numero intero positivo e restituisca (visualizzando a video)
il numero di cifre che compongono il valore inserito.
A tal fine è richiesto l’utilizzo di una specifica funzione.
	Esempio:
	Numero inserito: 524 – Lunghezza numero: 3
  Numero inserito: 1223 – Lunghezza numero: 4
*/
#include <stdio.h>
#include <math.h>

int check_length(int);

int main() {
    int n,l;
    printf("\nInput a positive integer: ");
    scanf("%d",&n);
    printf("\nThe number is: %d",n);
    l=check_length(n);
    printf("\nThe length of %d is: %d\n",n,l);
    return 0;
}

int check_length(int n) {
    int l=1;
    while(n>9){
        l++;
        n=n/10;
    }
    return l;
}
