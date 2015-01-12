/*
** weapon_handler.c for  in /home/veyrie_f/rendu/MUL_2014_wolf3d
**
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
**
** Started on  Sat Dec 20 12:33:28 2014 fernand veyrier
** Last update Sun Dec 21 18:42:49 2014 fernand veyrier
*/

#include "struct.h"
#include "my.h"

void		redraw_weapon(t_system *param, int flag)
{
  if (flag == 1)
    {
      refresh_image(param->image, param->pnj, param);
      mlx_put_image_to_window(param->mlx, param->win, param->image.img, 0, 0);
    }
  if (param->current_weapon == 1)
    mlx_put_image_to_window(param->mlx, param->win,
			    param->pistol.img, WIDTH / 3.2, 500);
  else
    mlx_put_image_to_window(param->mlx, param->win,
			    param->minigun.img, WIDTH / 3.4, 600);
}

void		shot_anim(t_system *param, int flag)
{
  if (flag == 1 && param->current_weapon == 1)
    {
      mlx_put_image_to_window(param->mlx,
				param->win, param->pistol_shot.img, 0, 0);
      my_putchar('\a');
    }
  else if (flag == 1 && param->current_weapon == 2)
    {
      mlx_put_image_to_window
	(param->mlx, param->win, param->minigun_shot.img, WIDTH / 3.9, 500);
    }
  else if (flag == 3)
    switch_weapons(param);
}

void		chose_side_color(t_system *param)
{
  int		cos_a;
  int		sin_a;

  cos_a = cos(param->pnj.angle * M_PI / 180);
  sin_a = sin(param->pnj.angle * M_PI / 180);
  if (cos_a == 0 && sin_a == 1)
    param->pnj.color = mlx_get_color_value(param->mlx, 0x00FFFF00);
  else if (cos_a == -1 && sin_a == 0)
    param->pnj.color = mlx_get_color_value(param->mlx, 0x00F000FF);
  else if (cos_a == 1 && sin_a == 0)
    param->pnj.color = mlx_get_color_value(param->mlx, 0x000022FF);
  else if (cos_a == 0 && sin_a == -1)
    param->pnj.color = mlx_get_color_value(param->mlx, 0x00FF0011);
  else
    param->pnj.color = param->pnj.last_color;
}
