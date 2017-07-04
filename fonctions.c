/*
** fonctions.c for fonctions in /home/walter_h/PSU_2016_my_sokoban
** 
** Made by Hugo WALTER
** Login   <walter_h@epitech.net>
** 
** Started on  Tue Dec 20 17:38:07 2016 Hugo WALTER
** Last update Tue Dec 20 18:14:40 2016 Hugo WALTER
*/

#include "my.h"

int     usage_h()
{
  write(2, "USAGE\n\t./my_sokoban map\n\nDESCRIPTION\n\tmap\tfile representing\
 the warehouse map, containing '#' for walls,\n\t\t'P' for the player, 'X' for\
 boxes and 'O' for storage locations.\n", my_strlen("USAGE\n\t./my_sokoban\
 map\n\nDESCRIPTION\n\tmap\tfile representing the warehouse map, containing\
 '#' for walls,\n\t\t'P' for the player, 'X' for boxes and 'O' for storage\
 locations.\n"));
  exit(84);
}

void    open_file(int ac, char **av, t_my_pos *p1)
{
  char  fd;
  char  *buffer;
  int   i;

  buffer = malloc(sizeof(char) * 1024);
  if ((fd = open(av[1], O_RDONLY)) == -1)
    exit (84);
  i = read(fd, buffer, 1024);
  buffer[i] = '\0';
  i = 0;
  while (buffer[i])
    {
      if (buffer[i] == '\n')
	p1->nb_line++;
      i++;
    }
  close(fd);
}

char    **map_in(char **tab, t_my_pos *p1, char *line)
{
  tab[p1->yt][p1->xt] = line[p1->xt];
  if (p1->stockx < p1->xt)
    {
      p1->stockx = p1->xt;
      p1->x_max = p1->stockx;
    }
  return (tab);
}

char    **map_to_tab(char **av, t_my_pos *p1)
{
  char          **tab;
  FILE          *fd;
  char          *line;
  size_t        len;

  line = NULL;
  len = 0;
  p1->yt = -1;
  tab = malloc(sizeof(char *) * p1->nb_line);
  fd = fopen(av[1], "r");
  while (++p1->yt < p1->nb_line)
    {
      p1->xt = -1;
      p1->taille = getline(&line, &len, fd);
      tab[p1->yt] = malloc(sizeof(char) * (p1->taille + 1));
      while (++p1->xt < p1->taille)
	map_in(tab, p1, line);
      tab[p1->yt][p1->xt] = '\0';
    }
  fclose(fd);
  return (tab);
}

char    **map_ref(char **av, t_my_ref *map, t_my_pos *p1)
{
  char          **save;
  FILE          *fd;
  char          *line;
  size_t        len;
  int           taille;
  int           y;

  line = NULL;
  len = 0;
  y = -1;
  map = malloc(sizeof(*map));
  save = malloc(sizeof(char *) * p1->nb_line);
  fd = fopen(av[1], "r");
  while (++y < p1->nb_line)
    {
      p1->xref = -1;
      taille = getline(&line, &len, fd);
      save[y] = malloc(sizeof(char) * (taille + 1));
      while (++p1->xref < taille)
	save[y][p1->xref] = line[p1->xref];
      save[y][p1->xref] = '\0';
    }
  fclose(fd);
  return (save);
}
