# POTD — Problem of the Day

Daily LeetCode Problem of the Day solutions. One file per problem, named by LeetCode problem number.

---

## Goal

Solve the LeetCode POTD every single day. This builds consistency, exposes you to a variety of patterns, and keeps your skills sharp across all topics.

---

## File Naming

```
<problem-number>.c++    e.g.  2130.c++  (Maximum Twin Sum of a Linked List)
                              2095.c++  (Delete the Middle Node of a Linked List)
```

---

## Daily Routine

1. Open [LeetCode Daily Challenge](https://leetcode.com/problemset/all/?listId=daily-challenge)
2. Read the problem — understand it fully before coding
3. Think: what pattern does this use? (two pointers, DP, graph, etc.)
4. Write the solution in a new `.c++` file here
5. Add a `main()` with at least 3 test cases (see `DSA/basics/README.md` for the template)
6. Compile & verify: `g++ -std=c++17 -o sol XXXX.c++ && ./sol`
7. Submit on LeetCode

---

## How to Add a Local Test Runner

If you're writing a solution with a custom data structure (like `ListNode`), copy this header:

```cpp
#include <bits/stdc++.h>
using namespace std;

// ListNode definition (same as LeetCode)
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Helper: build list from vector
ListNode* build(vector<int> v) {
    ListNode dummy(0);
    ListNode* cur = &dummy;
    for (int x : v) { cur->next = new ListNode(x); cur = cur->next; }
    return dummy.next;
}

// Helper: list to vector (for comparison)
vector<int> toVec(ListNode* head) {
    vector<int> v;
    while (head) { v.push_back(head->val); head = head->next; }
    return v;
}

// TreeNode definition
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
```

---

## Resources

- [LeetCode Daily](https://leetcode.com/problemset/all/?listId=daily-challenge)
- [NeetCode.io](https://neetcode.io) — video explanations for most problems
- [LC Discuss](https://leetcode.com/discuss/) — community solutions and approach discussions
