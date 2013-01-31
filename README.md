Trade
Robot trader : Le but de ce projet est de réaliser un robot trader, optimisant les gains. Le programme peut eﬀectuer les 3 actions suivantes :

ACHETER via la syntaxe buy n, où n est le nombre d’actions à acheter. Une commission de 0.15% arrondie à l’entier supérieur sur le montant total de l'ordre est prélevée. On doit impérativement avoir assez d’argent pour cet ordre.

VENDRE via la syntaxe sell n, où n est le nombre d’actions à vendre au cours actuel. Une commission de 0.15% arrondie à l’entier supérieur sur le montant total de l'ordre est prélevée. On doit impérativement posséder suﬃsamment d’actions pour cet ordre.

ATTENDRE via la syntaxe wait. Aucune action n’est achetée ni vendue.

Les cours de la bourse seront transmis au programme via une moulinette ; c’est aussi elle qui exécutera l’ordre passé par le programme. A chaque tour (représentant un jour), la moulinette enverra le cours actuel de l’action au programme qui passera alors un ordre. Le nombre de tours est déterminé à l’avance.

La moulinette s’utilise comme suit : ./trade_moulinette -f ﬁchier -p binaire -m capital [-o]

-f ﬁchier où ﬁchier contient la suite des entiers représentant le cours de l’action ; ces entiers seront envoyés un par un à votre programme à chaque tour. 
-p binaire où binaire est le chemin vers votre programme. 
-m capital où capital est le montant d’argent dont vous disposez initialement. 
-o permet d’aﬃcher les valeurs de l’action sur la sortie standard.
