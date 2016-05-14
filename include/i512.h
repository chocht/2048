/*
** i512.h for 512 in /home/chauch_p/temp/2048
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Fri May 13 02:12:39 2016 Pierre Chauchoy
** Last update Sat May 14 04:52:16 2016 Pierre Chauchoy
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

#ifndef LIST_H_
# define LIST_H_

typedef struct			s_elem
{
  int				**grid;
  struct s_elem			*prev;
  struct s_elem			*next;
}				t_elem;

typedef struct			s_list
{
  int				len;
  struct s_elem			*head;
  struct s_elem			*tail;
}				t_list;

int				**grid_dup(int**);

void				swap_elem(t_list*, t_elem*, t_elem*);
void				init_list(t_list*);
int				add_list(t_list*, int**);
int			        del_elem(t_list*, t_elem*);
int				free_list(t_list*);

#endif /* !LIST_H_ */

typedef t_bunny_pixelarray	t_b_pix;
typedef t_bunny_position	t_b_pos;

typedef struct			s_data
{
  t_bunny_window		*win;
  t_b_pix			*pix;
  t_b_pix			*sprite;
  t_b_pix			*cases[11];
  t_list			list;
  t_elem			*current;
  char				*spritesheet;
  int				**grid;
  int				key;
  void				(*key_func[2])(int);
  int				play;
  int				index;
}				t_data;

int				undo(t_data*);
int				redo(t_data*);
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

void				blit_this(t_data*);
int				algo(t_data*);

t_bunny_response		key(t_bunny_event_state,
				    t_bunny_keysym,
				    void*);
t_bunny_response		mainloop(void*);

int				init_data(t_data*, char*);

int				at_exit(t_data*, char*, int);

/*
** usual_functions
*/

void				my_free_inttab(int**, int);
int				my_strlen(char*);
int				my_strcmp(char*, char*);
unsigned int			getpixel(t_b_pix*,
					 t_b_pos*);
void				tekpixel(t_b_pix*,
					 t_b_pos*,
					 unsigned int);
void				fill_pixelarray(t_b_pix*,
						unsigned int);

#endif /* !I512_H_ */
