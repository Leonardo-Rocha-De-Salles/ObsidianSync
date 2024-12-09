
La progettazione non ammette "ricette" universali, ma richiedono inventiva.
**Fasi di Analisi**:
- Classificazione del problema
- Caratterizzazione della soluzione
- Tecnica di progettazione (*divide et impera, programmazione dinamica, greedy, ricerca locale, backtrack, probilistica*)
- Strutture dati

# Divide et impera

**Suddividere un problema in sottoproblemi, risolveri e combinare le soluzioni**
- Quicksort;
- Mergesort;
- Algoritmo di Strassen per la moltiplicazione di matrici.

# Programmazione dinamica
Risolvere tutti i sotto problemi, verso una unica soluzione principale, in modo da non dover mai risolvere due sottoproblemi insieme.
Viene utilizzata quando divide et impera ha troppi sottoproblemi che si ripetono.
*Il numero di sottoproblemi deve essere al massimo polinomiale.*
- Coefficiente binomiale
- Fibonacci
- Tartaglia

# Problema delle matrici

Date due matrici qualcolarne il prodotto. Dato che non è associativo il prodotto di una matrice, possiamo avere che date 3 matrici, moltiplicando le prime due sia più ottimale.
La catena di matrici è un problema che dato n matrici, si trova la parentesizzazione che le minimizzi il prodotto.

**Possiamo caratterizzare la soluzione ottima**:
$P_{i,j}$ è una parentesizzazione di $A_{i}*A_{i+1}...A_{j}$ se:
$$P_{i,j} = \begin{cases}  A_{i}  & se \ i = j \\
(P_{i,k}*P_{k+1,j})  & per \ qualche \ k\\
\end{cases}$$
Se $P_{i,j}$ è ottima, allora lo sono anche $P_{i,k}$ e $P_{k+1,j}$
![[Pasted image 20241205214003.png]]

# Memoization
![[Pasted image 20241205214110.png]]