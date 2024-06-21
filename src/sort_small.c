/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:25:41 by ssoeno            #+#    #+#             */
/*   Updated: 2024/06/21 16:15:28 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_list **stack_a)
{
	size_t first;
	size_t second;
	size_t third;
	
	if (!*stack_a || !(*stack_a)->next || !(*stack_a)->next->next) {
        // 必要な要素が足りない場合、エラーメッセージを表示または適切に処理を終了
        fprintf(stderr, "Not enough elements to perform sort_three\n");
        return;
    }
	first = (*stack_a)->index;
	/* stack_a が指すポインタ（リストの先頭要素へのポインタ）を取り出し、
	その要素が持つ index という名前のメンバにアクセス*/
	second = (*stack_a)->next->index;
	third = (*stack_a)->next->next->index;
	if (first > second && second < third && first < third) //2 1 3
		sa(stack_a);
	else if (first > second && second > third && first > third) //3 2 1
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (first > second && second < third && first > third) //3 1 2
		ra(stack_a);
	else if (first < second && second > third && first < third) //1 3 2
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (first < second && second > third && first > third) //2 3 1
		rra(stack_a);
}

static void	sort_four(t_list **stack_a, t_list **stack_b)
{
	while ((*stack_a)->index != 1) //最小値が先頭に来るまで
		ra(stack_a);
	pb(stack_a, stack_b); //最小値をstack_bに移動
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

static void	sort_five(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_a)->next->next->next->next->index == 1)
	{
		rra(stack_a); //最小値を先頭に持ってくる
		pb(stack_a, stack_b); //最小値をstack_bに移動
	}
	else
	{
		while ((*stack_a)->index != 1) //最小値が先頭に来るまで
			ra(stack_a); //stack_aを回転
		pb(stack_a, stack_b); //最小値をstack_bに移動
	}
	while ((*stack_a)->index != 2) //2番目に小さい値が先頭に来るまで
		ra(stack_a); //stack_aを回転
	pb(stack_a, stack_b); //2番目に小さい値をstack_bに移動
	sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

// static void	sort_five(t_list **stack_a, t_list **stack_b)
// {
// 	int	distance;

// 	distance = get_distance(stack_a, get_min(stack_a, -1)); //最小値までの距離
// 	if (distance == 1) //最小値が先頭から一つ下の場合
// 		ra(stack_a);
// 	else if (distance == 2)
// 	{
// 		ra(stack_a);
// 		ra(stack_a);
// 	}
// 	else if (distance == 3)
// 	{
// 		rra(stack_a);
// 		rra(stack_a);
// 	}
// 	else if (distance == 4)
// 		rra(stack_a);
// 	if (is_sorted(stack_a))
// 		return ;
// 	pb(stack_a, stack_b); //最小値をstack_bに移動
// 	sort_four(stack_a, stack_b); //残りの4つの数字をソート
// 	pa(stack_a, stack_b); //最小値をstack_aに戻す
// }

void	sort_small(t_list **stack_a, t_list **stack_b)
{
	if (!*stack_a)
	{
		printf("sort_small: stack is empty\n"); //debug
		return;
	}
	if (ft_lstsize(*stack_a) == 1 || is_sorted(stack_a))
		return ;
	if (ft_lstsize(*stack_a) == 2)
		sa(stack_a);
	else if (ft_lstsize(*stack_a) == 3)
		sort_three(stack_a);
	else if (ft_lstsize(*stack_a) == 4)
	{
		sort_four(stack_a, stack_b);
	}
	else if (ft_lstsize(*stack_a) == 5)
		sort_five(stack_a, stack_b);
	return ;
}