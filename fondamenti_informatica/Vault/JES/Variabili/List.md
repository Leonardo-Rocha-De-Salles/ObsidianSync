meccanismo per rappresentare struttura di dati.
Una variabile all'interno con diversi elementi.

Gli elementi partono da 0 e vanno da sinistra a destra
Una lista è un oggetto mutabile, ogni suo componento può essere modificato.

List = \[elem_0, elem_1, ...]

![[Pasted image 20240519152231.png]]

Adesso andiamo a parlare di opertatori specifici alle liste:


myList.append(object): Inserisce l'oggetto alla fine della lista

	append: list X T --> none


myList.extend(mySequence): aggiunge gli elementi mySequence alla fine della lista. per preciso n elementi (lunghezza di sequence)

	extend: list × sequence → none


myList.insert(i, object): inserisce object nella posizione di indice i, il vecchio oggetto che si trovava in quell'indice i diventa i + 1

	insert: list × N × T → none

myList.remove(something): rimuove il primo something all'interno della lista.

	remove : list × T → none

myList.pop(): rimuove l'ultimo elemento della lista e ne restituisce il valore

	pop: list → T

myList.pop(i): come pop ma l'elemento i

	pop: list × N → T

myList.sort(): dispone gli elementi in ordine (alfabetico, numeri)

	sort: list → none

myList.reverse(): mette ultimo elemento come primo etc.

	reverse: list → none

myList.count(something): conta quante volte something compaia nella lista.

	count: list × T → N


ATTENZIONE: I metodi che ritornano none, se associate a variabili saranno nulle, se voglio fare il sort di una lista devo semplicemente scrivere il comando.

	myList.sort()