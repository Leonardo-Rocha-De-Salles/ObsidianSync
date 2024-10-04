
# Definizione Algoritmo
Un algoritmo è un metodo che produce una risposta a partire dai dati, e che rispetta dei vincoli: 
1) Input
2) Output
3) Definitezza (nessuna ambiguità)
4) Efficacia (ciascun passo può essere eseguito in tempo finito)
5) [[1° Lezione (Algoritmi)#Finitezza di un Algortimo|Finitezza]] (esegue sempre un numero finito di passi)
Per definizione un aloritmo risponde **sempre** in tempo finito. 
Altrimenti stiamo parlando di un **metodo computazionale**.

### Per tutti  i problemi esiste un algoritmo di risoluzione?
**No**, non per tutti i problemi, esiste un algoritmo che lo risolve.
Esempi sono calcolare gli zeri di un polinomio completo di quinto grando.
Questa caratteristica viene dimostrato da **Alan Turing** [[1° Lezione (Algoritmi)#Teorema di Turing dell'arresto|Teorema di Turing dell'Arresto]].

### Per ogni problema c'è un solo algoritmo che lo risolve?
**No**, se l'insieme degli algoritmi che risolvono un problema non è vuoto, si apre la discussione di quale sia il "migliore".


# Algoritmo di Euclide
Il più antico algortimo attribuito ad un singolo individuo.
Serve per il calcolo del massimo comune divisisore **MCD** di due numeri interi
### Procedura Euclide(m,n)
Input: m ed n interi positive, $m>n$
begin:
	dividere m per n e calcolare il resto r;
	while r $\not =$ 0 do
		m $\leftarrow$ n, n $\leftarrow$ r;
		Dividere m per n e calcolare il resto r;


# Teorema di Turing dell'arresto
Correlato al teorema di incompletezza di Godel. Esistono problemi per i quali NON può esistere algoritmo risolutivo. 
Magari per alcuni problemi si possono scrivere algoritmi per risolvere certe istanze, ma su altre istanze non ha tempo finito.


# Finitezza di un Algortimo
Un algorttimo deve essere MOLTO finito, non solo finito.
Si valuta la qualità di un algoritmo descrivendone:

### Complessità temporale : 
Il tempo T(n) impiegato per risolvere un problema di dimensione n.

### Complessità spaziale :
quanittà di memoria impiegata S(n) per risolvere un problema di dimensione n.


Ma cosa vuol dire n? Per valutare T(n) si contano le **operazioni elementari** (assumendo che abbiamo più o meno tutte lo stesso costo, cosa che solitamente non è vera).

## Esempio:
Consideriamo il gioco degli scacchi; Claude Shannon considera un programma  che considera tutte le possibili sequenze di mosse e configurazione della scacchiera (finite).
1) Numero medio di (semi)mosse legali per configurazione : 30;
2) Numero medio di combinazioni di mosse Bianco/Nero : $10^3$;
3) Lunghezza media di una partita : 40 mosse;
Quindi dovremmo enumerare 
$$10^{120}$$
configurazioni possibili.



# Terminazione e Correttezza di un Algoritmo
La terminazione e correttezza di un algoritmo si dimostra spesso per induzione oppure utilizzando degli invarianti, proprietà vere all'inzio e che si mantengono durante l'esecuzione e fine dell'algoritmo.

## Principio di induzione:
Una affermazione è vera per il numero 0 (minimo di Q)
L'affermazione è vera per k + 1 (k >= Q);
L'affermazione è vera per tutti i naturali maggiore di Q.

Nei numeri naturali non può esistere una sequenza strettamente discendente ed infinita.



# Teorema dei Cavalli Bianchi
Dato un insieme di cavalli, se ne esiste uno bianco allora sono tutti bianchi.
Con un gruppo è semplice da vedere, il cavallo può essere bianco o no.
Se abbiamo k+1 cavalli



# Lavoro dell'informatico

1) Dato un problema trovare un algoritmo che lo risolva;
2) Studia l'esistenza di eventuali altri algoritmi e ne confronta l'efficienza;
3) Studia la rappresentazione dei dati necessaria alla soluzione del problema;
4) Costruisce una "buona" implementazione.