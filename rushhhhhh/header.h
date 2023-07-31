/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 16:02:59 by nbiron            #+#    #+#             */
/*   Updated: 2023/07/30 21:22:25 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

typedef struct s_nombres
{
	char	*x;
	char	*y;
}		t_nombres;
char		**ft_transfert(char *nom_fichier);
char		*last_words(char *str);
char		*first_word(char *str);
void		ft_putchar(char c);
t_nombres	*str_to_struct(char **dico);
void		ft_putnbr(char *nbr, t_nombres *dico);
char		*ft_strcat(char *dest, char src);
int			ft_strlen(char *str);
void		ft_putnbr(char *nbr, t_nombres *dico);
void		ft_putstr(char *str);
char		*ft_strncat(char *dest, char *src, unsigned int nb);
int			ft_strncmp(char *s1, char *s2, unsigned int n);
char		*suppr(char *str, int nb);
int			ft_strcmp(char *s1, char *s2);
int			t_nombres_len(t_nombres *str);
void		ft_putnbr(char *nbr, t_nombres *dico);
void		len_sup_un(char *str, t_nombres *structure);
void		len_un(char *str, t_nombres *structure);
void		len_inf(char *str, t_nombres *structure);
void		ft_taille_ligne(int nb_ligne, char **dico, int *len_ligne);
char		ft_error(int argc, char **argv);
char		*ft_atoa(char *str);
char		*ft_atoa_two(char *str, int i, char *nbr);
void		len_inf_two(int i, int fin, char *str, t_nombres *structure);
void		len_sup_un_two(char *str, t_nombres *structure, int diff, int i);
char		*suppr_two(int i, int fin, char *tab, char *tabb);

#endif
