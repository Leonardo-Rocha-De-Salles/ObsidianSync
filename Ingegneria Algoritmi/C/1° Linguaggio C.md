# Introduzione

Vediamo delle righe di codice introduttive


```
#include <stdio.h>

int main(){
	printf("Hello World!");
	return 0;
}
```

Questo è un programma base dove però abbiamo degli elementi essenziali:
********
Qualsiasi stringa che utilizza # il cancelleto è un messaggio per il pre-processore. 

**<stdio.h>** sta per "standard input-output header", è l'header file della libreria standard del C, contiene definizioni, costanti e funzioni (come printf()), operazioni input e output. Comprare in quasi tutti i programmi.

**main()** è la funzione principale di un programma C, il punto di entratata dove il programma inizia a eseguire il codice. Ogni programma in C deve avere una funzione main().
Se la funzione main non ritorna niente in output possiamo scrivere.
```
void main()
{
	//Function
}
```
Possiamo mettere *void* anche in caso la funzione non prenda argomenti.

**return 0** la funzione ritorna il valore 0 se l'esecuzione va a bene, in caso va a male essa ritorna 1. Una funzione del genere potrebbe essere anche void dato che il ritorno sta solo a verificare il buon fine dell'esecuzione.

**Davanti ad ogni funzione va messo il tipo di variabile in output.**


# Object File

Un Object file è il source code compilato da gcc, un executable file è formato linkando Object files, gli object files sono scritti in machine code, leggibili dalla CPU.
## Linker
Il linker è ciò che prende insieme tutti gli object file e li *linka*, permettendo un executable. Per se il mio programma è diviso in più file con funzioni che interagiscono fra di loro ma in file diversi. Posso utilizzare un linker dei object file per (se non sono già linkati con l'utilizzo di -c) per mettere in correlazione tutto.
# printf()

Print Formatted

Per fare il print di un messaggio di testo dobbiamo utilizzare la funzione printf() e una stringa. Adesso vediamo modi in cui si possono formattare questo messaggio.
```
#include <stdio.h>  
  
int main() {  
  printf("Hello World!**\n**");  
  printf("I am learning C.");  
  return 0;  
}

/*Questo è un commento*/

```
**\\n** va alla riga successiva
**\\t** crea uno spazio tab orizzontale
**\\\\** mette un backslash
**\\"** mette le "

## Inserire variabili in printf()

printf() è una funzione definita come:
```
int printf(const char * restrict format, ...);
```
Per printf è necessario sapere qual'è il format della variabile che stai mettendo in display, per esempio:
```
	printf("%d", numero);
```
*%d* sta a simboleggiare il format *integer*, quindi la nostra variabile *numero* precedentemente definita, può essere messa in print senza alcun problema.

Devo considerare il mio %format come se fosse la stringa che sto inserendo.



## Concatenazione di stringhe e variabili

```
int a = 10;
float b = 5.25;
char c = 'A';

printf("Integer: %d, Float: %.2f, Char: %c\n", a, b, c);

```

Output:
Integer: 10, Float: 5.25, Char: A

![[Pasted image 20240926214218.png]]

## Scegliere numero di cifre decimali


```
float myFloatNum = 3.5;  
  
printf("%f\n", myFloatNum);   // Default will show 6 digits after the decimal point  
printf("%.1f\n", myFloatNum); // Only show 1 digit  
printf("%.2f\n", myFloatNum); // Only show 2 digits  
printf("%.4f", myFloatNum);   // Only show 4 digits
```

# Dichiarazione di variabili e DataTypes
Su C c'è il bisogno di inserire il tipo di dato davanti la variabilie
## Principali data types
- int (4byte) %d
- float (virgola mobile 4 byte) %f
- double (8 byte) %lf
- char (singolo carattere, 1 byte)
- array(variabile, si calcola numero di elementi\**bytes di un elemento*)
- struct (Raggruppamento di diversi tipi, serve a implimentare algoritmi di ordinamento.)
- bool (1 byte)

Per conoscere quanti bit ha una funzione usiamo:
```
int myInt;  
float myFloat;  
double myDouble;  
char myChar;  
  
printf("%lu\n", sizeof(myInt));  
printf("%lu\n", sizeof(myFloat));  
printf("%lu\n", sizeof(myDouble));  
printf("%lu\n", sizeof(myChar));
```


## Dichiarazione e Inizializzazione di Variabili

Creare e assegnare numeri.
### Esempi di Dichiarazione:

- int numero;
- float prezzo;
- bool isActive

### Esempi di Inizializzazione


- int numero = 10
- float prezzo = 10,3
- bool isActive = True




# Variabile char

Questo variabile sta a rappresentare un singolo simbolo se rappresentata con le virgolette ""
Se invece facciamo conto di associarla a una cifra intera come facciamo gli interi, stiamo rappresentando la variabile come un simbolo dell'alfabeto **ASCII**.



# scanf()

A differenza di printf() che mostra degli output, scanf() riceve degli *user input*.
```
// Create an integer variable that will store the number we get from the user  
int myNum;  
  
// Ask the user to type a number  
printf("Type a number: \n");  
  
// Get and save the number the user types  
**scanf**("%d", &myNum);  
  
// Output the number the user typed  
printf("Your number is: %d", myNum);
```

Anche scanf() ha bisogna del format specifier, e prende anche il reference operator *&myNum*, il quale salva il *memory address* della variabile.

## Input Multipli

Per gli input multipli mettiamo due format operator vicini e l'utente dovrà inserire i sue due input con uno spazio in mezzo.


## String input

Per uno string input utilizziamo la variabile char variablename[size], dove size è l'array che conterrà tutti i caratteri del nostro input. In questo caso il format operator è %s, ma a differenza degli altri *non bisogna mettere il reference operator &*



# Memory Address

Quando una variabile è creata in C, ad essa viene associato un **memory adress**, che sarebbe il luogo dove la variabile è salvato nel computer. Quando associamo un valore a una variabile, salviamo questo valore nel memory address. Per accede al memory access usiamo il reference operator **&**.


# Pointer

Un pointer è una **variabile che salva il memory address** di un'altra variabile come suo valore


# /#define MACRO
Le macro sono identificatori che sono scambiati con il loro valore prima della compilazione. Si utilizzano quando vogliamo utilizzare un singolo dato molte volte.

# include altra funzione
Se faccio #include "file.h" posso utilizzare tutte le funzioni all'interno del file.h Per fare ciò dobbiamo creare un file "header" per poter poi richiamarlo in un'altra file di testo C.
Per fare un link fra object files dobbiamo fare *gcc -o mainfile link1.o link2.o*

# Namespace

Ogni variabile ha uno scope:
- Globale (Visibile da tutte le funzioni)
- Locale (Definita dentro una funzione)
- Statiche
Nel C89 devono essere dichiarate all'inizio di una funzione, in quelle successive no.
Pratiche comuni:
- Dichiarare le variabili importanti all'inizio della procedura
- Dichiarare le variabili locali e temporanee, in un blocco di codice che le usa (es. dentro un ciclo o if...)



# Tipi booleani
I valori logici vengono gestiti con gli interi, il valore 0 è false, qualunque valore che non sia 0 è true.


# Operatori
![[Pasted image 20241014105804.png]]

## And bit a bit
Se facessi l'& di due numeri binari, prendendo degli interi e ottenendo degli interi, l'opposto della somma.
l'operatore && sono operatori logici. Dove il vero è qualsiasi cosa diversa da 0.

## Operazioni di shift
Dato 2 << 1 = 4 perchè  10 è il binario, <<1 significa fare lo shift a sinistra di un bit, ovvero aggiungere uno 0 alla fine. 2<<1 = 100.
Invece lo shift a destra cancella l'ultimo bit ne aggiunge uno 0 all'inizio.
Ovvero sono uguali a moltiplicazione e divisione per 2.



# Array
[[2° Array]]