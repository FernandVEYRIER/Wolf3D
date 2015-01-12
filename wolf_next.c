/*
** wolf_next.c for  in /home/veyrie_f/rendu/MUL_2014_wolf3d
**
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
**
** Started on  Thu Dec 18 18:17:27 2014 fernand veyrier
** Last update Sun Dec 21 18:52:07 2014 fernand veyrier
*/

#include "struct.h"
#include "my.h"

void		on_collision_enter(t_system *param, int keycode)
{
  if (keycode == 122 && param->pnj.map_char[(int)(param->pnj.pos_y + 0.3 *
         sin(param->pnj.angle * M_PI / 180))][(int)(param->pnj.pos_x + 0.3
			    * cos(param->pnj.angle * M_PI / 180))] == '0')
    move_with_angles(param, keycode);
  else if (keycode == 115 && param->pnj.map_char[(int)(param->pnj.pos_y - 0.3 *
       sin(param->pnj.angle * M_PI / 180))][(int)(param->pnj.pos_x - 0.3 *
                              cos(param->pnj.angle * M_PI / 180))] == '0')
    {
      move_with_angles(param, keycode);
    }
  else if (keycode == 100 && param->pnj.map_char[(int)(param->pnj.pos_y - 0.3 *
       cos(param->pnj.angle * M_PI / 180))][(int)(param->pnj.pos_x + 0.3 *
                              sin(param->pnj.angle * M_PI / 180))] == '0')
    {
      move_with_angles(param, keycode);
    }
  else if (keycode == 113 && param->pnj.map_char[(int)(param->pnj.pos_y + 0.3 *
       cos(param->pnj.angle * M_PI / 180))][(int)(param->pnj.pos_x - 0.3 *
			      sin(param->pnj.angle * M_PI / 180))] == '0')
    {
      move_with_angles(param, keycode);
    }
  refresh_image(param->image, param->pnj, param);
  mlx_put_image_to_window(param->mlx, param->win, param->image.img, 0, 0);
}

void		generate_window(t_system *sys)
{
  sys->game_started = 0;
  sys->image.img = mlx_new_image(sys->mlx, 900, 800);
  sys->image.data = mlx_get_data_addr(sys->image.img, &(sys->image.bpp),
			         &(sys->image.size_line), &(sys->image.endian));
  sys->pnj.pos_x = 1.5;
  sys->pnj.pos_y = 1.5;
  sys->pnj.angle = 90;
  sys->pnj.speed = 0.1;
  sys->title.img = mlx_xpm_file_to_image(sys->mlx, "./assets/title.xpm",
					&sys->game_started, &sys->game_started);
  mlx_put_image_to_window(sys->mlx, sys->win, sys->title.img, 0, 0);
  mlx_string_put(sys->mlx, sys->win, WIDTH / 2.3,
		 HEIGHT / 2, 0xFFFFFF, "Chose your map");
  mlx_string_put(sys->mlx, sys->win, WIDTH / 2.3,
		 HEIGHT / 1.7, 0xFFFFFF, "[1] Default");
  mlx_string_put(sys->mlx, sys->win, WIDTH / 2.3,
		 HEIGHT / 1.6, 0xFFFFFF, "[2] Maze");
  mlx_string_put(sys->mlx, sys->win, WIDTH / 2.3,
		 HEIGHT / 1.5, 0xFFFFFF, "[3] Big one");
  mlx_string_put(sys->mlx, sys->win, WIDTH / 3, HEIGHT - 10, 0xFFFFFF,
		 "Chose AA :");
  mlx_string_put(sys->mlx, sys->win, WIDTH / 2.4, HEIGHT - 10, 0xFFFFFF, "x2");
  mlx_string_put(sys->mlx, sys->win, WIDTH / 2.2, HEIGHT - 10, 0xFFFFFF, "x4");
  mlx_string_put(sys->mlx, sys->win, WIDTH / 2, HEIGHT - 10, 0x00FF00, "x6");
  mlx_string_put(sys->mlx, sys->win, WIDTH / 1.8, HEIGHT - 10, 0xFFFFFF, "x8");
}
