/*
** i512.h for 512 in /home/chauch_p/temp/2048
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Fri May 13 02:12:39 2016 Pierre Chauchoy
** Last update Fri May 13 02:45:29 2016 Pierre Chauchoy
*/

#ifndef I512_H_
# define I512_H_

# include			<lapin.h>

# define WIN_WIDTH		256
# define WIN_HEIGHT		256

# define GRID_WIDTH		4
# define GRID_HEIGHT		4
# define CASE_NUM		9
# define CASE_WIDTH		64
# define CASE_HEIGHT		64

# define NB_SAVE		10

# define WIN_MSG		"You win !"
# define LOSE_MSG		"You lost !"
# define KEY_MSG		"Last key pressed : "
# define RESTART_MSG		"Press ENTER to restart."
# define QUIT_MSG		"Press ESCAPE to quit."

# define HELP			"-h"
# define HELP_LONG		"--help"
# define DEBUG			"-d"
# define DEBUG_LONG		"--debug"

typedef t_bunny_pixelarray	t_b_pix;
typedef t_bunny_position	t_b_pos;

typedef struct			s_data
{
  t_bunny_window		*win;
  t_b_pix			*pix;
  t_b_pix			*sprite;
  t_b_pix			*cases[11];
  char				*spritesheet;
  int				**save_grid[NB_SAVE + 1];
  int				**grid;
  int				key;
  void				(*key_func[2])(int);
  int				index;
  int				play;
}				t_data;

int				init_grid(t_data*);
void				reset_grid(int**);
void				add_random(int**);
int				is_win(int**);
int				is_lost(int**);

int				up_key(int**);
int				right_key(int**);
int				down_key(int**);
int				left_key(int**);
void				key_pressed(int);
int				play(int**, int);

int				at_exit(t_data*, char*, int);
int				init_data(t_data*, char*);
t_bunny_response		key(t_bunny_event_state,
				    t_bunny_keysym,
				    void*);
t_bunny_response		mainloop(void*);

/*
** usual_functions
*/

int				my_strcmp(char*, char*);
unsigned int			getpixel(t_b_pix*,
					 t_b_pos*);
void				tekpixel(t_b_pix*,
					 t_b_pos*,
					 unsigned int);
void				fill_pixelarray(t_b_pix*,
						unsigned int);

#endif /* !I512_H_ */
