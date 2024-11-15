# Ricorrenze
Le ricorrenze possono assumere diverse forme:
- Algoritmo con sottoproblemi di dimensioni diverse: $$T(n)=T(2n/3)+T(n/3)+\Theta(n)$$
- Algoritmo che riduce il problema di una quanittà fissa: $$T(n)=T(n-1)+\Theta(1)$$
Le ricorrenze aiutano a modellare il comportamento di algoritmi ricorsivi.
## Metodi principali per risolvere ricorrenze
- **Metodo di sostituzione**
	- Si ipotizza un limite e si usa l'induzione per verificare la correttezza
- **Metodo dell'albero di ricorsione**
	- Converte la ricorrenza in un albero e somma i costi ai vari livelli 
- **Metodo dell'esperto**
	- Per ricorrenze del tipo:$$T(n)=aT(n/b)+f(n)$$
- **Teorema delle ricorrenze lineari con partizioni bilanciate**
	- per ricorrenze del tipo: $$T(n)=aT(n/b)+cn^{\beta}$$



# Metodo della sostituzione
Prevede due passaggi, la stima asintotica per $T(n)$ e l'induzione su n per dimostrare che la stima è corretta.


# Teorema delle ricorrenze lineari con partizioni bilanciate
![[Pasted image 20241017184903.png]]

# Teorema dell'esperto
![[Pasted image 20241017185100.png]]

## Caso 1
$$f(n) = O(n^{log_{b}a-\varepsilon})$$ per qualche $\varepsilon > 0$ allora:
$$T(n)=\Theta(n^{log_{b}a})$$
## Caso 2
![[Pasted image 20241017185236.png]]
## Caso 3
![[Pasted image 20241017185251.png]]
## Teorema dell'esperto
Date $a \geq 1 \ e \ b > 1$ e la funzione f(n), sia T(n) una funzione definita sugli interi non negativi dalla ricorrenza:
$$T(n) = aT\left(\frac{n}{b}\right)+ f(n)$$
# Ricorrenze lineari di ordine costante
![[Pasted image 20241017185425.png]]

# Esercizi

## 1
$$T(n) = \begin{cases}n^{3}+3T(\frac{n}{3}) && n > 1 \\
1 && n=1
\end{cases}$$
Dimostrare applicando il metodo di sostituzione che $T(n) = O(n^3)$
$$n^{3}+ 3T\left(\frac{n}{3}\right)\leq n^{3}+ 3c(\frac{n}{3})^{3}$$
per Induttività
$$T\left(\frac{n}{3}\right)\leq c(\frac{n}{3})^{3} = n^{3}+ \frac{1}{9}cn^{3}$$




## 4
Trovare la soluzione della seugente relazione di ricorrenza utilizzando il teorema dell'esperto
$$T(n) = 4T(\frac{n}{2})+n^{2}$$
$a= 4, b=2 \qquad f(n) = \Theta(n^{log_{2}4}) = n^{2}$ allora:
$$T(n) = \Theta(n)$$