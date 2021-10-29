# get_next_line_exam42

#int  ft_strlen(char *str)
--> strlen basique

#int  is_line(char *save)
--> renvoie l'index du caractère '\n'
--> renvoie -1 si il n'y a pas de '\n'
--> renvoie -2 si save n'existe pas

#char ft_errors(char *save)
--> free save si il existe
--> renvoie NULL

#char *get_line(char *save)
--> Renvoie la ligne contenue dans save (de l'index 0 au '\n')
--> Si il y a un '\n', le rajoute en fin de ligne
--> Si save est vide renvoie NULL

#static char *join(char *save, char *tmp, int lu)
--> Concatene save et tmp dans new
--> Renvoie new
! pour la boucle qui copie tmp, utilise j < lu comme condition d’arrêt car si il y a moins de caractères lu que la taille du buffer cela pose problème.

#static char *update(char *save)
--> Met à jour save en supprimant la ligne (de l'index 0 ou '\n')
--> Si il n'y a plus de ligne, vérifie si save existe pour le free (avec la valeur de retour de get_line), puis renvoie NULL.

#char get_next_line(int fd)
--> Verifie si fd existe, si BUFFER_SIZE est positif et si le fichier est lisible
--> Créer une variable tmp qui sera utiliser pour le buffer. Elle est créer après avoir regarder si BUFFER_SIZE est positif pour éviter le probleme de taille négative en déclaration.
--> if qui regarde si il y a bien une ligne dans ma statique. Si oui il ne rentre pas, si non il rentre dans la boucle.
    --> boucle qui va concatener save et tmp jusqu'à trouver une ligne ou que save n'existe plus.
--> Copie la ligne dans line grace à get_line.
--> Si line == NULL utilise ft_errors pour free save et renvoie NULL.
--> Met à jour save grace à update_line
--> renvoie la ligne
