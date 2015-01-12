/*
** event_handler_next.c for  in /home/veyrie_f/rendu/MUL_2014_wolf3d
** 
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
** 
** Started on  Thu Dec 18 18:21:09 2014 fernand veyrier
** Last update Sat Dec 20 12:34:53 2014 fernand veyrier
*/

#include "struct.h"
#include "my.h"

void		switch_weapons(t_system *param)
{
  if (param->current_weapon == 1)
    {
      refresh_image(param->image, param->pnj, param);
      mlx_put_image_to_window(param->mlx, param->win, param->image.img, 0, 0);
      mlx_put_image_to_window(param->mlx, param->win,
			      param->minigun.img, WIDTH / 3.4, 600);
      param->current_weapon = 2;
    }
  else
    {
      refresh_image(param->image, param->pnj, param);
      mlx_put_image_to_window(param->mlx, param->win, param->image.img, 0, 0);
      mlx_put_image_to_window(param->mlx, param->win,
			      param->pistol.img, WIDTH / 3.2, 500);
      param->current_weapon = 1;
    }
}

void		redraw_menu(t_system *sys, int flag)
{
  (flag == 1) ? mlx_string_put(sys->mlx, sys->win, WIDTH / 2.3,
			       HEIGHT / 1.7, 0xFF0000, "[1] Default")
    + mlx_string_put(sys->mlx, sys->win, WIDTH / 2.3,
		     HEIGHT / 1.6, 0xFFFFFF, "[2] Maze")
    + mlx_string_put(sys->mlx, sys->win, WIDTH / 2.3,
		     HEIGHT / 1.5, 0xFFFFFF, "[3] Big one") : 0;
  (flag == 2) ? mlx_string_put(sys->mlx, sys->win, WIDTH / 2.3,
			       HEIGHT / 1.7, 0xFFFFFF, "[1] Default")
    + mlx_string_put(sys->mlx, sys->win, WIDTH / 2.3,
		     HEIGHT / 1.6, 0xFF0000, "[2] Maze")
    + mlx_string_put(sys->mlx, sys->win, WIDTH / 2.3,
		     HEIGHT / 1.5, 0xFFFFFF, "[3] Big one") : 0;
  (flag == 3) ? mlx_string_put(sys->mlx, sys->win, WIDTH / 2.3,
			       HEIGHT / 1.7, 0xFFFFFF, "[1] Default")
    + mlx_string_put(sys->mlx, sys->win, WIDTH / 2.3,
		     HEIGHT / 1.6, 0xFFFFFF, "[2] Maze")
    + mlx_string_put(sys->mlx, sys->win, WIDTH / 2.3,
		     HEIGHT / 1.5, 0xFF0000, "[3] Big one") : 0;
  (flag != 1 && flag != 2 && flag != 3) ?
    mlx_string_put(sys->mlx, sys->win, WIDTH / 2.3,
		   HEIGHT / 1.7, 0xFFFFFF, "[1] Default")
    + mlx_string_put(sys->mlx, sys->win, WIDTH / 2.3,
		     HEIGHT / 1.6, 0xFFFFFF, "[2] Maze")
    + mlx_string_put(sys->mlx, sys->win, WIDTH / 2.3,
		     HEIGHT / 1.5, 0xFFFFFF, "[3] Big one") : 0;
}

void		redraw_aa_next(t_system *sys, int flag)
{
  if (flag == 3)
    {
      mlx_string_put(sys->mlx, sys->win, WIDTH / 2.4,
		     HEIGHT - 10, 0xFFFFFF, "x2");
      mlx_string_put(sys->mlx, sys->win, WIDTH / 2.2,
		     HEIGHT - 10, 0xFFFFFF, "x4");
      mlx_string_put(sys->mlx, sys->win, WIDTH / 2,
		     HEIGHT - 10, 0x00FF00, "x6");
      mlx_string_put(sys->mlx, sys->win, WIDTH / 1.8,
		     HEIGHT - 10, 0xFFFFFF, "x8");
    }
  else
    {
      mlx_string_put(sys->mlx, sys->win, WIDTH / 2.4,
		     HEIGHT - 10, 0xFFFFFF, "x2");
      mlx_string_put(sys->mlx, sys->win, WIDTH / 2.2,
		     HEIGHT - 10, 0xFFFFFF, "x4");
      mlx_string_put(sys->mlx, sys->win, WIDTH / 2,
		     HEIGHT - 10, 0xFFFFFF, "x6");
      mlx_string_put(sys->mlx, sys->win, WIDTH / 1.8,
		     HEIGHT - 10, 0x00FF00, "x8");
    }
}

void		redraw_aa(t_system *sys, int flag)
{
  (flag == 1) ? mlx_string_put(sys->mlx, sys->win, WIDTH / 2.4,
			       HEIGHT - 10, 0x00FF00, "x2")
    + mlx_string_put(sys->mlx, sys->win, WIDTH / 2.2,
		     HEIGHT - 10, 0xFFFFFF, "x4")
    + mlx_string_put(sys->mlx, sys->win, WIDTH / 2,
		     HEIGHT - 10, 0xFFFFFF, "x6")
    + mlx_string_put(sys->mlx, sys->win, WIDTH / 1.8,
		     HEIGHT - 10, 0xFFFFFF, "x8") : 0;
  (flag == 2) ? mlx_string_put(sys->mlx, sys->win, WIDTH / 2.4,
			       HEIGHT - 10, 0xFFFFFF, "x2")
    + mlx_string_put(sys->mlx, sys->win, WIDTH / 2.2,
		     HEIGHT - 10, 0x00FF00, "x4")
    + mlx_string_put(sys->mlx, sys->win, WIDTH / 2,
		   HEIGHT - 10, 0xFFFFFF, "x6")
    + mlx_string_put(sys->mlx, sys->win, WIDTH / 1.8,
		     HEIGHT - 10, 0xFFFFFF, "x8") : 0;
  (flag == 3) ? redraw_aa_next(sys, flag) : 0;
  (flag == 4) ? redraw_aa_next(sys, flag) : 0;
}

void		check_hover(int x, int y, t_system *param)
{
  (y > 780 && x > 380 && x < 400) ? param->image.anti_al = 0.05 : 0;
  (y > 780 && x > 420 && x < 440) ? param->image.anti_al = 0.01 : 0;
  (y > 780 && x > 450 && x < 470) ? param->image.anti_al = 0.001 : 0;
  (y > 780 && x > 490 && x < 510) ? param->image.anti_al = 0.0005 : 0;
  (x > 370 && x < 390 && y > 780) ? redraw_aa(param, 1) : 0;
  (x > 400 && x < 430 && y > 780) ? redraw_aa(param, 2) : 0;
  (x > 450 && x < 480 && y > 780) ? redraw_aa(param, 3) : 0;
  (x > 500 && x < 520 && y > 780) ? redraw_aa(param, 4) : 0;
}
