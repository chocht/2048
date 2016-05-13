/*
** my_printf.h for 512 in /home/chauch_p/temp/2048
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Fri May 13 02:09:11 2016 Pierre Chauchoy
** Last update Fri May 13 03:00:43 2016 Pierre Chauchoy
*/

#ifndef MY_PRINTF_H_
# define MY_PRINTF_H_

# include		<stdarg.h>

# define NB_LETTERS	12

typedef struct		s_printf
{
  char			letters[NB_LETTERS];
  va_list		ap;
  int			p;
  const char		*s;
  int			fd;
  int			len;
  char			*dest;
  int			sprintf;
}			t_printf;

typedef void		(*t_disp_printf)(t_printf*);

int			my_printf(const char*, ...);
int			my_fprintf(int, const char*, ...);
char			*my_sprintf(const char*, ...);

void			printf_dec(t_printf*);
void			printf_oct(t_printf*);
void			printf_uint(t_printf*);
void			printf_uhex(t_printf*);
void			printf_char(t_printf*);
void			printf_str(t_printf*);
void			printf_str_np(t_printf*);
void			printf_ptr(t_printf*);
void			printf_bin(t_printf*);
void			printf_tab(t_printf*);

char			*add_char_to_dest(char*, char);

#endif /* !MY_PRINTF_H_ */
