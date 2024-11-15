# Definizione 3.7
Una successione si dice *monotona crescente* se $a_{n} \leq a_{n+1}$ *strettamente crescente* se  $a_{n} < a_{n+1}$ $\forall n$;
Una successione si dice *monotona decrescente* se $a_{n} \geq a_{n+1}$ *strettamente decrescente* se  $a_{n} > a_{n+1}$ $\forall n$;

Questo tipo di successioni non sono mai indeterminate, sono sempre o **convergenti o divergenti.**

# Teorema 3.1 (Di monotonia)

Sia data una successione monotona crescente e superiormente limitata. Allora questa successione è *convergente*, e il suo **limite è uguale a sup{$a_{n}:n \in N$}**
Analogamente, se la successione è **monotona decrescente e inferiormente limitata, il suo limite è uguale a inf{$a_{n}:n \in N$}**
Ovvero l'estremo superiore o inferiore dell'insieme dei valori assunti dalla successione.

## Dimostrazione

Poichè la successione data è limitata superiormente, esiste un estremo superiore,
$$A = sup\{a_{n}:n\in N\}, A \in R$$
Proviamo ora che
$$\lim_{n\to+\infty}a_{n}= A$$
Occorre mostrare che per ogni $\varepsilon$ > 0 si ha:
$$A - \varepsilon<a_{n}< A + \varepsilon \qquad definitivamente$$
(Ovvero la definizione di limite)
La seconda diseguaglianza è ovvia, per ogni $n$ è $a_{n}\leq A$  (e quindi $a_{n}<A +\varepsilon$)
Per la seconda, esssendo $A -\varepsilon < A$ esso non è maggiorante della successione, perciò esiste un $n_0$ per il quale
$$a_{n_{0}}>A -\varepsilon$$
Abbiamo provato che 
![[Pasted image 20240726135600.png]]
Per esprimere che il limite è il sup ( o inf) di una successione crescente (o decrescente) si usa la notazione
$$a_{n}\uparrow l \qquad oppure \qquad  a_{n}\downarrow l$$
Questa proprietà è una diretta correlazione con $R_4$ [[0.3 Insieme Q e R, Campi Ordinati#R4) Ogni insieme $E subset X$ non vuoto e 0.4 Numeri Reali, Estremo superiore e assioma di continuità limitato superiormente possiede 0.4 Numeri Reali, Estremo superiore e assioma di continuità estremo superiore in X.|R4]], perciò dire che una successione crescente e limitata ha come limite il sup, vale solo se stiamo nell'insieme $R$


# Corollario 3.2

Sia data una successione *monotona crescente*. Allora esiste
$$\lim_{n\to+\infty}a_{n}= sup\{a_n:n\in N\}$$
Esplicitamente: se la *successione monotona crescente è superiormente limitata*, allora **converge** (e il suo limite è uguale all'estremo superiore dei suoi valori). Se invece è *superiormente illimitata* **diverge** a $+\infty$ (che in questo caso è sempre l'estremo superiore dei suoi valori).

Si può dire che una successione monotona converge o diverge (non può essere irregolare).


## Dimostrazione

Se la successione crescente è *superiormente limitata* l'enunciato è contenuto nel teorema di monotonia. Se invece è *superiormente illimitata* questo significa che per ogni K > 0, esiste un $n_{0}$ tale che $a_{n_{0}} > K$ . 
Visto che la successione è crescente per ogni $n \geq n_{0}$ si ha che $a_{n}> a_{n_{0}} > K$.
Abbiamo provato che per ogni K > 0 è $a_{n}>K$ definitivamente.
Questo significa che $a_{n} \to +\infty$
