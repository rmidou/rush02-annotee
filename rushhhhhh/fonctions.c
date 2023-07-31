/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 16:51:27 by nbiron            #+#    #+#             */
/*   Updated: 2023/07/31 14:37:14 by nbiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"
//recupere nombre
char	*first_word(char *str)
{
	int		i;
	char	*tab;
	int		count;

	count = 0;
	i = 0;
	if (!str)//si le parametre est vide sa renvoie null
		return (NULL);
	while (str[i] >= 48 && str[i] <= 57)//tant que ces des chiffres on incremente la variable count qui permet de compter la taille du tableau qu'il nous faut pour stocker le nombre
	{
		count++;
		i++;
	}
	tab = malloc(sizeof(char) * count);//creation du tableau de la taille du nombre
	i = 0;
	while (str[i] >= 48 && str[i] <= 57)//incrementation du tableau par le nombre
	{
		ft_strcat(tab, str[i]);
		i++;
	}
	return (tab);//on retourne le nombre sous forme de chaine de caractere
}
//suite de la fonction last words
char	*last_words2(char *str)
{
	int		i;
	char	*tab;
	int		count;

	count = 0;
	i = 0;
	if (!str)
		return (NULL);//si parametre vide on renvoie null
	while (str[i])
		while (str[i] >= 32 && str[i++] <= 127)//on compte le nombre de caractere du nombre en lettre
			count++;
	tab = malloc(sizeof(char) * count);//on creer un tableau de la taille du nombre de caractere
	i = 0;
	while (str[i])//boucle qui incremente le nombre en lettre
	{
		while (str[i] >= 32 && str[i] <= 127)//tant que c un caractere printable on l'ajoute
		{
			ft_strcat(tab, str[i]);
			i++;
		}
	}
	return (tab);//on retourne une chaine de caractere qui contient le nombre en lettre
}
//fonction qui recupere le nombre en lettre
char	*last_words(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (NULL);//si parametre vide on renvoie null
	while (str[i] == 32 || (str[i] >= 48 && str[i] <= 57) || str[i] == 58)//tant que c des espaces , des nombres ou des : on avance dans la chaine de caractere
		i++;
	return (last_words2(&str[i]));//appel de la suite de la fonction
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	i2;

	i = 0;
	i2 = 0;
	while (dest[i] != '\0')
		i++;
	while (src[i2] != '\0' && i2 < nb)
	{
		dest[i + i2] = src[i2];
		i2++;
	}
	dest[i + i2] = '\0';
	return (dest);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && (i < n))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
