# Language Processor

Un language processor è un programma del computer che traduce del source code da un linguaggio da programmazione ad un altro.
I programmi sono solitamente scritti in linguaggi di alto livello come C, C++, Python. Per poi essere tradotti in qualche modo in linguaggio macchina.
Ma possono anche essere scritti in un linguaggio a basso livello come Assembly.

# Compilers
Quando parliamo di programmi come C, stiamo parlando di linguaggi compiler, ovvero tutti i programmi scritto in questo linguaggio devono essere compilati. Questo processo si basa sul prendere l'intero programma scritto in linguaggio di alto livello (**source code**)(il programma C) e tramite un compiler trasformarlo in linguaggio macchina binario (**object code**), il quale può essere processato dalla CPU. Il machine code viene salvato in un object file (executable)

Il compiler richiede molto tempo e memoria, può anche essere difficile trovare problemi col debugging dato che l'intero programma viene tradotto in linguaggio macchina per poi essere esecutato.

# Interpreter

L'interpreter prende ogni singola riga di codice, l otraduce in codice macchina per poi esecutare la riga appena tradotta. Così va avanti per tutto il programma.
Se si incontra un errore l'interpreter non va avanti. Esempio può essere python
# Assembler

Un programma che traduce codice scritto in assembly in linguaggio macchina.
