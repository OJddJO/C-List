#include <stdio.h>
#include "list.h"

int main() {
    struct list mylist;
    init_list(&mylist);
    add_element(&mylist, 5);
    add_element(&mylist, 10);
    add_element(&mylist, 15);
    print_list(&mylist);
    remove_element(&mylist, 1);
    print_list(&mylist);
    printf("The element at position 1 is %d\n", get_element(&mylist, 1));
    printf("The position of 5 is %d\n", get_position(&mylist, 5));
    printf("The size of the list is %d\n", list_size(&mylist));
    return 0;
}