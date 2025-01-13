# README

## Overview

This repository contains solutions and test files for **COMP2521 25T0 Week 02 Tutorial Questions**. The tutorial focuses on topics in **Analysis of Algorithms, ADTs, and Binary Search Trees**. Below is a summary of the corresponding code files and instructions on how to compile and run them.

---

## Questions and Corresponding Files

### 1. **Analysis of Algorithms: Palindrome**
   - **`palindrome.c`**  
     - Implements a **C program** that checks if a string is a palindrome.  
     - **Usage:**  
       ```bash
       ./palindrome <string>
       ```  
       - **Examples:**  
         - `./palindrome racecar` prints `\033[32myes\033[0m`  
         - `./palindrome reviewer` prints `\033[31mno\033[0m`  
     - **Key Concepts:**  
       - String processing  
       - O(n) time complexity analysis  

---

### 2. **Analysis of Algorithms: Two-Sum**
   - **`twoSum.c`**  
     - Contains a brute force function (`hasTwoSum`) that checks if an integer array has two elements that sum to a given target.  
     - Includes a **test suite** (using ANSI color codes).  
     - **Run the test suite:**  
       ```bash
       ./twoSum
       ```  
       *(Build using `make` first)*  
       - Pass: `\033[32mPASS\033[0m`  
       - Fail: `\033[31mFAIL\033[0m`  

---

### 3. **ADTs: Set ADT and Set Problems**
   - **Files:**
     - `Set.c`, `Set.h`  
       - Set ADT interface and implementation.  
     - `setProblems.c`  
       - Functions:  
         - `numOddOccurrences(int arr[], int size)`  
         - `numSingleOccurrences(int arr[], int size)`  
       - Solves these problems using the Set ADT.  
       - Includes a **test suite**.
   - **Run the test suite:**  
     ```bash
     ./setProblems
     ```  
     *(Build using `make` first)*  

---

### 4. **ADTs: Queue using Two Stacks**
   - **Files:**
     - `Queue.c`, `Queue.h`  
       - Queue implementation using two stacks.  
     - `Stack.c`, `Stack.h`  
       - Stack ADT used by the queue.  
     - `testQueue.c`  
       - Test file for the queue implementation (enqueue/dequeue tests).  
   - **Run the test suite:**  
     ```bash
     ./testQueue
     ```  
     *(Build using `make` first)*  
     - Enqueue test result: `\033[32mPASS\033[0m` or `\033[31mFAIL\033[0m`  
     - Dequeue test result: `\033[32mPASS\033[0m` or `\033[31mFAIL\033[0m`  

---

### 5. **Binary Search Trees (BST)**
   - **Files:**
     - `bst.c`, `bst.h`  
       - Functions:  
         - `bstCountOdds(struct node *t)`  
         - `bstCountInternal(struct node *t)`  
         - `bstNodeLevel(struct node *t, int key)`  
         - `bstCountGreater(struct node *t, int val)`  
     - `testBst.c`  
       - Test file with multiple tests (uses ANSI color codes) for the BST functions.  
   - **Run the test suite:**  
     ```bash
     ./testBst
     ```  
     *(Build using `make` first)*  
     - Test result: `\033[32mPASS\033[0m` or `\033[31mFAIL\033[0m`  

---

## How to Build

A **Makefile** is provided to simplify the compilation process. To build all executables, run:

```bash
make
```

## Testing
To test a specific suite run `make` to build, and then run that test, for e.g. `./testName`, instructions given above to test each individual question with my provided tests.

### Testing all at once
You can run `./testAll`, which will `make` and test, `twoSum`, `setProblems`, `testQueue`, `testBst`, all at once.
