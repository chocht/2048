/*
** left_key.c for 512 in /home/chauch_p/temp/2048
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Fri May 13 02:11:50 2016 Pierre Chauchoy
** Last update Fri May 13 02:11:50 2016 Pierre Chauchoy
*/

#include "i512.h"

static int		reg_left(int **grid, int y, int x)
{
  int			j;

  j = x;
  if (j == 0)
    return (0);
  while (--j >= 0 && grid[y][j] == CASE_NUM);
  if (j >= 0 && grid[y][j] == grid[y][x])
    {
      grid[y][j]++;
      grid[y][x] = CASE_NUM;
      return (1);
    }
  j++;
  if (j != x)
    {
      grid[y][j] = grid[y][x];
      grid[y][x] = CASE_NUM;
      return (1);
    }
  return (0);
}

int			left_key(int **grid)
{
  int			x;
  int			y;
  int			nb;

  nb = 0;
  y = -1;
  while (++y < GRID_HEIGHT)
    {
      x = -1;
      while (++x < GRID_WIDTH)
	if (grid[y][x] != CASE_NUM)
	  nb += reg_left(grid, y, x);
    }
  return (nb);
}
