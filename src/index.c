/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 22:42:53 by ssoeno            #+#    #+#             */
/*   Updated: 2024/06/21 16:19:42 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//stack の中でまだインデックスが振られていない（index == -1）要素の中から
//最小の value を持つ要素を見つけて返す。
static t_list	*get_next_min(t_list **stack)
{
	t_list	*head;
	t_list	*min;

	min = NULL; //最小値を持つ要素へのポインタ
	head = *stack; //stackの先頭から操作するためのポインタ
	while (head)
	{
			if ((head->index == -1) && (!min || head->value < min->value))
				min = head;
			head = head->next;
	}
	return (min);
}

void	index_compression(t_list **stack)
{
	t_list	*head;
	int		index;

	index = 1;
	head = get_next_min(stack); //まだインデックスが振られていない最小の要素を取得
	while (head)
	{
		head->index = index++; //現在のindexを設定してからindexをインクリメント
		printf("Assigning index %d to value %d\n", index, head->value); //debug
		head = get_next_min(stack);
		//headがNULLになるまで（全ての要素にindexが振られるまで）繰り返す
	}
	// printf("Index compression completed.\n");  // debug
}