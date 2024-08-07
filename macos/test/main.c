#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include "libasm.h"

int main(){
	char dest[40], *src = "IT'S COPY";
	char buff[40];
	char dup[40];


	int fd = open("foobar.txt", O_RDONLY);
	int sz = ft_read(fd, buff, 20);
	buff[sz] = 10;// \n
	buff[sz+1] = 0;// \0 
	ft_write(0, buff, ft_strlen(buff));
	close(fd);
	printf("What's up?\n");
	ft_write(0, "Hello?\n", 7)
	
	char *dup2 = ft_strdup("Hello World DUP!!");
	ft_strcpy(dup, "Hello World 3!");
	ft_write(0, dup2, ft_strlen(dest));
	ft_write(0, "\n", 1);
	ft_write(0, dup, ft_strlen(dup));
	ft_write(0, "Hello\n", 6);
	printf("Length: %ld\n", ft_strlen("Hello"));
	printf("Hello VS Hello: %d\n", ft_strcmp("Hello", "Hello"));
	printf("Hello VS hello: %d\n", ft_strcmp("Hello", "hello"));
	printf("hello VS Hello: %d\n", ft_strcmp("hello", "Hello"));
	char *cpyStr = ft_strcpy(dest, src);
	printf("Copied text %s\n", dest);
	ft_write(0, dup2, ft_strlen(dup2));
	ft_write(0, "\n", 1);
	ft_write(0, cpyStr, ft_strlen(cpyStr));
	free(dup2);
	printf("\n");
	return 0;
}

