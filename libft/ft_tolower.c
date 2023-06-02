/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:47:12 by ljospin           #+#    #+#             */
/*   Updated: 2022/05/23 11:24:39 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	c += 32;
	return (c);
}
/*
DESCRIPTION
       These functions convert lowercase letters to uppercase, and vice versa.

       If c is a lowercase letter, toupper() returns its uppercase equivalent,
       if an uppercase representation exists in the  current  locale.   Other‐
       wise,  it  returns c.

RETURN VALUE
       The value returned is that of the converted letter, or c if the conver‐
       sion was not possible.

*/
