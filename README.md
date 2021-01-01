# Ein Stone
***
Ein Stone est un jeu inspiré du célèbre Plants VS Zombies. Un joueur affronte au choix, soit l'ordinateur, soit un autre joueur, le but est de survivre le maximum de temps à l'invasion ennemies en achetant des alliés et en les posant sur le terrain.

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

### MENU
La partie MENU se décompose en 3 sous dossiers (controllers/methods/views) et un fichier menu.c.
Chaque page du menu est en fait un objet, une structure en C.
L'objet Main_Page comprend un label (le titre) et 4 boutons: "New Game", "Resume", "Scores", "Quit" ainsi qu'un pointeur sur l'un de ses boutons: "hover_btn".
Cette logique permet de savoir en permanence le boutons survolé par l'utilisateur, ce qui permet de redessiner la page uniquement sur le "hover_btn" change.

#### controllers
Dans le dossier controllers se trouve simplement 4 fichiers correspondant aux 4 pages. Chaque fichier gère les actions de l'utilisateur, le changement de page, la préparation au lancement du jeu etc...

#### methods
Le dossier methods comprend là aussi 4 fichiers, chacun responsable des méthodes d'une page.
Les fichiers les plus basiques comprennent les fonctions d'initialisation des pages (création des objets aux bonnes positions) et les fonctions permettant de retourner le bouton survolé de la page.
Les fichiers plus complexes possèdent en plus les fonctions permettant par exemple de transformer l'input d'une page en label.

#### views
Le dossier views ne comporte en réalité qu'un seul fichier draw_menu.c. Ce fichier est constitué des fonctions permettant de dessiner chaque page du menu, essentiellement en appelant les fonctions de dessin du dossier GUI.

#### menu.c
Le fichier menu.c est le point d'entrée du programme. C'est ici que se trouve la fonction main(), que le gestionnaire de sons est initialisé et que la fenêtre est créée.







## Convention de nommage des fonctions

### Les fonctions *...*_init(*paramètres*)
Les fonctions *..._init(paramètres)* retourne une structure initialisée.
Ces fonctions se retrouvent dans les modèles.
Retourné: Une structure initialisée.

### Les fonctions get_new_*...*(*paramètres*)
Ce type de fonctions créé et retourne un nouvel objet. On retrouve ces fonctions dans les modèles.
Retourné: le nouvel objet.

### Les fonctions set_*...*(*paramètres*)
Ce type de fonctions met à jour certaines valeurs d'un objet. On retrouve ces fonctions dans les modèles.
Retourné: rien.

### Les fonctions get_*...*(*paramètres*)
Similaire aux fonctions *get_new...(paramètres)* mais sans pour autant être spécifique aux objets. Peut se retrouver dans les contrôleurs, les vues ou les modèles. Ce type de fonction sert à trouver des valeurs.
Retourné: une structure, un objet ou une variable.

### Les fonctions update_*...*(*paramètres*)
Les fonctions de mise à jour se retrouvent dans les contrôleurs et vont dans leur corps appeler diverses méthodes de diverses classes.
Retourné: rien.