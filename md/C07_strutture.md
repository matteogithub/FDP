---
marp: true
---

<!-- footer: M. Fraschini - Università degli Studi di Cagliari - AA 2022-2023 -->

<!-- paginate: true -->

<!-- size: 4:3 -->


# C: Strutture

Elementi di Informatica

---

# Strutture

- Quando si usa una struttura :question: 

	- Quando abbiamo necessità  di trattare un **insieme NON omogeneo** di dati :exclamation:

---



# Strutture

**Esempio*: memorizzare una data

`int giorno, mese, anno;`

Tre variabili per ogni data. Se serve un'altra data, dobbiamo dichiarare altre tre variabili

**Le tre variabili sono logicamente collegate**

Sarebbe utile poterle raggruppare! Usiamo le strutture


---

# Strutture

```C
struct data
{
 int giorno;
 int mese;
 int anno;
};
```

---

# Strutture: definizione

```C
struct data
{
 int giorno;
 int mese;
 int anno;
};
```

Questa rappresenta la **DEFINIZIONE** di una struttura.

La definizione permette di creare un **NUOVO TIPO**


---

# Strutture: dichiarazione


```C
struct data oggi;
struct data data_nascita;
```

Con la dichiarazione viene allocato lo spazio in memoria

---

# Strutture: come accedere

Accedere ad una struttura:

`nome_variabile.nome_membro`

```C
oggi.giorno=6;
oggi.mese=11;
oggi.anno=2018;
```

---

# Strutture

Esempio:

```C
#include <stdio.h>

 struct data {
 int giorno;
 int mese;
 int anno;
};

int main() {
struct data oggi;

printf("Inserisci la data di oggi: ");
scanf("%d%d%d",&oggi.giorno,&oggi.mese,&oggi.anno);
printf("Oggi: %d/%d/%d",oggi.giorno,oggi.mese,oggi.anno);
}
```

---

# Strutture: inizializzazione

```C
#include <stdio.h>

 struct data {
 int giorno;
 int mese;
 int anno;
};

int main() {
struct data oggi = {6, 11, 2018};

printf("\nOggi e' %d/%d/%d",oggi.giorno,oggi.mese,oggi.anno);
}
```

---

# Strutture: inizializzazione

```C
#include <stdio.h>

 struct data {
 int giorno;
 int mese;
 int anno;
};

int main() {
struct data oggi = {.giorno=6, .mese=11, .anno=2018};

printf("\nOggi e' %d/%d/%d",oggi.giorno,oggi.mese,oggi.anno);
}
```

---

# Strutture: inizializzazione

```C
#include <stdio.h>

 struct data {
 int giorno;
 int mese;
 int anno;
} oggi = {.giorno=6, .mese=11, .anno=2018};

int main() {

printf("\nOggi e' %d/%d/%d",oggi.giorno,oggi.mese,oggi.anno);
}
```