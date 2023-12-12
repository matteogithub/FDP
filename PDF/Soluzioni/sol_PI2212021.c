#include <stdio.h>
#include <stdlib.h>
#define N 10
struct my_list{
    int val;
    struct my_list *next;
};
void carica_pari(int *,int);
void stampa_array(int *,int);
struct my_list *inserisci(struct my_list *, int);
void stampa_lista(struct my_list *);
void libera_lista(struct my_list *);

int main(){
    int v[N],n,i;
    struct my_list *lista=NULL;

    do{
        printf("\nQuanti valori vuoi inserire? ");
        scanf("%d",&n);
    }while(n>N || n<1);
    carica_pari(v,n);
    stampa_array(v,n);
    for(i=0;i<n;i++)
        if(v[i]==i) lista=inserisci(lista,v[i]);
    if(lista!=NULL) stampa_lista(lista);
    if(lista!=NULL) libera_lista(lista);

    return 0;
}

void carica_pari(int *v,int n) {
    int i,num;
    i=0;
    while(i<n){
        printf("\nInserisci valore: ");
        scanf("%d",&num);
        if(num%2==0){
            *(v+i)=num;
            printf("\nValore inserito...");
            i++;
        } else printf("\nValore NON inserito...");
    }
}

void stampa_array(int *v,int n){
    int i;
    printf("\nArray: ");
    for(i=0;i<n;i++)
        printf("%d ",*(v+i));
}

struct my_list *inserisci(struct my_list *p, int num) {
    struct my_list *p1,*paux;
    p1=(struct my_list *)malloc(sizeof(struct my_list));
    p1->val=num;
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

void stampa_lista(struct my_list *p) {
    printf("\nLista: ");
    while(p!=NULL){
        printf("%d ",p->val);
        p=p->next;
    }
}

void libera_lista(struct my_list *p) {
    struct my_list *paux;
    while(p!=NULL) {
        paux=p;
        p=p->next;
        free(paux);
    }
}