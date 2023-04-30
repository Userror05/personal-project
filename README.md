# Project Golfnic


                                                    Golfnic: projet de LIFAP4 2022-2023


## Table des matières

- [À propos](#à-propos)
- [Dépendances requises](#dépendances-requises)
- [Compilation et exécution](#compilation-et-exécution)
- [Les commandes](#les-commandes)
- [Astuces](#astuces)
- [Les prix](#les-prix)
- [Contenu de l'archive](#contenu-de-l'archive)
- [Étudiants](#étudiants)


## À propos

**Golfnic** est un jeu de golf inspiré de [Sonic](https://fr.wikipedia.org/wiki/Sonic) reprenant en partie son affichage 2D ainsi que des sprites. 
C'est un jeu de golf. Le but est simple mettre la balle dans le trou en faisant le moins de coup possible dans un temps imparti.

La partie se lance après avoir choisis l'angle ainsi que la puissance désiré par l'utilisateur.

Une fois le temps imparti terminé c'est le game over.

Afin de satisfaire les besoins des survivants, le bâtisseur doit **détruire/construire des salles** et **attribuer à ces dernières de la main-d’œuvre** (Exemple : pour nourrir les survivants, il faut construire un réfectoire et y ajouter des joueurs), attention chaque **personnage a des caractéristiques qui concordent plus ou moins avec une salle en particulier** (par exemple si le joueur est intelligent il serait pertinent de le faire travailler dans la salle des réacteurs, à l'inverse si un joueur est très fort il ne serait pas très malin de le faire travailler dans le salon).

De plus, **le nombre de d’habitant est limité au nombre de places dans le dortoir**, il n’y aura donc pas toujours de la place pour tout le monde, pour remédier à ceci, vous pouvez envoyer des personnages en **expédition suicide**, ils reviendront peut-être plus tard dans le jeu avec **aux choix de la ferraille ou bien des stuffs à ajouter dans votre sac à dos (pas disponible pour l'instant car pas d'invasion)**.


## Dépendances requises

- Système d'exploitation: **Linux/Windows/Mac os** (makefile).
- Libraire graphique pour l'**affichage**: [SDL2](https://www.libsdl.org/download-2.0.php)



## Compilation et exécution

Dans le dossier `projet-lifap4`, il faut ouvrir un terminal est exéctuer la commande `make` (compilation).
Puis il suffit d'executer la commande `bin/jeu_sdl` pour lancer le jeu (exécution).


## Les commandes

Pour **ajouter/soustraire** un angle pour une trajectoire souhaitée:
- appuyer sur t (ajouter)
- appuyer sur g (soustraire)

- cliquez sur un emplacement où des travaux sont possible 🚧
- choisissez la type de salle que vous souhaitez construire dans le menu à gauche.

Pour **ajouter/soustraire** de la puissance :
- appuyer sur z (ajouter)
- appuersur s (soustraire)


## Astuces

vous pouvez  **replacer la balle** si vous n'arrivez plus à avancer avec la touche a.<br/>
certains **obstacles** vous feront perdre instantanément à vous de les eviter.<br/>
Un personnage **agile et fort** sera plus efficace dans **l'atelier**.<br/>
Un personnage **agile et sociable** sera plus efficace dans **le réfectoire**.<br/>
Un personnage **charmant et sociable** sera plus efficace dans **le salon**.<br/>
Un personnage **concentré** sera plus efficace dans **la station d'épuration**.<br/>
Un personnage **fort** sera plus efficace dans **la milice**.<br/>
Un personnage **intelligent** sera plus efficace dans **la salle des réacteurs**.<br/>
**L'ascenceur** permet aux survivants de se **déplacer dans differents étages**.<br/>
**L'atelier** permet aux personnages d'aller resoudre les differents problèmes techniques.<br/>
**L'infirmerie** permet de soigner les personnages blessés.<br/>
**Le nombre de survivants** logeable dans le refuge dépand du nombre de lits dans **les dortoires**.<br/>
**Le réacteur** fournis de l'**énergie** aux salles.<br/>
**Le réfectoire** permet de nourrir les personnages.
**Le salon** est un espace qui **rends heureux** la communauté.<br/>
**Eau potable** est une station dépuration de l'eau qui permet fournir de l'eau potable.<br/>


## Les prix

**Destruction :**

- 0 ⚙️ pour **toutes les salles**.

**Construction :**

- 100 ⚙️ pour **un ascenseur** ou **un atelier** ou **une infirmerie** ou **un salon** ou **une salle d'eau** ou **un réfectoire** ou **un réacteur** ou **un dortoir**.
- 200 ⚙️ pour **une milice**.

**Agrandissment :** 

Du **niveau 1 au 2**: 
- 150 ⚙️ pour **un ascenseur** ou **un atelier** ou **une infirmerie** ou **un salon** ou **une salle d'eau** ou **un réfectoire** ou **un réacteur** ou **un dortoir**.
- 250 ⚙️ pour **une milice**.

Du **niveau 2 au 3**:
- 300 ⚙️ pour **un ascenseur** ou **un atelier** ou **une infirmerie** ou **un salon** ou **une salle d'eau** ou **un réfectoire** ou **un réacteur** ou **un dortoir**.
- 500 ⚙️ pour **une milice**.


## Contenu de l'archive

- Le dossier `bin` qui contient **les éxecutables**.
- Le dossier `data` qui contient **les données audio, image,niveaus (et anciennes versions)**.
- Le dossier `doc` qui contient **la documantation doxygen**.
- Le dossier `include` qui contient **les includes de la libraire sonore**.
- Le dossier `lib` qui contient la [libraire irrklang](#dépendances-requises).
- Le dossier `save` qui contient **les sauvegardes du jeu**.
- Le dossier `src` qui contient **les sources**.

## Étudiants

- Théo Forest 12104129 [lien vers mail](mailto:theo.forest@etu.univ-lyon1.fr)
- Gabriel DEBOTTE 12105156 [lien vers mail](mailto:gabriel.debotte@etu.univ-lyon1.fr)

