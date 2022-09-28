#include <stdio.h>
#define DIM 10
void show_array(int *, int);
int del_element(int *, int, int);

int main() {
    FILE *fp;
    int v_tofile[5]={1,2,3,4,5};
    int v[DIM];
    int i,pos;

    fp=fopen("14022020a.txt","w");
    for(i=0;i<5;i++)
        fprintf(fp,"%d ",v_tofile[i]);
    fclose(fp);

    fp=fopen("14022020a.txt","r");
    if(fp!=NULL) {
        i=0;
        while(feof(fp)==0 && i<=DIM) {
            fscanf(fp,"%d ",&v[i]);
            i++;
        }
        show_array(v,i);
        do {
            printf("\nPosition element to del: ");
            scanf("%d",&pos);
        } while(pos>i || pos<1);
        i=del_element(v,i,pos);
        show_array(v,i);
    }
    return 0;
}

void show_array(int *v, int n) {
    int i=0;
    for(i=0;i<n;i++)
        printf("%d ",*(v+i));
}

int del_element(int *v, int n, int pos) {
    int i;
    for(i=pos-1;i<n-1;i++)
        *(v+i)=*(v+i+1);
    return n-1;
}
