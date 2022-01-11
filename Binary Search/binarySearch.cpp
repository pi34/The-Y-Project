"""
The following implementation of the Binary Search Algorithm runs in O(log n) time complexity, and searches a specific element in a sorted array.
"""

#include <iostream>

using namespace std;

// Define a function which takes as input the starting index of the particular iteration, the ending index, the array, and the desired value
int binarySearch (int start, int end, int[] A, int value) {

    // Check if the end index is greater than the start index to validate the iteration (base case for recursion)
    if (end >= start) {

        // Find the value of the particular segment of the array by taking an average
        mid = (end+start) / 2;

        // Check if the mid value is what we are looking for 
        if (A[mid] == value) {

            // If so, return the index where the value was found
            return mid;

        }

        // Check if the mid value is greater than what we are looking for
        else if (A[mid] > value) {

            // If so, our value must be between the starting index and the mid index, so perform another round of binary search on that segment
            return binarySearch (start, mid - 1, A, value);

        

        // Check if the mid value is lesser than what we are looking for
        else {

            // If so, our value must be between the mid index and the end index, so perform binary search on that segment
            return binarySearch(mid + 1, end, A, value);

        };

    }

    // If the base case fails, that means that we have searched through the entire array and the element was not found
    else {

        // Return an invalid index
        return -1;

    };

};
