# Dimostrazione Algoritmo di Euclide
Nella divisione intera (q,r) <--m/n abbiamo sempre r < n, quindi una sequenda $r_1,r_2,...,r_{k)}$ è *strettamente discendente*, non esiste alcuna seria di numeri naturali strettamente discendente e infinita. Quindi abbiamo un numero finito di diivisioni.

# Complessità computazionale
Si torna alla domanda fondamentale "*quanto costa risolvere un dato problema?*".
Come prima approssimazione assumiamo che tutte le operazioni eseguita dal programma hanno lo stesso costo, mentre alcune operazioni non vengono conteggiate nel costo. Quindi poi dobbiamo vedere quanti cicli questo programma svolge.

## Esempio: 
Somma di due vettori:
```
>a = [1,2,3]
>b = [4,5,6]

>a+b
[5,7,9]
```
Il numero di operazioni è pari al numero di elementi all'interno del vettore, quindi in questo caso 3 (variabile n = numeri elementi in questo caso).
Notare che n non è stata definita e dipende dal problema.

## Tempo esecuzione T(n)
Introduciamo le comuni operazioni asintotiche al tempo di esecuzione di un programma T(n) su input di dimensione n.
**T(n) è O(f(n)) se esistono f(n), C e $n_0$ tali che**:
$$T(n) \leq C * f(n) \qquad \forall \ n >n_{0}$$
T(n) è $\Omega(f(n))$ se esistono $f(n), C,n_{0}$ tali che:
$$T(n) \geq C*f(n) \qquad per \ infiniti \ valori \ n >n_{0}$$
![[Pasted image 20240930101430.png]]
T(n) è $\Phi(f(n))$ se esistono $f(n),C_{1},C_{2} \ e \ n_0$ tali che:
$$C_{1}*f(n) \leq T(n) \leq C_{2}*f(n) \qquad \forall \ n > n_{0}$$


### Quante istante n esistono per un problema e hanno tutte lo stesso tempo?
Se una dimensione n non è sufficiente per determinare il tempo di esercuzione, si vanno a definire dei raffinamenti:
- **Worst case:** $T(n) \ è \ o(f(n))$ *per qualunche* input possibile di dimensione n
- **Average case:** $T(n) \ è \ o(f(n))$ *in media* su tutti gli input possibile di dimensione n
- **Best case:** $T(n) \ è \ \Omega(f(n))$ raggiunto per *alcuni* input di dimensione n

#### Casi comuni:
- $O(1)$ : algortimo richiede tempo costante;
-  $O(log(n))$
- $O(n)$ : Lineare;
- $O(n^{k})$ : Polinomiale;
- $O(a^{n})$ : Esponenziale.
Gli algoritmi di complessità polinomia sono considerati trattabili. Un $O(n^2)$ avrà prima o poi le sprestazioni migliore di un algoritmo $O(n^3)$ indipendente dal coefficiente. E in natura il grado del polinomio è regolarmente basso, comunemente 2,3.


# Distinzione complessità algoritmo e complessità di un problema.
*Complessità di un algoritmo* è la complesittà di un particolare metodo di soluzione del problema;
*Complessità di un problema* è la complessità del **Migliore** algoritmo che risolve quel problema.



# Come valutare il costo di un algoritmo
Le espressioni scalari elementari hanno costo O(1).
Il costo di una sequenza di istruzioni è dato dalla somma dei singoli costi.
Il costo di un ciclo è la somma del costo di ogni singola iterazioni.
Per un if ed else bisogna studiare la probabilità di ciascun ramo.

## Esempio
![[Pasted image 20241003160856.png]]

## Calcolo complessità di un ciclo
$$\sum\limits_{i\in I}C(i)$$
- i è una iterazione;
- I è l'insieme di tutte le iterazioni
- C(i) è il costo della i-esima iterazione.
- numero di iterazioni in questo caso è (numero di arrivo - numero iniziale + 1)
Solitamente il costo dell'iterazione è costante, per i cicli for è facile trovare $I$, per i cicli while un po meno.

Per i cicli innestati abbiamo:
$$\sum_{i=1}^{m}\sum\limits_{j=1}^{n}C(statement_{ij})$$
### Esempi
#### Somma di vettori di dimensione n: c=a+alpha\*b
![[Pasted image 20241003161827.png]]
i = 1, andiamo a n. quindi n passaggi. (n-1+1)=n 
c[i] = a[i] + alpha\*b[i]    che ha costo 2
$$\sum\limits^{n}_{i=1}2=2n$$

#### Prodotto scalare di due vettori di dimensione n: c = x'\*y;
![[Pasted image 20241003162307.png]]



#### Prodotto matrice-vettore y = y + A\*x (m x n):
![[Pasted image 20241003162412.png]]



#### Prodotto matrice-matrice
![[Pasted image 20241003163205.png]]

