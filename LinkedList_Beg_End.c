
#include <stdio.h>
#include <alloca.h>
#include <stdlib.h>

struct NODE {
    int value;
    struct NODE *next;
};

typedef struct NODE *node;

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

void insert_any(int item, int position, node first) {
    node temp, newnode;
    newnode = malloc(sizeof(struct NODE));
    int i = 1;
    temp = first;
    (newnode->value) = item;
    (newnode->next) = NULL;
    while (i < (position - 1)) {
        temp = temp->next;
        i++;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

int main() {
    int choice, item, x;
    node first = NULL;
    while (1) {
        printf("\n\n 1. Insert beginning 2. Insert end 3. Display 4. Delete beginning 5. Delete ending \n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("\nEnter the element to be inserted : ");
            scanf("%d", &x);
            first = insert_beg(x, first);
            break;
        case 2:
            printf("\nEnter the element to be inserted : ");
            scanf("%d", &x);
            first = insert_end(x, first);
            break;
        case 3:
            display(first);
            break;
        case 4:
            delete_beg(first);
            break;
        case 5:
            delete_end(first);
            break;
            
        case 6:
            printf("Enter the position to be inserted : ");
            scanf("%d", &pos);
            printf("Enter the element to be inserted : ");
            scanf("%d", &x);
            insert_at_any_position(x, pos, first);
            break;

        default:
            exit(0);
            break;
        }
    }
    return 0;
}

