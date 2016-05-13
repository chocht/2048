/*
** my_printf.c for 512 in /home/chauch_p/temp/2048
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Fri May 13 02:10:25 2016 Pierre Chauchoy
** Last update Fri May 13 02:10:25 2016 Pierre Chauchoy
*/

#include <stdlib.h>
#include "my_printf.h"

void		my_display(t_disp_printf *display, t_printf *printf)
{
  int		c;

  c = -1;
  printf->p++;
  while (++c < NB_LETTERS && printf->letters[c] != printf->s[printf->p]);
  if (c < NB_LETTERS)
    if (display[c] != NULL)
      display[c](printf);
}

char		*my_sprintf(const char *s, ...)
{
  t_disp_printf	display[NB_LETTERS];
  t_printf	printf;

  va_start(printf.ap, s);
  fill_printf(s, &printf);
  printf.sprintf = 1;
  if (!(printf.dest = malloc(sizeof(char) * 1)))
    return (NULL);
  printf.dest[0] = '\0';
  fill_display(display);
  while (s[++printf.p] != '\0')
    {
      if (s[printf.p] == '%' && s[printf.p + 1] != '\0')
	my_display(display, &printf);
      else
	my_putchar_printf(s[printf.p], &printf);
    }
  va_end(printf.ap);
  return (printf.dest);
}

int		my_fprintf(int fd, const char *s, ...)
{
  t_disp_printf	display[NB_LETTERS];
  t_printf	printf;

  va_start(printf.ap, s);
  fill_printf(s, &printf);
  printf.fd = fd;
  printf.sprintf = 0;
  fill_display(display);
  while (s[++printf.p] != '\0')
    {
      if (s[printf.p] == '%' && s[printf.p + 1] != '\0')
	my_display(display, &printf);
      else
	my_putchar_printf(s[printf.p], &printf);
    }
  va_end(printf.ap);
  return (printf.len);
}

int		my_printf(const char *s, ...)
{
  t_disp_printf	display[NB_LETTERS];
  t_printf	printf;

  va_start(printf.ap, s);
  fill_printf(s, &printf);
  printf.fd = 1;
  printf.sprintf = 0;
  fill_display(display);
  while (s[++printf.p] != '\0')
    {
      if (s[printf.p] == '%' && s[printf.p + 1] != '\0')
	my_display(display, &printf);
      else
	my_putchar_printf(s[printf.p], &printf);
    }
  va_end(printf.ap);
  return (printf.len);
}
