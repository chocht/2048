/*
** my_printf_func_5.c for 512 in /home/chauch_p/temp/2048
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Fri May 13 02:11:04 2016 Pierre Chauchoy
** Last update Fri May 13 02:11:04 2016 Pierre Chauchoy
*/

#include <stdlib.h>
#include "my_printf.h"

void		my_show_tab(char **tab, t_printf *printf)
{
  int		i;

  i = -1;
  while (tab[++i] != NULL)
    {
      my_putstr_printf(tab[i], printf);
      my_putchar_printf('\n', printf);
    }
}

char		*add_char_to_dest(char *dest, char c)
{
  char		*tmp;
  int		len;
  int		i;

  len = my_strlen(dest);
  if (!(tmp = malloc(sizeof(char) * (len + 1 + 1))))
    return (NULL);
  i = -1;
  while (++i < len)
    tmp[i] = dest[i];
  free(dest);
  tmp[i++] = c;
  tmp[i++] = '\0';
  return (tmp);
}
