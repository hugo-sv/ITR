# [TD-2] Familiarisation avec l’API multitâches pthread

## a) Exécution sur plusieurs tâches sans mutex

Il faut ajouter `-pthread` lors de la compilation :

```g++ -Wall -Wextra -O3 -o sansMutex.out sansMutex.cpp -lrt -pthread```

En excutant plusieurs fois `./sansMutex.out 1000 1000`, on observe plusieurs valeurs de compteurs, inférieurers à `nTasks * nLoops`.

L'opération d'incrémentation n'etant pas atomique, elles peuvent rentrer en conflit et des incrémentations sont perdues.

## b) Mesure de temps d’exécution

On observe que, environ une fois sur deux, le total du compteur est soit égal à `nLoops`, soit égal à `nLoops * nTasks`.

En tracant les temps d'execution, on obtient le graphique suivant :
![Chart](Chart.jpg "Courbe des temps d'execution")


## c) Exécution sur plusieurs tâches avec mutex

Avec les mutex, le programme est bien plus lent (et d'autant plus lent qu'il y a de taches), mais la valeur finale du compteur est fiable.