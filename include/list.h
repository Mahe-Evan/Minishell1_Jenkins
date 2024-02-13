/*
** EPITECH PROJECT, 2024
** fileslist
** File description:
** linked_list
*/

#pragma once

    #include <sys/stat.h>

typedef struct list_s {
    void *data;
    struct list_s *next;
    struct list_s *previous;
} list_t;

void list_add(list_t **list, void *data);
void list_display(list_t *list);
int list_size(list_t const *begin);
void list_reverse(list_t **begin);
void list_remove(list_t **begin,
    void const *data_ref, int (*cmp)());
int list_include(list_t const *begin,
    void const *data_ref, int (*cmp)());
list_t *list_get(list_t const *begin, int n);
list_t *list_find(list_t const *begin,
    void const *data_ref, int (*cmp)());
int list_apply(list_t *begin, int (*f)(void *));
int list_apply_on_matching(list_t *begin, int (*f)(void *),
    void const *data_ref, int (*cmp)());
void list_destroy(list_t *begin);
void list_move(list_t **src, list_t **dest,
    void *data_ref, int (*cmp)());
