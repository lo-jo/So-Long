/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:10:48 by ljospin           #+#    #+#             */
/*   Updated: 2022/05/23 15:33:27 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*current;

	current = lst;
	if (!lst || !f)
		return ;
	while (current != NULL)
	{
		(*f)(current->content);
		current = current->next;
	}
}

/*
1) The local pointer, current in this case, starts by pointing to the same
node as the head pointer with current = head;. When the function
exits, current is automatically deallocated since it is just an ordinary
local, but the nodes in the heap remain.
2) The while loop tests for the end of the list with (current != NULL).
This test smoothly catches the empty list case — current will be NULL
on the first iteration and the while loop will just exit before the first
iteration.
3) At the bottom of the while loop, current = current->next;
advances the local pointer to the next node in the list. When there are no
more links, this sets the pointer to NULL.
*/
