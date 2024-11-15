Quando si considerano input molto grandi, bisogna prendere in cosiderazione l'efficienza asintotica degli algoritmi.
# Notazione asintotica
Queste notazioni sono comode per descrive le funzioni $T(n)$
## Notazione $\Theta$
Data una funzione g(n), si denota con $\Theta (g(n))$ l'insieme di funzioni
$$\Theta(g(n))=\{f(n): \exists c_1,c_{2}, n_{0} \in N\ | \ 0\leq c_{1}g(n)\leq f(n)\leq c_{2}g(n) \forall n\geq n_0$$
Quindi la funzione f(n) appartiene all'insieme $\Theta (g(n))$ la funzione f(n) può essere schiacciata fra due prodotti scalari positivi di g(n) definitivamente dopo un dato numero.
![[Pasted image 20241017205420.png]]

## Notazione O
$\Theta$ limita asintoticamente una funzione da sopra e sotto, mentre O limita asintoticamente supriormente.
Data g(n), si denota con $O(g(n))$ l'insieme
$$O(g(n)) =\{f(n):\exists c,n_{0} \ | \ 0\leq f(n)\leq cg(n) \forall n \geq n_{0}  \}$$
Notiamo come se $f(n) = \Theta(g(n))$ implica che $f(n) = O(g(n))$ dato che Theta è semplicemente una notazione più forte e esclusiva di $O$  
$$\Theta(g(n)) \subseteq O(g(n))$$
![[Pasted image 20241017205937.png]]
## Notazione $\Omega$
$\Omega$ fornisce il limite asintotico inferiore di una funzione
$$\Omega(g(n)) = \{f(n): \exists c,n_{0} \ | \ 0 \leq cg(n) \leq f(n) \forall n \geq n_{0}\}$$
![[Pasted image 20241017210157.png]]

# Teorema
Per ogni coppia di funzioni f(n) e g(n) $f(n) = \Theta (g(n))$ se e solo se $f(n) = O(g(n))$ e $f(n) = \Omega(g(n))$
