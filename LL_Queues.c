#include <stdio.h>
#include <alloca.h>
#include <stdlib.h>

struct NODE {
    int value;
    struct NODE *next;
};


node insert_end(int item, node first) {
    node temp = (node)malloc(sizeof(struct NODE));
    
    if (temp == NULL) {
        printf("\nMemory not allocated");
    }
    
    (temp->value) = item;
    (temp->next) = NULL;
    
    if ((first->next) == NULL) {
        (first->next) = temp;
        return first;
    } else {
        node last = first;
        
        while ((last->next) != NULL) {
            last = (last->next);
        }
        
        (last->next) = temp;
        return first;
    }
}

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

int main() {
    int choice, item, x;
    node first = NULL;
    while (1) {
        printf("\n\n 1. Enqueue 2. Dequeue 3. Display\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("\nEnter the element to be inserted : ");
            scanf("%d", &x);
            first = insert_end(x, first);
            break;
        case 2:
            delete_beg(first);
            break;       
        case 3:
            display(first);
            break;

        default:
            exit(0);
            break;
        }
    }
    return 0;
}

