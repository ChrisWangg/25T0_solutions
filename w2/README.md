# README

## Overview

This repository contains solutions and test files for **COMP2521 25T0 Week 02 Tutorial Questions**. The tutorial focuses on topics in **Analysis of Algorithms, ADTs, and Binary Search Trees**. Below is a summary of where to find the corresponding code files and instructions on how to compile and run them.

---

## Questions and Corresponding Files

1. **Analysis of Algorithms: Palindrome**
   - **`palindrome.c`**  
     - Implements a **C program** that checks if a string is a palindrome.  
     - Usage: `./palindrome <string>`  
       - e.g. `./palindrome racecar` prints `yes`, `./palindrome reviewer` prints `no`.
   - Demonstrates:
     - String processing
     - O(n) time complexity analysis

2. **Analysis of Algorithms: Two-Sum**
   - **`twoSum.c`**  
     - Contains a brute force function (`hasTwoSum`) that checks if an integer array has two elements that sum to a given target.  
     - Also includes a **test suite** (similar to the queue tests) using ANSI color codes.
     - Test suite can be run with `./twoSum` after building with `make`

3. **ADTs: Set ADT and Set Problems**
   - **`Set.c`, `Set.h`**  
     - A Set ADT interface and implementation.
   - **`setProblems.c`**  
     - Demonstrates functions:
       - `numOddOccurrences(int arr[], int size)`  
       - `numSingleOccurrences(int arr[], int size)`  
     - Uses the Set ADT to solve these problems.
     - Also, is a test suite, and can be run with `./setProblems`, after building with `make`.

4. **ADTs: Queue using Two Stacks**
   - **`Queue.c`, `Queue.h`**  
     - Implementation of a queue using two stacks.
   - **`Stack.c`, `Stack.h`**  
     - Stack ADT used by the queue.
   - **`testQueue.c`**  
     - Test file for the queue implementation (enqueue/dequeue tests).
     - Run with `./testQueue`, after building with `make`.

5. **Binary Search Trees**
   - **`bst.c`, `bst.h`**  
     - Contains stubs or implementations for:  
       - `bstCountOdds(struct node *t)`  
       - `bstCountInternal(struct node *t)`  
       - `bstNodeLevel(struct node *t, int key)`  
       - `bstCountGreater(struct node *t, int val)`
   - **`testBst.c`**  
     - Test file with multiple tests (similar style with ANSI color codes) for the BST functions.
     - Run with `./testBst`, after building with `make`.

---

## How to Build

A **Makefile** is provided to simplify compilation. Typically, you can build all executables by running:

```bash
make
```
---

## Testing
To test a specific suite run `make` to build, and then run that test, for e.g. `./testName`, instructions given above to test each individual question with my provided tests.

### Testing all at once
You can run `./testAll`, which will `make` and test, `twoSum`, `setProblems`, `testQueue`, `testBst`, all at once.
