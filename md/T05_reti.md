---
marp: true
---

<!-- footer: M. Fraschini - Università degli Studi di Cagliari - AA 2022-2023 -->

<!-- paginate: true -->

<!-- size: 4:3 -->


# Reti di calcolatori


---

# Introduzione

Ciascuno dei tre secoli trascorsi è stato dominato da una specifica tecnologia

**Diciottesimo**: grandi sistemi meccanici della Rivoluzione Industriale
**Diciannovesimo**: motore a vapore
**Ventesimo**: raccolta, elaborazione e distribuzione dell’informazione

---

# Introduzione

# ![](/Users/matteo/Downloads/images/reti_intro.png)

---

# Introduzione

# ![](/Users/matteo/Downloads/images/reti01.png)

- Autonomi: capacità di calcolo propria
- Interconnessi: in grado di scambiare informazioni

Le reti possono avere dimensioni, tipologia e forma differente


---

# Internet e Web

Né Internet né il World Wide Web sono reti di calcolatori!

- Internet non è una singola rete, ma una rete di reti…
- Il WEB è un sistema distribuito che si appoggia ad Internet…

Un **sistema distribuito** è costituito da un insieme di computer indipendenti che appare ai propri utenti come un singolo sistema coerente

In una rete di calcolatori gli utenti vedono le macchine e il sistema non compie tentativi per far apparire e agire le macchine in modo coerente

---

# Scopi di una rete di calcolatori

- Applicazioni aziendali
- Applicazioni personali
- Applicazioni mobili (m-commerce, navigazione satellitare, RFiD e wearable computer)

---

# Hardware di rete

Le reti di calcolatori vengono classificate in base a due parametri principali: **la tecnologia trasmissiva** e **la scala**

---

# Tecnologia trasmissiva

- Collegamenti **broadcast**
	- un solo canale di comunicazione condiviso fra tutte le macchine
	-  brevi messaggi (pacchetti) sono inviati da una macchina e ricevuti da tutte le altre 
	-  un campo indirizzo individua il destinatario
 in fase di ricezione viene esaminato l’indirizzo
 se l’indirizzo corrisponde, la macchina ricevente elabora il pacchetto, in caso contrario lo ignora

# ![](/Users/matteo/Downloads/images/reti02.png)


---

# Tecnologia trasmissiva

- Collegamenti **punto-punto**
	- consistono di molte connessioni tra singole coppie di calcolatori
	- per arrivare a destinazione un pacchetto deve visitare una o più macchine intermedie
	- possono esistere più strade possibili, occorre scegliere quella migliore

# ![](/Users/matteo/Downloads/images/reti03.png)

---

# Scala

- **LAN**: reti private con estensione limitata; lavorano ad una velocità compresa tra i 100 Mbps e i 1000 Mbps. *Ethernet (IEEE 802.3)*

- **MAN**: è una rete che copre come estensione un'area metropolitana

- **WAN**: è una rete che copre una nazione o un continente

---

# Reti wireless

**Connessioni all’interno di un sistema**: portata ridotta, collega periferiche al computer. *Bluetooth*

**LAN wireless**: ogni PC è dotato di un sistema di comunicazione senza fili per poter comunicare con altri sistemi attraverso un access point. Lo standard più diffuso è il *IEEE 802.11*

**WAN wireless**: reti telefonia mobile (GPS, EDGE, UMTS, HSDPA, LTE), Wi-MAX (IEEE 802.16)…

---

# Software di rete

Le reti sono organizzate come  livelli (layer) costruiti uno sull’altro
Ogni livello ha il compito di fornire servizi al livello superiore mascherandone i dettagli (*macchina virtuale*)


# ![](/Users/matteo/Downloads/images/reti04.png)

---

# Software di rete

Ogni livello *n* è in comunicazione con il livello *n* di un altro computer attraverso delle regole definite da un **protocollo**

Ogni livello passa dati e informazioni al livello sottostante (**interfaccia**).

L’interfaccia definisce i servizi che il livello inferiore rende disponibili a quello superiore

L’insieme di livelli e protocolli prende il nome di **ARCHITETTURA DI RETE**

---

# Software di rete

# ![](/Users/matteo/Downloads/images/reti05.png)

---

# Software di rete

Spesso servizi e protocolli vengono confusi!

Un servizio è costituito da un insieme di operazioni  che uno strato offre a quello superiore (o all’utente!)

Un protocollo è un insieme di regole che definiscono il formato e il significato dei pacchetti


# ![](/Users/matteo/Downloads/images/reti06.png)

---

# Modello ISO-OSI

# ![](/Users/matteo/Downloads/images/reti07.png)

---

# Software di rete: strato fisico

Scopo: trasportare i bit da un computer ad un altro
- Mezzi Guidati
	- Mezzi magnetici: estremamente economici e ampiezza di banda eccellente. Ritardo
	- Doppino: connessione online. Linea telefonica. Segnali analogici e digitali. Basso costo.
	- Fibra ottica: enorme ampiezza di banda. 50 Gbps per 100 Km.

- Mezzi non guidati (wireless) 
	- Radio: omnidirezionali. Lunghe distanze attraverso ostacoli. 
	- Infrarossi: corto raggio. 
	- Satellitari

---

# Software di rete: TCP/IP

Il **TCP/IP** rappresenta il modello di riferimento di Internet (commutazione di pacchetto o packet switching)

**Strato rete**: consente agli host di inviare pacchetti e farli viaggiare in modo indipendente l’uno dall’altro fino a destinazione

Questo strato definisce un protocollo chiamato IP (Internet Protocol)

Lo scopo principale è quello di consegnare i pacchetti alla destinazione corretta

---

# Software di rete: TCP/IP

**Strato di trasporto**:  E’ progettato per consentire la comunicazione tra due host

In questo strato sono stati definiti due protocolli

- TCP (Transmission Control Protocol): è un protocollo affidabile che permette a un flusso di byte emessi da un computer di raggiungere senza errori qualsiasi altro computer. Si occupa di suddividere i dati in pacchetti e di ricomporli in fase di acquisizione.
- UDP (User Datagram Protocol): è un protocollo inaffidabile utilizzato per le applicazioni che non vogliono garanzia di ordinamento e controllo. E’ utilizzato nella applicazioni dove la consegna rapida è più importante dell’accuratezza (trasmissione di voce e filmati). 

---

# Esempio di rete


# ![](/Users/matteo/Downloads/images/reti08.png)






