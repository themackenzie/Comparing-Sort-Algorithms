# Comparing-Sort-Algorithms

This repository is focused on using a simple code in **C++**, implementing seven different sort algorithms to order an array.

## 🚀 Rapid Use
Using an online compiler or any other type (recommended **C++11**), copy and paste the main code inside the main file of the compiler.

### Input Format
The code takes 3 entries, all being numbers:
`(Number of values) (Min Value) (Max Value)`

The code will automatically:
1. Create an array with the number of values given.
2. Fill the array with random numbers between the Min and Max values.
3. Show the entire base array.
4. Execute every sorting algorithm.
5. Provide a summary including **number of steps** (swaps between values) and **execution time** (in milliseconds).

> [!IMPORTANT]
> Every algorithm takes a different amount of steps and time because their best and worst cases are defined mathematically.

---

## 📊 EXAMPLE 01
**Input:** `20 1 30`

*   **Numbers:** 20
*   **Range:** 1 - 30

### Base Array Reference
`27 17 7 6 20 28 5 21 20 1 25 29 26 8 11 11 26 8 17 26`

### Number of Steps (swaps) per Algorithm
| Algorithm | Steps |
| :--- | :--- |
| Selection Sort | 53 |
| Bubble Sort | 86 |
| Insertion Sort | 105 |
| Merge Sort | 176 |
| Quick Sort | 51 |
| Heap Sort | 73 |
| Cycle Sort | 19 |

**Best Algorithm in steps:** Quick Sort with **51**

> [!CAUTION]
> Cycle Algorithm almost always is the less on steps, for that, it won't be counted.

### Time (ms) per Algorithm
*   **Selection Sort:** 0.0000000000
*   **Bubble Sort:** 0.0000000000
*   **Insertion Sort:** 0.0000000000
*   **Merge Sort:** 0.0000000000
*   **Quick Sort:** 0.0000000000
*   **Heap Sort:** 0.0000000000
*   **Cycle Sort:** 0.0000000000

**Best Algorithm in times (ms):** Selection Sort with **0.0000000000**

---

## 📈 STRESS TEST (3000 cases)
The number of cases are lower, that's why the time of execution are almost in zero. To see better every algorithm, we will use 3000 cases.

**Input:** `3000 3 7864`

### Number of Steps (swaps) per Algorithm
| Algorithm | Steps |
| :--- | :--- |
| **Selection Sort** | **22630** |
| Bubble Sort | 2268798 |
| Insertion Sort | 2271797 |
| Merge Sort | 69808 |
| Quick Sort | 26717 |
| Heap Sort | 32055 |
| Cycle Sort | 3000 |

**Best Algorithm in steps:** Selection Sort with **22630**

> [!NOTE]
> Cycle Algorithm almost always is the less on steps, for that, it won't be counted.

### Time (ms) per Algorithm
| Algorithm | Time (ms) |
| :--- | :--- |
| Selection Sort | 12.0000000000 |
| Bubble Sort | 19.0000000000 |
| Insertion Sort | 7.0000000000 |
| Merge Sort | 1.0000000000 |
| **Quick Sort** | **0.0000000000** |
| Heap Sort | 1.0000000000 |
| Cycle Sort | 45.0000000000 |

**Best Algorithm in times (ms):** Quick Sort with **0.0000000000**

> [!WARNING]
> Because it is using `ctime` library, the time will be minimum. Recommended use more numbers. If you want to see time of execution on Quick Sort, it is recommended to use above 8000 cases forward. :)

---

## 🧠 Algorithm Definitions & Complexity

### 1. Selection Sort
It divides the input list into two parts: a sorted sublist and an unsorted sublist. It repeatedly finds the minimum element from the unsorted part and moves it to the end of the sorted part.
*   **Time Complexity:** $O(n^2)$

### 2. Bubble Sort
A simple algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. This process repeats until the list is sorted.
*   **Time Complexity:** $O(n^2)$

### 3. Insertion Sort
It builds the final sorted array one item at a time. It takes one element from the unsorted part and finds the correct position to "insert" it into the already sorted part.
*   **Time Complexity:** $O(n^2)$

### 4. Merge Sort
A "Divide and Conquer" algorithm. It recursively divides the array into halves until each sub-array has one element, then merges those sub-arrays in a way that results in a new sorted array.
*   **Time Complexity:** $O(n \log n)$

### 5. Quick Sort
Another "Divide and Conquer" approach. It picks an element as a "pivot" and partitions the array around it, so that elements smaller than the pivot stay on the left and larger ones on the right.
*   **Time Complexity:** $O(n \log n)$ (Average case) / $O(n^2)$ (Worst case)

### 6. Heap Sort
This algorithm uses a Binary Heap data structure. It first builds a "Max-Heap" from the data, then repeatedly removes the largest element from the heap and places it at the end of the array.
*   **Time Complexity:** $O(n \log n)$

### 7. Cycle Sort
An in-place, unstable sorting algorithm that is theoretically optimal in terms of the total number of writes to the original array. It is based on the idea that the permutation to be sorted can be decomposed into cycles.
*   **Time Complexity:** $O(n^2)$

> [!NOTE]
> Because Cycle Sort is almost always the best in sorting terms, it won't be counted at the final of every round.
