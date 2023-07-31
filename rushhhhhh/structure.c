/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:55:21 by nbiron            #+#    #+#             */
/*   Updated: 2023/07/31 14:25:59 by nbiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "header.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
//compte nombre de sous tableau
int	ft_strlenn(char **str)
{
	int	i;

	i = 0;
	while (str[i] != (void *)0)
	{
		i++;
	}
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	count;

	count = 0;
	while (src[count] != '\0')
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = '\0';
	return (dest);
}
//renvoie un tableau de structures de type t_nombres
t_nombres	*str_to_struct(char **dico)
{
	char		*temp;
	int			i;
	t_nombres	*tab;//initialise un tableau de structure de type t_nombres (tableau qui va etre renvoyee)

	tab = malloc(sizeof(t_nombres) * ft_strlenn(dico));//allocation de la bonne taille au tableau de structure
	i = 0;
	while (dico[i])//parcours du grand tableau et transfert les chaines de caractere vers des structures
	{
		temp = malloc(sizeof(char) * ft_strlen(dico[i]));//creation tableau temporaires
		ft_strcpy(temp, dico[i]);//copie le sous tableau de dico dans le tableau temporaire temp
		tab[i].x = first_word(temp);//fonction qui recup les nombres de chaque ligne et le met dans une structure
		tab[i].y = last_words(temp);//fonction qui recupere les nombres en lettres et le met dans une structure
		free (temp);//supprimer tableau temporel
		i++;
	}
	return (tab);
}
