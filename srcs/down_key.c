/*
** down_key.c for 512 in /home/chauch_p/temp/2048
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Fri May 13 02:11:37 2016 Pierre Chauchoy
** Last update Fri May 13 02:11:37 2016 Pierre Chauchoy
*/

#include "i512.h"

static int		reg_down(int **grid, int y, int x)
{
  int			j;

  j = y;
  if (j == GRID_HEIGHT - 1)
    return (0);
  while (++j < GRID_HEIGHT && grid[j][x] == CASE_NUM);
  if (j < GRID_HEIGHT && grid[j][x] == grid[y][x])
    {
      grid[j][x]++;
      grid[y][x] = CASE_NUM;
      return (1);
    }
  j--;
  if (j != y)
    {
      grid[j][x] = grid[y][x];
      grid[y][x] = CASE_NUM;
      return (1);
    }
  return (0);
}

int		        down_key(int **grid)
{
  int			x;
  int			y;
  int			nb;

  nb = 0;
  y = GRID_HEIGHT;
  while (--y >= 0)
    {
      x = -1;
      while (++x < GRID_WIDTH)
	if (grid[y][x] != CASE_NUM)
	  nb += reg_down(grid, y, x);
    }
  return (nb);
}
