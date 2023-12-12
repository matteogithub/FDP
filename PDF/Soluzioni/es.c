/*
Esercizio 3 (max 30 punti). Scrivere un programma in C che:
1. permetta all’utente di inserire da tastiera le coordinate (x e y) di n punti, con n scelto dall’utente (max 10 punti).
2. stampi a video le coordinate di tutti i punti precedentemente inseriti (max 3 punti).
3. calcoli per ogni punto la distanza dall’origine (punto di coordinate 0,0) e successivamente:
	3.1 individui e stampi a video le coordinate del punto che ha la minima distanza dall’origine (max 5 punti);
	3.2 inserisca in una lista concatenata (dinamica) tutti i punti che hanno una distanza dall’origine maggiore 	alla media delle distanze (max 10 punti);
4. stampi a video le coordinate dei punti inseriti nella lista (max 2 punti).

Nota 1. In C è possibile estrarre la radice quadrata di un numero utilizzando la funzione sqrt() inclusa nella libreria math.h.
Nota 2. Il punteggio massimo è da riferirsi al caso in cui si faccia uso corretto delle funzioni.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define DIM 50

struct punto {
  int x;
  int y;
};

struct punto_lista {
  struct punto coord;
  struct punto_lista *next;
};

float calcola_dist(struct punto);
int calcola_min(float *,int);
float calcola_media(float *,int);
struct punto_lista *inser_lista(struct punto_lista *,struct punto);
void visualizza_lista(struct punto_lista *);

int main() {
  int n,i,min;
  struct punto punti[DIM];
  float dist[DIM],dist_media;
  struct punto_lista *lista=NULL;

  do {
    printf("Quanti punti vuoi inserire? \n");
    scanf("%d", &n);
  } while(n<1 || n>DIM);

  for(i=0;i<n;i++) {
    printf("Inserisci nuovo punto...\n");
    printf("Inserisci x: ");
    scanf("%d", &punti[i].x);
    printf("Inserisci y: ");
    scanf("%d", &punti[i].y);
  }

  printf("Punti inseriti...\n");
  for(i=0;i<n;i++) {
    printf("Punto #%d: %d,%d\n",i+1,punti[i].x,punti[i].y);
  }

  for(i=0;i<n;i++)
    dist[i]=calcola_dist(punti[i]);

  printf("\nDistanze...\n");
  for(i=0;i<n;i++)
    printf("%.1f ",dist[i]);

  min=calcola_min(dist,n);
  printf("Il punto con distanza minima ha coordinate %d, %d\n",punti[min].x,punti[min].y);

  dist_media=calcola_media(dist,n);
  printf("\nLa distanza media e': %.1f",dist_media);

  for(i=0;i<n;i++)
    if(dist[i]>dist_media) lista=inser_lista(lista,punti[i]);

  printf("\nPunti inseriti nella lista...\n");
  visualizza_lista(lista);
}

float calcola_dist(struct punto p) {
  float dist;
  dist=p.x*p.x+p.y*p.y;
  return sqrt(dist);
}

int calcola_min(float *v, int n) {
  int minv=*v,mini=0,i;
  for(i=0;i<n;i++)
    if(*(v+i)<minv) {
      minv=*(v+i);
      mini=i;
    }
return mini;
}

float calcola_media(float *v,int n) {
  float m=0;
  int i;
  for(i=0;i<n;i++)
    m+=*(v+i);
  return m/n;
}

struct punto_lista *inser_lista(struct punto_lista *p, struct punto punt) {
  struct punto_lista *p1,*paux;
  p1=(struct punto_lista *)malloc(sizeof(struct punto_lista));
  p1->coord.x=punt.x;
  p1->coord.y=punt.y;
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


void visualizza_lista(struct punto_lista *p) {
  while(p!=NULL) {
    printf("%d %d; ",p->coord.x,p->coord.y);
    p=p->next;
  }
}
