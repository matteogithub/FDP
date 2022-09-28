#include <stdio.h>
#define N 5 //dim max array

int check_crescente(int *,int,int);
void mostra_arr(int *,int);

int main() {
    int v[N],i,val;

    for(i=0;i<N;i++) {
        scanf("%d",&val); //leggo da tast il valore

        if(check_crescente(v,i,val)==1) {
            v[i]=val; //viene inserito
            printf("valore inserito...\n");
        } else {
            i--;
            printf("valore NON inserito...\n");
        }

    }

    printf("\nArray: ");
    mostra_arr(v,N);
    return 0;
}

int check_crescente(int *v,int n,int val) {
    int check=0;
    if(n>0) {
        if(*(v+n-1)<val) check=1;
    } else check=1;
    return check;
}

void mostra_arr(int *v,int n) {
    int i;
    for(i=0;i<n;i++) printf("%d ",*(v+i));
}
