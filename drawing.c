/*
** drawing.c for  in /home/veyrie_f/rendu/MUL_2014_wolf3d
**
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
**
** Started on  Sun Dec 14 17:47:51 2014 fernand veyrier
** Last update Sat Dec 20 19:52:34 2014 fernand veyrier
*/

#include "struct.h"
#include "my.h"

void		chose_color(t_system *param, int column)
{
  if (param->pnj.current_x ==  param->pnj.last_x &&
      param->pnj.current_y - 1 ==  param->pnj.last_y)
    param->pnj.color = mlx_get_color_value(param->mlx, 0x000022FF);
  else if (param->pnj.current_x ==  param->pnj.last_x &&
	   param->pnj.current_y + 1 ==  param->pnj.last_y)
    param->pnj.color = mlx_get_color_value(param->mlx, 0x00F000FF);
  else if (param->pnj.current_y ==  param->pnj.last_y &&
	   param->pnj.current_x - 1 ==  param->pnj.last_x)
    param->pnj.color = mlx_get_color_value(param->mlx, 0x00FF0011);
  else if (param->pnj.current_y ==  param->pnj.last_y &&
	   param->pnj.current_x + 1 ==  param->pnj.last_x)
    param->pnj.color = mlx_get_color_value(param->mlx, 0x00FFFF00);
  else if (column < WIDTH / 2 && param->pnj.current_x == param->pnj.last_x
	   && param->pnj.last_y == param->pnj.current_y)
    chose_side_color(param);
  (column < 20) ? param->pnj.last_color = param->pnj.color : 0;
}

void		draw_line(double k, t_system *param, int column)
{
  int		wall_size_up;
  int		wall_size_down;
  int		pos;

  wall_size_up = (HEIGHT / 2 - HEIGHT / (2 * k));
  wall_size_down = (HEIGHT / 2 + HEIGHT / (2 * k));
  chose_color(param, column);
  while (wall_size_up < wall_size_down)
    {
      pos = (param->image.size_line * wall_size_up)
	+ (column * (param->image.bpp / 8));
      (pos < 0) ? pos = 0 : 0;
      param->image.data[pos] = param->pnj.color % 256;
      param->image.data[pos + 1] = (param->pnj.color >> 8) % 256;
      param->image.data[pos + 2] = (param->pnj.color >> 16) % 256;
      param->image.data[pos + 3] = 0;
      ++wall_size_up;
    }
}

void		draw_minimap(t_system *param)
{
  t_mmap	map;

  fill_struct(&map, param, 1);
  while (map.y < 100)
    {
      while (map.x < 200)
	{
	  map.pos = (map.y * param->image.size_line + map.x
		     * (param->image.bpp / 8));
	  map.color = (param->pnj.map_char[(int)map.tab_y]
		       [(int)map.tab_x] == '1') ? 0 : 255;
	  if (param->pnj.pos_x > map.tab_x - 0.2 &&
	      param->pnj.pos_x < map.tab_x + 0.2
	      && param->pnj.pos_y > map.tab_y - 0.2 &&
	      param->pnj.pos_y < map.tab_y + 0.2)
	    map.color = 125;
	  fill_struct(&map, param, 2);
	  ++map.x;
	  map.tab_x += (map.tab_size[1] / 200.);
	}
      map.tab_x = 0;
      map.x = 0;
      ++map.y;
      map.tab_y += (map.tab_size[0] / 100.);
    }
}

void		prepare_drawing(t_system *param, t_pnj pnj,
				int x_val, int y_val)
{
  pnj.k -= param->image.anti_al;
  param->pnj.last_x = (pnj.pos_x + ((pnj.k - param->image.anti_al) * pnj.vx));
  param->pnj.last_y = (pnj.pos_y + ((pnj.k - param->image.anti_al) * pnj.vy));
  param->pnj.current_x = x_val;
  param->pnj.current_y = y_val;
  draw_line(pnj.k, param, pnj.x1);
}

void		refresh_image(t_img image, t_pnj pnj, t_system *param)
{
  int		x_val;
  int		y_val;

  pnj.x1 = 0;
  draw_sky(param);
  draw_floor(param);
  while (pnj.x1 < WIDTH)
    {
      pnj.k = 1;
      do_ops(&pnj);
      x_val = pnj.pos_x + (pnj.k * pnj.vx);
      y_val = pnj.pos_y + (pnj.k * pnj.vy);
      while (pnj.map_char[y_val][x_val] == '0')
	{
	  pnj.k += image.anti_al;
	  x_val = pnj.pos_x + (pnj.k * pnj.vx);
	  y_val = pnj.pos_y + (pnj.k * pnj.vy);
	}
      if (pnj.map_char[y_val][x_val] == '1')
	{
	  prepare_drawing(param, pnj, x_val, y_val);
	}
      ++pnj.x1;
    }
  draw_minimap(param);
}
