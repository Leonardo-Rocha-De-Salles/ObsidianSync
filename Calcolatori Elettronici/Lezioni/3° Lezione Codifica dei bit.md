# Codifiche arbitrarie
Dati n cifre binaria, possiamo farle corrispondere a quello che vogliamo.

Dati N elementi da rappresentare, n cifre binarie disponibili per la codifica e m = $log_{2} N$:
Se n = m, allora il codice è *irridondante*, non esistono altri modi nella mia codifica di rappresentare un simbolo.
Se n > m, allora il codice e *ridondante* ci sono più modi nella mia codifica per rappresentare lo stesso simbolo. Permettono di identificare o correggere errori di trasmissione di codice etc...

Nel caso di un codice ridondante, le $k = n-m$ cifre aggiuntive sono chiamate *cifre di controllo*.


## Esempio di codice irridondante : codifica ASCII

### ASCII Tradizionale
7 bit, permette di rappresentare 128 caratteri, nessun accento.
Codici di controllo \[0,31\] e 127
L'ottavo bit del byte era usato come codice di *controllo di errore*.

### ASCII esteso:
8 bit con 256 caratteri rappresentabili (compresi i codici di controllo).


## Codice binary coded decimal (BCD)

Codice irridondante per rappresentare le 10 cifre decimali usando quattro cifre binarie.
Tipicamente due cifre sono memorizzate in un singolo byte.
Molti bit sprecati.
Funziona nel prendere un numero decimale, e codificare ogni suo elemento in binario, per poi metterli in fila.
$$1530 = 0001(1) \ 0101(5) \ 0011(3) \ 0000(0)$$
Comodo per consentire la veloce interazione uomo / macchina.


## Codice di Gray
Irridondante a lunghezza fissa.
tra due numeri adiacenti cambia una ed una sola cifra binaria.
Utile nel caso di contatori elettromeccanici per evitare fenomini transitori. (spegnere diversi interruttori per avere un numero adiacente).
![[Pasted image 20240930150532.png]]


## Distanza di Hamming h
Il numero minimo di cifre diverse fra tutte le possibili coppie di parole nel codice:
$$d (10010,01001) \to h = 4$$
$$d(11010,11001) \to h = 2$$
La distanza di hamming di un codice è 
$$h = min(d(x,y)) \qquad \forall \ x \not = y$$
Un codice irridondante ha distanza 1
Un codice ridondante è capace di rivelare errori di peso $\leq h -1$



## Codice ridonante
![[Pasted image 20240930151631.png]]


# Codici rivelatori di errore

Nella trasmissioni di dati ci possono essere dei bit che vengono scambiati per cause esterne. Dobbiamo trovare dei modi di rilevare questi errori.
Un codice ridondante è capace di rivelare errori di peso $\leq h-1$

## Codice di parità
Un semplice codice ridondante con h = 2
Si ottiene aggiungendo una cifra di parità ad un codice irridondante.
La cifra di parità è l'ultima cifra che abbiamo, e rappresente la somma degli 1 che abbiamo, se gli 1 sono pari allora alla fine del codice abbiamo un 0, se sono dispari abbiamo un 1.
Quindi possiamo rilevare soltanto un errore nel nostro codice.
## Codice di disparità
Stessa cosa ma con l'ultimo bit scambiato, gli 0 rappresentano dispari e 1 pari.


# Metodo di costruzione di codici a distanza h>2

Data una parola di codice $m = n+k$ cifre, con $n \leq 2^{k}-k-1$
I bit in posizione $2^{i}$ sono bit di parità, e ciascun bit di parità controlla la correttezza dei bit di informazione, la cui posizione, espressa in binario, ha un 1 nella potenza di 2 corrispondente al bit di parità
I bit di informazione sono quelli non in potenza 2.
![[Pasted image 20241001114940.png]]

## Esempio
Trasformiamo un valore ASCII a n = 7 bitt in un codice di Hamming h = 3
$$n \leq 2^{k}-k-1, k = 4 \ e \ m = 11$$
Quindi abbiamo 4 bit di parità, rappresentato da k, con un totale di 11 bit, rappresentato da m.
Supponiamo di codificare la cifra ASCII 0 (ovvero 0110000)
![[Pasted image 20241002190029.png]]
Quindi riassumendo:
- Trovo tutti i bit di parità, ovvero quelli che sono in posizione di potenz di due
- Dipendendo dalla loro posizione trovo il loro valore binario (essendo potenze di due sono un 1 seguite da 0) Quindi per esempio 2 = 10, 4 = 100, 8 = 1000... 
- Converto tutte le posizioni, il primo essendo a sinistro e l'ultimo essendo a destra, in numeri binari.
- Le caselle che hanno un 1 neila potenza di un bit di parità, verrà controllato da quel bit di parità. Es, la posizione 1,3,5,7,9,11 vengono controllati dal bit di parità $p_1$ dato che $p_1$ ha posizione 1 = 1 in binario, mentre 1,3,5,7,9,11 sono tutti binari del tipo ...1, ovvero con 1 in posizione 0.
- Dopo aver trovato le caselle che controlla ogni bit di parità, considero i bit di informazione, sommandoli e vedendo se esce un numero pari o dispari.
- Scrivo a ogni bit di parità se gli corrisponde 1 o 0
- Scrivo il mio codice mettendo i bit di parità dove devono andare.

## Controllo se codice di hamming ricevuto è corretto

per controllare se è corretto faccio come prima, mettendo però nelle caselle dei codice di parità la cifra di parità che ho. Se alla fine di tutto mi viene fuori che la somma di ogni riga è (0000...) allora non ho errore, però se mi esce fuori un 1. devo trasformare il risultato in decimale, la cifra che mi esce mi dirà dove sta il bit errato.


