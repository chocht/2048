/*
** main.c for 512 in /home/chauch_p/temp/2048
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Fri May 13 02:12:01 2016 Pierre Chauchoy
** Last update Fri May 13 02:54:53 2016 Pierre Chauchoy
*/

#include "my_printf.h"
#include "i512.h"

int			at_exit2(t_data *data)
{
  int			j;

  if (data->win)
    bunny_stop(data->win);
  if (data->pix)
    bunny_delete_clipable((t_bunny_clipable*)data->pix);
  if (data->sprite)
    bunny_delete_clipable((t_bunny_clipable*)data->sprite);
  j = -1;
  while (data->cases[++j])
    if (data->cases[j])
      bunny_delete_clipable((t_bunny_clipable*)data->cases[j]);
  j = -1;
  while (data->grid && data->grid[++j])
    bunny_free(data->grid[j]);
  if (data->grid)
    bunny_free(data->grid);
  return (0);
}

int			at_exit(t_data *data, char *err, int i)
{
  int			j;
  int			y;

  at_exit2(data);
  j = -1;
  while (data->save_grid && data->save_grid[++j])
    {
      y = -1;
      while (data->save_grid[j][++y])
	bunny_free(data->save_grid[j][y]);
      if (data->save_grid[j])
	bunny_free(data->save_grid[j]);
    }
  if (i != 0)
    my_fprintf(2, "%s\n", err);
  return (i);
}

int			scan_argv(t_data *data, char **argv)
{
  int			i;

  i = 0;
  data->key_func[0] = &key_pressed;
  data->key_func[1] = NULL;
  data->index = 1;
  data->spritesheet = NULL;
  while (argv[++i])
    {
      if (my_strcmp(argv[i], DEBUG) == 0 ||
	  my_strcmp(argv[i], DEBUG_LONG) == 0)
	data->index = 0;
      else if (my_strcmp(argv[i], HELP) == 0 ||
	       my_strcmp(argv[i], HELP_LONG) == 0)
	return (1);
      else
	data->spritesheet = argv[i];
    }
  return (0);
}

int			disp_help(char *argv0)
{
  my_printf("USAGE\n");
  my_printf("\t\t%s [%s] [%s] ", argv0, HELP, HELP_LONG);
  my_printf("[%s] [%s] spritesheet_images\n", DEBUG, DEBUG_LONG);
  my_printf("\nDESCRIPTION\n");
  my_printf("\t\t%s or %s to display this help\n", HELP, HELP_LONG);
  my_printf("\t\t%s or %s to display keys\n", DEBUG, DEBUG_LONG);
  my_printf("\nIN GAME\n");
  my_printf("\t\tUse directional keys to move numbers\n");
  my_printf("\t\tPress 'R' to restart\n");
  my_printf("\t\tPress BACKSPACE to undo\n");
  my_printf("\t\tPress 'Y' to redo\n");
  my_printf("\t\tPress ESCAPE to quit\n");
  return (0);
}

int			main(int argc, char **argv)
{
  t_data		data;

  if (argc < 2)
    {
      my_fprintf(2, "Try %s or %s for help\n", HELP, HELP_LONG);
      return (-1);
    }
  if (scan_argv(&data, argv))
    return (disp_help(argv[0]));
  if (init_data(&data, data.spritesheet))
    return (-1);
  bunny_set_key_response(key);
  bunny_set_loop_main_function(mainloop);
  bunny_loop(data.win, 150, &data);
  return (at_exit(&data, NULL, 0));
}
