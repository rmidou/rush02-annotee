/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erreurs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:41:11 by nbiron            #+#    #+#             */
/*   Updated: 2023/07/31 15:20:29 by nbiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "header.h"
//fonctions qui renvoie un char en enlevant les zeros devant , les witespace et les + et -
char	*ft_atoa(char *str)
{
	int			i;
	int			signe;
	char		*nbr;

	i = 0;
	signe = 1;
	nbr = malloc(sizeof(char) * ft_strlen(str));
	if (!str[i])
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i += 1;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
		{
			signe *= -1;
		}
	}
	return (ft_atoa_two(str, i, nbr));
}
//suite
char	*ft_atoa_two(char *str, int i, char *nbr)
{
	while (str[i] >= '0' && str[i] <= '9')
	{
		ft_strcat(nbr, str[i]);
		i++;
	}
	nbr[i] = '\0';
	i = 0;
	while (nbr[i] == '0')
		i++;
	return (suppr(nbr, i));
}

int	verif_signe(char *str)
{
	int	i;
	int	signe;

	i = 0;
	signe = 1;
	if (!str[i])
		write(1, "Arg_Error\n", 10);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i += 1;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
		{
			signe *= -1;
		}
	}
	return (signe);
}
//fonctions qui renvoie si il y a des erreurs
char	ft_error(int argc, char **argv)
{
	int	signe;

	signe = 0;
	if (argc != 2 && argc != 3)
	{
		write(1, "Arg_Error\n", 10);
		return (-1);
	}
	return (verif_signe (argv[argc - 1]));
}
