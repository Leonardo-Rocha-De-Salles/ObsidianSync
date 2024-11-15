Possiamo dividere il calcolo di una funzione integrale con tre relazione:
$$\begin{cases}operazioni \ algebriche \\
composizione \\
inversione
\end{cases}$$

# Algebra delle derivate
![[Pasted image 20240804183212.png]]


# Derivata di una funzione composta
![[Pasted image 20240804183258.png]]

# Derivata di una funzione inversa

$f:I \to J$, derivabile e biettiva (invertibile) e sia $x_{0}\in I \ t.c. \ f^{'}(x_{0})\not= 0$
allora
$$f^{-1}:J\to I \ è \ derivabile \ in \ y_{0}=f(x_0)$$
$$(f^{-1})^{'}(y_{0}) = \frac{1}{f^{'}(x_{0})}$$
Quindi spiegandolo semplicemente, calcolo la derivata $f^{'}(x)$ però poi ad x vado a sostituire $f^{-1}(y)$.

## Esempio

$$f(x) = e^{x},\forall x \in R \qquad  f^{-1}(y)=ln(y), \quad y \in (0,+\infty)$$Sappiamo che $f^{'}(x) \not = 0 \rightarrow f^{-1}(y)$ è derivabile in $(0,+\infty)$ e 
$$(f^{-1})^{'}(y) = 1/e^{x}$$
Ma devo sostituire al posto di x la funzione inversa quindi ho
$$(f^{-1})^{'}(y) = \frac{1}{e^{ln(y)}}= \frac{1}{y}$$
Perciò
$$ln(y) = \frac{1}{y}$$