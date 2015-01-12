/*
** utils.c for  in /home/veyrie_f/rendu/MUL_2014_wolf3d
**
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
**
** Started on  Thu Dec 18 18:30:37 2014 fernand veyrier
** Last update Sun Dec 21 20:19:07 2014 fernand veyrier
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "struct.h"

int		my_putchar(char c)
{
  write(2, &c, 1);
  return (1);
}

int		my_putstr(char *str)
{
  int		i;

  i = 0;
  while (*str != '\0')
    {
      my_putchar(*str);
      str = str + 1;
      i++;
    }
  return (i);
}

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}
