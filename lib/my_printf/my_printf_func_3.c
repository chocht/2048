/*
** my_printf_func_3.c for 512 in /home/chauch_p/temp/2048
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Fri May 13 02:10:55 2016 Pierre Chauchoy
** Last update Fri May 13 02:10:55 2016 Pierre Chauchoy
*/

#include "my_printf.h"

void		printf_bin(t_printf *printf)
{
  my_put_unsigned_nbr_printf(va_arg(printf->ap, int), 2, printf);
}

void		printf_tab(t_printf *printf)
{
  my_show_tab(va_arg(printf->ap, char**), printf);
}
