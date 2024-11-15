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

```
#include <stdio.h>
#include <stdlib.h>

// Structure of a Binary Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int v) {
    struct Node* node =
      (struct Node*)malloc(sizeof(struct Node));
    node->data = v;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to print preorder traversal
void printPreorder(struct Node* node) {
    if (node == NULL)
        return;

    // Deal with the node
    printf("%d ", node->data);

    // Recur on left subtree
    printPreorder(node->left);

    // Recur on right subtree
    printPreorder(node->right);
}

// Driver code
int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    // Function call
    printf("Preorder traversal of binary tree is:\n");
    printPreorder(root);
    printf("\n");

    return 0;
}

```
#### Inorder Traversal (left-current-right)
![[Pasted image 20241111110807.png]]
Saltiamo la root e partiamo dal node più in basso a sinistra, poi una volta finito il sotto albero a sinitra, leggiamo la root, e passiamo a destra

```
#include <stdio.h>
#include <stdlib.h>

// Structure of a Binary Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to print inorder traversal
void printInorder(struct Node* node) {
    if (node == NULL)
        return;

    // First recur on left subtree
    printInorder(node->left);

    // Now deal with the node
    printf("%d ", node->data);

    // Then recur on right subtree
    printInorder(node->right);
}

// Function to create a new node
struct Node* newNode(int v) {
    struct Node* node = 
      (struct Node*)malloc(sizeof(struct Node));
    node->data = v;
    node->left = node->right = NULL;
    return node;
}

// Driver code
int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    // Function call
    printf("Inorder traversal of binary tree is: \n");
    printInorder(root);

    return 0;
}

```
#### Postorder Traversal (left-right-current)
![[Pasted image 20241111110937.png]]

Come prima, ma invece di leggere la root passiamo all'ultimo nodo destro per poi salire.
```
#include <stdio.h>
#include <stdlib.h>

// Structure of a Binary Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int v) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = v;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to print postorder traversal
void printPostorder(struct Node* node) {
    if (node == NULL)
        return;

    // First recur on left subtree
    printPostorder(node->left);

    // Then recur on right subtree
    printPostorder(node->right);

    // Now deal with the node
    printf("%d ", node->data);
}

// Driver code
int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    printf("Postorder traversal of binary tree is:\n");
    printPostorder(root);
    printf("\n");

    return 0;
}

```
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


## Proprietà
La root dell'albero è SEMPRE nera, ogni node è o rosso o nero, i node rossi NON possono avere figli rossi, tutti i percorsi da un nodo fino alle foglie ha lo stesso numero di node neri, tutte le foglie sono nere.

## Insertion
Quando facciamo l'insertion dobbiamo verificare se abbiamo violato qualche prorietà, solo in caso il parente è rosso, se il parente è nero non ci sono problemi