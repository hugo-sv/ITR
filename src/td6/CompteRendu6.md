# [TD6] Object actif

Pour compiler les fichiers, éxecuter la commande suivante à la racine du projet :

`make td6`

L'executable est dans le dossier `./build`.

Les classes `ActiveObject`, `Request`, `ActiveCalc`, `Calculator` et `CrunchReq` sont implémentés dans le dossier `src/td4/`.

Le script `src/td4/main_td6.cpp` permet de tester ces implémentations avec la classe `Client`.

Celle-ci soumet un calcul avec sa `seed` comme paramètre au calculateur, poursuit d'autres instruction (patiente 1 500 ms), puis attend le résultat.

Chaque calculs prend 500 ms et renvoie le paramètre en sortie.

On s'attends dans un premier temps à ce que chaque client recoive sa propre `seed` à l'issue du calcul.

En lançant 10 clients, on s'attends aussi à ce que les trois premiers qui soumettent leur tâche ne recoivent un résultat qu'au bout de 1 500 ms(du fait des autres instructions). 

Tous les autres clients devront successivement recevoir leur résultat toutes les 500ms, tous devraient alors leurs résultats en environ 5 000 ms ou moins.

Les clients étant successivement crées (on laisse 1 ms entre chaque `client.start()`), et de part la structure de la Fifo, les clients devraient recevoir leur résultats dans le même ordre.

Le script peut être exécuté avec la commande `build/td6.out`, et il vérifie tous les comportements décrits ci-dessus.