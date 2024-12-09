
# Componenti Interni

## Architettura di von Neumann rivisitata
Abbiamo suddiviso l'architettura di von Neumann in due blocchi logici:
- Unità di calcolo: ciò he esegue il lavoro
- Unità di controllo: la componente in grado di interpretare le istruzioni.
![[Pasted image 20241029114053.png]]

Nella CPU troviamo: *Unità di controllo, Unità di Calcolo, una piccola parte della memoria di lavoro (registri)*.
![[Pasted image 20241029114234.png]]


## I registri
Sono delle unità di memoria interne al processore, compongono la parte di memoria di lavoro interna alla CPU.
Permettono di memorizzare *parole binarie*. 
La quantità di memoria disponibile è **estramemente limitata**.
Sono realizzati a partire dai D flip/flop (64 flipflop equivale a 64 bit).
![[Pasted image 20241029114413.png]]
L'unità di controllo ci dice se all'interno del registro bisogna memorizzare una nuova parola, e attiva i clock dei flipflop.
Sono flipflop D.

I registri vanno alla stessa velocità del processore, sono molto veloci.

Nei registri si possono caricare, conversare e leggere dati.

I registri di una CPU possono essere suddivisi in più classi.

- *Registri fonamentali* : senza non si potrebbe realizzare un'architettura di Von Neumann
- *Registri visibili al programmatore* : il programmatore può usare esplicitamente nel suo programma.
- *Registri invisibili al programmatore* : Il programmatore può modificarli solo indirettamente e non programmaticamente. (Non è detto che siano esplicitati)

### Registri visibili al programmatore
Ci sono 16 registri **general purpose** a 64 bit che il programmatore può utilizzare come operandi delle istruzioni:
![[Pasted image 20241029115118.png]]
Alcuni di questi registri hanno significato particolare e sono utilizzabili *implicitamente* utilizzando specifiche istruzioni di assembly.

### Necessità di interconnesione tra registri

E' fondamentale per lo spostamente dei dati che i nostri registri siano interconessi.

L'uso dei registri è quello di mantenere copie di variabili in memoria ed è necessario supportare lo spostamento dati fra di essi.

$$mov \ \%rax, \%rbx$$

Per copiare le informazioni da un registro a un altro ci servono dei fili.

#### Interconnessione tra registri

##### Interconessione diretta
![[Pasted image 20241029115939.png]]

Il problema è che per ogni nostro registro, dobbiamo collegarlo a tutti gli altri 15 registri (ognuno da 64 flipflop), e sono tantissimi fili, un traffico enorme che non possiamo permetterci.
##### Interconessione tramite multiplexer
![[Pasted image 20241029120243.png]]
Abbiamo meno fili, ogni registro ha solo 64 fili che escono da esso.
##### costruzione di un BUS interno (Quello utilizzato)
E' gruppo di 64 fili che corrono all'interno del processore e collega fra loro tutti i registri interni.
Però se tutti i circuiti scrivono su questi 64 fili entro in corto circuito, ci serve un INTERRUTTORE che attacca o stacca i registri quando ci sono delle informazioni da inserire o ricevere.
Lo si fa tramite un **Buffer Three State**.

Inseriamo in memoria dei dati tramite un input Write, mentre se vogliamo leggere qualcosa, attiviamo il Buffer Three State in output, collegandolo al circuito e condividendo il segnale.

![[Pasted image 20241029121244.png]]

### Ottimizzazione : Banco dei registri

Il **Banco dei registri**, divide in modo ottimale la parte di codifica e decodifica.

#### Codifica (Scrittura)
Abbiamo un decoder che ci permette di identificare a quale registro stiamo trasferendo le informazioni. Abbiamo 16 regisitri a cui associamo ciascuno un numero, da 0 a 15, poi avremmo un decoder a 16 uscite che attiverà il *Write* del registro di nostro interesse

#### Decodifica (Lettura)
Per la lettura del registro utilizziamo sempre il codificatore per scegliere da quale registro leggere, e un bit di Read, se entrambi sono attivi un *buffer three state* viene attivato e collega i 64 bit di informazioni al sistema.

Quindi per scegliere il registro mi servono 4 bit, per verificare cosa farci col registro me ne servono 2.

![[Pasted image 20241029121844.png]]

$R_M$ è il read bit di controllo, $W_M$ il write bit di controllo.
Quindi quando voglio leggere RAX, avrò 4 bit che lo identificano, e $R_M$ attivo.


### Processamento dei Dati

Un processore può operare su dati di dimensioni differente. 
Possiamo utilizzare banchi di registri ed è molto utilize poter accedere a sottoporzioni dei dati nei registri, ovvero dividere gli 8 byte di dati nel nostro registro.

![[Pasted image 20241029123153.png]]

Prendendo in considerazione il registro RAX, possiamo vedere come abbiamo un'implementazione a 8-bit (AL), AL extended a 16-bit (AX), la EAX a 32-bit, e la RAX che ci fornisce in totale 64-bit.

I nostri registri vengono divisi quindi quindi in 2 sotto registri da 1 byte, AL e AX, 1 sotto registro di 2 byte EAX e infinite un sotto registro da 4 byte RAX.


![[Pasted image 20241111171454.png]]

**Le Istruzione Assembly** lavorano molto con i registri, perciò utilizzano suffissi per indicare la dimensione dei dati che stanno spostando.$$MOVx \ <sorgente>,<destinazione>$$
Dove possiamo mettere B : 1 byte, W: word 2 byte, L : longword 4 byte, Q quadword 8 byte.

Questo suffisso fornisce i dati necessari alla CU per modificare i dati.

Notare come se io vado a modificare i primi 32 bit del nostro registro, quindi la EAX, vado anche a modificare quelli precedenti.

Questi sotto registri che stiamo identificando si chiamano **Registri Virtuali**.

Perciò adesso abbiamo in aggiunta al nostro registro, un nuovo Decoder, che ci permette di scegliere su quale Registro virtuale stiamo lavorando.
Perciò abbiamo un selettore di registro e un selettore di dimensione.

![[Pasted image 20241029124354.png]]

### Instruction Register
E' un registro all'interno della CPU non visibile al programmatore, serve a memorizzare l'operazione attualmente in esecuzione all'interno della CPU, salvando mano a mano il suo processo in un posto sicuro e facilmente e velocemente accessibile durante la fase di decodifica ed esercuzione.

Nella fase di *Fetch* il programma viene preso dalla memoria e mano a mano caricato in questo registro, dove dopo entrerà nella fase di *Decode* e infine *Execute*.

![[Pasted image 20241111174127.png]]

Qui possiamo vedere che l'instruction register ha 64 bit, che poi tramite un controllo di Write, viene collegato a S-mux e REG-mux, indicando dove le informazioni devono andare.

Vediamo collegato anche i registri **RSP** e **RDX** due registri programmabili.
- **RSP**: Register stack pointer serve a puntare alla cima dello stack durante l'esecuzione di un programma
- **RDX**: Registro utilizzato per le operazioni, solitamente viene memorizzato il risultato di una certa operazione.



### Interconnesione fra registri e circuiti di calcolo

Un circuito di calcolo come la ALU ha bisogno di due operandi per fuzionare, ma fino ad adesso come abbiamo visto, i bus sono in grado di mettere in output solo il valore di un registro.
Come facciamo per esempio a sommare due registri?

Tramite un **Registro Tampone** (TEMP1 e TEMP2).

Quindi un registro viene attivato il Read, che sarà il Write di un registro di tampone in caso il Write sia attivo per i registri tampone.

Questi due registri vanno in una ALU che tramite un opcode decide cosa fare.

Mentre il TEMP2 funziona anche come shifter.

![[Pasted image 20241111180416.png]]

Ma adesso la **ALU e lo SHIFTER sono reti iterative che emettono bit di carry (stato) ed occorre memorizzarli, questo è fattibile grazie ai FLAGS REGISTERS**.

![[Pasted image 20241111180912.png]]

### Flag Registers

I bit nel FLAGS si dividono in *status* e *control* bit:
- Status -> Aggiornati dalla ALU e SHIFTER per memorizzare l'ultima operazione eseguita.
- Control -> Modificabili dal programmatore per modificare la funzionalità del processore.

![[Pasted image 20241111181151.png]]
![[Pasted image 20241111181204.png]]

Il registro FLAGS è leggibile per il momento, ma non scrivibile per modificarne il suo contenuto. **Aggiungiamo un three-state buffer collegato al bus** in modo da prendere valori esterni.
![[Pasted image 20241111181341.png]]

## Memoria Esterna alla CPU e come comunica

Oltre ai registri utilizzati dalla CPU, il restante della memoria è esterna ad essa. Però è necessario un **protocollo di scambio dati** fra CPU e Memoria.
La memoria è vista dalla CPU come un nastro di celle, con ogni cella identificato da un numero intero (**indirizzo**), ogni cella è un byte. Una testina si muove sul nastro per leggere o scrivere dati.

### Suddivisione dei BUS

I **Bus di sistema** sono gruppi di fili che corrono esternamente alla CPU e la interconnette con componenti esterni (memoria).
Abbiamo diversi bus:
- Address bus : Per leggere/scrivere dati la memoria deve conoscere l'indirizzo di interesse
- Control bus : Serve a indicare l'operazione di interesse
- Data Bus : Dove viaggiano i dati fra CPU e memoria.

E' importante che le parole ricevute dalla memoria vengano inserite correttamente nei registri giusti, ma anche che dai registri venga salvata in memoria i dati del registro corretto.

Visto che la CPU è molto più veloce della memoria, abbiamo bisogno di un "tampone" fra i due dispositivi. Ovvero il **Memory Data Register** e il **Memory Address Register**.

![[Pasted image 20241112144823.png]]


## Anatomia dei programmi in memoria

Un programma è codificato in formato binario, alla partenza esso viene caricato in memoria.

Un programma assembly può essere diviso in 3 parti:
- .text : Sequenza lineare di istruzione dove si trova effettivamente il codice del nostro programma
- .data : delle informazioni costanti che dichiariamo nel nostro programma
- .bss : Sezione dove vengono dichiarate variabili.
Ogni oggetto ha un indirizzo di memoria.
Il data e bss segment indica la parte del nostro programma in memoria che gestice i dati, mentre il text le istruzioni.

Infine abbiamo lo **stack**, che è una sezione di memoria dove avvengono pop e push con la logica Last In first Out. Lo stack ha un'origine fissa nella memoria e un size variabile. Cresce verso il basso e mantiene informazioni importanti per l'esecuzione del programma.

![[Pasted image 20241112151602.png]]

Per traversare le istruzioni in .text abbiamo bisogno di tener traccia in che punto stiamo, per questo esiste *il registro instruction pointer*, questo registro chiede alla memoria di lavoro il trasferimento della prossima istruzione da seguire. Infatti esso mantiene quasi sempre l'indirizzo in memoria della prossima istruzione.

![[Pasted image 20241112151623.png]]

Quindi l'instruction register prende dalla memoria le istruzioni da eseguire, nella CPU, con la RIP puntando sempre a che punto sta.

Il RIP viene incrementato dopo ogni sua esecuzione per puntare alla memoria successiva, questo è un processo che richiede velocità perciò gli viene dedicato un sommatore per renderlo un *registro a incremento*.

**Instruction Pointer Register**

![[Pasted image 20241112151826.png]]

## Stack

Un programma per gestire le variabili senza ingombrare i registri, utilizza lo *stack* (un'area di memoria) come area di appoggio.
E' una struttura **Last-In First-Out** : il primo elemento che può essere prelevato è l'ultimo ad essere stato memorizzato, come una pila di oggetti.
- push : viene inserito un elemento alla cima della pila
- pop : viene prelevato l'elemento in cima alla pila
Lo stack è composta da **quadword**, la cima dello stack è memorizzato nel registro **stack pointer**. Lo stack "cresce" se il valore dello stack pointer diminiusce, "decresce" se il valore dello stack pointer cresce.
Le operazioni di pop e push urilizzano il registro lo stack pointer, il programmatore può anche accedere a questo stack pointer anche se crea problemi con la perdita dei dati registrati in precedenza.

# Modalità di Indirizzamento

Visto che la memoria è una sequenza lineare, indirizzato al byte, possiamo trovare modi per rendere più comodo il suo indirizzamento.
Per esempio per manipolare strutture e vettori si utilizzano 3 elementi:
- indirizzo base del vettore o struttura
- indice del dato che vediamo (a\[i] = a + size \* i)
- spiazzamento, per esempio se abbiamo delle informazioni in una struttura che non sono quelle che vogliamo.
Si lavora quindi sempre con l'indice iniziale della nostra struttura dati.

![[Pasted image 20241112153426.png]]

![[Pasted image 20241115164650.png]]

L'indirizzo base e l'indice sono *registri general purpose*, mentre la dimensione e spiazzamento del dato sono codificate nell'istruzione.

Determinare un indirizzo di memoria è complesso, bisogna lasciarlo fare alla PU.

Lo spiazzamento ci dice a quanta distanza di memoria dobbiamo andare, per esempio.

movq %rax, 0xaaaa(%rax, %rcx, 8)

![[Pasted image 20241115164357.png]]

0xaaaa(%rax, %rcx, 8) è lo spiazzamento calcolato come %rax+%rcx\*8

Quindi 0xaaaa è lo spiazzamento, ovvero da dove iniziamo a puntare la memoria, per esempio uno struct, dopo dichè ci spostiamo di %rax+%rcx\*8, dove %rax potrebbe essere un dato, mentre %rcx\*8 un array di dati.

![[Pasted image 20241112153910.png]]

Per il calcolo dello spiazzamento e quindi trovare l'indirizzo di memoria di interesse abbiamo bisogno della ALU, che prendo le informazione dal **MEMORY ADDRESS REIGISTER**.
Nel MAR c'è l'indirizzo di memoria a cui a noi interessa leggere i dati, e possiamo anche appunto calcolare il successivo tramite lo spiazzamento.

Il MDR memory data register, contiene i dati letti o da scrivere in memoria.


Notare come ciò che comunica direttamente con i registri etc.. è la RAM, infatti è anche in essa che vengono salvati i .text, stack, .data etc... e comunica direttamente con la CPU per scambio di dati di memoria tramite i BUS.
Mentre i non volatile memories come HDD o SSD, comunicano con la CPU per mandare i loro programmi all'interno della RAM, con ulteriore BUS non collegati alla CPU.



# Architettura finale CPU

![[Pasted image 20241112153947.png]]


# Formato Istruzioni

Dobbiamo determinare il modo in cui la CU interpreta le istruzioni e determinare quali parole binarie il compilatore inserisce in .text

Le istruzioni hanno un fromato a lunghezza variabile.
![[Pasted image 20241112163249.png]]

## Opcode

![[Pasted image 20241112163339.png]]

## Mode

![[Pasted image 20241112163357.png]]
![[Pasted image 20241112163413.png]]

## Campo SIB(Scala, Indice, Base)

![[Pasted image 20241112163451.png]]
**INDEX REGISTER:**
![[Pasted image 20241112163522.png]]

## Campo R/M

![[Pasted image 20241112163621.png]]

# Esempi di Istruzioni Assembly

![[Pasted image 20241112163728.png]]
![[Pasted image 20241112163737.png]]

## Traduzione assembly in linguaggio macchina

### Esempio 1)

$$movw \ \%ax, \ \%bx$$
Vedendo le tabelle precedenti possiamo dire
![[Pasted image 20241112164017.png]]
![[Pasted image 20241112164058.png]]
![[Pasted image 20241112164106.png]]

I numeri e lettere scritti sotto non sono altro che la conversione in esadecimale del codice binario visto. Ogni 4 bit viene rappresentato da un singolo numero esadecimale.

## Little-Endianess
Come vengono accesse in memoria le istruzioni del z64, i comandi da eseguire e le informazioni vengono memorizzato a partire dall'indirizzo meno significativo, ovvero il byte meno significativo.
![[Pasted image 20241112164911.png]]
![[Pasted image 20241112164931.png]]

Questo ci permette di accedere a sottoporzioni di un dato senza eseguire alcuno spiazzamento.
# Instruction Set

![[Pasted image 20241112165122.png]]

[[8. z64 PU.pdf#page=70-80]]

## Classe 1: Istruzione di movimento dati

L'operando B può essere un registro, costante, memoria; l'operando A può solo essere un registro o memoria.

L'estensione di un dato serve a far allungare il nostro dato, magari il valore inel banco di registro a un byte lo voglio spostare al banco di registro che ha 2 byte, quindi devo aggiungere 8 volte zero. Perciò si usa movzX.

Mentre se ho -1 in complemento a due col segno, ovvero 1111 1111 rappresentato in un byte, se devo portarlo in un banco di registro a 2 byte devo aggiungere tutti 1. Perciò si usa movsX.

lea calcola l indirizzo effettivo e ne salvo nel registro l'indirizzo calcolato


## Classe 2


Dividivo il mio numero a 128 bit in due, operandhigh and operandlow.
