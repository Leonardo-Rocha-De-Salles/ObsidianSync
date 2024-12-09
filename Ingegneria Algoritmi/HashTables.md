Possiamo accedere e recuperare informazione in tempo O(1)?

Questo è ciò che accade in array, quindi se abbiamo informazione indirizzato e l'indice numero è calcolabile in O(1), allora abbiamo tempo di accesso O(1).

**Array monodimensionali**
```C
double v[10];
i = 4;
x = v[i];
```

Per accedere a v, il compilatore riconosce l'indirizzo di partenza di v e la dimnesione di ciascun elemento al suo interno, insieme all'indice di partenza **xb** che in C è sempre uguale a 0. Il compilatore per accedere a un certo elemento fa:

$$start(v) + size *(i-xb)$$

**Array multidimensionale**
```C
double a[10][20];
i = 4; j = 3;
x = [i][j];
```

Per accedere alla posizione a\[i]\[j], il nostro compilatore ha bisogno di :
- indirizzo di partenza in memeoria dell'array a;
- la dimensione di ciascun elemento dell'array;
- indirizzo iniziale in ciascuna dimensione xb( in C : 0);
- numero di elementi NC in ciascuna riga (questo caso 20);
Dato questi il compilatore calcola
$$start(a) + size * ((i-xb)*NC + (j-xb))$$
![[Pasted image 20241125102639.png]]

**NOTARE  QUANDO SI FA V + 1 O QUALSIASI INTERO, SOMMA LA DIMENSIONE DELL'ELEMENTO DELL'ARRAY, NON LA DIMESIONE INT.**

![[doublearray.c]]

# Hash

Supponiamo di avere dei dati con chiavi numeriche che possono contenere ripetizioni. Si potrebbero memorizzare i puntatori ai record in una tabella bidimensionale.
![[Pasted image 20241125111801.png]]

Data un chiave $K \in U$ cerchiamo una funzione per la quale $$h(k) : U \to \{1,\dots,m\} (INIETTIVA)$$
$$K_{1}\not = K_{2} \to h(K_{1}) \not = h (K_{2})$$
Abbiamo anche che m ha la stessa cardinalità di U.

Perciò ogni chiave di un mio elemento, dovrà essere diversa dalle altre e ricavate da una funzione linerare.

Quando la dimensione m è molto più piccola di U, si possono avere conflitti dove abbiamo chiavi uguali, per questo possiamo risolverlo manualemente la maggior parte di volte.

**La funzione h(K) viene detta hash o funzione di hashing**.

![[Pasted image 20241125112949.png]]
## Requisiti di una tabella hash
- h() deve essere calcolabile in O(1);
- h() deve restituire valori ben distribuiti nell'insieme atteso U;
- esista un metodo di risoluzione per collisioni;
- Che la tabella abbia più elementi necessari per eveitare riempimento  completo.
**La chiave deve essere uniforme, ossia la probabilià che una chiave K venga inserita in posizione i è la seguente**;
$$Q(i) = \sum\limits _{K:h(K) = i}P(K,i) \thicksim \frac{1}{m}$$

## Esempi di Funzioni Hash
![[Pasted image 20241125114005.png]]

### Division method
Si basa sul dividere la chiava per un numero primo e ritornare il suo resto come hash value. $$h(k) = k \ \%\ prime$$

### Multiplication method

### Folding
Dividere la chiave in parti uguali, sommandole e poi prendendo il modulo della somma
## Risoluzione collisioni

- **Scansione interna** : 
  si estende la funzione hash con un secondo argomento, dove i = 0,..., m-1.
  Se l'elemento della tabella indirizzato i è occupato, si passa al suo valore successivo, se tutti sono pieni la tabella è riempitva.
  ![[Pasted image 20241125114318.png]]
  ![[Pasted image 20241125114342.png]]
  ![[Pasted image 20241125114359.png]]
Uno svantaggio della scansione lineare è il sovradimensionamento della tabella e i cluster tendono ad espandersi.

- **Liste di trabocco**: 
  Quando ho indici uguali, inserisco il nuovo elemento in una lista, dove viene posto alla fine.
  ![[Pasted image 20241125114535.png]]
  Nel peggiore dei casi la tabella hash ha un costo lineare della dimensione della tabella stessa.
# Complessità
![[Pasted image 20241125114642.png]]
![[Pasted image 20241125114703.png]]
![[Pasted image 20241125114712.png]]
![[Pasted image 20241125114724.png]]