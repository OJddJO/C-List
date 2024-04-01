#ifndef __LIST_H__
#define __LIST_H__

typedef struct element {
    int value;
    struct element *prev;
    struct element *next;
} element;

typedef struct list {
    struct element *head;
    struct element *tail;
    int size;
    int middle;
} list;

void init_list(list *l);
void add_element(list *l, int value);
void set_element(struct list *l, int index, int value);
void remove_element(list *l, int value);
int get_element(list *l, int index);
int get_position(struct list *l, int value);
int list_size(struct list *l);
void delete_list(struct list *l);
void print_list(struct list *l);

#endif