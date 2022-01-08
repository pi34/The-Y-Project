
# Define a function run the sorting algorithm
def quicksort(arr):

    # Count the number of elements in the array
    elements = len(arr)
    
    # Base case for recursion: If there's only one element, then the array is already sorted
    if elements < 2:
      
        # Return the array as it is
        return arr
    
    # Otherwise, set the position for the lower bound
    current_position = 0 

    # Iterate over all the values from the lwoer bound onward, where i will act as the upper bound
    for i in range(1, elements):
      
          # Check if the upper bound element is smaller than the pivot element (the first element), and if they need to be swapped.
         if arr[i] <= arr[0]:
            
              # If true, increment the lower bound
              current_position += 1
              
              # Store the upper bound value temporarily, to perform the swap
              temp = arr[i]
              
              # Set the upper bound position value as the larger value
              arr[i] = arr[current_position]
              
              # Set the lower bound value as the smaller value
              arr[current_position] = temp

    # Swap the pivot with the last value of the lower bound, so temporarily store the pivot value in a variable.
    temp = arr[0]
    
    # Set the pivot value equal to the lower bound value
    arr[0] = arr[current_position] 
    
    # Set the lower bound value equal to the pivot value
    arr[current_position] = temp 
    
    # Perform recursion, by dividing this array in two halves, first half would be from the starting index to the ith (lower bound) index
    left = quicksort(arr[0:current_position]) 
    
    # Second half of the array, from the ith index to the end of the array
    right = quicksort(arr[current_position+1:elements]) 

    # Join the sorted arrays once more, to procure the final array
    arr = left + [arr[current_position]] + right 
    
    # Return the sorted array
    return arr
    
