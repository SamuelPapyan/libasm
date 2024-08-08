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
    //  --- List of Numbers ---
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

    // --- List Of Strings ---
    t_list *lst = ft_list_create_elem("Hello");
    ft_list_push_front(&lst, "World");
    ft_list_push_front(&lst, "OF");
    ft_list_push_front(&lst, "HEROSHIP");
    ft_list_push_front(&lst, "42");
    t_list *tmp = lst;
    printf("Length: %d\n", ft_list_size(lst));
    while (tmp) {
        printf("%s\n", (tmp->data));
        tmp = tmp->next;
    }
    int number = ft_atoi_base("111111", "01");
    printf("111111 in Base-2 is: %d\n", number);

    ft_list_remove_if(&lst, "OF", &ft_strcmp);
    ft_list_remove_if(&lst, "OF", &ft_strcmp);

    tmp = lst;
    printf("Length: %d\n", ft_list_size(lst));
    while (tmp) {
        printf("%s\n", (tmp->data));
        tmp = tmp->next;
    }

    ft_list_sort(&lst, &strSortAsc);

    tmp = lst;
    printf("Length: %d\n", ft_list_size(lst));
    while (tmp) {
        printf("%s\n", (tmp->data));
        tmp = tmp->next;
    }

    return 0;
}