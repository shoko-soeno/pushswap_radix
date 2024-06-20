/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 22:42:53 by ssoeno            #+#    #+#             */
/*   Updated: 2024/06/20 18:54:12 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//stack の中でまだインデックスが振られていない（index == -1）要素の中から
//最小の value を持つ要素を見つけて返す。
static t_list	*get_next_min(t_list **stack)
{
	t_list	*head;
	t_list	*min;
	int		has_min;

	min = NULL; //最小値を持つ要素へのポインタ
	has_min = 0; //最小値が見つかったかどうかを示すフラグ
	head = *stack; //stackの先頭から操作するためのポインタ
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && (!has_min || head->value < min->value))
			{
				min = head; //headをminに設定
				has_min = 1; //最小値が見つかったことを示すフラグを立てる→次からhead->value < min->valueで判定
				//!has_min==0(まだ最小値が見つかってない)：現在の要素を暫定の最小値とする
				//head->valueがmin->valueより小さい：新しい最小値を現在の要素に更新
			}
			head = head->next;
		}
	}
	return (min);
}

void	index_compression(t_list **stack)
{
	t_list	*head;
	int		index;

	index = 0;
	head = get_next_min(stack); //まだインデックスが振られていない最小の要素を取得
	while (head)
	{
		head->index = index++; //現在のindexを設定してからindexをインクリメント
		head = get_next_min(stack);
		//headがNULLになるまで（全ての要素にindexが振られるまで）繰り返す
	}
}