/*
** right_key.c for 512 in /home/chauch_p/temp/2048
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Fri May 13 02:12:15 2016 Pierre Chauchoy
** Last update Fri May 13 02:12:16 2016 Pierre Chauchoy
*/

#include "i512.h"

static int		reg_right(int **grid, int y, int x)
{
  int			j;

  j = x;
  if (j == GRID_WIDTH - 1)
    return (0);
  while (++j < GRID_WIDTH && grid[y][j] == CASE_NUM);
  if (j < GRID_WIDTH && grid[y][j] == grid[y][x])
    {
      grid[y][j]++;
      grid[y][x] = CASE_NUM;
      return (1);
    }
  j--;
  if (j != x)
    {
      grid[y][j] = grid[y][x];
      grid[y][x] = CASE_NUM;
      return (1);
    }
  return (0);
}

int		        right_key(int **grid)
{
  int			x;
  int			y;
  int			nb;

  nb = 0;
  y = -1;
  while (++y < GRID_HEIGHT)
    {
      x = GRID_WIDTH;
      while (--x >= 0)
	if (grid[y][x] != CASE_NUM)
	  nb += reg_right(grid, y, x);
    }
  return (nb);
}
