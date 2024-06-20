/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:25:32 by ssoeno            #+#    #+#             */
/*   Updated: 2024/06/20 08:34:18 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_stack(t_list **stack, int argc, char **argv)
{
	t_list	*new;
	char	**values = NULL;
	size_t	i;

	i = 0;
	if (argc == 2){ //argc == 2 の条件が真の場合、values に値が割り当てられない
		values = ft_split(argv[1], ' ');
	}
	else
	{
		i = 1;
		values = argv;
	}
	while (values && values[i])
	{
		printf("Processing value: %s\n", values[i]); //debug
		new = ft_lstnew(ft_atoi(values[i])); //atoiにエラーハンドリングがないから追加しなきゃ
		ft_lstadd_back(stack, new);
		i++;
	}
	index_compression(stack);
	printf("Index compression completed.\n"); //debug
	if (argc == 2 && values)
		ft_free(values);
	// ft_split で割り当てられたメモリを解放。
	// argc != 2 の場合、values = argv（外部から渡される引数）なので解放する必要がない
}

static void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) <= 5)
		sort_small(stack_a, stack_b);
	// else
	// 	radix_sort(stack_a, stack_b);
	printList(*stack_a);
}

int	main(int argc, char *argv[])
{
	t_list	**stack_a;
	t_list	**stack_b;
	
	(void)argv;
	if (argc < 2)
	{
		ft_putstr_fd("input error", 1);
		return (-1);
	}
	ft_check_args(argc, argv);
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	*stack_b = NULL;
	init_stack(stack_a, argc, argv);
	if (is_sorted(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return (0);
	}
	sort_stack(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
