/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 07:43:34 by ssoeno            #+#    #+#             */
/*   Updated: 2024/06/21 16:18:13 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_list **stack_to, t_list **stack_from)
{
	t_list	*head_from;

	if (ft_lstsize(*stack_from) < 1)
		return (0);
	if (!*stack_from)
		return (0);

	head_from = *stack_from; //stack_fromの先頭をhead_fromに格納
	*stack_from = head_from->next; // 元々のリストの先頭を2番目の要素に更新
	if(!stack_to) //stack_toが空の場合
	{
		head_from->next = NULL; //head_fromの次の要素をNULLに設定
	} else {
		head_from->next = *stack_to; //head_fromの次の要素をstack_toに設定
	}
	*stack_to = head_from; //stack_toの先頭をhead_fromに更新
	return (0);
}

int	pa(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_a, stack_b) == -1)
		return (-1);
	ft_putendl_fd("pa", 1);
	return (0);
}

int	pb(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_b, stack_a) == -1)
		return (-1);
	ft_putendl_fd("pb", 1);
	return (0);
}
