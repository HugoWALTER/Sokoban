/*
** main.c for main in /home/walter_h/delivery/PSU_2016_my_sokoban/sok3/test
** 
** Made by Hugo WALTER
** Login   <walter_h@epitech.net>
** 
** Started on  Fri Dec 16 20:55:13 2016 Hugo WALTER
** Last update Wed Dec 21 10:10:47 2016 Hugo WALTER
*/

#include "my.h"

void	init_struct_ref(t_my_ref **map)
{
  t_my_ref	*elem;

  elem = malloc(sizeof(*elem));
  elem->nb_x = 0;
  elem->nb_o = 0;
  elem->nb_p = 0;
  *map = elem;
}

void	init_struct(t_my_pos **p1)
{
  t_my_pos	*lm;

  lm = malloc(sizeof(*lm));
  lm->x = 0;
  lm->y = 0;
  lm->nb_line = 1;
  lm->x_max = 0;
  lm->is_on = 0;
  lm->is_on2 = 0;
  lm->on_end = 0;
  lm->valdepo = 0;
  lm->taille = 0;
  lm->xt = 0;
  lm->yt = 0;
  lm->stockx = 0;
  lm->xp = 0;
  lm->yp = 0;
  lm->np = 0;
  lm->nx = 0;
  lm->no = 0;
  lm->key = 0;
  lm->xref = 0;
  *p1 = lm;
}

char	**display(char **tab, t_my_pos *p1, int key)
{
  if (key == KEY_DOWN || key == 's')
    tab = move_down(tab, p1);
  if (key == KEY_UP || key == 'z')
    tab = move_up(tab, p1);
  if (key == KEY_RIGHT || key == 'd')
    tab = move_right(tab, p1);
  if (key == KEY_LEFT || key == 'q')
    tab = move_left(tab, p1);
  clear();
  find_p(tab, p1);
  refresh();
  return (tab);
}

int	affichagemap(t_my_pos *p1, int ac, char **av)
{
  initscr();
  noecho();
  keypad(stdscr, TRUE);
  curs_set(FALSE);
  while (p1->key != ' ')
    {
      check_size(p1);
      printmap(p1->tab, p1);
      refresh();
      p1->key = getch();
      display(p1->tab, p1, p1->key);
      if (p1->valdepo == p1->on_end)
	{
	  clear();
	  mvprintw(LINES / 2, (COLS / 2) - (9 / 2), "%s", "YOU WIN !");
	  refresh();
	  usleep(2000000);
	  endwin();
	  exit (0);
	}
    }
  clear();
  endwin();
  p1->tab = find_p(p1->tab, p1);
  main(ac, av);
  return (0);
}

int	main(int ac, char **av)
{
  char	**tab;
  char	**save;
  t_my_pos	*p1;
  t_my_ref	*map;

  if (ac != 2 || (ac == 2 && av[1][0] == '-' && av[1][1] == 'h'))
    usage_h();
  init_struct(&p1);
  init_struct_ref(&map);
  open_file(ac, av, p1);
  save = map_ref(av, map, p1);
  save = find_elem(save, map, p1);
  tab = map_to_tab(av, p1);
  tab = find_p(tab, p1);
  p1->tab = tab;
  p1->save = save;
  affichagemap(p1, ac, av);
  return (0);
}
