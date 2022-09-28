#include <stdio.h>
#include <stdlib.h>
#define N 10 //spazio alloc statica per l'array

struct lista { //nuovo tipo
    int val;
    struct lista *next;
};

void carica_arr(int *, int);
void mostra_arr(int *, int);

struct lista *crea_lista(int *, int);
void mostra_lista(struct lista *);

void elimina_el(int *, int, int);

int main() {
    int v[N],n,i;
    struct lista *p_lista;

    //dimensione dell'array
    do {
        scanf("%d",&n);
    } while(n<1 || n>N); //verifica la dim max e min

    //prima parte
    carica_arr(v,n); // v --> &v[0]
    printf("\nArray: ");
    mostra_arr(v,n);

    //seconda parte
    p_lista=crea_lista(v,n);
    printf("\nLista: ");
    mostra_lista(p_lista);

    //terza parte
    for(i=0;i<n;i++) {
        if(*(v+i)%2!=0) {
            elimina_el(v,i,n);
            n--;
            i--;
        }
    }
    printf("\nArray: ");
    mostra_arr(v,n);
    return 0;
}

void carica_arr(int *v, int n) {
    int i;
    for(i=0;i<n;i++) {
        scanf("%d",v+i);
    }
}

void mostra_arr(int *v, int n) {
    int i;
    for(i=0;i<n;i++) {
        printf("%d ",*(v+i));
    }
}

struct lista *crea_lista(int *v, int n) {
    struct lista *p,*paux;
    int i;
    p=(struct lista *)malloc(sizeof(struct lista));
    p->val=*(v);
    paux=p;
    for(i=1;i<n;i++) {
        paux->next=(struct lista *)malloc(sizeof(struct lista));
        paux=paux->next;
        paux->val=*(v+i);
    }
    paux->next=NULL;
    return p;
}

void mostra_lista(struct lista *p) {
    while(p!=NULL) {
        printf("%d ", p->val);
        p=p->next;
    }
}

void elimina_el(int *v, int pos, int n) {
    int i;
    for(i=pos;i<n;i++) *(v+i)=*(v+i+1);
}


