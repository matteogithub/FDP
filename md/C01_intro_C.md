---
marp: true
---

<!-- footer: M. Fraschini - Università degli Studi di Cagliari - AA 2022-2023 -->

<!-- paginate: true -->

<!-- size: 4:3 -->


# Introduzione al C

Fondamenti di Programmazione


---

# Un po' di storia...

Nel **1972** Dennis Ritchie sviluppa la prima versione del linguaggio C

Da allora la più significativa estensione è relativa all'introduzione della programmazione orientata agli oggetti (OOP): **C++**

E' un linguaggio di **alto livello** ma con funzionalità più **tipiche del linguaggio macchina**

Unix/Linux

---

# Un po' di storia...

1977: presentazione del linguaggio C
1989: pubblicazione dello standard C - C89
1999: pubblicazione dello standard C - C99
2011: pubblicazione dello standard C - C11

---
# IDE – Integrated Development Enviroment

**Linux**: *gcc*

**Mac OS**: dipendenza da *XCode*

`gcc -o nome_programma mio_codice.c`

---

# IDE – Integrated Development Enviroment

Windows (multipiattaforma)

- DEV-C++ (obsoleto)
- Eclipse
- CodeLite
- Visual Studio (Code)
- **Atom**
- **CLion** (licenza con credenziali di Unica)
- **Qt Creator**

---

# ![](/Users/matteo/Documents/GitHub/FDP/images/clion.png)


---

# ![](/Users/matteo/Documents/GitHub/FDP/images/clion_guide.png)

---

# Per smartphone e tablet

# ![](/Users/matteo/Documents/GitHub/FDP/images/emu.png)

---

# Domande?

www.menti.com

---
# Struttura di un programma in C

```C
//eventuali definizioni

int main()
{

//Dichiarazioni

//Istruzioni

return 0;
}

```

---
# Il mio primo programma
```C
//Il mio primo programma in C

#include <stdio.h>

int main()
{
  printf("Hello world");
  return 0;
}
```

---

# Il mio primo programma
```C
/*Il mio primo programma in C*/

#include <stdio.h>

int main()
{
  printf("Hello world\n");
  return 0;
}
```

---

# Passo passo...

`/*Il mio primo programma in C*/` 
`//Il mio primo programma in C`

rappresentano dei **commenti**

---

# Passo passo...

`#include <stdio.h>`

- E' una direttiva al preprocessore. 
- Le linee che iniziano con `#` vengono elaborate prima della compilazione del programma.
- Nel programma verrà incluso il contenuto del file `stdio.h`.
- `stdio.h` (standard input-output header) è un file di intestazione che definisce gli stream (flussi) di input e output. 

---

# Passo passo...

`int main()`

- Il `main` è la funzione principale.
- Tutte le funzioni vengono richiamate usando il loro **nome** e tra `()` vengono indicati i parametri. 
- `int` indica che la funzione restituisce un intero e le parentesi `{}` definiscono il **corpo** della funzione

---

# Passo passo...

`printf("Hello world\n");`

- La `printf` è una funzione che scrive sullo standard output (monitor). 
- Tra `“”` si può inserire del testo.
- `\n` indica l'inserimento di una nuova linea.
- ogni istruzione deve terminare con un `;`.

---

# Passo passo...

`return 0;`

- indica che il programma è terminato con successo.


