
# Memoria primaria (RAM)

**Organizzazione Logica**:
- modello di memoria *flat*, ovvero la memoria è un lungo vettore di celle (byte)
- Ongi cella ha come attributo un indirizzo che la riconosce

**Organizzazione in Moduli:**
L'organizzazione a moduli risolve il problema che a volte il nostro processore vuole leggere più byte insieme, per esempio 8. La soluzione di questo problema è l'organizzazione a **Moduli**, che permette di recuperare byte in parallelo.

- I tre bit meno significativa dell'indirizzo indicano il modulo, quelli più significativi la riga

![[Pasted image 20241204210106.png]]

Questa soluzione non basta, data che il processore potrebbe voler prendere meno di 8 byte.

**CHIP SELECT (CS)**
Permette di attivare o disattivare dei determinati moduli di memoria.

![[Pasted image 20241204211146.png]]


**Allineamento e Disallineamento** :
Invece di essere disposto in una riga, l'informazione potrebbe essere disposta in più righe.
- L'hardware deve effettuare più letture per ricostruire il dato
- Soluzione software si chiama *padding*




# Matrice di Memoria

![[Pasted image 20241204211404.png]]

**Organizzazione a matrice** : 

![[Pasted image 20241204211505.png]]

L'operazione di lettura è un'operazione distruttiva, che permette di leggere i dati in una raga ma allo stesso tempo li cancella.



# Costruzione di celle (Memoria RAM statica)

![[Pasted image 20241204211539.png]]

Ogni cella elementare che permette di memorizzare un bit è un insieme di 6 transistor in modo da catturare un bit di informazione.

L'informazione rimane salvata finchè ho una presenza di tensione.

*Tempi di accessi rapidi, Costi elevati*.
I tempi di accesso sono rapidi ma costi molto elevati per produrla.

La matrice di bit è realizzata come un insieme di flip-flop di un circuito combinatorio


![[Pasted image 20241204211647.png]]

# Memoria RAM dinamiche

![[Pasted image 20241202144640.png]]

Tecnologia solitamente utilizzata per la sua efficineza di costi, anche se il condensatore come componente è lento. Sono circuiti molto piccoli e condensati, quindi sono anche più capienti.

![[Pasted image 20241202144853.png]]
Il problema dei condensatori è che si scaricano naturalmente, causando problemi di immagazzinazione visto che non puoi sapere se in quella cella di memoria ci fosse un 1 prima. Questo è il motivo per cui le RAM dopo lo spegnimento del computer perdono tutti i dati.
![[Pasted image 20241202145344.png]]
Per risolvere questo problema la DRAM (dinamic ram) viene *refresh*-ata, all'incirca ogni 64ms, questo causa un consumo energetico e degradazione delle prestazioni, visto che se io sto per prendere un dato ma parte il refresh, il nostro processore deve aspettare che il refresh avvenga.
Più la memoria è grande, più la RAM ci metterà a fare un refresh.
![[Pasted image 20241202145623.png]]
Se tieni acceso per 1 minuto un computer di 64GB, 46% di quel tempo è speso in refresh.

**Miglioramento del Refresh** : Refresh a burst, ogni 64ms si effettua un refresh a tutte le righe, perciò conviene fare un *refresh distribuito* in modo che il processore non si trovi mai bloccato, eliminando statisticamente le lunghe pause. 


# Interazione sincrona con la memoria

Per sincronizzare memoria e processore abbiamo bisogno di un memoria con una certa velocità, questo significa che dobbiamo sapere quanto è più lento il controllore della memoria rispetto la CPU.

![[Pasted image 20241202150544.png]]

La prima operazione che avviene è quella dell'*address bus* che deve selezionare la riga di lettura, successivamente la CPU informa se deve leggere o scrivere, infine il *data bus* finisce l'esecuzione.

![[Pasted image 20241204212100.png]]

**Differenze di velocità tra CPU e DRAM** :

![[Pasted image 20241204212142.png]]

![[Pasted image 20241204212153.png]]


# Gerarchia di Memoria

Soluzione approssimata per implementare la memoria nel nostro sistema, utilizza tecnologie diverse per soddisfare necesità diversi, cercando di ottimizzare globalmente i parametri.

Abbiamo più livelli di memoria, *al crescere* del livello e distanza dalla CPU decresce il costo e velocità della memoria, ma aumenta la capacità di memorizzazione.

![[Pasted image 20241204212741.png]]
![[Pasted image 20241204212816.png]]

## Efficienza uso delle cache

Più piccolo della RAM, mantiene *sottoinsieme* di dati (copie), vicino la CPU, dobbiamo trovare un modo per aumentare la probabilità di trovare dati utili in questa cache.
![[Pasted image 20241204212850.png]]

### Principio di località

Un sistema di memoria gerarchico è efficiente se gli schemi di accesso ai dati sono prevedibili, l'efficienza quindi dipende dall'applicazoine.
Se il nostro codice non rispetta i principi di località il nostro programma sarà più lento visto che recupererà dati da livelli inferiori (più lenti) di memoria. Quindi il processore secondo dei principi di località porta più vicini a sè certi dati per rendere più facile il processo.

**Due tipi di località**
- Località Temporale : se si è effuttuato un accesso ad un elemento, è probabile che nel breve tempo si effettuerà un altro accesso dello stesso elemento.
- Località Spaziale : Se si effettua l'accesso ad un elemento, è probabile che si effettui l'accesso a un elemento vicino ad esso.

### Sfruttare il principio di località

![[Pasted image 20241203114650.png]]

I blocchi permettono di avere byte di memoria vicini, vicini.
Se il mio processore è entrato in un blocco, devo tenere più vicini possibile al mio processore questi blocchi.

![[Pasted image 20241203115010.png]]


## Cache e controlli di Memoria

![[Pasted image 20241203115352.png]]

Il processore lavora con una macchina a stati che gestisce lo stato delle varie copie di dati che sono contenuto nella nostra cache di primo livello. Ogni nostra Cache ha una macchina a stati che controlla che rimanga coerente con quello che succede all'interno del processore.

Se il processore vuole accedere a una variabile, prima di tutto chiede al controllore della Cache lo stato della variabile. Se la copia non è disponibile manda il segnale a un livello inferiore di memoria se è presente.
Un livello superiore parla solo con il controller del livello inferiore.

## Strategue di utilizzo delle cache

La cache è una struttura di *linee*, quando arriva un blocco (64byte) da un livello inferiore lo inseriamo nella linea, in caso sono piane dobbiamo trovare modo per fare un rimpiazzo

Il processore interagisce soltanto con il controller del primo livello.

Se il dato è nel primo livello si ha un cache *hit*, senno avviene un *miss*, in caso di miss si chiede al controllore di secondo livello e così via. Nel caso peggiore è la RAM che ha la copia dei dati.

## Politiche di inclusività nelle cache

### Cache inclusive:
Il processore chiede una variabile che il livello 1 non ha, ma il livello 2 ha, allora si fa una copia del dato da livello 2 al livello 1 per poi mandarlo al processore (solo il livello 1 interagisce con il processore). Ma in caso fosse la RAM ad avere questo dato, ci sarebbe diversi copiature consecutive, però questo comporta anche che in caso la mia cache di livello 1 sia piena, può scartare qualsiasi linea, perchè tanto il livello 2 ne ha una copia.

### Cache esclusive:
Alcuni livelli possono essere non inclusi, un miss ad un livello superiore può comportare un diretto accesso in memoria, in questo caso il dato è scritto solo nel L1 e non in L2. Per scrivere in L1 è necessario rimpiazzare un blocco, questo "scende" in L2.

## Informazioni di controllo

Una linea di cache non contiene solo il blocco, ma anche *informazioni di controllo* (la directory).
La dimensione di un bit di linea di cache è quindi maggiore della dimensione stesso.

## Cache direct mapping : determinare la posizione del blocco

![[Pasted image 20241203121153.png]]

La funzione hash più semplice da implementare è il modulo.
## Problema di collisione

Abbiamo problemi di collisione quando più indirizzi di memoria puntano alla stessa posizione di cache, con informazioni differenti, perciò il controllore di primo livello deve differenziare sinonimi (stessa chiavi, valori diversi) e non ho un *hit* ma un *miss*.

Una soluzione è utilizzare *TAG* per risolvere collisioni

L'indirizzo di memoria viene scomposto in tre parti:
- Tag : per discriminare sinonimi
- Index : bit intermedi per selezionare linee di cache
- Offset : bit meno significativi per selezionare la parola esatta all'interno del blocco

![[Pasted image 20241204215030.png]]

Le Directory servono a dire se un blocco è stato precedentemente caricato, in modo da avere un hit, difatti se un blocco non è caricato vale 0, e il processore potrebbe pensare che il valore sia un hit se non per le Directory.

## Cache completamente associativa

Nelle cache associative, ogni blocco può essere memorizzata in ogni linea di cache

*Vantaggi* : Utilizzo massimo della cache, riduzione di conflitti
*Svantaggi* : Iterazione di tutta la cache per trovare un blocco che aumenta la latenza. Perciò è necessario aggiungere un comparatore per ciascuna linea, questa aumenta molto il costo.
![[Pasted image 20241204215252.png]]


## Cache set associative (compromesso cache)

Un misto fra una Cache diretta e una Cache associativa.
- Ciascuno blocco può essere memorizzato in un numero di linee $n \geq 2$ (un insieme)
- La ricerca di un blocco richiede al massimo il confronto fra n tag
- Il costo è minore
- Tecnologia utilizzata nei processori moderni
![[Pasted image 20241204215654.png]]

## Politiche di rimpiazzo (eviction)

Quando non si possono aggiungere dei dati in un livello di cache c'è la necessità di togliere dalla memoria un'informazione per fare spazio.
Le principali politiche che scelgono come togliere sono :
- *Least Recently Used* : Viene utilizzato un contatore di età che si resetta quando si carica un blocco e ogni accesso i contatori del set sono incrementati di uno
- ![[Pasted image 20241204215949.png]]


# Gestione operazioni di scrittura

![[Pasted image 20241204220033.png]]
![[Pasted image 20241204220043.png]]
![[Pasted image 20241204220053.png]]
![[Pasted image 20241204220102.png]]
![[Pasted image 20241204220109.png]]