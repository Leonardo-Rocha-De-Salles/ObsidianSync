# Teorema 3.10(Gerarchia degli infiniti)
$$\lim_{n\to+\infty}\frac{log_{a}n}{n^{\alpha}}=0$$
Per $\alpha >0$
$$\lim_{n\to+\infty}\frac{n^{\alpha}}{a^{n}}=0$$
Per ogni $a>1,\alpha > 0$

$$\lim_{n\to+\infty} \frac{q^{n}}{n!}=0$$
$q >1$

$$\lim_{n\to+\infty} \frac{n!}{n^{n}} = 0$$

Questi limiti dimostrano la velocità delle funzioni ad andare all'infinito.

Ovvero le funzioni al numeratore, vanno più velocemente a infinito, assumendo numeri più "grandi", quindi abbiamo la seguente gerarchia di infiniti:	$$log(n) < n ^ {\alpha} < q^{n}<n!<n^{n} \qquad con \ n \to +\infty$$
Per esempio:
$$\lim_{n\to+\infty} \frac{n^{n}}{q^{n}} = \frac{1}{\frac{q^{n}}{n^{n}}}= \frac{1}{0^{+}} = +\infty$$
Vediamo adesso le **radici**

$$\lim_{n\to+\infty} n^{\frac{1}{n}}= \lim_{n\to+\infty} e^{\frac{log(n)}{n}}=e^{0}= 1$$

# Teorema 3.11 (Criterio del rapporto o Criterio di Cesàro)
Sia data una successione positiva ($a_{n}\geq 0$) per ogni n. Se esiste

$$\lim_{n\to+\infty} \frac{a_{n+1}}{{a_{n}}} = l\in R^*$$
e $l<1$, allora $a_{n}\to 0$; se $l > 1$ (eventualmente anche $+\infty$), allora $a_{n}\to +\infty$
e poi 
$$\lim_{n\to+\infty} a_{n}^{\frac{1}{n}} = l$$Quindi se ho:

$$\lim_{n\to+\infty} n^\frac{1}{n}$$
Posso scriverlo come

$$\lim_{n\to+\infty} \frac{n+1}{n} = 1$$