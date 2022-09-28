/*
Esercizio 3 (max 26 punti) -
Scrivere un programma in C che permetta di leggere da tastiera n numeri interi (con n scelto dall’utente) e di caricarli in un array. Il programma dovrà inoltre:
1-	Eseguire le opportune verifiche sulla dimensione dell’array
2-	Modificare l’array originale invertendo la sequenza degli elementi (vedi esempio)

Esempio: 	array originale 	-> 	3, 5, 1, 9, 7
		array modificato 	->	7, 9, 1, 5, 3

3-	Stampare l’array così modificato a video
4-	Creare un nuovo array che contenga gli elementi dell’array originale il cui valore sia maggiore della media (calcolata sull’array originale).
*/


#include <stdio.h>
#define N 10

int main() {
    int v[N],w[N];
    int i,j,tmp,n;
    float media=0;

    printf("\nQuanti elementi vuoi inserire? (max %d): ",N);
    scanf("%d",&n);
    while(n>N || n<1) {
      printf("\nInserisci un numero corretto (max %d): ",N);
      scanf("%d",&n);
    }

    printf("\nRiempi il vettore: ");
    for(i=0;i<n;i++) {
      printf("\nElemento %d: ",i+1);
      scanf("%d",&v[i]);
      media=media+v[i];
    }
    media=media/n;

    for(i=0,j=n-1;i<j;i++,j--) {
        tmp=v[i];
        v[i]=v[j];
        v[j]=tmp;
    }

    printf("\nVettore invertito: ");
    for(i=0;i<n;i++)
        printf("%d ",v[i]);

    j=0;
    for(i=0;i<n;i++) {
      if(v[i]>media) {
        w[j]=v[i];
        j++;
      }
    }

    printf("\nNuovo vettore con elementi > media (%.1f): ",media);
    for(i=0;i<j;i++)
        printf("%d ",w[i]);

    return 0;
}
