#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

/*
 * Linked-list exercise from https://youtu.be/YyWMN_0g3BQ (Fábio Akita)
 */

typedef struct Node {
    int value;
    struct Node *previous;
} Node;

Node *create_node(int value, Node *previous) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->value = value;
    if (previous) {
        node->previous = previous;
    }

    return(node);
}

int main() {

    Node *first = create_node(2020, NULL);
    Node *second = create_node(2021, first);
    Node *third = create_node(2022, second);

    Node *iterator = third;
    while (iterator) {
        printf("On %p: %d\n", iterator, iterator->value);
        iterator = iterator->previous;
    }

    return(errno);
}
