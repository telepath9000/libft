/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 13:12:13 by wdebs             #+#    #+#             */
/*   Updated: 2016/09/29 23:00:11 by wdebs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc((ft_strlen(s1) + 1) * (sizeof(char)));
	if (str != NULL)
	{
		while (s1[i] != '\0')
		{
			str[i] = s1[i];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	else
		return (NULL);
}
