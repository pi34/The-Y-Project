/*
The following implementation of the Sliding Window Algorithm has a time complexity proportional to O(n). The goal here is to 
find a continuous segment of integers in an array of minimum length with sum exactly K, and return the length.

*/

// Define the function which takes as input the Array and the value K
int slidingWindow (int[] A, int K) {

    // Define a variable that will store the current total sum of the integers
    int sumTot = 0

    // Define a variable which keeps track of the starting position of our sliding window
    int start = 0

    // Define a variable which keeps track of the ending position of our sliding window
    int end = 0

    // Define a variable which will store the shortest possible length with sum K, which will initially be as large as possible
    int leng = sizeof(A) + 1

    // We want to loop over the array as long as the sliding window does not exceed the bounds of the array
    while ((start < sizeof(A) && (end < sizeof(A)))) {

        // If the current sum is less than the desired value, then we expand our window from the right
        if (sumTot < K) {

            // Upon the expansion, we add the new rightmost element to our sum
            sumTot = sumTot + A[end]

            // We then increment the end index of our window, to initiate the expansion
            end++

        }

        // Otherwise if the current sum is more than K, then we contract our window from the left
        else if (sumTot > K) {

            // Upon contraction we subtract the leftmost element from the sum
            sumTot = sumTot - A[start]

            // We then increment the start index to initiate the contraction
            start++

        }

        // If the current sum is equal to K, then we have found a possible length of integers summing up to K
        else if (sumTot == K) {

            // In that case we compare this new length to the existing minimum length, and we save whichever one is smaller
            leng = min(leng, end-start)

            // We then increment our start index to contract the window from the left
            start++

        }

    }

    // We then return the minimum length identified
    return leng

}
