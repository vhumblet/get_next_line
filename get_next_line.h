#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

size_t		ft_strlen(char *str);
void		feel_free(char **ptr);
char		*ft_substr(char *s, unsigned int start, size_t len);
char		*ft_strchr(char *s, int c);
char		*ft_strdup(char *s, int fmallok);
char		*ft_strjoin(char *s1, char *s2);
char		*get_next_line(int fd);

#endif