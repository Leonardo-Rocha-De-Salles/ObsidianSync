$f:X \to R$, con un punto di accumulazione $x_{0} \in X$ (solitamente il punto di accumulazione non deve per forza appartenere all'insieme), allora $f$ si dice continua in $x_{0}$ se 
$$\lim_{x\to x_{0}} f(x)= f(x_0)$$
Inoltre $f$ si dice continua in $X$ se $f$ è continua in $x_{0,}\forall x_{0}\in X$

Osservazione:

Se $x_0$ è un punto isolato di $X$, cioè appartiene a $X$ ma non è di accumulazione, allora $f$ si considera continua in $x_0$

Dimostrazione di continuità:

$f(x) = e^{x},\forall x \in R$ 
$f$ è continua in R, cioè $\forall x_{0}\in R$
1) $\lim_{x\to x_{0}} e^{x}= e^{x_{0}}$  Quindi $\lim_{x\to x_{0}} e^{x} - e^{x_{0}}= 0$

Una funzione è continua quando tutti i punti di accumulazione hanno limite e questo limite è uguale alla $f(punto \ di \ accumulazione)$
![[Pasted image 20240804165937.png]]

# Proprietà funzioni continue

Se $f,g$ sono continue in $x_0$ allora:
1) $f +- g$ è continua in $x_0$
2) $fg$ è continua in $x_0$
3) $\frac{f}{g}$ è continua in $x_0$ se g(x_0) è diverso da 0
4) $(f(x))^g(x)$ è continua in $x_0$ se $f(x_{0})>0$



# Teorema continuità di funzioni inverse.

$f:I \to J$, ove $I$ è un intervallo e $f$ è continua in questo intervallo.

1) $f$ è biettiva (quindi invertibile) se e solo se, f è strettamente monotona in $I$
2) Se $f$ è biettiva da $I \ in \ J$, allora $f^{-1}: J\to I$ è continua in $J$

Questo significa che una funzione è continua se l'inversa della sua funzione è continua



