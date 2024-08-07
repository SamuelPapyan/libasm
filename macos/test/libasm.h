# ifndef LIBASM_H
#  define LIBASM_H

size_t  ft_read(int fd, const void *buf, size_t nbyte);
char    *ft_strcpy(char *dest, const char *src);
char    *ft_strdup(const char *s1);
size_t  ft_strlen(char *s);
size_t  ft_write(int fd, const void *buf, size_t count);
int     ft_strcmp(const char *s1, const char *s2);

# endif