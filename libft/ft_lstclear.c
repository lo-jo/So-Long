/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:04:23 by ljospin           #+#    #+#             */
/*   Updated: 2022/05/23 15:35:01 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*nextract;

	current = *lst;
	if (!lst)
		return ;
	while (current != NULL)
	{
		nextract = current->next;
		(*del)(current->content);
		free(current);
		current = nextract;
	}
	*lst = NULL;
}

/*
lst: L’adresse du pointeur vers un élément.
del: L’adresse de la fonction permettant de
supprimer le contenu d’un élément.
DESCRIPTION
Supprime et libère la mémoire de l’élément passé en
paramètre, et de tous les éléments qui suivent, à
l’aide de ’del’ et de free(3)
Enfin, le pointeur initial doit être mis à NULL.

1. deref lst to get the real position
2. if lst is empty return
3. the next pointer need to be extracted inside the loop
	before deleting the node since after it is deleted
	it will technically be unavailable.
*/
