# 1. What is a Hash Map?

A **hash map** is a data structure that stores information as **key-value pairs**.

Think of it like a dictionary:

| Key        | Value |
| ---------- | ----- |
| `"apple"`  | 3     |
| `"banana"` | 5     |
| `"mango"`  | 2     |

You use the **key** to find its associated **value**.

For example, if you want to know how many times `"apple"` appears, you can look up its key instead of searching through everything.

## Hash map in C++

In C++, we commonly use `unordered_map`.

```cpp
#include <unordered_map>
using namespace std;

unordered_map<string, int> freq;
```

This creates a hash map where:

* The key is a `string`.
* The value is an `int`.

### Example: Count how many times each number appears

Suppose:

```cpp
vector<int> nums = {2, 5, 2, 7, 5, 2};
```

We want to count each number's frequency.

```cpp
unordered_map<int, int> freq;

for (int num : nums) {
    freq[num]++;
}
```

After the loop:

| Key (`num`) | Value (`freq[num]`) |
| ----------: | ------------------: |
|           2 |                   3 |
|           5 |                   2 |
|           7 |                   1 |

The line:

```cpp
freq[num]++;
```

means: **increase the count stored for this number by 1**. If the key doesn't exist yet, `freq[num]` creates it with a default value of `0`, then increments it.

### Useful hash map operations

```cpp
unordered_map<int, int> mp;

mp[10] = 5;          // Store key 10 with value 5
mp[10]++;             // Increase its value
cout << mp[10];       // Access the value
mp.count(10);         // Returns 1 if key exists, otherwise 0
mp.erase(10);         // Remove the key
```

Hash maps have **average O(1)** lookup, insertion, and deletion. That makes them useful when you need to count things or quickly check whether you've seen a value.

### Where does hashing come in?

Hashing is the technique that helps a hash map decide where to store a key. A **hash function** converts a key into a number used to organize the data internally.

You usually don't need to implement the hash function yourself when using `unordered_map` in LeetCode.


---

# 2. What is a Monotonic Stack?

A **monotonic stack** is a stack that keeps its elements in a particular order.

There are two common types:

| Type                       | Order maintained                     |
| -------------------------- | ------------------------------------ |
| Monotonic increasing stack | Elements increase from bottom to top |
| Monotonic decreasing stack | Elements decrease from bottom to top |

When a new element breaks that order, we remove elements from the top until the order is restored.

**Why use it?** It's especially useful for finding the *next greater* or *next smaller* element without checking every element against every other element.

## Example: Next Greater Element

Suppose we have:

```cpp
vector<int> nums = {2, 1, 5, 3};
```

For each element, find the first greater element to its right.

The answer is:

| Element | Next greater element |
| ------: | -------------------: |
|       2 |                    5 |
|       1 |                    5 |
|       5 |                   -1 |
|       3 |                   -1 |

We can solve this with a **monotonic decreasing stack**.

```cpp
vector<int> ans(nums.size(), -1);
stack<int> st;

for (int i = 0; i < nums.size(); i++) {
    while (!st.empty() && nums[i] > nums[st.top()]) {
        ans[st.top()] = nums[i];
        st.pop();
    }

    st.push(i);
}
```

### What is stored in the stack?

Notice this line:

```cpp
st.push(i);
```

We're storing **indices**, not values. That lets us use an index to access the corresponding number with `nums[st.top()]`.

### Trace the example

| Current number | What happens                                                                      |
| -------------: | --------------------------------------------------------------------------------- |
|              2 | Stack is empty, so push index of 2                                                |
|              1 | 1 is smaller than 2, so push index of 1                                           |
|              5 | 5 is greater than 1 and 2, so pop both and record 5 as their next greater element |
|              3 | 3 is smaller than 5, so push index of 3                                           |

Any elements still in the stack at the end have no greater element to their right, so their answers remain `-1`.

**Complexity:** O(n) time and O(n) space. Although there's a `while` loop inside the `for` loop, each index is pushed once and popped at most once.

---

# 3. Where Do These Two Concepts Come in DSA?

## Hash map problems

Use a hash map when you need to count, look up, or associate information with keys.

| Problem                 | LeetCode | How hashing helps                           |
| ----------------------- | -------: | ------------------------------------------- |
| Two Sum                 |        1 | Quickly check whether the complement exists |
| Contains Duplicate      |      217 | Check whether a number has appeared before  |
| Group Anagrams          |       49 | Group words by a common frequency-based key |
| Top K Frequent Elements |      347 | Count each number's frequency               |
| Subarray Sum Equals K   |      560 | Store prefix-sum frequencies                |
| Next Greater Element I  |      496 | Map each number to its next greater element |

## Monotonic stack problems

Use a monotonic stack when you need to find nearby greater/smaller elements or maintain useful candidates in order.

| Problem                        | LeetCode | How the stack helps                                             |
| ------------------------------ | -------: | --------------------------------------------------------------- |
| Daily Temperatures             |      739 | Find the next warmer day                                        |
| Next Greater Element I         |      496 | Find the next greater value                                     |
| Next Greater Element II        |      503 | Find the next greater value in a circular array                 |
| Online Stock Span              |      901 | Count consecutive previous prices less than or equal to today's |
| Largest Rectangle in Histogram |       84 | Find boundaries where a bar can extend                          |
| Sum of Subarray Minimums       |      907 | Find how far each element contributes as a minimum              |

## Remember the difference

* **Hash map:** Helps you find or count information by key.
* **Monotonic stack:** Helps you maintain an ordered set of candidates and efficiently resolve elements when a greater or smaller value appears.

And one important detail: **a monotonic stack is not a separate C++ container.** You implement it using an ordinary `stack` and write the logic that maintains its order.
