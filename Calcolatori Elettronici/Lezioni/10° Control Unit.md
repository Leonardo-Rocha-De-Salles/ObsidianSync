cover airpods
# Esercuzione di un programma

Il nostro programma viene mantenuto in memoria come codice macchina e il registro RIP punta alla prossima istruzione da esegueire.

Un programma è molto complesso, esiste uno **stato di programma** che viene mantenuto dai registri della CPU e memoria, che permettono di mantenere e modificare lo stato di programma.

## Esempi con C

Il main in C è l'entry point del nostro programma, l'instruction Pointer punterà alle operazione del main come inizio.
Poi utiliziamo chiamate esplicite nel programma per eseguire funzioni al dì fuori del main. Quest'operazione avviene tramite il **call** di una funzione.
Quando abbiamo il **return** termina la funzione, se il return si trova nel main, termina il programma.

Il **program counter** (PC) punta alla prossima istruzione da eseguire, e l'Instruction Register porta dentro di sè l'istruzione. Poi il Program counter punta all'indirizzo della prossima istruzione ancora.

Per ritornare al main al termine di una funzione, ci serve salvare un indirizzo della prossima istruzione nel main, utilizzo lo stack di programma per memorizzare gli indirizzi di memoria di ritorno.
Quindi appena eseguo una funzione nel main, scrivo nello stack l'indirizzo dell'istruzione successiva di main, in modo da memorizzare il punto di ritorno.

Se ho una variabile nel mio stack ho bisogno di copiarlo su un Registro general purpose prima di toglierlo dallo stack.


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

Devo sempre tenere conto a quale punto del microprogramma sono arrivato, quindi abbia bisogno di un program counter per tener conto della micro operazione a cui sono arrivato.
La nostra ROM Funziona come memoria a cui possiam associare tutte le nostre microoperazioni.
A ogni colpo di clock passo da microoperazione a un'altra.
La macchina a stati stessa aggiorna lo stato successivo del micro-programma.

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