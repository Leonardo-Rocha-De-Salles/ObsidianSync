Si deve progettare un codificatore e decodificatore di una stringa di 8 bit.
Il codice di Hamming ha distanza minima pari a 3.
Il circuito ha 13 ingressi e 13 uscite.
Il primo ingresso d ci dice
$$d = 0 (codifica) \qquad d=1(decodifica)$$

# Modalità di codifica
$$d=0$$
I nostri bit di parità $p_1,p_2,p_4,p_8$ sono in *condizione don't care*.
Si mettono i bit di dato come si vuole e il codificatore  metterà in output i seguenti valori:
![[Pasted image 20241025183332.png]]
Ovvero calcoliamo solo i bit di parità.
l'output e è sempre 0
# Modalità di decodifica
$$d=1$$
![[Pasted image 20241025183434.png]]
Abbiamo come input diversi valori, il nostro circuito dovrà riconoscere se ci sono errori, in quel caso.
$$e=1$$
Nel caso si riveli solo un errore, correggerlo. 

# Svolgimento

## Codifica di Hamming

La codifica di hamming ha i bit di parità che controllano le caselle in cui la posizione decimale si scrive con un bit di parità. 

# Tabella Codifica

| 0   | 1   | 2   | 3   | 4   | 5   | 6   | 7   | 8   | 9   | 10  | 11  | 12  |     |     |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| d   | p_1 | p_2 | d_1 | p_4 | d_2 | d_3 | d_4 | p_8 | d_5 | d_6 | d_7 | d_8 |     |     |
| p1  | x   | -   | x   | -   | x   | 0   | x   | -   | x   | 0   | x   | 0   |     |     |
| p2  | -   | x   | x   | -   | -   | x   | x   | -   | 0   | x   | x   | 0   |     |     |
| p4  |     |     |     | x   | x   | x   | x   |     |     |     |     | x   |     |     |
| p8  |     |     |     |     |     |     |     | x   | x   | x   | x   | x   |     |     |

