#include <stdio.h>
#include <stdlib.h>
#define N 10
struct my_elem{
    int val;
    struct my_elem *next;
};
void carica(int *, int);
void stampa(int *, int);
struct my_elem *inserisci(struct my_elem *, int);
void stampa_lista(struct my_elem *);
void libera(struct my_elem *);
void calcola(int *,int,int *,int *);

int main() {
    int v[N],n,i,mini,maxi;
    struct my_elem *lista=NULL;
    do{
        printf("\nDimensione array: ");
        scanf("%d",&n);
    }while(n>N || n<1);
    carica(v,n);
    printf("\nArray: ");
    stampa(v,n);
    for(i=0;i<n;i++)
        if(v[i]%2==0) lista=inserisci(lista,v[i]);
    if(lista!=NULL) stampa_lista(lista);
    if(lista!=NULL) libera(lista);
    calcola(v,n,&mini,&maxi);
    printf("\nIl max in V: %d",maxi);
    printf("\nIl min in V: %d",mini);
    return 0;
}
void carica(int *v, int n){
    int i;
    for(i=0;i<n;i++){
        printf("\nInserisci elemento: ");
        scanf("%d",v+i);
    }
}
void stampa(int *v, int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ",*(v+i));
    }
}
struct my_elem *inserisci(struct my_elem *p, int val){
    struct my_elem *p1,*paux;
    p1=(struct my_elem *)malloc(sizeof(struct my_elem));
    p1->val=val;
    p1->next=NULL;
    if(p==NULL){
        p=p1;
    } else {
        paux=p;
        while(paux->next!=NULL) paux=paux->next;
        paux->next=p1;
    }
    return p;
}
void stampa_lista(struct my_elem *p){
    printf("\nLista: ");
    while(p!=NULL){
        printf("%d ",p->val);
        p=p->next;
    }
}
void calcola(int *v,int n,int *x,int *y){
    int i;
    *x=*(v);
    *y=*(v);
    for(i=0;i<n;i++){
        if(*(v+i)>*y) *y=*(v+i);
        if(*(v+i)<*x) *x=*(v+i);
    }
}
void libera(struct my_elem *p){
    struct my_elem *paux;
    while(p!=NULL) {
        paux=p;
        p=p->next;
        free(paux);
    }
}
