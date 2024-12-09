L'incremento delle prestazioni di una CPU aumenta del 60% ogni anno nel mercato, mentre le periferiche esterne solo del 10%.
Questo significa che un programma è diviso un due parti, una parte $f$ che è il tempo di processamento da parte della CPU e una parte 1 - $f$ passata in interazioni con dispositivi esterni.

![[Pasted image 20241206113827.png]]


# Legge di Amdahl

![[Pasted image 20241206113842.png]]
![[Pasted image 20241206113922.png]]

Dobbiamo impedire i casi dove il dispositivo più veloce sovvrascriva le operazioni del dispositivo più lento.
Per impedirlo abbiamo bisogno di un **Protocollo di Handshaking** : 
Abbiamo la necessità di far sincronizzare momentaneamente due dispositivi per farsì che i dati di entrambi i dispositivi sono stabili per le reti combinatorie.

Il processore *non può rallentare per aspettare dispositivi*, nè possiamo avere che il dispositivo vada più veloce.

Perciò dobbiamo **Simulare** un rallentamento del processore, utilizzando registri tamponi e segnali di controllo (flip-flop tampone) per sincronizzare trasferimento di dati corretti.
Il modo migliore per implementare il protocollo di handshaking sono le macchine a stato.

![[Pasted image 20241206114638.png]]

Qui abbiamo due dispotivi, quello di sinistra che trasmette e quello di destra che riceve.

Il *trasmittende invia un segnale di controllo* che un dato è pronto a essere ricevuto, utilizzando un *flipflop* FF1. Una volta che che il *ricevente è pronto* a ricevere il dato, *aggiornerà il suo flip-flop* che indicherà che il il dato può essere trasmesso *dal registro del trasmittende al suo*.

Appena il dato è stato ricevuto, *il ricevente aggiorna un suo altro flip-flop*, per dare l'informazione al trasmittende che, quando è pronto, *può iniziare ad elaborare un altro dato da trasmettere*.

Se tolgo la Wait ACK1 dal trasmittente, esso potrebbe sovvrascrivere il dato prima che sia stato letto.
Se tolgo la Wait ACK2 il trasmittente potrebbe sovvrascrivere il dato durante la lettua.
Se tolgo Wait RDY1 dal ricevente potrei leggere prima la scrittura sia avvenuta.
Se tolgo Wait RDY1 (il secondo nel ciclo) potrei leggere lo stesso valore due volte.

# I/O microprogrammato

## Un solo dispotivo : input

![[Pasted image 20241206120028.png]]

Abbiamo un registro nel device per bufferizzare le informazioni, nel z64 abbiamo un registro per leggere e acquisire un dato da un dispositivo esterno.
Visto che non sappiamo se il trasmittente o il ricevente è più veloce, utilizziamo un flip-flop SR per entrambi i dispositivi (SR Dato che i segnali di clock sono diversi).

Il processore farà una richiesta di lettura, Q negato andrà a 1, e il processore riceverà il segnale che può produrre un altro dato.
Allo stesso tempo  finchè il valore WAIT è 1, non succede niente, quando va a 0, abiliterà la scrittura.

## Output

![[Pasted image 20241206120744.png]]


# Connesioni CPU-dispositivi

Questo ci permette di avere più dispositivi I/O, possiamo riciclare i BUS della CPU.
![[Pasted image 20241206121243.png]]

Questi sono tutti moduli di memoria collegati ai BUS. Questi dati possono essere trasferiti tramite istruzioni *mov*.
**Memory Mapped I/O**
Però questo significa che dobbiamo partizionare degli spazi di memoria per avere alcuni indirizzi per celle di memoria, altri associati a dispositivi.

![[Pasted image 20241206121842.png]]

Avremmo dei BUS di memoria distinti per le I/O con spazi di indirizzamento separati, con anche *istruzioni e regstri dedicati*.

Ci saranno delle istruzioni assembly specifiche per utilizzare certi bus rispetto ad altri.

![[Pasted image 20241206121939.png]]

![[Pasted image 20241206122640.png]]
# I/O Programmato
![[Pasted image 20241206124137.png]]

Il software guido lo scambio dei dati tra periferiche e CPU con due principali modalità:
- **Busy waiting**
- **Polling** ![[Pasted image 20241207152457.png]]
Abbiamo anche un massimo di $2^{16}$ porte di I/O

## Busy Waiting
- Il processore avvisa il dispositivo che vuole fare un trasferimento
- Si verifica il flip-flop STATUS è a 1
- Se è a 0, il trasferimento non è completato, e ritorna al secondo step.

I dispositivi non possono utilizzare il bus se non interrogati esplicitamente dalla CPU, non è necessario il segnale WAIT negato.

Questa modalità ha sempre il problema fondamnetale che il processore non può eseguire alcuna altra attività finchè non si completa il trasferimento.
![[Pasted image 20241207152811.png]]

Per esempio visto in assembly, il processore esegue lo stesso codice finchè il trasferimento non è completato.

Una possibile soluzione è interrogare altre periferiche e servire la prima disponibile.

![[Pasted image 20241207152955.png]]


## Polling

Verifica circolare per trovare la prima periferica pronta ad interagire.

![[Pasted image 20241207153051.png]]
