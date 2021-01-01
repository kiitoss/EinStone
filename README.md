# Ein Stone
***
Ein Stone est un jeu inspiré du célèbre Plants VS Zombies. Un joueur affronte au choix, soit l'ordinateur, soit un autre joueur, le but est de survivre le maximum de temps à l'invasion ennemie en achetant des alliés et en les posant sur le terrain.





## Architecture des fichiers
Le projet est très largement inspiré du modèle MVC sans pour autant respecter strictement les conventions.
Le projet se subdivise en 4 grandes parties:
* GUI: la partie qui concentre la création de boutons/inputs/labels et qui les gères.
* menu: la partie qui se concentre sur la gestion du menu, en se servant notamment de la partie GUI.
* game: la partie qui gère le jeu.
* save: la partie qui gère la sauvegarde des scores et des parties sauvegardées.

Chaque partie est développé dans la même logique, mais l'organisation des différents modules/dossiers estt différente. Le but étant de limiter la taille des fichiers pour une lecture améliorée du code source.



### GUI
La partie GUI comporte simplement 4 fichiers: button.c, input.c, label.c et general.c.
button.c, input.c et label.c contiennent les fonctions de dessin des éléments, mais aussi de création et de gestion.
C'est ici qu'on trouvera les fonctions permettant de rendre un élément *hover* ou *select*.
Le fichier general.c est légerement différent, il comporte les fonctions affectant plusieurs éléments différents. On aura par exemple ici la fonction permettant d'affecter une taille de police optimale pour un objet donné, ou encore la fonction permettant de dessiner soit un input, soit son label correspondant selon les action de l'utilisateur.
C'est aussi dans le fichier general.c que l'on retrouve la redefinition des structures MLV_List, _MLV_list, _MLV_Input_box. Cela nous permet de récupérer la valeur d'un input sans que le joueur n'ai besoin de valider l'inptu en cliquant sur la touche <Entré>.



### MENU
La partie MENU se décompose en 3 sous dossiers (controllers/methods/views) et un fichier menu.c.
Chaque page du menu est en fait un objet, une structure en C.
L'objet Main_Page comprend un label (le titre) et 4 boutons: "New Game", "Resume", "Scores", "Quit" ainsi qu'un pointeur sur l'un de ses boutons: "hover_btn".
Cette logique permet de savoir en permanence le bouton survolé par l'utilisateur, ce qui permet de redessiner la page uniquement sur le "hover_btn" change.

#### controllers
Dans le dossier controllers se trouve simplement 4 fichiers correspondant aux 4 pages. Chaque fichier gère les actions de l'utilisateur, le changement de page, la préparation au lancement du jeu etc...

#### methods
Le dossier methods comprend là aussi 4 fichiers, chacun responsable des méthodes d'une page.
Les fichiers les plus basiques comprennent les fonctions d'initialisation des pages (création des objets aux bonnes positions) et les fonctions permettant de retourner le bouton survolé de la page.
Les fichiers plus complexes possèdent en plus les fonctions permettant par exemple de transformer l'input d'une page en label.

#### views
Le dossier views ne comporte en réalité qu'un seul fichier draw_menu.c. Ce fichier est constitué des fonctions permettant de dessiner chaque page du menu, essentiellement en appelant les fonctions de dessin du dossier GUI.
C'est aussi dans la vue que l'on retrouve la fonction get_event() permettant de retourner l'action de l'utilisateur sur une page.

#### menu.c
Le fichier menu.c est le point d'entrée du programme. C'est ici que se trouve la fonction main(), que le gestionnaire de sons est initialisé et que la fenêtre est créée.



### GAME
La partie GAME se décompose encore une fois en 3 sous dossiers (controllers/initializers/views) et d'un fichier game.c
Le jeu est logiquement composé d'une multitudes de structures différentes, reliés entres-elles dans une structure très importante: Game_Manager.
Une partie entière est consacré aux structure plus bas dans le document.

#### controllers
Dans le dossier controllers se trouve les fichiers permettant de gérer les principales structures du projet, notamment les alliés avec le fichier friend.c, les ennemies avec enemy.c, le joueurs, les lignes du terrain etc...

#### initializers
Comme son nom l'indique, le dossier initializers contient les fonctions d'initialisation des structures.

#### views
Le dossier views comporte le fichier chargé de dessiner le jeu, qui va faire appel aux fonctions des deux autres fichiers de la vue, draw_objects pour dessiner les alliés, les ennemies, les flèches etc.. et draw_window pour dessiner la fenêtre, les spawners, le terrain etc...

#### game.c
Le fichier game.c est le fichier principal du jeu. C'est ici que l'on retrouvera les fonctions en charge d'interpréter les actions de l'utilsiateurs et d'appeler les bonnes fonctions après un clique, une touche du clavier etc...
C'est ce fichier qui met à jour les éléments du jeu en permanence.



### SAVE
La partie SAVE permet de gérer les sauvegardes.
Constitué d'un seul et unique fichier, on y retrouve les fonctions permettant de sauvegarder une partie, l'ajouter dans les scores, retourner une liste d'objets Game_Manager correspondant aux parties sauvegardées.





## Convention de nommage des fonctions

### Les fonctions *...*_init(*paramètres*)
Les fonctions *..._init(paramètres)* retourne une structure initialisée.

### Les fonctions get_new_*...*(*paramètres*)
Ce type de fonctions créé et retourne une nouvelle structure initialisée.

### Les fonctions set_*...*(*paramètres*)
Ce type de fonctions met à jour certaines valeurs d'une structure. Rien n'est retourné.

### Les fonctions get_*...*(*paramètres*)
Similaire aux fonctions *get_new...(paramètres)* mais sans pour autant être spécifique aux structures. Retourne une structure, une variable, un pointeur...

### Les fonctions update_*...*(*paramètres*)
Les fonctions de mise à jour se retrouvent dans les contrôleurs et vont appeler un certain nombre de fonctions. Rien n'es retourné.

### Les fonctions is_*...*(*paramètres*)
Vérifie une condition et retourne une variable booléenne vrai ou faux.





## Structures