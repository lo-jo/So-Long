/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:38:34 by ljospin           #+#    #+#             */
/*   Updated: 2022/05/23 11:24:46 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	c -= 32;
	return (c);
}

/* DESCRIPTION
       These functions convert lowercase letters to uppercase, and vice versa.

       If c is a lowercase letter, toupper() returns its uppercase equivalent,
       if an uppercase representation exists in the  current  locale.   Other‐
       wise,  it  returns c.  The toupper_l() function performs the same task,
       but uses the locale referred to by the locale handle locale.

RETURN VALUE
       The value returned is that of the converted letter, or c if the conver‐
       sion was not possible.
*/
