/*
** list.c for lib in /home/chauch_p/librairie/samples/start_doubled_linked_lists
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue Apr 12 03:32:05 2016 Pierre Chauchoy
** Last update Sat May 14 04:47:21 2016 Pierre Chauchoy
*/

#include <stdlib.h>
#include "i512.h"

void		init_list(t_list *list)
{
  list->len = 0;
  list->head = NULL;
  list->tail = NULL;
}

int		**grid_dup(int **grid)
{
  int		**new;
  int		y;
  int		x;

  if (!(new = bunny_malloc(sizeof(int*) * (GRID_HEIGHT + 1))))
    return (NULL);
  y = -1;
  while (++y < GRID_HEIGHT)
    {
      if (!(new[y] = bunny_malloc(sizeof(int) * (GRID_WIDTH))))
	return (NULL);
      x = -1;
      while (++x < GRID_WIDTH)
	new[y][x] = grid[y][x];
    }
  return (new);
}

int		add_list(t_list *list, int **grid)
{
  t_elem	*new;

  if (!(list) || !(new = bunny_malloc(sizeof(t_elem))))
    return (1);
  new->next = NULL;
  if (!(new->grid = grid_dup(grid)))
    return (1);
  if (list->tail == NULL)
    {
      new->prev = NULL;
      list->head = new;
    }
  if (list->tail != NULL)
    {
      new->prev = list->tail;
      list->tail->next = new;
    }
  list->tail = new;
  list->len++;
  return (0);
}

int		free_list(t_list *list)
{
  t_elem	*old;
  t_elem	*tmp;

  if (!(list))
    return (1);
  tmp = list->head;
  while (tmp)
    {
      old = tmp;
      tmp = tmp->next;
      my_free_inttab(old->grid, GRID_HEIGHT);
      bunny_free(old);
    }
  return (0);
}
