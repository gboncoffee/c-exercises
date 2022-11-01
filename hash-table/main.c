#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#define HASH_SIZE 100
#define MAGIC_HASH 1634 

/*
 * Hash table exercise from https://youtu.be/YyWMN_0g3BQ (Fábio Akita)
 */

typedef struct Node {
    char *key;
    char *value;
    struct Node *next;
} Node;

typedef struct Hash {
    Node *list[HASH_SIZE];
} Hash;

unsigned short hash_code(char *key) {
    unsigned long hash = MAGIC_HASH;
    unsigned long c;
    while ((c = *key++)) {
        hash = ((hash << 5) + hash) + c;
    }

    return (hash % HASH_SIZE);
}

Node *create_node(char *key, char *value) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->key = key;
    node->value = value;
    return(node);
}

int insert_node(Hash *hash, char *key, char *value) {
    unsigned short index = hash_code(key);
    Node *node = hash->list[index];
    if (node == NULL) {
        hash->list[index] = create_node(key, value);

    } else {

        while (node) {
            if (node->next == NULL) {
                node->next = create_node(key, value);
                break;
            }

            node = node->next;
        }
    }

    return (0);
}

char *search(Hash *hash, char *key) {
    unsigned short index = hash_code(key);
    Node *node = hash->list[index];
    while (node) {
        if (!strcmp(node->key, key)) {
            return (node->value);
        }

        node = node->next;
    }

    return "";
}

int main() {

    Hash *hash = (Hash *) malloc(sizeof(Hash));
    insert_node(hash, "hello", "world");
    insert_node(hash, "Gabriel", "gboncoffee");

    printf("%s\n", search(hash, "hello"));
    printf("%s\n", search(hash, "Gabriel"));

    return(errno);
}
