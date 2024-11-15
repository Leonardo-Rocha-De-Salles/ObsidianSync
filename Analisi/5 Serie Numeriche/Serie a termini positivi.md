Una serie ha termini positivi se $\forall n \in N$ i termini della successione {$a_n$} sono tutti positivi. 
Data la definizione di serie a termini positivi [[Definizione di Serie]], abbiamo tre criteri:
$$Criteri \begin{cases}confronto \\
confronto \ asintotico \\
rapporto \\
radice
\end{cases}$$
# Criterio del confronto

Sia $\sum_{k=0}^{+\infty} a_k$, $\sum_{k=0}^{+\infty} b_k$ due serie a termini positivi, tale che $a_{k}\leq b_{k}\ \ \forall k \in N$, allora
1) Se la serie minorante diverge, anche la serie maggiorante diverge
2) Se la serie maggiorante converge, anche la serie minorata converge



# Criterio del confronto asintotico

Siano date due serie a termini positivi

1) Se $\lim_{n\to+\infty} \frac{a_{n}}{b_{n}}= l\in R \not = 0$ allora $\sum_{k=0}^{+\infty} a_{k} < +\infty \leftrightarrow \sum_{k=0}^{+\infty} b_{k} < +\infty$, Più in generale, il rapporto delle serie converge solo se entrambe hanno lo stesso carattere (convergono o divergono). 
2) Se $\lim_{n\to+\infty} \frac{a_{k}}{b_{k}} = 0$, e la serie $b_k$ converge allora anche la serie $a_{k}$ converge
3) Se $\lim_{n\to+\infty} \frac{a_{n}}{b_{n}}= +\infty$ e la serie $b_k$ diverge allora anche la serie $a_k$ diverge

## Applicazione

sin(1/k) $\geq 0 \qquad \forall k$ .
$sin(a_n)\sim a_{n} \qquad se \ \lim_{n\to+\infty} a_{n}=0$
$$sin\left(\frac{1}{k}\right)\sim \frac{1}{k}, per \ k\to +\infty$$
$$\sum_{k=0}^{+\infty} \frac{1}{k}=+\infty$$
Perciò anche
$$\sum_{k=0}^{+\infty}sin\left(\frac{1}{k}\right)= +\infty$$

# Criterio del rapporto
$\sum_{k=0}^{+\infty} a_{k}$ a termini positivi, supponiamo che $\exists \ \lim_{n\to+\infty} \frac{a_{k+1}}{a_{k}} = l \in R \cup \{+\infty\}$
1) se $l < 1$ la serie converge
2) se $l > 1$ la serie diverge a $+\infty$
3) se $l = 1$ non si può concludere nulla
![[Pasted image 20240803155505.png]]

# Criterio della radice

Sia data una serie a termini positivi e si supponga che $\exists \ \lim_{n\to+\infty} a_{k}^{\frac{1}{k}} = l \in R \cup \{+\infty\}$
1) se $l < 1$ la serie converge
2) se $l > 1$ la serie diverge a $+\infty$
3) se $l = 1$ non si può concludere nulla

![[Pasted image 20240803155519.png]]