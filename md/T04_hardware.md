---
marp: true
---

<!-- footer: M. Fraschini - Università degli Studi di Cagliari - AA 2022-2023 -->

<!-- paginate: true -->

<!-- size: 4:3 -->


# Hardware

---

# Hardware e Software

Hardware e Software sono "logicamente" equivalenti

"L’hardware è software pietrificato" `(Karen Panetta Lenz)`

- Tutto ciò che viene effettuato da un software, può essere inglobato nell’hardware e viceversa: il software di oggi potrebbe essere l’hardware di domani

- La scelta dipende da: costo, velocità, affidabilità e frequenza di aggiornamento delle funzioni


---

# Transistor e Microchip

Le componenti fondamentali che costituiscono un calcolatore sono i **transistor** e i **microchip**.

- Il transistor è un dispositivo a stato solido formato da semiconduttori. I transistor vengono impiegati in ambito elettronico, principalmente, come amplificatori di segnali elettrici o come interruttori elettronici comandati da segnali elettrici
- I microchip sono dei circuiti integrati di ridottissime dimensioni (circa 5 mm2) che contengono milioni di transistor che opportunamente collegati formano i circuiti logici di base e le memorie.



---

# ![](/Users/matteo/Documents/GitHub/FDP/images/moore.png)

---

# Macchina di Von Neumann

# ![](/Users/matteo/Documents/GitHub/FDP/images/von.png)

---

# Macchina di Von Neumann

- Microprocessore (CPU – Central Processing Unit): ha il compito di elaborare i dati presenti nella memoria centrale (RAM), coordina e controlla le periferiche.

- Memoria Centrale (RAM – Random Access Memory): memorizza i programmi in esecuzione e i dati utili al loro funzionamento.

- Periferiche di i/o: componenti che rendono possibile la comunicazione tra PC e utente.

- Bus di sistema: connessioni (sistema aperto) lungo le quali viene trasferita l’informazione (indirizzi, dati e segnali di controllo). 


---

# CPU

### Il processore è la mente del calcolatore.

- E’ formata dai dispositivi elettronici che consentono di **acquisire**, **interpretare** ed **eseguire** le singole istruzioni dei programmi (caricati in memoria centrale).

- Una delle principali caratteristiche che identificano una CPU è la dimensione del bus interno. I primi PC usavano architetture a 4-8-16 bit, oggi si è giunti a costruire CPU che utilizzano architetture a 32 e 64 bit (necessità di adeguamento dei SO).


---

# CPU

- La CPU è costituita dai seguenti elementi:
	- Unità di controllo
	- Unità aritmetico logica (ALU)
	- Clock
	- Registri

---

# CPU – unità di controllo

L’unità di controllo ha il compito di interpretare i comandi provenienti dalle unità periferiche e dalla memoria centrale.
Così facendo l’unità di controllo coordina, controlla e sovraintende l’esecuzione dei programmi e le unità periferiche.



---

# CPU – unità aritmetico logica

E’ detta ALU – Arithmetic Logical Unit e rappresenta quella unità che elabora i dati (sottoforma di numeri binari…) provenienti dalla memoria centrale.
L’ALU ha il compito di svolgere i calcoli (addizioni e sottrazioni), le operazioni logiche e di confronto richieste dall’unità di controllo.


---

# CPU – clock di sistema

Il clock serve a sincronizzare fra di loro le varie parti del processore in modo che tutte abbiano terminato il loro compito prima di passare alla gestione dell’istruzione successiva.
La frequenza di clock indica la frequenza con cui si susseguono le quattro fasi che costituiscono il **ciclo macchina**.

- Fase di acquisizione
- Fase di decodifica
- Fase di elaborazione
- Fase di memorizzazione (opzionale)

---

# CPU – registri

I registri sono gli elementi di memoria della CPU e vengono utilizzati per memorizzare temporaneamente istruzioni e risultati parziali delle operazioni, nonché informazioni di controllo.

- Program counter (PC): punta all’istruzione successiva

- Instruction register (IR): contiene l’istruzione che si trova in fase di esecuzione

- Data register: permette di prelevare e memorizzare i dati e le istruzioni presenti in RAM

- Address register: individua la cella di memoria RAM che contiene i dati e le istruzioni da eseguire


---

# Memoria

Lo schema della macchina di Von Neumann prevede un unico tipo di memoria da cui il processore preleva istruzioni e dati e dove deposita i risultati delle elaborazioni. In realtà vedremo in seguito che esistono altri tipi di memoria.

---

# Memoria

Esistono diverse tecniche per far ricordare ad un mezzo fisico un informazione di tipo binario (0 o 1). 
Tali tecniche definiscono memorie molto diverse tra di loro in termini di velocità (tempo medio necessario per recuperare l’informazione) e di costo.

---

# Memoria

In base al fenomeno fisico responsabile del processo di memorizzazione, vengono distinte diverse categorie di memorie:

- semiconduttore
- magnetiche
- ottiche

# ![](/Users/matteo/Documents/GitHub/FDP/images/mem.png)

---

# Memoria

- Memorie a **semiconduttore**: il metodo è elettronico e si fonda sulla conservazione di una carica elettrica all’interno di un piccolo conduttore. Si tratta di una memoria di piccole dimensioni fisiche e molto veloce; per contro il costo è elevato.

---

# Memoria

- Memorie **magnetiche**: la tecnica utilizza la caratteristica di alcuni materiali (le sostanze ferromagnetiche) di assumere e mantenere una direzione di magnetizzazione. Il costo non è elevato e la memorizzazione è permanente (fino ad una successiva sovrascrittura); per contro la velocità non è notevole e viene richiesto un  dispositivo di lettura elettro-meccanico.

	- 1 HHD da 1 TB: 50 euro
	- 1 SSD da 1 TB: 150-200 euro

---

# Memoria

- Memorie **ottiche**: il principio usato è la possibilità di un raggio laser di causare e poi riconoscere modifiche nella struttura della materia (riflettività, polarizzazione). I vantaggi e gli svantaggi sono simili a quelli delle memorie magnetiche, ma vengono migliorati i parametri costo e velocità.

---

# Memoria

L’ideale dal punto di vista delle prestazioni sarebbe implementare tutta la memoria con tecnologie a semiconduttore consentendo un accesso quasi istantaneo alle informazioni; 

d’altra parte, per aver memorie in grado di contenere una elevata quantità di dati, senza spendere cifre astronomiche, sarebbe opportuno scegliere memorie dal basso costo per le unità di memoria.

---

# Memoria

Il compromesso fra le due esigenze ha fatto nascere una gerarchia a tre livelli (i registri interni del processore non vengono considerati memoria vera e propria):

- Memoria **cache** (memoria molto veloce, di piccolo dimensioni e costosa)

- Memoria **centrale** (memoria veloce, di medie dimensioni e abbastanza costosa)

- Memoria **secondaria** (memoria lenta, di notevoli dimensioni ed economica).

---

# Memoria Centrale - RAM

Caratteristica fondamentale della memoria centrale è la capacità di permettere l’accesso alle informazioni in modo diretto e in tempi molto brevi. E’ una memoria volatile.

- Dal punto di vista logico essa può essere vista come una grande matrice formata da celle (parola - word) caratterizzate da un indirizzo e da un contenuto.

- Il processore accede al contenuto (in lettura o in scrittura) della cella per mezzo del suo indirizzo.

- La lunghezza dell’indirizzo è strettamente legato al numero di celle che si possono distinguere e rappresenta quindi un indice  dello spazio di indirizzamento del processore (massima grandezza della memoria).

---

# Memoria Centrale - RAM


# ![](/Users/matteo/Documents/GitHub/FDP/images/ram.png)

---

# RAM e ROM

### ROM (Read Only Memory – memoria a sola lettura)
### RAM (Random Access Memory - memoria ad accesso casuale).

Si differenziano per il loro uso e le loro caratteristiche.


---

# RAM e ROM


- la memoria **RAM** è cancellabile e riscrivibile ed è adatta a contenere il/i programma/i in esecuzione e tutti i dati necessari al suo/loro funzionamento. 
- la memoria **ROM**, non cancellabile e non riscrivibile, viene usata in tutti quei casi in cui non serva modificare il contenuto della memoria (stabilito all’atto della costruzione); tipicamente contiene le istruzioni che consentono di impostare le condizioni ottimali di funzionamento della macchina ed effettuare i vari test di controllo, ossia di realizzare l’inizializzazione o bootstrap del sistema. Estensioni: EPROM

---

# Estensioni alla macchina di Von Neumann

Il limite della M. di von Neumann è la **stretta sequenzialità** con cui vengono eseguite le operazioni. 

Sono state proposte alcune estensioni:

- uso di processori dedicati (co-processori matematici, processori grafici - GPU).

- parallelismo: (i) a livello di istruzione (pipelining) e (ii) a livello di processore (dotare il sistema di più processori che cooperano nell’eseguire le singole istruzioni - sistemi multi-processore).

- altri tipi di memoria (memoria cache).

---

# La memoria Cache

La memoria cache è una memoria temporanea utilizzata per migliorare il trasferimento dei dati tra la memoria centrale e la CPU.

La cache, sensibilmente più veloce della memoria centrale, contiene i dati usati più frequentemente/prababilmente dalla CPU, producendo così accessi più veloci.