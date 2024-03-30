#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/*Initializes list structure l*/
void init_list (struct list *l) {
    l->head = NULL;
    l->tail = NULL;
}

/*Adds element x to the list l*/
void add_element(struct list *l, int value) {
    struct element *e = (struct element *)malloc(sizeof(struct element));
    e->value = value;
    e->prev = l->tail;
    e->next = NULL;
    if (l->head == NULL) {
        l->head = e;
    } else {
        l->tail->next = e;
    }
    l->tail = e;
}

/*Removes element x from the list l*/
void remove_element(struct list *l, int index) {
    struct element *e = l->head;
    for (int i = 0; i < index; i++) {
        e = e->next;
    }
    if (e->prev != NULL) {
        e->prev->next = e->next;
    } else {
        l->head = e->next;
    }
    if (e->next != NULL) {
        e->next->prev = e->prev;
    } else {
        l->tail = e->prev;
    }
    free(e);
}

/*Returns the element at position i in the list l*/
int get_element(struct list *l, int index) {
    struct element *e = l->head;
    for (int i = 0; i < index; i++) {
        e = e->next;
    }
    return e->value;
}

/*Returns the position of the first occuration of element x in the list l*/
int get_position(struct list *l, int value) {
    struct element *e = l->head;
    int position = 0;
    while (e != NULL) {
        if (e->value == value) {
            return position;
        }
        e = e->next;
        position++;
    }
    return -1;
}

/*Returns the number of elements in the list l*/
int list_size(struct list *l) {
    struct element *e = l->head;
    int size = 0;
    while (e != NULL) {
        size++;
        e = e->next;
    }
    return size;
}

/*Deletes the list l*/
void delete_list(struct list *l) {
    struct element *e = l->head;
    while (e != NULL) {
        struct element *next = e->next;
        free(e);
        e = next;
    }
    l->head = NULL;
    l->tail = NULL;
}

/*Prints the list l*/
void print_list(struct list *l) {
    struct element *e = l->head;
    printf("list{");
    while (e != NULL) {
        printf("%d", e->value);
        if (e->next != NULL) {
            printf("; ");
        }
        e = e->next;
    }
    printf("}\n");
}
