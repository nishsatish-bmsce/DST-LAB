#include <stdio.h>
#include <stdlib.h>
#define size 10

void insert_rear(int q[], int (*r), int item, int (*count)) {
    if ((*r) == size-1) {
        printf("Queue overflow");
    } else {
        (*r) = ((*r) + 1)%size;
        q[*r] = item;
        (*count)++;
        printf("\n Inserted %d", item);
    }
}

int delete_front(int q[], int (*r), int (*f), int (*count)) {
    int deletedItem;
    if ((*count) == 0) {
        printf("\n Empty queue");
        exit(0);
    } else {
        deletedItem = q[(*f)];
        (*f) = ((*f) + 1)%size;
        count--;
        return deletedItem;
    }
}

void display(int q[], int (*f), int (*count)) {
    if((*count) ==0) {
        printf("Underflow");
    }
    int temp, i;
    temp  =(*f);
    for (int i = 0; i < (*count); i++) {
        printf("%d \n", q[temp]);
        temp = (temp + 1)%size;
    }
}

void main() {
    int ch;
    int ele;
    int f=0, r = -1, q[size];
    int a = 1;
    int count = 0;
    while(a > 0) {
        printf("\n \n 1. Insert 2. Delete 3. Display 4. Exit \n Enter choice");
        scanf("%d", &ch);
        
        switch(ch) {
            case 1: printf("\n Enter element to insert");
                    int item;
                    scanf("%d", &item);
                    insert_rear(q, &r, item, &count);
                    break;
            case 2: 
                    ele = delete_front(q, &r, &f, &count);
                    printf("\n %d was the element removed", ele);
                    break;
            case 3: display(q, &f, &count);
                    break;
            default: exit(0); 
                    break;
        }
    }
}
