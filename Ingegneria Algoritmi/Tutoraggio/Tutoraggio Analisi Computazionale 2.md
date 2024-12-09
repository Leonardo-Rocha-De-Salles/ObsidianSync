![[analisi_computazionale_2.pdf]]

# 1

![[Pasted image 20241205211124.png]]

```
int count = 0 #1
for (int i = n; i>0; i = i/2){ #log(n) volte
	for(int j = 0; j<i; j++){ #n + n/2...
		count ++; #1
	}
}

O(n*log(n))

```

## Motivo per cui il ciclo esterno è log(n)

Abbiamo i = n, e il ciclo termino quando i = 1, dato che 1 / 2 = 0.5 = 0 per C.
Questo significa che otteniamo $$
\frac{n}{2^{k}}= 1 \qquad cicli
$$
$$k = log_{2}(n)$$
# 2

![[Pasted image 20241205212221.png]]

Il primo ciclo for, avviene  $\frac{n}{2}$ volte, il secondo ciclo interno,  $log(n)$.
$$O(nlog(n))$$