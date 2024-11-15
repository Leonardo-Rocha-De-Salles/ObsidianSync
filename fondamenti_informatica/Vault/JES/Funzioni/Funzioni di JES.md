# PickAFile:

Apre finestra per scegliere la directory di un file, ritornando il nome completo, quindi location, di tale file. Lo possiamo utilizzare per trovare string di file.

	pickAFile()
		pickAfile: none --> string

# makePicture:

Crea un oggetto di tipo picture con una stringa che corriponde a una file directory.

	makePicture(fileDir)
		makePicture: string --> picture

# Show:

Usiamo show per visualizzare un oggetto picture.

	show(picture)
		show:picture-->none


# makeSound:

Crea oggetto sound tramite fileDir

	makeSound()
		makeSound --> sound


# play:

Fa parte l'oggetto sound

	play()
		play:sound --> none



# showParam, playParam:

Qunado utilizziamo show e play dobbiamo mettere rispettivamente un oggetto picture o sound, però con le seguenti funzioni possiamo direttamente inserire la fileDir dei file interessati

	showParam(fileDir)
	playParam(fileDir)
		showParam: string --> none
		playParam: string --> none
----------------------------------------------
# pickAColor:

Ci fa scegliere un oggetto colore.

	pickAColor()
	pickAColor:None --> Color


# repaint:

Aggiorna l'immagine modificata

	repaint()

# getPixel:

Restituisce il pixel dell'immagine Picture, nel punt x,y

	getPixel(picture, x, y)
	getPixel: Picture x X x Y --> Pixel

# getPixels:

Restituisce la lista di tutti i pixel dell'immagine.

	getPixels(picture)
	getPixels: Picture --> List of Pixels
	
# getWidth:

Ritorna la larghezza dell'immagine

	getWidth(picture): Picture --> N
# getHeight:

Ritorna l'altezza dell'immagine

	getHeight(picture): Picture --> N

# writePictureTo:

Salva l'immagine in una file directory, bisogna anche assorci un nome e finire l'estensione con ==.jpg==

	writePictureTo(picture, fileDir): Picture x str --> none


# Funzioni Per i colori:

N sta per numero intero da 0 a 255

	getRed(pixel): Pixel --> N
	getGreen(pixel): Pixel --> N
	getBlue(pixel): Pixel --> N

Queste funzioni prendono valori di x da 0 a 255

	setRed(pixel, x): Pixel x R --> none
	setGreen(pixel, x): Pixel x R --> none
	setBlue(pixel, x): Pixel x R --> none

Un color è strutturato come (r,g,b) tutti numeri interi da 0 a 255

	getColor(pixel): Pixel --> Color
	setColor: Pixel x Color --> none
# getX

Restituisce la posizione X del pixel

	getX(pixel): Pixel --> N

# getY

Restituisce la posizione Y del pixel

	getX(pixel): Pixel --> N

# makeColor:

Crea colore con 3 valori da 0 a 255

	makeColor(): RxRxR --> Color


# pickAColor:

Scegli un colore

	pickAColor(): none --> Color

# makeLighter/makeDarker:

Rendi un colore più chiaro o scuro

	makeLighter(): Color --> Color
	makeDarker(): Color --> Color

# distance:

Calcola la distanza fra due colori, quindi si capisce quanto sono simili, questo calcolo è fatto dalla distanza cartesiana in $R^3$ dei due colori:

d = $\sqrt{(r_1-r_2)^2 + (g_1-g_2)^2 + (b_1-b_2)^2}$    

	distance(): Color x Color --> R

# makeEmptyPicture:
Crea un'immagine vuota

	makeEmptyPicuture(x,y, color): R x R x Color --> Picture 
	