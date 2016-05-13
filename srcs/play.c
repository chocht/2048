/*
** play.c for 512 in /home/chauch_p/temp/2048
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Fri May 13 02:12:10 2016 Pierre Chauchoy
** Last update Fri May 13 02:12:10 2016 Pierre Chauchoy
*/

#include "i512.h"

int		init_grid(t_data *data)
{
  int		i;
  int		x;

  i = -1;
  if (!(data->grid = bunny_malloc(sizeof(int*) * (GRID_HEIGHT + 1))))
    return (1);
  while (++i < GRID_HEIGHT)
    {
      if (!(data->grid[i] = bunny_malloc(sizeof(int) * (GRID_WIDTH))))
	return (1);
      x = -1;
      while (++x < GRID_WIDTH)
	data->grid[i][x] = CASE_NUM;
    }
  data->grid[i] = NULL;
  add_random(data->grid);
  return (0);
}

void		reset_grid(int **grid)
{
  int		y;
  int		x;

  y = -1;
  while (++y < GRID_HEIGHT)
    {
      x = -1;
      while (++x < GRID_WIDTH)
	grid[y][x] = CASE_NUM;
    }
  add_random(grid);
}

void		add_random(int **grid)
{
  int		n;
  int		i;

  i = -1;
  n = rand() % (GRID_WIDTH * GRID_HEIGHT);
  while (grid[n / GRID_HEIGHT][n % GRID_WIDTH] != CASE_NUM && ++i < 50000)
    n = rand() % (GRID_WIDTH * GRID_HEIGHT);
  if (i != 50000)
    grid[n / GRID_HEIGHT][n % GRID_WIDTH] = 0;
}

int		play(int **grid, int key)
{
  int		i;

  if (key == 0)
    i = up_key(grid);
  else if (key == 1)
    i = right_key(grid);
  else if (key == 2)
    i = down_key(grid);
  else if (key == 3)
    i = left_key(grid);
  return (i);
}
