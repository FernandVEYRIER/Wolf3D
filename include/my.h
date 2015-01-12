/*
** libmy.h for lib in /home/veyrie_f/rendu/Piscine_C_J09
**
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
**
** Started on  Thu Oct  9 12:45:34 2014 fernand veyrier
** Last update Mon Dec  8 00:19:18 2014 fernand veyrier
*/

#ifndef MY_H_
# define MY_H_

int		my_putchar(char c);
int		my_isneg(int nb);
int		my_put_nbr(int nb);
int		my_swap(int *a, int *b);
int		my_putstr(char *str);
int		my_strlen(char *str);
int		my_getnbr(char *str);
void		my_sort_int_tab(int *tab, int size);
int		my_power_rec(int nb, int power);
int		my_square_root(int nb);
int		my_is_prime(int nombre);
int		my_find_prime_sup(int nb);
char		*my_strcpy(char *dest, char *src);
char		*my_strncpy(char *dest, char *src, int nb);
char		*my_revstr(char *str);
char		*my_strstr(char *str, char *to_find);
int		my_strcmp(char *s1, char *s2);
int		my_strncmp(char *s1, char *s2, int nb);
char		*my_strupcase(char *str);
char		*my_strlowcase(char *str);
char		*my_strcapitalize(char *str);
int		my_str_isalpha(char *str);
int		my_str_isnum(char *str);
int		my_str_islower(char *str);
int		my_str_isupper(char *str);
int		my_str_isprintable(char *str);
int		my_showstr(char *str);
int		my_showmem(char *str, int size);
char		*my_strcat(char *dest, char *src);
char		*my_strncat(char *dest, char *src, int nb);
int		my_strlcat(char *dest, char *src, int size);
char		**my_str_to_wordtab(char *str);
int		my_show_wordtab(char **tab);
char		*my_strdup(char *str);
char		*convert_base(char *nbr, char *base_from, char *base_to);
int		my_getnbr_base(char *str, char *base);
unsigned int	my_putnbr_base(unsigned int nbr, char *base);
unsigned long	my_putnbr_base_long(unsigned long nbr, char *base);
int		my_put_nbr_float(float nb);
int		my_put_nbr2(unsigned int nb);
int		my_printf(char *str, ...);

#endif /* !MY_H_ */
