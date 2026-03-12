# hash

## Définitions 

**Fonctions de hachqge cryptographique**

Une fonction de hachage cryptographique est une fonction qui prend en entrée un mesage de longuer arbitraire et produit une sortie de longueur fixe m appelée empreinte (message digest).

Elle doit satisfaire des propriétés telles que :
- Résistance à la préimage
- Résistance à la seconde préimage
- Résistance aux collisions
Il doit être difficile de trouver deux messages différents $x \neq x'$ tels que

$$\ h(x) = h(x')\$$

**Fonction de hachage non-cryptographique**

Une fonction de hachage non-cryptographique est aussi une fonction qui transform une donnée de taille arbitraire en une valeur plus courte. Mais elle n'est pas conçu pour la sécurité.

Ses objectifs sont la distribution uniforme des valeurs, vitesse de calcul et l'utilisation dans structures de données. 

**Truncation**

La troncature consiste à garder seulement une partie des bits d’un hash.

## Resultats

Dans une première expérience multi-classe, le modèle atteint une accuracy d’environ 40 %, supérieure au hasard (20 %), ce qui montre qu’il peut distinguer certaines familles de fonctions de hachage. Cependant, ce résultat est partiellement expliqué par des différences structurelles simples, notamment la longueur des sorties. En revanche, lorsque la tâche est restreinte à SHA-256 et SHA3-256, l’accuracy reste proche du hasard (environ 52 %), ce qui suggère que les deux fonctions cryptographiques produisent des sorties difficilement séparables par un modèle simple.

