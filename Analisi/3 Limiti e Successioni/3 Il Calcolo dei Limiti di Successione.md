Come si può calcolare un limite? Inanzitutto per utilizzare la definizione di limite dobbiamo già conoscere $l$

Cominciamo con esaminare le proprietà dell'operazione di limite rispetto alle *operazioni algebriche*.

# Teorema 3.3 (Algebra dei Limiti)
Siano dati due limiti
$$\lim_{n\to+\infty}a_{n}=a \qquad \lim_{n\to+\infty}b_{n}=b$$

Se $a_{n}\to a \ e \ b_{n}\to b$ allora
![[Pasted image 20240726141620.png]]
Per esempio:
$$\lim_{n\to+\infty}a_{n}+ b_n=a+b$$
Abbiamo anche
$$\lim_{n\to+\infty}|a_n|=|a|$$

# Proprietà algebriche successioni divergenti
![[Pasted image 20240726143528.png]]
![[Pasted image 20240726143538.png]]
![[Pasted image 20240731142435.png]]
![[Pasted image 20240726143628.png]]



# Teorema 3.4 (Di Permanenza del segno, 1° forma)

Se $a_{n}\to a$  e $a > 0$ $(a < 0)$ , allora $a_{n}>0$ *definitivamente* ($a_{n}<0$ *definitivamente*).

## Dimostrazione
Fissato $\varepsilon > 0$
$$|a_{n}-a |<\varepsilon \qquad definitivamente$$
Poichè possiamo scegliere $\varepsilon$ in modo che $a-\varepsilon>0$ la diseguaglianza dimostra che $a_{n}>0$ definitivamente.


# Teorema 3.5 (Di Permanenza del segno, 2° forma)
![[Pasted image 20240726142221.png]]



# Limiti e Ordinamento


## Teorema 3.6 (Del Confronto o Dei Carabinieri)

Se $a_{n}\leq b_{n}\leq c_n$ definitivamente $\forall n \in N$ e 
$$a_{n}\to l, c_{n}\to l\in R$$
$$\lim_{n\to+\infty}a_{n}=l \qquad \lim_{n\to+\infty}c_{n}= l$$
Allora Anche $b_{n}\to l$
$$\lim_{n\to+\infty}b_n=l$$
![[Pasted image 20240726142321.png]]

### Esempio:
![[Pasted image 20240731154535.png]]
Si usa spesso con le funzioni limitate trigonometriche

## Corollario (Permanenza del segno)

Si ha una successione che converge a $l$
$$Se \ a_{n}\geq 0 \ \forall n, allora \ l \geq 0$$
Osservazione, questo valore solo per maggioranza debole (zero incluso) perchè senza allora anche se alcune successioni sono maggiori di 0 per ogni membro, esse tendono a 0.
$$Se \ a_{n} \in [\alpha, \beta] \ \forall n,allora \ l \in [\alpha, \beta]$$


## Corollario 3.7 (Successioni limitate in rapporto o prodotto con successioni divergenti)

1) Se $|b_{n}|\leq c_n$ definitivamente e $c_{n}\to 0$, allora anche $b_{n}\to 0$
2) Se $c_n\to0$ e $b_n$ è *limitata* (non necessariamente convergente) allora $c_{n}b_{n}\to 0$
Detto a parole: *Il prodotto di una successione infinitesima e una limitata è infinitesimo*
*Il rapporto di una successione limitata con una infinita è uguale a 0*
$$\lim_{n\to+\infty}\frac{sin(n)}{n}=0$$
![[Pasted image 20240726143416.png]]



## Teorema sul limite del reciproco

{$a_n$} sia un successione diversa da 0 per ogni n e $\lim_{n\to+\infty}a_{n}=a$  con a diverso da 0. Allora
$$\lim_{n\to+\infty} \frac{1}{a_{n}}= \frac{1}{a}$$
Questo deriva anche dal teorema dell'algebra dei limiti sul quoziente.



# Limite destro e sinistro

Sia data una successione t.c
$$\lim_{n\to+\infty} a_{n}= 0$$
Se $a_{n}\geq 0, \forall n \in N$ diciamo che
$$\lim_{n\to+\infty}a_{n}= 0^+$$
Se $a_{n} \leq 0, \forall n \in N$ diciamo che
$$\lim_{n\to+\infty}a_{n}=0^{-}$$