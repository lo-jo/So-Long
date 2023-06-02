/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:57:46 by ljospin           #+#    #+#             */
/*   Updated: 2022/05/23 15:39:43 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (*lst == NULL)
			*lst = new;
	else
	{
	current = ft_lstlast(*lst);
	current->next = new;
	}
}

/*
1 if head node is null -> it is an empty list\
2 otherwise, find the last node (with ftlast) \
3 add the new node at the end of the linked list\

? if the head pointer is in the last position, in that
case the head pointer itself must be changed
*/
