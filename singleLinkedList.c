#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;


node *create(int val) {
    node *n = malloc(sizeof(node));
    if (n == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    n->data = val;
    n->next = NULL;
    return n;
}

node *insert(node *head, int val) {
    node *newNode = malloc(sizeof(node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    newNode->data = val;
    newNode->next = head;
    return newNode;
}

void output(node *list) {
    static int count = 0;
    if (list != NULL) {
        printf("%d\n", list->data);
        count++;
        output(list->next);
    } else {
        printf("\nCount: %d\n", count);
    }
}

int searching(node *list, int target) {
    for (node *tmp = list; tmp != NULL; tmp = tmp->next) {
        if (tmp->data == target) {
            printf("Found %d\n", target);
            return 1;
        }
    }
    printf("Not found: %d\n", target);
    return 0;
}


void destroy(node *list) {
    node *tmp;
    while (list != NULL) {
        tmp = list->next;
        free(list);
        list = tmp;
    }
}

int main(void) {
    node *list = NULL;
    list = create(6);
    list = insert(list, 8);
    list = insert(list, 4);
    list = insert(list, 2);

    output(list);
    searching(list, 10);
    destroy(list);

    return 0;
}
