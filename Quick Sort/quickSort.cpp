/*
The following implementation of the quikSort algorithm sorts an array in an ascending order. Quicksort runs in O(n log n) time complexity, and is thus one of the
most efficient sorting algorithms

*/

#include <iostream>
#include <algorithm>

using namespace std;

// Define a function to run the sorting algorithm
void sort (int arr[], int bot, int top) {

    // Base case for recursion: perform the sort only if there is more than one element in the array segment
    if (bot < top) {

        // Otherwise, set the position for the lower bound
        int curr = bot - 1;

        // Determine the pivot element, based on which the array will be sorted
        int pivot = arr[top];

        // Iterate over all the values from the lwoer bound onward, where i will act as the upper bound
        for (int i = bot; i < top; ++i) {

            // Check if the upper bound element is smaller than the pivot element, and if they need to be swapped.
            if (arr[i] <= pivot) {

                // If true, increment the lower bound
                curr++;

                // Store the upper bound value temporarily, to perform the swap
                int temp = arr[i];

                // Set the upper bound position value as the larger value
                arr[i] = arr[curr];

                // Set the lower bound value as the smaller value
                arr[curr] = temp;

            };

        };

        // Swap the pivot with the last value of the lower bound, set the pivot value equal to the lower bound value
        arr[top] = arr[curr+1];

        // Set the lower bound value equal to the pivot value
        arr[curr+1] = pivot;

        // Perform in place recursion on two different parts of the array without actually dividing, 
        // First half would be from the starting index to the ith (lower bound) index
        sort(arr, bot, curr);

        // Second half of the array, from the ith index to the end of the array
        sort(arr, curr+2, top);

    }

}
