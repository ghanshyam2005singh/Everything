### Time complexity: **O(1)**

Every operation takes constant time:

* `min()` and `max()` each take constant time.
* Subtraction and multiplication take constant time.
* The final comparison takes constant time.

The number of operations does not increase with the size of the input.

### Space complexity: **O(1)**

We only use a few integer variables: `closestX`, `closestY`, `dx`, and `dy`.

We don't create an array, loop through the input, or use recursion. The extra memory stays constant.

**Final answer:**

* **Time:** `O(1)`
* **Auxiliary space:** `O(1)`

---


# 2. What do time and space complexity actually mean?

When you write a solution, you should ask two questions:

### Time complexity

**How does the amount of work grow as the input gets bigger?**

For example, if an array has `n` elements, how many times does your code process those elements?

### Space complexity

**How does the extra memory used by your algorithm grow as the input gets bigger?**

For example, does your code create another array of size `n`, or does it only use two or three variables?

We usually express these using **Big O notation**.

| Complexity   | Meaning      | Example                                          |
| ------------ | ------------ | ------------------------------------------------ |
| `O(1)`       | Constant     | Accessing `nums[0]`                              |
| `O(log n)`   | Logarithmic  | Binary search                                    |
| `O(n)`       | Linear       | One loop through an array                        |
| `O(n log n)` | Linearithmic | Efficient comparison sorting, such as merge sort |
| `O(n²)`      | Quadratic    | Two nested loops over an array                   |
| `O(2ⁿ)`      | Exponential  | Some recursive subset-generation algorithms      |
| `O(n!)`      | Factorial    | Generating all permutations                      |

These describe how the work or memory grows, not the exact number of seconds or bytes.

---

# 3. How to calculate time complexity

## Rule 1: Ignore constant operations → O(1)

```cpp
int x = 10;
int y = 20;
int sum = x + y;
cout << sum;
```

There are a few operations, but their number doesn't depend on an input size.

**Time: `O(1)`**

---

## Rule 2: One loop → usually O(n)

```cpp
for (int i = 0; i < n; i++) {
    cout << i;
}
```

The loop runs `n` times.

If `n = 10`, it runs 10 times.

If `n = 1000`, it runs 1000 times.

So the work grows proportionally to `n`.

**Time: `O(n)`**

Another example:

```cpp
for (int i = 0; i < n; i++) {
    cout << nums[i];
}

for (int i = 0; i < n; i++) {
    cout << nums[i];
}
```

Each loop runs `n` times, so there are roughly `2n` operations.

Big O ignores constant multipliers:

`O(2n) = O(n)`

**Time: `O(n)`**

---

## Rule 3: Nested loops → usually O(n²)

```cpp
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        cout << i << " " << j;
    }
}
```

The outer loop runs `n` times.

For each outer iteration, the inner loop also runs `n` times.

Total iterations:

$$
n \times n = n^2
$$

**Time: `O(n²)`**

### What if the loop sizes differ?

```cpp
for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        cout << i << " " << j;
    }
}
```

The outer loop runs `n` times and the inner loop runs `m` times.

**Time: `O(nm)`**

Don't automatically call every nested loop `O(n²)`; check how many times each loop runs.

---


## Rule 4: A loop that repeatedly halves or doubles → often O(log n)

Consider binary search:

```cpp
int left = 0;
int right = n - 1;

while (left <= right) {
    int mid = left + (right - left) / 2;

    if (nums[mid] == target)
        return mid;

    if (nums[mid] < target)
        left = mid + 1;
    else
        right = mid - 1;
}
```

Each iteration eliminates approximately half the remaining search space.

For example, if there are 16 elements:

```text
16 → 8 → 4 → 2 → 1
```

It takes about 4–5 iterations, rather than 16.

**Time: `O(log n)`**

A common way to recognize logarithmic loops is to look for something like:

```cpp
i *= 2;
```

or:

```cpp
n /= 2;
```

The exact complexity depends on how the loop changes its variables.

---

## Rule 5: Analyze the loop's actual bounds

Consider:

```cpp
for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
        cout << i << " " << j;
    }
}
```

The inner loop doesn't always run `n` times.

* When `i = 0`, it runs `n` times.
* When `i = 1`, it runs `n - 1` times.
* When `i = 2`, it runs `n - 2` times.
* Eventually, it runs once.

The total is:

$$
n+(n-1)+(n-2)+\cdots+1
=\frac{n(n+1)}{2}
$$

The dominant term is proportional to `n²`.

**Time: `O(n²)`**

---

# 4. How to calculate space complexity

For space complexity, focus on **additional memory your algorithm uses**.

## Example 1: Only a few variables → O(1)

```cpp
int sum = 0;

for (int i = 0; i < n; i++) {
    sum += nums[i];
}
```

The loop runs `n` times, but the algorithm only uses a few variables.

**Time: `O(n)`**

**Auxiliary space: `O(1)`**

The loop does not create additional memory proportional to `n`.

## Example 2: Creating a vector of size n → O(n)

```cpp
vector<int> ans(n);

for (int i = 0; i < n; i++) {
    ans[i] = nums[i] * 2;
}
```

The vector stores `n` integers.

**Time: `O(n)`**

**Auxiliary space: `O(n)`**

## Example 3: Creating a 2D matrix → O(n²)

```cpp
vector<vector<int>> matrix(n, vector<int>(n, 0));
```

The matrix contains `n × n` elements.

**Space: `O(n²)`**

## Example 4: Recursion also uses memory

```cpp
void printNumbers(int n) {
    if (n == 0)
        return;

    printNumbers(n - 1);
}
```

The function calls itself `n` times before reaching the base case.

Each call uses a stack frame, so the call stack grows proportionally to `n`.

**Time: `O(n)`**

**Auxiliary space: `O(n)`**

---

# 5. A common interview mistake: confusing time and space

Look at this solution:

```cpp
bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> seen;

    for (int num : nums) {
        if (seen.count(num))
            return true;

        seen.insert(num);
    }

    return false;
}
```

Assuming average-case `unordered_set` operations:

* The loop processes up to `n` elements.
* Each lookup and insertion takes average `O(1)`.
* The set can store up to `n` elements.

Therefore:

| Complexity      | Result |
| --------------- | ------ |
| Average time    | `O(n)` |
| Auxiliary space | `O(n)` |

The set makes the solution use extra memory, but helps avoid comparing every element against every other element.

*Note:* `unordered_set` operations are average-case `O(1)`; their worst-case behavior can be slower.

---

# 6. Your quick checklist for any LeetCode solution

Whenever you finish writing code, go through these questions:

### Time complexity checklist

1. **Are there loops?** Count how many times each loop runs.
2. **Are there nested loops?** Multiply their iteration counts when appropriate.
3. **Does a variable repeatedly halve or double?** Consider `O(log n)`.
4. **Are there recursive calls?** Work out how many calls are made and how much work each call does.
5. **Are there library operations?** Consider their complexity too. For example, sorting a vector typically takes `O(n log n)`.
6. **Simplify the result.** Ignore constant factors and lower-order terms.

### Space complexity checklist

1. **Are you creating another vector, array, map, or set?** Count how its size grows.
2. **Are you using recursion?** Consider the maximum recursion stack depth.
3. **Are you using only a fixed number of variables?** That is usually `O(1)` auxiliary space.
4. **Does the memory grow with the input size?** If so, express that growth using Big O.

One more distinction: **auxiliary space** means extra memory used by the algorithm, excluding the input itself. Some problems or interviewers ask for total space instead, so clarify which convention you're using.

---

# 7. Practice: test yourself

Try calculating the complexities of these three snippets before checking the answers.

### A

```cpp
for (int i = 0; i < n; i++) {
    cout << nums[i];
}
```

### B

```cpp
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        cout << nums[i] + nums[j];
    }
}
```

### C

```cpp
vector<int> result;

for (int i = 0; i < n; i++) {
    result.push_back(nums[i]);
}
```

**Answers:**

| Snippet | Time    | Auxiliary space |
| ------- | ------- | --------------- |
| A       | `O(n)`  | `O(1)`          |
| B       | `O(n²)` | `O(1)`          |
| C       | `O(n)`  | `O(n)`          |

For snippet C, `push_back()` is amortized `O(1)` per insertion, so inserting `n` elements takes amortized `O(n)` time.

## The main thing to remember

**Time complexity is about how the work grows. Space complexity is about how the extra memory grows.**

For your current problem, LeetCode 1401, neither depends on the size of an input collection: the algorithm performs a fixed number of operations and uses a fixed number of variables. That's why both are `O(1)`.
