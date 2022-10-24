---
marp: true
---

<!-- footer: M. Fraschini - Università degli Studi di Cagliari - AA 2022-2023 -->

<!-- paginate: true -->

<!-- size: 4:3 -->

# Esempi avanzati sugli array

---

# Esercizio
Inserire un nuovo elemento in un array in una specifica posizione

---

# Soluzione 

```C
#include <stdio.h>
#define DIM 5

int main() {
  int v[DIM],n,i;
  int num,pos;

  do  {
    printf("Dimensione array: \n");
    scanf("%d", &n);
  } while(n<1 || n>DIM);

  printf("Inserisci elementi:\n");
  for(i=0;i<n;i++)  {
      printf("elemento di indice - %d : ",i);
      scanf("%d",&v[i]);
  }
```

---

# Soluzione 

```C
printf("\nInserisci nuovo elemento ");
  scanf("%d",&num);
  printf("\nInserisci la posizione ");
  scanf("%d",&pos);

  if(pos<0 || pos>n || n==DIM) {
    printf("\nInserimento non valido ");
  }
  else {
    //sposta a destra
    for(i=n;i>pos;i--)
      v[i]=v[i-1];
    v[pos]=num;
    n++;
  }
```

---

# Esercizio
Eliminare un elemento da un array in una specifica posizione

---

# Soluzione 

```C
#include <stdio.h>
#define DIM 5

int main() {
  int v[DIM],n,i;
  int num,pos;

  do  {
    printf("Dimensione array: \n");
    scanf("%d", &n);
  } while(n<1 || n>DIM);

  printf("Inserisci elementi:\n");
  for(i=0;i<n;i++)  {
      printf("elemento di indice - %d : ",i);
      scanf("%d",&v[i]);
  }
```

---

# Soluzione 

```C
printf("\nIndice elem da cancellare ");
  scanf("%d",&pos);

  if(pos<0 || pos>n-1) {
    printf("\Indice non valido");
  }
  else {
    //sposta a sinistra
    for(i=pos;i<n;i++)
      v[i]=v[i+1];
    n--;
  }
```