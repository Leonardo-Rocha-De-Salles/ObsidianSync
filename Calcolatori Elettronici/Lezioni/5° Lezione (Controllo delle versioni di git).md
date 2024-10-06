
# Cos'è un version Control

Un version control system è un programma che permette la gestione dei cambiamenti di una serie di file, un suo obiettivo è quello di poter tornare a versioni precedenti di possibilmente un intero progetto e far lavorare insieme membri di un team.

Lo sviluppo di applicazioni avviene nel tempo con contributo di squadre di sviluppatori.
Per uno sviluppo efficiente e sostenibile è necessario:
- tenere traccia dell'evoluzione del codice sorgente e della documentazione
- tenere traccia di errori
- sviluppare *patch* per correggere errori
- tenere traccia delle nuove *funzionalità*
- associare una *versione* dell'applicazione al codice sorgente corrispondente
C'è bisogno di controllare le versioni, per gestire tutti gli aspetti del codice sorgente.

# La storia di un'applicazione
![[Pasted image 20241004113739.png]]

# Operazioni tipiche del controllo delle versioni
- *Commit* : rende definitivo un insieme di modifiche e renderle disponibili a tutti gli utenti (tutte le modifiche messe insieme e inserite nella base del codice)
- *File locking* : Modo per uno sviluppatore per essere l'unico per modificare un file.
- *Merge* : Più sviluppatori modificano file diversi o lo stesso file, per poi riconcigliare tutte le modifiche nel file sorgente. Possono verificarsi dei conflitti dall'unione di codici che poi devono essere risolti manualmente.
- *Tagging* : uno specifico *commit* a cui può essere associato un'*etichetta* per tracciare una versione specifica dell'applicazione.


# Git
Strumento file sharing per modificare file sorgenti, nato dagli sviluppatori di Linux. Veloce, capace di gestire complessità.
Git è un **Version Control System**, un sistema che si ricorda tutti i cambiamenti fatti al nostro codice in un data base chiamato **repository**, possiamo guardare tutti i cambiamenti nel nostro database, chi li ha fatti etc...
Se si avessero problemi con una versione aggiornata del nostro programma, possiamo tornare a una versione precedente grazie a **Git**.

## Modello distribuito
git utilizza un modello completamente distribuito, ogni utente ha una copia del codice sorgente del programma sulla sua macchina, con tutte le versioni passate, anche se un server malfunziona, possiamo collegare il computer fra gli utenti senza dover passare prima per un server centrale..
Il modello distribuito permette agli sviluppatori di distribuirse codice fra di loro direttamente senza prima passare per un server. Capaci di ricostruire tutta la storia dell'applicazione.

## Snapshot
Ogni volta che viene generato un commit, git crea delle istantanee (snapshot) del valoro, basato sul concetto di filesystem. Permette velocemenente di portarsi avanti e indietro nel flusso del lavoro. Per passare da una versione o l'altra basta ricreare delle patch per far andare avanti la nostro base di codice. Prendendo pezzi del codice sorgente e riportandoli come voglio in modo da ricreare versioni moderne o passate.


## Aree di un progetto locale
Un progetto locale ha tre aree: la working directory, la staging area e la git directory.
![[Pasted image 20241004115509.png]]
Abbiamo la working directory, i nostri file locali a cui lavoriamo direttamente.
git directory (repository), storia della mia applicazione, esiste il repository sul mio computer e quello su github.
Quando voglio costruire un commit dalla working directory, posso spostarli nella staging area, un commit non finalizzato con tutte le modifiche pronte ad essere inviate ma ancora modificabili. Quando lo staging è pronto le prendo e le inserisco nel repository, git directory.

git add aggiunge un file dalla working directory alla stanging area, git commit sposta il nostro file nella local repository, infine git push lo pubblica nella repository online.
Invece per ricevere dalla repository online, utilizziamo git clone per copiare la repository sul nostro computer, inseguito utilizziamo git checkout per prendere dalla local repository alla nostra woking area.
Git pull prende direttamente dalla repository alla nostra woking directory.


Se uso git fetch prendo gli ultimi update da un utente nella repository, per poi utilizzare git merge e unirli ai miei nella working directory.








## Ciclo di vita di un file

La creazione o modifica di un file possono essere non tracciati, al di fuori del progetto. Quando aggiungo il file al mio progetto diventa un file non modificato, se lo modifico diventa modificato e poi posso andarlo ad inserirlo nella sezione staged
![[Pasted image 20241004115935.png]]





# Git Terminology

- Working tree: l'insieme di tutte le directory e file che contengono il progetto
- Repository: La directory locata al livello più alto del working tree, dove Git mantiene tutte la storia del meta data.
- Hash : riproduce i contenuti di un file tramite un sequenza di 160 bit
- Object : Una git repository ne contine 4 tipi, blob object che contiene file normali, tree object che rappresenta una directory con nomi, hashes, permissioni. Un commit object che rappresenta una specficia versione del wokring tree. A tag object è il nome del commit
- Commit: l'azione significa di far confermando i cambiamenti fatti.
- Branch : Un branch è nominato da una serie di commit collegati. Il commit più recente di un branch si chiama head.
  Il branch default della repository è il main oppure master.  I branches permettono ai developer di lavorare indipendetemente in brancher e dopo unirli.
- Remote : quando crei una repo, git crea un remote chiamato origin dove i push e pull operations avvengono







# Github
E' il sito che ospita copie dei repository *git*.
## Differenza fra git e github
git è un sistema di controllo delle versioni distribuito che può essere accesso anche senza github, github è più un social network, un'interfaccia network di git che ha il vantaggio di avere le github actions


## Github actions
Offre la funzionalità del testing automatizzato delle applicazioni, per verificare bug o regressioni (pezzi di applicazione che per modifiche smettono di funzionare) in modo da fermare problemi futuri.
Github esegue automaticamente *batterie di test* per verificare la qualità del software ogni commit.
servizio basato su container, permette di eseguire automaticamente le batterie di test ad ogni commit.


# Preparazione all'uso di git

- Imposta il nome utente e l'email con cui verranno "firmati" i commit.
```
git config --global user.name "username"
git config --global user.email "user@email.com"
```
- Si puo utilizzare git config --list per verificare la corretta impostazione dell'utente.
- Omettendo il flag --global si possono impostare variabili di configurazioni locali per ciasun repository

## Creare un repository locale (workflow)

Creiamo una cartella vuota, ci entriamo e scriviamo
```
git init
git add README.md
git commit -m "initial project version"
```
git init crea la cartella necessaria a mettere in comunicazione la nostra cartella con git.
git add README.md dice a git che il file pre esistende readme adesso è da "controllare", ovvero è lo sposta nella Staged Area. Ogni volta da adesso in poi che scriviamo per esempio *git status*, git ci dirà se un nostro file **staged** è stato modificato o meno.
git commit -m "Message" farà uscire i nostri file added dallo staged al commit type, questo significa che è come se salvassimo tutte le modifiche applicate, preparandole ad essere inviate.
Facendo git log possiamo vedere tutti i commit applicati.
**git diff** ci fa vedere quello che è rimasto inalterato.


Fino ad adesso la nostra git repository è rimasta locale, per renderale online:

Adesso se vogliamo mettere i nostri file online e caricare per la prima volta i file alla nostra repository come prima di tutto dobbiamo dire a git qual'è la nostra repository ("Serve una chiave associata al computer e il nostro account github per permettere questa cosa").

```
git remote add origin <url>
```

Stiamo specificanto che questa remote repository è l'origine della nostra local git repository

Adesso mettiamo online il nostro master branch

```
git push -u origin master
```

E' così abbiamo messo i nostri file nella online repository.

Adesso se dovessi modificare o creare file, tutto come prima, i file create li mettiamo nella stage phase con git add, poit usiamo git commit per applicare le modifiche e infine basterà solo

```
git push 
```

Per metterle online

Se vogliamo fare la copia locale di un repository online utilizziamo.
```
git clone <url>
```
Adesso se vogliamo aggiornare questa repository locale, utilizziamo

```
git pull
```


vedere cosa è stato modificato ma non inserito nello staging
	git diff

Vedere differenze nell'area di staging
	git diff -cached


## Sincronizzare repository remoti

Per prendere da un repository remoto le ultime modifiche pubblicate:
	git pull origin main
Per pubblicare sul repository remoto i commit dal repository locale:
	git push origin main
Informazioni sul repository remoto:
	git remote -v


## Branching
Git branching serve a divergere dalla code base principale per sviluppare una nuova feature senza influenzare la code base prima di averlo finito. Branching aiuta un workflow isolato.
Creare multipli rami di lavoro chiamati *branch*, per crearlo:
![[Pasted image 20241004121942.png]]


# Comandi git

![[Pasted image 20241004121750.png]]![[Pasted image 20241004121959.png]]



# Che cos'è GitHub
## Repository
Contiene tutti i project files e le loro versioni.
https://learn.microsoft.com/en-us/training/modules/introduction-to-github/2-what-is-github


## Pull Request
Una pull request è un metodo per indicare che i commit di un Branch sono pronti ad essere merged con un altro branch.
![[Pasted image 20241006210422.png]]
