L'ordinamento consiste nel mettere in relazione di ordine un insieme di oggetti.
La complessità migliore che ci possiamo aspettare è di:
$$nlog(n)$$

# Permutazione

Una sequenza di n oggetti distinguibili tra loro in uno specifico ordine.
Per esempio utilizzare una permutazione 
$$P = [6,0,3,2,5,6]$$
Come Indice di un array:
$$V[P[0]]$$
Accedendo a tutti gli elementi in un ordine creato dalla **permutazione**.

Ci sono metodi che cercano la permutazione corretta eseguendo tutto le possibili permutazioni.

Vediamo altre sorting methods:

# Bubble Sort

Il bubble sort è uno degli algoritmi meno efficienti di sorting da implementare ma anche quello più semplice.
Ogni iterazione dell'algoritmo compara gli elementi adiancenti nell'array,spostandoli in caso uno sia maggiore dell'altro. Ogni iterazione k porterà il k-esimo numero più grande alla fine.
L'algoritmo si ferma quando non avviene nessuno swap.
$$Time \ Complexity : O(n^{2})$$
# Inserition Sorting

L'Insertion sorting consiste nel dividere il nostro array in una porzione sorted e una non-sorted.
Iniziamo al secondo elemento dell'array, e lo compariamo al primo, scambiandoli se necessarrio. Così i nostri primi due elementi saranno sorted. Successivamente compariamo il terzo elemento con i primi due, mettendono nel posto corretto. Poi il quarto con i primi tre. E così via.

![[Pasted image 20241114133905.png]]

![[InsertionSorting.c]]

L'inserion sorting ha come complessità
$$\Omega(n),O(n^{2})$$

# QuickSort
Un Sorting Algorithm che lavora sul principio di **divide and conquer**, ovvero dividere il nostro problemi in sotto categorie di problemi più piccoli.
Ci sono tre step principali per farlo:
- Scegliere un **Pivot**, ovvero l'elemento su cui dopo useremo per dividere il nostro array in sottoproblemi
- **Partizione dell'Array** : Riodiniamo l'array inotrno al pivot, tutti gli elementi più piccoli saranno a sinistra, mentre quelli più grandi saranno a destra. Mentre il pivot si troverà nella posizione corretta.
- **Ricorsivamente** applichiamo la funzione alle altre sezione partizionate.
- **Base case** finiamo quando esiste solo un elemento nella partizione di sinistra.

![[Pasted image 20241114150722.png]]

## Scelta del Pivot

### Prendere ultimo o primo elemento
Questo rende più possibile ottenere il Computational Time maggiore.

### Prendere un elemento random
Scelta ottima, permette di eleminari il peggiore caso del sorting.

### Prendere l'elemento che è in mezzo a tutti
Scelta migliore, dato che troviamo il mezzo in un tempo di complessità lineare, questo significa calcolare l'elemento che sta in mezzo all'array.

## Partizione dell'Array
Abbiamo tre modi per farlo
### Creare una copia dell'array
Mettiamo gli elementi più piccoli a sinistra del pivot, quelli più grandi a destra, e poi ricopiamo l'array temporaneo in quello originale.

### Scambio contemporaneo
Controlliamo sia il primo che ultimo elemento, scambiandoli in continuazione a seconda se sono maggiori o minori.

## Svolgimento 
![[Pasted image 20241114164823.png]]

![[QuickSort.c]]


# MergeSort

Anche questo come il QuickSort utilizza il metodo **divide and conquer**. Ricorsivamente suddividiamo l'array di un input in sotto array, facendo un merge finale per ottenere un array sorted.
Il merge sort ha una complessità di computazione standard di :
$$O(nlog(n))$$

## Steps

- Divide : dividiamo l'array in due finchè non può più essere diviso
- Tutti i sotto array sono sorted
- Vengono Merged togheter.