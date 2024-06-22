/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:25:32 by ssoeno            #+#    #+#             */
/*   Updated: 2024/06/22 14:29:23 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//debug用
void print_stack_state_main(t_list *stack) {
    t_list *current = stack;
    int count = 0;
    while (current) {
        printf("Node %d: Index: %d, Value: %d, Next: %p\n",
               count++, current->index, current->value, (t_list *)current->next);
        current = current->next;
    }
}

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
		// printf("Processing value: %s\n", values[i]); //debug
		new = ft_lstnew(ft_atoi(values[i])); //atoiにエラーハンドリングがないから追加しなきゃ
		ft_lstadd_back(stack, new);
		i++;
	}
	index_compression(stack);
	/* リストの現在の状態をデバッグ出力
   	t_list *current = *stack;
    int node_count = 0;
    printf("Current stack state after index compression:\n");
    while (current) {
        printf("Node %d: Index: %d, Value: %d, Next: %p\n", 
               node_count, current->index, current->value, (void *)current->next);
        current = current->next;
        node_count++;
    }
	ここまでdebug */
	if (argc == 2 && values)
		ft_free(values);
	// ft_split で割り当てられたメモリを解放。
	// argc != 2 の場合、values = argv（外部から渡される引数）なので解放する必要がない
}

static void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	// printf("ft_lstsize %d\n", ft_lstsize(*stack_a)); //debug
	if (ft_lstsize(*stack_a) <= 5)
		sort_small(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
	//printList(*stack_a);
}


#include <libc.h>
// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q push_swap");
// }

int	main(int argc, char *argv[])
{
	t_list	**stack_a;
	t_list	**stack_b;
	
	if (argc < 2)
		return (1); //not -1!!
	if (!ft_check_args(argc, argv))
		return (1);
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	*stack_b = NULL;
	init_stack(stack_a, argc, argv);
	// printf("Stack A initialized.\n"); //debug
	if (is_sorted(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return (0);
	}
	// printf("After is_sorted:\n");
	// print_stack_state_main(*stack_a); //debug
	sort_stack(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
