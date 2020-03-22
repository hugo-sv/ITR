# [TD-1] Mesure de temps et échantillonnage en temps

## a) Gestion simplifiée du temps Posix

Les fonctions sont implémentées dans le fichier `posixHelpers.cpp`.

Elles peuvent etre testées dans le main du fichier `posixHelpers.test.cpp`.

## b) Timers avec callback

Une fonction générique de timer est implémentée dans le fichier `posixTimer.cpp`.

ELle peut etre testée dans le main du fichier `posixTimer.test.cpp`.

## c) Fonction simple consommant du CPU

La fonction de l'incrément et le test sont implementésd dans le fichier `IncrSimple.cpp`.

Pour la tester, il faut l'executer avec la commande suivante (out étant la version compilée de `IncrSimple.cpp`) : 
```./out 10000000```

## d) Mesure du temps d’exécution d’une fonction

Il faut déclarer pStop comme `volatile bool` pour que le compilateur ne fasse pas de suppositions sur sa valeur.

Dans le fichier `mesureExecution.cpp`, la mesure du temps d'execution est effectuée, des parametres sont calculées et vérifiés.

Pour le vérifier, une incrémentation est effectuée, et on compare le temps d'execution mesuré par la formule et celui mesuré.

Je trouve en général une erreur relative de l'ordre de 40% dans la calibration.

## e) Amélioration des mesures

