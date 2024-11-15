
# Punti stazionari, massimi e minimi locali


## Massimo e minimo

Si dice che M è un *massimo* di $f:[a,b] \to R, x_{0} \in [a,b]$ è *un punto di massimo* se
$$f(x_{0}) = M \geq f(x), \quad \forall x \in [a,b]$$
analogamente si definisce il minomo


## Massimo e minimo locale


Si dice che M è un *massimo locale* per $f$ e che $x_{0}$ è un punto di *massimo locale* se:
$$\text{esiste un intervallo } (x_{0}-\delta,x_{0}+\delta) |M = f(x_{0}) \geq f(x), \forall x \in (x_{0}-\delta,x_{0}+\delta) \cap [a,b]$$
analogamente per un *minimo locale*

Se vogliamo definire un punto generico che può essere massimo o minimo locale, lo chiamiamo **estremo locale**

![[Pasted image 20240804201458.png]]
Nella prima figura:
*massimo globale* M = f(x_2); $x_2$ unico punto di *massimo globale*
minimo globale m = f(a), a è unico punto di minimo globale
massimo locale il punto $x_0$
due minimi locali sono il punto b e $x_1$

Nella seconda figura
massimo locale $x_0$
minimo globale sono i due punti m = $f(x_{1),}f(b)$
il massimo globale di f non esiste.




# Teorema di Fermat

$f:[a,b] \to R, x_{0} \in (a,b)$ un punto di estremo locale (massimo o minimo locale) e $f$ derivabile in questo punto $x_0$, allora la derivata in quel punto si annulla.
$$f^{'}(x_0)=0$$

## Dimostrazione 
sia x un punto di massimo locale. Allora per z abbastanza vicino di x abbiamo che f(z) $\leq$ f(x):
$$z<x \rightarrow \frac{f(z)-f(x)}{z-x} \geq 0 \qquad e \ quindi \qquad f^{'}_{-}(x)=\lim_{z\to x^{-}} \frac{f(z)-f(x)}{z-x} \geq 0$$
D'altra parte abbiamo
$$z>x \rightarrow \frac{f(z)-f(x)}{z-x} \leq 0 \qquad e \ quindi \qquad f^{'}_{+}(x)=\lim_{z\to x^{+}} \frac{f(z)-f(x)}{z-x} \leq 0$$
Essendo $f$ derivabile in x, si ha che $f^{'}(x) = 0$

# Punti stazionari

I punti in cui la derivata prima si annulla si dicono, *punti stazionari* per $f$. Più nello specifico se x non si trova agli estremi dell'intervallo allora $$x \ di \ estremo \ locale \rightarrow x \ stazionario$$


# Teorema del valor medio (o di Lagrange)

Sia $f$ derivabile nell'intervallo (a,b) e continua in [a,b] (fino agli estremi di intervallo), allora esiste:
$$c \in (a,b) \qquad  t.c. \qquad \frac{f(b)-f(a)}{b-a} = f^{'}(c)$$
![[Pasted image 20240804211319.png]]

Ovvero abbiamo un punto nel nostro grafico la cui pendenza della retta tangente è uguale alla pendenza della retta che interseca il punto (a,f(a)) e (b,f(b)).
![[Pasted image 20240804211430.png]]

# Test di monotonia

Sia $f:(a,b) \to R$ derivaile, allora:
$$f \qquad crescente \leftrightarrow f^{'}(x) \geq 0$$
$$f \qquad decrescente \leftrightarrow f^{'}(x) \leq 0$$![[Pasted image 20240804213156.png]]


# Teorema del confronto

$f,g : (a,b) \to R$ derivabili e tale che:
1) $g(a)\leq f(a)$
2) $g^{'}(x) \leq f(x)^{'} \quad \forall x \in (a,b)$
Allora
$$g(x) \leq f(x) \quad \forall x \in (a,b)$$
# Funzione Lipschitziana
![[Pasted image 20240804215847.png]]