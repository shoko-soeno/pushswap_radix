/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:25:28 by ssoeno            #+#    #+#             */
/*   Updated: 2024/06/20 09:56:29 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//スタック内の要素の index 値の最大値を求め、その値を表現するのに必要なビット数を計算
static int	get_max_bits(t_list **stack)
{
	t_list	*head;
	int		max;
	int		max_bits;

	head = *stack;
	max = head->index; //最初の要素の index を max に設定
	max_bits = 0;
	while (head) //index の最大値を求めるためのループ
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	// 最大の index 値を右シフトしながらカウントし、0になるまでのビット数（max_bits）を数える
	// max の最上位ビットから max_bits 個のビットを右にシフト（元々の最下位ビットは捨てられる）
	// その値が 0 になるまで、max_bits をインクリメント
	while ((max >> max_bits) != 0) //max の値の上位にまだ 0 以外のビットが存在している間
		max_bits++;
	return (max_bits);
}
/* 例えば
max = 10 (バイナリで 1010) 、最初の max_bits が 3 とする
max >> 3 は 1010 を 3 ビット右にシフトして 0001 となります。
この結果は 0 ではないため、このシフト後に残る 1 は、
元の max の値の中でまだ重要なビットが残っていることを意味します。
そのため、max_bits をさらに増やす必要があります。

max = 10、バイナリで 1010
初期値 max_bits = 0
イテレーション1:

max >> 0 = 1010 (10)
結果は 0 ではないので max_bits を 1 にインクリメント。
イテレーション2:

max >> 1 = 0101 (5)
結果は 0 ではないので max_bits を 2 にインクリメント。
イテレーション3:

max >> 2 = 0010 (2)
結果は 0 ではないので max_bits を 3 にインクリメント。
イテレーション4:

max >> 3 = 0001 (1)
結果は 0 ではないので max_bits を 4 にインクリメント。
イテレーション5:

max >> 4 = 0000 (0)
結果が 0 なのでループを終了。最終的な max_bits は 4 です。
*/

/*
radix_sort
stack_a の要素を index のビットごとにソートし、必要時に stack_b を使用

size を stack_a のサイズに設定
max_bits を get_max_bits 関数を使って取得
各ビットに対してループを実行し、i が 0 から max_bits 未満である間
stack_a の各要素に対して、現在のビット i が 1 かどうかをチェック
ビットが 1 の場合、その要素は stack_a 内で回転操作（ra）を行い、元の位置に戻す
ビットが 0 の場合、その要素を stack_a から stack_b へ移動する（pb）
stack_b にあるすべての要素を stack_a に戻す（pa）
これで一つのビットレベルのソートが完了。
すべてのビットレベルでソートが完了すると、stack_a は完全にソートされた状態になる
*/

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*head_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	head_a = *stack_a;
	size = ft_lstsize(head_a);
	max_bits = get_max_bits(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = *stack_a;
			if (((head_a->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (ft_lstsize(*stack_b) != 0)
			pa(stack_a, stack_b);
		i++;
	}
}