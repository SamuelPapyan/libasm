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

int compare(void *a, void *b) {
    return !((int)a == (int)b);
}

int freeFunction(void *a) {
    printf("FREE!: %d is removed\n", (int)a);
}

int main() {
    t_list *lst = ft_list_create_elem(42);
    ft_list_push_front(&lst, (void *)45);
    ft_list_push_front(&lst, (void *)47);
    ft_list_push_front(&lst, (void *)48);
    ft_list_push_front(&lst, (void *)41);
    t_list *tmp = lst;
    printf("Length: %d\n", ft_list_size(lst));
    while (tmp) {
        printf("%d\n", (int)(tmp->data));
        tmp = tmp->next;
    }
    int number = ft_atoi_base("111111", "01");
    printf("111111 in Base-2 is: %d\n", number);
    ft_list_remove_if(&lst, (void *)47, &compare);
    ft_list_remove_if(&lst, (void *)47, &compare);
    tmp = lst;
    printf("Length: %d\n", ft_list_size(lst));
    while (tmp) {
        printf("%d\n", (int)(tmp->data));
        tmp = tmp->next;
    }
    return 0;
}