/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahyildir <ahyildir@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 20:51:45 by ahyildir          #+#    #+#             */
/*   Updated: 2023/12/15 20:51:45 by ahyildir         ###   ########.tr       */
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
