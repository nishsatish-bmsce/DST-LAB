#include <stdio.h>
#include <alloca.h>
#include <stdlib.h>

struct NODE {
    int value;
    struct NODE *next;
};

typedef struct NODE *node;

// Performing stack operatiions at the beginning of linked list so that we can print it normally later

node insert_beg(int item, node first) {
    node temp = (node)malloc(sizeof(struct NODE));
    
    if (temp == NULL) {
        printf("\nMemory not allocated");
        exit(0);
    }
    
    (temp->value) = item;
    (temp->next) = NULL;
    
    if (first == NULL) {
        return temp;
    } else {
        temp->next = first;
        first = temp;
        return first;
    }
}

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

void display(node first) {
    node temp;
    temp = first;
    if (temp == NULL) {
        printf("\nThe Linked list is empty!");
    } else {
        printf("The elements in the node are : ");
        while (temp != NULL) {
            printf("\n %d", (temp->value));
            temp = (temp->next);
        }
    }
}

int main() {
    int choice, item, x;
    node first = NULL;
    while (1) {
        printf("\n\n 1. Push 2. Pop 3. Display\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("\nEnter the element to be inserted : ");
            scanf("%d", &x);
            first = insert_beg(x, first);
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

