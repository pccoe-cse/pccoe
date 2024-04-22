// Include necessary libraries
#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Define a structure to hold item details
struct items
{
  float profits;  // Profit of the item
  float weights;  // Weight of the item
  float p_b_w;    // Profit per unit weight of the item
};

// Function to compare two items based on their profit per unit weight
bool compareItems(items &a, items &b) {
  return a.p_b_w > b.p_b_w;
}

// Function to calculate the maximum profit for the given items and maximum weight
void checker(vector<items> &Item, int n, float max_weight)
{
  // Sort the items in decreasing order of profit per unit weight
  sort(Item.begin(), Item.end(), compareItems);
  
  float profit_final = 0.0;  // Initialize final profit
  
  // Iterate over the items
  for(int i = 0; i < n; i++)
  {
    // If the item can be fully included
    if(max_weight >= Item[i].weights)
    {
      profit_final += Item[i].profits;  // Add the item's profit to the final profit
      max_weight -= Item[i].weights;    // Subtract the item's weight from the maximum weight
    }
    else  // If the item can only be partially included
    {
      profit_final += (max_weight * Item[i].p_b_w);  // Add the profit for the part of the item that can be included
      break;  // No more items can be included, so break the loop
    }
  }
 
  // Print the final profit
  cout << profit_final << endl;
}

// Main function
int main()
{
  // Define the weights and profits of the items
  float weight[] = {28, 29, 32};
  float profit[] = {8 ,4, 3};
  
  // Create a vector of items
  vector<items> Item(3);
  
  // Initialize the items
  for(int i = 0; i < 3; i++)
  {
    Item[i].profits = profit[i];
    Item[i].weights = weight[i];
    Item[i].p_b_w = profit[i] / weight[i];
  }
  
  // Define the maximum weight
  float max_weight = 32;
  
  // Call the function to calculate the maximum profit
  checker(Item, 3, max_weight);
}