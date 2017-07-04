/*
** fonctions2.c for fonctions2 in /home/walter_h/PSU_2016_my_sokoban
** 
** Made by Hugo WALTER
** Login   <walter_h@epitech.net>
** 
** Started on  Tue Dec 20 17:41:55 2016 Hugo WALTER
** Last update Wed Dec 21 09:07:57 2016 Hugo WALTER
*/

#include "my.h"

char    **move_down(char **tab, t_my_pos *p1)
{
  if (tab[p1->y + 1][p1->x] == 'X' && tab[p1->y + 2][p1->x] !=
      '#' && tab[p1->y + 2][p1->x] != 'X')
    {
      tab[p1->y][p1->x] = (p1->save[p1->y][p1->x] == '1') ? 'O': 32;
      if (tab[p1->y][p1->x] == 'O')
	{
	  p1->save[p1->y][p1->x] = 'O';
	  p1->on_end--;
	}
      tab[p1->y + 1][p1->x] = 'P';
      p1->on_end += tab[p1->y + 2][p1->x] == 'O' ? 1 : 0;
      p1->save[p1->y + 2][p1->x] = (tab[p1->y + 2][p1->x] == 'O') ?
	'1' : 32;
      tab[p1->y + 2][p1->x] = 'X';
    }
  else
    if (tab[p1->y + 1][p1->x] != '#' && tab[p1->y + 1][p1->x] != 'X')
      {
	p1->save[p1->y + 1][p1->x] = (tab[p1->y + 1][p1->x] == 'O') ? '1' : 32;
	tab[p1->y + 1][p1->x] = 'P';
	tab[p1->y][p1->x] = (p1->save[p1->y][p1->x] == '1') ? 'O' : 32;
	p1->save[p1->y][p1->x] = (p1->save[p1->y][p1->x] == '1') ? 'O' : 32;
      }
  return (tab);
}

char    **move_up(char **tab, t_my_pos *p1)
{
  if (tab[p1->y - 1][p1->x] == 'X' && tab[p1->y - 2][p1->x] !=
      '#' && tab[p1->y - 2][p1->x] != 'X')
    {
      tab[p1->y][p1->x] = (p1->save[p1->y][p1->x] == '1') ? 'O': 32;
      if (tab[p1->y][p1->x] == 'O')
	{
	  p1->save[p1->y][p1->x] = 'O';
	  p1->on_end--;
	}
      tab[p1->y - 1][p1->x] = 'P';
      p1->on_end += tab[p1->y - 2][p1->x] == 'O' ? 1 : 0;
      p1->save[p1->y - 2][p1->x] = (tab[p1->y - 2][p1->x] == 'O') ?
	'1' : 32;
      tab[p1->y - 2][p1->x] = 'X';
    }
  else
    if (tab[p1->y - 1][p1->x] != '#' && tab[p1->y - 1][p1->x] != 'X')
      {
	p1->save[p1->y - 1][p1->x] = (tab[p1->y - 1][p1->x] == 'O') ? '1' : 32;
	tab[p1->y - 1][p1->x] = 'P';
	tab[p1->y][p1->x] = (p1->save[p1->y][p1->x] == '1') ? 'O' : 32;
	p1->save[p1->y][p1->x] = (p1->save[p1->y][p1->x] == '1') ? 'O' : 32;
      }
  return (tab);
}

char    **move_right(char **tab, t_my_pos *p1)
{
  if (tab[p1->y][p1->x + 1] == 'X' && tab[p1->y][p1->x + 2] !=
      '#' && tab[p1->y][p1->x + 2] != 'X')
    {
      tab[p1->y][p1->x] = (p1->save[p1->y][p1->x] == '1') ? 'O': 32;
      if (tab[p1->y][p1->x] == 'O')
	{
	  p1->save[p1->y][p1->x] = 'O';
	  p1->on_end--;
	}
      tab[p1->y][p1->x + 1] = 'P';
      p1->on_end += tab[p1->y][p1->x + 2] == 'O' ? 1 : 0;
      p1->save[p1->y][p1->x + 2] = (tab[p1->y][p1->x + 2] == 'O') ?
	'1' : 32;
      tab[p1->y][p1->x + 2] = 'X';
    }
  else
    if (tab[p1->y][p1->x + 1] != '#' && tab[p1->y][p1->x + 1] != 'X')
      {
	p1->save[p1->y][p1->x + 1] = (tab[p1->y][p1->x + 1] == 'O') ? '1' : 32;
	tab[p1->y][p1->x + 1] = 'P';
	tab[p1->y][p1->x] = (p1->save[p1->y][p1->x] == '1') ? 'O' : 32;
	p1->save[p1->y][p1->x] = (p1->save[p1->y][p1->x] == '1') ? 'O' : 32;
      }
  return (tab);
}

char    **move_left(char **tab, t_my_pos *p1)
{
  if (tab[p1->y][p1->x - 1] == 'X' && tab[p1->y][p1->x - 2] != '#'
      && tab[p1->y][p1->x - 2] != 'X')
    {
      tab[p1->y][p1->x] = (p1->save[p1->y][p1->x] == '1') ? 'O': 32;
      if (tab[p1->y][p1->x] == 'O')
	{
	  p1->save[p1->y][p1->x] = 'O';
	  p1->on_end--;
	}
      tab[p1->y][p1->x - 1] = 'P';
      p1->on_end += tab[p1->y][p1->x - 2] == 'O' ? 1 : 0;
      p1->save[p1->y][p1->x - 2] = (tab[p1->y][p1->x - 2] == 'O') ?
	'1' : 32;
      tab[p1->y][p1->x - 2] = 'X';
    }
  else
    if (tab[p1->y][p1->x - 1] != '#' && tab[p1->y][p1->x - 1] != 'X')
      {
	p1->save[p1->y][p1->x - 1] = (tab[p1->y][p1->x - 1] == 'O') ? '1' : 32;
	tab[p1->y][p1->x - 1] = 'P';
	tab[p1->y][p1->x] = (p1->save[p1->y][p1->x] == '1') ? 'O' : 32;
	p1->save[p1->y][p1->x] = (p1->save[p1->y][p1->x] == '1') ? 'O' : 32;
      }
  return (tab);
}
