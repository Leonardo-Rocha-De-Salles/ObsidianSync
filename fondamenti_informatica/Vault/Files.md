Un file si può trovare in diversi stati: 
read
write
In python si utilizza la funzione open() per inizializzare una variabile di tipo fiel

La sintassi:

	f = open(filename, mode) 

mode può essere r (read), w (write), a(append), a cui si può aggiungere b per i file binari
![[Pasted image 20240522104038.png]]

Vediamo un esercizio che prende un file e ne crea due, uno con le righe pari e uno con le dispari:
![[Pasted image 20240522104222.png]]