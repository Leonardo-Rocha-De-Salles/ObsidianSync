
# Definizione di Grafo

Un grafo è un *struttura non lineare* che ha due componenti:

- Vertici : chiamati anche nodi
- Archi (edges): le due linee che collegano due nodi in un certo modo.

Un grafo è composto da un set di vertici e collegamenti, denotato come **G(V, E)**.

Terminologia grafi :

- **Orientati** : In caso il verso degli archi ha importanza
- **Non orientati** : In caso il verso dell'arco non importa
- **Nodi Adiacenti** : due nodi sono adiacenti se un arco li collega
- **Arco incidente** : L'arco che parte da i a j, si dice incidente su j da i
- **Grado di un nodo** : numero di archi incidenti su un nodo (Quanti archi puntano a un nodo).
- **Cammino** : Dato un grafo orientato, un *cammino* di lunghezza k è una sequenza di nodi, se non ci sono nodi ripetuti si dice semplice, si dice chiuso se il primo nodo è uguale all'ultimo. Se è sia semplice che chiuso allora è un *ciclio*.
- **Catena** : sequenza di nodi in un grafo NON orientato, se è semplice e chiuso di dice *circuito*.
- **Connessione forte** : Se un grafo orientato è fortemente connesso se per ogni coppia di nodi u,v esiste arco da u a v e da v a u.
- **Componenti formente connesse** : E' un sottografo formente connesso e massimale:
  - *Sottografo* : se per ha gli stessi nodi e collegamenti di un porzione di un altro grafo
  - *Massimale* : Se non esiste nessun sottografo fortemente connesso di un grafo che lo contiene

# Tipi di Grafo

## Grafo finito
Ha un numero finitio di nodi ed Archi
## Grafo infinito

## Grafo Semplice

Un grafo che per ogni nodo collegato, ha solo un arco che li collega

## Multi Grafo

Due nodi possono essere collegati da più archi.

## Completo

Se ci sono n nodi, essi sono connsessi a n-1 nodi.

## Pseudo grafo

contiene dei self loop


# Implementazione di Grafi

## Matrice di adiacenza

Le Righe rappresentano i Nodi di partenza, le colonne i Nodi di arrivo

### Non Orientato, Non Pesato
![[Pasted image 20241202105359.png]]
Denotiamo con colonne e righe i vertici, in caso due nodi sono connessi, mettiamo 1 nella corrisponente casella, 0 se no.


```C
#include <stdio.h>

void addEdge(int* mat, int i; int j){
	mat[i][j] = 1
	mat[j][i] = 1
	//In caso è orientata mettiamo un valore bool per capire
	//la direzione di orientamento
}

int main(){
	int nodes = 5;
	int* mat = (int*)malloc(sizeof(int)*5*5)
	addEdge(mat, 1, 2);
	addEdge(mat,2,4);
}

```


### Non Orientato, Pesato

![[Pasted image 20241202110511.png]]

Mettiamo NULL dove non ci sono collegamenti, e il valore del collegamento se è presente.

### Orientato, Unweigheted

![[Pasted image 20241202110813.png]]

### Orientato con Pesi

![[Pasted image 20241202110831.png]]

## Matrice di adiacenza nodi-archi

Come la nostra tipica matrice di adiacenza orientata, ma indichiamo con -1 se un arco esce da un nodo e con 1 se ci entra.

## Lista di adiacenza

Un array di dimensione n, dove per ogni nodo u viene predisposta la lista adj(u) per rappresentare i nodi adiacenti.

### Orientata, Unweigheted



### Non Orientata

### Orientata e Weighted

### Non Orientata Weighted

# Numero di Erdos

Erdos ha numero di Erdos uguale a 0, mentre tutte le altre persone al mondo, hanno il numero di Erdos uguale al numero di studi scritti con Erdos pari a 1 se l'hanno scritto direttamente con lui, 2 se l'hanno scritto insieme a qualcuno che l'ha scritto insieme a qualcuno che ha scritto uno studio direttamente con Erodos, quindi che ha numero di Erdos 1 e così via.


# Traversal

## BFS

Scelgo un nodo, vedo tutti i suoi adiacenti, per poi navigare a un suo adiacente e ripetere il traversal, sempre vedendo gli elementi mai visti in precedenza.


Creiamo un Queue, col il primo elemento quello con cui iniziamo, ogni volta che troviamo i nostri nodi adiacenti, li inseriamo nella Queue. Se un elemento non si trova nella queue, allora non è stato ancora trovato.

## DFS

Scelgo un nodo, vado a uno vicino e invece di tornare indietro, proseguo a uno vicino a quel nodo, se non ci sono adiacenti, torno indietro e provo a vedere se c'è un altro nodo adiacente a quello.

Si utilizza uno stack per implementarlo, iniziamo dal nodo che vogliamo e inseriamolo nello stack in caso ha degli adiacenti, se non ci sono adiacenti prendiamo dallo stack il più recente e vediamo se esso ha adiacenti. In caso non ho più niente nello stack significa che tutti i nodi adiacenti sono stati traversati ed è finito la nostra ricerca.