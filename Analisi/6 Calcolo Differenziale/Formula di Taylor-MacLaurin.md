Data una funzione derivabile quanto necessario, è possibile trovare un polinomio che nell'intorno di un punto fissato è simile a quella funzione?
# Polinomio di MacLaurin
Data una funzione f derivabile n volte, esiste un solo polinomio di grado $\leq$ n, chiamato $T_n$ con la proprietà che
$$T_{n}(0)=f(0),T_{n}'(0) = f'(0),...T_{n}^{(n)}(0) = f^{(n)}(0)$$
E questo polinomio di MacLaurin di f(x) di grado n è:
$$T_{n}(x) = \sum_{k=0}^{n} \frac{f^{(k)}(0)}{k!}x^{k}$$
Ovvero
$$f(0) + f'(0)x+ \frac{1}{2}f''(0)x^{2}+...$$
# Resto secondo Peano
$f : (a,b) \to R$ derivabile n volte in 0 $\in (a,b)$. Allora
$$f(x) = T_{n}(x) + o(x^{n}), per \  x \to 0$$
Funzione da approssimare = polinomio approssimazione + errore di approssimazione

# Punto $x_{0} \not = 0$

$f : (a,b) \to R$ derivabile n volte in $x_0$ $\in (a,b)$. Allora
$$f(x) = T_{n,x_{0}}(x) + o((x-x_{0})^{n}), per \  x \to x_0$$