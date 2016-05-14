/*
** i512.c for 512 in /home/chauch_p/temp/2048
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Fri May 13 02:11:41 2016 Pierre Chauchoy
** Last update Sat May 14 04:52:26 2016 Pierre Chauchoy
*/

#include "i512.h"

int			key2(t_bunny_event_state	state,
			     t_bunny_keysym		key,
			     t_data			*data)
{
  if (state == GO_DOWN && key == BKS_RETURN && data->play == 0)
    {
      reset_grid(data->grid);
      data->play = 1;
    }
  else if (state == GO_DOWN && key == BKS_R)
    reset_grid(data->grid);
  else if (state == GO_DOWN && key == BKS_BACKSPACE)
    {
      if (undo(data))
	return (1);
    }
  else if (state == GO_DOWN && key == BKS_Y)
    {
      if (redo(data))
	return (1);
    }
  else
    return (0);
  blit_this(data);
  return (0);
}

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
  else if (key2(state, key, data))
    return (EXIT_ON_ERROR);
  return (GO_ON);
}

t_bunny_response	mainloop(void	*my_data)
{
  t_data		*data;

  data = my_data;
  if (data->key != -1 && data->play == 1)
    if (algo(data))
      return (EXIT_ON_ERROR);
  bunny_display(data->win);
  return (GO_ON);
}
