# [TD4] Classes de base pour la programmation multitâches

## a) Classe Thread

Les classes Thread et PosixThread sont implémentés dans les fichiers `Thread.cpp` et `PosixThread.cpp`.

Le script `a.cpp` Teste ces implementations en 3 tests en utilsant des Thread d'incrementation de compteur jusqu'à 100 000 000:
- 1 : Test des mesure de temps d'exceution, de la méthode `join` et `sleep`.
- 2 : Test de la méthode `join` avec timeout : La premiere tentative echoue, tandis que la seconde join le thread avant le timeout.
- 3 : test de la concurrence : Trois thread concurents sont lancé, la valeur finale du compteur n'est pas celle attendue.

Ce script peut être exécuté avec la commande `build/td4_a.out`.

## b) Classes Mutex et Mutex::Lock

@ Todo

Ce script peut être exécuté avec la commande `build/td4_b.out`.

## c) Classe Semaphore

@ Todo

Ce script peut être exécuté avec la commande `build/td4_c.out`.

## c) Classe Fifo multitâches

@ Todo

Ce script peut être exécuté avec la commande `build/td4_d.out`.