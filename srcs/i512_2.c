/*
** i512_2.c for 512 in /home/chauch_p/temp/2048
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Sat May 14 04:36:53 2016 Pierre Chauchoy
** Last update Sat May 14 05:56:25 2016 Pierre Chauchoy
*/

#include "i512.h"
#include "my_printf.h"

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

void			del_rest_of_the_list(t_data *data)
{
  t_elem		*old;
  t_elem		*tmp;

  tmp = data->current->next;
  while (tmp)
    {
      old = tmp;
      tmp = tmp->next;
      my_free_inttab(old->grid, GRID_HEIGHT);
      bunny_free(old);
    }
  data->current = data->list.tail;
  data->current->next = NULL;
}

int			algo(t_data *data)
{
  if (data->key_func[data->index])
    data->key_func[data->index](data->key);
  if (play(data->grid, data->key) == 0)
    {
      data->key = -1;
      return (0);
    }
  del_rest_of_the_list(data);
  if (add_list(&data->list, data->grid))
    return (1);
  data->current = data->current->next;
  add_random(data->grid);
  blit_this(data);
  if (is_win(data->grid))
    {
      data->play = 0;
      return (0);
    }
  else if (is_lost(data->grid))
    {
      data->play = 0;
      return (0);
    }
  data->key = -1;
  return (0);
}
