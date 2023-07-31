/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionnaire.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 10:50:15 by nbiron            #+#    #+#             */
/*   Updated: 2023/07/31 14:13:14 by nbiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "header.h"

char	*ft_strcat(char *dest, char src)
{
	int	i;

	i = 0;
	while (dest[i] != '\0')
		i++;
	dest[i++] = src;
	dest[i] = '\0';
	return (dest);
}
//cree tableau qui va contenir la taille de chaque ligne
void	ft_creationtab(char **dico, int nb_ligne, char *nom_fichier)
{
	char	tab[1];
	int		*len_ligne;
	int		ligne;
	int		taille;
	int		desc1;

	ligne = 0;
	taille = 0;
	desc1 = open(nom_fichier, O_RDONLY);//on ouvre le fichier
	len_ligne = malloc (sizeof(int) * nb_ligne);// creer un tableau qui va contenir la taille de chaque ligne
	while (read(desc1, tab, 1))//parcourir fichier
	{
		if (tab[0] == '\n')//a chaque saut de ligne on ajoute a len_ligne la taille de chaque ligne
		{
			len_ligne[ligne] = taille;
			taille = 0;
			ligne++;
		}
		else
			taille++;//compter la taille de chaque ligne
	}
	close(desc1);//fermer le fichier
	ft_taille_ligne(nb_ligne, dico, len_ligne);//appel de la fonction taille ligne qui va creer les sous tableau du grand tableau
}

//fonction qui cree sous tableau de la bonne taille
void	ft_taille_ligne(int nb_ligne, char **dico, int *len_ligne)
{
	int	ligne;

	ligne = 0;
	while (ligne != nb_ligne)//boucle qui va parcourir le grand tableau en allouant la onne taille a chaque petit tableau
	{
		dico[ligne] = malloc(sizeof(char) * len_ligne[ligne]);//allocation de la taille optimale de chaque sous tableau
		ligne++;
	}
}
//fonction qui rempli les sous tableau
void	ft_remplissage(char **dico, char *nom_fichier)
{
	int		ligne;
	int		desc;
	char	tab[1];

	ligne = 0;
	desc = open(nom_fichier, O_RDONLY);//ouverture fichier
	while (read(desc, tab, 1))//parcours fichier
	{
		if (tab[0] == '\n')//des qu'on est a la fin d une ligne on change de sous tableau
			ligne++;
		else
			ft_strcat(dico[ligne], tab[0]);//incremente chaque caractere dans les sous tableau
	}
	close(desc);//ferme le fichier
}
//cette fonctiosn permet de transferer le contenue du fichier ver un tableau de tableau
char	**ft_transfert(char *nom_fichier)
{
	char	**dico;
	int		desc;
	char	tab[1];
	int		nb_ligne;
						
	nb_ligne = 0;
	desc = open(nom_fichier, O_RDONLY);//on ouvre le fichier
	while (read(desc, tab, 1))//on lis caractere par caractere
	{
		if (tab[0] == '\n')//compter nombre de ligne
			nb_ligne++;
	}
	close(desc);//fermer fichier
	dico = malloc(sizeof(char *) * (nb_ligne));//creer grand tableau qui va coontenir chaque ligne du fichier dans des petits tableau
	ft_creationtab(dico, nb_ligne, nom_fichier);//lancer fonction creationtab
	ft_remplissage(dico, nom_fichier);//remplir sous tableau
	return (dico);
}
