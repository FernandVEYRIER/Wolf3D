/*
** event_handler.c for  in /home/veyrie_f/rendu/MUL_2014_wolf3d
**
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
**
** Started on  Sun Dec 14 18:54:11 2014 fernand veyrier
** Last update Sat Dec 20 15:24:36 2014 fernand veyrier
*/

#include "struct.h"
#include "my.h"

int		func_key_released(int keycode, t_system *param)
{
  if (param->game_started == 1 && keycode == 65362)
    redraw_weapon(param, 1);
  return (0);
}

void		func_key_pressed_next(int keycode, t_system *param)
{
  (param->game_started == 1 && keycode == 65362) ? shot_anim(param, 1) : 0;
  (keycode == 65293) ? generate_window(param) : 0;
  (param->game_started == 1 && keycode == 65364) ? shot_anim(param, 3) : 0;
  if (keycode == 65505 && param->pnj.speed == 0.1)
    param->pnj.speed = 0.2;
  else if (keycode == 65505 && param->pnj.speed == 0.2)
    param->pnj.speed = 0.1;
}

int		func_key_pressed(int keycode, t_system *param)
{
  if (keycode == 65307)
    {
      mlx_destroy_window(param->mlx, param->win);
      exit(0);
    }
  else if (param->game_started == 1 &&(keycode == 100 || keycode == 113
				       || keycode == 122 || keycode == 115))
    {
      on_collision_enter(param, keycode);
      redraw_weapon(param, 2);
    }
  else if (keycode == 65361 && param->game_started == 1)
    {
      param->pnj.angle += 5;
      redraw_weapon(param, 1);
    }
  else if (keycode == 65363 && param->game_started == 1)
    {
      param->pnj.angle -= 5;
      redraw_weapon(param, 1);
    }
  func_key_pressed_next(keycode, param);
  return (0);
}

int		func_mous_move(int x, int y, t_system *param)
{
  (param->game_started == 0 || param->game_started == 800) ?
    redraw_menu(param, 4) : 0;
  (y > HEIGHT / 1.8 && y < HEIGHT / 1.7 && (param->game_started == 0
					    || param->game_started == 800)) ?
    redraw_menu(param, 1) : 0;
  (y > HEIGHT / 1.7 && y < HEIGHT / 1.6 && (param->game_started == 0
					    || param->game_started == 800)) ?
    redraw_menu(param, 2) : 0;
  (y > HEIGHT / 1.6 && y < HEIGHT / 1.5 && (param->game_started == 0
					    || param->game_started == 800)) ?
    redraw_menu(param, 3) : 0;
  return (0);
}

int		func_mous_click(int button, int x, int y, t_system *param)
{
  if (button == 1 && param->game_started != 1)
    {
      (y > HEIGHT / 2 && y < HEIGHT / 1.7) ? param->pnj.map_char
	= generate_map("./maps/default", param) : 0;
      (y > HEIGHT / 1.7 && y < HEIGHT / 1.6) ? param->pnj.map_char
	= generate_map("./maps/maze", param) : 0;
      (y > HEIGHT / 1.6 && y < HEIGHT / 1.5) ? param->pnj.map_char
	= generate_map("./maps/big", param) : 0;
      check_hover(x, y, param);
      if (param->game_started == 1)
	{
	  param->image.data = mlx_get_data_addr
	    (param->image.img, &(param->image.bpp), &(param->image.size_line),
	     &(param->image.endian));
	  mlx_put_image_to_window(param->mlx, param->win, param->image.img, 0, 0);
	  refresh_image(param->image, param->pnj, param);
	}
    }
  return (0);
}
