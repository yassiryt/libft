/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatanagh <yatanagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:29:15 by yatanagh          #+#    #+#             */
/*   Updated: 2024/11/15 15:48:09 by yatanagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t i;
	size_t ii;
	char *rs;

	i = 0;
	ii = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (strdup(s2));
	if (!s2)
		return (strdup(s1));
	rs = (char *)malloc(strlen(s1) + strlen(s2) + 1);
	while (s1[i])
		rs[ii++] = s1[i++];
	i = 0;
	while (s2[i])
		rs[ii++] = s2[i++];
	rs[ii] = '\0';
	return (rs);
}
