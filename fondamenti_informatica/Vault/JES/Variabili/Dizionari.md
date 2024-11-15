# Sintassi: 
{key:value, key:value, ..., key:value}

key può appartenere a un qualunque dato immutabile, come string o un numero.
key diverse possono essere di tipo diverso

value può appartenere a qualunque dato di python

Le coppie key:value non sono ordinate

Dictionary è un oggetto mutabile, ogni suo elemento può essere modificato.

Creare un dizionario:

	myDict = {'bill':100, 'fred':50, 'sam':10}

La chiave è univoca nell'insieme.

Acesso: per accedere a un dizionario si usa la chiave (key), prendendo l'esempio di prima

	myDict['bill']
	>>100
	myDict['fred']
	>>50
	
# Operatori:
## Metodi:

### .keys
restituisce una lista contenente tutte le key in myDictionary

	myDictionary.keys() 
	keys: dictionary → list

### .values
restituisce una lista contenente tutte i value in myDictionary

	myDictionary.values() 
	values: dictionary → list
### .items
restituisce una lista contenente tutte le coppie (rappresentate come tuple) key:value in myDictionary
	myDictionary.items()
	items: dictionary → list
### .get
restituisce il valore associato alla key k (nome della key) in myDictionary, se k esiste in myDictionary, altrimenti restituisce None

	myDictionary.get(k)
	get: dictionary × key → T  {none}

restituisce il valore associato alla key k in myDictionary, se k esiste in myDictionary, altrimenti restituisce il valore di default d

	myDictionary.get(k, d)
	get: dictionary × key × default → T  {default}
### .pop

restituisce il valore v associato alla key k in myDictionary e rimuove la coppia k:v da myDictionary, se k esiste in myDictionary; altrimenti restituisce errore

	myDictionary.pop(k)
	pop: dictionary × key → T  {error}

restituisce il valore v associato alla key k in myDictionary e rimuove la coppia k:v da myDictionary, se k esiste in myDictionary; altrimenti restituisce il valore di default d

	myDictionary.pop(k, d)
	pop: dictionary × key × default → T  {default}
### .update

modifica myDictionary, aggiungendo le coppie presenti in otherDict, se sono presenti coppie con stessa key, viene tenuto il valore associato a key in otherDict

	myDictionary.update(otherDict)
	update: dictionary × dictionary → none
### len

numero di elementi nel dictionary.

	len:dictionary --> N


Esempi:

![[Pasted image 20240519212724.png]]


