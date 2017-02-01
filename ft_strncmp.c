/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 17:52:59 by wdebs             #+#    #+#             */
/*   Updated: 2016/09/26 00:33:55 by wdebs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	int				result;
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	i = 0;
	tmp1 = (unsigned char *)s1;
	tmp2 = (unsigned char *)s2;
	while ((tmp1[i] != '\0' || tmp2[i] != '\0') && i < n)
	{
		result = tmp1[i] - tmp2[i];
		if (result != 0)
			return (result);
		i++;
	}
	return (0);
}
