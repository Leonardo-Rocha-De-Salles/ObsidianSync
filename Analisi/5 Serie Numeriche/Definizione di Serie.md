Data una successione {$a_n$} con $n \in N$, allora definiamo una successione {$S_n$} con $n \in N$ (successione delle somme parziali n-esime) 

$$S_{n}= \sum_{k=0}^{n} a_k$$
$$S_{0}= a_0$$
$$S_{1}= a_{0}+ a_1$$
$$S_{n}= a_{0}+ ...+ a_{n} = S_{n-1}+a_n$$


Data una successione, si dice che la serie numerica $\sum_{k=0}^{+\infty} a_{k}$ :

1) **Converge** se $\exists \ \lim_{n\to+\infty} S_{n}= S\in R$; in questo caso poniamo $\sum_{k=0}^{+\infty} a_{k}= S$ (somma della serie).
   **CONDIZIONE NECESSARIA PER LA CONVERGENZA DI UNA SERIE**
   Per verificare se una serie converge, il primo passo e controllare se $\lim_{n\to+\infty} a_{n} = 0$ , però non per forza vale il contrario, ovvero se il limite di una successione converge a 0, non per forza la serie di quella successione ha limite finito convergente.
   Questa condizione non è sufficiente, a dirci se una serie converga a un punto, serve solamente a dirci se la serie NON converge (in caso sia falsa) oppure verificare che la serie potrebbe convergere o divergere (in caso sia vera)
2) **Diverge** se $\lim_{n\to+\infty} S_{n}= +(-)\infty$
3) è **irregolare** se non esiste $\lim_{n\to+\infty} S_{n}$
   Una serie si dice a termini positivi si $a_{n}\geq 0 \forall n \in N$, Se $\sum_{k=0}^{+\infty} a_n$ è a termini positivi, allora {$S_n$} è crescente e quindi **regolare**.

$$\sum_{k=0}^{n} a_{k}= \lim_{n\to+\infty} \sum_{k = 0}^{n} a_{k}= S \ (somma \ della \ serie)$$


# Serie Geometrica
La serie geometrica è la seguente
$$\sum_{k=0}^{+\infty}q^{k} \qquad q \in R \qquad a_{n}= q^{n}$$
Per poterla calcolare dobbiamo prima di tutto sapere quanto vale quando ha indice n

$$S_{n}=\sum_{k=0}^{n} q^{k}= \frac{1-q^{n-1}}{ 1-q} \qquad q \not = 1$$
Poi vediamo se q fosse = a 1 
$$S_{n}= \sum_{k=0}^{n} 1^{k} = n + 1 \qquad  q =1$$
Adesso utilizzando la definizione di [[1.5 Successione Geometrica e Armonica|successione geometrica]]
$$\lim_{n\to+\infty} S_{n} = \lim_{n\to+\infty} \frac{1-q^{n-1}}{ 1-q} = \begin{cases} +\infty &  q > 1 \\
\frac{1}{1-q} & |q| < 1 \\
\not \exists & q \leq -1
\end{cases} 
$$
# Serie Armonica

$$\sum_{k=0}^{+\infty}\frac{1}{k}= +\infty$$

# Serie di Mengoli

$$\sum_{k=1}^{+\infty} \frac{1}{k(k+1)}$$
$$S_{n}= \sum_{k=1}^{n} \frac{1}{k(k+1)}= \sum_{k=1}^{n} \left(\frac{1}{k} - \frac{1}{k+1}\right)= 1 - \frac{1}{n+1}$$![[Pasted image 20240731201159.png]]


# Nota

Se ho $\sum_{k=0}^{n} a_{k}$ che converge a un certo numero con $n \to +\infty$, allora so che $\sum_{k=j}^{n} a_{k}$ con j > 0, so che anche essa ha lo stesso comportamento e anch'essa convergerà.
In caso potrei anche sottrarre dalla serie quei primi 10 indici.