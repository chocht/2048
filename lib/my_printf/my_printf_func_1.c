/*
** my_printf_func_1.c for 512 in /home/chauch_p/temp/2048
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Fri May 13 02:10:30 2016 Pierre Chauchoy
** Last update Fri May 13 02:10:30 2016 Pierre Chauchoy
*/

#include "my_printf.h"

void		fill_display(t_disp_printf *display)
{
  display[0] = &printf_dec;
  display[1] = &printf_dec;
  display[2] = &printf_oct;
  display[3] = &printf_uint;
  display[4] = &printf_uhex;
  display[5] = &printf_uhex;
  display[6] = &printf_char;
  display[7] = &printf_str;
  display[8] = &printf_str_np;
  display[9] = &printf_ptr;
  display[10] = &printf_bin;
  display[11] = &printf_tab;
}

void		fill_printf(const char *s, t_printf *printf)
{
  printf->letters[0] = 'd';
  printf->letters[1] = 'i';
  printf->letters[2] = 'o';
  printf->letters[3] = 'u';
  printf->letters[4] = 'x';
  printf->letters[5] = 'X';
  printf->letters[6] = 'c';
  printf->letters[7] = 's';
  printf->letters[8] = 'S';
  printf->letters[9] = 'p';
  printf->letters[10] = 'b';
  printf->letters[11] = 't';
  printf->p = -1;
  printf->s = s;
  printf->len = 0;
}

void		printf_dec(t_printf *printf)
{
  my_put_nbr_printf(va_arg(printf->ap, int), 10, printf);
}

void		printf_oct(t_printf *printf)
{
  my_put_unsigned_nbr_printf(va_arg(printf->ap, unsigned int), 8, printf);
}

void		printf_uint(t_printf *printf)
{
  my_put_unsigned_nbr_printf(va_arg(printf->ap, unsigned int), 10, printf);
}
