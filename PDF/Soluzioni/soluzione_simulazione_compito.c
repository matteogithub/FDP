#include <stdio.h>
#include <stdlib.h>
#define DIM 10
struct lista {
    int val;
    int idx;
    struct lista *next;
};
void carica_array(int, int *);
void vis_array(int,int *);
struct lista *ins_lista(struct lista *,int,int);
void vis_lista(struct lista *);
int verifica_presenza(int,struct lista *);

int main() {
    int v1[DIM];
    int v2[DIM];
    int n,i,flag;
    struct lista *p=NULL;

    do {
        printf("Dimensione array: ");
        scanf("%d",&n);
    } while(n<1 || n>DIM);
    carica_array(n,v1);
    vis_array(n,v1);
    carica_array(n,v2);
    vis_array(n,v2);
    for(i=0;i<n;i++){
        if( *(v1+i) == *(v2+i) ){
            flag=verifica_presenza(*(v1+i),p);
            if (flag==0) p=ins_lista(p,i,*(v1+i));
        }
    }
    if(p!=NULL){
        printf("\nLista: ");
        vis_lista(p);
    }
    return 0;
}

void carica_array(int n, int *v){
    int i;
    for(i=0;i<n;i++){
        printf("\nElemento: ");
        scanf("%d",v+i);
    }
}

void vis_array(int n, int *v){
    int i;
    for(i=0;i<n;i++)
        printf("%d ",*(v+i));
}

struct lista *ins_lista(struct lista *p, int ind, int val){
    struct lista *p1,*paux;
    p1=(struct lista *)malloc(sizeof(struct lista));
    p1->idx=ind;
    p1->val=val;
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

void vis_lista(struct lista *p){
    while(p!=NULL){
        printf("%d,%d ",p->val,p->idx);
        p=p->next;
    }
}

int verifica_presenza(int v, struct lista *p){
    int c=0;
    while(p!=NULL){
        if(p->val == v) c++;
        p=p->next;
    }
    return c;
}
