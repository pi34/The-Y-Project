"""
The following implementation of the Merge Sort Algorithm runs in time complexity O(n log n), and sorts an array in ascending order, based on the principle of 
merging to previously sorted arrays.

"""

# Define the function which takes as input, the two sorted arrays to be merged
def mergeSort (A1, A2):
  
    # Define an empty array, which will contained the merged result
    finArr = []
  
    # Define the index for the first array, to be iterated over with the loop
    i = 0
  
    # Define the index for the second array, to be iterated over with the loop
    j = 0
  
    # Iterate as long as both the index values i and j are within the bounds of their respective arrays
    while i < len(A1) && j < len(A2):
    
        #  Check if the ith element of A1 is smaller than the jth element of A2
        if A1[i] < A2[j]:
      
            # If so, add the ith element of A1 to the final merged array
            finArr.append(A1[i])

            # Increment i to move on to the next element of A1, while keeping j constant
            i += 1
      
        # Otherwise check if the jth element of A2 is smaller
        else:
            
            # If so, add the jth element of A2 to the final merged array instead
            finArr.append(A2[j])
            
            #Increment j to move on to the next element of A2
            
    # Check if all elements of A1 have been covered, if not, that means all the remaining elements of A1 are greater than all elements in A2
    while i < len(A1):
      
        # Thus, add all the remaining elements to the final array
        finArr.append(A1[i])

        # Increment i
        i += 1
      
    # Check if all elements of A2 have been covered, if not, that means all the remaining elements of A2 are greater than all elements in A1
    while j < len(A2):
      
        # Thus, add all the remaining elements to the final array
        finArr.append(A2[j])
        
        # Increment j
        j += 1
        
        
     # Return the sorted array
    return finArr
  

# Define the recursive sort function with the array parameter
def sort (A):
  
    # Check if the array contains more than one element (base case), since an array with one element is already sorted
    if len(A) == 1:
      
        # If so, return the array as it is
        return A
      
    # Otherwise, divide the array into two to perform recursion on each segment of the array, for that idenitfy the midpoint
    mid = len(A) // 2
    
    # Recursively sort the left half of the array, from the starting index to the mid index
    left = sort (A[:mid])
    
    # Recursively sort the right half of the array, from the mid index to the end index
    right = sort (A[mid:])
    
    # After receiving the sorted arrays, run the merge function on them and return the final array
    return merge (left, right)
  
   
    
