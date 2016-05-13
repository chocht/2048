/*
** play2.c for 512 in /home/chauch_p/temp/2048
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Fri May 13 02:12:05 2016 Pierre Chauchoy
** Last update Fri May 13 02:27:19 2016 Pierre Chauchoy
*/

#include "my_printf.h"
#include "i512.h"

static int	board_is_full(int **grid)
{
  int		y;
  int		x;

  y = -1;
  while (++y < GRID_HEIGHT)
    {
      x = -1;
      while (++x < GRID_WIDTH)
	if (grid[y][x] == CASE_NUM)
	  return (1);
    }
  return (0);
}

int		is_lost(int **grid)
{
  int		y;
  int		x;

  if (board_is_full(grid))
    return (0);
  y = -1;
  while (++y < GRID_HEIGHT)
    {
      x = -1;
      while (++x < GRID_WIDTH)
	{
	  if (x >= 1 && grid[y][x - 1] == grid[y][x])
	    return (0);
	  else if (x <= 2 && grid[y][x + 1] == grid[y][x])
	    return (0);
	  else if (y >= 1 && grid[y - 1][x] == grid[y][x])
	    return (0);
	  else if (y <= 2 && grid[y + 1][x] == grid[y][x])
	    return (0);
	}
    }
  my_printf("%s\n%s\n%s\n", LOSE_MSG, RESTART_MSG, QUIT_MSG);
  return (1);
}

int		is_win(int **grid)
{
  int		y;
  int		x;

  y = -1;
  while (++y < GRID_HEIGHT)
    {
      x = -1;
      while (++x < GRID_WIDTH)
	{
	  if (grid[y][x] == CASE_NUM - 1)
	    {
	      my_printf("%s\n%s\n%s\n", WIN_MSG, RESTART_MSG, QUIT_MSG);
	      return (1);
	    }
	}
    }
  return (0);
}
