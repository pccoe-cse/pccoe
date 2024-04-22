#include <iostream>
#include <vector>
using namespace std;

// Function to heapify the tree
void heapify(vector<int>& arr, int n, int i) {
      int parent = (i - 1) / 2; // Find parent
      if (parent >= 0) {
            // If child is greater, swap it with parent
            if (arr[i] > arr[parent]) {
                  swap(arr[i], arr[parent]);
                  // Heapify the parent.
                  heapify(arr, n, parent);
            }
      }
}

// Function to insert a node into the heap
void insertNode(vector<int>& arr, int key) {
      arr.push_back(key); // Insert the new node at the end
      int n = arr.size();
      // Heapify the tree from the last node
      heapify(arr, n, n - 1);
}

// Function to heapify the tree after deletion
void heapifydel(vector <int>& arr , int i)
{
      int parent = i;
      int l = 2*i +1; // left child
      int r = 2*i +2; // right child
      
      // If left child is larger than root
      if(arr[l] > arr[parent])
      {
            parent = l;
      }
      
      // If right child is larger than largest so far
      if(arr[r] > arr[parent])
      {
            parent = r;
      }
      
      // If largest is not root
      if(parent != i)
      {
            swap(arr[i] , arr[parent]); // Swap
            heapifydel(arr,parent); // Heapify the affected sub-tree
      }
}

// Function to delete a node from the heap
void deletenode(vector <int>&arr)
{
      int n = arr.size();
      int m = arr[n-1] ;
      arr[0] = m; // Replace root with last node
      arr.pop_back(); // Remove last node
   
      heapifydel(arr,0); // Heapify the root node
}

// Function to print the array
void printArray(const vector<int>& arr) {
      for (int i = 0; i < arr.size(); i++) {
                  cout << arr[i] <<" ";
      }
      cout << endl;
}

int main() {
      int key;
      vector<int> arr;
      int ans = 0;
      int ch;

      do {
            cout << "Enter choice:" << endl;
            cout << "1. Insert" << endl;
            cout << "2. Delete" << endl;
            cout << "3. Display" << endl;
            cin >> ch;

            switch (ch) {
                  case 1: {
                        cout << "Enter key: ";
                        cin >> key;
                        insertNode(arr, key); // Insert key into heap
                        break;
                  }
                  case 2: {
                        deletenode(arr); // Delete root node
                        printArray(arr); // Print array
                        break;
                  }
                  case 3: {
                        printArray(arr); // Print array
                        break;
                  }
                  default:
                        cout << "Invalid choice!" << endl;
            }
            cout << "Do you want to continue? 1-yes 0-no: ";
            cin >> ans;
      } while (ans == 1);

      return 0;
}