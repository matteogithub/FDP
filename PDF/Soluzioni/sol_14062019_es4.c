/*
Scrivere un programma in C che permetta (tramite chiamate ad una
specifica funzione) di inserire in due array N
numeri interi (gli array avranno la stessa lunghezza, N).
Il programma dovrà successivamente visualizzare i due array (tramite la chiamata
ad una specifica funzione).
Infine, il programma dovrà creare una lista concatenata lineare - di dimensione
pari alla lunghezza degli array - i cui elementi contengano due numeri interi.
Per ogni elemento della lista concatenata, il primo numero intero indicherà
la posizione dell’elemento all’interno della lista mentre il secondo numero
intero assumerà il valore 1 se i corrispondenti valori degli array sono uguali
o il valore 0 se i corrispondenti valori degli arrays sono diversi.

	Esempio:
	array1: 1, 2, 3, 2
 	array2: 4, 2, 6, 2
	lista: (1,0) (2,1) (3,0) (4,1)
*/

#include <stdio.h>
#include <stdlib.h>
#define DIM 100

struct valori {
    int num;
    int pos;
    struct valori *next;
};

void carica_array(int *,int);
void visualizza_array(int *,int);
struct valori *inser_lista(struct valori *,int,int);
void visualizza_lista(struct valori *);

int main() {
    int n,a1[DIM],a2[DIM],i;
    struct valori *lista=NULL;

    printf("Carica due array di dimensione N");
    printf("\nDefinisci N: ");
    do {
        scanf("%d", &n);
    } while(n<1 || n>DIM);

    printf("\nRiempi il primo array...");
    carica_array(a1,n);
    printf("\nRiempi il secondo array...");
    carica_array(a2,n);
    printf("\nPrimo array...");
    visualizza_array(a1,n);
    printf("\nSecondo array...");
    visualizza_array(a2,n);

    for(i=0;i<n;i++)
    {
        if(a1[i]==a2[i]) lista=inser_lista(lista,1,i);
        else lista=inser_lista(lista,0,i);
    }
    printf("\nLista: ");
    visualizza_lista(lista);
}

void carica_array(int *a,int n) {
    int i;

    for(i=0;i<n;i++) {
        printf("\nInserisci elemento di indice %d ",i);
        scanf("%d",a+i);
    }
}

void visualizza_array(int *a,int n) {
    int i;

    for(i=0;i<n;i++) {
        printf("\nElemento di indice %d ",i);
        printf("%d",*(a+i));
    }
}

struct valori *inser_lista(struct valori *p, int val, int ind) {
    struct valori *p1,*paux;

    p1=(struct valori *)malloc(sizeof(struct valori));
    p1->num=val;
    p1->pos=ind+1;
    if(p==NULL) {
        p=p1;
        p->next=NULL;
    }
    else {
        p1->next=NULL;
        paux=p;
        while(paux->next!=NULL) paux=paux->next;
        paux->next=p1;
    }
    return p;
}

void visualizza_lista(struct valori *p) {
    while(p!=NULL) {
        printf("%d %d; ",p->pos, p->num);
        p=p->next;
    }
}
