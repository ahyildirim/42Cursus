/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahyildir <ahyildir@student.42istanbul      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 21:42:06 by ahyildir          #+#    #+#             */
/*   Updated: 2024/05/08 21:42:07 by ahyildir         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ns;

	i = 0;
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	ns = malloc(sizeof(char) * (len + 1));
	if (ns == NULL)
		return (NULL);
	while (s[start] && len > 0)
	{
		ns[i] = *(char *)(s + start);
		i++;
		start++;
		len--;
	}
	ns[i] = '\0';
	return (ns);
}
