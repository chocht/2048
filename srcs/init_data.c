/*
** init_data.c for 512 in /home/chauch_p/temp/2048
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Fri May 13 02:11:45 2016 Pierre Chauchoy
** Last update Sat May 14 04:35:26 2016 Pierre Chauchoy
*/

#include <time.h>
#include "i512.h"

void			load_case(t_bunny_pixelarray *sprite,
				  t_bunny_pixelarray *cases,
				  t_bunny_position pos)
{
  t_bunny_position	p;
  int			ret;

  p.y = -1;
  ret = pos.x;
  while (++p.y < CASE_HEIGHT)
    {
      p.x = -1;
      while (++p.x < CASE_WIDTH)
	{
	  tekpixel(cases, &p, getpixel(sprite, &pos));
	  pos.x++;
	}
      pos.x = ret;
      pos.y++;
    }
}

int			fill_cases(t_data *data)
{
  int			i;
  t_bunny_position	pos;

  pos.x = 0;
  pos.y = 0;
  i = -1;
  while (++i < CASE_NUM)
    {
      if (!(data->cases[i] = bunny_new_pixelarray(CASE_WIDTH, CASE_HEIGHT)))
	return (at_exit(data, "Failed to create pixelarray", 1));
      load_case(data->sprite, data->cases[i], pos);
      pos.x += CASE_WIDTH;
      if (pos.x == CASE_WIDTH * GRID_WIDTH)
	{
	  pos.x = 0;
	  pos.y += CASE_HEIGHT;
	}
    }
  if (!(data->cases[i] = bunny_new_pixelarray(CASE_WIDTH, CASE_HEIGHT)))
    return (at_exit(data, "Failed to create pixelarray", 1));
  fill_pixelarray(data->cases[i], BLACK);
  data->cases[++i] = NULL;
  return (0);
}

int			init_data(t_data *data, char *sprite)
{
  srand(time(NULL));
  data->win = NULL;
  data->pix = NULL;
  data->cases[0] = NULL;
  data->grid = NULL;
  init_list(&data->list);
  if (!(data->win = bunny_start_style(WIN_WIDTH, WIN_HEIGHT,
				      TITLEBAR | CLOSE_BUTTON, "512")))
    return (at_exit(data, "Failed to start window", 1));
  if (!(data->pix = bunny_new_pixelarray(WIN_WIDTH, WIN_HEIGHT)))
    return (at_exit(data, "Failed to create pixelarray", 1));
  if (!(data->sprite = bunny_load_pixelarray(sprite)))
    return (at_exit(data, "Failed to load sprite", 1));
  if (init_grid(data))
    return (at_exit(data, "Failed to malloc grid", 1));
  if (fill_cases(data))
    return (1);
  if (add_list(&data->list, data->grid))
    return (1);
  data->current = data->list.head;
  blit_this(data);
  data->key = -1;
  data->play = 1;
  return (0);
}
