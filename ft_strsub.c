/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 22:10:38 by wdebs             #+#    #+#             */
/*   Updated: 2016/09/30 01:06:15 by wdebs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	new_str = (char *)malloc(len + 1);
	if (new_str != NULL)
	{
		while (i < len)
		{
			new_str[i] = s[start];
			i++;
			start++;
		}
		new_str[i] = '\0';
		return (new_str);
	}
	return (NULL);
}
