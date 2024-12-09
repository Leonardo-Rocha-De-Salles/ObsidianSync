
# Esercuzione di un programma

Il nostro programma viene mantenuto in memoria come codice macchina e il registro RIP punta alla prossima istruzione da esegueire.

Se non viene eseguita alcuna istruzione di controllo del flusso del programma, esso continua in maniera lineare puntando da un'istruzione all'altra.

Un programma è molto complesso, esiste uno **stato di programma** che viene mantenuto dai registri della CPU e memoria, che permettono di mantenere e modificare lo stato di programma.

## Esempi con C

Il main in C è l'entry point del nostro programma, l'instruction Pointer punterà alle operazione del main come inizio.
Poi utiliziamo chiamate esplicite nel programma per eseguire funzioni al dì fuori del main. Quest'operazione avviene tramite il **call** di una funzione.
Quando abbiamo il **return** termina la funzione, se il return si trova nel main, termina il programma.


Il **program counter** (PC) punta alla prossima istruzione da eseguire, e l'Instruction Register porta dentro di sè l'istruzione (Notare che il **program counter è la stessa cosa del instruction pointer register**). Poi il Program counter punta all'indirizzo della prossima istruzione ancora.

Per ritornare al main al termine di una funzione, ci serve salvare un indirizzo della prossima istruzione nel main, utilizzo lo stack di programma per memorizzare gli indirizzi di memoria di ritorno.
Quindi appena eseguo una funzione nel main, scrivo nello stack l'indirizzo dell'istruzione successiva di main, in modo da memorizzare il punto di ritorno.

Se ho una variabile nel mio stack ho bisogno di copiarlo su un Registro general purpose prima di toglierlo dallo stack.

![[Pasted image 20241115150157.png]]

In questo esempio il nostro nostro instruction pointer iniziare a puntare all prima riga del main, di conseguenza il nostro instruction register prende dentro di se l'informazioni in quell'indirizzo di memoria.
Instruction Register legge di dover andare in un'altra parte del codice in .text, ovvero deve spostare il PC all'istruzione della funzione bar(). Per fare questo prima, mettiamo in stack con il push l'attuale posizione del PC, in modo che una volta finita l'esecuzione di bar(), sappiamo a che punto ritornare nel main.
Una volta che puntiamo a bar(), viene chiamata l'operazione foo(), quindi nuovamente nello stack salviamo dove stavamo puntando in bar, e andiamo in foo().
foo() esegue l'operazione y = x\*x, essa viene messa nell'instruction register, svolta, e poi messa nello stack come dato di soluzione.
Quando faccio return y, il valore y viene salvato dallo stack al registro RAX. Quindi togliendo dallo stack la y.
Poi abbiamo subito dopo il successivo RET che ci dice dove puntare successivamente, ovvero ritorniamo in bar(). dove x = valore precedente ovvero RAX.
Il return ci dice nuovamente di prendere il valore del PC precedente ancora ovveri ritorniamo nel main.
Dobbiamo notare come RAX mantiene il valore 4 fino a quando non abbiamo un'altra assegnazione.

**Notare come ogni funzione crea un nuovo stack, e alla fine di questo stack si ha sempre il RET che ci dice di ritornare al passo precedente, ANCHE se non è presente il return".
# Processamento Istruzioni

**L'Unità di Controllo** governa il funzionamente di tutto il sistema e permette l'esecuzione di programmi, interazione fra software e hardware.
Il processamento di istruzioni prevede tre fasi:
- **fetch**: prelievo delle istruzioni dalla memoria
- **decodifica**: l'isturzione viene interpretata
- **esercuzione**: l'istruzione viene implementata
L'unità di controllo viene progettata coeremente con il *datapath* della CPU, Modello *uniciclo o multiciclo*


## Modelli di Esecuzione

### Modello Unicliclo

Un'istruzione viene eseguito in un solo colpo di clock, che è tarato in modo che la rete sia stabile.
Visto che tutto viene eseguito in un clock cicle, ho bisogno che ogni operazione da svolgerebe abbia un suo componente personale, quindi la condivisione di componenti non è possibile.
Per esempio se devo eseguire due somme differenti, ho bisogno di due ALU.

### Modello multiciclo

Le istruzione vengono eseguite in più colpi di clock. Le componeneti possono essere riutilizzate fra un ciclo e un altro di clock.
Il datapath che abbiamo scelto per lo z64 segue questo modello multiciclico, per questo la nostra Control Unit deve rispettare le regole.


# Modello Multiclo

Il modello multiciclo utilizza più cicli per svolgere un lavoro, ciascun perdiodo di ciclo implementa qualcosa di diverso:
- Ciclo istruzione : intervallo per eseguire un'istruzione nella sua interezza
- Ciclo macchina : intervallo necessario a eseguire una fase (fetch, decode, execute)
- Stato macchina : tempo per stabilizzare la rete dell'unità di controllo e calcolo
![[Pasted image 20241114182007.png]]

La control unit implemente un'istruzione con un insieme di *microoperazioni*, definite dai segnali di controllo abilitata dallo stato della macchina. Ogni stato corrisponde a un aggiornamento a una macchina di stato che implemente le microoperazioni.

![[Pasted image 20241114182216.png]]
Per eseguire il microprogramma di un'istruzione, la CU userà come input:
- la classe e tipo di istruzione - contenuta nell'instruction register
- Le variabili che arrivano aldi fuori della CPU, come dispositivi I/O
- Variabili interne alla CPU come i FLAGS
- Modalità di indirizzamento degli operandi derivato dall'instruction register

# La CU come macchina di Mealy

Devo sempre tenere conto a quale punto del microprogramma sono arrivato, quindi abbia bisogno di un program counter per tener conto della micro-operazione a cui sono arrivato.
La nostra ROM Funziona come memoria a cui possiam associare tutte le nostre micro-operazioni.
A ogni colpo di clock passo da microoperazione a un'altra.
La macchina a stati stessa aggiorna lo stato successivo del micro-programma.

Le micro-operazioni della ROM vengono selezionata a seconda dell'Opcode che abbiamo nel nostr instruction register.

Quando vado a costruire una ROM, possiamo costruirla paginata, suddividendo lo spazio in pagine differenti, questo è utile per decidere di avere pagine di tutte la stessa dimensione; in modo da contenere una micro-operazioni ogni pagina.

E' intuitivo dire che non tutti i micro-programmi hanno la stessa dimensione. Quindi la dimensione di tutte le pagine per essere uguali, devono essere grandi quanto il più lungo micro-progamma.

![[Pasted image 20241115114721.png]]

Gli indirizzi in input della ROM posso dividerli in due parti:
- Primi 3 bit li associo a quale delle 8 pagine sto scegliende
- I restanti 3 bit servono a identificare lo spiazzamento.



![[Pasted image 20241115114738.png]]

Questo permette in una decodifica delle istruzioni molto efficiente.

Per ridurre le variabili di conidizione della ROM posso introdurre un circuito combinatorio di selezione per fare in modo che riassumo esternamente le variabili di conidzione di alcuni micro-programmi.


# Come funziona un programma

## Fase di Fetch

Le micro-operazioni associate alla fase di fetch sono:
- MAR <- RIP (copio il contenuto del Instruction Pointer Register nel Memory Address Register)
- MDR <- (MAR); RIP <- RIP + 8 (Salvo nel Memory Data Register quello in MAR, mentre l'Instruction Pointer lo incremento di 8, per dire che la prossima instruzione è in quell'indirizzo)
- IR <- MDR (In MDR abbiamo la prossima instruzione da eseguire che quindi poi salvo nell'Instruction Register)

![[Pasted image 20241115155907.png]]
![[Pasted image 20241115155939.png]]![[Pasted image 20241115160020.png]]
![[Pasted image 20241115160040.png]]
![[Pasted image 20241115160047.png]]

Tipicamente le istruzioni di moviemnto dati che accedono memoria richiedono più cicli di una macchina.

Quindi il MAR contiene l'indirizzo di memoria da essere letto o scritto, il quale gli viene fornito dal program counter, per poi mandarli in MDR per essere letti o scritti.

## Esempio istruzione assembly con le micro-operazioni

#### 1

$$movq \ \%rax,\%rcx;$$
Prima di tutto copiamo il nostro indirizzo di memoria dove è presente l'istruzione
$$MAR \leftarrow RIP$$
Adesso copiamo i contenuti di quell'indirizzo d imemoria nel memory data register e mandiamo avanti il RIP.
$$MDR \leftarrow (MAR); RIP \leftarrow RIP+8$$
Adesso mandiamo nell'instruction register i dati all'interno dell'indirizzo MDR, infatti se vediamo stiamo indicando (MAR), questo significa che stiamo usando i dati all'interno di quell'indirizzo e non l'indirizzo a cui puntava l'instruction pointer.
$$IR \leftarrow MDR$$
Adesso che sappiamo di dover salvare i dati di un registro in un altro lo facciamo:
$$TEMP2 \leftarrow RAX$$
Salviamo temporaneamente il valore di RAX nel nostro registro TEMP2.
$$RCX \leftarrow TEMP2$$
Salviamo i contenuti di TEMP2 in RCX.
![[Pasted image 20241115161508.png]]
![[Pasted image 20241115161515.png]]

#### 2)

![[Pasted image 20241115173326.png]]

Dobbiamo svolgere il calcolo del memori address dove abbiamo
$$0xaaaa(\%rax,\%rcx,8)$$
dove 0xaaaa è lo spiazzamento, salvato nell'instruction register in posizione 0:31 bit, \%rax la base,  %rcx indice, 8 scala.
Quindi l'operazione 0xaaaa + %rax + %rcx\*8
i passaggi sono i seguenti:
- il memory address dell'istruzione viene comunicato al MAR
- i dati di quel memory adress vengono comunicati al MDR e il RIP passa alla prossima istruzione
- L'instruction register riceve le informazioni
- in TEMP2 salviamo RCX
- in TEMP1 salviamo il risultato del shift a sinistra di 3 posizioni, notare che TEMP2 è collegato al shifter quindi stiamo moltiplicando per 8 RCX. Ottenendo %rcx\*8
- Mettiamo in TEMP2 RAX
- Sommiamo i due e salviamo la somma di TEMP1 e TEMP2 in MAR. Ottenendo %rax + %rcx\*8.
- Adesso prendiamo lo spiazzamento in IR\[0:31\] e lo mettiamo in TEMP1
- Riprendiamo la somma precedente salvata in MAR e la mettiamo in TEMP2
- Sommiamo i due salvando il contenuto in MAR, ottenendo 0xaaaa + %rax + %rcx\*8.
- adesso salviamo il risultato di RAX in MDR
- Copiamo il risultato da MDR nel memory address (MAR), notare che le parentesi indicano che 0xaaaa + %rax + %rcx\*8 è un memory address, quindi mettendo le parentesi salviamo un dato in quel memory address.


## Fase fetch con immediati "grandi"

Il microprogramma di fetch legge dalla memoria 64bit alla volta, nel caso di immediati grandi, la costante si trova nei 64 bit successivi quindi è necessario un secondo accesso di memoria.
![[Pasted image 20241115174408.png]]
Quindi come vediamo salviamo come sempre l'istruzione, ma questa volte rifacciamo l'operazione con l'instruction pointer che punta 8 byte successivi, salvando però il valore di MDR non nell'instruction register ma in RAX.



![[Pasted image 20241115174704.png]]



## Istruzione di salto condizionale

Se vengono verificate delle conidzioni viene aggiornato l'instruction register e si sposta, senno rimane invariato.
![[Pasted image 20241115174814.png]]