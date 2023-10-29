#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H


#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_left_read(int fd, char *str);
char	*fetch_line(char *left_str);
char	*ft_new_left_str(char *left_str);
size_t	ft_strlen(char *str);
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char *left_str, char *buff);

#endif
