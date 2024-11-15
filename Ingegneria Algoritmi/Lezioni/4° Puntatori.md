Nel linguaggio C un puntatore è semplicemente una variabile che contiene *un indirizzo di memoria*.
![[Pasted image 20241018105607.png]]
la \* sta a rappresentare che quella variabile è associato a un puntatore, l'*int* davanti sta a dirci che in quello slot di memoria possiamo trovare un numero intero. Stesso vale per $(float \ *a \ ...)$. **Un puntatore ad un intero**.

## Come assegnare un indirizzo

Ci sono modi per associare un indirizzo ad un puntatore, il primo modo è di utilizza **&** davanti una variabile.
Quella è un'espressione che ha come valore l'indirizzo di memoria dove si trova quella variabile. Nell'esempio precedente dove si trova b.

Come sappiamo il nome di una variabile non è altro che un'etichetta di un sezione di memoria, quando faccio $a = \&b$, $a$ è una variable anche essa in uno slot di memoria, ma dopo che faccio l operazione con &, diventa la stessa informazione che punta, dove punta b.

Quando assegno a un puntatore un valore di memoria, è come se diventasse quella variabile, dato che assume il valore di quello slot di memoria. Se faccio print del puntatore con un **\***, printerà il valore della variabile assoicata. Se modifico la variabile a cui ho associta il puntatore, anche il valore del puntatore cambia, e se cambio il valore del puntatore con somme aritmetiche, cambia anche il valore della variabile associata al puntatore.
Se lo faccio senza asterisco printa lo slot di memoria.


## Come si usano i puntatori
$ptr \ è \ puntatore$
- Accedere al valore puntatore, vedere a cosa puntiamo $val = *ptr;$
- Accesso ad un indirizzo, ovvero dire al putatore a cosa punta $type \ *ptr = \&val;$ 
- Dichiarare la variabile puntatore $type *ptr;$
- Aritmetica dei puntatori $val = *(ptr+i) \qquad ptr++;$
- $*(ptr + i)$ Sommo un indirizzo a un numero, ritorna un altro indirizzo, che è l'indirizzo iniziale più tante byte quanti è $i$ moltiplicato per quanti byte occupa il tipo di puntatore (per esempio int \*ptr). Esempio se ho (ptr + 3), vado avanti di 12 byte di memoria dato che  sizeof(int) è 4 byte (32 bit).
  Nel linguaggio C $v[i] \leftrightarrow *(v+i)$, dato che a un array viene associato il primo slot di memoria  che occupa.

![[Pasted image 20241021102443.png]]

## Somma algebrica intera a un pointer esempi
$ptr++;$ significa aumentare il valore dell'indirizzo di un numero di byte pari alla dimensione del tipo base del pointer.
	$$int \ *ptr=100;\ (sizeof(int)==4)$$
	$$(ptr+2)\ lo \ rende == 1008$$


## Aliasing 
un evento dove due differenti espressioni o simboli si riferiscono allo stesso oggetto.


## NULL
dare il valore NULL a un puntatore $a = NULL;$ ci sta dicendo quale slot di memoria è libero e ne "associa" uno ma in realtà non punta a niente. Se non associamo niente a un puntatore ci da errore perchè a volte si creano casualmente degli errori.




## Confronto fra puntatori

Viene utilizzato se due puntatori sono uguali o diversi. Per esempio verifico un if se il nostr puntatore sia NULL, in caso non lo sia facciamo un else dove stampiamo il suo valore.

## malloc (memory allocate)
Un'operazione dove il programma chiede al sistema operativo di avere assegnato a se stesso più memoria di quanto gli serva.
```
// Ottenere memoria
	void *malloc(size_t size); 
//size_t il numero di byte in memoria. Per esempio 4 interi sono 16 byte. malloc ci resistuisce un void, un indirizzo di memoria generico, quindi devo dirgli che tipo di puntatore è, per farlo dobbiamo assegnarlo a una variabile:
	int *a; //Creo il puntatore
	a = (int *) malloc(K*sizeof(int)) 
// con K gli slot che voglio, in questo esempio possiamo considerare che stiamo chiedendo un array di K slot.
//Rilasciare memoria
	void free(void *ptr);
```

## Errori con puntatori e memoria dinamica
![[Pasted image 20241021104527.png]]
Devo stare anche attento a non sbagliarmi e cambiare slot di memoria che appartengono ad altre variabili che non dovrei toccare.
Le memory leak accadono quando faccio una doppia malloc, se assegno a un puntatore un'area di memoria tramite malloc, per poi riassegnare a quel puntatore un'altra area di memoria tramite malloc, allora perderò la prima area di memoria dato che nessun puntatore sa dove sta. Quindi sarà un'area di memoria che il sistema operativo da al programma, ma noi non possiamo utilizzarla in nessun modo, neanche liberarla visto che il puntatore non indica più essa. L'unico modo per liberarla è terminare il programma.


## Puntatore per passare una variabile fra funzioni

![[Pasted image 20241021111455.png]]

Questo codice printa 10 due volte, dato che la funzione foo lavora su una copia di n, quindi non modificherà la variabile n all'interno del main.
Per farlo abbiamo bisogno di utilizzare un pointer.
Questo vale in quanto riguarda le variabili, gli array vengono indicati direttamente con pointer perciò non bisogna fare questo utilizzo di pointer.

Quindi per utilizzare il pointer, *passo alla funzione l'indirizzo della variabile da cambiare*, così lavoro sul dato in mememoria.

![[Pasted image 20241024160744.png]]

Per creare un pointer che punta alla mia variabile desiderata devo fare:

```
int *a,b;
b=10;
a = &b
```

Posso anche creare una funzione

```
int *foo(int n)
{
	foo = (int*)malloc(n*sizeof(int))
}

int main()
{
	int *a; int n = 5;
	a = foo(n)
}

```

Che assegna al puntatore uno spazio creato.

**Notiamo come che dobbiamo anche passare l'indirizzo di un puntatore se vogliamo inizializzarlo all'interno di una funzione, senno anch'esso non viene modificato.**

![[Pasted image 20241024162105.png]]