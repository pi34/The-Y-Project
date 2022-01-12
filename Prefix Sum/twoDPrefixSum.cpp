/*
The following implementation of the 2-D Prefic Sum Algorithm seeks to find the sum of an entire m * m 2-D matrix in time limit 
proportional to O(n), where n is the number of elements in the grid. This is followed by an application of prefix sum, used
to find the subsection of the matrix which contains the largest possible sum.

*/

// Define the prefix sum function which takes as input the Matrix (2-D Array), and the number of rows/columns m
int prefixSumTwoD (int A[], int m) {

    // Initialise a matrix with zeroes representing the sums till all the elements in the grid
    int dp[n][n];

    // We know that the max possible sum till the [0][0]th index is A[0][0] itself
    dp[0][0] = A[0][0]

    // We than perform 1-D Prefix Sum on the top row and the leftmost column of th grid using a simple loop
    for (int i = 0; i < m; ++i) {

        // We add the ith value of the fist row of the grid to the sum value till the i-1th index of the row
        dp[0][i] = dp[0][i-1] + A[0][i]

        // We add the ith value of the leftmost row of the grid to the sum value till the i-1th index of the column
        dp[i][0] = dp[i-1][0] + A[i][0]

    }

    // Now we run a nested loop over all other elements in the matrix and compute their prefix sums
    for (int i = 1; i < m; ++i) {

        // This is the loop running over the columns
        for (int j = 1; j < m; ++j) {

            // We know that the sum at any point would be as follows
            dp[i][j] = A[i][j] + dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1]

        }

    }

    // We return the last value of the new matrix, which will be the sum of the entire grid
    return dp[n-1][n-1]

}
