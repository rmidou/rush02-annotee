/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 10:27:41 by nbiron            #+#    #+#             */
/*   Updated: 2023/07/31 15:05:56 by nbiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "header.h"
//fonction qui affiche en lettre le nombre si sa taille est de 1 (chiffre de 1 a 9)
void	len_un(char *str, t_nombres *structure)
{
	int	i;

	i = 1;
	while (i <= 9)//donction qui parcours le tableau de structure et qui compare a notre nombre
	{
		if (ft_strcmp(str, structure[i].x) == 0) // si on trouve le nombres dans le tableau de structure 
			ft_putstr(structure[i].y);//on l'affiche
		i++;
	}
}
//si le nombre a une taille de 2 (entre 10 et 99) 
void	len_inf(char *str, t_nombres *structure)
{
	int		i;
	int		fin;

	fin = 0;
	i = 9;
	while (i <= 19 && fin != 1)//tant que i < 19 (tant qu'on est avec des chiffre en dessous de 20)
	{
		if (ft_strcmp(str, structure[i].x) == 0)//si la structure et egale au nombre alors on affiche le nombre
		{
			ft_putstr(structure[i].y);//affichage du nombre
			fin = 1;//sortit boucle
		}
		i++;
	}
	len_inf_two(i, fin, str, structure);//execute la deuxieme parti de la fonctions
}
//deuxieme partie de la fonction
void	len_inf_two(int i, int fin, char *str, t_nombres *structure)
{
	if (fin == 0)//on l'execute que si on a rien afficher a l etape d avant
	{
		while (i <= 28)//tant que on est dans les dizaines (20,30,40 ... 90)
		{
			if (ft_strncmp(str, structure[i].x, 2) == 0)//si on la dizaine et egale au nombre
				ft_putstr(structure[i].y);//on affiche la dizaine
			else if (ft_strncmp(str, structure[i].x, 1) == 0)//si la dizaine et juste mais pas les unitee
			{
				ft_putstr(structure[i].y);//on affiche la dizaine
				ft_putchar(' ');//on affiche un espace
				ft_putnbr(suppr(str, 1), structure);//on rappel recursivement la fonction putnbr avec juste l unite
			}
			i++;
		}
	}
}
//fonctions qui affiche si la taille du nombre et superieur ou egale a 3 (100 et au dessus)
void	len_sup_un(char *str, t_nombres *structure)
{
	int		i;
	int		diff;

	diff = 0;
	i = t_nombres_len(structure) - 1;
	while (ft_strlen(structure[i].x) > ft_strlen(str))
		i--;
	if (ft_strlen(structure[i].x) == ft_strlen(str))
	{
		if (ft_strncmp(str, structure[i].x, ft_strlen(structure[i].x)) == 0)
		{
			ft_putstr("one ");
			ft_putstr(structure[i].y);
			diff = 1;
		}
	}
	len_sup_un_two(str, structure, diff, i);
}

void	len_sup_un_two(char *str, t_nombres *structure, int diff, int i)
{
	char	*tab;

	if (diff == 0)
	{
		tab = malloc(sizeof(char) * ft_strlen(str));
		diff = ft_strlen(str) - ft_strlen(structure[i].x) + 1;
		ft_strncat(tab, str, diff);
		ft_putnbr(tab, structure);
		free (tab);
		ft_putchar(' ');
		ft_putstr(structure[i].y);
		ft_putchar(' ');
		ft_putnbr(suppr(str, diff), structure);
	}
}
