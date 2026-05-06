# Comparing-Sort-Algorithms
The respository is focused on use a simple code in C++, using seven different sort algorithms for order an array.

<<Rapid use>>
Using an online compiler or any other type (recommended C++11), copy and paste the main code inside the main file of the compiler.

The script takes 3 entries, being numbers each one:
(Number of values) (Min Value) (Max Value)

The code automatically will create an array with the number of values give it, then, this array will filled by numbers between Min and Max Values.

First, the code will show the entire array
Second, every sorting algorithm will work
Third, at the end, a small pieces of information will give, the number of steps(swaps between values) and the time by each algorithm (in milliseconds).

Every algorithm takes a different amount of steps and time, because their best and worst cases are defined mathematically.


1. Selection Sort
It divides the input list into two parts: a sorted sublist and an unsorted sublist. It repeatedly finds the minimum element from the unsorted part and moves it to the end of the sorted part.
*Time Complexity: $O(n^2)$

2. Bubble Sort
A simple algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. This process repeats until the list is sorted.
*Time Complexity: $O(n^2)$

3. Insertion Sort
It builds the final sorted array one item at a time. It takes one element from the unsorted part and finds the correct position to "insert" it into the already sorted part.
*Time Complexity: $O(n^2)$

4. Merge Sort
A "Divide and Conquer" algorithm. It recursively divides the array into halves until each sub-array has one element, then merges those sub-arrays in a way that results in a new sorted array.
*Time Complexity: $O(n \log n)$

5. Quick Sort
Another "Divide and Conquer" approach. It picks an element as a "pivot" and partitions the array around it, so that elements smaller than the pivot stay on the left and larger ones on the right.
*Time Complexity: $O(n \log n)$ (Average case) / $O(n^2)$ (Worst case)

6. Heap Sort
This algorithm uses a Binary Heap data structure. It first builds a "Max-Heap" from the data, then repeatedly removes the largest element from the heap and places it at the end of the array.
*Time Complexity: $O(n \log n)$

7. Cycle Sort
An in-place, unstable sorting algorithm that is theoretically optimal in terms of the total number of writes to the original array. It is based on the idea that the permutation to be sorted can be decomposed into cycles.
*Time Complexity: $O(n^2)$

NOTE: Because Cycle Sort is almost always the best in sorting therms, it wont be count at the final of every round.
