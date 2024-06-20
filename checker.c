/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 00:10:03 by ssoeno            #+#    #+#             */
/*   Updated: 2024/06/20 00:13:50 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	do_commands(char *line, t_list **stack_a, t_list **stack_b)
{
	if (!(ft_strncmp(line, "sa", 2)))
	{
		swap(stack_a);
		return (0);
	}
	if (!(ft_strncmp(line, "sb", 2)))
	{
		swap(stack_b);
		return (0);
	}
	if (!(ft_strncmp(line, "ss", 2)))
	{
		swap(stack_a);
		swap(stack_b);
		return (0);
	}
	if (!(ft_strncmp(line, "pa", 2)))
	{
		push(stack_a, stack_b);
		return (0);
	}
	if (!(ft_strncmp(line, "pb", 2)))
	{
		push(stack_b, stack_a);
		return (0);
	}
	// if (!(ft_strcmp(line, "ra")))
	// {
	// 	rotate(stack_a);
	// 	return (0);
	// }
	// if (!(ft_strcmp(line, "rb")))
	// {
	// 	rotate(stack_b);
	// 	return (0);
	// }
	// if (!(ft_strcmp(line, "rr")))
	// {
	// 	rotate(stack_a);
	// 	rotate(stack_b);
	// 	return (0);
	// }
	// if (!(ft_strcmp(line, "rra")))
	// {
	// 	reverseRotate(stack_a);
	// 	return (0);
	// }
	// if (!(ft_strcmp(line, "rrb")))
	// {
	// 	reverseRotate(stack_b);
	// 	return (0);
	// }	
	// if (!(ft_strcmp(line, "rrr")))
	// {
	// 	reverseRotate(stack_a);
	// 	reverseRotate(stack_b);
	// 	return (0);
	// }
	return (1);
}

void	print_checker_res(t_list **stack_a, t_list **stack_b)
{
	if (is_sorted(stack_a))
		ft_putendl_fd("OK\n", 1);
	else
		ft_putendl_fd("KO\n", 1);
	if (*stack_a)
		free_stack(stack_a);
	if (*stack_b)
		free_stack(stack_b);
}

static void	initStack(t_list **stack, int argc, char **argv)
{
	t_list	*new;
	char	**args;
	int		i;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		new = ft_lstnew(ft_atoi(args[i]));
		ft_lstadd_back(stack, new);
		i++;
	}
	index_compression(stack);
	if (argc == 2)
		ft_free(args);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;
	// char	*line;

	if (argc < 2)
		return (0);
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	*stack_b = NULL;
	ft_check_args(argc, argv);
	initStack(stack_a, argc, argv);
	// while (get_next_line(0, &line))
	// {
	// 	if (do_commands(line, stack_a, stack_b))
	// 	{
	// 		ft_error("Error");
	// 		return (-1);
	// 	}
	// 	free(line);
	// }
	// print_checker_res(stack_a, stack_b);
	return (0);
}