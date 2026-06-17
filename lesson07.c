#include <stdio.h>
#include <stdlib.h>

typedef int data_t;
typedef struct node node_t;
struct node {
    data_t data;
    node_t *next;
};
typedef struct {
    node_t *head;
    node_t *foot;
} list_t;

// build an empty list
list_t *make_empty_list(void) {
    list_t *list = (list_t *)malloc(sizeof(list_t));
    if (list == NULL) {
        return NULL;
    }
    list->head = NULL;
    list->foot = NULL;
    return list;
}

// insert a node at the head (LIFO -> stack push)
list_t *insert_at_head(list_t *list, data_t value) {
    node_t *new = (node_t *)malloc(sizeof(node_t));
    if (new == NULL) {
        return list;            // malloc failed: leave the list unchanged
    }
    new->data = value;
    new->next = list->head;     // step A: wire new in first
    list->head = new;           // step B: then move head

    if (list->foot == NULL) {   // list was empty -> new is also the foot
        list->foot = new;
    }
    return list;
}

// traverse and print: read-only, no backup needed
void print_list(list_t *list) {
    node_t *curr = list->head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

// free every node, then the handle: back up next before freeing
void free_list(list_t *list) {
    node_t *curr = list->head;
    while (curr != NULL) {
        node_t *t = curr->next;   // back up first
        free(curr);               // then destroy
        curr = t;                 // advance using the backup
    }
    free(list);                   // finally free the list_t handle
}

int main(void) {
    list_t *list = make_empty_list();
    if (list == NULL) {
        return 1;
    }

    list = insert_at_head(list, 30);
    list = insert_at_head(list, 20);
    list = insert_at_head(list, 10);

    print_list(list);   // expected: 10 20 30
    free_list(list);
    return 0;
}
