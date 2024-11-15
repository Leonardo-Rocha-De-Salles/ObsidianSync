I circuiti logici sono reti di componenti che accettano variabili booleane e le restutuiscono anche come output.
Permettono di utilizzare l'algebra booleana nel mondo reale.
Gli operatori booleani implementati in hardware da circuiti chiamati *porte logiche*, vediamo alcune standard:
![[Pasted image 20241014151207.png]]
# Negazioni e porte a più ingressi
Per rappresentare la negazione di una variabile, mettiamo un pallino vicino al suo input.
Possiamo anche costruire porte logiche a più entrate, ma le rappresentiamo in modo diverso.
![[Pasted image 20241014151337.png]]
Possiamo utilizzare le porte a più ingressi grazie alla proprietà associativa e commutativa 
$$(x_0x_1)x_{2}=x_0(x_1x_2)$$
Ci sono però operatori che non si possono rappresentare semplicemente grazie alle proprietà.

# NAND a più ingressi
Il NAND a più ingressi **è una funzione diversa dal NAND dell'algebra booleana proprio perchè essa non è associativa!**.
![[Pasted image 20241014151641.png]]
![[Pasted image 20241014151631.png]]Quindi per comodità possiamo rendere associativo l'operatore NAND dato che funziona nei circuito (non funziona però nell'algebra booleana).


# Porte logiche a diodi
La corrente scorre da una tesione alta a una bassa, il filo non provoca un cambio di tensione quindi lo possiamo ignorare, mentre con i resistori abbiamo un rallentamento del passaggio della corrente, provocando una caduta di tensione.
Per i circuiti i diodi perfetti sono una specie di valvola, che fanno passare la corrente in un'unica direzione.
Se la direzione opposto al diodo è bloccata, esso non può far scorrere la corrente e quindi essa andrà a circolare nel componente successivo, come se tutto ciò che c'è dopo il diodo (esso incluso) non esiste.

## Struttura di un diode

Un diode è costituito da una struttura chiamata pn junction. Il terminale attaccato al semiconduttore di tipo P si chiama **anode**, il terminale attaccato al semiconduttore di tipo n si chiama **cathode**.
![[Pasted image 20241017163404.png]]
Nel Diode se colleghiamo all'anode un potenziale positivo e al cathode uno negativo, la corrente passerà al diode e il diode entrerà in modalità polarizzata attiva.
Se abbiamo il caso contrario la corrente non scorrerà, il diode starà in polarizzazione inversa finchè esso è in grade di bloccare il passaggio di corrente.

## Porta AND
![[Pasted image 20241014152202.png]]
**Tensione alta è il mio 1 logico, mentre la tensione bassa è il mio 0 logico**.
Perciò qui abbiamo una tabella di verità $V_{L}\ e \ V_{H}$.
### Come funziona

Abbiamo la nostra corrente che scorre dal VCC verso $V_1$ e $V_2$ dato che essi hanno una tensione maggiore rispetto a $V_{out}$, un **Diodo** funziona in tal modo che la corrente passi solo verso la direzione della freccia. Però in caso producessimo una corrente da $V_{1},V_{2}$ questo comporterebbe un blocco al flow del Diodo, infatti la corrente si bloccherebbe davanti al diodo dato che non può passare e scorrerebbe al luogo con la seconda tensione maggiore. Se sia $V_{1},V_2$ sono accesi e quindi con una corrente che blocca lo scorrimento di corrente, la nostra corrente può solo andare nell'output $V_{out}$, rendendo così acceso il nostro circuito AND.

## Porta OR
![[Pasted image 20241014152612.png]]Queste componenti non vengono più utilizzate nei computer moderni dati che interferiscono un po' con la corrente in circolazione nel sistema, se ho tante componenti, da un voltaggio iniziale alzo arrivo a una tensione bassa alla fine, che è sbagliato.
**Questo è il motivo per cui si utilizzano i transistor**
### Come funziona
Qui abbiamo sempre una storia sui Diodi, che però in questo caso basta che uno dei due sia acceso per andare nel nostro voltaggio di output, dato che i diodi non impediscono il flusso di corrente e abbiamo solo un ground.


# Transistor

Esistono due tipi di transistor, *NPN* e *PNP*
## Struttura di un transistor
Un transistor è composto da un **Base, Collector, Emitter**. Se la base riceve una corrente, il transistor si apre, facendo scorrere la corrente dal colletor all'emmiter (descritto con una freccia)


## NPN
Abbiamo una bipolar junction transisotor, dove il nostro transistor è diviso in tre giunzioni suddivise da un materiale semiconduttivo.
Abbiamo tre suddivisioni N P N, da qui il nome.
L'emitter e il collector del transistor sono collegati al semiconduttore di tipo N, mentre la base al semiconduttore di tipo P.
Essenzialmente abbiamo due Diode che puntano verso le N al centro del diode.
![[Pasted image 20241017170213.png]]

Nel NPN la freccia punta verso il filo dell'emitter.
Solitamente il nostro emitter è collegato al suolo e il collector va verso la fonte di voltaggio e stesso vale per la base.
La correnta entra nella base. La direzione della freccia blue sta a dirci in che direzione scorre la corrente.


![[Pasted image 20241017163817.png]]

## PNP
In questo caso abbiamo 2 P tipo semiconduttori collegati all'emitter e collector, mentre la base alla n type semiconduttore.
Quindi abbiamo due diodi che puntano verso l'interno.
nella PNP la freccia parte dal filo dell'emitter e punta verso il transistor.
Solitamente il collector è collegato al suolo e lo stesso vale per la base, l'emitter va verso la fonte di voltaggio.
La corrente fuoriesce dalla base e scorre verso il collector.
![[Pasted image 20241017170201.png]]
## **La TTL** 
si basa sull'uso di transistor per la realizzazione della funzione di commutazione e di alcuni transistor NPN per l'amplificazione di segnale.
Esempio di una porta **NOT**
![[Pasted image 20241015113558.png]]
Da $V_{CC}$ ho una corrente, se applicono una tensione Alta da $V_{in}$ il transistor $Q1$ fa in modo che il transistor $Q2$ si apra, permettendo lo scorrimento della corrente verso terra, il punto di tensione più alta. E di conseguenza abbiamo un *Low* di output.

Se ho $V_{in}$ senza segnale, quindi 0, La corrente non scorrerà

## Logica CMOS
Circuiti molto più compatti, si usano i transistor pMOS e nMOS che si comportano in maniera inversa.
![[Pasted image 20241015114130.png]]
Abbiamo l'input che sta a dire se il transistor chiude il circuito (1) oppure lo lascia sconnesso (0).
Nel caso del nMos 1 chiude il circuito mentre per il pMOS rappresentato con un pallino 1 lo lascia aperto.




# Riduzione del costo nelle operazioni AND/OR
![[Pasted image 20241015115507.png]]
## Tecnologia in Open Collector
E' una soluzione per non far avvenire un accumulo di corrente all'interno dei miei transistor quando ho tante funzioni che arrivano in un unico punto.
Si basa nell'utilizzare il nostro output di un circuito, che sia 1 o 0, come input della base del nostro transistor, che appunto dipendendo questo input aprirà o chiuderà il circuito.
![[Pasted image 20241015115901.png]]
Qui è rappresentata una porta logica in Open Collector
![[Pasted image 20241015115946.png]]

![[Pasted image 20241015120135.png]]
Qui stiamo utilizzando un singolo filo per calcolare l'OR di tante funzioni Booleane.


# Buffer Three-State
Può avere tre possibili uscite, 0,1, alta impedenza (quando è staccato dal circuito). Se enable vale 1, collega il circuito, se vale 0, la corrente non passa dal Buffer.
![[Pasted image 20241015120702.png]]

# Dalle Funzioni Booleane ai Circuiti

## Dal Circuito alla Funzione

$y= \ valore \ di \ uscita$
![[Pasted image 20241015121003.png]]


## Dalla funzione al circuito
![[Pasted image 20241015121229.png]]
![[Pasted image 20241015121257.png]]

## Qualità di un circuito
Dipende dal costo per realizzarlo e il tempo in cui impiega a calcolare i suoi ingressi, dato che i circuiti di commutazione hanno un ritardo di calcolo.
Ogni porta logica, porta con sè un ritardo di commutazione, ovvero il tempo che serve per passare dallo stato sbagliato a quello corretto.
Questo tempo è importante perchè non posso cambiare il valore dell'input nel mentre il mio circuito ancora non ha finito il calcolo, dato che scarterebbe la funzione. 
![[Pasted image 20241015121915.png]]
Il tempo di propagazione si accumula quando si hanno tanto porte logiche e calcoli di funzioni interconnessi. Per stimare la prestazione si può ripercorrere al *critical path*, ovvero il percorso più lungo che un segnale di input deve attraversare nel circuito.
![[Pasted image 20241015122144.png]]
Assumendo che tutte queste 4 porte logiche hanno lo stesso tempo di propagazione allora abbiamo un ritardo di 4 volte il ritardo di propagazione di una.

### Minimizzazione del circuito
E' importante minimizzare un circuito utilizzando funzioni booleane per ridurre non solo le tempistiche di esercuzione ma anche il costo di produzione dato che ogni componente di un circuito ha un costo.
![[Pasted image 20241015122349.png]]


# Semplificazione di Circuiti
Come nell'algebra booleana abbiamo operatori elementari che abbiamo utilizzato per derivarne altri più complessi che però ci semplificano la scrittura, lo stesso faremo per i circuiti:

## Codificiatore(encorder)
è un circuito che realizza la funzione di codifica binaria, associa ad ogni elemento di un certo insieme di codifica composta da m simboli, ad una sequenza distinta di n bit.
Per ogni simbolo genera il codice corrispondente (con $2^{n}\geq m$).
Il circuito quindi ha m fili di ingresso $x_0,..,x_{m-1}$ ed $n$ linee di uscita $y_{0},...,y_{n-1}$
![[Pasted image 20241015123852.png]]
Esempio di un codificatore:
![[Pasted image 20241015123927.png]]
Ogni y rappresenta un bit in uscita, che è descritto da una certa funzione composta da m input, dipendendo dalla y.
Se per rappresentare uno degli output desirati, possiamo considerarla come un tabella di verità con un certo numero di variabili.
Per esempio in questa tabella, $y_{1}$ prende i seguenti valori : 0,1,0,1,0,1,0,1,0,1; perciò può essere descritta da una funzione booleana, ed evidentemente un circuito, grazie alla tabella di verità derivata.


## Decoficatore
L'inverso del codificatore, a partire da una parola di un codice binario, genera una uscita che identifica uno dei simboli dell'insieme di interesse.
*Per ciascuna configurazione di ingresso, una sola uscita vale 1, le altre 0.*
![[Pasted image 20241015124839.png]]
Possiamo costruire delle tabelle di verità per le $x_i$

| $y_1$ | $y_2$ | $y_3$ | $y_4$ | $x_2$ |
| ----- | ----- | ----- | ----- | ----- |
| 0     | 0     | 0     | 0     | 0     |
| 0     | 0     | 0     | 1     | 0     |
| 0     | 0     | 1     | 0     | 1     |
|       |       |       |       |       |
|       |       |       |       |       |
Possiamo continuare quanto vogliamo, ma queste funzioni booleane hanno il valore 1 per solo un punto della funzione.

![[Pasted image 20241015124925.png]]

Questi circuiti calcolano più volte gli stessi elementi, per esempio $y_4$ negato. Quindi per semplificarlo facciamo:
![[Pasted image 20241015124939.png]]
Dove prima facciamo tutte le possibili compinazioni fra le y. per poi associare a una coppia di prodotti un'altra coppia di prodotti, in modo di non dover fare ogni volta il prodotto.
In realtà questa rappresentazione è meno ottimale fisicamente rispetto a quello precedente, se l'hardware ce lo permette conviene utilizzare il primo.


## Multiplexer

Permette di effettuare una scelta, quando abbiamo vari circuiti ma in output dobbiamo mandare solo un risultato, scelto da delle variabili booleane che sceglie quale output mandare.
Quindi da diversi valori booleani ne manda solo uno in uscita selezionando.
Per deciderlo ho bisogno di altre variabili booleane, posso scegliere io quante, che mi permetteno di identificare quale dato voglio.
![[Pasted image 20241018113955.png]]
Qui le x rappresentano i valori di controllo booleani che userò per selezionare il mio output. Per esempio con valore delle x 000 sceglierei d0.

![[Pasted image 20241018114054.png]]
Ciascuno combinazione di x moltiplica se stessi con il valore d, e solo uno di questi prodotti farà 1.
Circuito corrispondente:
![[Pasted image 20241018114310.png]]


### Multiplexer come generatore di funzioni
Un multiplexer può essere utilizzato per implementare qualsiasi funzione booleana di n variabili, dato che possono essere rappresentati come tabelle di verità.

![[Pasted image 20241018114835.png]]

Come faccio? Conto le righe, quindi 4 possibili valori, per ogni valore ho un output noto. 
Per esempio nella tabella AND ho 0 0 0 1 come risultati, utilizzo le x per descrivere quando avrò le y a seconda delle x. per esempio con x1,x2 = 1, ho 1 in uscita.


# Demultiplexer

Ottenuto un input, faccio uscire n possibili uscite, ma ne seleziono soltanto una.
![[Pasted image 20241018115519.png]]
Dipende sempre dagli input di controllo x. Tutte le altre linee hanno segnale 0.



# Read Only Memory
Un tipo di circuito che implementa una memoria disolo lettura.
Dato un input viene fornito un output. E' molto semplice da realizzare, quindi posso fornire molti input e avere molti output.
Il nostro input è l'indirzzo  e l'uscita è il valore.
![[Pasted image 20241018120209.png]]

## Schema logico di una ROM

![[Pasted image 20241018120225.png]]
Tutti i valori in entrata, selezioneranno una sola riga. E ogni riga attribuirò un singolo valore logico. Visto che poi i fili si collegano a un gate logico OR, verrà acceso tutti quei valori attaccati alla riga selezionata.

Il fusibile è un circuito che attacco stacco, alcuni ci saranno, altri no e se non ci sono il filo è sconnesso, non accendendo gli output.

## Implementazione di una ROM
![[Pasted image 20241018120700.png]]

Si dice readonly dato che io non posso modificare i transistor presenti o meno nel mio sistema, una volta fabbricata rimane così.

Questa implementazione di ROM è scomoda, dato che potrei avere matrici di fili molto pià lunghi che alti.
Quindi dobbiamo cercare di renderla quadrata.


## ROM Paginata
![[Pasted image 20241018122217.png]]



# Programmable Logic Array

![[Pasted image 20241018123641.png]]
Una board dove possiamo mettere i fusibili dove vogliamo. Serve a progettare le memorie ROM.

![[Pasted image 20241018123712.png]]

Per esempio y1 qui è data da 3 variabili, e come possiamo vedere nei fusibili abbiamo 3 punti sulla y1. Quindi per esempio P1 dovrà valere 1 quando ($\bar{x_1}x_2\bar{x_4}$).
Posso calcolare contemporaneamente sia la rete AND che la rete OR.

![[Pasted image 20241018124100.png]]
































