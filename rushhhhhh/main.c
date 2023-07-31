/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 16:26:32 by nbiron            #+#    #+#             */
/*   Updated: 2023/07/31 14:40:09 by nbiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "header.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	argc_2(char **argv)
{
	t_nombres	*dico;
	char		*nb;
	int			fin;
	char		tab[1];

	fin = 0;
	tab[0] = '0';
	nb = malloc(sizeof(char) * ft_strlen(ft_atoa(argv[1])));//creation du tableau qui va contenir chaque ligne dans des ous tableau
	nb = ft_atoa(argv[1]);//remplissage du tableau cree
	if (ft_strlen(nb) > 18)//si chiffre trop grand = erreur
	{
		write(1, "Arg_Error\n", 10);
		fin = 1;
	}
	if (fin == 0)//si il n'y a pas d erreur
	{
		dico = str_to_struct(ft_transfert("numbers.dict"));//ft_transfert permet de prendre les info du fichier et les transferer vers un tableau de chaine de caractere et str to struct va convertir le grand tableau de chaine de caractere en tableau de structure
		if (nb[0] == tab[0])//si ils ont rentree le nombre 0 affiche zero
			ft_putstr(dico[0].y);
		ft_putnbr(nb, dico);//affiche le nombre
		free (nb);//suppression du tableau appres l'affichage
	}
}

void	argc_3(char **argv)
{
	t_nombres	*dico;
	char		*nb;
	int			fin;
	char		tab[1];

	fin = 0;
	tab[0] = '0';
	nb = malloc(sizeof(char) * ft_strlen(ft_atoa(argv[2])));
	nb = ft_atoa(argv[2]);
	if (ft_strlen(nb) > 18)
	{
		write(1, "Arg_Error\n", 10);
		fin = 1;
	}
	if (fin == 0)
	{
		dico = str_to_struct(ft_transfert(argv[1]));
		if (nb[0] == tab[0])
			ft_putstr(dico[0].y);
		ft_putnbr(nb, dico);
		free (nb);
	}
}

int	main(int argc, char **argv)
{
	if (ft_error(argc, argv) == -1)
		write(1, "Arg_Error\n", 10);
	else if (argc == 2)
		argc_2(argv);
	else if (argc == 3)
		argc_3(argv);
	ft_putchar('\n');
}
