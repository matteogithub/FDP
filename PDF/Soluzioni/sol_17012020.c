#include <stdio.h>
#include <stdlib.h>
#define DIMSOURCE 10 //usato per creare il file - non richiesto nel compito
#define N 50

struct list {
    int val;
    int pos;
    struct list *next;
};

void show_array(int *,int);
int check_single(int *, int, int);
struct list *copy_to_list(struct list *, int, int);
void show_list(struct list *);
void copy_array(int *, int*, int);
void ord_array(int *, int);
int search_pos(int, int *, int);

int main() {
    int source[DIMSOURCE]={3,4,2,1,7,6,2,4,0,0}; //usato per creare il file - non richiesto nel compito
    int v_raw[N],v_ord[N];
    FILE *fp;
    int i,j=0,tmp,pos=0;
    struct list *pl=NULL;

    //scrittura del file - non richiesto nel compito
    printf("\nScrivo file...");
    fp=fopen("/Users/matteofraschini/Downloads/nums.txt","w");
    for(i=0;i<DIMSOURCE;i++)
        fprintf(fp,"%d ",source[i]);
    fclose(fp);
    printf("\nFile scritto con successo.\n");
    //fine scrittura del file - non richiesto nel compito

    fp=fopen("/Users/matteofraschini/Downloads/nums.txt","r");
    if(fp!=NULL)
    {
        printf("\nFile aperto. Valori presenti nel file: ");
        while(feof(fp)==0 && j<N) {
            fscanf(fp,"%d ",&tmp);
            printf("%d ", tmp);
            if(check_single(v_raw,tmp,j)==1) {
                v_raw[j]=tmp;
                j++;
            }
        }
        printf("\nArray caricato con %d elementi singoli (non duplicati) letti dal file:\n",j);
        show_array(v_raw,j);
        printf("\nArray ordinato:\n");
        copy_array(v_raw,v_ord,j);
        ord_array(v_ord,j);
        show_array(v_ord,j);
        for(i=0;i<j;i++) {
            pos=search_pos(v_raw[i],v_ord,j);
            pl=copy_to_list(pl,v_raw[i],pos);
        }
        if(pl!=NULL) {
            printf("\nLista (valore - posizione nell'array ordinato): \n");
            show_list(pl);
        }
    }
    else printf("\nFile insesistente!");
    return 0;
}

void show_array(int *v, int n) {
    int i;

    for(i=0;i<n;i++) {
        printf("Numero %d in posizione %d\n",*(v+i),i+1);
    }
}

int check_single(int *v, int val, int n) {
    int check=1, i;

    for(i=0;i<n;i++)
        if(*(v+i)==val)
            check=0;
    return check;
}

struct list *copy_to_list(struct list *p, int val, int pos) {
    struct list *p1,*paux;
    p1=(struct list *)malloc(sizeof(struct list));
    p1->val=val;
    p1->pos=pos;
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

void show_list(struct list *p) {
    while(p!=NULL) {
        printf("%d - %d \n",p->val,p->pos);
        p=p->next;
    }
}

void copy_array(int *v, int *w, int n) {
    int i;
    for(i=0;i<n;i++)
        *(w+i)=*(v+i);
}

void ord_array(int *v, int n) {
    int i,j,tmp;

    for(i=0;i<n-1;i++)
        for(j=0;j<n-1;j++)
            if(*(v+j)>*(v+j+1)) {
                tmp=*(v+j);
                *(v+j)=*(v+j+1);
                *(v+j+1)=tmp;
            }
}

int search_pos(int val, int *v, int n) {
    int pos,i;

    for(i=0;i<n;i++)
        if(*(v+i)==val) pos=i+1;
    return pos;
}


