/*
** i512.c for 512 in /home/chauch_p/temp/2048
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Fri May 13 02:11:41 2016 Pierre Chauchoy
** Last update Fri May 13 02:42:41 2016 Pierre Chauchoy
*/

#include "my_printf.h"
#include "i512.h"

t_bunny_response	key(t_bunny_event_state	state,
			    t_bunny_keysym	key,
			    void		*my_data)
{
  t_data		*data;

  data = my_data;
  if (state == GO_DOWN && key == BKS_UP)
    data->key = 0;
  else if (state == GO_DOWN && key == BKS_RIGHT)
    data->key = 1;
  else if (state == GO_DOWN && key == BKS_DOWN)
    data->key = 2;
  else if (state == GO_DOWN && key == BKS_LEFT)
    data->key = 3;
  else if (state == GO_DOWN && key == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  else if (state == GO_DOWN && key == BKS_RETURN && data->play == 0)
    {
      reset_grid(data->grid);
      data->play = 1;
    }
  else if (state == GO_DOWN && key == BKS_R)
    reset_grid(data->grid);
  /* else if (state == GO_DOWN && key == BKS_BACKSPACE) */
  /*   undo_this(&data->save_grid, data->grid); */
  /* else if (state == GO_DOWN && key == BKS_Y) */
  /*   redo_this(&data->save_grid, data->grid); */
  return (GO_ON);
}

void			blit_this(t_data *data)
{
  t_bunny_position	pos;
  int			i;

  i = -1;
  pos.x = 0;
  pos.y = 0;
  while (++i < (GRID_HEIGHT * GRID_WIDTH))
    {
      if (data->grid[pos.y / CASE_HEIGHT][pos.x / CASE_WIDTH] > 9)
        data->grid[pos.y / CASE_HEIGHT][pos.x / CASE_WIDTH] = CASE_NUM;
      bunny_blit(&data->win->buffer, &data->cases\
		 [data->grid[pos.y / CASE_HEIGHT]\
		  [pos.x / CASE_WIDTH]]->clipable, &pos);
      pos.x += CASE_WIDTH;
      if (pos.x == (CASE_WIDTH * GRID_WIDTH))
	{
	  pos.y += CASE_HEIGHT;
	  pos.x = 0;
	}
    }
}

void			key_pressed(int key)
{
  my_printf(KEY_MSG);
  if (key == 0)
    my_printf("UP\n");
  else if (key == 1)
    my_printf("RIGHT\n");
  else if (key == 2)
    my_printf("DOWN\n");
  else if (key == 3)
    my_printf("LEFT\n");
}

void			algo(t_data *data)
{
  if (data->key_func[data->index])
    data->key_func[data->index](data->key);
  if (play(data->grid, data->key) == 0)
    {
      data->key = -1;
      return ;
    }
  add_random(data->grid);
  if (is_win(data->grid))
    {
      data->play = 0;
      return ;
    }
  else if (is_lost(data->grid))
    {
      data->play = 0;
      return ;
    }
  data->key = -1;
}

t_bunny_response	mainloop(void	*my_data)
{
  t_data		*data;

  data = my_data;
  if (data->key != -1 && data->play == 1)
    algo(data);
  blit_this(data);
  bunny_display(data->win);
  return (GO_ON);
}
