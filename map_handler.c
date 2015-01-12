/*
** map_handler.c for  in /home/veyrie_f/rendu/MUL_2014_wolf3d
**
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
**
** Started on  Sun Dec 14 18:34:09 2014 fernand veyrier
** Last update Sun Dec 21 20:19:22 2014 fernand veyrier
*/

#include "my.h"
#include "struct.h"

void		put_in_map(char *buff, char **map)
{
  int		i;
  int		j;
  int		k;

  i = 0;
  j = 0;
  k = 0;
  if ((map[j] = malloc(sizeof(char) * my_strlen(buff))) == 0)
    exit(-1);
  while (buff[i])
    {
      if (buff[i] != '\n' && buff[i] != ' ')
	{
	  map[j][k++] = buff[i];
	  map[j][k] = 0;
	}
      else if (buff[i] == '\n')
	{
	  if ((map[++j] = malloc(sizeof(char) * my_strlen(buff))) == 0)
	    exit(-1);
	  k = 0;
	}
      ++i;
    }
  map[j + 1] = 0;
}

int		check_map_size(char **map)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (map[i])
    {
      while (map[i][j])
	{
	  j++;
	}
      if (j < 3 || map[i][0] == '0' || map[i][j - 1] == '0')
	return (-1);
      j = 0;
      ++i;
    }
  return ((i > 3) ? 0 : -1);
}

void		my_bzero(char *str, int size)
{
  int		i;

  i = 0;
  while (i <= size)
    {
      str[i++] = 0;
    }
}

char		**generate_map(char *file, t_system *param)
{
  int		fd;
  char		buff[4096];
  char		**map;

  if ((fd = open(file, O_RDONLY)) == -1)
    exit(my_putstr("Fatal error: could not open map.\n"));
  my_bzero(buff, 4096);
  read(fd, buff, 4095);
  if ((map = malloc(sizeof(char*) * my_strlen(buff) + 1)) == 0)
    exit(-1);
  put_in_map(buff, map);
  if (check_map_size(map) != 0)
    exit(my_putstr("Invalid map : exit.\n"));
  param->game_started = 1;
  return (map);
}
