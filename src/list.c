/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 00:07:31 by ssoeno            #+#    #+#             */
/*   Updated: 2024/06/21 16:16:44 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int value)
{
	t_list	*new;

	new = (t_list *) malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = -1; // -1 means that the index is not set
	new->next = NULL;
	//printf("Created new node with value %d\n", new->value); //debug
	return (new);
}

void	ft_lstadd_front(t_list **stack, t_list *new)
{
	new->next = *stack;
	*stack = new;
}

t_list	*ft_lstlast(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	if (!tmp)
		return (NULL);
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	return (tmp); //listの最後の要素を返す
}

void	ft_lstadd_back(t_list **stack, t_list *new)
{
	t_list	*last;

	if (!*stack) // リストが空の場合、新しいノードを先頭にする
	{
		*stack = new;
		new->next = NULL;
	}
	else
	{
		last = ft_lstlast(*stack);
		last->next = new;
		new->next = NULL; // 新しいノードのnextをNULLに設定してリストの終端を明示
	}
}

int	ft_lstsize(t_list *head)
{
	size_t	i;
	t_list	*tmp;

	tmp = head;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	printList(t_list *head)
{
	t_list	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		ft_putnbr_fd(tmp->value, 1);
		ft_putendl_fd("", 1);
		tmp = tmp->next;
	}
}
