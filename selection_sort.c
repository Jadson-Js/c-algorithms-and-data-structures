#include <stdio.h>

#define MAX_LENGTH_ARRAY 90

int find_lowest_index(int *arr, int size);

int main(void)
{
  int arr[MAX_LENGTH_ARRAY] = {
      42, 7, 89, 13, 56, 91, 3, 77, 24, 68,
      15, 99, 1, 34, 60, 81, 9, 47, 72, 28,
      65, 18, 93, 5, 39, 84, 21, 70, 11, 58,
      96, 31, 2, 76, 49, 87, 14, 62, 26, 90,
      8, 54, 36, 95, 19, 66, 30, 73, 44, 10,
      83, 27, 51, 98, 6, 41, 69, 17, 92, 33,
      80, 12, 57, 25, 88, 4, 64, 20, 75, 45,
      97, 16, 59, 32, 85, 22, 71, 40, 94, 29,
      67, 48, 79, 35, 52, 23, 86, 55, 74, 50};

  int arr_size = sizeof(arr) / sizeof(arr[0]);

  int arr_ordened[MAX_LENGTH_ARRAY];

  for (int i = 0; i < arr_size; i++)
  {
    int lowest_index = find_lowest_index(arr, arr_size);
    arr_ordened[i] = arr[lowest_index];
    arr[lowest_index] = -1;
  }

  for (int i = 0; i < arr_size; i++)
  {
    printf("array[%i] = %i \n", i, arr_ordened[i]);
  }
}

int find_lowest_index(int *arr, int size)
{
  int value = 0;
  int index = 0;

  for (int i = 0; i < size; i++)
  {
    if (arr[i] > value)
    {

      value = arr[i];
      index = i;
    }
  }

  return index;
}