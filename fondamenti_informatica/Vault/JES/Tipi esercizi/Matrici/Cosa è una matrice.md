Algoritmo che permette di ripetere un'azione
![[Pasted image 20240518150724.png]]

Qui abbiamo il caso di come iterare la riga di una matrice

	for i in range(0, len(allPix)):
		originalRed = getRed(allPix[i])
		newRed = originalRed*0.5
		setRed(allPix[i], newRed)

il range è una funzione che prende numeri interi.
Vediamo la funzione range come funziona
- range : N --> sequence_of_int
	- range(k) genera la sequenza (0, 1,..., k-1)
		- Default: start = 0, step = 1


-  range: Z x Z --> senquence_of_int
	-  range(h, k) genera la sequenza (h, h+1, ..., k-1)
		- Default: step = 1 

- range: Z x Z x Z --> sequence_of_int
	- range(h, k, p) genera la sequenza (h, h+p, ..., h+jp)
		- dove j è il massimo intero tale che:
			- h+jp < k, se p>0
			- h+jp > k, se p<0


Se dobbiamo iterare una matrice dobbiamo fare nel seguente modo:

	def func():
	# @param pict: Picture
	for x in range(0, getWidth(pict)):
		for y in range(0, getHeight(pict)):
			px = getPixel(pict, x ,y)
			...
	return

In questo modo fissiamo un valore x, per poi iterare tutti i valori y, ovvero: (0,0), (0,1), (0,2)...


Ci sono casi in cui abbiamo matrici a specchio:
![[Pasted image 20240518154816.png]]
Esempio:

	def mirror_vlr(p): 
	#@param p: Pixel 
	#@return: None 
		w = getWidth(p) 
		for y in range(getHeight(p)): 
			for x in range(w/2): 
				lp = getPixel(p, x, y) 
				rp = getPixel(p,getWidth(p)-x-1,y) 
				setColor(rp, getColor(lp))