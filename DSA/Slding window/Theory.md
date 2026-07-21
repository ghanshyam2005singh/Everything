
# 1. What is a Sliding Window?

Imagine an array:

```cpp
[1, 2, 3, 4, 5]
```

A "window" is just a continuous portion.

For example:

```cpp
[1, 2, 3]
```

or

```cpp
[2, 3, 4]
```

or

```cpp
[3, 4]
```

We usually track it using two pointers:

```cpp
left
right
```

Example:

```cpp
1 2 3 4 5
L     R
```

Current window:

```cpp
[1,2,3,4]
```

Length:

```cpp
right - left + 1
```

which is:

```cpp
3 - 0 + 1 = 4
```

---

## Growing the Window

Move `right`.

```cpp
1 2 3 4 5
L       R
```

Window becomes:

```cpp
[1,2,3,4,5]
```

---

## Shrinking the Window

Move `left`.

```cpp
1 2 3 4 5
  L     R
```

Window becomes:

```cpp
[2,3,4,5]
```

---

That's literally what a sliding window is:

```text
Expand -> Shrink -> Expand -> Shrink
```

using two pointers.

---

# 2. Why do we need Sliding Window?

Suppose:

```cpp
nums = [1,2,3,4,5]
k = 3
```

Find sum of every subarray of size 3.

Brute force:

```cpp
1+2+3
2+3+4
3+4+5
```

Instead of recalculating everything:

```cpp
1+2+3 = 6

remove 1
add 4

2+3+4 = 9

remove 2
add 5

3+4+5 = 12
```

That's the sliding window idea.

---

# 3. What is a HashSet?

In C++:

```cpp
unordered_set<int> st;
```

Think:

```text
A box that stores unique values.
```

Example:

```cpp
st.insert(5);
st.insert(7);
st.insert(9);
```

Now:

```cpp
{5,7,9}
```

---

## Check if value exists

```cpp
st.count(7)
```

returns:

```cpp
1
```

because 7 exists.

---

```cpp
st.count(100)
```

returns:

```cpp
0
```

because 100 doesn't exist.

---

Example:

```cpp
unordered_set<int> st;

st.insert(5);

cout << st.count(5);
```

Output:

```cpp
1
```

---

# 4. Common HashSet Syntax

## Insert

```cpp
st.insert(10);
```

---

## Remove

```cpp
st.erase(10);
```

---

## Check

```cpp
st.count(10)
```

returns:

```cpp
1 or 0
```

---

## Size

```cpp
st.size()
```

---

# 5. What is a HashMap?

HashMap = Key → Value pairs.

C++:

```cpp
unordered_map<char,int> mp;
```

Example:

```cpp
mp['a'] = 5;
mp['b'] = 10;
```

Stored:

```text
a -> 5
b -> 10
```

---

Access:

```cpp
cout << mp['a'];
```

Output:

```cpp
5
```

---

# 6. Why Set for LeetCode 3?

Question:

> Longest substring without repeating characters

We only need to know:

```text
Does character already exist?
```

Not frequency.

So Set is enough.

---

# 7. Understanding This Line

```cpp
st.count(s[right])
```

Suppose:

```cpp
s = "abcabc"
```

Current:

```cpp
right = 2
```

Character:

```cpp
s[right]
```

means:

```cpp
s[2]
```

which is:

```cpp
'c'
```

---

Then:

```cpp
st.count(s[right])
```

becomes:

```cpp
st.count('c')
```

Meaning:

```text
Does 'c' exist in the set?
```

Returns:

```cpp
1 or 0
```

---

# 8. Understanding This Loop

```cpp
while(st.count(s[right]))
```

Read it as:

```text
While current character already exists in window
```

---

Example:

```cpp
s = "abca"
```

Current window:

```cpp
abc
```

Set:

```cpp
{'a','b','c'}
```

---

Now right reaches:

```cpp
a
```

Again.

Check:

```cpp
st.count('a')
```

returns:

```cpp
1
```

Duplicate found.

---

# 9. Why Erase?

```cpp
st.erase(s[left]);
left++;
```

Suppose:

```cpp
abc
^
left
```

Remove:

```cpp
a
```

Set becomes:

```cpp
{'b','c'}
```

Move:

```cpp
left++
```

Window becomes:

```cpp
bc
```

Now duplicate gone.

---

# 10. Understanding

```cpp
ans = max(ans, right-left+1);
```

Window:

```cpp
abc
```

Indices:

```cpp
0 1 2
```

Length:

```cpp
2 - 0 + 1 = 3
```

---

Suppose:

```cpp
ans = 2
```

Current length:

```cpp
3
```

Then:

```cpp
ans=max(2,3);
```

becomes:

```cpp
3
```

---

# Mental Model

For LeetCode 3:

```text
1. Expand right pointer.
2. If duplicate appears:
      remove from left
      until duplicate disappears.
3. Update answer.
4. Continue.
```

Think of it like a rubber band:

```text
expand →
expand →
expand →
duplicate!
shrink ←
shrink ←
expand →
```

That's the essence of **Sliding Window**.

Before moving to harder sliding window problems, make sure you're comfortable with:

* `unordered_set`
* `unordered_map`
* `left/right pointers`
* `right-left+1`
* `insert()`
* `erase()`
* `count()`

These are the tools used in most sliding-window questions.
