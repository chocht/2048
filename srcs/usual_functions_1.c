/*
** usual_functions_1.c for 512 in /home/chauch_p/temp/2048
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Fri May 13 02:12:24 2016 Pierre Chauchoy
** Last update Fri May 13 02:29:17 2016 Pierre Chauchoy
*/

#include <unistd.h>
#include "i512.h"

int		my_strlen(char *s)
{
  int		i;

  i = -1;
  while (s[++i]);
  return (i);
}

int		my_strcmp(char *s1, char *s2)
{
  while (*s1 && (*s1 == *s2))
    {
      s1++;
      s2++;
    }
  return (*(unsigned char*)(s1) - *(unsigned char*)(s2));
}

void			fill_pixelarray(t_bunny_pixelarray	*pix,
					unsigned int		color)
{
  t_bunny_position	pos[1];

  pos[0].y = -1;
  while (++pos[0].y < pix->clipable.clip_height)
    {
      pos[0].x = -1;
      while (++pos[0].x < pix->clipable.clip_width)
	tekpixel(pix, pos, color);
    }
}

unsigned int		getpixel(t_bunny_pixelarray	*pix,
				 t_bunny_position	*pos)
{
  return (((unsigned int*)pix->pixels)[(pix->clipable.clip_width * pos->y) +
				       pos->x]);
}

void		        tekpixel(t_bunny_pixelarray	*pix,
				 t_bunny_position	*pos,
				 unsigned int		color)
{
  ((unsigned int *)pix->pixels)[(pix->clipable.clip_width * pos->y) +
				pos->x] = color;
}
