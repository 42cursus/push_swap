The push_swap problem from 42 Network is a coding challenge that involves sorting a stack of integers using a limited set of operations,
aiming to use the fewest operations possible.
A powerful approach to solve this problem is using the three-way, three-pivot quicksort algorithm. \
Here’s a step-by-step explanation of how this algorithm is implemented to solve the push_swap problem:

### Overview
 - Initialization 
 - Choosing Pivots
 - Partitioning
 - Recursive Sorting
 - Combining Results

### Step-by-Step Explanation
#### Step 1: Initialization
1. Stacks Setup: You start with two stacks, a and b. \
   Initially, stack a contains all the unsorted integers, and stack b is empty.

2. Operation Set: The allowed operations are:

   - sa: swap the first two elements of stack a
   - sb: swap the first two elements of stack b
   - ss: sa and sb simultaneously
   - pa: push the top element from stack b to stack a
   - pb: push the top element from stack a to stack b
   - ra: rotate stack a upwards (first element becomes the last)
   - rb: rotate stack b upwards (first element becomes the last)
   - rr: ra and rb simultaneously
   - rra: rotate stack a downwards (last element becomes the first)
   - rrb: rotate stack b downwards (last element becomes the first)
   - rrr: rra and rrb simultaneously

#### Step 2: Choosing Pivots
1. Finding Pivots: \
   For three-way partitioning, you need to choose three pivot values.
   - pivot1: value at one-third position in the sorted array
   - pivot2: value at two-thirds position in the sorted array
   - pivot3: median value in the sorted array

2. Dividing the Array: These pivots divide the array into four parts:

   - Elements less than pivot1
   - Elements between pivot1 and pivot2
   - Elements between pivot2 and pivot3
   - Elements greater than pivot3

#### Step 3: Partitioning
1. Initial Partitioning: Use the pivots to partition the elements in stack a into four parts. During partitioning:

   - Elements less than pivot1 are pushed to stack b.
   - Elements between pivot1 and pivot2 are rotated to the bottom of stack a.
   - Elements between pivot2 and pivot3 remain in their place.
   - Elements greater than pivot3 are pushed to stack b.

2. Operations:

    - Use pb to move elements to stack b.
    - Use ra and rra to rotate stack a.
#### Step 4: Recursive Sorting
1. Sort the Subarrays:

    - Recursively apply the same partitioning process to the subarrays created by the pivots.
2. Handle Each Subarray:
    - Sort elements in stack b (those less than pivot1 and greater than pivot3) using similar partitioning and recursive sorting.
#### Step 5: Combining Results
1. Merging Sorted Sections:
    - After sorting the elements recursively, merge them back together.
    - Use pa to move elements from stack b to stack a.
2. Final Adjustments:
   - Ensure that all elements are sorted and in the correct order in stack a.

#### Notes
 - Efficiency: This approach is efficient because it reduces the problem size with each recursive call.
 - Edge Cases: Handle edge cases where the stack has very few elements differently to avoid unnecessary operations.
 - Optimization: Further optimize by balancing the number of operations and minimizing the depth of recursion.
 