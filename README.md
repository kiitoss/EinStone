# Ein Stone
***
Ein Stone est un jeu inspiré du célèbre Plants VS Zombies. Un joueur affronte au choix, soit l'ordinateur, soit une autre joueur, le but est de survivre aux différentes vagues d'ennemis en achetant des alliés et en les posant sur le terrain.

## Architecture des fichiers
Le projet est très largement inspiré du modèle MVC sans pour autant respecter strictement les conventions.

### Model
Le modèle comporte toutes les fonctions propores aux différentes structures du projet (hors fonctions de dessin). Chaque fichier '.c' du dossier 'models' pourrait être associé à une classe avec les différentes méthodes de cette dernière.

### View
La vue contient toutes les fonctions propres au dessin du jeu.
La vue n'affecte en aucune façon les valeurs du jeu, son rôle est uniquement de déssiner les différents objets sur le plateau.
La vue est aussi en charge de récupérer les actions de l'utilisateur pendant le jeu. Elle retourne ensuite au contrôleur l'action effectuée, sans jamais ni modifier, ni chercher à comprendre la signification d'une action. Cela est resté à la charge du contrôleur.

### Controller
Le contrôleur va organiser l'actualisation des différents éléments du jeu.
Après une action du joueur, le contrôleur en déduit l'action à effectuer, et met à jour tous les objets du jeu.


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