# Linguaggio C

Linguaggio di basso livello per sviluppare sistemi ad alta efficienza come sistemi operativi.

## Compilatore per Linux

GCC (GNU Compiler Collection)

## Estensione Linux
.elf


## Operatori

|| = Or
&& = and
sizeof() prende in input di una variabile ritornando la sua dimensione in byte.


# Controli di flusso
Condizioni
- if,else if, else: permette di eseguire blocchi a seconda se una condizione è vera o falsa
- switch: Permette di eseguire differenti blocchi di codice in base al valore di una variabile, utile per non ripetere if-else.

# Cicli
- for: usato per iterazioni con numero di ripetizioni noto. Comprende inizializzazione, condizione e incremento in un'unica funzione.
- while:
- do-while: Come il while ma percorre il codice all'interno del while una volta prima di controllare la condizione del while.


# Come compilare un file C
Per compilare il nostro codice C in un esecutabile facciamo il seguente comando nel terminale all'interno della cartella dove il file è salvato

$$\text{gcc filename.c -o filenameoutput}$$

-o viene utilizzata per specificare il nome del file di output.

Dopo aver fatto la compilazione viene generato l'eseguibile, per eseguirlo facciamo il seguente comando : 
$$\text{./filename}$$


# Makefile

Un Makefile è un file di testo utilizzato per automatizzare il processo di compilazione in proggetti di programmazione. Contiene una serie di regole che specificano come compilare e collegare i file sorgente per generare un eseguibile o altri obiettivi. Ogni regola include:
- Target
- Dipendenze
- Comandi




# man commando

Mi spiega tutto il ocmnaod, utile all'esame
















