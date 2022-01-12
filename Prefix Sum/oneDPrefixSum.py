"""
The following implementation of the 1-D Prefix Sum Algorithm seeks to find a sebsection of integers in an array (with both
negative and positive integers), whose sum is maximum. Note that this algorithm uses the concept of Dynamic Programming as well.
The time complexity of this algorithm is O(n).

"""

# Define the Prefix Sum function which takes as input the array of integers
def prefixSumOneD (A):

    # Initialise an empty array with len(A) zeroes to store the maximum sum possible in the array till the ith index
    dp = [0] * len(A)

    # We know that the max possible sum till the 0th index is A[0] itself
    dp[0] = A[0]

    # Now we can iterate over all other values, and check if adding it to the previous sum would lead to a larger total
    # Or if starting a new section with that element would to a larger total
    for i in range(1, len(A)):

        # Whichever value turns out to be greater will become the max possible sum till the current index
        dp[i] = max(A[i], A[i]+dp[i-1])

    # The max possible value till the last index of the array will be the max overall, and thus that value is returned
    return dp[-1]

 
