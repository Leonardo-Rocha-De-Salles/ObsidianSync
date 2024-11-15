
# Punto di accumulazione

$c \in R, X \subseteq R$ allora c è un punto di accumulazione per $X$ se:
$$\exists \{x_n\}_{n\in N} \ t.c$$
1) $x_{n}\in X \ \forall n \in N$
2) $x_{n}\not = c \ \forall n \in N$
3) $\lim_{n\to+\infty} x_{n} = c$
c che in generale potrebbe non appartenere a X, può essere approssimato (nel senso del limite) da punti contenuti in X.
$X = (a,b)$
allora l'insieme dei punti di accumulazione di $X$ è [a,b].
![[Pasted image 20240803183427.png]]
![[Pasted image 20240803183604.png]]
I punti di accumulazione sono punti dove il dominio si avvicini molto ed è denso.

Prendiamo in considerazione un intervallo $I$ e un punto $c$ che appartiene a questo intervallo e una funzione $f$ a valori reali, definita in $I$, che potrebbe anche non essere definita nel punto $c$.
L'intervallo può essere limitato, illimitato, chiuso, aperto.
Il punto $c$ deve essere un punto di accumulazione dell'insieme $I$. (inclusi infiniti)
Prendiamo adesso una successione di punti $x_{n} \qquad (n=1,2,...)$, nell'intervallo $I$ e diversi da $c$, che tenda a $c$, per $n \to +\infty$
$$x_{n}\to c \quad se \quad  n\to+\infty$$
# Definizione di limite
$f:X \subseteq R \to R$, c punto di accumulazione per X, allora si dice che $f$ tende a $l$ per x che tende a c, ove $l\in R$
$$\lim_{x\to c} f(x)=l$$
Se abbiamo la seguente situazione:
$$\forall \{x_{n}\}_{n\in N} | x_{n}\in X \ \forall n \in N, x_{n}\not = c \ \forall n \in N \ \ e \ \ \lim_{n\to+\infty} x_{n}=c$$
Ovvero per ogni successione scelta che tende a c (il valore $l$ non dipende dalla successione), otteniamo $l$

Parleremo di 
$$limite \begin{cases}finito \\ infinito\end{cases}
\qquad se \begin{cases}l\in R \\ l = +\infty, l = -\infty 
\end{cases}$$
e parleremo di

$$limite \begin{cases}al \ finito \\ all'infinito 
\end{cases} \qquad se \begin{cases}c \in R \\ c = +\infty, c = -\infty
\end{cases}$$


# Esempio di limite utilizzando definizione

$$\lim_{x\to 0} \frac{sin(x)}{x}= 1$$
Perchè? Dimostriamo come $\forall \{x_n\}_{n\in N} | x_{n} \not = 0 e \lim_{n\to+\infty} x_{n}=0$
$$\lim_{n\to+\infty}f(x_{n}) = \lim_{n\to+\infty} \frac{sin(x_{n})}{x_{n}}= 1$$
Per il confronto asintotico fra successioni sappiamo che $sin(x_n) \sim x_{n}, n \to +\infty$ 

## Dimostrare che un limite non esiste

$\not \exists \lim_{x\to 0} sin(\frac{1}{x})$
$x_{n}= \frac{1}{2\pi x} \not = 0 \qquad e \qquad \lim_{n\to+\infty} \frac{1}{2\pi x} = 0$
$\lim_{n\to+\infty} sin\frac{1}{x_{n}}= \lim_{n\to+\infty} sin(2\pi n) = 0$
![[Pasted image 20240803203543.png]]
Quindi prendendo due successioni diverse otteniamo due valori $l$ diversi, perciò il limite non esiste.



# Seconda definizione di limite

$f: X \to R, c \in R, l \in R, X \subseteq R$
$$\lim_{x\to c} f(x)=l$$
Se $\forall \varepsilon >0$, $\exists \delta = \delta(\varepsilon)>0 \ t.c. \ se \ x\in X \ e \ 0<|x-c|<\delta \rightarrow |f(x)-l|<\varepsilon$ 
![[Pasted image 20240803203855.png]]
![[Pasted image 20240803203915.png]]


# Teorema 3.12 (Unicità del Limite)

Se una funzione tendente a un punto di accumulazione tende a $l$, questo limite sarà *unico*, dato che la successione $f(x_n)$ non può dare due limiti distinti.




# Definizione 3.9 Limite per eccesso e per difetto

$Se \ l \in R$ e $c \in R^*$ si dice che
$$\lim_{x\to c} f(x) = l^{+} (l^{-})$$
$f(x)$ tende ad $l$ per eccesso (difetto) per x tendente a c. Ovvero prendendo in considerazione la successione che tende a $c$, $f(x_{n})\to l$ e inoltre $f(x_{n})\geq l$ ($\leq$) definitivamente. 
Quindi la funzione approccia da sopra $l$ (sotto), quindi il simbolo + (-)sopra un numero significa che tendono a quel numero mantendosi positivi (negativi).
Non tutte le funzione a limite finito tendono per eccesso o difetto infatti per la seguente non è vero:
![[Pasted image 20240726214143.png]]

# Definizione 3.10 Limite Destro e Sinistro
Data {$x_n$}, $c \in R$ si dice che
1) $$\lim_{n\to+\infty} x_{n}= c^{+} \ se \begin{cases}\lim_{n\to+\infty} x_{n}=c \\
x_{n}\geq c \ \ \forall n \in N
\end{cases}$$
2) $$\lim_{n\to+\infty} x_{n}= c^{-} \ se \begin{cases}\lim_{n\to+\infty} x_{n}=c \\
x_{n}\leq c \ \ \forall n \in N
\end{cases}$$
Adesso vediamo

1) $$\lim_{x\to c^{+}} f(x) = l  \qquad se \ \forall \{x_{n}\} \ t.c\ x_{n}\in X, x_{n}\not= c \quad e \quad \lim_{n\to+\infty} x_{n}= c^{+}\quad allora$$
$$ \quad \lim_{n\to+\infty} f(x_{n})= l$$


![[Pasted image 20240726221235.png]]

**Più in generale il limite di una funzione tendente a un numero esiste finito solo se il limite destro e il limite sinistro sono uguali. Se solo uno dei due limiti o nessuno dei due esiste allora il limite non esiste.**

**UNA CONDIZIONE NECESSARIO DI LIMITE E' LA SEGUENTE**:
$$\lim_{x\to c} f(x) = l \qquad solo \ se \qquad \lim_{x\to c^+} f(x) =  \lim_{x\to c^-} f(x) = l$$


# Asintoto obliquo

La funzione $f(x)$ ammette asintoto obliquo per $x \to +\infty$ se valgono le seguenti condizione:
1) Esiste finito $$\lim_{x\to+\infty} \frac{f(x)}{x} = m \not = 0$$
2) Esiste finito $$\lim_{x\to+\infty} [f(x) -mx] = q$$
In tal caso l'asintoto è $y = mx + q$

Se uno di questi limiti non esiste finito, la funzione non ha asintoto obliquo.



# Asintoto orizzontale

$f$ ha asintoto orizzontale di equazione $y =l \quad per \ x \to +\infty(-\infty)$ se 
$$\lim_{x\to+\infty} f(x) = l \qquad oppure \qquad \lim_{x\to-\infty} f(x) = l \qquad l\in R$$




# Asintoto Verticale

L'asintoto verticale di equazione $x = c$ esiste se 
$$\lim_{x\to c} f(x) = +-(\infty)$$
Questo può accadere anche per un limite destro o sinistro rispettivamente.







# Algebra e op.Algebriche sui limiti

![[Pasted image 20240803210604.png]]



# Limite per funzione composta

Sia $f:X \to Y, g: Y  \to R$ e c un punto di accumulazione di $X$ Se:
1) $\lim_{x\to c} f(x) = y_{0}$
2) $\lim_{y\to y_{0}} g(y)=l$
3) $\exists \delta >0 \ t.c. \ se \ 0<|x-c|<\delta, x \in X \rightarrow f(x) \not = y_0$
E' importante che $f(x) \not = y_{0}$ dato che 
![[Pasted image 20240804160159.png]]
Allora
$$\lim_{x\to c} g(f(x)) = l$$
Esempio:
$$\lim_{x\to+\infty} sin(\frac{1}{x^{2}})$$
Quindi prima di tutto facciamo il limite della nostra funzione interna
$$\lim_{x\to+\infty} \frac{1}{x^{2}} = 0$$
E poi poniamo y che tende a 0
$$\lim_{y\to 0} sin(y) = 0$$






# Limiti di Ordinamento

## Teorema del confronto
$f,g : X \subseteq R \to R$, e dato c punto di accumulazione di $X$, supponiamo che $f(x) \leq g(x) \forall x \in X$ e $\lim_{x\to c} f(x) = l$, $\lim_{x\to c} g(x) = m$ allora $l \leq m$
Questo vale anche per semplicemente un intervallo vicino a $c$


## Teorema dei Carabinieri

$f,g,h:X \to R$ e supponiamo che $f(x)\leq h(x) \leq g(x) \ \forall x \in X, \lim_{x\to c} f(x) = \lim_{x\to c} g(x) = l$ , allora $\lim_{x\to c} h(x) = l$


## Teorema permanenza Segno

$f:X \to R, f(x) \geq 0, \forall x \in X \ e \ \lim_{x\to c} = l$ Allora $l\geq 0$
Osservazione:
$$f(x) \in [\alpha,\beta],allora \ l\in [\alpha,\beta]$$
$$f(x) = \frac{1}{x} >0 \ \ \forall x \in (0,+\infty), \lim_{x\to +\infty} \frac{1}{x}=0$$
![[Pasted image 20240804161127.png]]






# Limite e monotonia

$f : X\to R$ crescente, allora $\lim_{x\to c^{+}},\lim_{x\to c^{-}}$ esistono sempre. Inoltre
1) Se f è crescente $\lim_{x\to c^{-}} f(x) = sup\{f(x):x\in X \ t.c. \ x\le c\}$
2) Se f è decrescente $\lim_{x\to c^{-}} f(x) = inf\{f(x):x\in X \ t.c. \ x\le c\}$ e 
   $\lim_{x\to c^{+}} f(x) = sup\{f(x):x\in X \ t.c. \ x > c\}$

































# Definizione 3.12 (Tipi di Discontinuità)

Se il limite destro e sinistro di un punto esistono finiti ma diversi si dice che si ha una **discontinuità a salto**.
Se uno dei due coincide con $f(c)$ ma l'altro no è continua da destra o sinistra rispettivamente.













# Limite finito all'infinito

Dimostriamo che: 
$$\lim_{x\to-\infty} e^{x}= 0$$
Applicando la definizione, si tratta di provare che per ogni successione {$x_n$} tale che $x_{n}\to -\infty$, si ha:
$$\lim_{n\to+\infty} e^{x_n}= 0$$
Per definizione di limite di successione questo significa che fissato $\varepsilon > 0$ qualsiasi, risulti
$$|e^{x_{n}}| < \varepsilon \qquad definitivamente$$
Dato che l'esponenziale è positivo
$$e^{x_{n}} < \varepsilon \qquad definitivamente$$
Che equivale a 
$${x_{n}} < log(\varepsilon)$$
