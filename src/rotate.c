/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:25:35 by ssoeno            #+#    #+#             */
/*   Updated: 2024/06/21 18:00:30 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(t_list **stack)
{
	t_list	*head;
	t_list	*last;

	if (ft_lstsize(*stack) < 2) //0-1個の要素しかない
		return (-1);
	head = *stack; //headにスタックの先頭を格納
	last = ft_lstlast(head); //tailにスタックの最後の要素を格納
	*stack = head->next; //スタックの先頭を2番目の要素に更新
	head->next = NULL; //headをリストの最後にする準備
	last->next = head; //tailのnextにheadを設定することで、リストの最後に追加
	/* デバッグ: 結果を出力
    printf("After rotate:\n");
    for (t_list *current = *stack; current != NULL; current = current->next) {
        printf("Node Index: %d Value: %d Next: %p\n", current->index, current->value, (t_list *)current->next);
    } */
	return (0);
}

int	ra(t_list **stack_a)
{
	if (rotate(stack_a) == -1)
		return (-1);
	ft_putendl_fd("ra", 1);
	return (0);
}

int	rb(t_list **stack_b)
{
	if (rotate(stack_b) == -1)
		return (-1);
	ft_putendl_fd("rb", 1);
	return (0);
}

int	rr(t_list **stack_a, t_list **stack_b)
{
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return (-1);
	rotate(stack_a);
	rotate(stack_b);
	ft_putendl_fd("rr", 1);
	return (0);
}

// Shifts down all elements of a stack by 1. The last element becomes the first one | rra and rrb
int	reverseRotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_lstlast(head);
	while (head)
	{
		if (head->next->next == NULL) //listの最後から2番目の要素を見つけたら
		{
			head->next = NULL; //listの末尾を切り離す
			break ;
		}
		head = head->next;
	}
	tail->next = *stack; //切り離されたnodeをtailの先頭にする
	*stack = tail; //tailをlistの先頭に更新
	return (0);
}

int	rra(t_list **stack_a)
{
	if (reverseRotate(stack_a) == -1)
		return (-1);
	ft_putendl_fd("rra", 1);
	return (0);
}

int	rrb(t_list **stack_b)
{
	if (reverseRotate(stack_b) == -1)
		return (-1);
	ft_putendl_fd("rrb", 1);
	return (0);
}

int	rrr(t_list **stack_a, t_list **stack_b)
{
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return (-1);
	reverseRotate(stack_a);
	reverseRotate(stack_b);
	ft_putendl_fd("rrr", 1);
	return (0);
}

