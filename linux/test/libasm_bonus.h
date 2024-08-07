# ifndef LIBASM_BONUS_H
#  define LIBASM_BONUS_H

typedef struct s_list
{
    void            *data;
    struct s_list   *next;
}                   t_list;

size_t  ft_read(int fd, const void *buf, size_t nbyte);
char    *ft_strcpy(char *dest, const char *src);
char    *ft_strdup(const char *s1);
size_t  ft_strlen(char *s);
size_t  ft_write(int fd, const void *buf, size_t count);
int     ft_strcmp(const char *s1, const char *s2);

int		ft_atoi_base(char *str, char *base);
t_list	*ft_list_create_elem(void *data);
void    ft_list_push_front(t_list **begin_list, void *data);
void    ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());
int     ft_list_size(t_list *begin_list);
void    ft_list_sort(t_list **begin_list, int (*cmp)());

# endif