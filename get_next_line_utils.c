#include "get_next_line.h"

size_t ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*substr;
	size_t		i;
	size_t		len_sub;

	if (!s)
		return(NULL);
	i = 0;
	substr = NULL;
	len_sub = ft_strlen(&s[start]);
	if (len_sub > len)
	{
		substr = (char *)malloc(sizeof(char) * len + 1);
		len_sub = len;
	}
	else if (len_sub < len)
		substr = (char *)malloc(sizeof(char) * len_sub + 1);
	if (!substr)
		return(NULL);
	while(s[start + i] && i < len_sub)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = 0;
	return(substr);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	end;

	i = -1;
	end = ft_strlen(s);
	if (c == '\0')
		return ((char *)&s[end]);
	while (s[++i])
		if (s[i] == c)
			return ((char *)&s[i]);
	return (0);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	char	*dup;
	int		i;

	str = (char *)s;
	dup = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (dup == 0)
		return (0);
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

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*s_join;
	int		ls1;
	int		ls2;
	int		t_len;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	t_len = ls1 + ls2;
	s_join = (char *)malloc(sizeof(char) * t_len + 1);
	if (!s_join)
		return(NULL);
	ft_memmove(s_join, s1, ls1);
	ft_memmove(s_join + ls1, s2, ls2);
	s_join[t_len] = 0;
	return (s_join);
}
