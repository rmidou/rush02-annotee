/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_deux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 14:27:26 by nbiron            #+#    #+#             */
/*   Updated: 2023/07/31 15:17:06 by nbiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "header.h"
//supprime les carcateres qu'on lui demande et partant du debut
char	*suppr(char *str, int nb)
{
	int		i;
	char	*tab;
	int		fin;
	char	*tabb;
	int		j;

	j = 0;
	tabb = malloc(sizeof(char) * 2);//cree un tableau de taille 2
	tabb[0] = '0';
	fin = 0;
	i = 0;
	tab = malloc(sizeof(char) * (ft_strlen(str) + 1));//cree un tableau de la taille du parametre str
	while (str[i])//boucle qui icremente les valeurs sans celle qu on demande 
	{
		if (i > (nb - 1) && str[i] != '0')
			fin = 2;
		if (fin == 2 && i > (nb - 1))
		{
			tab[j] = str[i];
			j++;
		}
		i++;
	}
	return (suppr_two(i, fin, tab, tabb));//appel de la suite de la fonction
}
//suite fonctions qui va renvoyer si il reste que des zeros 
char	*suppr_two(int i, int fin, char *tab, char *tabb)
{
	tab[i] = '\0';
	while (tab[i])
	{
		if (tab[i] != '0')
			fin = 1;
		i++;
	}
	if (fin == 0)
		return (tabb);//renvoie un tableau qui contient que un zero si il contient que des zeros
	return (tab);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0' || s2[i] != '\0'))
	{
		i++;
	}
	return (s1[i] - s2[i]);
}
//len d une structure
int	t_nombres_len(t_nombres *str)
{
	int	i;

	i = 1;
	while (str[i].x)
		i++;
	return (i);
}
//fonctions qui qppel les fonctions qui affiche par rapport a la taille de nombres
void	ft_putnbr(char *nbr, t_nombres *dico)
{
	if (ft_strlen(nbr) == 1)
		len_un(nbr, dico);
	else if (ft_strlen(nbr) == 2)
	{
		len_inf(nbr, dico);
	}
	else
	{
		len_sup_un(nbr, dico);
	}
}
