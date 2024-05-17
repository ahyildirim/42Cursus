#include "push_swap.h"

void push(t_list **dest, t_list **src)
{
	t_list *push_node;

	if(*src == NULL)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if(*src)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	if(*dest == NULL)
	{
		*dest = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dest;
		push_node->next->prev = push_node;
		*dest = push_node;
	}
}

void	pa(t_list **a, t_list **b, int checker)
{
	push(a, b);
	if (!checker)
		write(1, "pa\n", 3);
}

void	pb(t_list **b, t_list **a, int checker)
{
	push(b, a);
	if (!checker)
		write(1, "pb\n", 3);
}