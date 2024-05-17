#include "checker.h"

static int ft_strcmp(char *str1, char *str2)
{
    	while (*str1 == *str2
		&& *str1)
	{
	    str1++;
		str2++;
	}
	return (*str1 - *str2);
}

static void checker_error(t_list **a, t_list **b)
{
    free_stack(a);
    free_stack(b);
    (void)!write(2, "Error\n", 6);
    exit(1);
}

static void cmp_commands(t_list **a, t_list **b, char *command)
{
    if(!ft_strcmp(command, "pa\n"))
        pa(a, b, 1);
    else if(!ft_strcmp(command, "pb\n"))
        pb(b, a, 1);
    else if(!ft_strcmp(command, "sa\n"))
        sa(a, 1);
    else if(!ft_strcmp(command, "sb\n"))
        sb(b, 1);
    else if(!ft_strcmp(command, "ra\n"))
        ra(a, 1);
    else if(!ft_strcmp(command, "rb\n"))
        rb(b, 1);
    else if(!ft_strcmp(command, "rr\n"))
        rr(a, b, 1);
    else if(!ft_strcmp(command, "rra\n"))
        rra(a, 1);
    else if(!ft_strcmp(command, "rrb\n"))
        rrb(b, 1);
    else if(!ft_strcmp(command, "rrr\n"))
        rrr(a, b, 1);
    else if(!ft_strcmp(command, "pa\n"))
        pa(a, b, 1);
    else
        checker_error(a, b);
}

int main(int ac, char **av)
{
    t_list *a;
    t_list *b;
    char    *next_line;
    int     len;

    a = NULL;
    b = NULL;
    if(ac == 1)
        return (1);
    else if(ac == 2)
        av = ft_split(av[1], ' ');
    initialize_stack(&a, &av[1], ac == 2);
    len = stack_len(a);
    next_line = get_next_line(STDIN_FILENO);
    while(next_line)
    {
        cmp_commands(&a, &b, next_line);
        next_line = get_next_line(STDIN_FILENO);
    }
    if(is_sorted(a) && stack_len(a) == len)
        (void)!write(1, "OK\n", 3);
    else
        (void)!write(1, "KO\n", 3);
    free(a);
    return (0);
}