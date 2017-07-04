/*
** print.c for print in /home/walter_h/PSU_2016_my_sokoban
** 
** Made by Hugo WALTER
** Login   <walter_h@epitech.net>
** 
** Started on  Tue Dec 20 17:45:24 2016 Hugo WALTER
** Last update Wed Dec 21 13:55:26 2016 Hugo WALTER
*/

#include "my.h"

char	**find_elem(char **save, t_my_ref *map, t_my_pos *p1)
{
  while (p1->yp < p1->nb_line)
    {
      p1->xp = 0;
      while (save[p1->yp][p1->xp] != '\0')
	{
	  if (save[p1->yp][p1->xp] == 'P')
	    p1->np++;
	  if (save[p1->yp][p1->xp] == 'O')
	    p1->no++;
	  if (save[p1->yp][p1->xp] == 'X')
	    p1->nx++;
	  p1->xp++;
	}
      p1->yp++;
    }
  map->nb_p = p1->np;
  map->nb_x = p1->nx;
  map->nb_o = p1->no;
  p1->valdepo = p1->no;
  if (p1->no < p1->nx || p1->np >= 2 || p1->np == 0)
    exit(84);
  return (save);
}

char	**find_p(char **tab, t_my_pos *p1)
{
  int   x;
  int   y;

  x = 0;
  y = 0;
  while (y < p1->nb_line)
    {
      x = 0;
      while (tab[y][x] != '\0')
	{
	  if (tab[y][x] == 'P')
	    {
	      p1->x = x;
	      p1->y = y;
	    }
	  x++;
	}
      y++;
    }
  return (tab);
}

int	printmap(char **tab, t_my_pos *p1)
{
  int   i;

  i = 0;
  while (i < p1->nb_line)
    {
      printw("%s", tab[i]);
      i++;
    }
  return (0);
}

int	check_size(t_my_pos *p1)
{
  while (COLS < p1->x_max || LINES < p1->nb_line)
    {
      clear();
      mvprintw(LINES / 2, (COLS / 2) - (23 / 2), "%s", "Enlarge your\
 terminal !");
      refresh();
    }
  return (0);
}
