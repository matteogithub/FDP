#include <stdio.h>
#include <stdlib.h>
#define DIM 10

struct list {
    int ind;
    int val;
    struct list *next;
};

void load_array(int *,int);
void show_array(int *, int);
int check_single(struct list *, int);
struct list * ins_list(struct list *, int, int);
void show_list(struct list *);

int main() {
    int v1[DIM];
    int v2[DIM];
    int n,i,check;
    struct list *p=NULL;

    do {
        printf("\nInsert array dimension: ");
        scanf("%d",&n);
    } while(n<1 || n>DIM);

    load_array(v1,n);
    show_array(v1,n);
    load_array(v2,n);
    show_array(v2,n);

    for(i=0;i<n;i++) {
        if(*(v1+i) == *(v2+i)) {
            check=check_single(p,*(v1+i));
            if(check == 0) p=ins_list(p,i,*(v1+i));
        }
    }

    printf("\nList: ");
    show_list(p);
    return 0;
}

void load_array(int *v, int n) {
    int i;

    for(i=0;i<n;i++) {
        printf("\nElelemt: ");
        scanf("%d",v+i);
    }
}

void show_array(int *v, int n) {
    int i=0;
    for(i=0;i<n;i++)
        printf("%d ",*(v+i));
}

int check_single(struct list *l, int val) {
    int count=0;

    while(l!=NULL) {
        if(val == l->val) count++;
        l=l->next;
    }
    return count;
}

struct list * ins_list(struct list *p, int ind, int val) {
    struct list *p1,*paux;
    p1=(struct list *)malloc(sizeof(struct list));
    p1->ind=ind;
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

void show_list(struct list *p) {
    while(p!=NULL) {
        printf("(%d,%d)",p->ind,p->val);
        p=p->next;
    }
}

