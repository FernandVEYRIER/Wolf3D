/*
** struct.h for  in /home/veyrie_f/rendu/MUL_2014_wolf3d
** 
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
** 
** Started on  Mon Dec  8 00:10:31 2014 fernand veyrier
** Last update Sat Dec 20 20:03:06 2014 fernand veyrier
*/

#ifndef STRUCT_H_
# define STRUCT_H_

# define WIDTH 900
# define HEIGHT 800

#include <mlx.h>
#include <X11/X.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct	s_mmap
{
  int		x;
  int		y;
  double	tab_x;
  double	tab_y;
  int		pos;
  int		color;
  int		tab_size[2];
}		t_mmap;

typedef struct	s_pnj
{
  double	pos_x;
  double	pos_y;
  double	angle;
  double	x1;
  double	y1;
  double	x_prime;
  double	y_prime;
  double	x_prime_sec;
  double	y_prime_sec;
  double	k;
  double	vx;
  double	vy;
  double	speed;
  int		last_x;
  int		last_y;
  int		current_x;
  int		current_y;
  int		color;
  int		last_color;
  char		**map_char;
}		t_pnj;

typedef struct	s_img
{
  void		*img;
  char		*data;
  int		bpp;
  int		size_line;
  int		endian;
  double	anti_al;
}		t_img;

typedef struct	s_system
{
  void		*mlx;
  void		*win;
  int		game_started;
  int		current_weapon;
  t_img		image;
  t_img		pistol;
  t_img		pistol_shot;
  t_img		title;
  t_img		minigun;
  t_img		minigun_shot;
  t_pnj		pnj;
}		t_system;

void		draw_sky(t_system *param);
void		draw_floor(t_system *param);
void		draw_line(double k, t_system *param, int column);
int		func_expose(t_system *param);
void		do_ops(t_pnj *pnj);
char		**generate_map(char *map, t_system *param);
void		refresh_image(t_img img, t_pnj pnj, t_system *param);
int		func_mous_click(int button, int x, int y, t_system *param);
int		func_mous_move(int x, int y, t_system *param);
int		func_key_pressed(int keycode, t_system *param);
int		func_key_released(int keycode, t_system *param);
void		on_collision_enter(t_system *param, int keycode);
void		generate_window(t_system *sys);
void		fill_struct(t_mmap *map, t_system *param, int flag);
void		redraw_menu(t_system *param, int flag);
void		redraw_aa(t_system *param, int flag);
void		redraw_aa_next(t_system *sys, int flag);
void		shot_anim(t_system *param, int flag);
void		move_with_angles(t_system *param, int keycode);
void		check_hover(int x, int y, t_system *param);
void		redraw_weapon(t_system *param, int flag);
void		switch_weapons(t_system *param);

#endif /* !STRUCT_H_ */
