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

Une fois le nombre de coups épuisés c'est le game over. Une autre manière de perdre et de heurter certains obstacles avec la balle.
Vous débutez la partie avec un totale de 1000 points, moins vous tirez plus vous avez de points.


## Dépendances requises

- Système d'exploitation: **Linux/Windows/Mac os** (makefile).
- Libraire graphique pour **l'affichage**: [SDL2](https://github.com/libsdl-org/SDL)



## Compilation et exécution

Dans le dossier `projet-lifap4`, il faut ouvrir un terminal est exéctuer la commande `make` (compilation) (ou bien F9 sur un IDE comme CodeBlocks)
Puis il suffit d'executer la commande **`bin/jeu_sdl`** pour lancer le jeu (exécution) affichage sdl.
Sinon pour afficher une version textuelle du terrain chargé il suffit d'executer **'bin/jeu_txt'**.


## Les commandes

Pour **ajouter/soustraire** un angle pour une trajectoire souhaitée:
- appuyer sur  la touche **t** (ajouter)
- appuyer sur  la touche **g** (soustraire)



Pour **ajouter/soustraire** de la puissance :
- appuyer sur  la touche **z** (ajouter)
- appuer sur  la touche **s** (soustraire)

Pour **ajouter/soustraire** de la fréquence de rafraichissement pour adapter le jeux a votre ordinateur :
- appuyer sur  la touche **o** (ajouter)
- appuer sur  la touche **l** (soustraire)

Pour **Lancer la balle**:
- appuyer sur la touche **j**

## Astuces

vous pouvez  **replacer la balle** si vous n'arrivez plus à avancer avec la touche a.<br/>
certains **obstacles** vous feront perdre instantanément à vous de les eviter.<br/>
Après **20 coups** vous perdrez donc essayer d'n faire le moins possible !.<br/>



## Les prix

**SCORE :**

- début à 1000.
- vous perdez des points en jouant (-1000-sqrt(1000)/2 par action)



## Contenu de l'archive

- Le dossier `bin` qui contient **les éxecutables**.
- Le dossier `data` qui contient **les données audio, images, niveau**.
- Le dossier `doc` qui contient **la documentation doxygen** ainsi que les **diagramme de Gant et UML**.
- Le dossier `save` qui contient **les sauvegardes du jeu**.
- Le dossier `src` qui contient **les sources**.
- dans src il y a les dossier 'core', 'sdl2', 'txt' qui contiennent **les différents fichiers header et cpp**

## Étudiants

- Théo Forest 12104129 [lien vers mail](mailto:theo.forest@etu.univ-lyon1.fr)
- Gabriel DEBOTTE 12105156 [lien vers mail](mailto:gabriel.debotte@etu.univ-lyon1.fr)

