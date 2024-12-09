Un **Heap** è un complete binary tree data structure che soddisfa la proprietà di *heap*. Per ogni nodo il valore dei figli è maggiore o uguale al valore stesso del nodo.

Le heap sono solitamente utilizzati per implementare le Priority Queues, dove l'elemente più piccolo (o più grande) a alla radice dell'albero.

Abbiamo:
- **Max-Heap**: Il valore del root è il più grande di tutto l'albero, e lo stesso valore per i sotto alberi sinistri e destri con il root del sotto albero.
- **Min-Heap**: il valore del root è il più piccolo, questo vale anche per tutti gli altri sotto alberi come prima.
## Proprietà
- Il valore massimo o minimo è alla root dell'albero, questo permette sempre un tempo costante di accesso.
- The relationship between a parent node at index ****‘i’**** and its children is given by the formulas: left child at index ****2i+1**** and right child at index ****2i+2**** for 0-based indexing of node numbers.
- Posizione padre = (j-1)/2
- Tutti i livelli sono pieni, tranne possibilmente l'ultimo, riempito da sinistra a destra.
- Quando inseriamo lo facciamo all'ultimo slot possibile per poi riorganizzare i nodi.
- When we remove an item, we swap root with the last node to make sure either the max or min item is removed. Then we rearrange the remaining nodes to ensure heap property (max or min)

## Operazioni
![[Pasted image 20241118112003.png]]

In C le strutture heap vengono rappresentate tramite un array.
Dato un nodo, per trovare il suo parente o figli si usano le seguente formule (Assumendo che l'array parta da 0).

![[Pasted image 20241118112124.png]]

