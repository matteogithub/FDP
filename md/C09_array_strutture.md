<!-- footer: M. Fraschini - Università degli Studi di Cagliari - AA 2021-2022 -->

<!-- page_number: true -->


# C: Array e Strutture

Elementi di Informatica

---

# Strutture e Array

- Strutture contenenti array
- Array di strutture
- Strutture contenenti strutture

---

# Strutture contenenti array

```C
#include <stdio.h>
#define NOME 20
    struct anagr
    {
        int matricola;
        char nome[NOME];
        char cognome[NOME];
    };
int main() {
    struct anagr studente;

    printf("\nNome studente: ");
    scanf("%s",studente.nome);
    printf("\nCognome studente: ");
    scanf("%s",studente.cognome);
    printf("\nMatricola: ");
    scanf("%d",&studente.matricola);

    printf("\n\nLo studente si chiama: ");
    printf("%s %s e la sua matricola e' %d\n",
    studente.nome,studente.cognome,studente.matricola);
}
```
---

# Array di strutture

```C
#include <stdio.h>
#define DIM_NOME 20
#define DIM_STUD 100
    struct anagr {
        int matricola;
        char nome[DIM_NOME];
        char cognome[DIM_NOME];
    };

int main() {
    struct anagr studente[DIM_STUD];
    int n_studenti;
```
Continua...

---

# Array di strutture

```C
printf("\nQuanti studenti vuoi inserire? ");
    scanf("%d",&n_studenti);

    printf("Inserisci studenti:\n");
    for(int i=0;i<n_studenti;++i) {
        printf("Studente - %d: ", i+1);
        printf("\nNome studente: ");
        scanf("%s",studente[i].nome);
        printf("\nCognome studente: ");
        scanf("%s",studente[i].cognome);
        printf("\nMatricola: ");
        scanf("%d",&studente[i].matricola);
    }

    printf("\n\nElenco studenti:\n");
    for(int i=0;i<n_studenti;++i) {
        printf("%s %s - matricola: %d\n",
studente[i].nome,studente[i].cognome,
studente[i].matricola);
    }
}
```

---

# Esercizio
Scrivere un programma che calcoli la media del voto di laurea di N studenti e stampi l'elenco degli studenti con la differenza del loro voto rispetto alla media

---

# Soluzione

```C
#include <stdio.h>
#define DIM_NOME 20
#define DIM_STUD 100
    struct anagr {
        int voto_laurea;
        char nome[DIM_NOME];
        char cognome[DIM_NOME];
    };

int main() {
    struct anagr studente[DIM_STUD];
    int n_studenti,somma=0,i;
    float media;
```

---

```C

    printf("\nQuanti studenti vuoi inserire? ");
    scanf("%d",&n_studenti);
    printf("\nInserisci studenti:\n");
    for(i=0;i<n_studenti;++i) {
        printf("Studente - %d: ", i+1);
        printf("\nNome studente: ");
        scanf("%s",studente[i].nome);
        printf("\nCognome studente: ");
        scanf("%s",studente[i].cognome);
        printf("\nVoto di laurea: ");
        scanf("%d",&studente[i].voto_laurea);
        somma+=studente[i].voto_laurea;
    }
    media=(float)somma/n_studenti;
    printf("\n\nElenco studenti:\n");
    for(i=0;i<n_studenti;++i) {
        printf("%s %s - diff media: %.1f\n",studente[i].nome,studente[i].cognome,studente[i].voto_laurea-media);
    }
}
```

---

# Strutture contenenti strutture

```C
    struct corso {
        int voto;
        char nome[DIM_NOME];
    };

    struct anagr {
        char nome[DIM_NOME];
        char cognome[DIM_NOME];
        struct corso esame[DIM_ESAME];
    };
```

---

# Esercizio
Creare un programma che permetta di inserire i voti di N esami per M studenti e stampi per ogni studente la media dei voti

---

# Soluzione

```C
#include <stdio.h>
#define DIM_NOME 20
#define DIM_STUD 1000
#define DIM_ESAME 50
    struct corso {
        int voto;
        char nome[DIM_NOME];
    };

    struct anagr {
        char nome[DIM_NOME];
        char cognome[DIM_NOME];
        struct corso esame[DIM_ESAME];
    };

int main() {
    struct anagr studente[DIM_STUD];
    int n_studenti,n_esami,somma[DIM_STUD]={0};
    float media[DIM_STUD]={0};
```

___


```C
printf("Qunati studenti vuoi inserire? ");
    scanf("%d",&n_studenti);
    printf("\nInserisci studenti.");
    for(int i=0;i<n_studenti;++i) {
        printf("\nStudente - %d", i+1);
        printf("\nNome studente: ");
        scanf("%s",studente[i].nome);
        printf("\nCognome studente: ");
        scanf("%s",studente[i].cognome);
        printf("\nQuanti esami ha sostenuto?: ");
        scanf("%d",&n_esami);
        for(int j=0;j<n_esami;++j) {
            printf("\nEsame - %d",j+1);
            printf("\nNome corso: ");
            scanf("%s",studente[i].esame[j].nome);
            printf("\nVoto: ");
            scanf("%d",&studente[i].esame[j].voto);
            somma[i]+=studente[i].esame[j].voto;
        }
        media[i]=(float)somma[i]/n_esami;
    }
```

---

```C
    printf("\n\nElenco studenti\n");
    for(int i=0;i<n_studenti;++i) {
        printf("%s %s - media: %.1f\n",studente[i].nome,
        studente[i].cognome,media[i]);
    }
}
```