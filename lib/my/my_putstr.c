/*
** my_putstr.c for my_putstr in /home/walter_h/CPool_Day04
** 
** Made by Hugo WALTER
** Login   <walter_h@epitech.net>
** 
** Started on  Thu Oct  6 15:50:01 2016 Hugo WALTER
** Last update Wed Dec 14 12:08:46 2016 Hugo WALTER
*/

#include "my.h"

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
  return (0);
}
