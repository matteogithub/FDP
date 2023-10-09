---
marp: true
---

<!-- footer: M. Fraschini - Università degli Studi di Cagliari - AA 2023-2024 -->

<!-- paginate: true -->

<!-- size: 4:3 -->

# C: iterazione

Fondamenti di Programmazione

---

# Iterazione

Permette di sviluppare programmi con processi ripetitivi (**cicli**), evitando di scrivere più volta la/e stessa/e istruzione/i.

---

# Iterazione: cosa non fare!

```C
#include <stdio.h>
int main()
{
  int n,somma=0;

  scanf("%d",&n);
  somma=somma+n;
  scanf("%d",&n);
  somma=somma+n;
  scanf("%d",&n);
  somma=somma+n;
  printf("%d",somma);
}
```

---

# Iterazione: cosa fare!

```C
#include <stdio.h>
int main()
{
  int i,n,somma=0;

  for(i=1;i<=3;i=i+1)
  {
    scanf("%d",&n);
    somma=somma+n;
  }
  printf("%d",somma);
}
```

---

# For

`for(inizializzazione;condizione;incremento/decremento)`
`istruzione;`

- **inizializzazione**: viene eseguita *solo* la prima volta
- **condizione**: condizione necessaria affinché il ciclo continui
- **incremento/decremento**: ultima espressione del ciclo

---

# For

NB: l'incremento/decremento viene svolto dopo che il corpo del ciclo è stato eseguito!!!

---

# For

### Attenzione ai cicli infiniti!

`for(i=1;i>=1;i=i+1)`

---

# For

```C
#include <stdio.h>
int main()
{
  int i,n,somma=0;

  for(i=1;i<=3;i=i+1)
  {
    printf("\nInserisci numero %d: ",i);
    scanf("%d",&n);
    somma=somma+n;
  }
  printf("\nLa somma vale: %d\n",somma);
}
```

---

# Operatore: incremento/decremento

`i++;` equivale a `i=i+1;`
`i--;` equivale a `i=i-1;`

### Attenzione:

`b=2; a=++b;` b=3 e a=3
`b=2; a=b++;` b=3 e a=2

---

# Esercizio
Scivere un programma che fornisca la somma dei primi N numeri naturali. N è definito dall'utente.

___

# Soluzione

```C
#include <stdio.h>
int main()
{
  int i,n,somma=0;

  printf("Quanto vale N? ");
  scanf("%d",&n);
  for(i=1;i<=n;++i)
    somma+=i;
  printf("Somma dei natutali fino a %d: %d\n",n, somma);
}
```

---

# Esercizio
Scrivere un programma che calcoli la media di N numeri. N è definito dall'utente.

---

# Soluzione

```C
#include <stdio.h>
int main()
{
  int i,n,num,somma=0;
  float media;

  printf("Quanti n vuoi inserire? ");
  scanf("%d",&n);
  for(i=1;i<=n;++i)
  {
    printf("\nInserisci numero %d: ",i);
    scanf("%d",&num);
    somma+=num;
  }
  media=(float)somma/n;
  printf("\nLa media vale: %f\n",media);
}
```

---

# Esercizio
Scrivere un programma che calcoli la tabellina del numero N. N è definito dall'utente.

---

# Soluzione

```C
#include <stdio.h>
int main()
{
  int i,n;

  printf("Inserisci un numero ");
  scanf("%d",&n);
  for(i=1;i<=10;++i)
    printf("\n%d * %d = %d",i,n,i*n);
}
```

---

# Esercizio
Scrivere un programma che calcoli le tabelline dei numeri tra l'1 e il 12 e stampi la tabella risultante.

---

# Soluzione

```C
#include <stdio.h>
int main()
{
  int i,j;

  for(i=1;i<=12;++i)
  {
    for(j=1;j<=12;++j)
      printf("%3d ",i*j);
    printf("\n");
  }
}
```

---

# Esercizio
Scrivere un programma che permetta di inserire N voti, calcoli la media e conti il numero di voti sopra una soglia definita dall’utente

---

# Soluzione

```C
#include <stdio.h>
int main()
{
  int n,i,voto,somma=0,soglia,sopra=0;

  printf("Quanti voti?");
  scanf("%d",&n);
  printf("Che soglia?");
  scanf("%d",&soglia);
  for(i=1;i<=n;++i)
  {
    printf("Inserisci voto %d: ",i);
    scanf("%d",&voto);
    somma+=voto;
    if(voto>soglia) ++sopra;
  }
  printf("\nLa media e': %.1f\n",(float)somma/n);
  printf("\n%d voti sopra %d", sopra,soglia);
}
```
---

# While

`while(condizione) {istruzioni;}`

Il ciclo `while` impone la ripetizione del blocco di istruzioni fino a quando la *condizione* non diventa FALSE
- valutazione della condizione
- se condizione è FALSE -> non viene eseguito il corpo del ciclo
- si valuta nuovamente la condizione e così via…

### L'inizializzazione della variabile che contralla il ciclo deve essere fatta prima del `while` 
### L'incremento sarà eseguito come ultima istruzione del corpo del `while`

---

# While

Esempio:
```C
#include <stdio.h>
int main()
{
  int i=1,n,somma=0;

  while(i<=3)
  {
    printf("\nInserisci numero %d: ",i);
    scanf("%d",&n);
    somma=somma+n;
    i++;
  }
  printf("\nLa somma vale: %d\n",somma);
}
```

---

# Esercizio
Scrivere un programma che calcoli la media di N numeri utilizzando `while`

---

# Soluzione

```C
#include <stdio.h>
int main()
{
  int i=1,n,num,somma=0;
  float media;

  printf("Quanti n vuoi inserire? ");
  scanf("%d",&n);
  while(i<=n)
  {
    printf("\nInserisci numero %d: ",i);
    scanf("%d",&num);
    somma+=num;
    ++i;
  }
  media=(float)somma/n;
  printf("\nLa media vale: %f\n",media);
}
```

---

# Esercizio
Scrivere un programma che verifichi se un anno è bisestile usando `while`

(divisibile per 4 `&&` non divisibile per 100) `||` divisibile per 400

---

# Soluzione

```C
#include <stdio.h>

int main()
{
   int anno;

   printf("Inserisci l'anno ");
   printf("(0 per uscire): ");
   scanf("%d",&anno);
   while(anno>0)
   {
     if ((anno%4 == 0 && anno%100 != 0) || anno%400 == 0)
        printf("\n%d e' bisestile\n", anno);
     else
        printf("\n%d non e' bisestile\n", anno);
     printf("Inserisci l'anno ");
     printf("(0 per uscire): ");
     scanf("%d",&anno);
   }
}
```

---

# Esercizio
Scrivere un programma che calcoli diametro, circonferenza e area usando il `while`

---

# Soluzione

```C
#include <stdio.h>
int main()
{
  const float Pi=3.14;
  float raggio, diametro, circ, area;
  char sel='Y';

  while(sel=='Y')
  {
    printf("Inserisci raggio: ");
    scanf("%f",&raggio);
    diametro=2*raggio;
    circ=diametro*Pi;
    area=Pi*raggio*raggio;
    printf("Diametro: %f ",diametro);
    printf("Circonferenza: %f ",circ);
    printf("Area: %f ",area);
    printf("\nY per continuare, N per uscire\n");
    scanf(" %c",&sel);
  }
}
```

---

# Esercizio
Scrivere un programma che calcoli il BMI usando il `while` e verificare i valori per la ripetizione e per l’uscita dal programma

---

<!-- $size: 16:9 -->

# Soluzione

```C
#include <stdio.h>
int main() {
	float altezza,peso,bmi;
	char sel='Y';
	while(sel!='N')	{
		printf("Inserisci altezza in m:\n");
		scanf("%f",&altezza);
		printf("Inserisci peso in Kg:\n");
		scanf("%f",&peso);
		bmi=peso/(altezza*altezza);
		if(bmi<=20)
			printf("BMI: %.2f; sottopeso\n",bmi);
			else if (bmi>20 && bmi<=30)
				printf("BMI: %.2f; normopeso\n",bmi);
				else printf("BMI: %.2f; sovrappeso\n",bmi);
		printf("N per uscire, Y per continuare: \n");
		scanf(" %c",&sel);
		while(sel!='N' && sel!='Y')		{
			printf("Scelta non valida \n");
			printf("N per uscire, Y per continuare: \n");
			scanf(" %c",&sel);
		}}}
```
---

# Do While

Le istruzioni `for` e `while` verificano la condizione prima che il ciclo venga eseguito. 
**Il corpo del ciclo potrebbe non essere eseguito mai!**

---

# Do While

Se vogliamo verificare la condizione alla fine del ciclo possiamo usare il `do-while`.

`do istruzione; while(espressione);`

```C
#include <stdio.h>
int main()
{
  int n=0;

  do printf("%d ",n++);
  while(n<=9);
}
```

---

# Do While

### Attenzione!

```C
#include <stdio.h>
int main()
{
  int n=0;

  do printf("%d ",n++);
  while(n<=9);
}
```

```C
#include <stdio.h>
int main()
{
  int n=0;

  do printf("%d ",++n);
  while(n<=9);
}
```