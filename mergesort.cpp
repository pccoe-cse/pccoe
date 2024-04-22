#include<bits/stdc++.h>

using namespace std;

// Function to merge two subarrays
void merge(int arr[], int start, int end)
{
    // Temporary array to hold the merged result
    int brr[end+1];
    // Copying the elements from the original array to the temporary array
    for(int i = 0; i <= end; i++)
    {
        brr[i] = arr[i];
    }

    // Finding the middle index
    int mid = (start+end) / 2;

    // Initial index of first subarray
    int i = start;
    // Initial index of second subarray
    int j = mid + 1;
    // Initial index of merged subarray
    int k = start;

    // Merge the temp arrays back into arr[start..end]
    while( i <= mid && j <= end)
    {
        // If element of first subarray is smaller, add it to the merged array
        if(brr[i] < brr[j])
        {
            arr[k] = brr[i];
            i++;
            k++;
        }
        // If element of second subarray is smaller, add it to the merged array
        else
        {
            arr[k] = brr[j];
            j++;
            k++;
        }
    }

    // Copy the remaining elements of the first subarray, if there are any
    while(i <= mid)
    {
        arr[k] = brr[i];
        k++;
        i++;
    }

    // Copy the remaining elements of the second subarray, if there are any
    while(j <= end)
    {
        arr[k] = brr[j];
        j++;
        k++;
    }
}

// Function to implement merge sort
void mergesort(int arr[], int start , int end)
{
    // Base case: If there is only one element, return
    if(start == end)
    return;

    // Find the middle point to divide the array into two halves
    int mid = (start + end) / 2;
    // Call mergesort for first half
    mergesort(arr, start , mid);
    // Call mergesort for second half
    mergesort(arr, mid + 1, end);
    // Merge the two halves sorted
    merge(arr, start, end);
}

// Driver code
int main()
{
    // Array to be sorted
    int arr[] = {9, 1, 8, 2, 7, 3, 6, 4, 5};
    // Call merge sort
    mergesort(arr, 0, 8);
    // Print the sorted array
    for(int i = 0; i < 9; i++)
    {
        cout << arr[i] << endl;
    }
}