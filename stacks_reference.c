/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#define size 10


void push(int st[], int (*top), int ele) {
    if((*top) == size - 1) {
        printf("Stack overflow");
    } else {
        (*top)++;
        st[*top] = ele;
    }
}

int pop(int st[], int (*top)) {
    if((*top) == -1) {
        printf("Underflow");
    } else {
        int n  = st[*top];
        (*top)--;
        return n;
    }
}

void display(int st[], int (*top)) {
    if((*top) == -1) {
        printf("Empty stack");
    } else {
        for(int i = 0; i <= (*top); i++) {
            printf("%d\n", st[i]);
        }
    }
}

int main() {
    int st[100], top=-1, j=1, ch, n;

    while(j > 0) {
        printf("Enter a choice \n");
        printf("1, Push 2. Pop 3. Display 4. Exit \n");
        scanf("%d", &ch);
        switch(ch) {
            case 1: printf("Enter element \n");
                    scanf("%d", &n);
                    push(st, &top, n);
                    break;
                    
            case 2: n = pop(st, &top);
                    printf("Popped element = %d \n", n);
                    break;
            case 3: display(st, &top);
                    break;
            default: exit(0);
                    break;                    
        }
    }
    
    return 0;
}


