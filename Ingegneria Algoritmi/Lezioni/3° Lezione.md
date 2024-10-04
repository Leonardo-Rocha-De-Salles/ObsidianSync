# Soluzione di un sistema triangolare
Se la matrice dei coefficiente di un sistema è traingolare inferiore L, il sistema $Lx = b$
![[Pasted image 20241003163521.png]]
![[Pasted image 20241003163537.png]]


# Espressioni utili per calcolo di complessità
![[Pasted image 20241003163802.png]]
IlIlIlIlIlIlIlIlIlIlIlIlIlIlIlIlIlIlIlIlIlIlIlIlIlIlIlIlIIlIlIlIlIlIlI

# Complessità del insertion sorting
![[Pasted image 20241003170307.png]]




# Complexity di funzioni ricorsive
Solitamente si chiama la funzione con il dato n, per poi richiamarla con n-1...
Nella analisi delle funzioni ricorsive si usano spesso delle relazioni di ricorrenza, ossi delle equazioni del tipo
$$T(n)=G(T(n-n_1),T(n-n_2),...,T(n-n_k))$$
con $n_{j}<n$. Ad esempio una ricorrenza lineare a termini costanti sarà:
$$T(n) = \left(\sum\limits_{i=1}^{k}a_{i} \ T(n-i)\right)+ cn^{\beta}, \qquad n > k$$
## Teorema
![[Pasted image 20241003171539.png]]
Abbiamo alcuni valori che sappiamo apriori, come nella serie di Fibonacci i = 0, i = 1.

### Esempio Fibonacci
$$F(n) = F(n-1) + F(n-2)$$
$$T_{F(n)}= \sum\limits^{2}_{i=1} 1T(n-i)+1 \ n^{0} \rightarrow T_{F}(n) = O(2^{n})$$
## Dimostrazione

![[Pasted image 20241003172123.png]]![[Pasted image 20241003172451.png]]![[Pasted image 20241003172502.png]]
