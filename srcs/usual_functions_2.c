/*
** usual_functions_2.c for 512 in /home/chauch_p/temp/2048
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Sat May 14 04:42:59 2016 Pierre Chauchoy
** Last update Sat May 14 04:46:00 2016 Pierre Chauchoy
*/

#include <lapin.h>

void		my_free_inttab(int **tab, int height)
{
  int		y;

  if (!(tab))
    return ;
  y = -1;
  while (tab[++y] && y < height)
    bunny_free(tab[y]);
  bunny_free(tab);
}
