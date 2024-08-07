#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include "libasm.h"

int main(){
	char dest[40], *src = "IT'S COPY";
	char buff[40];
	char dup[1000];


	int fd = open("foobar.txt", O_RDONLY);
	printf("Errno: %d\n", errno);
	int sz = ft_read(312312, buff, 20);
	printf("Errno: %d\n", errno);
	buff[sz] = 10;// \n
	buff[sz+1] = 0;// \0 
	printf("%zu\n", ft_strlen(""));
	printf("%zu\n", ft_strlen("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Quisque vestibulum mauris id condimentum ornare. Maecenas auctor, sapien ac ultricies scelerisque, turpis ligula mollis elit, id maximus libero ante at ex. In gravida augue lectus, rhoncus volutpat dolor fringilla non. Praesent ac facilisis libero. Curabitur egestas et nisl in placerat. Nulla commodo dui ut velit vehicula porttitor. Aliquam pretium tellus eu ligula pharetra tristique. Aenean quis lacinia tellus. Aenean quis faucibus augue."));
	ft_write(1, buff, ft_strlen(buff));
	close(fd);
	printf("What's up?\n");
	ft_write(1, "Hello?\n", 7);
	ft_strcpy(dup, "");
	ft_write(1, dup, ft_strlen(dup));
	ft_write(1, "\n", 1);
	ft_strcpy(dup, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Quisque vestibulum mauris id condimentum ornare. Maecenas auctor, sapien ac ultricies scelerisque, turpis ligula mollis elit, id maximus libero ante at ex. In gravida augue lectus, rhoncus volutpat dolor fringilla non. Praesent ac facilisis libero. Curabitur egestas et nisl in placerat. Nulla commodo dui ut velit vehicula porttitor. Aliquam pretium tellus eu ligula pharetra tristique. Aenean quis lacinia tellus. Aenean quis faucibus augue.\n");
	errno = 0;
	int sz1 = ft_write(1, dup, ft_strlen(dup));
	printf("SZ: %d\n", sz1);
	int number = ft_write(10, "\n", 1);
	
	printf("Errno: %d | Typed bytes: %d\n", errno, number);
	errno = 0;
	printf("Length: %ld\n", ft_strlen("Hello"));
	printf("Hello VS Hello: %d\n", ft_strcmp("", ""));
	printf("Hello VS hello: %d\n", ft_strcmp("", "hello"));
	printf("hello VS Hello: %d\n", ft_strcmp("hello", ""));
	printf("hello VS Hello: %d\n", ft_strcmp("hello", "hello"));
	printf("hello VS Hello: %d\n", ft_strcmp("hello", "Hello"));
	printf("hello VS Hello: %d\n", ft_strcmp("Hello", "hello"));

	fd = open("foobar1.txt", O_CREAT | O_TRUNC | O_RDWR, 0777);
	ft_write(fd, "HEllo world", 11);
	close(fd);
	number = ft_write(1, "dumba yumba", 10);
	printf("Errno: %d | Typed bytes: %d\n", errno, number);
	int bytes = ft_read(0, buff, 4);
	printf("Errno: %d | Typed bytes: %d\n", errno, bytes);
	errno = 0;
	ft_write(1, buff, ft_strlen(buff));
	ft_write(1, "\n", 1);
	printf("Bytes: %d\n", bytes);

	char *dup1 = ft_strdup("");
	ft_write(1, dup1, ft_strlen(dup1));
	ft_write(1, "\n", 1);
	char *dup2 = ft_strdup("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Integer quis ante at neque accumsan porta. Ut sollicitudin, risus in eleifend iaculis, mi sem posuere enim, quis commodo massa libero in purus. Proin felis justo, rhoncus eget sollicitudin in, sagittis vitae risus. Fusce cursus dignissim lectus ac maximus. Pellentesque mollis auctor dui quis vulputate. Phasellus facilisis justo sit amet dui pretium, pellentesque ultricies orci facilisis. Aliquam condimentum risus ut volutpat elementum. Vestibulum faucibus purus in nulla molestie ultricies. In gravida luctus condimentum. Cras mattis faucibus vulputate. Vestibulum ut nunc urna. Donec quis venenatis orci, sed congue felis. Nullam tincidunt purus ut convallis ultricies. Curabitur suscipit tempus nulla, et tempus nibh lobortis vel. Duis a congue ante. Suspendisse ultricies augue nisl, et semper neque hendrerit id.");
	ft_write(1, dup2, ft_strlen(dup2));
	ft_write(1, "\n", 1);
	free(dup1);
	free(dup2);


	return 0;
}

