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

## Creare un repository locale

Creiamo una cartella vuota, ci entriamo e scriviamo
```
git init
git add README.md
git commit -m "initial project version"
```
Se vogliamo fare la copia locale di un repository per modificarlo 
```
git clone <url>
```

## Commit di file
ogni volta che effettuami una modifica che vogliamo salvare dobbiamo aggiungerlo all'area di stagin:
	git add README.txt hello.java
questo comando crea uno snapshot della versione corrente.
Per spostare dalla staging alla repository dobbiamo effettuare l'operazione commit:
	git commit -m "Fixing bug #22"
Questi comandi operano nella verisone locale del repository.

per vedere lo stato attuale della repository
	git status

vedere cosa è stato modificato ma non inserito nello staging
	git diff

Vedere differenze nell'area di staging
	git diff -cached


## Logs
elenco modifiche fatte
	git log 


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