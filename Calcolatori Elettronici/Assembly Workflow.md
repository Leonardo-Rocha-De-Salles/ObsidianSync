
Inanzitutto per inizializzare il nostro programma assembly dobbiamo creare il file in cui andrà tutto il nostro codice.

Questo file afrà come suffisso .s (pure assembly, non vengono preprocessati) oppure .S, dipendendo se il nostro codice utilizzi o meno librerie esterne.

Adesso una volta creato il nostro file dobbiamo definire la funzione main nel seguente modo

```
.global main

main:
	#code
```


Adesso per assemblare il nostro programma possiamo utilizzare anche gcc, ma io preferisco il GNU assembler.
scriviamo nel terminale

$$as \ -o \ \ output.o \ \ \ file.s$$
Infine dobbiamo linkare il file

$$ld \ \ -o \ \ executable \ \ output.o$$

In caso il programma non riconosca l'entry point main dobbiamo utilizzare durante la fase di linking anche l'opzione **-e functionanme**

Infine apriamo il programma su gdb per vedere le sue funzionalità. Quindi
	gdb ./a.out
	lay next
premiamo enter finchè non ci soddisfa la schermata
	break main (o qualsiasi funzione vogliamo vedere)
	step (per vedere gli step)

# Stack in una funzione

Ogni volta che accediamo a una funzione dobbiamo anche espandere il suo stack. Per fare ciò si utilizzano due righe di codice.

	pushq %rbp
	movq %rsp, %rbp

Specifichiamo cosa sono questi registri e cosa fanno

# RSP(Register Stack Pointer)

Ha sempre come valore l'indirizzo della cima dello stack, questo significa che quando qualcosa viene inserito all'interno dello stack, l'rsp si muove verso l'ultimo byte di questo nuovo dato inserito. Se invece viene tolto va a quello precedente.

Perciò quando inseriamo un elemento l'rsp si decrementa di tot byte, mentre se togliamo dallo stack esso va verso l'alto e quindi accresce. **Questo perchè lo stack cresce verso il basso**.

**Perchè è importante**
- Rende il push di un dato nello stack molto efficiente, dato che quando faccio push, rsp viene decrementato e il nuovo valore dello stack inserito nell'indirizzo puntato da rsp.
- Rende il pop anche più efficiente per lo stesso motivo
- Quando una funzione viene chiamata, l'indirizzo di ritorno viene pushato nello stack, successivamente rsp viene usato per inserire la nuova base dello stack chiamato rbp.
- Quando una funzione finisce rsp viene usato per repristinare il base pointer della funzione iniziale chiamante.

