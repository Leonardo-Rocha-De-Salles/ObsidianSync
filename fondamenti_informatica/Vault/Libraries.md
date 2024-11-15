Possiamo importare moduli all'interno di un programma python, questi moduli sono file .py che contengono metodi e funzioni.

Python ha una vasta libreria di moduli, chiamata pythond standard library. 

Per importare un modulo utilizziamo 

	import modulename

e ogni funzione del modulo viene utilizzata con

	modulename.functionname()

se non vogliamo importare un modulo intero ma solo una funzione possiamo utilizzare

	from modulename import functionname

In questo caso non importanto il modulo in se le funzioni del modulo possono essere chiamate semplicemente con 

	functionname()

Se vogliamo importare un modulo intero e le sue funzioni, senza dover utilizzare la dot notation possiamo fare

	from modulename import *

Un esempio di module è random
random ha le seguenti due funzioni utili:

	random() ritorna un valore reale casuale tra 0 e 1

	choice(list) ritoruna un elemento scelto a casa da list

quindi:

	random.random(), random.choice()


Librearia math:
Molte funzioni matematiche
![[Pasted image 20240522124418.png]]
![[Pasted image 20240522124432.png]]
