#include "get_next_line.h"

size_t ft_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char **s, unsigned int start, size_t len)
{
	char		*substr;
	size_t		i;
	size_t		len_sub;

	if (start >= ft_strlen(*s))
		return (NULL);
	i = 0;
	substr = NULL;
	len_sub = ft_strlen((*s) + start);
	if (len_sub > len)
	{
		substr = (char *)malloc(sizeof(char) * len + 1);
		len_sub = len;
	}
	else if (len_sub < len)
		substr = (char *)malloc(sizeof(char) * len_sub + 1);
	if (!substr)
		return (feel_free(&substr), free(*s), *s = NULL, NULL);
	while ((*s)[start + i] && i < len_sub)
	{
		substr[i] = (*s)[start + i];
		i++;
	}
	substr[i] = 0;
	return (substr);
}

char	*ft_strchr(char *s, int c)
{
	int	i;
	int	end;

	i = -1;
	end = ft_strlen(s);
	if (c == '\0')
		return (&s[end]);
	while (s[++i])
		if (s[i] == c)
			return (&s[i]);
	return (0);
}

char	*ft_strdup(char *s, int fmallok)
{
	char	*dup;
	int		i;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	if (i <= 0)
		return (NULL);
	dup = (char *)malloc(sizeof(char) * (i + 1));
	if (!dup)
	{
		if (fmallok != 0)
			feel_free(&s);
		return (feel_free(&dup), NULL);
	}
	i = -1;
	while (s[++i])
		dup[i] = s[i];
	dup[i] = '\0';
	if (fmallok == 0)
		return (s = NULL, dup);
	return (feel_free(&s), dup);
}

char	*ft_strjoin(char **s1, char *s2)
{
	char	*s_join;
	int		i;
	int		j;

	if (*s1 && !s2)
		return (NULL);
	if (!*s1 && s2)
		return (feel_free(s1), ft_strdup(s2, 0));
	i = -1;
	j = -1;
	s_join = (char *)malloc(sizeof(char) * (ft_strlen(*s1) + ft_strlen(s2) + 1));
	if (!s_join)
		return(feel_free(s1), feel_free(&s_join), NULL);
	while ((*s1)[++i])
		s_join[i] = (*s1)[i];
	while (s2[++j])
		s_join[i + j] = s2[j];
	s_join[i + j] = 0;
	return (feel_free(s1), s_join);
}
