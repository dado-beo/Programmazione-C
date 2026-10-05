# 💻 Corso di Programmazione C — Università del Piemonte Orientale (UPO)

Benvenuto nel repository dedicato al corso di **Programmazione in Linguaggio C**.  
Questo spazio racchiude tutti gli argomenti teorici, gli esempi di codice commentati e gli esercizi pratici svolti durante l'anno accademico.

---

## 🛠️ Ambiente di Sviluppo & Setup

L'ambiente di lavoro è configurato per garantire la massima compatibilità con gli standard di laboratorio universitario e la portabilità tra diverse postazioni:

* **OS / Environment:** WSL 2 (Ubuntu su Windows)
* **Compilatore:** GCC (`GNU Compiler Collection`)
* **Editor:** Visual Studio Code
* **Automatizzazione:** Estensione *Code Runner* (con compilazione ed esecuzione gestita direttamente nella cartella `bin/`)
* **Version Control:** Git & GitHub

---

## 📂 Struttura del Repository

Il repository è organizzato per argomenti progressivi seguendo le slide del corso. Ciascun file `.c` contiene una trattazione teorica approfondita (tramite commenti) e un programma eseguibile completo.

```text
Programmazione-C/
├── .gitignore                    # Regole di esclusione per file binari ed eseguibili
├── README.md                     # Documentazione generale del progetto
├── bin/                          # Cartella generata automaticamente contenente i binari (ignorata da Git)
│
├── 00_introduzione.c             # Struttura base del C, main(), printf, sequenze di escape e GCC
├── 01_variabili.c                # Tipi di dato, operatore sizeof, scanf, gestione buffer e costanti
│
# ... (in aggiornamento continuo con le prossime slide)

# Compilazione con flag di avvertimento (-Wall) e output in bin/
gcc -Wall 00_introduzione.c -o bin/00_introduzione

# Esecuzione
./bin/00_introduzione

# Per salvare e inviare gli aggiornamenti al repository remoto con un solo comando: salva