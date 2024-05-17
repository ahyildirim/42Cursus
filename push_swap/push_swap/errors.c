#include "push_swap.h"

void free_stack(t_list **a)
{
    t_list *tmp;
    t_list *current;

    if(a == NULL)
        return ;
    current = *a;
    while(current)
    {
        tmp = current->next;
        free(current);
        current = tmp;
    }
    *a = NULL;
}

void free_av(char **av)
{
    int i;
    
    i = -1;
    if(av == NULL || *av == NULL)
        return ;
    while(av[++i])
        free(av[i]);
    free(av - 1); //?
}

void error_free(t_list **a, char **av, int flag)
{
    free_stack(a);
    if(flag)
        free_av(av);
    write(2, "Error\n", 6);
    exit(1);
}

int rep_error(t_list *a, int nbr)
{
    if(a == NULL)
        return (0);
    while(a)
    {
        if(a->value == nbr)
            return (1);
        a = a->next;
    }
    return (0);
}

int syntax_error(char *av)
{
    int i;

    i = 1;
    if(!(av[0] == '+' || av[0] == '-' || (av[0] <= '9' && av[0] >='0')))
        return (1);
    if((av[0] == '+' || av[0] == '-') && !(av[1] <= '9' && av[1] >= '0'))
        return (1);
    while(av[i])
	{
        if(!(av[i] <= '9' && av[i] >= '0'))
            return (1);
		i++;
	}
    return (0);
}