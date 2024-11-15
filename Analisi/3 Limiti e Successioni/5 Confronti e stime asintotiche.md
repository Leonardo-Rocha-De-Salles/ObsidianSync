Quando una successione è un *infinitesimo* o *infinto* è utile stabilire un confronto tra di esse, per capire quale delle due tende "più rapidamente" a 0 o infinito.

Siano {$a_n$} e {$b_n$} due **infiniti**. Consideriamo il rapporto $\frac{a_n}{b_{n}}$; si hanno quattro possibilità:
$$
\lim_{n\to+\infty}a_{n}/{b_{n}}=
\begin{cases}  0 & i)\\ 
l \ finito \ e \not = 0 &ii)\\
+-\infty &iii)\\
inesistente &iv)\\
\end{cases}
$$
Diciamo che:
i) {$a_n$} è un infinito di *ordine inferiore* a {$b_n$}
ii) {$a_n$} e {$b_n$} sono infiniti dello *stesso ordine*
iii) {$a_n$} è un infinito di *ordine superiore* a {$b_n$}
iv) {$a_n$} e {$b_n$} non sono *confrontabili*


Se {$a_n$} e {$b_n$} sono **infinitesimi** si riconsiderino i casi precedenti e si può dire che:
i) {$a_n$} è un infinito di *ordine superiore* a {$b_n$}
ii) {$a_n$} e {$b_n$} sono infiniti dello *stesso ordine*
iii) {$a_n$} è un infinito di *ordine inferiore* a {$b_n$}
iv) {$a_n$} e {$b_n$} non sono *confrontabili*

## Successioni Asintotiche

Nel caso in cui il rapporto delle due successioni si trovi nel secondo caso e tenda ad 1 
$$\lim_{n\to+\infty} \frac{a_{n}}{b_{n}}=1$$
è particolarmente importante; si usa dire che le due successioni sono **asintotiche**
$$a_{n} \sim b_n$$Il simbolo asintotico è molto utile nel calcolo dei limiti per le seguenti proprietà:

# Proposizione 3.1 (Successioni Asintotiche)

1)  Se $a_{n} \sim b_n$, le due successioni hanno lo stesso comportamente (convergono allo stesso numero, divergono allo stesso infinito o non hanno limite)
2) Si possono scrivere catene di relazioni asintotiche: $$ se \ \ a_{n} \sim b_{n}\sim \ ... \ \sim c_{n,}\ allora \ a_{n} \sim c_n$$
3) Un’espressione composta da prodotto o quoziente di più fattori può essere stimata fattore per fattore:$$a_{n} \sim a_n^{'},b_{n} \sim b_n^{'},c_{n} \sim c_n^{'},\quad allora \quad \frac{a_{n}b_{n}}{c_{n}}\sim \frac{a_{n}^{'}b_{n}^{'}}{c_{n}^{'}}$$

la 3 si è il **Principio di sostituzione**, ovvero
$$\lim_{n\to+\infty} \frac{a_{n}b_{n}}{c_{n}}=\lim_{n\to+\infty} \frac{a_{n}^{'}b_{n}^{'}}{c_{n}^{'}}$$
Che vale appunto solo per prodotti e rapporti.
Mentre in generale per somme/differenze e potenze **non vale**


![[Pasted image 20240726155322.png]]

![[Pasted image 20240726204735.png]]



# Osservazione

$$\lim_{n\to+\infty} a_{n}=l \longleftrightarrow \lim_{n\to+\infty} \frac{a_{n}}{l}= 1$$
$$a_{n}\sim l$$