#include<bits/stdc++.h>

using namespace std;

// Function to find the pivot position
int pivotal(int array[], int start, int end)
{
  int pivotalIndex = start; // Initializing the pivot index
  int rightIndex = start; // Initializing the right index

  // Loop to iterate over the array
  for(int i = start + 1; i <= end; i++)
  {
    // If the pivot element is greater or equal to the current element, increment the right index
    if(array[pivotalIndex] >= array[i])
    rightIndex++;
  }
  // Swap the pivot element with the element at the right index
  swap(array[pivotalIndex], array[rightIndex]);
  pivotalIndex = rightIndex; // Update the pivot index

  int i = start, j=  end;
  // Loop to rearrange the elements around the pivot
  while(i <= j)
  {
    // Increment i while the elements are smaller or equal to the pivot
    while(array[pivotalIndex] >= array[i])
    i++;
    // Decrement j while the elements are greater than the pivot
    while(array[pivotalIndex] < array[j])
    j--;
    // If i is less than j, swap the elements at i and j
    if(i < j)
    swap(array[i], array[j]);
  }
  // Return the pivot index
  return pivotalIndex;
}

// Function to perform the quicksort
void quicksort(int array[] , int start, int end)
{
  // If the start index is greater or equal to the end index, return
  if(start >= end)
  return;

  // Find the pivot position
  int pivotalpoint = pivotal(array, start, end);
  // Perform quicksort on the left part of the array
  quicksort(array, start, pivotalpoint-1);
  // Perform quicksort on the right part of the array
  quicksort(array, pivotalpoint + 1, end);
}

int main()
{
  // Initialize the array
  int array[] = {9, 3, 1, 6, 5, 4};
  // Perform quicksort on the array
  quicksort(array, 0, 5);
  int i = 0;
  // Loop to print the sorted array
  while( i <= 5)
  {
    cout << array[i];
    i++;
  }
}