
Prepocessore sostituisce pezzi di testo con altri pezzi di testo. Input e Output di programma è sempre lo stesso (per esempio entra un programma in C nel preprocessore, ne fuoriesce uno in C).

Il compilatore legge tutti i caratteri e li tokenizza, per poterli manipolare tramite regole (per esempio il nome di una variabile, !=, if, while...).
Ne fuoriescono degli alberi sintaticci astratti che rappresentano come i pezzi del nostro programma interagiscono fra di loro.

Il compilatore genererà del codice assembly a seconda dell'architetture del computer.

Il risultato è un Object File.

Per un programma potrei avere più file Oggetti, che successivamente devo essere agganciati insieme da un Linker, che prende in unput Object File, incollandoli insieme.

Alla fine otterremo un'unica sezione .data .text.
Ovvero un file eseguibile, un file oggetto o una libreria dinamica.

![[Pasted image 20241118143523.png]]

Mettendo i flag -E mi fermo dopo la fase di preprocessamento, con -S mi fermo alla faste dopo la compilazion o con -C mi fermo alla fase di linking.

Con -E otteniamo un file.c dove i file inclusi con #include vengono tutti inseriti nel nostro programma, e viene anche eliminato qualisasi commento.

Con -S otteniamo come risultato del codice assembly.

Con -C abbiamo come risultato un file.o che sarebbe le istruzioni binarie del mio programma.

Con **objdump** posso riottenere del codice assembly da del codice binario (incluso file esecutabili).

Il main prende in argomento 1 variabile in e un array
**int main(int argc, char \*argv[])** dove argc è il numero di argomenti che prende il main, mentre argv è il vettore che li contiene tutti. (gcc -c -o sono 3 argomenti per esempio).

La cima dello stack, sopra, è il valore più basso mentre più scendiamo più incremento c'è.

**RSP register stack pointer e RBP register base pointer**, servono a definire le finestre di stack di un programma. Uno punta alla cima delo stack, ovvero l'elemento aggiunto di più recente, e l'altro alla base della finestra di stack corrente. Viene generata una nuova finestra di stack ogni volta che viene chiamata una funzione.
L'RSP rimane lo stesso finchè qualcosa non viene tolto dallo stack oppure aggiunto
Quindi quando faccio il call a una funzione, il RSP punterà all'indirizzo di ritorno RET, che è stato pushato nello stack.
Quando il RET viene chiamato, ritorniamo a dove ci dice l'indirizzo, facendo il pop dello stack.

Quando abbiamo una nuova funzione facciamo push ebp per mettere lo stack base sopra e poi muoviamo lo stack pointer dove sta la stackbase.

qunado utiizzo xorl di un registro con se stesso mi ritorna sempre 0.


# Scheletro di un programma Assembly

![[Pasted image 20241119113627.png]]

## Direttive Assembly

- **label** : mnemonico testuale associato all'indirizzo di ciò che la segue immediatamente. Il programma traduce questa etichetta con l'indirizzo di memoria associato
- **Location Coutner** : idetificato da **.**, viene valutato il valore dell'indirizzo corrente:
  - Può essere usata per saltare la generazione di indirizzi
  - Può essere usato per calcolare le dimensioni di strutture dati:
	    msg:
		    .ascii "Hello, world!\\n"
		    len = . - msg
		(Prendo dove punta la memoria dopo aver messo tutti i caratteri, poi tolgo l'inizio del programma in memoria, e ottengo la lunghezza della stringa. ES: 1000 inizio, 1006 dove punta dopo aver messo la stringa. 1006 - 1000 = 6, numero di caratteri).
- **.org address, fill** : imposto il location counter, impostando i byte a fill.
- **.equ** symbol, expression: definisce una costante:
	  .equ SETTE, 7
	  moveq $SETTE(7), %rax
- **.data**, dove metto delle variabili globali.
	  .data
		  x : .long 7 (in C la dimensione viene indicata da int qui la devo specificare) 
		  v :   .long 1
			 .long 2
			 .long 3 (Questo è un vettore)
			OPPURE
		  v : .long 1,2,3
- **.fill** repeat, size, value: riservo memoria da repeat celle di dimensione size.
- **.comm** symbol, lenght : dichiara un0area di memoria con nome(symbol) di dimensione lenght nella sezione .bss.
- **.driver** ivn : identifica l'inizio della routine di servizio associato al codice ivn.

# Controllo di condizioni

![[Pasted image 20241119120938.png]]
Utilizziamo dei salti condizionali.
confronto x con 1, dove x è presente in al. cmpb è un compare fra 1 e il registro. Esegue la sottrazione fra il contenuto di al e 1.
Nel registro FLAGS abbiamo il bit ZF, che ci ritorna ZF = 1 se l'ultima operazione eseguita è uguale a 1.
jnz (jump not zero) quindi salto a .elseif se ho nello stack qualcosa diverso da 0.

Lo facciamo per ogni blocco.
In caso cmpb ritorna 0 allora facciamo l'execute del CODE BLOCK, a fine del CODE BLOCK A o B abbiamo un jump all'.endif


## Aggiornamento del Carry Flag

Per verificare se un numero è maggiore di un altro avrò bisogno di un altro modo per verificarla.
Quando eseguo a - b, richiedo un prestito quando b è maggiore di a.
Nel caso di sottrazione la CU rileva un prestito se l'addizione in complemente a 2 corrispondente determina riporto.
Se non c'è riporto non c'è prestito nella sottrazione, quindi a maggiore di b.

Quindi è il carry flag a darci condizione di maggiore o minore.
Nel caso di esecuzione di sub, il carry flag viene negato.

![[Pasted image 20241119122505.png]]

Questo vale per interi senza segno. *unsigned int*.

Per effettuare confronti fra numeri con segno, facciamo.
$$dest-src< 0(destinazione \ meno \ sorgente)$$
Il risultato viene salvato nella Sign Flag SF, dato che il bit più significativo se è 1, l'operazione ha riportato un segno negativo.
Ma se c'è stato overflow è cambiato il segno.
Il OF Overflow, viene salvato il risultato calcolato dalla ALU di un xor fra gli ultimi due riporti.
![[Pasted image 20241119123138.png]]ù

### ESEMPIO:

![[Pasted image 20241119123556.png]]

**NELLA CODIFICA DELLE ISTRUZIONI NON POSSO ESEGUIRE DUE OPERANDI IN MEMORIA, SOLO UNO.**


# Pseudo-Operazioni

Alcuni costrutti assembly sono complessi o ripetitivi, per questo abbiamo le *pseudo-operazioni* per semplificare il processo di sviluppo.

![[Pasted image 20241119124546.png]]

# Switch case

![[Pasted image 20241119124705.png]]

Possiamo utilizzare *tabelle di salto*, ovvero vettori in memoria che a ogni case associano un indirizzo. E' necessario considerare anche possibili buchi nei valori associati ai case.

![[Pasted image 20241119124811.png]]

Vedo se sono fuori dall'intervallo, in quel caso salto alla default.
Senno prendo la mia variabile, utilizzo l'indice del mio vettore e lo utilizzo per controllare l'indirizzo dei case, la mia var è una variabile a 32 bit, quindi la devo estendere a 64 per spostarla in %rax.

utilizzo movzlq, significa mov (copiamo la sorgente a una destinazione), z (zero extension, i bit significativi vengono riempiti con 0), l (indica che la sorgente è un valore a 32 bit)q(indica la destinazione è a 64 bit).

successivamente con shlq faccio lo shift a sinistra di 3 posti, ovvero moltiplico per 8. per esempio se %rax conteva il valore 0x0000000000000001, adesso cntiene il valore 0x0000000000000008.

moveq branchTable(%rax), %rax carica il valore a 64bit dall'indirizzo branchTable + rax a %rax.
La branchTable è una tabella di indirizzo a salti.

Per esempio per passare dall'elemento 0 all'leemento 1 nel vettore, devo andare avanti di 8 byte.
Per fare uno spiazzamento moltiplo per 8, ovvero di 3 posizioni.
shll $3, %rax.
branchTable(%rax),%rax, calcola branchTable + %rax e lo inserisco a %rax.


# Salti e chiamate di funzioni

In C è possibile utilizzare la funzione **goto** che serve a saltare ad una etichetta.
![[Pasted image 20241122113354.png]] 

# Cicli

Per fare un ciclo in assmebly utilizzo un cmp per verificare una condizione, se questa condizione è vera faccio un salto alla stessa funzione che stiamo chiamando in questo momento.
![[Pasted image 20241122113614.png]]
## While
In assembly per il while devo fare il controllo di condizione prima del jump e del codice. In caso la condizione è falsa faccio un jmp a un'altra funzione.

## Do While

Nel do while viene esecutato il codice almeno una volta, per questo il controllo di conidzione la mettiamo a seguito del codice.

## For

Per il for ho bisogno di più parti, un init statement, un test e una operazione post, eseguite al termine delle iterazioni. Perciò ho bisogno di definire prima della funzione il codice di inizializzazione delle variabili, per esempio un contatori e un numero di iterazioni da fare.
Poi dentro la nostra funzione come il while facciamo subito un compare, in seguito il codice, poi l'operazione per il contatore e infine il jmp all'inzio della funzione.
Nell'esempio sopra abbiamo:
```C
for(int i = 0; i<3; i++){
	//Code
}
```



# TIpi di dato

Ogni variabile in C ha un tipo, che possono essere raggrupati in 3 tipi:
- Tipi primitivi (interi, virgola mobile,...);
- Tipi aggregati (strutture,...);
- Puntatori;
**I tipi primitivi e puntatori sono gli unici tipi di variabili ad avere un corrispettivo in istruzioni assembly**.
I tipi aggregati vengono convertiti dal compilatore in accesso a tipi primitivi, quindi non sono altro che raggrupamenti di primitivi.

## Ambito delle variabili

Ogni variabile ha uno **scope** che determina la sua "visibilità" all'interno di determinate porzioni del programma:
- Variabili **Globali** : Occupano memoria nella sezione *.data* e *.bss* e sono visibili a tutte le funzioni;
- Variabili **Locali(o automatiche)** : Occupano memoria all'interno dello stack e sono visibili alla funzione stessa (o a funzioni chiamate se passate tramite puntatori).
  La variabile locale non può essere accessa finchè non viene chiamata la funzione, dato che è la funzione stessa a metterla in memoria.
  Se abbiamo una funzione **f()** e al suo interno chiama **g()**, se definisco una variabile i all'interno di **f**, essa non sarà visibili a **g**, nonostante essa sta all'interno della funzione **f** come lo è **i**.
  Per permettere a **g** di vedere la **i**, posso passare l'indirizzo di memoria di **i**.
  *Questo è dato che la finestra di stack è valida finchè la funzione non termina, e se ne eseguiamo un'altra, si apre un ulteriore finestra di stack sopra la prima senza chiuderla.*


# Finestra di stack
![[Pasted image 20241122120645.png]]

![[Pasted image 20241122120727.png]]


# Passaggio di parametri

Bisogna mettersi d'accordo su come si passano e si ritornano i parametri.
Le *calling conventions* definiscono, per ogni architettura e sistema, come è opportuno passare i parametri.
Le convenzioni principali permettono di passare parametri tramite:
- lo Stack
- I regsitri
- Un misto dei due
Generalmente il valore di ritorno viene passato in un registro dato che lo stack viene distrutto dopo la subroutine.
Se la subroutine chiamante vuole conservare il valore del registro, deve memorizzarlo nello stack prima di eseguire la chiamata dell'altra subroutine.

## Calling convention z64/x86

**I primi sei parametri (interi e indirizzi) di una subroutine** vengono passati tramite registri:
- RDI, RSI, RDX, R8, 9;
Se abbiamo più di sei parametri si utilizza lo *stack*.

**Si utilizzano due registri di ritorno (possiamo avere solo 1 valore di ritorno, ma possiamo ritornare un valore di 128 bit, dato dai bit di questi due registri):**
- RAX e RDX

I registri sono divisi in *callee save* e *caller save*:
- **calle-save** : RBP, RBX, R12-R15(Il valore salvato nel registro deve rimanere tale anche a fine della funzione);
- **caller-save**: tutti gli altri (La funzione chiamata deve mettere apposto prima del ritorno della funzione);

# Anatomia dello Stack

![[Pasted image 20241122124948.png]]

Prima di poter invocare f dobbiamo scrivere i nostri parametri all'interno dei registri general purpose.
L'ottavo e il settimo vengono messi nello stack dato che superano i 6 registri di call.
Poi retorna all'address precedente con il registry base pointer precedente. Infine viene fatto spazio per le variabili del codice.
Nella finestra di stack corrente incima abbiamo le variabili locali (valori negativi rispetto il base stack pointer), poi gli address precedenti e infine i parametri della funzione.


# Tipi Primitivi

In C : *char,int,float,double*, che possono essere modificati con *signed, unsigned, short, long*.
Ciò che ci dice quante bit è ogni variabile è l'architettura della CPU, l'ISA.
signed e unsigned dicono se devono essere utilizzate istruzioni aritmetiche particolari.
![[Pasted image 20241125141206.png]]

## Conversione tra tipi
 La conversione tra tipi interi viene realizzata mediante istruzioni *movsX (estensione con 0) e movzX (estensione con segno)*, oppure troncamente la parte più significativa.
```C
int integer = 10;
double real = (double)integer;
```

## Boolean

Per convenzione 0 è false e qualsiasi numero diverso da 0 è true.
```C
char booleano = 1;
if(booleano){
	printf("true\n");
}
```
Il controllo sui booleani viene fatto con **jz/jnz**.

## Array

Per accederlo viene utilizzata una *trasformazione lineare* dall'indice.
![[Pasted image 20241125141730.png]]
**manipolazione array**:
Si utilizza la base o lo spiazzamente per individuare l'inizio dell'array in memoria.
L'indice e la scala possono essere usati per calcolare l'indirizzo di un elemento ben preciso.
![[Pasted image 20241125142312.png]]
E' importante mettere il $ davanti dato che simboleggia l'indirizzo.

Oppure possiamo utilizzare:
![[Pasted image 20241125143014.png]]


In caso il vettore non è composta da tipi primitivi, non si può usare la scala, in questo caso si utilizza un registro per puntare all'area di memoria dell'elemneto successivo. Questo registro poi viene incrementato manualmente (puntatore).
![[Pasted image 20241125143249.png]]


## Stringhe

Rappresentate come array di caratteri, 1 byte per carattere ovvero *char*.
![[Pasted image 20241125143935.png]]
Ogni volta però che vengono usati i "", viene inserito automaticamente lo \o, questo significa che in realtà abbiamo sempre due bit in più a causa del terminatore di stringa.

## Matrici

Per raprresentare una matrice dobbiamo "linealizzarla".
Il comportamente dell'operatore [] è lo spiazzamento e avviene diversamente nelle matrici \[i]\[j] 
$$address \leftrightarrow i *N*size+j*size$$
Si estende lo stesso funzionamente per matrici n-dimensionali.
![[Pasted image 20241125144923.png]]

## Puntatori

Il puntatore contiene l'indirizzo di un'area di memoria che può contenere una variabile del tipo del puntatore, il puntatore è grande 8 byte.
$$int\ *intptr;$$
esiste anche un generico puntatore a memoria: *void* *


## Strutture

![[Pasted image 20241125151803.png]]

Per calcolare lo spiazzamento devo vedere quanto sono grandi tutti i dati all'interno di book. In modo da sapere le dimensioni di tutto ciò che vienee prima del valore che mi interessa.

![[Pasted image 20241125151948.png]]

### Passaggio di parametri di tipo struttura

In C quando si passa un parametro se ne fa una copia, qualcosa di molto inefficiente per le strutture.
Eì possibile utilizzare i puntatori per effetturare un *passaggio per riderimento ( o indirizzo )*.

![[Pasted image 20241125152341.png]]

![[Pasted image 20241125152455.png]]

## movs e stos

**movs : move data from string to string**
**stos : store string**

Istruzione per operare su stringhe, utilizzando registri impliciti:
- RCX : contatore del numero di operazione elementari da eseguire
- RSI : indirizzo sorgente
- RDI : indirizzo destinazione
- RAX : valore a cui impostare la memoria
Il direction flag (DF) identifica la direzione dell'operazione
- DF = 0 l'opreazione di copia si svolge in avanti
- DF = 1; si svolge all'indietro

![[Pasted image 20241126114144.png]]

## Sorgente e destinazione sovrapposte

Se sorgente e destinazione sono sovrapposte, una copia in avanti può portare a un risultato errato.
![[Pasted image 20241126114727.png]]

Per fare la copia all'indietro, RSI e RDI puntano alla fine dei buffer coinvolti, *std* configura il processo per fare la copia all'indietro.

### Equivalenti in C

![[Pasted image 20241126115023.png]]


## Tipi di Unione

Un'unione è un valore che può assumere diverse rappresentazione all'interno della stessa posizione di memoria. Un blocco di memoria utilizzate per conservare, una per volta, variabili di tipo differente.

![[Pasted image 20241126115525.png]]

Lo spazio di memoria è grande quando il più grande dato della union.
Quindi posso scrivere valori con una determinata codifica per poi leggerli in modo diverso. Manipolando gli stessi bit per ottenere risutlati diversi.

![[Pasted image 20241126115703.png]]

# Campi di bit

Si possono modificare singoli *flag* all'interno di un tipo primitivo
- registri di controllo
- *bitmap*, che raggruppa insieme più variabili booleane singole

## IEE 754

![[Pasted image 20241126120615.png]]

La mia union della iee754 sarà grande 4 byte come il suo più grande valore.
In questa union posso scriverci o un float, oppure una struct. Nella struct posso accedere a 1 bit, oppure a 8 bit, oppure a 23 bit, precisamente come la scrittura in virgola mobile IEEE 754.


## Maschere di bit

### Forzatura

Per forzare dei bit a valori specifici si usano maschere di bit.

![[Pasted image 20241126121323.png]]


### Estrazione

Supponiamo di avere 32 bit e volerne estrarre i 3 bit meno significativi.

![[Pasted image 20241126121444.png]]

La prima istruzione calcola l'AND fra 10 (2 binario) e rax.
Questo ci aiuta a verificare specifici bit come 0 o 1 per fare anche controlli di jmp.

La seconda istruzione verifica se una variabile vale 0 o meno.
# Puntatori a funzione

Il puntatore a funzione punta a sezione differenti della sezione .text per chiamare sezioni all'interno del nostro programma.

Permette di selezionare dinamicamente la funzione da attivare.

![[Pasted image 20241126122345.png]]

quando scrivo operazione = somma, sto puntando il puntatore a funzione alla funzione somma, quindi quando la chiamo insieme a delle variabili chiamo la funzione somma. Stesso vale per operazione = sottrazione.

## Assembly 

![[Pasted image 20241126122851.png]]

Memorizzo l'indirizzo della prima istruzione della mia funzione.