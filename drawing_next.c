/*
** drawing_next.c for  in /home/veyrie_f/rendu/MUL_2014_wolf3d
** 
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
** 
** Started on  Thu Dec 18 18:10:37 2014 fernand veyrier
** Last update Thu Dec 18 18:29:13 2014 fernand veyrier
*/

#include "struct.h"
#include "my.h"

void		draw_sky(t_system *param)
{
  int		x;
  int		color;

  x = 0;
  color = mlx_get_color_value(param->mlx, 0x0000FFFF);
  while (x < WIDTH * HEIGHT * 2)
    {
      param->image.data[x] = color % 256;
      param->image.data[x + 1] = (color >> 8) % 256;
      param->image.data[x + 2] = (color >> 16) % 256;
      param->image.data[x + 3] = 0;
      x += 4;
    }
}

void		draw_floor(t_system *param)
{
  int		x;
  int		color;

  x = WIDTH * HEIGHT * 2;
  color = mlx_get_color_value(param->mlx, 0x00444444);
  while (x < WIDTH * HEIGHT * 4)
    {
      param->image.data[x] = color % 256;
      param->image.data[x + 1] = (color >> 8) % 256;
      param->image.data[x + 2] = (color >> 16) % 256;
      param->image.data[x + 3] = 0;
      x += 4;
    }
}

void		get_tab_size(char **map, int *tab_size)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (map[j])
    {
      i = 0;
      while (map[j][i])
	++i;
      ++j;
    }
  tab_size[0] = j;
  tab_size[1] = i;
}

void		fill_struct(t_mmap *map, t_system *param, int flag)
{
  if (flag == 1)
    {
      map->x = 0;
      map->y = 0;
      map->tab_x = 0;
      map->tab_y = 0;
      get_tab_size(param->pnj.map_char, map->tab_size);
    }
  else
    {
      param->image.data[map->pos] = map->color;
      param->image.data[map->pos + 1] = map->color;
      param->image.data[map->pos + 2] = map->color;
      param->image.data[map->pos + 3] = map->color;
    }
}

int		func_expose(t_system *param)
{
  if (param->game_started == 1)
    mlx_put_image_to_window(param->mlx, param->win, param->image.img, 0, 0);
  return (0);
}
