![[09-TipiDati.pdf]]

Un **dato** è un valore che appartiene ad un insieme.
**Un tipo di dato (astratto)** è costituito da un insieme di valori e dagli operatori su questi valori hanno senso. (Per esempio con le stringhe contare i caratteri, concantenare stringhe, etc... sono tutti operatori che prendono stringhe per ottenere un altro tipo di dato o informazione).
**Struttura dati è un modo che un tipo di dato è rappresentato all'interno del mio calcolatore.**
A ciascun tipo di dato astratto possono corrispondere più **realizzazioni** diverse.
Bisogna prima ragionare su quale *operazioni* il mio dato potrà subire, per poi studiarne le **rappresentazioni**.

# Tipi di dati astratti
## Sequenza
Un insieme di elementi (stessi tipo di dato) caratterizzati da una **posizione**:
$$S = s_1,s_2,...,s_n$$
Esistono delle posizioni speciali $pos_{0}, pos_{n+1}$ che marcano inizio e fine della sequenza.
#### Metodi di una Sequenza
![[Pasted image 20241028094942.png]]
empty() mi ritorna se è vuota
head() ci dice dove comincia
tail() dove finisce
next() elemento successivo
prev() elemento precedente
insert() inserisci elemento (dove lo inserisci si può decidere)
remove() togli elemento

## Insiemi ("SET")
un insieme è una collezione di elementi idetificabili.
- Il numero di elementi di un insieme ha cardinalità $|A|$
- Un insieme che non contiene niente si dice vuoto
- Se un elemento appartiene ad A, $x \in A$
- $A \subseteq B$ se ogni insieme di A appartiene anche a B.
Sugli insiemi si applicano operatori di *unione e differenza simmetrica*

### Operazioni sugli insiemi
![[Pasted image 20241028095844.png]]
size() dimensione
contains(item x) dice se contiene quell'elemento
insert(item x) inserisce un elemento
remove() lo rimuove
Set union() unione fra insiemi
intersection() Intersezione
difference() differenza

## Altri esempi di Insiemi
![[Pasted image 20241028095958.png]]
### Grafo
![[Pasted image 20241028101319.png]]
$V$ = {1,2,3,4,5,6} sono i nodi
$\varepsilon$ = {(1,2),(1,3),(2,4),...} 
Questo è un grafo **orientato**, dato che l'arco (1,2) significa che parte da 1 e arriva da 2, ed è **diverso** da (2,1).
Se il grafo **non** fosse orientato, posso scrivere sia (1,2) oppure (2,1) dato che sono la **stessa cosa**.
### Albero 
![[Pasted image 20241028101353.png]]
E' un grafo senza cicli, ovvero un grafo le cui frecce non ritornano al punto di partenza, come per esempio un grafo orientato senza ripetizioni su se stesso.