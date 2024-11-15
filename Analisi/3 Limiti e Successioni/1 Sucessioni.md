# 1 Successioni

# 1.1 Definizione di successione e di limite

Consideriamo l'insieme $N$ degli interi positivi ordinati.
$$N : 0,1,2,3,4,...,n,...$$
Questo è l'esempio canonico di successione. Stabiliamo una legge che associa a ogni elemento di N un numero reale.$$n \to a_n$$
Chiameremo *successione* una tale corrispondenza. Che si può vedere come
$$f:n \to a_n$$
Il dominio della funzione $f$ sono l'insieme dei naturali, rende possibile visualizzare la successione enumerando i suoi valori, nell'ordine in cui essi si succedono.

Esempio:
![[Pasted image 20240725154207.png]]

**La successione è nota come legge che data l'intero n, determinare il numero $a_n$ associato a quell'intero**. Per indicare una successione useremo i simboli
$$n \to a_{n}\qquad oppure \qquad \{a_n\}$$

## Successione limitata

Una successione $\{a_n\}$ si dirà:
$$limitata \ inferiormente \text{ se esiste un numero m tale che} \qquad a_{n}\geq m \forall n$$
$$limitata \ superiormente \text{ se esiste un numero M tale che} \qquad a_{n}\leq M \forall n$$
$$limitata  \text{ se esistono due numeri m e M tale che} \qquad m\leq a_{n}\leq m \forall n$$![[Pasted image 20240725160048.png]]

Per esempio la successione $\{(-1)^n\}$ è limitata; $\{n^2\}$ è limitata inferiormente, $\{(-2)^n\}$ non è limitata.

**NOTARE, UNA SUCCESSIONE LIMITATA NON PER FORZA HA TENDE A UN LIMITE, MENTRE SE UNA FUNZIONE TENDE A UN LIMITE (CONVERGENTE) ALLORA CERTAMENTE E' LIMITATA (SUPERIORMENTE E/O INFERIORMENTE)** come nel caso di (-1)^n

L'operazione che vogliamo definire è il **limite** che risponde alla domanda: *come si comportano i numeri $\{a_n\}$ quando $n$ diventa sempre più grande?*


## Definizione 3.1 (Definitivamente)

Una successione possiede *definitivamente* una certa proprietà se esiste un $n_0 \in N$ tale che $a_n$ soddisfa quella proprietà per ogni intero $n \geq n_0$



## Definizione 3.3 (Limite Successione)

Il numero $l$ si chiamata *limite* della successione $\{a_n\}$ se :$$\forall \varepsilon > 0, \exists \ n_{0} \in N \ | \ \forall n \geq n_{0} \to |a_{n}-l| < \varepsilon$$
Che equivale a dire:
$$l-\varepsilon<a_n<l+\varepsilon$$
Quindi esiste definitivamente una fascia di piano, dove per qualsiasi valore di $\varepsilon$ quindi l'ampiezza di questa fascia, abbiamo che $a_{n}$ rientra ancora all'interno di questa fascia.
Ed in quel caso il **limite** della successione si scrive
$$\lim_{n\to+\infty}a_{n}= l \qquad oppure \qquad a_{n}\to l \ per \ n \to +\infty$$
Quindi ricapitolando:
$$\lim_{n\to+\infty}a_{n}= l \longleftrightarrow \forall \varepsilon > 0, \exists \ n_{0} \in N \ | \ \forall n \geq n_{0} \to |a_{n}-l \ | < \varepsilon$$
![[Pasted image 20240725212742.png]]
Esercizio:

![[Pasted image 20240725212805.png]]
![[Pasted image 20240730214424.png]]


## Definizione 3.2 (Convergenza e Limite)

Una successione si dice *convergente* se esiste un numero $l \in R$ con questa proprietà: qualsia sia $\varepsilon$ > 0 risulta definitivamente
$$|a_{n}- l| < \varepsilon$$
In altre parole: per ogni $\varepsilon > 0$ si può trovare un intero $n_0$ (che dipenderà da questo $\varepsilon$) tale che:
$$|a_{n} - l | < \varepsilon \qquad \forall n \geq n_0 $$
Ovvero
$$l - \varepsilon < a_{n}< l + \varepsilon$$
Se una successione è convergente è associata ad un unico numero $l$.

## Dimostrazione unicità limite $l$ di una successione.

Dimostrazione per assurdo: se avessimo $l_1$ e $l_2$ associati a una medesima successione:
$$l_1,l_{2}\in R \quad \lim_{n\to+\infty} a_{n}= l_{1} \quad e \quad \lim_{n\to+\infty} a_{n}= l_2$$
Dimostriamo che possiamo ottenere una contraddizione data dalla definizione di limite di una successione.
$$l_{1} \not = l_{2} \to |l_{1}-l_{2}| \not = 0$$
Allora poniamo per definizione $\varepsilon = |l_{1}-l_{2}|$ dato che è > 0.
$$|l_{1}-l_{2}| = |l_{1}- a_n+a_n-l_{2}|\leq |l_{1}-a_n|+|a_{n}-l_{2}| < 2\varepsilon \not = \varepsilon$$
(SPIEGAZIONE), nel secondo passaggio sommo e sottrago a con n, che essendo lo stesso numero è uguale a 0. Poi applico la diseguaglianza triangolare dei moduli. Come vediamo alla fine anche se per inizio abbiamo dato una definizione per epsilon troviamo un'altra lla fine.
Questa diseguaglianza è vera solo se $l_{1} \ e \ l_{2}$ sono uguali.



## Definizione 3.4 (Successioni divergenti e irregolari)

Quando al crescere di $n$ una successione supera *definitivamente* qualunque numero $\forall M \in R, a_{n}>M$ fissato, diremo che **diverge** a $+\infty$; se invece scende al di sotto di -M ($a_n$ < M definitivamente), **diverge** a $-\infty$
$$
\lim_{n\to+\infty} a_{n}= +\infty \qquad  \lim_{n\to+\infty}a_{n}= -\infty
$$

### Definizione di $\infty$

Questi simboli non sono numeri, a questi punto non corrisponde alcun numero sulla retta dei numeri.
L'insieme reali $R$ con l'aggiunta di $\infty$ sarà indicato con $R^*$


Esistono anche successioni che non divergono ne convergono, come la successione di {(-1)^n} che sono dette *irregolari* (oscillante) o *indeterminate*.


## Definizione 3.5

Se l'insieme $E \subseteq R$ non è limitato superiormente (inferiormente), diremo che:
$$sup E = +\infty (inf E = -\infty)$$
In questo modo enunciamo la $R_4$ dei numeri reali in quesot modo:

****ogni insieme $E \in R$ non vuoto è dotato di estremo superiore e inferiore; sup E (inf E) è un numero se $E$ è limitato superiormente (inferiormente), altrimenti è $+ \infty (- \infty)$


## Infinitesimi e infiniti

Una successione tendente a zero si dice *infinitesima*, ad esempio {1/n}.
“infinitesimo” non è un “numero infinitamente piccolo” (concetto privo di senso, se non si vuole che denoti semplicemente il numero 0) **ma una quantità variabile** (successione o, come vedremo, funzione), **che diviene indefinitamente piccola**.
$$\lim_{n\to+\infty} a_{n}= 0$$
Analogamente una successione tendente a infinito si dice *infinita*.

## Definizione 3.6

Si dice che una successione tende a $l \in R$ per *eccesso* (*per difetto*), e si scrive:
$$\lim_{n\to+\infty}a_{n}= l^{+} \qquad oppure \qquad a_{n}\to l^{+}\ per \ n\to +\infty$$
$$(\lim_{n\to+\infty}a_{n}= l^{-} \qquad oppure \qquad a_{n}\to l^{-}\ \ per \ n \to +\infty)$$
se per ogni $\varepsilon >0$ si ha che 
$$0 \leq a_{n}- l <\varepsilon \qquad definitivamente$$
$$(0 \leq l-a_{n} <\varepsilon \qquad definitivamente) \qquad caso \ l^{-}$$
In sostanza $a_{n}\to l^+$ significa affermare che $a_{n}\to l$ inoltre $a_{n}\geq l$ definitivamente, dunque $a_n$ si avvicina ad $l$ "da sopra".