#include<stdio.h>
#include<stdlib.h>

struct node {
  int value;
  struct node * next;
  struct node * prev;
};
typedef struct node * NODE;

NODE getnode() {
  NODE temp;
  temp = (NODE) malloc(sizeof(struct node));

  if (temp == NULL) {
    printf("Memory could not be allocated.");
  }

  return (temp);
}

NODE insert_left(NODE first, int pos, int item) {
  int count = 1;
  NODE New, curr;
  New = getnode();
  New->value = item;
  New->next = NULL;
  New->prev = NULL;

  if (first == NULL)
    return New;

  if (pos == 1) {
    New->next = first;
    first->prev = New;
    first = New;
    return first;
  }

  curr = first;
  while (count != pos && curr -> next != NULL) {
    curr = curr->next;
    count++;
  }

  if (count == pos) {
    New->next = curr;
    New->prev = curr->prev;
    (curr->prev)->next = New;
    curr->prev = New;
    printf("Item has been inserted");
    return first;
  }

  printf("pos not found");
  return first;
}

NODE del_specific(NODE first, int key) {
  NODE temp, curr;

  if (first == NULL) {
    printf("Nothing to delete :(");
    return NULL;
  }

  if (key == first->value) {
    first = first->next;
    return first;
  }

  curr = first;

  while (curr->next != NULL && curr->value != key) {
    curr = curr->next;
  }

  if (curr->next == NULL && curr-> value == key) {
    (curr->prev)->next = curr->next;
    printf("Deleted Value:%d", curr->value);
    free(curr);
    return first;
  }

  if (curr->value == key) {
    (curr->prev)->next = curr->next;
    (curr->next)->prev = curr->prev;

    printf("Deleted Value:%d", curr->value);
    free(curr);
    return first;
  }

  printf("Value not found: (");
  return first;

}

void display(NODE first) {
  NODE temp;
  temp = first;

  if (first == NULL) {
    printf("Whoops List is empty!");
  }

  while (temp != NULL) {
    printf(" %d", temp->value);
    temp = temp->next;
  }
}

int main() {
  int choice, item, x;
  NODE first = NULL;
  while (1) {
    printf("1) Insert at pos\n2) Del specific value\n3) Display\n4) Exit\nEnter your choice : ");
    scanf("%d", & choice);
    switch (choice) {
    case 1:
      printf("Enter the element to be inserted : ");
      scanf("%d", & item);
      printf("Enter the position to be inserted : ");
      scanf("%d", & x);
      first = insert_left(first, x, item);
      break;
    case 2:
      printf("Enter the element to be deleted : ");
      scanf("%d", & item);
      first = del_specific(first, item);
      break;
    case 3:
      display(first);
      break;
    case 4:
      printf("Exiting...");
      exit(0);
      break;
    default:
      printf("Please enter correct choice :(");
      break;
    }
  }
  return 0;
}
