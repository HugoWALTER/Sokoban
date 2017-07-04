/*
** my.h for my.h in /home/walter_h/CPool_Day09/include
** 
** Made by Hugo WALTER
** Login   <walter_h@epitech.net>
** 
** Started on  Thu Oct 13 19:38:54 2016 Hugo WALTER
** Last update Wed Dec 21 09:07:11 2016 Hugo WALTER
*/

#ifndef MY_H
# define MY_H

#include <signal.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <curses.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct  s_my_pos
{
  int   x;
  int   y;
  int   nb_line;
  int   x_max;
  int   is_on;
  int   is_on2;
  int   on_end;
  int   valdepo;
  char  **tab;
  char  **save;
  int   taille;
  int   xt;
  int   yt;
  int   stockx;
  int   xp;
  int   yp;
  int   np;
  int   nx;
  int   no;
  int   key;
  int	xref;
}               t_my_pos;

typedef struct  s_my_ref
{
  int   nb_x;
  int   nb_o;
  int   nb_p;
}               t_my_ref;

int	my_putchar(char);
int	my_put_nbr(int);
int	my_strlen(char *);
int	my_getnbr(char *);
int	my_search(char s);
int	my_putnbr_base(int nbr, char *base);
unsigned int	my_putnbr_binary(unsigned int nbr);
unsigned int	my_putnbr_hexmin(unsigned int nbr);
unsigned int	my_putnbr_hexmax(unsigned int nbr);
unsigned int	my_putnbr_octal(unsigned int nbr);
unsigned int	my_putnbr_unsigned(unsigned int nb);
long		my_putnbr_p(long nbr);
int		my_moduloS(char *str);
int	my_putnbr_octalint(int nbr);
int	my_printf(const char *format, ...);
void	my_modulo(const char *format, int i , va_list ap);
void	my_modulo2(const char *format, int i , va_list ap);
void	my_test(const char *format, int i , va_list ap);
void	modulomodulo(const char *format, int i);
int     affichage(const char *format, int i);
char	*my_strcat(char *dest, char *src);
void	init_struct_ref(t_my_ref **map);
void	init_struct(t_my_pos **p1);
char	**display(char **tab, t_my_pos *p1, int key);
int	affichagemap(t_my_pos *p1, int ac, char **av);
int	main(int ac, char **av);
char	**find_elem(char **save, t_my_ref *map, t_my_pos *p1);
char	**find_p(char **tab, t_my_pos *p1);
int	printmap(char **tab, t_my_pos *p1);
int	check_size(t_my_pos *p1);
char	**move_down(char **tab, t_my_pos *p1);
char	**move_up(char **tab, t_my_pos *p1);
char	**move_right(char **tab, t_my_pos *p1);
char	**move_left(char **tab, t_my_pos *p1);
int	usage_h();
void	open_file(int ac, char **av, t_my_pos *p1);
char	**map_in(char **tab, t_my_pos *p1, char *line);
char	**map_to_tab(char **av, t_my_pos *p1);
char	**map_ref(char **av, t_my_ref *map, t_my_pos *p1);

#endif /* !MY_H */
