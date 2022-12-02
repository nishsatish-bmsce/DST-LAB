#include <stdio.h>
#include <stdlib.h>
#define size 10

void insert_rear(int q[], int (*r), int item) {
    if ((*r) == size-1) {
        printf("Queue overflow");
    } else {
        (*r)++;
        q[*r] = item;
        printf("\n Inserted %d", item);
    }
}

int delete_front(int q[], int (*r), int (*f)) {
    int deletedItem;
    if ((*f) > (*r)) {
        printf("\n Empty queue");
    } else {
        deletedItem = q[(*f)];
        (*f)++;
        return deletedItem;
    }
}

void display(int q[], int (*f), int (*r)) {
    if ((*f) > (*r)) {
        printf("\n Empty queue");
    } else {
        for(int i = (*f); i <= (*r); i++) {
            printf("\n %d", q[i]);
        }
    }
}

void main() {
    int ch;
    int ele;
    int f=0, r = -1, q[size];
    int a = 1;
    while(a > 0) {
        printf("\n \n 1. Insert 2. Delete 3. Display 4. Exit \n Enter choice");
        scanf("%d", &ch);
        
        switch(ch) {
            case 1: printf("\n Enter element to insert");
                    int item;
                    scanf("%d", &item);
                    insert_rear(q, &r, item);
                    break;
            case 2: 
                    ele = delete_front(q, &r, &f);
                    printf("\n %d was the element removed", ele);
                    break;
            case 3: display(q, &f, &r);
                    break;
            default: exit(0); 
                    break;
        }
    }
}