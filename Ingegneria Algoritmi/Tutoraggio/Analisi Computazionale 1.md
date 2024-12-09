
# Analisi Computazionale di Ricorsioni
![[Pasted image 20241206165100.png]]
Abbiamo quattro motodi principilai per risolvere le ricorrenze:
**Metodo di sostituzione**:
Si ipotizza un limite e si usa l'induzione per verificarne la correttezza.

**Metodo dell'albero di ricorsione** : 
Converte la ricorrenza in un albero e somma i costi ai vari livelli

**Metodo dell'esperto**:
Per ricorrenze del tipo
$$T(n) = aT(n/b)
+ f(n)$$
**Teorema delle ricorrenze lineari con partizioni bilanciate**
Per ricorrenze del tipo 
$$T(n) = aT(n/b)
+cn^{\beta}$$

# Metodo della sostituzione

Prevede due passaggi:
- **Stima Asintotica** per $T(n)$.
- **Induzione su** n per dimostrare che la stima è corretta.

# Teorema delle ricorrenze lineari con partizioni bilanciate

![[Pasted image 20241206165617.png]]
# Teorema dell'esperto
![[Pasted image 20241206165635.png]]

## Caso 1 
![[Pasted image 20241206165649.png]]

## Caso 2
![[Pasted image 20241206165658.png]]
## Caso 3
![[Pasted image 20241206165710.png]]