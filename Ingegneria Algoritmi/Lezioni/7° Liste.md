Le liste sono strutture dati che realizzano il tipo di dato astratto "Sequence". Sono composte da **Node**.
![[Pasted image 20241028122148.png]]
Per accedere a questi Node, abbiamo bisogno di un pointer che punta al primo Node della lista, questo pointer si chiama Head ed è la List in sè.
A differenze degli array, gli address di memoria non per forza sono "vicini fra di loro" ma ci possono essere dei salti.
# Liste con puntatori singoli
Ci permettono di realizzare operatori **empty, head, next e insert** con complessità O(1); la complessità degli operatori **prev, remove** è O(n). Quella dell'operatore *tail* dipende dalla implementazione.
La lista in sè è un puntatore che punta alla struttura.
Ciascuno "**nodo**" è un elemento della lista che contiene due componenti:
- Un campo **value** che è il valore del dato;
- Un campo **next** che contiene il puntatore address al prossimo node;
L'ultimo elemento della lista ha un campo *next* che vale null.

```
typedef struct node{
	int val;
	struct node *next; //*next è il pointer a un'altro
	struct node
}Node

Node *list;
```

Possiamo dire che una lista è strutturata in questo modo.

![[Pasted image 20241028104931.png]]

## Vediamo gli operatori (Metodi della Lista)
```
EMPTY
bool empty(Node *list){
	return (list == NULL) //vede se il puntatore lista è vuota
}
HEAD
Node *head(Node *list){
	return(list); //ritorna il puntatore della lista quindi
	il primo elemento
}
NEXT
Node *next(Node *pos){
	return(pos -> next) // next è il puntatore della lista
	che punta all'elemento successivo, pos punterà a
	quell'elemento
}
INSERT
//Dobbiamo dire alla funzione dove inserire l'elemento
//Dobbiamo prendere il puntatore dell'elemento precedente
che punta a quello successivo e farlo puntare al nostro
nuovo elemento
//Poi dobbiamo fare puntare il nostro nuovo Node a quello successivo
typedef struct list{
	Node *head;
}List
if (list == NULL){return (NULL)};
if (list -> head == NULL){
	list -> head = NULL;
	new -> next = NULL;
}
else if (pos == NULL){
	tempo = list -> head -> next;
	list -> head = new;
	new -> next = tempo;
}
Node *insert( List list, Node *pos, Node *new){
	Node *temp = pos -> next;
	pos -> next = new;
	new -> next = temp;
}

```

Qui abbiamo che il "Head" del nostro codice è in realtà List, il puntatore del primo node, mentre head è il primo node.

![[Pasted image 20241028124856.png]]
Qui vediamo come identificare i pointer.
Se io faccio head -> link, ho come risultato il pointer che punto al prossimo node.
Ma se io faccio head -> link -> sto dicendendo NodeSuccessivo -> link,
Quindi sto prendendo il link del secondo node, ovvero il pointer che punta al terzo e così via..



# Codice Lista Singola




# Liste con puntatore doppio
Ogni nodo della lista ha 3 componenti:
- value
- next 
- prev
Quindi abbiamo in aggiunto un puntatore che indica il nodo precedente, questo ci permette di avere il metodo *prev* con costo O(1).

# Array Lists
Possiamo implementare le liste anche tramite l'utilizzo di array, in questo caso la nostra lista avrà la seguente struttura:
- Un vettore V che contiene i valori;
- La dimensione del vettore D;
- Il numero di elementi attualmente presenti K, ovvero l'indice dell'ultimo elemento occupato S.
Se vogliamo aggiungere nuovi elementi al nostro array dobbiamo controllare se il nostro array è pieno, ovvero se la dimensione dell'array è uguale agli elementi presenti.
In caso vogliamo per forza aggiungere un elemento all'array pieno dobbiamo utilizare *realloc* per dare più memoria all'array, successivamente anche aggiornare la dimensione dell'array.

Il costo medio di ogni singolo inserimento è O(N), possiamo però invece di allocare semplicemente la un elemento per il nostro array, aggiungerci due volte la grandezza dell'array originale, in questo modo avremmo una complessità di log(N)<< N




# Pile(STACK)

E' un modo di gestire la lista dove:
- Gli inserimenti avvengono solo dopo l'ultimo elemento
- La cancellazione avviene solo sull'ultimo elemento.
Abbiamo come metodi:
- push
- pop
- top (l'elemento incima alla pila ovvero l'ultimo)

![[Stack.c]]
# Coda(QUEUE)
- Gli eventi avvengono solo ad un estremo della lista, che sia inizio o fine.
- La cancellazione e inserimento avviene solo all'estremo scelto.
Metodi:
- enqueue (inserimento)
- dequeue (cancella elemento e ritorna quello cancellato)


![[Queue.c]]





