# [TD4] Classes de base pour la programmation multitâches

Pour compiler les fichiers, éxecuter la commande suivante à la racine du projet :

`make td4`

Les exécutables de chaque sous-questions seront dans le dossier `./build`.

## a) Classe Thread

Les classes `Thread` et `PosixThread` sont implémentés dans les fichiers `src/td4/Thread.cpp` et `src/td4/PosixThread.cpp`.

Le script `src/td4/main_td4a.cpp` Teste ces implementations en 3 tests en utilsant des Thread d'incrementation de compteur (`src/td4/AIncrementer.cpp`) jusqu'à 100 000 000:
- 1 : Test des mesure de temps d'exceution, de la méthode `join` et `sleep`.
- 2 : Test de la méthode `join` avec timeout : La premiere tentative echoue, tandis que la seconde join le thread avant le timeout.
- 3 : test de la concurrence : Dix threads concurents sont lancés, la valeur finale du compteur n'est pas celle attendue.

Ce script peut être exécuté avec la commande `build/td4_a.out`.

## b) Classes Mutex et Mutex::Lock

Les classes `Mutex`, `Mutex::Monitor`, `Mutex::Lock` et `Mutex::TryLock` sont implémentées dans le fichier `src/td4/Mutex.cpp`.

Le compteur avec accès protégé par Mutex est implémenté dans le fichier `src/td4/BIncrementer.cpp`. Son fonctionnement est testé dans le premier test du script `src/td4/main_td4b.cpp`, où trois compteurs protégés sont lancés en parallèle.

On observe que le compte est bon, mais que la vitesse d'execution est moindre comparée au test 3 de la partie a.

La classe `Thread` est aussi complétée du champs booléen `started`, testé dans le second test du script, où l'on tente à deux reprise d'exécuter la méthode `start()` sur un thread actif. 

Ce script peut être exécuté avec la commande `build/td4_b.out`.

## c) Classe Semaphore

La classe `Semaphore` est implémentée dans le fichier `src/td4/Semaphore.cpp`.

Dans le script `src/td4/main_td4c.cpp`, un sémaphore est partagé par des tâches à la fois consommatrices et productrices, implémentées dans le fichier `src/td4/CProducer.cpp`.

Cette tâche prend un jeton, attend 100 ms, puis donne un jeton au sémaphore.
Avec 10 taches consomatrices, et un sémaphore initialisé à 5 jetons, on vérifie avec le script bien une execution en 200ms.
Les prises et rendus de jetons sont aussi affichés.

Ce script peut être exécuté avec la commande `build/td4_c.out`.

## c) Classe Fifo multitâches

La classe `Fifo` est entierement implémentée dans le fichier `src/td4/Fifo.hpp`.

Pour tester cette classe, le script `src/td4/main_td4d.cpp` utilise la classe `Cproducer`, implémentée dans le script `src/td4/Cproducer.cpp`.

Ce producer consomme une tache de la Fifo (un entier `n` strictement positif), attend 10 ms, puis produit deux taches : `n-1` et `n-2`, tant qu'ils sont strictement supérieurs à 0. Ce dernier consomme indéfiniement les éléments de la Fifo, a moins que son timeout ne soit atteint.

Dans notre exemple, la Fifo est initialisé avec les entiers `5`, `4`, `3`, `2` et `1`, et deux `Cproducer` sont crées, puis mis en route pour consommer la Fifo.

Une fois les timeout des deux taches atteints, on vérifie que toutes les tahces (initialeemnt entrée, mais aussi produites) ont bien étée consommées, et que le Fifo est bien vide.

Ce script peut être exécuté avec la commande `build/td4_d.out`.