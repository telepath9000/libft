/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 14:59:38 by wdebs             #+#    #+#             */
/*   Updated: 2016/12/13 22:41:26 by wdebs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *var;

	var = (void *)malloc(size);
	if (var == NULL)
		return (NULL);
	ft_bzero(var, size);
	return (var);
}
