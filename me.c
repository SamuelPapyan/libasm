#include <stdio.h>
// size_t   read(int fd, const void *buf, size_t nbyte);
char  *ft_strcpy(char *dest, const char *src);
char	*ft_strdup(const char *s1);
size_t    ft_strlen(char *s);
size_t   ft_write(int fd, const void *buf, size_t count);

int main(){
	char *dest = "Hello World 2!";
	char dup[40];
	char *dup2 = ft_strdup("Hello World DUP!!");
	ft_strcpy(dup, "Hello World 3!");
	ft_write(0, dest, ft_strlen(dest));
	ft_write(0, "\n", 1);
	ft_write(0, dup, ft_strlen(dup));
	ft_write(0, "\n", 1);
	ft_write(0, dup2, ft_strlen(dup2));
	// printf("%s\n", dest);
//	dup = ft_strdup("Geloo dumboll!");
//	printf("%s\n", dup);
	return 0;
}

