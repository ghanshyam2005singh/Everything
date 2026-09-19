# Complete DSA Learning Roadmap — Topics, Algorithms, Methods & Practice Questions

Ghanshyam, let's make this your **master DSA checklist**: a structured list of the important data structures, algorithms, problem-solving patterns, and LeetCode questions you can use to learn them.

The goal isn't just to memorize solutions. For every topic, aim to learn:

1. **What it is** and when to use it.
2. **How the logic works**, including why it works.
3. **How to implement it** in C++.
4. **Time and space complexity**.
5. **Which problems test that technique**, starting with easier ones and progressing to harder ones.

I'll use **LeetCode problem numbers** wherever possible. A problem can teach multiple techniques, so you'll sometimes see the same number under more than one topic. I've also tried to avoid treating problems you've already worked on as new practice; some familiar ones are included as revision checkpoints.

**How to use the checklist**

* ☐ = learn or practise
* ★ = particularly useful pattern to understand well
* **Revision** = a problem you've already encountered that can help you test whether you still remember the technique

This is a broad roadmap, not a requirement to finish every problem before moving forward. Learn the concept, solve a few representative questions, then revisit it later.

---


# 0. Foundations — Learn These First

Before advanced DSA, make sure you can comfortably write and understand these in C++.

| Topic                   | What to learn                                                                                         |
| ----------------------- | ----------------------------------------------------------------------------------------------------- |
| Complexity analysis     | Big-O time, auxiliary space, best/average/worst case                                                  |
| C++ STL                 | `vector`, `string`, `pair`, `stack`, `queue`, `deque`, `set`, `map`, `unordered_set`, `unordered_map` |
| Sorting and searching   | `sort()`, `lower_bound()`, `upper_bound()`, `binary_search()`                                         |
| Functions               | Parameters, references, return values, helper functions                                               |
| Recursion               | Base case, recursive call, call stack                                                                 |
| References and pointers | `&`, `*`, `nullptr`, pointer traversal                                                                |
| Custom sorting          | Comparators and sorting pairs/objects                                                                 |
| Integer safety          | `int`, `long long`, overflow, safe arithmetic                                                         |

### Complexity patterns to recognize

* One pass through an array → often **O(n)**.
* Two nested loops over the same input → often **O(n²)**.
* Repeatedly halving a search range → **O(log n)**.
* Sorting → usually **O(n log n)**.
* A hash table operation → average **O(1)**, though worst-case behavior can differ.
* Recursion → account for both the work per call and the number of calls.
* Extra array/vector proportional to input size → **O(n) auxiliary space**.

---

# 1. Sorting Algorithms

Learn how sorting works internally, even though in most interview solutions you can use `sort()`.

## Algorithms to learn

| Algorithm      | Key idea                                                |            Typical time |
| -------------- | ------------------------------------------------------- | ----------------------: |
| Bubble Sort    | Swap adjacent elements that are out of order            |                   O(n²) |
| Selection Sort | Repeatedly select the smallest remaining element        |                   O(n²) |
| Insertion Sort | Insert each element into the already-sorted prefix      |        O(n²), best O(n) |
| Merge Sort     | Divide, sort both halves, merge                         |              O(n log n) |
| Quick Sort     | Partition around a pivot, then recursively sort         |      Average O(n log n) |
| Heap Sort      | Build a heap and repeatedly extract the maximum/minimum |              O(n log n) |
| Counting Sort  | Count occurrences when the value range is limited       |                O(n + k) |
| Radix Sort     | Sort by digit/place value                               |  Depends on digit count |
| Bucket Sort    | Distribute values into buckets, then sort buckets       | Depends on distribution |

genui{"learning_viz":{"type_id":"BUBBLE_SORT","initial_values":{"initialOrder":"mixed"}}}

genui{"learning_viz":{"type_id":"INSERTION_SORT"}}

## Sorting questions

| Question            | LeetCode |
| ------------------- | -------: |
| Sort an Array       |      912 |
| Sort Colors ★       |       75 |
| Merge Sorted Array  |       88 |
| Largest Number      |      179 |
| Sort List           |      148 |
| Relative Sort Array |     1122 |
| Maximum Gap         |      164 |
| Pancake Sorting     |      969 |
| Wiggle Sort II      |      324 |
| Meeting Rooms       |      252 |
| Meeting Rooms II    |      253 |

**Learn to recognize:** when sorting simplifies a problem, how to sort by a custom key, and when sorting destroys useful original ordering.

---

# 2. Arrays

Arrays are one of the most important DSA topics. Learn the patterns separately; many interview problems are combinations of them.

## 2.1 Basic traversal and in-place operations

Learn:

* Forward and reverse traversal
* Updating elements in place
* Maintaining minimum, maximum, sum, and count
* Swapping elements
* Using read/write pointers
* Handling empty arrays and boundary indices

| Question                            |           LeetCode |
| ----------------------------------- | -----------------: |
| Move Zeroes                         |                283 |
| Remove Element                      |                 27 |
| Remove Duplicates from Sorted Array |                 26 |
| Plus One                            |                 66 |
| Find Pivot Index                    |                724 |
| Best Time to Buy and Sell Stock     | 121 — **Revision** |
| Rotate Array                        | 189 — **Revision** |

## 2.2 Prefix sums and suffix sums ★

Learn:

* Prefix sum arrays
* Suffix sum arrays
* Range-sum queries
* Prefix and suffix products
* Difference arrays for range updates

| Question                     |           LeetCode |
| ---------------------------- | -----------------: |
| Running Sum of 1d Array      |               1480 |
| Find the Highest Altitude    |               1732 |
| Product of Array Except Self | 238 — **Revision** |
| Range Sum Query – Immutable  |                303 |
| Subarray Sum Equals K        | 560 — **Revision** |
| Contiguous Array             |                525 |
| Subarray Sums Divisible by K |                974 |
| Corporate Flight Bookings    |               1109 |
| Car Pooling                  |               1094 |

## 2.3 Kadane's algorithm and maximum subarray

Learn:

* Maximum subarray sum
* Tracking the best answer ending at the current index
* Maximum and minimum subarray products
* Circular maximum subarray

| Question                             | LeetCode |
| ------------------------------------ | -------: |
| Maximum Subarray                     |       53 |
| Maximum Sum Circular Subarray        |      918 |
| Maximum Product Subarray             |      152 |
| Maximum Absolute Sum of Any Subarray |     1749 |
| K-Concatenation Maximum Sum          |     1191 |

## 2.4 Two-dimensional arrays and matrices

Learn:

* Row-wise and column-wise traversal
* Matrix transpose
* In-place matrix transformations
* Spiral traversal
* Searching sorted matrices
* Marking rows and columns

| Question                                  | LeetCode |
| ----------------------------------------- | -------: |
| Transpose Matrix                          |      867 |
| Reshape the Matrix                        |      566 |
| Spiral Matrix                             |       54 |
| Spiral Matrix II                          |       59 |
| Set Matrix Zeroes                         |       73 |
| Rotate Image                              |       48 |
| Search a 2D Matrix                        |       74 |
| Search a 2D Matrix II                     |      240 |
| Game of Life                              |      289 |
| Count Negative Numbers in a Sorted Matrix |     1351 |

## 2.5 Cyclic sort and index placement

Learn:

* Placing values at their corresponding indices
* Finding missing numbers
* Finding duplicates under constrained value ranges
* In-place marking

| Question                                 |          LeetCode |
| ---------------------------------------- | ----------------: |
| Find All Numbers Disappeared in an Array |               448 |
| Find All Duplicates in an Array          |               442 |
| Set Mismatch                             |               645 |
| First Missing Positive                   | 41 — **Revision** |

## 2.6 Array mathematics and greedy observations

| Question                                         |            LeetCode |
| ------------------------------------------------ | ------------------: |
| Majority Element                                 |  169 — **Revision** |
| Majority Element II                              |                 229 |
| Missing Number                                   |  268 — **Revision** |
| Single Number                                    |  136 — **Revision** |
| Maximum Product of Three Numbers                 |  628 — **Revision** |
| Maximum Product of Two Elements in an Array      | 1464 — **Revision** |
| Boats to Save People                             |  881 — **Revision** |
| Removing Minimum and Maximum From Array          | 2091 — **Revision** |
| Find the Duplicate Number                        |                 287 |
| Maximum Length of Subarray With Positive Product |                1567 |

---

# 3. Strings

## 3.1 String fundamentals

Learn:

* Character traversal
* ASCII and character arithmetic
* Case conversion
* Alphanumeric checks
* Building strings
* Comparing strings
* Frequency arrays for lowercase letters or digits

| Question                           |           LeetCode |
| ---------------------------------- | -----------------: |
| Valid Palindrome                   | 125 — **Revision** |
| Reverse String                     |                344 |
| Reverse Vowels of a String         |                345 |
| First Unique Character in a String |                387 |
| Valid Anagram                      |                242 |
| Ransom Note                        |                383 |
| Find the Difference                |                389 |
| Isomorphic Strings                 |                205 |
| Word Pattern                       |                290 |
| Longest Common Prefix              |                 14 |

## 3.2 Palindromes

Learn:

* Two-pointer palindrome checking
* Expanding around a center
* Odd- and even-length centers
* Palindromic substrings versus subsequences

| Question                      | LeetCode |
| ----------------------------- | -------: |
| Valid Palindrome II           |      680 |
| Longest Palindromic Substring |        5 |
| Palindromic Substrings        |      647 |
| Longest Palindrome            |      409 |
| Shortest Palindrome           |      214 |
| Palindrome Partitioning       |      131 |

## 3.3 String matching algorithms

Learn:

* Naive pattern matching
* Knuth–Morris–Pratt (KMP)
* Prefix-function / LPS array
* Z-algorithm
* Rabin–Karp and rolling hash

| Question                                           | LeetCode |
| -------------------------------------------------- | -------: |
| Find the Index of the First Occurrence in a String |       28 |
| Repeated Substring Pattern                         |      459 |
| Shortest Palindrome                                |      214 |
| Implement strStr()                                 |       28 |

## 3.4 String construction and parsing

Learn:

* Parsing numbers and operators
* Tokenization
* Stack-based evaluation
* Building strings efficiently
* Run-length encoding
* Converting between numbers and strings

| Question                 | LeetCode |
| ------------------------ | -------: |
| String to Integer (atoi) |        8 |
| Add Strings              |      415 |
| Multiply Strings         |       43 |
| String Compression       |      443 |
| Decode String            |      394 |
| Basic Calculator II      |      227 |
| Integer to Roman         |       12 |
| Roman to Integer         |       13 |
| Zigzag Conversion        |        6 |

---

# 4. Two Pointers and Sliding Window ★

These are high-value patterns. Practise identifying when a window can expand or shrink and when sorted order enables two-pointer movement.

## 4.1 Two pointers

Learn:

* Opposite-direction pointers
* Same-direction read/write pointers
* Two pointers on sorted arrays
* Pair and triplet searching
* Fast and slow pointers

| Question                            |           LeetCode |
| ----------------------------------- | -----------------: |
| Two Sum II – Input Array Is Sorted  |                167 |
| 3Sum                                |                 15 |
| 3Sum Closest                        |                 16 |
| 4Sum                                |  18 — **Revision** |
| Container With Most Water           |                 11 |
| Trapping Rain Water                 |  42 — **Revision** |
| Boats to Save People                | 881 — **Revision** |
| Squares of a Sorted Array           |                977 |
| Remove Duplicates from Sorted Array |                 26 |

## 4.2 Fixed-size sliding window

Learn:

* Add the incoming element
* Remove the outgoing element
* Maintain a sum, count, or frequency table

| Question                                               |           LeetCode |
| ------------------------------------------------------ | -----------------: |
| Maximum Average Subarray I                             |                643 |
| Permutation in String                                  | 567 — **Revision** |
| Find All Anagrams in a String                          |                438 |
| Number of Sub-arrays of Size K and Average ≥ Threshold |               1343 |

## 4.3 Variable-size sliding window

Learn:

* Expand the right pointer
* Shrink the left pointer while a condition is violated
* Maintain counts or frequencies
* Understand when negative values make ordinary sum-based shrinking invalid

| Question                                             |            LeetCode |
| ---------------------------------------------------- | ------------------: |
| Longest Substring Without Repeating Characters       |    3 — **Revision** |
| Minimum Size Subarray Sum                            |                 209 |
| Longest Repeating Character Replacement              |  424 — **Revision** |
| Max Consecutive Ones III                             |                1004 |
| Fruit Into Baskets                                   |                 904 |
| Minimum Window Substring                             |                  76 |
| Longest Substring With At Most K Distinct Characters |                 340 |
| Maximum Length Substring With Two Occurrences        | 3090 — **Revision** |
| Minimum Operations to Reduce X to Zero               |                1658 |
| Subarrays with K Different Integers                  |                 992 |

## 4.4 Monotonic deque

Learn:

* Maintain candidates in increasing or decreasing order
* Remove elements that can no longer become the answer
* Use indices to track window boundaries

| Question                              | LeetCode |
| ------------------------------------- | -------: |
| Sliding Window Maximum                |      239 |
| Shortest Subarray with Sum at Least K |      862 |
| Jump Game VI                          |     1696 |

---

# 5. Hashing

## Techniques to learn

* `unordered_set` for membership and duplicate detection
* `unordered_map` for frequencies and key-value relationships
* Counting arrays for small fixed domains
* Grouping items by a derived key
* Prefix sum + hash map
* Hashing pairs or custom objects
* Ordered versus unordered maps and sets

| Question                     |           LeetCode |
| ---------------------------- | -----------------: |
| Contains Duplicate           | 217 — **Revision** |
| Two Sum                      |                  1 |
| Valid Anagram                |                242 |
| Group Anagrams               |                 49 |
| Top K Frequent Elements      |                347 |
| Longest Consecutive Sequence |                128 |
| Intersection of Two Arrays   |                349 |
| Isomorphic Strings           |                205 |
| Subarray Sum Equals K        | 560 — **Revision** |
| Contiguous Array             |                525 |
| 4Sum II                      |                454 |
| Design HashMap               |                706 |
| Design HashSet               |                705 |
| Insert Delete GetRandom O(1) |                380 |

---


# 6. Binary Search

## Techniques to learn

* Ordinary binary search
* Lower bound and upper bound
* First/last occurrence
* Search in a rotated sorted array
* Binary search on the answer
* Finding a peak
* Binary search on a monotonic predicate
* Searching in 2D matrices

| Question                                                | LeetCode |
| ------------------------------------------------------- | -------: |
| Binary Search                                           |      704 |
| Search Insert Position                                  |       35 |
| First Bad Version                                       |      278 |
| Find First and Last Position of Element in Sorted Array |       34 |
| Search in Rotated Sorted Array                          |       33 |
| Search in Rotated Sorted Array II                       |       81 |
| Find Minimum in Rotated Sorted Array                    |      153 |
| Find Peak Element                                       |      162 |
| Find Peak Element II                                    |     1901 |
| Search a 2D Matrix                                      |       74 |
| Search a 2D Matrix II                                   |      240 |
| Sqrt(x)                                                 |       69 |
| Find K Closest Elements                                 |      658 |
| Koko Eating Bananas                                     |      875 |
| Capacity To Ship Packages Within D Days                 |     1011 |
| Split Array Largest Sum                                 |      410 |
| Median of Two Sorted Arrays                             |        4 |
| Find in Mountain Array                                  |     1095 |

**Important:** For binary search on the answer, practise identifying a condition that changes monotonically from false to true, or true to false.

---

# 7. Linked Lists

## Techniques to learn

* Traversing and modifying nodes
* Dummy/sentinel nodes
* Reversing a linked list
* Fast and slow pointers
* Finding the middle node
* Detecting cycles
* Merging sorted lists
* Splitting and reconnecting lists
* Reversing nodes in groups
* Copying a list with random pointers

| Question                           |           LeetCode |
| ---------------------------------- | -----------------: |
| Reverse Linked List                |                206 |
| Merge Two Sorted Lists             |                 21 |
| Linked List Cycle                  |                141 |
| Linked List Cycle II               |                142 |
| Middle of the Linked List          |                876 |
| Remove Nth Node From End of List   |                 19 |
| Remove Duplicates from Sorted List |  83 — **Revision** |
| Palindrome Linked List             |                234 |
| Intersection of Two Linked Lists   |                160 |
| Add Two Numbers                    |                  2 |
| Reorder List                       | 143 — **Revision** |
| Odd Even Linked List               |                328 |
| Rotate List                        |                 61 |
| Sort List                          |                148 |
| Copy List with Random Pointer      |                138 |
| Reverse Linked List II             |                 92 |
| Swap Nodes in Pairs                |                 24 |
| Reverse Nodes in k-Group           |                 25 |
| Merge k Sorted Lists               |                 23 |
| LRU Cache                          |                146 |

---

# 8. Stacks, Queues and Monotonic Structures

## 8.1 Stack

Learn:

* LIFO behavior
* Expression evaluation
* Matching brackets
* Undoing/reversing operations
* Maintaining a stack of indices
* Monotonic increasing and decreasing stacks

| Question                                 |           LeetCode |
| ---------------------------------------- | -----------------: |
| Valid Parentheses                        |                 20 |
| Min Stack                                | 155 — **Revision** |
| Evaluate Reverse Polish Notation         | 150 — **Revision** |
| Baseball Game                            | 682 — **Revision** |
| Daily Temperatures                       | 739 — **Revision** |
| Next Greater Element I                   |                496 |
| Next Greater Element II                  |                503 |
| Online Stock Span                        | 901 — **Revision** |
| Asteroid Collision                       | 735 — **Revision** |
| Remove All Adjacent Duplicates in String |               1047 |
| Decode String                            |                394 |
| Largest Rectangle in Histogram           |                 84 |
| Maximal Rectangle                        |                 85 |
| Sum of Subarray Minimums                 |                907 |
| Basic Calculator                         |                224 |

## 8.2 Queue and deque

Learn:

* FIFO behavior
* Queue simulation
* Deque operations at both ends
* BFS
* Monotonic deque

| Question                        | LeetCode |
| ------------------------------- | -------: |
| Implement Queue using Stacks    |      232 |
| Implement Stack using Queues    |      225 |
| Design Circular Queue           |      622 |
| Design Circular Deque           |      641 |
| Number of Recent Calls          |      933 |
| Dota2 Senate                    |      649 |
| Moving Average from Data Stream |      346 |
| Sliding Window Maximum          |      239 |

## 8.3 Monotonic stack patterns

Learn:

* Next greater/smaller element
* Previous greater/smaller element
* Contribution of each element to subarray answers
* Histogram rectangle boundaries

| Question                       |          LeetCode |
| ------------------------------ | ----------------: |
| Largest Rectangle in Histogram |                84 |
| Maximal Rectangle              |                85 |
| Sum of Subarray Minimums       |               907 |
| Online Stock Span              |               901 |
| Trapping Rain Water            | 42 — **Revision** |
| Remove K Digits                |               402 |
| Create Maximum Number          |               321 |

---

# 9. Recursion and Backtracking

## Techniques to learn

* Base cases and recursive calls
* Choose → explore → undo
* Subsets and combinations
* Permutations
* Duplicate avoidance
* Pruning
* Constraint checking
* Backtracking on grids
* Partitioning and decision trees

| Question                              |          LeetCode |
| ------------------------------------- | ----------------: |
| Fibonacci Number                      |               509 |
| Pow(x, n)                             |                50 |
| Subsets                               |                78 |
| Subsets II                            |                90 |
| Permutations                          | 46 — **Revision** |
| Permutations II                       |                47 |
| Combinations                          |                77 |
| Combination Sum                       |                39 |
| Combination Sum II                    |                40 |
| Combination Sum III                   |               216 |
| Letter Combinations of a Phone Number |                17 |
| Generate Parentheses                  |                22 |
| Palindrome Partitioning               |               131 |
| Word Search                           |                79 |
| N-Queens                              |                51 |
| Sudoku Solver                         |                37 |
| Restore IP Addresses                  |                93 |
| Matchsticks to Square                 |               473 |
| Expression Add Operators              |               282 |

---

# 10. Trees

## 10.1 Binary tree fundamentals

Learn:

* Node structure and pointers
* Preorder, inorder, postorder
* Recursive DFS
* Iterative DFS with a stack
* Level-order BFS with a queue
* Height, depth, and subtree properties

| Question                                |            LeetCode |
| --------------------------------------- | ------------------: |
| Binary Tree Preorder Traversal          |                 144 |
| Binary Tree Inorder Traversal           |                  94 |
| Binary Tree Postorder Traversal         |                 145 |
| Binary Tree Level Order Traversal       |                 102 |
| Binary Tree Level Order Traversal II    |                 107 |
| Maximum Depth of Binary Tree            |                 104 |
| Minimum Depth of Binary Tree            |                 111 |
| Invert Binary Tree                      |                 226 |
| Same Tree                               |                 100 |
| Symmetric Tree                          |                 101 |
| Count Complete Tree Nodes               |                 222 |
| Balanced Binary Tree                    |                 110 |
| Diameter of Binary Tree                 |                 543 |
| Count Nodes Equal to Average of Subtree | 2265 — **Revision** |

## 10.2 Tree path and subtree problems

Learn:

* Root-to-leaf paths
* Path sums
* Global versus returned answers
* Lowest common ancestor
* Subtree aggregation
* Tree serialization and construction

| Question                                                   | LeetCode |
| ---------------------------------------------------------- | -------: |
| Path Sum                                                   |      112 |
| Path Sum II                                                |      113 |
| Binary Tree Maximum Path Sum                               |      124 |
| Sum Root to Leaf Numbers                                   |      129 |
| Lowest Common Ancestor of a Binary Tree                    |      236 |
| Construct Binary Tree from Preorder and Inorder Traversal  |      105 |
| Construct Binary Tree from Inorder and Postorder Traversal |      106 |
| Serialize and Deserialize Binary Tree                      |      297 |
| Binary Tree Right Side View                                |      199 |
| All Nodes Distance K in Binary Tree                        |      863 |
| House Robber III                                           |      337 |
| Maximum Width of Binary Tree                               |      662 |
| Distribute Coins in Binary Tree                            |      979 |

## 10.3 Binary Search Trees (BST)

Learn:

* BST ordering property
* Search, insert, and delete
* Inorder traversal gives sorted order
* Validating a BST with bounds
* LCA in a BST
* Successor and predecessor

| Question                                   | LeetCode |
| ------------------------------------------ | -------: |
| Search in a Binary Search Tree             |      700 |
| Insert into a Binary Search Tree           |      701 |
| Delete Node in a BST                       |      450 |
| Validate Binary Search Tree                |       98 |
| Minimum Absolute Difference in BST         |      530 |
| Kth Smallest Element in a BST              |      230 |
| Lowest Common Ancestor of a BST            |      235 |
| Convert Sorted Array to Binary Search Tree |      108 |
| Recover Binary Search Tree                 |       99 |
| Binary Search Tree Iterator                |      173 |

## 10.4 Advanced tree structures

Learn:

* Trie
* Segment tree
* Fenwick tree / Binary Indexed Tree
* Lazy propagation
* Balanced BST concepts: AVL and Red-Black trees
* Tree diameter and rerooting DP
* Lowest common ancestor with binary lifting

| Question                                   | LeetCode |
| ------------------------------------------ | -------: |
| Implement Trie (Prefix Tree)               |      208 |
| Design Add and Search Words Data Structure |      211 |
| Word Search II                             |      212 |
| Count of Smaller Numbers After Self        |      315 |
| Range Sum Query – Mutable                  |      307 |
| My Calendar III                            |      732 |
| Create Sorted Array through Instructions   |     1649 |
| Number of Longest Increasing Subsequence   |      673 |

---


# 11. Heaps and Priority Queues

## Techniques to learn

* Min-heap and max-heap
* `priority_queue` in C++
* Top-K elements
* K-way merge
* Two heaps for medians
* Heap-based scheduling
* Lazy deletion when maintaining a heap

| Question                                      | LeetCode |
| --------------------------------------------- | -------: |
| Kth Largest Element in an Array               |      215 |
| Last Stone Weight                             |     1046 |
| K Closest Points to Origin                    |      973 |
| Top K Frequent Elements                       |      347 |
| Kth Largest Element in a Stream               |      703 |
| Find Median from Data Stream                  |      295 |
| Task Scheduler                                |      621 |
| Reorganize String                             |      767 |
| Sort Characters By Frequency                  |      451 |
| Find K Pairs with Smallest Sums               |      373 |
| Merge k Sorted Lists                          |       23 |
| Smallest Range Covering Elements from K Lists |      632 |
| IPO                                           |      502 |
| Meeting Rooms III                             |     2402 |

---

# 12. Greedy Algorithms

## Techniques to learn

* Make a locally optimal choice and prove why it works
* Sort by start time, end time, cost, or another useful property
* Interval scheduling
* Exchange arguments
* Greedy reachability
* Greedy allocation
* Greedy with heaps
* Recognizing when greedy fails and DP is needed

| Question                                   | LeetCode |
| ------------------------------------------ | -------: |
| Assign Cookies                             |      455 |
| Lemonade Change                            |      860 |
| Best Time to Buy and Sell Stock II         |      122 |
| Jump Game                                  |       55 |
| Jump Game II                               |       45 |
| Gas Station                                |      134 |
| Candy                                      |      135 |
| Partition Labels                           |      763 |
| Queue Reconstruction by Height             |      406 |
| Hand of Straights                          |      846 |
| Non-overlapping Intervals                  |      435 |
| Minimum Number of Arrows to Burst Balloons |      452 |
| Remove K Digits                            |      402 |
| Maximum Units on a Truck                   |     1710 |
| Minimum Number of Refueling Stops          |      871 |
| Course of action with a heap: IPO          |      502 |

**Practice goal:** Don't stop at getting the answer. Explain why choosing the next item can't make the optimal solution worse.

---

# 13. Intervals

## Techniques to learn

* Sort intervals by start or end
* Detect overlap
* Merge overlapping intervals
* Insert an interval
* Track active intervals with a heap
* Sweep-line events
* Difference arrays
* Calendar and resource scheduling

| Question                                       | LeetCode |
| ---------------------------------------------- | -------: |
| Merge Intervals                                |       56 |
| Insert Interval                                |       57 |
| Non-overlapping Intervals                      |      435 |
| Meeting Rooms                                  |      252 |
| Meeting Rooms II                               |      253 |
| Minimum Number of Arrows to Burst Balloons     |      452 |
| Interval List Intersections                    |      986 |
| Employee Free Time                             |      759 |
| My Calendar I                                  |      729 |
| My Calendar II                                 |      731 |
| My Calendar III                                |      732 |
| Minimum Interval to Include Each Query         |     1851 |
| Divide Intervals Into Minimum Number of Groups |     2406 |

---

# 14. Bit Manipulation

## Techniques to learn

* AND, OR, XOR, NOT
* Left and right shifts
* Check/set/clear/toggle a bit
* Test whether a number is a power of two
* XOR cancellation
* Bit masks for subsets
* Counting set bits
* Bitwise DP and tries

| Question                                |           LeetCode |
| --------------------------------------- | -----------------: |
| Single Number                           | 136 — **Revision** |
| Number of 1 Bits                        |                191 |
| Counting Bits                           |                338 |
| Reverse Bits                            |                190 |
| Missing Number                          | 268 — **Revision** |
| Power of Two                            |                231 |
| Power of Four                           |                342 |
| Sum of Two Integers                     |                371 |
| Bitwise AND of Numbers Range            |                201 |
| Single Number II                        |                137 |
| Single Number III                       |                260 |
| Maximum XOR of Two Numbers in an Array  |                421 |
| Subsets                                 |                 78 |
| Gray Code                               |                 89 |
| Minimum Flips to Make a OR b Equal to c |               1318 |

---

# 15. Graphs

Graphs are a large topic. Learn basic traversal first, then shortest paths, connectivity, and advanced algorithms.

## 15.1 Graph representation and traversal

Learn:

* Adjacency list and adjacency matrix
* Directed versus undirected graphs
* Weighted versus unweighted graphs
* BFS and DFS
* Visited arrays/sets
* Connected components
* Grid traversal as a graph

| Question                        | LeetCode |
| ------------------------------- | -------: |
| Find if Path Exists in Graph    |     1971 |
| Number of Provinces             |      547 |
| Number of Islands               |      200 |
| Max Area of Island              |      695 |
| Flood Fill                      |      733 |
| Clone Graph                     |      133 |
| Rotting Oranges                 |      994 |
| Walls and Gates                 |      286 |
| Surrounded Regions              |      130 |
| Pacific Atlantic Water Flow     |      417 |
| Keys and Rooms                  |      841 |
| All Paths From Source to Target |      797 |
| Number of Closed Islands        |     1254 |
| Shortest Path in Binary Matrix  |     1091 |
| 01 Matrix                       |      542 |

## 15.2 Topological sorting

Learn:

* Directed acyclic graphs (DAGs)
* Kahn's algorithm using indegrees
* DFS-based topological ordering
* Detecting cycles in directed graphs
* Dependency scheduling

| Question                                     | LeetCode |
| -------------------------------------------- | -------: |
| Course Schedule                              |      207 |
| Course Schedule II                           |      210 |
| Minimum Height Trees                         |      310 |
| Find Eventual Safe States                    |      802 |
| Alien Dictionary                             |      269 |
| Parallel Courses                             |     1136 |
| Sort Items by Groups Respecting Dependencies |     1203 |

## 15.3 Shortest paths

Learn:

* BFS for unweighted graphs
* 0–1 BFS
* Dijkstra's algorithm for nonnegative weights
* Bellman–Ford for negative edges
* Floyd–Warshall for all-pairs shortest paths
* Shortest paths in DAGs

| Question                                                                    | LeetCode |
| --------------------------------------------------------------------------- | -------: |
| Network Delay Time                                                          |      743 |
| Cheapest Flights Within K Stops                                             |      787 |
| Path With Minimum Effort                                                    |     1631 |
| Path with Maximum Probability                                               |     1514 |
| Swim in Rising Water                                                        |      778 |
| Find the City With the Smallest Number of Neighbors at a Threshold Distance |     1334 |
| Minimum Cost to Make at Least One Valid Path in a Grid                      |     1368 |
| Shortest Path Visiting All Nodes                                            |      847 |

## 15.4 Disjoint Set Union (DSU / Union-Find)

Learn:

* Parent and size/rank arrays
* Path compression
* Union by size or rank
* Connected-component queries
* Detecting cycles in undirected graphs
* Offline connectivity

| Question                                       | LeetCode |
| ---------------------------------------------- | -------: |
| Number of Provinces                            |      547 |
| Redundant Connection                           |      684 |
| Accounts Merge                                 |      721 |
| Number of Operations to Make Network Connected |     1319 |
| Most Stones Removed with Same Row or Column    |      947 |
| Satisfiability of Equality Equations           |      990 |
| Smallest String With Swaps                     |     1202 |
| Regions Cut By Slashes                         |      959 |
| Minimize Malware Spread                        |      924 |

## 15.5 Minimum spanning tree (MST)

Learn:

* Kruskal's algorithm
* Prim's algorithm
* DSU for cycle prevention
* Minimum total edge cost connecting all vertices

| Question                                 | LeetCode |
| ---------------------------------------- | -------: |
| Min Cost to Connect All Points           |     1584 |
| Connecting Cities With Minimum Cost      |     1135 |
| Optimize Water Distribution in a Village |     1168 |

## 15.6 Strongly connected components and bridges

Learn:

* Tarjan's algorithm
* Kosaraju's algorithm
* Discovery and low-link times
* Bridges and articulation points
* Strongly connected components

| Question                                    | LeetCode |
| ------------------------------------------- | -------: |
| Critical Connections in a Network           |     1192 |
| Minimum Number of Days to Disconnect Island |     1568 |
| Longest Cycle in a Graph                    |     2360 |

---


# 16. Dynamic Programming (DP)

DP is one of the biggest interview topics. Learn to identify the **state**, **transition**, **base case**, and **answer**.

## 16.1 DP fundamentals

Learn:

* Recursion versus memoization
* Top-down versus bottom-up
* State definition
* Transition equations
* Base cases
* Space optimization
* Reconstructing a solution

| Question                            | LeetCode |
| ----------------------------------- | -------: |
| Climbing Stairs                     |       70 |
| Min Cost Climbing Stairs            |      746 |
| Fibonacci Number                    |      509 |
| House Robber                        |      198 |
| House Robber II                     |      213 |
| Delete and Earn                     |      740 |
| Maximum Alternating Subsequence Sum |     1911 |
| Solving Questions With Brainpower   |     2140 |

## 16.2 One-dimensional DP

Learn:

* DP over an index
* Take-or-skip decisions
* Maintaining a small number of previous states
* Linear DP and state compression

| Question                                         |            LeetCode |
| ------------------------------------------------ | ------------------: |
| House Robber                                     |                 198 |
| House Robber II                                  |                 213 |
| Decode Ways                                      |                  91 |
| Word Break                                       |                 139 |
| Perfect Squares                                  |                 279 |
| Coin Change                                      |                 322 |
| Combination Sum IV                               |                 377 |
| Integer Break                                    |                 343 |
| Maximum Length of Subarray With Positive Product |                1567 |
| Jump Game                                        |                  55 |
| Jump Game II                                     |                  45 |
| Stone Game III                                   | 1406 — **Revision** |

## 16.3 Grid and two-dimensional DP

Learn:

* DP over rows and columns
* Moving through a grid
* Obstacles and blocked states
* Minimum/maximum path cost
* In-place and rolling-array optimization

| Question                 | LeetCode |
| ------------------------ | -------: |
| Unique Paths             |       62 |
| Unique Paths II          |       63 |
| Minimum Path Sum         |       64 |
| Triangle                 |      120 |
| Maximal Square           |      221 |
| Dungeon Game             |      174 |
| Minimum Falling Path Sum |      931 |
| Cherry Pickup            |      741 |
| Cherry Pickup II         |     1463 |

## 16.4 Knapsack and subset DP

Learn:

* 0/1 knapsack
* Unbounded knapsack
* Subset sum
* Target sum
* Partitioning
* One-dimensional DP update direction

| Question                   | LeetCode |
| -------------------------- | -------: |
| Partition Equal Subset Sum |      416 |
| Target Sum                 |      494 |
| Ones and Zeroes            |      474 |
| Coin Change                |      322 |
| Coin Change II             |      518 |
| Last Stone Weight II       |     1049 |
| Combination Sum IV         |      377 |
| Profitable Schemes         |      879 |

## 16.5 Longest increasing subsequence and sequence DP

Learn:

* DP ending at an index
* Comparing previous states
* Binary-search optimization for LIS
* Longest common subsequence

| Question                                 | LeetCode |
| ---------------------------------------- | -------: |
| Longest Increasing Subsequence           |      300 |
| Number of Longest Increasing Subsequence |      673 |
| Russian Doll Envelopes                   |      354 |
| Longest Common Subsequence               |     1143 |
| Uncrossed Lines                          |     1035 |
| Maximum Length of Repeated Subarray      |      718 |
| Longest Arithmetic Subsequence           |     1027 |
| Longest String Chain                     |     1048 |

## 16.6 String DP and edit distance

Learn:

* DP over two string indices
* Matching versus not matching
* Insert, delete, and replace transitions
* Palindromic subsequence DP

| Question                        | LeetCode |
| ------------------------------- | -------: |
| Edit Distance                   |       72 |
| Distinct Subsequences           |      115 |
| Interleaving String             |       97 |
| Regular Expression Matching     |       10 |
| Wildcard Matching               |       44 |
| Longest Palindromic Subsequence |      516 |
| Palindrome Partitioning II      |      132 |
| Scramble String                 |       87 |

## 16.7 Interval DP

Learn:

* Choosing a split point
* Solving smaller intervals first
* Combining left and right subproblems

| Question                                                                       | LeetCode |
| ------------------------------------------------------------------------------ | -------: |
| Matrix Chain Multiplication *(classic problem; not a standard LeetCode title)* |        — |
| Minimum Score Triangulation of Polygon                                         |     1039 |
| Burst Balloons                                                                 |      312 |
| Strange Printer                                                                |      664 |
| Minimum Cost to Cut a Stick                                                    |     1547 |
| Remove Boxes                                                                   |      546 |

## 16.8 DP on trees and graphs

Learn:

* DP states for each node
* Combining child states
* Tree take/skip decisions
* Bitmask states
* DAG DP

| Question                                                  | LeetCode |
| --------------------------------------------------------- | -------: |
| House Robber III                                          |      337 |
| Binary Tree Maximum Path Sum                              |      124 |
| Longest Increasing Path in a Matrix                       |      329 |
| Largest Divisible Subset                                  |      368 |
| Shortest Path Visiting All Nodes                          |      847 |
| Number of Ways to Stay in the Same Place After Some Steps |     1269 |

---

# 17. Tries and Prefix-Based Structures

## Techniques to learn

* Trie node structure
* Insert, search, and prefix search
* Word dictionaries
* Trie + DFS
* Bitwise trie for XOR queries

| Question                                   | LeetCode |
| ------------------------------------------ | -------: |
| Implement Trie (Prefix Tree)               |      208 |
| Design Add and Search Words Data Structure |      211 |
| Word Search II                             |      212 |
| Replace Words                              |      648 |
| Map Sum Pairs                              |      677 |
| Search Suggestions System                  |     1268 |
| Maximum XOR of Two Numbers in an Array     |      421 |
| Stream of Characters                       |     1032 |

---

# 18. Math, Number Theory and Combinatorics

## Techniques to learn

* GCD and LCM
* Euclidean algorithm
* Prime checking and Sieve of Eratosthenes
* Prime factorization
* Modular arithmetic
* Fast exponentiation
* Combinations and permutations
* Pigeonhole principle
* Digit manipulation
* Counting arguments

| Question                            |            LeetCode |
| ----------------------------------- | ------------------: |
| Count Primes                        |                 204 |
| Excel Sheet Column Number           |                 171 |
| Excel Sheet Column Title            |                 168 |
| Factorial Trailing Zeroes           |                 172 |
| Pow(x, n)                           |                  50 |
| GCD of Strings                      |                1071 |
| Ugly Number                         |                 263 |
| Happy Number                        |                 202 |
| Perfect Number                      |                 507 |
| Add Digits                          |                 258 |
| Integer Break                       |                 343 |
| Super Pow                           |                 372 |
| Smallest Divisible Digit Product I  | 3345 — **Revision** |
| Smallest Divisible Digit Product II | 3348 — **Revision** |
| Count Commas in Range               | 3870 — **Revision** |
| Smallest Missing Multiple of K      | 3718 — **Revision** |

---

# 19. Advanced Problem-Solving Patterns

These techniques often appear inside harder problems rather than as isolated topics.

## 19.1 Meet in the middle

Split the input into two halves, enumerate possibilities for each half, then combine them.

| Question                                                   | LeetCode |
| ---------------------------------------------------------- | -------: |
| Partition Array Into Two Arrays to Minimize Sum Difference |     2035 |
| Closest Subsequence Sum                                    |     1755 |

## 19.2 Sweep line and event processing

Sort events by coordinate or time, then maintain the active state.

| Question                                       | LeetCode |
| ---------------------------------------------- | -------: |
| The Skyline Problem                            |      218 |
| Meeting Rooms II                               |      253 |
| My Calendar III                                |      732 |
| Rectangle Area II                              |      850 |
| Divide Intervals Into Minimum Number of Groups |     2406 |

## 19.3 Bitmask DP

Represent a subset using bits; useful when the number of items is small.

| Question                                            | LeetCode |
| --------------------------------------------------- | -------: |
| Shortest Path Visiting All Nodes                    |      847 |
| Partition to K Equal Sum Subsets                    |      698 |
| Matchsticks to Square                               |      473 |
| Minimum Number of Work Sessions to Finish the Tasks |     1986 |

## 19.4 Randomization and reservoir sampling

Learn:

* Uniform random selection
* Reservoir sampling for streams
* Randomized algorithms and expected complexity

| Question                     | LeetCode |
| ---------------------------- | -------: |
| Insert Delete GetRandom O(1) |      380 |
| Linked List Random Node      |      382 |
| Random Pick Index            |      398 |
| Shuffle an Array             |      384 |

## 19.5 Design problems

These test whether you can combine data structures to meet operation and complexity requirements.

| Question                     | LeetCode |
| ---------------------------- | -------: |
| Min Stack                    |      155 |
| LRU Cache                    |      146 |
| LFU Cache                    |      460 |
| Insert Delete GetRandom O(1) |      380 |
| Design Twitter               |      355 |
| Time Based Key-Value Store   |      981 |
| Design Underground System    |     1396 |
| Design Browser History       |     1472 |
| Snapshot Array               |     1146 |
| All O`one Data Structure     |      432 |

---


# 20. Important Interview Patterns — Quick Reference

Use this as a recognition guide when you read a new problem.

| If the problem asks you to…                          | Consider learning/using…           |
| ---------------------------------------------------- | ---------------------------------- |
| Find a pair or triplet satisfying a condition        | Hash map, sorting + two pointers   |
| Find the longest/shortest valid contiguous segment   | Sliding window                     |
| Answer many range-sum queries                        | Prefix sums                        |
| Find a subarray sum with negative values allowed     | Prefix sum + hash map              |
| Find the next greater/smaller element                | Monotonic stack                    |
| Find the maximum/minimum in each moving window       | Monotonic deque                    |
| Search sorted data                                   | Binary search                      |
| Find the smallest feasible capacity, speed, or limit | Binary search on the answer        |
| Find top K elements                                  | Heap or quickselect                |
| Explore connected cells or nodes                     | BFS/DFS                            |
| Find the shortest path in an unweighted graph        | BFS                                |
| Find a shortest path with nonnegative edge weights   | Dijkstra                           |
| Check connectivity after merging components          | DSU / Union-Find                   |
| Resolve dependency ordering                          | Topological sort                   |
| Choose non-overlapping activities                    | Greedy + sorting                   |
| Combine overlapping ranges                           | Interval merging                   |
| Enumerate all valid arrangements                     | Backtracking                       |
| Find an optimal answer from overlapping subproblems  | Dynamic programming                |
| Find a prefix among many words                       | Trie                               |
| Support range queries and updates                    | Fenwick tree or segment tree       |
| Maintain a running median                            | Two heaps                          |
| Detect a cycle in a linked list                      | Fast and slow pointers             |
| Detect a cycle in an undirected graph                | DFS or DSU                         |
| Detect a cycle in a directed graph                   | DFS states or topological sort     |
| Count distinct combinations under constraints        | Backtracking, DP, or combinatorics |
| Work with a small set of elements and many subsets   | Bitmasking / bitmask DP            |

---

# 21. Recommended Learning Order

Since you want to build your DSA skills systematically, here's an order that develops the foundations before moving into more advanced patterns.

| Stage                          | Topics                                                      |
| ------------------------------ | ----------------------------------------------------------- |
| **1. Foundations**             | C++ STL, complexity analysis, arrays, strings               |
| **2. Core array patterns**     | Sorting, hashing, prefix sums, two pointers, sliding window |
| **3. Searching**               | Binary search, binary search on the answer                  |
| **4. Linear data structures**  | Linked lists, stacks, queues, monotonic stacks              |
| **5. Recursion**               | Recursion fundamentals, backtracking, subsets, permutations |
| **6. Trees**                   | Traversals, recursion on trees, BSTs, tree construction     |
| **7. Priority structures**     | Heaps, priority queues, top-K problems                      |
| **8. Greedy patterns**         | Greedy proofs, scheduling, intervals                        |
| **9. Graph foundations**       | BFS, DFS, components, cycle detection, topological sort     |
| **10. Graph algorithms**       | Dijkstra, DSU, MST, advanced graph algorithms               |
| **11. Dynamic programming**    | 1D DP, grid DP, knapsack, sequence DP, string DP            |
| **12. Specialized structures** | Tries, Fenwick trees, segment trees                         |
| **13. Advanced techniques**    | Bitmask DP, meet in the middle, sweep line, design problems |
| **14. Interview practice**     | Mixed problems, timed sessions, explaining solutions aloud  |

## How to practise each topic

For each new technique:

1. **Understand the idea.** Explain it in your own words before coding.
2. **Implement a basic version.** For example, implement binary search yourself before using a library function.
3. **Solve 2–3 easier problems.** Focus on correctness and understanding.
4. **Solve 2–4 medium problems.** Try to identify the pattern without looking at the solution.
5. **Review mistakes.** Record what you missed: the pattern, an edge case, a data structure, or syntax.
6. **Re-solve later without notes.** A solution you can reproduce independently is much more valuable than one you merely recognize.

For every problem, try to answer these four questions afterward:

* **Why does this algorithm work?**
* **What is its time complexity?**
* **What is its auxiliary space complexity?**
* **What constraint or clue in the problem suggested this approach?**

### A note about the list

This roadmap covers the major DSA topics and a large selection of representative LeetCode practice problems, but it isn't literally every algorithm or every possible problem. Some listed questions are advanced and are better attempted after their prerequisites. A few topics—such as AVL trees, Red-Black trees, and some classic algorithms—are more useful for understanding data structures and theory than for routine LeetCode practice.

**Your next step:** Start with **Foundations → Sorting → Arrays → Strings → Two Pointers/Sliding Window → Hashing**. Don't rush through the list just to tick boxes; focus on being able to derive and implement the logic yourself.
