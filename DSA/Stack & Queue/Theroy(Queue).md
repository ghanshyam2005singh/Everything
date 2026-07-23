Queue is related to a stack, but the way you think about it is different.

# Stack vs Queue

## Stack (LIFO)

Last In First Out

Imagine a stack of plates:

```text
Top
4
3
2
1
```

You add on top:

```cpp
st.push(5);
```

```text
5
4
3
2
1
```

You remove from top:

```cpp
st.pop();
```

5 comes out first.

---

## Queue (FIFO)

First In First Out

Imagine a line at a ticket counter:

```text
Front -> A B C D <- Back
```

A entered first.

If someone leaves:

```text
A leaves
```

Now:

```text
Front -> B C D <- Back
```

The first person who came is the first person served.

That's FIFO.

---

# Queue Operations

Create:

```cpp
#include <queue>

queue<int> q;
```

---

## Push

Add at the back

```cpp
q.push(10);
q.push(20);
q.push(30);
```

Queue:

```text
Front -> 10 20 30 <- Back
```

---

## Front

See first element

```cpp
cout << q.front();
```

Output:

```text
10
```

---

## Back

See last element

```cpp
cout << q.back();
```

Output:

```text
30
```

---

## Pop

Remove from front

```cpp
q.pop();
```

Queue becomes:

```text
Front -> 20 30 <- Back
```

Notice:

Unlike stack:

```cpp
st.pop();
```

removes top.

Queue:

```cpp
q.pop();
```

removes front.

---

## Empty

```cpp
q.empty();
```

Returns:

```cpp
true
```

if queue is empty.

---

## Size

```cpp
q.size();
```

Returns number of elements.

---

# Common Beginner Mistake

This does NOT work:

```cpp
int x = q.pop();
```

Same reason as stack.

`pop()` returns nothing.

Correct:

```cpp
int x = q.front();
q.pop();
```

---

# Stack Functions vs Queue Functions

| Stack   | Queue   |
| ------- | ------- |
| push()  | push()  |
| pop()   | pop()   |
| top()   | front() |
| size()  | size()  |
| empty() | empty() |

---

# Why no top() in Queue?

Because queue has two ends.

```text
Front -> A B C D <- Back
```

You may want:

```cpp
q.front();
```

or

```cpp
q.back();
```

There is no single "top".

---

# Can we do indexing?

No.

This is invalid:

```cpp
q[0]
q[1]
```

Just like stack.

Queue does not support random access.

---

# When do we use Queue?

The biggest clue:

## "Process in order"

Example:

```text
Person 1 arrived
Person 2 arrived
Person 3 arrived
```

Need to process them in same order.

Queue.

---

## BFS (Very Important)

When you learn trees and graphs:

```text
Level 1
Level 2
Level 3
```

We use Queue.

Example:

LeetCode

* 102. Binary Tree Level Order Traversal
* 994. Rotting Oranges
* 200. Number of Islands (BFS)

All use Queue.

---

# Real World Examples

## Queue

```text
Ticket counter
Food delivery orders
CPU scheduling
Printer jobs
Call center waiting line
```

---

## Stack

```text
Undo
Browser back button
Function calls
Parentheses matching
```

---

# Another Useful Type: Deque

After queue, learn:

```cpp
deque<int> dq;
```

Deque = Double Ended Queue

Can insert/remove from both ends.

```cpp
dq.push_front(5);
dq.push_back(10);

dq.pop_front();
dq.pop_back();
```

Many sliding window problems use deque.

---

# Quick Visualization

### Stack

```text
push(1)
push(2)
push(3)

3
2
1

pop()

2
1
```

---

### Queue

```text
push(1)
push(2)
push(3)

Front -> 1 2 3 <- Back

pop()

Front -> 2 3 <- Back
```

---

For DSA progression, after Arrays and Strings, a good order is:

1. Stack
2. Queue
3. Linked List
4. Hash Map (`unordered_map`)
5. Hash Set (`unordered_set`)
6. Sliding Window
7. Binary Search
8. Trees
9. Heap/Priority Queue
10. Graphs

Since you've already started Binary Search and Sliding Window questions, learning **Hash Map/Hash Set next** will make many LeetCode mediums much easier.
