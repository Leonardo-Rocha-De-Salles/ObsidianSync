Jes ha le seguenti funzioni per funzioni di testo:

addText (pict, x, y, text)
	inserisce il testo text nell'immagine a partire da x,y
addLine(pict, x1, x2, y1, y2)
	Traccia una linea nell'immagine, dalla posizione (x1,ya) alla (x2, y2)
addRect(pict, x1, x2, w, h)
	disegna un rettangolo nero vuoto nell'immagine con angolo superiore sinistroa a (x1, y1), larghezza w e altezza h
addRectFilled(pict, x1, x2, y1, y2)
	disegna un rettangolo riempito con il colore color nell’immagine pict, con l’angolo superiore sinistro in posizione (x1,y1) e con larghezza w e altezza h

![[Pasted image 20240518181317.png]]
Il rettangolo è vector-based: codice che general pixel

Se voglio modificare un immagine vector based, devo modificare il programma che la genera.

![[Pasted image 20240518181644.png]]