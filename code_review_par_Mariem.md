# Revue de code — TP Pokémon

Date : 17 septembre 2026

## Points positifs

- Le code est séparé entre les interfaces (`inc/`) et les implémentations (`src/`).
- La classe `Moacreature` possède un constructeur, un destructeur et une méthode d'attaque. La règle actuellement implémentée est : les dégâts sont égaux à `attaque - défense` lorsque l'attaque est strictement supérieure à la défense ; sinon, aucun dégât n'est infligé.
- `MoaDex` lit un fichier CSV et renvoie une copie d'une créature grâce au constructeur de copie, ce qui va dans le sens de l'extraction d'un clone demandée par l'énoncé.
- Le constructeur de `MoaDex` est privé et les constructeurs/copies d'instance sont interdits : l'intention d'implémenter un Singleton est présente.

## Écarts par rapport à l'énoncé et corrections recommandées

### 1. Classe `Moacreature`

- `hitPointMax` est déclaré mais n'est initialisé dans aucun constructeur. Il faut définir explicitement les points de vie maximum et les points de vie courants, par exemple en initialisant `hitPointMax` avec la valeur reçue puis `hitPoint` avec cette même valeur.
- Le constructeur de copie initialise `hitPoint`, `attack` et `defense` à `1` au lieu de recopier les valeurs de l'objet source. Le clone extrait du Pokédex ne représente donc pas fidèlement la créature de référence. Il faut copier tous les attributs, y compris `evolution` et `hitPointMax`.
- L'attribut `evolution` vaut bien `0` par défaut, comme demandé, mais il n'est ni renseigné par les constructeurs ni affiché. À l'inverse, `generation` est utilisé alors qu'il n'est pas demandé dans l'énoncé. Il faut préciser la différence entre génération et évolution, ou supprimer l'attribut inutile.
- `displayInfo()` n'affiche ni l'évolution ni les points de vie maximum. Pour faciliter les tests, ces informations devraient être affichées.
- Les accesseurs de `evolution` et de `hitPointMax` manquent. 
- La règle de combat doit être documentée dans le code ou le README. Elle devrait aussi empêcher les points de vie de devenir négatifs et indiquer le cas où la défense annule l'attaque. Le `std::cout << std::endl;` isolé après le message d'élimination est superflu.

### 2. Classe `Collections_Moacreature`

- L'énoncé demande une classe abstraite. Or `Collections_Moacreature` est instanciable : ses deux méthodes `trouver_la_creature` sont virtuelles mais pas pures, et leurs implémentations ne sont pas redéfinies dans les classes filles. Il faut revoir l'interface pour qu'elle contienne au moins une opération virtuelle pure pertinente, puis l'implémenter dans les classes dérivées, ou justifier un autre choix de conception.
- Les méthodes publiques `obtient` et `perd` utilisent des pointeurs bruts. La propriété des objets n'est pas définie et le destructeur ne libère aucun élément du vecteur : cela provoque des fuites mémoire pour les créatures créées avec `new`.
- `perd()` localise l'élément mais ne l'efface jamais : l'appel à `collection.erase(...)` est commenté et l'indice calculé ne peut pas être passé directement à `erase`. Il faut utiliser l'itérateur trouvé, par exemple `collection.erase(it)`, puis gérer correctement la destruction de l'objet.
- Les méthodes de recherche et de gestion de collection méritent une documentation de leurs paramètres, de leur valeur de retour et de la propriété mémoire des objets retournés ou ajoutés.

### 3. Classe `MoaDex` (Pokédex)

- Le Singleton contient deux fois le même test `if (instance == nullptr)`. Un seul test suffit. 
- Le Pokédex doit être une référence interne non modifiable. Or `obtient()` et `perd()` sont héritées publiquement de `Collections_Moacreature` : un appelant peut donc ajouter ou retirer des créatures du Pokédex. Il faut rendre ces opérations inaccessibles sur `MoaDex` et ne proposer que les méthodes d'extraction de clones.
- `chercher_moacreature(const string&)` effectue une recherche partielle avec `find`. Si l'objectif est d'extraire un Pokémon précis, une comparaison exacte est préférable, ou le comportement de recherche partielle doit être documenté.

### 4. Classe `mon_MoaDex` 

- La suppression repose sur `perd()`, qui ne supprime actuellement aucun élément. Elle doit donc être corrigée avant que la fonctionnalité ne soit considérée comme réalisée.
- Lorsqu'une créature clonée est refusée parce qu'elle existe déjà, le pointeur obtenu n'est pas libéré. 

### 5. Classe `PokemonAttack`

La classe demandée est absente. 

### 6. Organisation et programme de test

- Le dépôt ne contient pas le fichier CSV attendu ni de dossier dédié aux ressources. Il faut ajouter, par exemple, un dossier `resources/` contenant le CSV et utiliser un chemin cohérent.
- Dans `main.cpp`, un `return 0;` rend toute la partie consacrée au Singleton et au Pokédex inatteignable. Cette partie n'est donc pas testée.
- Le test suivant déréférencerait un pointeur nul : `if (Charizard == nullptr) { Charizard->getName(); }`. La condition doit être inversée ou le pointeur ne doit pas être utilisé dans le bloc `nullptr`.

## Priorités de correction

1. Implémenter `PokemonAttack` et rendre `Collections_Moacreature` réellement abstraite.
2. Corriger la copie des créatures, l'initialisation de `hitPointMax` et la suppression d'une créature.
3. Clarifier la propriété mémoire des créatures et supprimer les fuites liées aux pointeurs bruts.
4. Empêcher toute modification directe du Pokédex .
5. Ajouter des tests exécutables et documenter les règles de combat.
