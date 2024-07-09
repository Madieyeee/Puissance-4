        ##Projet : Puissance 4 ++
        
Le projet se nomme Puissance 4 comme le jeu original, mais avec des fonctionnalités supplémentaires pour enrichir l'expérience de jeu. Voici une description complète du projet intégrant toutes les modifications et ajouts.

        ##Fonctionnalités
        
  1) Identification des Joueurs
    - Chaque joueur doit s'identifier en fournissant un nom et un mot de passe.
    - Chaque utilisateur possède un identifiant unique.
  2) Connexion des Joueurs
    - Pour commencer une partie, deux utilisateurs doivent être connectés.
  3) Règles de Jeu
    - Les joueurs jouent à tour de rôle selon les règles classiques de Puissance 4.
    - La partie se termine lorsque l'un des joueurs aligne quatre jetons horizontalement, verticalement ou en diagonale, ou lorsque la grille est remplie sans qu'aucun joueur n'ait aligné quatre jetons (match nul).
  4. Enregistrement des Scores
    -  Les résultats des parties sont enregistrés et mis à jour dans trois tableaux : gagnants, perdants et nuls.
    - Tableau des gagnants : Liste des joueurs avec le nombre de victoires.
    - Tableau des perdants : Liste des joueurs avec le nombre de défaites.
    - Tableau des nuls : Liste des joueurs avec le nombre de matchs nuls.
  5) Meilleur Gagnant et Pire Perdant
  - Meilleur Gagnant : Le joueur avec le plus grand nombre de victoires. En cas d'égalité de victoires, le joueur ayant remporté une partie avec le moins de coups joués est considéré comme le meilleur gagnant. Si une égalité persiste, le joueur ayant atteint cet exploit en premier est considéré comme le meilleur gagnant.
  - Pire Perdant : Le joueur qui a perdu une partie avec le moins de coups joués.
  6) Gestion des Joueurs après une Partie
  - Un joueur perdant ne peut pas rejouer immédiatement contrairement au gagnant, qui peut continuer à jouer autant de fois qu'il le souhaite jusqu'à  ce qu'il perde ou décide de quitter.
  - Un joueur qui a joué jusqu'à ce que les boules occupent 20 cellules peut rejouer après que deux matchs aient été joués par d'autres joueurs.
  - Un joueur gagnant n'a pas besoin de se reconnecter pour rejouer, car il est déjà connecté. Cependant, son adversaire perdant est déconnecté immédiatement après la partie.
  - Un joueur ne peut pas quitter sans que la partie en cours se termine.
  7) Fin de la Session de Jeu
  - Lorsqu'un utilisateur décide de quitter, le jeu affiche les statistiques suivantes :
    ▪ Tableau des gagnants : Liste des joueurs avec le nombre de victoires.
    ▪ Tableau des perdants : Liste des joueurs avec le nombre de défaites.
    ▪ Tableau des nuls : Liste des joueurs avec le nombre de matchs nuls.
    ▪ Meilleur gagnant : Le joueur avec le plus grand nombre de victoires, avec des critères de dénouement en cas d'égalité.
    ▪ Pire perdant : Le joueur ayant perdu une partie avec le moins de coups joués.
