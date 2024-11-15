E' possibile derivari altri tipi di dati da quelli che consideriamo elementari.
C'è da dire che a differenza dei dati elementari, **i dati derivati non occupano uno spazio di memoria predefinito.**

Un dato derivato che tratteremo adesso è l'**Array**.
l'Array è una collezione di oggetti, ciascuno dello stesso tipo di dato. Ognuno di esso è identificato da un indice numerico, o insieme di indici quando abbiamo Array di array.

Vediamo l'esempio di array *Monodimensionale*:
![[Pasted image 20241018093629.png]]
- **Il primo elemento dell'aria corrisponde alla posizione \[0\]**
- **L'ultimo elemento è quello \[N-1\]**
- **Quando si definisce inizialmente l'Array, dobbiamo mettere al suo interno un numero che rappresenta quanti elementi ci saranno all'interno dell'array**
- **E' importante che faccia \#define N per dare il numero dell'array, dato che un comando per il pre-processore**

## Come è fatto un array in memoria

![[Pasted image 20241018103702.png]]

Nel chiedere un array v\[N\], il compilatore mi fornisce uno spazio di memoria con N slot di memoria, e ogni slot di memoria è grande quanto un elemento base.
Per esempio se il nostra array è un float, ogni float è 4 byte, quindi avremmo 4\*N (slot di memoria che abbiamo) byte.
Il nome v, viene associato all'indirizzo di memoria del primo slot.
quando scrivo $$v[i]$$
Dico al compilatore di prendere l'indirizzo associato a $v$ e vammi avanti di $i$ posti. ma ogni slot è composto da float di 4byte, quindi il compilatore deve avanzare di $i*4$, quindi l'indirizzo di memoria $v+i*4$.

# Array Pluri-Dimensionali
## Array bidimensionali
$$int \ a[M][N]$$
Questa è una matrice bidimensionale, ma come viene messa in memoria una matrice? Si suddivide la nostra matrice in righe e le metto in successione negli slot di memoria.

![[Pasted image 20241018104500.png]]

Quindi significa che:
$$a[Riga][Colonna]$$
- **Il primo elemento ha indice \[0]\[0], l'ultimo \[M-1]\[N-1]**
- **L'indirizo di memoria i,j si trova aggiungendo ((i\*N)+j)\*S**
# Come passare array a una funzione
Ci sono due modi, quello "tradizionale" usando un puntatore, il modo "moderno" usando la standard C99 e seguenti:
![[Pasted image 20241018104833.png]]

Il metodo tradizionale col puntatore :

![[Pasted image 20241018105048.png]]
Invece di passare a\[m]\[n]
passiamo un puntatore, rappresentato con \*a

# Array e stringhe
In C una stringa è semplicemente un array di caratteri, con la caratteristica di avere come ultimo elemento un byte 0, che serve a indicare che la stringa è finita. Perciò bisogna sempre considerare un carattere in più.

![[Pasted image 20241018105008.png]]
