/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhumblet <vhumblet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:50:00 by vhumblet          #+#    #+#             */
/*   Updated: 2024/11/08 12:49:22 by vhumblet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;
	int	end;

	i = -1;
	end = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)&s[end]);
	while (s[++i])
		if (s[i] == (char)c)
			return ((char *)&s[i]);
	return (0);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char		*substr;
	ssize_t		i;
	size_t		len_sub;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	i = -1;
	substr = NULL;
	len_sub = ft_strlen(&s[start]);
	if (len_sub >= len)
	{
		substr = (char *)malloc(sizeof(char) * len + 1);
		len_sub = len;
	}
	else if (len_sub <= len)
		substr = (char *)malloc(sizeof(char) * len_sub + 1);
	if (!substr)
		return (NULL);
	while (++i < (ssize_t)len_sub && s[start + i] != '\0')
		substr[i] = s[start + i];
	substr[i] = 0;
	return (substr);
}

char	*ft_strdup(char *s)
{
	char	*str;
	char	*dup;
	int		i;

	str = s;
	dup = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!dup)
		return (NULL);
	if (!str)
	{
		*dup = '\0';
		return (dup);
	}
	i = 0;
	while (*str)
	{
		dup[i] = *str;
		str++;
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s_join;
	int		i;

	i = -1;
	if (!s1 && !s2)
		return (ft_strdup(""));
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	s_join = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!s_join)
		return (NULL);
	while (s1[++i])
		s_join[i] = s1[i];
	i = -1;
	while (s2[++i])
		s_join[i + ft_strlen(s1)] = s2[i];
	s_join[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	return (s_join);
}
