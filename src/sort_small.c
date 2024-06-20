/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:25:41 by ssoeno            #+#    #+#             */
/*   Updated: 2024/06/20 08:33:39 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min(t_list **stack, int value)
{
	t_list	*head;
	int		min;
	
	head = *stack;
	min = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < min) && head->index != value)
			min = head->index;
	}
	return (min);
}

static void	sort_three(t_list **stack_a)
{
	t_list	*head;
	int		min;
	int 	next_min;

	head = *stack_a;
	min = get_min(stack_a, -1);
	next_min = get_min(stack_a, min);
	if (is_sorted(stack_a))
		return ;
	if (head->index == min && head->next->index != next_min)
	//先頭が最小値で、2番目が"次に小さい値"でない場合 つまり1 3 2
	{
		sa(stack_a); //先頭と2番目を入れ替える
		ra(stack_a); //新しい最小値を再びリストの先頭に戻す
	}
	else if (head->index == next_min)
	{
		if (head->next->index == min) //2 1 3
			sa(stack_a);
		else   //2 3 1
			rra(stack_a);
	}
	else
	{
		if (head->next->index == min) //3 1 2
			ra(stack_a);
		else  //3 2 1
		{
			sa(stack_a);
			rra(stack_a);
		}
	}
}

static void	sort_four(t_list **stack_a, t_list **stack_b)
{
	t_list	*head;
	int		min;
	int		next_min;
	
	head = *stack_a;
	min = get_min(stack_a, -1);
	next_min = get_min(stack_a, min);
	while (head->index != min && head->index != next_min)
	{
		ra(stack_a);
		head = *stack_a;
	}
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

static void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	distance = get_distance(stack_a, get_min(stack_a, -1)); //最小値までの距離
	if (distance == 1) //最小値が先頭から一つ下の場合
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (distance == 4)
		rra(stack_a);
	if (is_sorted(stack_a))
		return ;
	pb(stack_a, stack_b); //最小値をstack_bに移動
	sort_four(stack_a, stack_b); //残りの4つの数字をソート
	pa(stack_a, stack_b); //最小値をstack_aに戻す
}

void	sort_small(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) == 2)
		sa(stack_a);
	else if (ft_lstsize(*stack_a) == 3)
		sort_three(stack_a);
	else if (ft_lstsize(*stack_a) == 4)
		sort_four(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) == 5)
		sort_five(stack_a, stack_b);
}