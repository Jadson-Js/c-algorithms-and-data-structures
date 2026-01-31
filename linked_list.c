/*
  node = {value: string, next: *node}

  node list[4] = [{value: a, next: 1}, {value: b, next: 2}, {value: c, next: null} ];
*/

#include <stdio.h>

typedef char *string;

typedef struct node
{
  string value;
  struct node *next;

} node;

void push(string value, node *head);

int main()
{
  node item1, item2, item3;
  item1.value = "A";
  item1.next = &item2;
  item2.value = "B";
  item2.next = &item3;
  item3.value = "C";
  item3.next = NULL;

  push("D", &item1);

  node current;
  for (node current = item1; current.next != NULL; current = *current.next)
  {
    printf("%s \n", current.value);
  }
  printf("%s \n", current.value);
}

void push(string value, node *head)
{
  node *current = head;
  node new;
  new.value = value;
  new.next = NULL;

  while (current->next != NULL)
  {
    current = current->next;
  }

  current->next = &new;
}