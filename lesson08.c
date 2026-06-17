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

// insert a node at the foot (FIFO -> queue enqueue); needs foot for O(1)
list_t *insert_at_foot(list_t *list, data_t value) {
    node_t *new = (node_t *)malloc(sizeof(node_t));
    if (new == NULL) {
        return list;            // malloc failed: leave the list unchanged
    }
    new->data = value;
    new->next = NULL;           // the new node is the new tail

    if (list->foot == NULL) {   // empty list: new is both head and foot
        list->head = new;
        list->foot = new;
        return list;            // case handled -> leave (no cross-contamination)
    }

    list->foot->next = new;     // wire old tail onto the new node
    list->foot = new;           // then move foot (order matters: else self-loop)
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

    // head insertion (stack push): last in ends up first -> reversed
    list = insert_at_head(list, 30);
    list = insert_at_head(list, 20);
    list = insert_at_head(list, 10);
    printf("head insert (30,20,10): ");
    print_list(list);   // expected: 10 20 30
    free_list(list);

    // foot insertion (queue enqueue): keeps insertion order
    list_t *q = make_empty_list();
    if (q == NULL) {
        return 1;
    }
    q = insert_at_foot(q, 10);
    q = insert_at_foot(q, 20);
    q = insert_at_foot(q, 30);
    printf("foot insert (10,20,30): ");
    print_list(q);      // expected: 10 20 30
    free_list(q);

    return 0;
}
