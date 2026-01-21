#include <stdio.h>

void quicksort(int *array, int array_size, int start, int end);
void swap(int *a, int *b);

int main(void)
{
  int array[5] = {4, 2, 1, 3, 5};
  int array_size = sizeof(array) / sizeof(array[0]);

  quicksort(array, array_size, 0, array_size - 1);

  for (int i = 0; i < array_size; i++)
  {
    printf("%i \n", array[i]);
  }

  return 0;
}

void quicksort(int *array, int array_size, int start, int end)
{
  /*
  array = [4, 2, 1, 3, 5]
  array_size = 5
  start = 0
  end = 4

  if array_size <= 2
    break

  pivo = array[start]
    (4)

  swap array[start] com array[end]
    ([5, 2, 1, 3, 4])

  int j = start
    (0)

  for (int i = start; i < end; i++)
    if (array[i] < pivo)
      swap array[i] com array[j]
      j++

  j++
  swap array[j] com array[end]
  */

  if (array_size <= 2)
    return;

  int pivo = array[start];

  swap(&array[start], &array[end]);

  int j = start;

  for (int i = start; i < end; i++)
  {
    if (array[i] < pivo)
    {
      swap(&array[i], &array[j]);
      j++;
    }
  }
  swap(&array[j], &array[end]);

  quicksort(array, end - start, start, j - 1);
  quicksort(array, end - start, j + 1, end);
}

void swap(int *a, int *b)
{
  int tmp = *a;

  *a = *b;
  *b = tmp;
};