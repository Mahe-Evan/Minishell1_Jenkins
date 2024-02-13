/*
** EPITECH PROJECT, 2024
** fileslist
** File description:
** linked_list
*/

#ifndef LINKED_LIST_H_
    #define LINKED_LIST_H_

    #include <sys/stat.h>

typedef struct linked_list_s {
    void *data;
    struct linked_list_t *next;
    struct linked_list_t *previous;
} linked_list_t;

int my_apply_on_matching_nodes(linked_list_t *begin, int (*f)(void *),
    void const *data_ref, int (*cmp)());
int my_apply_on_nodes(linked_list_t *begin, int (*f)(void *));
linked_list_t *my_find_node(linked_list_t const *begin,
    void const *data_ref, int (*cmp)());
int my_list_size(linked_list_t const *begin);
linked_list_t *my_params_to_list(int ac, char *const *av);
void my_put_in_list(linked_list_t **list, char *data);
void my_rev_list(linked_list_t **begin);
void my_show_list(linked_list_t *list);

#endif /* LINKED_LIST_H_ */
