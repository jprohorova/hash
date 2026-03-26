# Cryptographie vs Machine Learning  

## Introduction

Les fonctions de hachage occupent une place centrale dans la cryptographie moderne. Elles sont utilisées dans de nombreux mécanismes de sécurité tels que les signatures numériques, l’intégrité des données, les structures de données sécurisées et les protocoles d’authentification.

Selon Douglas R. Stinson - Cryptography: Theory and Practice, une fonction de hachage cryptographique est une fonction déterministe qui transforme un message de longueur arbitraire en une empreinte de longueur fixe.

Dans ce projet, nous analysons plusieurs fonctions de hachage cryptographiques et non cryptographiques afin d’examiner si des modèles statistiques ou de machine learning peuvent identifier des régularités exploitables.

# Définition formelle d’une fonction de hachage

Une fonction de hachage est une application :

$$
H : \{0,1\}^* \rightarrow \{0,1\}^n
$$

où :

- $\{0,1\}^*$ représente l’ensemble des messages de longueur arbitraire
- $\{0,1\}^n$ représente l’ensemble des sorties de longueur fixe $n$

Pour tout message $m$ :

$$
h = H(m)
$$

où $h$ est appelé empreinte (digest).

---

# Propriétés cryptographiques fondamentales

D’après Stinson, une fonction de hachage cryptographique doit satisfaire plusieurs propriétés de sécurité.

---

## Résistance à la préimage

Étant donné une valeur $h$, il doit être computationnellement infaisable de trouver un message $m$ tel que :

$$
H(m) = h
$$

---

## Résistance à la seconde préimage

Étant donné un message $m_1$, il doit être difficile de trouver un message $m_2$ tel que :

$$
H(m_1) = H(m_2)
$$

avec :

$$
m_1 \neq m_2
$$

---

## Résistance aux collisions

Il doit être difficile de trouver deux messages distincts $m_1$ et $m_2$ tels que :

$$
H(m_1) = H(m_2)
$$

Pour une fonction produisant $n$ bits, la sécurité théorique est donnée par la borne du paradoxe des anniversaires :

$$
\text{Complexité} \approx 2^{n/2}
$$

---

# Avalanche Effect

Une propriété fondamentale des fonctions de hachage cryptographiques est l’effet d’avalanche.

Une petite modification du message d’entrée doit produire un changement important dans la sortie.

Si :

$$
m' = m \oplus \Delta
$$

alors idéalement :

$$
H(m') \sim U(\{0,1\}^n)
$$

c’est-à-dire que la sortie doit se comporter comme une variable aléatoire uniforme.

Dans un système idéal :

$$
P(\text{bit changé}) = \frac{1}{2}
$$

---

# Fonctions étudiées dans ce projet

Ce projet compare plusieurs fonctions de hachage.

## Fonctions cryptographiques

- SHA-256
- SHA3-256

Ces fonctions sont conçues pour satisfaire les propriétés de sécurité définies précédemment.

## Fonction de hachage non-cryptographique

- **FNV-1a**
- **Polynomial hash**
- **Truncated hash**

Une fonction de hachage non-cryptographique est aussi une fonction qui transform une donnée de taille arbitraire en une valeur plus courte. Mais elle n'est pas conçu pour la sécurité.

Ses objectifs sont la distribution uniforme des valeurs, vitesse de calcul et l'utilisation dans structures de données. 

**Truncation**

La troncature consiste à garder seulement une partie des bits d’un hash.

---

# Problématique

Les fonctions de hachage cryptographiques sont conçues pour se comporter comme des fonctions pseudo-aléatoires. Cependant, les modèles de machine learning sont précisément conçus pour détecter des structures statistiques dans les données. Cela conduit à la question suivante :

> Dans quelle mesure les modèles d’apprentissage automatique peuvent-ils révéler des régularités dans des structures conçues précisément pour les empêcher ?

---

# Hypothèse

- Les fonctions non cryptographiques contiennent des régularités statistiques détectables.
- Les fonctions cryptographiques modernes se comportent comme des distributions quasi-aléatoires.

Dans ce cas, un modèle de classification devrait obtenir :

$$
P(\text{prédiction correcte}) \approx 0.5
$$

ce qui correspond à une performance équivalente au hasard.

---

# Resultats

Dans une première expérience multi-classe, le modèle atteint une accuracy d’environ 40 %, supérieure au hasard (20 %), ce qui montre qu’il peut distinguer certaines familles de fonctions de hachage. Cependant, ce résultat est partiellement expliqué par des différences structurelles simples, notamment la longueur des sorties. En revanche, lorsque la tâche est restreinte à SHA-256 et SHA3-256, l’accuracy reste proche du hasard (environ 52 %), ce qui suggère que les deux fonctions cryptographiques produisent des sorties difficilement séparables par un modèle simple.

