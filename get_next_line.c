/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codecham <codecham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:44:07 by codecham          #+#    #+#             */
/*   Updated: 2021/10/29 15:15:53 by codecham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int			ft_strlen(char *str)
{
	int i;

	i = 0;
	if(!str)
		return(0);
	while(str[i])
		i++;
	return(i);

}

int			is_line(char *save)		// Renvoie l'index du caractere '\n' ou un nombre négatif si la string n'existe pas ou ne possède pas de ligne
{
	int i;

	i = 0;
	if (!save)
		return(-2);
	while (save[i])
	{
		if (save[i] == '\n')
			return(i);
		i++;
	}
	return(-1);
}

char 		*ft_error(char *save) // Free save et renvoie NULL
{
	if(save)
		free(save);
	return(NULL);
}

char		*get_line(char *save)	// Renvoie la ligne contenue dans save
{
	int		i;
	char	*new;

	i = 0;
	while(save && save[i] && save[i] != '\n')
		i++;
	if (is_line(save) >= 0)
		i++;
	if(i == 0)
		return(NULL);
	new = (char *)malloc(sizeof(char) * i + 1);
	if(!new)
		return(NULL);
	i = 0;
	while(save && save[i] && save[i] != '\n')
	{
		new[i] = save[i];
		i++;
	}
	if (is_line(save) >= 0)
	{
		new[i] = '\n';
		i++;
	}
	new[i] = '\0';
	return(new);
}

static char	*join(char *save, char *tmp, int lu) // Concatene save et tmp
{
	int i;
	int j;
	char *new;

	i = ft_strlen(save);
	j = 0;
	new = (char *)malloc(sizeof(char) * i + lu + 1);
	if (!new)
		return(NULL);
	i = 0;
	while (save && save[i])
	{
		new[i] = save[i];
		i++;
	}
	while (j < lu)
	{
		new[i + j] = tmp[j];
		j++;
	}
	new[i + j] = '\0';
	if(save)
		free(save);
	return(new);
}

static char *update_line(char *save) // Supprime le début de la string jusqu'au '\n'
{
	char	*new;
	int		i;
	int		j;

	i = is_line(save);
	j = 0;
	if (i < 0)
	{
		if (i == -1)
			free(save);
		return (NULL);
	}
	new = (char *)malloc(sizeof(char) * ft_strlen(save) - i + 1);
	if (!new)
		return(NULL);
	i++;
	while(save[i + j])
	{
		new[j] = save[i + j]; 
		j++;
	}
	new[j] = '\0';
	if(save)
		free(save);
	return(new);
}

/*
	save: 	String statique pour stocker la lecture du read
	line: 	String qui contiendra la ligne à renvoyée
	tmp:	String utilisée pour le read
	lu:		Integer pour stocker le résultat du read
*/

char		*get_next_line(int fd)
{
	static char *save;
	char 		*line;
	int			lu;
	
	line = NULL;
	lu = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, line, 0) < 0)
		return(ft_error(save));
	char tmp[BUFFER_SIZE + 1]; 
	if (is_line(save) < 0) 
	{
		while (is_line(save) < 0 && (lu = read(fd, tmp, BUFFER_SIZE)))
		{
			save = join(save, tmp, lu);
			if (!save)
				return(ft_error(save));
		}
	}
	line = get_line(save);
	if(line == NULL)
		return(ft_error(save));
	save = update_line(save);
	return(line);
}