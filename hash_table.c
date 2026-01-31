#include <stdio.h>
#include <string.h>
#define TABLE_SIZE 3
#define INPUT_SIZE 4

typedef char *string;
typedef struct node
{
  string value;
  struct node *next;
} node;

int hash(string input);
void push(string value, node *head);
int main(void)
{
  node table[TABLE_SIZE] = {};
  string input[INPUT_SIZE] = {"A", "B", "C", "D"};

  for (int i = 0; i < INPUT_SIZE; i++)
  {
    int index = hash(input[i]);

    if (table[index].value == NULL)
    {
      table[index].value = input[i];
    }
    else
    {
      push(input[i], &table[index]);
    }
  }

  for (int i = 0; i < TABLE_SIZE; i++)
  {
    printf("%i* ITEM DO HASH \n", i);

    node current;
    for (node current = table[i]; current.next != NULL; current = *current.next)
    {
      printf("%s \n", current.value);
    }
    printf("%s \n\n", current.value);
  }
}

int hash(string input)
{
  int size = strlen(input);
  int first = input[0];
  int second = input[1];
  int result = (size * first) + second;
  return result % TABLE_SIZE;
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