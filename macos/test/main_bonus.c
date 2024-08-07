#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include "libasm_bonus.h"

int compare(void *a, void *b) {
    return !((int)a == (int)b);
}

int sortDesc(void *a, void *b) {
    return !((int)a > (int)b);
}

int sortAsc(void *a, void *b) {
    return !((int)a < (int)b);
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

    ft_list_sort(&lst, &sortAsc);

    tmp = lst;
    printf("Length: %d\n", ft_list_size(lst));
    while (tmp) {
        printf("%d\n", (int)(tmp->data));
        tmp = tmp->next;
    }

    return 0;
}