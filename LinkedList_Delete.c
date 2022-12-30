#include <stdio.h>
#include <alloca.h>
#include <stdlib.h>

struct NODE {
    int value;
    struct NODE *next;
};

typedef struct NODE *node;

node delete_beg(node first) {
    if (first == NULL) {
        printf("\nUnderflow");
        exit(0);
    } else {
        node temp;
        temp = first;
        temp = (first->next);
        return temp;
    }
}

void delete_end(node first) {
    if (first == NULL) {
        printf("\n Underflow");
    } else {
        node prev, curr;
        prev = NULL;
        curr = first;
        
        while ((curr->next) != NULL) {
            prev = curr;
            curr = (curr->next);
        }
        printf("The deleted value is %d", (curr->value));
        (prev->next) = NULL;
        free(curr);
    }
}