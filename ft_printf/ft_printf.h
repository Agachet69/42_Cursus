/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 16:08:07 by agachet           #+#    #+#             */
/*   Updated: 2021/05/26 18:28:31 by agachet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_printf
{
	char		car;
	char		*struc;
	int			i;
	long int	stockstar;
	long int	stockzero;
	long int	stockmoins;
	long int	stockspaces;
	long int	stockprecision;
	int			compteur_putnbr;
	int			putnbr_zero;
	int			pourcent;
	int			ireturn;
	int			cas_zero_c;
}				t_printf;

int				ft_printf(const char *str, ...);
int				ft_checkstr(t_printf *res, va_list ap);
void			ft_check_flag(t_printf *res);
int				ft_searchtype(const char *str, t_printf *res, va_list ap);
void			ft_search_arg(const char *str, t_printf *res, va_list ap);
void			ft_putnbr_base(t_printf *res, int nbr, char *base);
int				ft_strlen(char *src);
int				ft_putchar(char c, t_printf *res);
void			ft_putnbr(t_printf *res, int nb);
void			ft_putun_base(t_printf *res, unsigned long int nbr, char *base);
void			ft_putstr_calloc(t_printf *res, char *str);
void			ft_affadresse(t_printf *res, unsigned long chaine, char *base);
char			*ft_adresse_zero_x();
char			*ft_calloc(int count, int size);
void			ft_bzero(void *s, int n);
void			ft_putchar_calloc(t_printf *res, char c);
int				ft_atoi(const char *str, t_printf *res);
int				ft_atoim(const char *str, t_printf *res);
void			ft_initstruct(t_printf *res);
void			ft_search_arg(const char *str, t_printf *res, va_list ap);
char			*ft_checknbr(int nbr, int compteur, t_printf *res);
void			ft_do_zero(t_printf *res);
char			*ft_strfjoinz(char *s1, char *s2, int mode);
char			*ft_strjoin_zero(char *s1, char *s2);
char			*ft_cz(int i, t_printf *res);
void			ft_do_spaces(t_printf *res);
char			*ft_strfjoin_spaces(char *s1, char *s2, int mode);
char			*ft_strjoin_spaces(char *s1, char *s2);
char			*ft_create_str_spaces(int i);
void			ft_do_star(t_printf *res);
void			ft_do_moins(t_printf *res);
void			ft_do_precision(t_printf *res);
int				ft_specials(t_printf *res);
char			*ft_chaine_vide(t_printf *res);
char			*ft_substr(char *s, int i);
void			ft_putstr(char *s);
void			ft_re_zero(t_printf *res);
int				ft_boolean(char c);
void			ft_for_star_moins(va_list ap, t_printf *res, const char *str);
void			ft_for_star_zero(va_list ap, t_printf *res, const char *str);
int				ft_boolean_bis(t_printf *res);
void			ft_star_moins(t_printf *res);
char			*ft_ck_uns(unsigned long int nbr, int compteur, t_printf *res);
void			ft_putchar_calloc_pourcent(t_printf *res);

#endif
