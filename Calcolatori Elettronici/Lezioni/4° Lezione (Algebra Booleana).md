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
OR Esclusivo basta pensare che nell'or normale è valido anche 1, 1 che sarebbe AND, quindi OR Esclusivo lo toglie
![[Pasted image 20241004123709.png]]
Ovvero solo 1 acceso, se ho 2 accesi viene fuori spento. Quindi due valori discordi.

## Not AND (NAND)
Tutto ciò che non è AND
![[Pasted image 20241004123812.png]]
Ha valore positivo se ho tutto tranne il valore AND, quindi solo quando ho tutto acceso mi esce spento, il resto è sempre acceso.

## NOR
Tutto ciò che non è OR
![[Pasted image 20241004123933.png]]
Opposto del NAND, ho acceso solo quanto ho tutto spento.

## NOR esclusivo (XNOR)

![[Pasted image 20241004124125.png]]
E' un AND dove però vale anche tutto spento dove fuoriesce acceso.


# Teorema di Shannon Forma Canonica

$f(x_1,x_{2}), x_{1}\in \{0,1\}, f(1,x_{2})$ se $x_{1}=1 \rightarrow f(1,x_{2})=x_{1}f(1,x_{2})$, se invece vale 0  $\bar{x_{1}}f(0,x_{2})$ dato che moltiplicando per 1 non altera il valore booleano.
$$x_{1}f(1,x_{2})+\bar{x_{1}}f(0,x_{2}) = $f(1,x_{2}) + f(0,x_{2})$$
Questo ragionamento vale anche per
$$\bar{x_2}x_{1}f(1,0)+\bar{x_{1}}x_2f(0,1) + {x_1}x_{2}f(1,1)+\bar{x_{1}}\bar{x_2}f(0,0)= f(1,1) + f(0,1) + f(1,1)+f(0,0)$$
Una funzione generica di n variabili può essere rappresentata come un insieme di termini che si sommano fra di loro, con ciascun termine calcolato in un determinato punto moltiplicate per una varabile in modo che essa valga 1.
![[Pasted image 20241011115853.png]]


Le forme canoniche sono rappresentazioni della funzione dove tutte le variabili compaiono almeno una volta a membro.
## Forma canonica in somma di prodotti


![[Pasted image 20241011120329.png]]
Quindi tutte le funzioni booleane grazie al teorema di Shannon possono essere rappresentati come somma di prodotti. Dove sopravvivono solo i mintermini associati che moltiplicano i punti dove la $f$ fa 1.
![[Pasted image 20241014122345.png]]
Devo pensare di avere $f(x_1,x_2,x_{3})$ e moltiplicare per i termini che non variano.

***ovviamente solo quando la funzione ha come risultato 1, ho dei prodotti. Dopo aver individuato dove la funzione fa 1, devo prendere le x e scriverle come prodotti l'una fra l'altra in modo che tutte le x valgono 1. Perciò se ho x_1 = 0, $\bar{x_{1}}$ ******
## Forma canonica in prodotti di somme
Applicando il teorema di de Morgan
Possiamo anche calcolare la funzione negata:
![[Pasted image 20241011120541.png]]
![[Pasted image 20241014122101.png]]


La forma canoniche del prodotto di somme, devo prendere in considerazione tutte le le volte in cui la funzione fa 0, prendendo i singoli termini della funzione sommandoli tutti in modo che ciascuno faccia 0 (come tutte le somme). Quindi è un prodotto continuo di 0.

## Identificazione di mintermini e max termini
I *mintermini* di una funzione sono i posti in essa dove la funzione fa 1, ed è quindi  rappresentabile con una **Somma di Prodotti**, mentre i *maxtermini* sono rappresentati dai posti dove la funzione ha valore 1 ed è rappresentabile il **Prodotto di Somme**.
![[Pasted image 20241011121317.png]]
![[Pasted image 20241011121353.png]]
![[Pasted image 20241011121411.png]]
![[Pasted image 20241011122437.png]]

## Forma decimale
![[Pasted image 20241011123342.png]]

I numeri all'interno della sommatoria stanno a rappresentare in quali posizioni nella tabella i numeri fanno 1, nella moltiplicatoria quali valgono 0. Si inizia dal numero 0 e i numeri successivi rappresentano in binario la posizione.
Quindi k = 5 abbiamo come numero binario rappresentato dalle nostre x 101.


## Semplificazioni Canoniche
Minimizzare i termini di una funzione booleana ci permette di identificare circuiti più compatti.
![[Pasted image 20241011123552.png]]
![[Pasted image 20241011124514.png]]

Quindi da una forma canonica possiamo semplificare il nostro circuito con questi passaggi, solitamente si cerca sempre di prende in considerazioni coppie con più elementi simili e soltanto un elemento opposto all'altro, in modo che esse si annullano.




# Mappe di Karnaugh
Sono un diverso tipo di tabelle di verità, che ad occhio ci permette di trovare subito i termini semplificabili.
Le variabili sono organizzate in tabelle quadrate o rettangolari, e i valori delle loro variabili vengono ordinate secondo un codice di **Gray**.
In questo modo da una cella all'altra si ha il cambiamento di un singolo valore di una variabile.
E' possibile eliminare una variabile se la funzione assume lo stesso valore in gruppi di celle adiacenti.
E' utile per gli umani fino a 6 variabili.

Vediamo un esempio:
![[Pasted image 20241014132414.png]]
Una mappa di karnough è fatta nel seguente modo, si prende una tabella di verità e si descrive la mappa di karnough.
Il prossimo passaggio è cerchiare le coppie di 1 e studiare quali informazioni riusciamo ad ottenere. In questo caso prendiamo la prima coppia di 1 orizzontale, possiamo notare che al variare di A, il risultato non cambia, perciò quei 1 dipendono entrambi da B. Quindi scriviamo B
$$B$$
Adesso vediamo come oltre a dipendere da B, dipende anche dal fatto che C sia 0 per essere 1, perciò scriviamo
$$B\bar{C}$$
Passiamo alla prossima coppia di 1, quella verticale all'ultima colonna.
Questa colonna non dipende da C, ma invece prende il suo valore quando A = 1 e B = 0. Perciò
$$A\bar{B}$$
Mettendo tutto insieme:
$$f=B\bar{C} + A\bar{B}$$

***Quindi scrivo tutti i membri delle nostre coppie di 1, che anche se cambiano valore, il risultato NON cambia.***


**Questo accoppiamento di uno va fatto per tutti gli 1, quindi in caso ho 1 dispari, è permesso riutilizzare l'1 adiacente di un altra coppia**

![[Pasted image 20241014133138.png]]


La codifica di Gray permette che anche le celle agli estremi siano adiacenti, oltre a quelle adiacenti.
![[Pasted image 20241014133345.png]]

![[Pasted image 20241011124810.png]]

![[Pasted image 20241014133004.png]]

![[Pasted image 20241014133015.png]]

Se abbiamo tabelle più grandi dove invece di coppie di 1 abbiamo 4, 1 adiacenti possiamo fare nel seguente modo:
![[Pasted image 20241014133616.png]]
Notare che questi raggrupamenti vanno a potenze di 2, o una coppia di 2, gruppo di 4,8,16...
Queste funzioni possono essere semplificate in maniera molto semplicemente, basta vedere gli 1 da chi dipendono. In questo esempio
$$f = \bar{A}\bar{B} + AD$$
Lo stesso vale anche per i punti agli angoli, dato che sono considerati adiacenti.

**Esistono infiniti modi di rappresentazione booleana, quindi non perforza il risultato che ottengo deve essere l'unico.**
Dato che possiamo raggruppare in diversi modi le coppie o gruppi di 1, ottenendo diverse forme semplificate.
![[Pasted image 20241014142824.png]]
In questo caso non si hanno semplificazioni.
Tutti queste esempi sono stati fatti con somme di prodotti, adesso vediamo con prodotto di somme.
![[Pasted image 20241014142908.png]]
## Adiacenze
![[Pasted image 20241014143332.png]]

## 5 Variabili
Dobbiamo sovvrappore le due tabelle, dato che il raddoppiamento dei gruppi di 1 lo posso fare anche sull'asse z
![[Pasted image 20241014144127.png]]
Per esempio qui abbiamo il gruppo giallo che è di 8 elementi.


## Don't care conditions
Le nostre funzioni booleane possono essere anche solamente specificate, in questi casi il valore dell'uscita non è definito per tutte le configurazioni di variabili d'ingresso.
In questi casi il min e maxtermini vengono associati a un insieme $\sum_{0/1}$ che rappresenta i lfatto che non è noto il valore della funzione.
Tale condizione nella mappa di karnough viene rappresentata con un trattino (-)
![[Pasted image 20241014144519.png]]
L'assunzione è che questi valori non ci interessano.
**Possiamo considerare questi trattini come 0 o 1, come più ci è comodo.
Quindi possiamo ignorarli oppure considerare come 1 o 0.**
Io devo sempre cercare il numero minore di insiemi più grandi.


# Operatori Universali

I tre operatori logici dell'algebra booleana sono AND,OR,NOT. Ma uno di questi può essere eliminato.
Per il teorema di De Morgan possiamo sostituire l'AND con l'OR.
![[Pasted image 20241014150113.png]]

Anzi potremmo addirittura utilizzare il NAND per eseprimere tutta l'algebra booleana.
![[Pasted image 20241014150145.png]]

Visto che l'operatore NOR è definito come duale del NAND, vale lo stesso anche per lui.
![[Pasted image 20241014150215.png]]