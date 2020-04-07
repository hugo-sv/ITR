# [TD1] Mesure de temps et échantillonnage en temps

Pour compiler les fichiers, à la racine du projet, éxecuter la commande :

`make td1`

Les executables de chaque sous questions seront dans le dossier 

`./build`

## a) Gestion simplifiée du temps Posix

Les fonctions sont implémentées dans le fichier `posixHelpers.cpp`.

Elles sont testées dans le main du fichier `posixHelpers.test.cpp`.

Exécuter `build/td1_a.out` pour faire les tests.

## b) Timers avec callback

Une fonction générique de timer est implémentée dans le fichier `posixTimer.cpp`.

Elle peut etre testée dans le main du fichier `posixTimer.test.cpp`.

Exécuter `build/td1_b.out` pour tester la fonction.

## c) Fonction simple consommant du CPU

La fonction de l'incrément et le test sont implementésd dans le fichier `IncrC.cpp`.

Pour la tester, il faut l'executer avec la commande suivante : 
```build/td1_c.out 10000000```

## d) Mesure du temps d’exécution d’une fonction

Il faut déclarer pStop comme `volatile bool` pour que le compilateur ne fasse pas de suppositions sur sa valeur.

Dans le fichier `mesureExecution.cpp`, la mesure du temps d'execution est effectuée, des parametres sont calculées et vérifiés.

L'objet Timer de la question b est réutilisé.

Pour le vérifier, une incrémentation est effectuée, et on compare le temps d'execution mesuré par la formule et celui mesuré.

Je trouve en général une erreur relative de l'ordre de 50% dans la calibration.

Pour tester, exécuter `build/td1_d.out`.

## e) Amélioration des mesures

La précision de la mesure pourrait etre améliorée en mesurant plus de fois le nombre de boucles pour un `t` donné, et en effectuant une moyenne.

On pourrait aussi supposer `l(t)` affine par morceaux, et calibrer avec plus de deux points pour se rapprocher au mieux de la courbe réelle `l(t)`.

Enfin, il faudrait s'assurer que la fonction calib ne soit pas perturbée par d'autres taches. On pourrait l'executer dans un thread à priorité maximale. Cependant, nous ne pouvons pas etre complètement sur qu'aucunes taches ne pourra perturber celle-ci.