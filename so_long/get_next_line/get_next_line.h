/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahyildir <ahyildir@student.42istanbul      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 21:12:25 by ahyildir          #+#    #+#             */
/*   Updated: 2024/05/08 21:43:34 by ahyildir         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

size_t	ftt_strlen(const char *s);
char	*ftt_strdup(const char *s1);
char	*ftt_strjoin(char const *s1, char const *s2);
char	*ftt_substr(char const *s, unsigned int start, size_t len);
char	*ftt_read(int fd, char *str, char *src);
char	*ftt_clean(char	*line);
char	*get_next_line(int fd);
char	*ftt_strchr(const char *s, int c);

#endif
