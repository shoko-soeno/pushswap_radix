/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:25:41 by ssoeno            #+#    #+#             */
/*   Updated: 2024/06/20 19:08:32 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min(t_list **stack, int value)
{
	t_list	*head;
	int		min; //見つかった最小値を格納
	
	head = *stack;
	if (!head) {
		printf("get_min: stack is empty\n");
		return -1;  // エラーコードとして -1 を返す
	}
	min = head->index;
	printf("Initial min: %d\n", min); //debug
	while (head->next)
	{
		head = head->next;
		printf("Checking index: %d, current min: %d, excluded value: %d\n", head->index, min, value);
		if ((head->index < min) && head->index != value)
		//現在の要素のindexがminより小さく、かつvalueと異なる場合
		{
			min = head->index;
			printf("Updated min: %d at index: %d\n", min, head->index);//debug
		}
	}
	return (min);
}

static void	sort_three(t_list **stack_a)
{
	t_list	*head;
	int		min;
	int 	next_min;

	if (!*stack_a)
	{
		printf("sort_three: stack is empty\n"); //debug
		return;
	}
	head = *stack_a;
	min = get_min(stack_a, -1);
	printf("sort_three: result of get_min(stack_a, -1) %d\n", min); //debug
	next_min = get_min(stack_a, min);
	printf("sort_three: result of get_min(stack_a, min) %d\n", next_min); //debug
	if (min == next_min) {
        printf("Error: min and next_min are the same, which should not happen.\n");
        return; // Early exit or error handling
    }
	printf("Sorting three: min = %d, next_min = %d\n", min, next_min); //debug
	if (is_sorted(stack_a))
		return ;
	if (head->index == min && head->next->index != next_min)
	//先頭が最小値で、2番目が"次に小さい値"でない場合 つまり1 3 2
	{
		printf("Case 1: head is min and next is not next_min\n");
		sa(stack_a); //先頭と2番目を入れ替える
		ra(stack_a); //新しい最小値を再びリストの先頭に戻す
		printf("Sorting three: min = %d, next_min = %d\n", min, next_min); //debug
	}
	else if (head->index == next_min)
	{
		if (head->next->index == min) //2 1 3
		{
			printf("Case 2: head is next_min and next is min\n");
			sa(stack_a);
		}
		else   //2 3 1
		{
			printf("Case 3: head is next_min\n");
			rra(stack_a);
		}
	}
	else
	{
		if (head->next->index == min) //3 1 2
		{
			printf("Case 4: head is not min or next_min, next is min\n");
			ra(stack_a);
		}
		else  //3 2 1
		{
			printf("Case 5: default case, swap and reverse rotate\n");
			sa(stack_a);
			rra(stack_a);
		}
	}
}

static void	sort_four(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	if (is_sorted(stack_a))
		return ;
	distance = get_distance(stack_a, get_min(stack_a, -1));
	printf("sort_four: min distance = %d\n", distance);
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
		rra(stack_a);
	if (is_sorted(stack_a))
		return ;
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