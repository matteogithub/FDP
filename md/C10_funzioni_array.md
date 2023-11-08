---
marp: true
---

<!-- footer: M. Fraschini - Università degli Studi di Cagliari - AA 2023-2024 -->

<!-- paginate: true -->

<!-- size: 4:3 -->


# C: Funzioni e Array


---

# Funzioni e Array

- E’ possibile passare ad una funzione il valore di un elemento di un array? **sì**

```C
nome_funzione(nome_array[indice]);
```

- E’ possibile passare ad una funzione un array? 
**sì**, **ma** occorre fare attenzione.

```C
nome_funzione(nome_array);
```
:point_right: Sto passando il puntatore al suo primo elemento!

---

# Esercizio
Scivere un programma in C che, attraverso l'uso di una funzione, calcoli il minimo di un array di interi


---

# Soluzione

```C
#include <stdio.h>
#define DIM 10

int calcola_minimo(int *, int);

int main() {
  int n,v[DIM],i,min;

  do  {
    printf("Inserisci dimensione array: \n");
    scanf("%d", &n);
  } while(n<1 || n>DIM);

  printf("Inserisci i %d elementi:\n",n);
  for(i=0;i<n;i++)  {
      printf("elemento di indice - %d : ",i);
      scanf("%d",&v[i]);
  }
```

---

# Soluzione

```C
  min=calcola_minimo(v, n);
  printf("\nIl minimo vale: %d\n", min);
}

int calcola_minimo(int *v, int n) {
  int i,min=*v;

  for(i=0;i<n;i++) {
    if(*(v+i)<min)
      min=*(v+i);
  }
  return min;
}
```

---

# Esercizio
Scrivere un programma in C che, attraverso l'uso di una funzione, permetta di calcolare la media degli elementi di un vettore

___

# Soluzione

```C
#include <stdio.h>
#define DIM 10

float calcola_media(int *, int);

int main() {
  int n,v[DIM],i;
  float media;

  do  {
    printf("Inserisci dimensione array: \n");
    scanf("%d", &n);
  } while(n<1 || n>DIM);

  printf("Inserisci i %d elementi:\n",n);
  for(i=0;i<n;i++)  {
      printf("elemento di indice - %d : ",i);
      scanf("%d",&v[i]);
  }
```

___

# Soluzione

```C
  media=calcola_media(v, n);
  printf("\nLa media vale: %.1f\n", media);
}

float calcola_media(int *v, int n) {
  int i;
  float media=0;

  for(i=0;i<n;i++) {
    media+=*(v+i);
  }
  return media/n;
}
```

___

# Soluzione

Oppure...

```C
float calcola_media(int *v, int n) {
  int i;
  float media=0;

  for(i=0;i<n;i++,v++) {
    media+=*v;
  }
  return media/n;
}
```

---

# Domanda di ripasso...

Perché i puntatori hanno un tipo?

---

# Domanda di ripasso...

Perché i puntatori non vengono utilizzati solo per memorizzare l'indirizzo di una variabile!
- Deferenziazione
- Aritmetica dei puntatori

---

```C
#include <stdio.h>

int main(){

    int n = 1025;
    int *ip;
    char *cp;
    ip = &n;
    printf("\n%p %d",ip,*ip);
    printf("\n%p %d",ip+1,*(ip+1));
    cp = (char *)ip;
    printf("\n%p %d",cp,*cp);
    printf("\n%p %d",cp+1,*(cp+1));

    // 00000000 00000000 00000100 00000001

    return 0;
}
```