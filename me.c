#include <stdio.h>
//#include <libasm.a>

int main(){
	char *dest = "Hello World 2!";
//	char *dup = NULL;
	//ft_strcpy(dest, "Hello World 2!");
	ft_write(0, dest, ft_strlen(dest));
	//printf("%s\n", dest);
//	dup = ft_strdup("Geloo dumboll!");
//	printf("%s\n", dup);
	return 0;
}

