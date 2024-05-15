/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktas <ktas@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:32:25 by ktas              #+#    #+#             */
/*   Updated: 2023/12/15 15:32:26 by ktas             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*jointstr;
	size_t	i;
	size_t	j;

	i = 0;
	j = -1;
	jointstr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2))
			+ 1);
	if (!s1 || !s2)
		return (NULL);
	if (!jointstr)
		return (NULL);
	while (s1[++j])
		jointstr[i++] = s1[j];
	j = -1;
	while (s2[++j])
		jointstr[i++] = s2[j];
	jointstr[i] = '\0';
	return (jointstr);
}
