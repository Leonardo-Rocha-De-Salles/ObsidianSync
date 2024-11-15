Un altro uso del calcolo differenziale è trovare una funzione lineare del tipo $L(x) = Ax + B \qquad A,B \in R$ che approssima la funzione data, stimando l'errore.
L'esempio di un'equazione lineare è quella della retta tangente a un punto
$$T(x) = f(x_{0}) + f'(x_{0})(x-x_{0})$$
Poi ovviamente abbiamo un resto rispetto la tangente e il grafico stesso della funzione, questo resto è 
$$r(x) = f(x) - T(x)$$
Se consideriamo il punto proprio quello dove la retta tange il grafico abbiamo
$$r(x_{0}) = f(x_{0})-T(x_{0}) = 0$$

# o Piccolo (simbolo di Landau)
Date due funzioni definite in un intorno $x_{0}$, si dice che
$$f(x) = o(g(x)), per \ x \to x_{0}$$
Se
$$\frac{f(x)}{g(x)} \to 0, per \ x \to x_{0}$$
Ovvero
$$\lim_{x\to 0} \frac{f(x)}{g(x)} = 0$$
## Esempi

$$x^{4}= o(x^{3}),per \ x \to 0$$
Questo significa che x^4 tende più rapidamente a 0 quando x tende a 0.
Più in generale
$$x^{3}= o(x^{m}),per \ x \to 0, se \ n > m$$
Ogni funzione è un o piccolo di 1, dato che
$$\lim_{x\to x_{0}} \frac{f(x)}{1} = 0, \text{se f(x) tende a 0 per x che tende a 0}$$
# Relazione tra "o piccolo" e "asintotico"
$$Per \ x\to x_{0}, f(x) \sim g(x) \ \ se \ e \ solo \ se \ f(x) = g(x) + o(g(x))$$


# Proprietà o piccolo
$$o(x)-o(x) = o(x)$$
$$o(-3x) = o(x)$$
per $x \to 0$ 
$$o(x)+o(x^{2})= o(x)$$
L'errore più grossolano cioè o(x) ingloba quello più fine, quindi $o(x^{n})+o(x^{m}) =o(x^n),n<m$
per $x \to +\infty$
$$o(x)+o(x^{2})=o(x^{2})$$
$$f(o(g)) = o(fg)$$
$$xo(x)=o(x^{2})$$
$$o(f)o(g)=o(fg)$$
$$o(x)o(x^{2}) = o(x^3)$$