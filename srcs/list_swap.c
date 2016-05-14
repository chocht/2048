/*
** list_swap.c for lib in /home/chauch_p/librairie/samples/start_doubled_linked_lists
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue Apr 12 03:29:26 2016 Pierre Chauchoy
** Last update Sat May 14 04:13:51 2016 Pierre Chauchoy
*/

#include <stdlib.h>
#include "i512.h"

static void	swap_elem2(t_list	*list,
			   t_elem	*tmp1,
			   t_elem	*tmp2)
{
  t_elem	*one;
  t_elem	*two;

  if (tmp2 == list->tail)
    {
      one = tmp1->prev;
      one->next = tmp2;
      tmp2->prev = one;
      tmp2->next = tmp1;
      tmp1->prev = tmp2;
      tmp1->next = NULL;
      list->tail = tmp1;
    }
  else
    {
      two = tmp1->prev;
      one = tmp2->next;
      one->prev = tmp1;
      tmp1->next = one;
      tmp1->prev = tmp2;
      tmp2->next = tmp1;
      tmp2->prev = two;
      two->next = tmp2;
    }
}

void		swap_elem(t_list	*list,
			  t_elem	*tmp1,
			  t_elem	*tmp2)
{
  t_elem	*one;

  if (list->len == 2)
    {
      tmp1->next = NULL;
      tmp1->prev = tmp2;
      tmp2->next = tmp1;
      tmp2->prev = NULL;
      list->head = tmp2;
      list->tail = tmp1;
    }
  else if (tmp1 == list->head)
    {
      one = tmp2->next;
      one->prev = tmp1;
      tmp1->next = one;
      tmp1->prev = tmp2;
      tmp2->next = tmp1;
      tmp2->prev = NULL;
      list->head = tmp2;
    }
  else
    swap_elem2(list, tmp1, tmp2);
}
