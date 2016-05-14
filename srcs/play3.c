/*
** play3.c for 512 in /home/chauch_p/temp/2048
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Sat May 14 04:31:27 2016 Pierre Chauchoy
** Last update Sat May 14 04:52:41 2016 Pierre Chauchoy
*/

#include "i512.h"

int		undo(t_data *data)
{
  if (data->current->prev == NULL)
    return (0);
  data->current = data->current->prev;
  my_free_inttab(data->grid, GRID_HEIGHT);
  if (!(data->grid = grid_dup(data->current->grid)))
    return (1);
  return (0);
}

int	        redo(t_data *data)
{
  data = data;
  return (0);
}
