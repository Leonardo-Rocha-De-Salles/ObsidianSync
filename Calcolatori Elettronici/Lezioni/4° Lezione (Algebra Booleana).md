L'algebra di Boole è utilissima per progettare su carta circuiti, prima di costruirli. Dato che le legge rispettano perfettamente i transistor.

**Variabile booleana (o di commutazione)** è una quantità algebrica x, definita su un insieme S = {0,1}, ovvero assume due valori (True or False).

**Funzione di commutazione** di una variabile booleana è definita come la proiezione di {0,1} su {0,1}:
- $f:\{0,1\} \to \{0,1\}$
- $y = f(x)$
Una funzione di commutazione di n variabili booleane è una funzione il cui dominio è dato da tutte le $n-uple(x_1,x_2,...,x_{n}) \ in \ \{0,1\}^{n}$ ed il codominio è {0,1}:
- $f:\{0,1\}^n \ to \{0,1\}$
- $y = f(x_1,...,x_n)$

# Operatori e assiomi fondamentali dell'algebra booleana
Considerando 1 come acceso e 0 come spento.
**Somma logica**: indicata con il segno + (Rappresentabile come il connettivo logico *OR*)
**Prodotto logico**: indicato con il segno * (Rappresentabile come il connettivo logico *AND*)
**Negazione** : dato un valore x, il suo valore negato è $\bar{x}$ (Rappresentabile come il connettivo logico *NOT*)
![[Pasted image 20241001123404.png]]In questo caso il nostro dominio ammette due valori $S : \{0,1\}$, anche se esistono infinite algebre booleane con insieme di cardinalità (numero di elementi) uguali a potenze di 2.
$$1+1 = 1 \qquad 1*1 = 1 \qquad 1+0 = 1 \qquad 1*0 = 0 \qquad 0+0=0 =0*0 $$
$$x = 0 \qquad \bar{x}=1$$
$$a+b(c) = (a+b)(a+c) =a(a+c) + b(a+c)=aa +ac+ba+bc = $$
$$a(c+b) +bc +a \ (dato \ che \ a*a = a)=a(1+(c+b))+bc= a+bc$$
Questo dato che $(1+(c+b)) = 1$ visto che abbiamo il + che è un OR, quindi indipendentemente dal valore di (c+b) abbiamo 1.
## Legge di dualità
Ogni identità booleana rimane invariata scambiando + con * e 0 con 1.
Ovvero faccio un sistema dove 0 è acceso, 1 è spento, il + diventa AND e il * diventa OR.
![[Pasted image 20241001124439.png]]

## Propreità di idempotenza
$$a+a = a \ e \ a*a = a$$
![[Pasted image 20241001124627.png]]

## Legge dell'assorbimento

![[Pasted image 20241004113531.png]]

## Teorema di De Morgan
![[Pasted image 20241002183733.png]]


# Funzioni di commutazione : rappresentazione

Una funzione di commutazione di n variabile è della forma $$y = f(x_{1,}\dots, x_n )$$
è una funzion il cui dominio consiste di tutte e sole le n-uple x1...xn e il codominio è l'insieme {0,1}
$$f:\{0,1\}^{n}\to \{0,1\}$$
Il dominio è finito dato che può assumere solo i valore 0,1.
Ci sono vari modi per esprimere una funzione di commutazione:
forma tabellare, canonica, decimale.
Se conosco tutti i valori del nostro dominio posso appunto creare delle tabelle con i valori del dominio.

# Tabelle di verità

Se ho $f(x_1,x_2,x_{3})=\bar{x_{1}}+ x_{2}* \bar{x_3}$ abbiamo il dominio che vale $2^{3}$ quindi 8 possibili risultati. che possiamo esprimere in una tabella facendo i calcoli di f.

| $x_1$ | $x_2$ | $x_3$ | $f(x_1,x_2,x_{3})$ |
| ----- | ----- | ----- | ------------------ |
| 0     | 0     | 0     | 1                  |
| 0     | 0     | 1     | 1                  |
| 0     | 1     | 0     | 1                  |
| 1     | 0     | 0     | 1                  |
| 0     | 1     | 1     | 0                  |
| 1     | 0     | 1     | 0                  |
| 1     | 1     | 0     | 1                  |
| 1     | 1     | 1     | 0                  |

Posso anche associare alle composizione binaria del mio dominio, un valore decimale.
![[Pasted image 20241004123401.png]]

## Tabella di verità degli operatori fondamentali
![[Pasted image 20241004123530.png]]

# Operatori derivati

Sulle tre operazioni fondamentali (somma, prodotto, negazione) possiamo definire operazioni derviate

## OR Esclusivo (XOR)
![[Pasted image 20241004123709.png]]
Ovvero solo 1 acceso, se ho 2 accesi viene fuori spento. Quindi due valori discordi.

## Not AND (NAND)

![[Pasted image 20241004123812.png]]
Ha valore positivo se ho tutto tranne il valore AND, quindi solo quando ho tutto acceso mi esce spento, il resto è sempre acceso.

## NOR

![[Pasted image 20241004123933.png]]
Opposto del NAND, ho acceso solo quanto ho tutto spento.

## NOR esclusivo (XNOR)
![[Pasted image 20241004124125.png]]
E' un AND dove però vale anche tutto spento dove fuoriesce acceso.