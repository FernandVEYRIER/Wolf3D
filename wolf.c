/*
** minilibx.c for  in /home/veyrie_f
**
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
**
** Started on  Mon Nov 24 17:41:41 2014 fernand veyrier
** Last update Sun Dec 21 11:52:11 2014 fernand veyrier
*/

#include "struct.h"
#include "my.h"

void		do_ops(t_pnj *pnj)
{
  pnj->y1 = (WIDTH / 2 - pnj->x1) / WIDTH;
  pnj->x_prime = (0.5 * cos(pnj->angle * M_PI / 180))
    - (pnj->y1 * sin(pnj->angle * M_PI / 180));
  pnj->y_prime = (0.5 * sin(pnj->angle * M_PI / 180))
    + (pnj->y1 * cos(pnj->angle * M_PI / 180));
  pnj->x_prime_sec = pnj->x_prime + pnj->pos_x;
  pnj->y_prime_sec = pnj->y_prime + pnj->pos_y;
  pnj->vx = pnj->x_prime_sec - pnj->pos_x;
  pnj->vy = pnj->y_prime_sec - pnj->pos_y;
}

void		move_with_angles_next(t_system *param)
{
  param->pnj.pos_x -= param->pnj.speed
    * sin(param->pnj.angle * M_PI / 180);
  param->pnj.pos_y += param->pnj.speed
    * cos(param->pnj.angle * M_PI / 180);
}

void		move_with_angles(t_system *param, int keycode)
{
  if (keycode == 122)
    {
      param->pnj.pos_y += param->pnj.speed
	* sin(param->pnj.angle * M_PI / 180);
      param->pnj.pos_x += param->pnj.speed
	* cos(param->pnj.angle * M_PI / 180);
    }
  else if (keycode == 115)
    {
      param->pnj.pos_y -= param->pnj.speed
	* sin(param->pnj.angle * M_PI / 180);
      param->pnj.pos_x -= param->pnj.speed
	* cos(param->pnj.angle * M_PI / 180);
    }
  else if (keycode == 100)
    {
      param->pnj.pos_x += param->pnj.speed
	* sin(param->pnj.angle * M_PI / 180);
      param->pnj.pos_y -= param->pnj.speed
	* cos(param->pnj.angle * M_PI / 180);
    }
  else
    move_with_angles_next(param);
}

void		load_assets(t_system *sys)
{
  int		i;

  sys->pistol.img = mlx_xpm_file_to_image
    (sys->mlx, "./assets/pistol3.xpm", &i, &i);
  sys->pistol_shot.img = mlx_xpm_file_to_image
    (sys->mlx, "./assets/pistol_shot.xpm", &i, &i);
  sys->minigun.img = mlx_xpm_file_to_image
    (sys->mlx, "./assets/minigun.xpm", &i, &i);
  sys->minigun_shot.img = mlx_xpm_file_to_image
    (sys->mlx, "./assets/minigun_shot.xpm", &i, &i);
  if (sys->pistol.img == NULL || sys->pistol.img == NULL
      || sys->minigun.img == NULL || sys->minigun_shot.img == NULL)
    exit(my_putstr("Failed to load assets.\n"));
  sys->current_weapon = 1;
  if (WIDTH != 900 || HEIGHT != 800)
    exit(my_putstr("Sorry, resizing is not supported yet.\n"));
}

int		main(void)
{
  t_system	sys;

  sys.image.anti_al = 0.001;
  if ((sys.mlx = mlx_init()) == NULL)
    exit(my_putstr("Failed to init.\n"));
  if ((sys.win = mlx_new_window(sys.mlx, WIDTH, HEIGHT,
				"Wolf 4D by veyrie_f")) == NULL)
    exit(my_putstr("Failed to init window.\n"));
  load_assets(&sys);
  generate_window(&sys);
  sys.game_started = 0;
  sys.pnj.color =  mlx_get_color_value(sys.mlx, 0x00FFFFFF);
  mlx_expose_hook(sys.win, &func_expose, &sys);
  mlx_hook(sys.win, MotionNotify, PointerMotionMask, &func_mous_move, &sys);
  mlx_hook(sys.win, KeyPress, KeyPressMask, &func_key_pressed, &sys);
  mlx_hook(sys.win, KeyRelease, KeyReleaseMask, &func_key_released, &sys);
  mlx_mouse_hook(sys.win, &func_mous_click, &sys);
  mlx_loop(sys.mlx);
  return (0);
}
