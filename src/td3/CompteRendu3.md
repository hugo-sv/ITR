# [TD3] Classes pour la gestion du temps

## a) Classe Chrono

Le chronomètre est implémenté dans le fichier `Chrono.cpp` et testé dans le fichier `a.cpp`.
Dans ce second fichier, nous testons les fonctions stop, restart et lap, et vérifions que la différence entre la valeur attendue par timespec_wait etla valeur mesurée par le chronomètre ne dépasse pas 5 millisecondes (pour prendre en compte le délai d'exécution entre les instructions)

## b) Classe Timer

Le constructeur et le destructeur de la classe `Timer`, ainsi que les méthodes `start` et `stop` sont des éléments publics : en effet, pour que n'importe quel élément puisse utiliser la classe `Timer` pour créer, démarrer, arrêter et détruire un `Timer`, il est nécessaire que ces méthodes soient accessibles à tous, donc publiques.

L'attribut de class `timer_t` et la méthode `callback` sont des éléments protégés : il n'est pas sécurisé de les laisser publics, sans quoi n'importe quel élément pourrait modifier le comportement du `Timer` en changeant la fonction de `callback` ou en fournissant un tid erroné. Cependant, afin de pouvoir construire des `Timer` particuliers, et d'implémenter la fonction `callback` (virtuelle pure dans Timer), il est nécessaire que ces deux éléments soient accessibles par les classes dérivées. 

La méthode de class `call_callback` est privée, car elle ne fait qu'appeler la méthode `callback` après la fin du timer, et n'a donc pas de raison d'être modifiée ultérieurement. Son utilité est de permettre d'appeler callback depuis un timer posix : en effet, cette dernière est une méthode protégée, et le timer posix n'a pas le contrôle sur l'objet `Timer` qui l'a créé, et ne peut donc pas appeler directement la fonction `callback`

La méthode callback est virtuelle pure : en effet, elle doit être implémentée de façon spécifique à chaque `Timer`.
La méthode `start`doit également être virtuelle afin de pouvoir être surchargée pour faire le `PeriodicTimer`.

## c) Calibration en temps d'une boucle

Le calibrateur est implémenté dans les fichiers `Calibrator.cpp` et `Looper.cpp`, et testé grâce à `c.cpp`.
La calibration est effectuée sur 1000 mesures, effectuées toutes les millisecondes. 
On constate un décalage de plusieurs centaines de millisecondes entre le temps prévu pour les tests (4 et 6 secondes), et le temps réellement nécessaire pour effectuer le nombre de boucles calculé grâce aux valeurs calibrées.