# Limiti dei circuiti di commutazione

Nei circuiti che abbiamo visto manca l'operazione di retroazione, ovvero abbiamo solo visto input che diventano output; manca l'operazione di un output di ridiventare l'input iniziale.
A disposizione  solo i circuiti iniziali non potremmo implementare **elementi di memoria**.

# Circuito Latch
![[Pasted image 20241025115050.png]]
Permette di catturare un bit di informazione, anche cambiando l'input non cambia l'output.
R sta per input di Reset, S sta per input di Set. Q è l'uscita memorizzata dal circuito Latch, $\bar{Q}$ è l'inverso.
Ho problemi quando sia reset e il set sono uguali a 1 e 1, dato che avrei come output 0, 0 e non avrei come output un bit e dall'altra parte il suo inverso.
Se ho Set e Reset uguali a 0, mantengo il risultato dell'operazione precedente.

Q diventa 1 solo se ho S = 1 e R = 0. Se R = 1 mi si spegne Q
## Problema del Latch

Devo campionare gli input del latch solo quando so che i valori in input sono stabili (non 1,1).
Quando applico questo cambiamento ho un circuito Flip Flop SR

# Flip Flop

Bisogna ricordarsi che all'accensione di S, il mio input Q si memorizza. Se invece ho come input R, $\bar{Q}$ si memorizza ad 1.
Si basas sull'aggiunta di un segnale di clock al latch.

## Flip Flop SR
![[Pasted image 20241025120225.png]]

## Flip Flop JK
Risolve il problema per cui si potevano creare reti indeterminate nel flip flop.
La rete rende impossibile che si verifichi la condizione S = 1 e R = 1 in input al flip flop.
![[Pasted image 20241025121004.png]]
Lo svantaggio di questo circuito è che devo sempre tirare fuori il valore negato.

## Flip Flop D

![[Pasted image 20241025121348.png]]


## Flip Flop T
![[Pasted image 20241025121506.png]]

# Fronti di commutazione

I miei clock devono avere un periodo con lo stesso segnale, senno il mio flipflop potrebbe perdere dei valori. Ogni flip flop ha bisongo di unda durata di segnale diversa.
![[Pasted image 20241025121805.png]]
![[Pasted image 20241025122003.png]]
Il miglior modo di utilizzare i clock CK è considerare solo lo spazio di tempo di salita del segnale.

# Reti sequenziali

I circuiti che implementano i flip flop sono reti sequenziali, che ha un funzionamento che evolve nel tempo, è quindi necessario definire uno stato interno per descrivere l'evoluzione nel tempo.

![[Pasted image 20241025123056.png]]

Con questa funzione (sequenziale) calcoliamo sia un output che uno stato interno.

Per manipolare questi oggetti ci servono altri tipi di astrazione dato che l'algebra booleana non lo permette.
![[Pasted image 20241025123541.png]]

# Macchine a stati finiti
Una macchina a stati finiti lavora sulla memoria, è una macchina astratta che si trova in uno stato temporaneamente (tra un insieme di finiti stati). Eventi esterni provocano un cambiamento di stato e la macchina genera un output verso l'esterno. Ne esistono due tipi

## Macchina di Mealy
Abbiamo una sestupla, con un alfabeto di ingresso I (insieme di caratteri che possiamo leggere), insieme di stati interni possibili (S), uno stato iniziale in cui ci troviamo all'inizio $s_{0}$, l'alfabeto di output (O), una funzione di trasizione e una funzione output.

![[Pasted image 20241025123851.png]]

## Macchina di Moore

Molto simile ma non riceve un input corrente dello stato.
![[Pasted image 20241025123956.png]]


## Rappresentazioni Alternative
Ci permettono di semplificare le macchine di Mealy e Moore.

### Diagramma degli stati
![[Pasted image 20241025124040.png]]
Abbiamo dei valori chiamati nodi e delle frecce chiamate archi. I nodi sono gli stati, le frecce le transizioni, determinano uno stato a quali stati può andare a seconda dell'input ricevuto.

### Tabellare
![[Pasted image 20241025124322.png]]

## Equivalenza fra modelli

Posso passare da una macchina di Moore a una di Mealy e viceversa senza probleimi. I due modelli sono equivalenti.
![[Pasted image 20241025124659.png]]
La trasformazione da macchina di Mealy a una macchina di Moore è meno immediata, possiamo avere più transizione verso lo stesso stato che generano output differenti, in questo caso dobbiamo decomporre in più stati differenti.
![[Pasted image 20241025124810.png]]

# Sintesi delle macchine a stati
![[Pasted image 20241025124925.png]]

# Esempi

## Sintesi della macchina che accetta stringa "mamma" in input

### Modello di Mealy
$$I = \{m,a\}, o=\{si,no\}$$![[Pasted image 20241028141619.png]]

Uno stato pozzo è la "fine" del nostro programma.
In questo caso lo stato pozzo è 5, se volessimo toglierlo mettiamo una freccia da 4 a 1 quando riceviamo una a.
Mentre se vogliamo che si interrompe, mettiamo tutte le frecce errate che vanno a 1, a 5. In modo che l'errore vada a 5 e poi in loop.

### Modello di Moore
![[Pasted image 20241028143731.png]]


## Come realizzarla con circuiti
Devo scegliere una codifica arbitraria

| i   | x   |     | O   | Z   |
| --- | --- | --- | --- | --- |
| m   | 0   |     | No  | 0   |
| a   | 1   |     | Si  | 1   |

Dobbiamo anche farlo per i nostri Stati, scegliamo la codifica binaria


| S   | y1  | y2  | y3  |
| --- | --- | --- | --- |
| 0   | 0   | 0   | 0   |
| 1   | 0   | 0   | 1   |
| 2   | 0   | 1   | 0   |
| 3   | 0   | 1   | 1   |
| 4   | 1   | 0   | 0   |
| 5   | 1   | 0   | 1   |

Per il calcolo di stato, utilizziamo la stessa tabella ma con una variabile in più che l'input ricevuto.


| S   | y1  | y2  | y3  | x   | y'1 | y'2 | y'3 | Z   |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 0   | 0   | 0   | 0   | 0   | 0   | 0   | 1   | 0   |
| 1   | 0   | 0   | 1   | 1   | 0   | 0   | 0   | 0   |
| 2   | 0   | 1   | 0   | 0   | 0   | 0   | 1   | 0   |
| 3   | 0   | 1   | 1   | 1   | 0   | 1   | 1   | 0   |
| 4   | 1   | 0   | 0   | 0   | 0   | 0   | 0   | 0   |
| 5   | 1   | 0   | 1   | 1   | 1   | 0   | 0   | 0   |

Quando lo trasformo in circuito, i miei bit che rappresentano lo stato, gli devo "salvare" in un flipflop, dato che deve essere memorizzato per essere utilizzato dal mio circuito.
Dopo quello stato salvato dal flipflop lo devo mettere come valore di y1, in caso lo stato sia y'1.
E' imporatne mettere un clock ai flipflop dato che ho complessità diverse nei circuiti.