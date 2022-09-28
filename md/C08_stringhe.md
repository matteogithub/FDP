<!-- footer: M. Fraschini - Università degli Studi di Cagliari - AA 2021-2022 -->

<!-- page_number: true -->


# C: Stringhe

Elementi di Informatica

---

# Stringhe

`char carattere; //memorizza un solo carattere!`

Le **stringhe** sono array di caratteri (tipo `char`)

---

# Stringhe

`char c[10];` <- vettore di 10 caratteri

#### Non è indispensabile specificare il numero di elementi
La dimensione sarà determinata da: 
- inizializzazione + carattere *null* (`\0`)

`char stringa[] = "Elementi di Informatica";`

---

# Stringhe

Il carattere `\0` ci permette di usare una stringa senza conoscerne l'effettiva dimensione!

```C
#include <stdio.h>

int main() {
char stringa[]="Elementi di informatica";
int i=0;

while(stringa[i]!='\0') {
  printf("%c",stringa[i]);
  ++i;
}
}
```

---

# Stringhe

Per visualizzare l'intera stringa si usa il formato `%s`

```C
#include <stdio.h>

int main() {
char stringa[]="Elementi di informatica";

printf("%s",stringa);
}
```

---

# Stringhe

Attenzione!

Se indichiamo la dimensione della stringa occorre considerare lo spazio per il carattere nullo `\0`

`char stringa[5]="Ciao";`

---

# Stringhe

Operazioni comuni:

- copiare una stringa
- concatenare stringhe 

---

# Stringhe: copia

```C
#include <stdio.h>
#define DIM 100

int main()
{
    char stringa[]="Elementi di Informatica";
    char altra_stringa[DIM];
    int i;

    for(i=0;stringa[i]!='\0';i++)
      altra_stringa[i]=stringa[i];

    altra_stringa[i]='\0';
    printf("Prima: %s - Seconda: %s\n",stringa,
    altra_stringa);
}
```
---

# Stringhe: concatena

```C
//concatena due stringhe
#include <stdio.h>
#define DIM 100

int main()
{
    char stringa1[]="Elementi di ";
    char stringa2[]="Informatica";
    char concat[DIM];
    int i,j;

    for(i=0;stringa1[i]!='\0';++i)
        concat[i]=stringa1[i];

    for(j=0;stringa2[j]!='\0';++j)
        concat[i+j]=stringa2[j];
        
        concat[i+j]='\0';
        

    printf("%s",concat);
}
```

---


# Stringhe: input e scanf()

```C
#include <stdio.h>
#define DIM 10

int main()
{
    char stringa[DIM];

    printf("Inserisci una stringa: ");
    scanf("%s",stringa);

    printf("La tua stringa: %s",stringa);
}
```

- Non è necessario usare il simbolo `&`
- ATTENZIONE: lo spazio interrompe l'immissione

---

# Stringhe: input e getchar()

```C
#include <stdio.h>
#define DIM 100

int main()
{
    char stringa[DIM];
    int i;

  printf("Inserisci testo: ");
  for(i=0;((stringa[i]=getchar())!='\n') && (i<DIM);i++);
  stringa[i]='\0';
  printf("Parola: %s",stringa);
}
```
Con `getchar()` riusciamo a leggere anche lo spazio
Attenzione al `;` alla fine del ciclo `for`

---

# Stringhe: la libreria `<string.h>`

Libreria per operare sulle stringhe:
- `strcpy(str_dest,str_orig)`
- `strncpy(str_dest,str_orig,n_char)`
- `strcat(str1,str2)` 
- `strlen(str)` -> rende numero di caratteri
- `strcmp(str1,str2)` -> rende`0` se uguali

---

# Stringhe: conversione

Libreria `<stdlib.h>`
- `atoi(stringa)`: converte una stringa in un `int`
- `atof(stringa)`: converte una stringa in un `double`


