17/12/2024
**LAI Yohann - E3 IMAC TD2**

# ❌⭕ Programmation C++ : Rapport du Projet TicTacToe

- [❌⭕ Programmation C++ : Rapport du Projet TicTacToe](#-programmation-c--rapport-du-projet-tictactoe)
  - [Description](#description)
  - [Prérequis](#prérequis)
    - [Librairies et dépendances](#librairies-et-dépendances)
  - [Organisation du code](#organisation-du-code)
    - [Dossier `include`](#dossier-include)
    - [Dossier `src`](#dossier-src)
  - [Fonctionnalités supplémentaires](#fonctionnalités-supplémentaires)
  - [Problèmes rencontrés et solutions](#problèmes-rencontrés-et-solutions)
    - [Validation des entrées utilisateur](#validation-des-entrées-utilisateur)
    - [Logique de l'IA](#logique-de-lia)
    - [Clarté du code](#clarté-du-code)
    - [Placements des #include](#placements-des-include)
  - [Conclusion](#conclusion)

## Description

Ce projet implémente un jeu de TicTacToe (ou morpion) en C++, avec deux modes de jeu :

- **Deux joueurs :** Deux personnes jouent l'une contre l'autre sur le même ordinateur.
- **Un joueur contre l'IA :** Un joueur joue contre une intelligence artificielle simple.

Le jeu s'effectue sur une grille 3x3 où les joueurs doivent aligner trois de leurs symboles (X ou O) pour gagner.

## Prérequis

Avant d'exécuter le programme, assurez-vous d'avoir un environnement de développement C++ avec le standard C++17. Le projet utilise CMake pour la configuration du build. Pour information, le programme a été testé sur le système d'exploitation macOS Sonoma 14.6.1 mais il ne devrait pas y avoir de problème sur Windows.

### Librairies et dépendances

Aucune dépendance externe n'est nécessaire pour ce projet. Le jeu utilise uniquement les bibliothèques standard de C++ (`iostream`, `array`, `cstdlib` et `ctime`).

## Organisation du code

Le code est organisé en deux dossiers principaux :

### Dossier `include`

- `Player.hpp` : Déclare la structure `Player`, représentant un joueur avec un nom et un symbole, et le prototype de la fonction `create_player()`.
- `Game.hpp` : Contient les déclarations des fonctions liées au jeu lui-même, telles que l'affichage du plateau (`draw_game_board(std::array<char, 9> game_board)`), la vérification de la victoire (`check_win(std::array<char, 9> game_board, char symbol)`), et les modes de jeu qui sont donc deux joueurs (`two_players()`) et un joueur contre l'IA (`player_vs_AI()`).
- `Launcher.hpp` : Déclare les fonctions de démarrage (`boot()`) et de redémarrage du jeu (`play_again()`).

### Dossier `src`

- `Player.cpp` : Implémente la fonction `create_player()` qui permet de créer un joueur en demandant son nom et son symbole (j'ai imposé obligatoirement X ou O).
- `Game.cpp` : Contient les fonctions principales du jeu :
  - `draw_game_board()` : Affiche l'état actuel du plateau.
  - `check_win()` : Vérifie si un joueur a gagné en fonction de la disposition des symboles sur le plateau. J'ai choisi de faire un tableau avec toutes les positions gagnantes possibles car c'est ce qui m'est venu en premier et que pour une grille 3x3 cela ne m'a pas semblé déraisonnable.
  - `two_players()` : Gère la logique d'un jeu à deux joueurs.
  - `player_vs_AI()` : Gère la logique d'un jeu contre l'IA.
- `Launcher.cpp` : Gère le démarrage du jeu et la possibilité de rejouer une fois une partie terminée.
- `main.cpp` : Contient le point d'entrée principal du programme, appelant la fonction `boot()` pour démarrer le jeu.

J'ajoute que j'ai mis des commentaires dans mon code, ce qui peut donner plus d'indications sur ce que j'ai fait si besoin.

## Fonctionnalités supplémentaires

Il n'y a pas à proprement parler de fonctionnalités supplémentaires. Étant donné l'existence d'autres projets à faire en parallèle, j'ai préféré me concentrer sur l'essentiel requis pour ce projet. Par ailleurs, j'ai rencontré quelques difficultés qui m'ont ralenti et qui m'ont ainsi conforté dans cette décision (voir [section suivante](#problèmes-rencontrés-et-solutions)). Je ne suis de plus pas familier avec les librairies et les interfaces graphiques, et je n'avais pas le temps de les comprendre.

J'ai tout de même ajouté quelque chose qui n'était pas demandé et qui est contenu dans la fonction `play_again()`, qui permet, à la fin d'une partie, de demander au(x) joueur(s) s'il(s) souhaite(nt) continuer à jouer en relançant une nouvelle partie ou bien s'il(s) souhaite(nt) arrêter le jeu. Il s'agit d'une fonction simple reprenant modèle sur `boot()` et qui ne nécessite donc pas plus d'explications.

## Problèmes rencontrés et solutions

### Validation des entrées utilisateur
Au début du projet, il y avait des problèmes avec la validation des entrées utilisateurs, notamment lorsqu'un joueur entrait une valeur incorrecte pour le choix du symbole ou pour une case sur le plateau. J'ai ajouté une validation robuste avec des boucles `do-while` et des vérifications sur les entrées de l'utilisateur pour m'assurer que les valeurs sont correctes (X, O, ou des numéros entre 1 et 9).

### Logique de l'IA
L'IA dans ce projet est simple : elle choisit une case aléatoire parmi celles qui sont encore disponibles. Bien que basique en apparence, cette partie m'a donnée du fil à retordre car je pensais simplement reprendre le code du mode deux joueurs en remplaçant un joueur par l'IA mais je me suis rendu compte que cette approche ne fonctionnerait pas et qu'il fallait revoir la logique de gestion des tours de jeu. 

### Clarté du code
Je me suis aussi rendu compte à ce moment là que mon code aurait mérité plus de clarté, puisqu'en navigant entre les différentes fonctions de `Game.cpp` je me perdais souvent au milieu de toutes ces lignes. Là j'ai compris que l'indentation et les couleurs de l'éditeur de code ne suffisait pas à le rendre clair quand les fonctions sont de plus en plus détaillées. J'ai pensé à éventuellement découper les grosses fonctions avec dedans des sous-fonctions communes mais je n'ai pas exécuté mon idée pour déjà me concentrer sur la réalisation d'un programme fonctionnel.

### Placements des #include
Ici, ce n'est pas un problème en soi mais plutôt un oubli. En organisant les fichiers avec les `.hpp` et les `.cpp`, j'ai au début effectivement oublié d'inclure certains fichiers à d'autres ou parfois je ne mettais pas le bon chemin. Il fallait aussi penser à les inclure au bon endroit et uniquement là où c'est nécessaire. J'ai aussi utilisé des fonctions nécessitant les bibliothèques standard de C++ et j'ai au départ oublié d'en inclure certaines comme `cstdlib`. Au final, vérifiant à chaque fois comment était exécuté le programme, je me suis vite rendu compte de ces oublis.

## Conclusion

Je trouve que ce projet de jeu de TicTacToe en C++ est une bonne introduction à la gestion de la logique de jeu. Il montre aussi comment organiser le code en différents fichiers.

Je suis satisfait du résultat obtenu, bien que certaines optimisations doivent rester à explorer pour parfaire mes compétences. Je regrette juste de ne pas avoir eu le temps d'ajouter des améliorations au jeu de base et peut-être aussi de ne pas avoir créé plus de sous-fonctions pour la lisibilité.

J'ai identifié les points où je dois progresser, notamment dans l'organisation et la clarté du code et des fichiers, ainsi que dans la compréhension de la logique du jeu.
