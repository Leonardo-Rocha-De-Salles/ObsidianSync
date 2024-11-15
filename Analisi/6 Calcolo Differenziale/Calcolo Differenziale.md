Il calcolo differenziale risponde a due tipologie di Problemi:
1) Problema di tipo geometrico, la costruzione della retta tangente al grafico della funzione in una dato punto
2) Problema di approssimazione, sostituiendo una funzione con un'altra e stimando l'errore commesso

# Problema geometrico

![[Pasted image 20240804172155.png]]

Prendiamo in considerazione un grafico, attraversato da una retta secante nei punti $(x_{0},f(x_{0})), (x_{0}+ h, f(x_{0}+h))$ con equazione del tipo:
$$y = f(x_0) + \frac{f(x_{0} + h) - f(x_{0})}{h}(x-x_0)$$
Vediamo che:
$$\frac{f(x_{0} + h) - f(x_{0})}{h}$$
E' il **coefficiente angolare della retta**, dove il numeratore è la variazione della quota, mentre il denominatore la variazione del percorso.
$$tan(\alpha) = \frac{f(x_{0} + h) - f(x_{0})}{h}$$
Se riduciamo questo spazio h a un numero molto piccolo che tende a 0, la nostra retta secante mano a mano diventa una retta tangente. Quindi:

## Def

$f:[a,b]\to R, x_{0} \in R$, allora $f$ si dice derivabile in $x_{0}\in[a,b]$ se esiste finito
$$\frac{df}{dx}(x_0)=\lim_{h\to 0} \frac{f(x_{0} + h) - f(x_{0})}{h} \qquad derivata \ di \ f \ in \ x_0$$
In questo caso il nostro limite si chiama **rapporto incrementale**


L'equazione della nostra retta tangente in $x_0$ sarà
$$y = f(x_{0})+ f^{'}(x_0)(x-x_0)$$
Osservazione:
Nella definizione di derivata, $x_{0} \in X$ deve essere un punto interno a $X$ cioè $\exists \delta >0 \ t.c. \ (x_{0}-\delta,x_{0}+\delta)\subseteq X$

Poi abbiamo che la definizione di derivata si può anche scrivere come
$$lim_{x\to x_{0}} \frac{f(x)-f(x_{0})}{x-x_{0}}$$


# Relazione fra derivabilità e continuità

Se una funzione f è derivabile in un punto, allora è continua in quel punto. Cioè **la derivabilità implica la continuità ma non il viceversa**.
![[Pasted image 20240804174103.png]]
![[Pasted image 20240804174108.png]]

![[Pasted image 20240804175057.png]]



# Derivabilità da destra e sinitra

Siano $f : (a,b) \to R, x_{0} \in (a,b)$. Se esistono finiti i limiti.
$$\lim_{h\to 0^{+}} \frac{f(x_{0} + h) - f(x_{0})}{h} \qquad \lim_{h\to 0^{-}} \frac{f(x_{0} + h) - f(x_{0})}{h}$$
Allora si dice che la funzione è **derivabile da destra nel primo caso, e da sinistra nel secondo.** e si indica con
$$f^{'}_{+}(x_0)\qquad  f^{'}_{-}(x_{0})$$
$f$ è derivabile in un punto solo se $f$ è continua in quel punto e
$$f_{+}^{'}(x_{0}) = f_{-}^{'}(x_{0})$$