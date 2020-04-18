# [TD4] Classes de base pour la programmation multitâches

## a) Classe Thread

Les classes `Thread` et `PosixThread` sont implémentés dans les fichiers `src/td4/Thread.cpp` et `src/td4/PosixThread.cpp`.

Le script `src/td4/a.cpp` Teste ces implementations en 3 tests en utilsant des Thread d'incrementation de compteur (`src/td4/AIncrementer.cpp`) jusqu'à 100 000 000:
- 1 : Test des mesure de temps d'exceution, de la méthode `join` et `sleep`.
- 2 : Test de la méthode `join` avec timeout : La premiere tentative echoue, tandis que la seconde join le thread avant le timeout.
- 3 : test de la concurrence : Trois thread concurents sont lancé, la valeur finale du compteur n'est pas celle attendue.

Ce script peut être exécuté avec la commande `build/td4_a.out`.

## b) Classes Mutex et Mutex::Lock

Les classes `Mutex`, `Mutex::Monitor`, `Mutex::Lock` et `Mutex::TryLock` sont implémentées dans le fichier `src/td4/Mutex.cpp`.

Le compteur avec accès protégé par Mutex est implémenté dans le fichier `src/td4/BIncrementer.cpp`. Son fonctionnement est testé avec le fichier `src/td4/b.cpp` : trois compteurs protégés sont lancés en parallèle.

On observe que le compte est bon, mais que la vitesse d'execution est moindre comparée au test 3 de la partie a.

Ce script peut être exécuté avec la commande `build/td4_b.out`.

## c) Classe Semaphore

@ Todo

Ce script peut être exécuté avec la commande `build/td4_c.out`.

## c) Classe Fifo multitâches

@ Todo

Ce script peut être exécuté avec la commande `build/td4_d.out`.