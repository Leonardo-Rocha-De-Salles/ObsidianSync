Altro tipo di dato derivato, simile agli array, ma le strutture possono utilizzare tipi di dati diversi fra di loro, **non devono essere dello stesso tipo**. Sono una specie di classe.

![[Pasted image 20241024162551.png]]

Con struct myStrucutre, creo una classe, al suo interno posso mettere gli attributi.
Al di fuori della creazione della struct posso creare una variabile a cui attribuire quella structure.

creiamo l'oggetto *book* che ha tanti **attributi**, come un titolo, autore, prezzo, etc...
Il problema che sorge quando ho stringhe con tanti caratteri, io devo predefinire la dimensione dell'array, se non lo faccio non funziona il programma.
Come faccio a decidere quanti caratteri ha ogni stringa?

Per risolvere questo problema utiliziamo i puntatori, lasciando le nostre stringhe come:
```
char *title;
char *author;
```
Ricordando che le stringhe si chiudono con il carattere 0.

# Assegnare attributo a una structure.
![[Pasted image 20241028092722.png]]
# Come creare strutture con Puntatori

![[Pasted image 20241024163957.png]]


```
struct person *person_create(name,age,...)
{
	struct person *who = NULL
	if((who = (*)malloc()==NULL)){
		return(NULL);
	}
}
```

Per accedere a uno struttura

```
who.age = age;
```
E definiamo l'età della variabile, ma se invece **abbiamo il puntatore della struttura dobbiamo usare**.
```
struct person *who;
who->age = age;
```

Se usiamo i puntatori, per cambiare il valore di una variabile dobbiamo usare la freccia.

Possiamo usare un puntatore anche per cambiare i valori di un altro elemento creato con lo struct

```
struct person who;
who.age = 10;
struct person *who2;
who2 = &who
who2 -> age = 5;
```

Qui prima assegnamo age = 10. Ma poi mettiamo un pointer che assegna age = 5 successivamente.





![[Pasted image 20241024170553.png]]

Questo ci crea un problema, se who è un puntatore nullo, ci ritorna in print cose sbagliate, quindi occorre sempre verificarlo.
![[Pasted image 20241024171322.png]]


# Strutture con List
Possiamo porre alla fine della nostra struttura un nomevariable, quel nome della variabile lo potremmo utilizzare per richiamare la struttura senza mettere sempre davanti struct
![[Pasted image 20241024171730.png]]