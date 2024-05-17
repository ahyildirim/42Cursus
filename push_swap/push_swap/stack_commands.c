#include "push_swap.h"

t_list *find_last_node(t_list *a)
{
    if(a == NULL)
        return (NULL);
    while(a->next)
        a = a->next;
    return (a);
}

void add_node(t_list **a, int nbr)
{
    t_list *node;
    t_list *last_node;

    if(a == NULL)
        return ;
    node = malloc(sizeof(t_list));
    if(!node)
        return ;
    node->next = NULL;
	node->value = nbr;
    if(*a == NULL)
    {
        *a = node;
        node->prev = NULL;
    }
    else
    {
        last_node = find_last_node(*a);
        last_node->next = node;
        node->prev = last_node;
    }
}

int stack_len(t_list *a)
{
    int i;

    i = 0;
    if(a == NULL)
        return (0);
    while(a)
    {
        i++;
        a = a->next;
    }
    return (i);
}

void initialize_stack(t_list **a, char **av, int flag)
{
    long    nbr;
    int     i;

    i = 0;
	while(av[i])
    {
        if(syntax_error(av[i]))
            error_free(a, av, flag);
        nbr = ft_atoi(av[i]);
        if(nbr > INT_MAX || nbr < INT_MIN)
            error_free(a, av, flag);
        if(rep_error(*a, (int)nbr))
            error_free(a, av, flag);
        add_node(a, (int)nbr);
		++i;
    }
    if(flag)
        free_av(av);
}

t_list	*return_cheapest(t_list *stack)
{
	if(stack == NULL)
		return (NULL);
	while(stack)
	{
		if(stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

t_list	*smallest_node(t_list *stack)
{
	t_list	*smallest;
	long	min;

	if(stack == NULL)
		return (NULL);
	min = LONG_MAX;
	while(stack)
	{
		if(stack->value < min)
		{
			min = stack->value;
			smallest = stack;
		}
		stack = stack->next;
	}
	return (smallest);
}
