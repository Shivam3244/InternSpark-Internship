# Task 2 - Algorithms & Problem Solving

## Implemented Algorithms

1. Quick Sort
2. Binary Search
3. 0/1 Knapsack using Dynamic Programming

## Compile

```bash
gcc quicksort.c -o quicksort
gcc binary_search.c -o binary_search
gcc knapsack.c -o knapsack
```

## Run

```bash
./quicksort
./binary_search
./knapsack
```

## Complexity

| Algorithm | Time Complexity | Space |
|---|---|---|
| Quick Sort | Average O(n log n), Worst O(n^2) | O(log n) average |
| Binary Search | O(log n) | O(1) |
| 0/1 Knapsack | O(nW) | O(nW) |

Quick Sort also measures execution time using the C clock API.
