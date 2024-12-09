Gli alberi sono una struttura dato:
- Costituito da nodi collegati tra loro;
- Ogni nodo ha solo un nodo padre, e può avere degli antenati
- La radice (primo nodo) non ha padre
- Ogni nodo può avere più figli e discendenti
- Da ogni nodo parte un sotto albero di cui il nodo stesso è la radice
- Un nodo senza figli si dice foglia

Una struttura ad albero ha un'altezza che è pari a quanti nodi bisogna attraversare per arrivare alla root.
# Visita di un albero
Un'operazione fondamentale che ci premette di attraversare un albero, dandoci la possibilità di :
}
- Stampare i contenuti del nodo attuale
- Mettere i condetenuti del nodo in un insieme di dati

# Strutture ad albero in C
In C le strutture ad albero sono uno struct composto da un valore, e diversi puntatori che sono i linker fra dei rami, quindi per esempio il ramo sinistro e il ramo destro.
```
typedef struct tree{
	...
	struct tree *right;
	struct tree* left;
}tree
```

# Binary tree
Un binari tree ha la proprietà che ogni node ha due figli, tranne all'ultimo livello dove ci possono essere meno di 2 foglie per node.
In caso è perfetto allora tutti i nodi hanno due figli.

## Traversal di un Binary Tree

Il traversal di un Binary Tree significa visitare tutti i nodi in un certo ordine e vedere il valore del suo dato.
Esistono due tipi di traversal con poi le loro sotto categorie:

### Depth-First Search (DFS)
Esploriamo fino alla fine dell'albero, per poi tornare indietro, ne esistono 3 Tipi:
#### Preorder Traversal (current-left-right)
![[Pasted image 20241111110608.png]]
Legge come prima cosa la root, per poi andare come segue le frecce.
#### Inorder Traversal (left-current-right)
![[Pasted image 20241111110807.png]]
Saltiamo la root e partiamo dal node più in basso a sinistra, poi una volta finito il sotto albero a sinitra, leggiamo la root, e passiamo a destra

#### Postorder Traversal (left-right-current)
![[Pasted image 20241111110937.png]]

Come prima, ma invece di leggere la root passiamo all'ultimo nodo destro per poi salire.
### Level Order Traversal (BFS)
Leggiamo i nodi in ordine da destra sinistra su come stanno messi sul piano.
![[Pasted image 20241111111114.png]]

```
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

void printCurrentLevel(struct Node* root, int level);
int height(struct Node* node);

// Function to print level order traversal a tree
void printLevelOrder(struct Node* root) {
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}

// Print nodes at a current level
void printCurrentLevel(struct Node* root, int level) {
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

// Compute the "height" of a tree -- 
int height(struct Node* node) {
    if (node == NULL)
        return 0;
    else {
        int lheight = height(node->left);
        int rheight = height(node->right);
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}

struct Node* createNode(int data) {
    struct Node* node
        = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}
int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    printLevelOrder(root);
    return 0;
}

```
# Binary search tree
A differenza dei binary tree, i binary search tree hanno i loro valori messi in ordini precisi.

Per la *min Heaps*
**Il padre è MAGGIORE rispetto al figlio a sinistra e MINORE rispetto il figlio a destra**.
Per la *max Heaps*
**Il padre è MINORE rispetto al figlio a sinistra e MAGGIORE rispetto il figlio a destra**.

Questo ci permette di cercare valori facilmente. Voglio cercare un numero? Lo campare al root node, il numero è quello? Ho finito, senno verifico se è minore, in caso positivo allora vado in un branch, in caso è maggiore nell'altro.

# Alberi Bilanciati
Un albero è bilanciato se la sua altezza è $O(log (n))$ dove n sono i nodi.
Per capire se un albero è bilanciato possiamo vedere.
- se la differenza fra l'altezza di destra e sinistra dei sottoalberi deve essere al massimo 1
- Per tutti i nodi, il suo left e right subtree deve essere un albero binario bilanciato


# Alberi AVL

E' un albero self-balanced, mantengono un bilanciamento assicurandosi che la differenza di altezza dal sotto albero sinistro e destro di ogni nodo è al massimo 1. 
Dobbiamo ricordarci che è sempre un albero di ricerca binario, quindi a sinistra dobbiamo mantere sempre un sotto albero che ha valori inferiori del suo nodo genitore e a destra superiori.

Nella struttura del dato oltre ad avere il valore, nodo sinistro e destro, abbiamo anche l'altezza del nostro nodo.

La differenza di altezza fra questi alberi può essere -1,0,1, e questa differenza viene chiamato fattore di bilanciamento.
Alberi che non rispettano questo bilanciamento hanno su di loro una specifica operazione di rotazione, abbiamo 4 possibili casi:

## Right Rotation (RR)

Questa è una rotazione che viene messa in atto quando abbiamo uno sbilanciamento a sinistra, il modo per risolvero è prendere il noto sbilanciato e ruotarlo a destra
![[Pasted image 20241111125518.png]]

## Left Rotation (LL)
Lo stesso caso di prima ma abbiamo uno sbilanciamento nei nodi di destra.
![[Pasted image 20241111125601.png]]

## Left-Right Rotation(LR)

Applichiamo due rotazioni, in modo da prendere un nodo a sinistra del root, ponendo quel nodo come root e la root a destra dato che è maggiore e poi bilanciando l'albero.

![[Pasted image 20241111125853.png]]

## Right-Left Rotation

Stessa cosa ma adesso la root diventa quello più piccolo.
![[Pasted image 20241111125932.png]]
# Alberi Rosso e Neri

Un albero nero rosso è un albero self-balancing binary search tree, dove ogni nodo ha un attributo aggiuntivo, un colore, che può essere nero o rosso. Questo albero è importante per mantere una complessità durante l'inserimento e cancellazione.

Un *self-balancing tree*, vuol dire che applichiamo delle rotazioni al nostro albero per ottenere l'organizzazione della struttura dato necessaria.

Il nostro struct sarà il seguente:
- Node Color
- Value
- Left-Child
- Right-Child

![[Pasted image 20241118104125.png]]
![[Pasted image 20241118104158.png]]
## Proprietà
**La root dell'albero è SEMPRE nera**, ogni node è o rosso o nero, i **node rossi NON possono avere figli rossi**, tutti i percorsi da un nodo fino alle foglie ha lo stesso numero di node neri, tutte le foglie sono nere.

## Insertion
Quando facciamo l'insertion dobbiamo verificare se abbiamo violato qualche prorietà, solo in caso il parente è rosso, se il parente è nero non ci sono problemi

![[Pasted image 20241118104242.png]]

## Applicazione in C

Abbiamo 4 operazione possibili da applicare ai nostri alberi:

### Insertion

Questo include una doppia verifica; facendo una semplice inserzione dei binary search tree, per poi controllare il colore se è corretto o meno.

Se il parent è nero, nessuno proprietà è violata, se è rosso c'è una possibile violazione.

Soluzione:

- Se lo zio è rosso, dobbiamo ricolorare il parente e lo zio neri, e i nonni rossi. Per poi muoverci verso l'insù per controllare altre violazioni.
- Se lo zio è Nero: se il nodo inserito è a destra, faccio una left rotation al genitore; se è inserito a sinistra faccio una right rotation ai nonni e ricolorare appropriamente.

### Ricerca
Come un binary search tree

### Deletion

BST deletion.
Controllare se c'è una double black condition.

Se la double black condition si realizza, abbiamo due casi:
- fratello è rosso : rotazione del genitore e ricoloramente del parente e fratello
- Fratello è nero : 
  - Figli del fratello sono neri: ricoloriamo il fratello e propaghiamo il controllo del doppio nero verso l'alto
  - Almeno uno dei figli del fratello è rosso : 
    - Se il figlio lontano è rosso: facciamo una rotazione al parente e fratello riapplicando un coloramento.
    - Se il figlio vicino è rosso: rotazione al fratello e figlio e si controlla come sopra


### Rotazione
#### Left Rotation

Before Rotation:

    x                                              
     \                                             
      y                                                         
     / \                                                     
    a   b                                                     

After Left Rotation:

      y
     / \
    x   b
     \
      a

Metto y come il figlio destro di x
muovo il sotto albero sinistro di y come sotto albero destro di x
aggiorno i parenti di x e y
aggiorno il parente di x al punto y invece di x
metto i figli sinistri di y a x
aggiorno il parente di x come y.

#### Right Rotation

Befor Right Rotation:    

	   x
       /
      y
	/ \
	a  b

After Right Rotation:

	   y
	   / \
	  a   x
        /
        b

### Dove applicare le rotazioni

#### Rotazione dopo Insertion
![[Pasted image 20241118110147.png]]

#### Rotazione dopo Deletion
![[Pasted image 20241118110212.png]]