/*
The following implementation of the Merge Sort Algorithm runs in time complexity O(n log n), and sorts an array in ascending order, based on the principle of 
merging to previously sorted arrays.

*/

#include <iostream>

using namespace std;

// Define the function which takes as input, the two array to be merged in place, the start and the ending index
void merge (int arr[], int n, int m) {

    // Find the mid index of the array segment
    int mid = (n+m) / 2;

    // Find the length of the left array
    int left = mid - n + 1;

    // Find the length of the right array
    int right = m - mid;

    // Initialise an empty left array
    int lArr[left];

    // Initialise an empty right array
    int rArr[right];

    // Loop over the left part of the array segment
    for (int i = 0; i < left; ++i) {

        // Add the element to the left array
        lArr[i] = arr[n+i];

    };


    // Loop over the right part of the array segment
    for (int i = 0; i < right; ++i) {

        // Add the element to the right array
        lArr[i] = arr[mid+i];

    };

    // Define a variable for the index of the left array
    int j = 0;

    // Define a variable for the index of the right array
    int k = 0;

    // Define a varaible for the index of the new merged array
    int c = 0;

    // Iterate as long as both the index values i and j are within the bounds of their respective arrays
    while ((j < left) && (k < right)) {

        // Check if the ith element of A1 is smaller than the jth element of A2
        if (lArr[j] <= rArr[k]) {

            // If so, add the ith element of A1 to the final merged array and increment the indexes
            arr[c++] = lArr[j++];

        } 
        
        // Otherwise check if the jth element of A2 is smaller
        else {

            // If so, add the jth element of A2 to the final merged array instead
            arr[c++] = rArr[k++];

        }

    }

    // Check if all elements of A1 have been covered, if not, that means all the remaining elements of A1 are greater than all elements in A2
    while (j < left) {

        // Thus, add all the remaining elements to the final array
        arr[c++] = lArr[j++];

    }

    // Check if all elements of A2 have been covered, if not, that means all the remaining elements of A2 are greater than all elements in A1
    while (k < right) {

        // Thus, add all the remaining elements to the final array
        arr[c++] = rArr[k++];

    }

}

// Define the recursive sort function with the array parameter
void sort (int arr[], int bot, int top) {
    
    // Check if the array contains more than one element (base case), since an array with one element is already sorted
    if (top-bot <= 1) {

        // If so, return the array as it is
        return;

    };

    // Otherwise, divide the array into two to perform recursion on each segment of the array, for that idenitfy the midpoint
    int avg = (top-bot)/2;

    // Recursively sort the left half of the array, from the starting index to the mid index
    sort(arr, bot, avg);

    // Recursively sort the right half of the array, from the mid index to the end index
    sort(arr, avg+1, top);

    // After receiving the sorted arrays, run the merge function on them
    merge(arr, bot, top);

}
 
