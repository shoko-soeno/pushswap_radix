/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 07:43:34 by ssoeno            #+#    #+#             */
/*   Updated: 2024/06/20 08:32:39 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Takes the first element of one stack and 
// puts it at the top of another | pa and pb
int	push(t_list **stack_to, t_list **stack_from)
{
	t_list	*tmp;
	t_list	*head_to;
	t_list	*head_from;

	if (ft_lstsize(*stack_from) < 1)
		return (0);
	if (!*stack_from)
		return (0);
	head_to = *stack_to;
	head_from = *stack_from;
	tmp = head_from->next; // 2番目の要素のポインタをtmpに格納
	*stack_from = tmp; // 元々のリストの先頭を2番目の要素に更新
	if(!head_to) // toスタックが空の場合
	{
		head_to = tmp; // toスタックの最初の要素としてtmpを設定
		head_to->next = NULL; // tmpの次の要素をNULLに設定
		*stack_to = head_to; // toスタックの先頭を更新
	}
	else //toスタックが空でない場合
	{
		tmp->next = head_to; // tmpをtoスタックの先頭として更新
		*stack_to = tmp; // toスタックの先頭がtmpの次の要素になる
	}
	return (0);
}

int	pa(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_a, stack_b) == -1)
		return (-1);
	ft_putendl_fd("pa\n", 1);
	return (0);
}

int	pb(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_b, stack_a) == -1)
		return (-1);
	ft_putendl_fd("pb\n", 1);
	return (0);
}
