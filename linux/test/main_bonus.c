#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct s_list
{
    void            *data;
    struct s_list   *next;
}                   t_list;


int		ft_atoi_base(char *str, char *base);
t_list	*ft_list_create_elem(void *data);
void	ft_list_push_front(t_list **begin_list, void *data);
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());
int		ft_list_size(t_list *begin_list);
void	ft_list_sort(t_list **begin_list, int (*cmp)());

size_t   ft_read(int fd, const void *buf, size_t nbyte);
char  *ft_strcpy(char *dest, const char *src);
char	*ft_strdup(const char *s1);
size_t    ft_strlen(char *s);
size_t   ft_write(int fd, const void *buf, size_t count);
int   ft_strcmp(const char *s1, const char *s2);

int compare(void *a, void *b) {
    return !((int)a == (int)b);
}

int sortDesc(void *a, void *b) {
    return !((int)a > (int)b);
}

int strSortDesc(void *a, void *b) {
    return ft_strcmp((char *)a, (char *)b) < 0; 
}

int strSortAsc(void *a, void *b) {
    return ft_strcmp((char *)a, (char *)b) > 0; 
}

int sortAsc(void *a, void *b) {
    return !((int)a < (int)b);
}

int main() {
    // t_list *lst = ft_list_create_elem(42);
    // ft_list_push_front(&lst, (void *)45);
    // ft_list_push_front(&lst, (void *)47);
    // ft_list_push_front(&lst, (void *)48);
    // ft_list_push_front(&lst, (void *)41);
    // t_list *tmp = lst;
    // printf("Length: %d\n", ft_list_size(lst));
    // while (tmp) {
    //     printf("%d\n", (int)(tmp->data));
    //     tmp = tmp->next;
    // }
    // int number = ft_atoi_base("111111", "01");
    // printf("111111 in Base-2 is: %d\n", number);

    // ft_list_remove_if(&lst, (void *)47, &compare);
    // ft_list_remove_if(&lst, (void *)47, &compare);

    // tmp = lst;
    // printf("Length: %d\n", ft_list_size(lst));
    // while (tmp) {
    //     printf("%d\n", (int)(tmp->data));
    //     tmp = tmp->next;
    // }

    // ft_list_sort(&lst, &sortAsc);

    // tmp = lst;
    // printf("Length: %d\n", ft_list_size(lst));
    // while (tmp) {
    //     printf("%d\n", (int)(tmp->data));
    //     tmp = tmp->next;
    // }
    t_list *lst = ft_list_create_elem("Hello");
    ft_list_push_front(&lst, "World");
    ft_list_push_front(&lst, "OF");
    ft_list_push_front(&lst, "HEROSHIP");
    ft_list_push_front(&lst, "42");
    t_list *tmp = lst;
    printf("Length: %d\n", ft_list_size(lst));
    while (tmp) {
        printf("%s\n", (int)(tmp->data));
        tmp = tmp->next;
    }
    int number = ft_atoi_base("111111", "01");
    printf("111111 in Base-2 is: %d\n", number);

    ft_list_remove_if(&lst, "OF", &ft_strcmp);
    ft_list_remove_if(&lst, "OF", &ft_strcmp);

    tmp = lst;
    printf("Length: %d\n", ft_list_size(lst));
    while (tmp) {
        printf("%s\n", (int)(tmp->data));
        tmp = tmp->next;
    }

    ft_list_sort(&lst, &strSortAsc);

    tmp = lst;
    printf("Length: %d\n", ft_list_size(lst));
    while (tmp) {
        printf("%s\n", (int)(tmp->data));
        tmp = tmp->next;
    }

    return 0;
}