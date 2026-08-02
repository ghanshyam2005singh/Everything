This is one of the most famous "trick" problems on LeetCode.

When you first read it, it feels like a **Dynamic Programming / Minimax** problem.

But **LeetCode 877 has a hidden observation** that makes the answer incredibly simple.

---

# Observation 1

The number of piles is **always even**.

Example:

```text
4 piles

5 3 4 5
```

or

```text
6 piles

2 9 4 6 8 3
```

There are always an equal number of **even-indexed** and **odd-indexed** piles.

---

# Observation 2

Alice moves first.

Suppose there are 4 piles.

```text
Index

0   1   2   3
5   3   4   5
```

Alice can take

* left → index 0
* right → index 3

Notice:

```text
0 -> even index

3 -> odd index
```

So Alice gets to decide:

> "Do I want to collect all the even-index piles, or all the odd-index piles?"

This is the key idea.

---

# Why can Alice always do that?

Take

```text
5 3 4 5
```

Indices

```text
0 1 2 3
```

Suppose Alice chooses **even-index piles**.

### Move 1

Take left.

```text
5 3 4 5
^

Alice gets index 0
```

Remaining

```text
3 4 5
```

Bob can take

* left (index 1 originally)
* right (index 3 originally)

Whichever Bob takes, Alice will always be able to take the remaining even-index pile next.

This pattern continues until the end.

---

The same happens if Alice decides to collect **odd-index piles**.

She can force the game to stay on that parity.

---

# Observation 3

Compute

```text
sumEven
```

and

```text
sumOdd
```

One of them is larger.

Since

```text
Total sum is odd
```

they can never be equal.

So

```text
sumEven > sumOdd
```

or

```text
sumOdd > sumEven
```

Alice simply chooses the larger one.

Therefore

```text
Alice always wins.
```

---

# Therefore

The answer is literally

```cpp
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};
```

Yes...

That's the official accepted solution for this specific problem.

---

# Wait... why do people learn DP for this?

Because this problem is a simplified version.

Problems like

* Stone Game II
* Stone Game III
* Predict the Winner (486)
* Stone Game VII
* Stone Game VIII

**cannot** use this trick.

They require **DP + Minimax**.

---

# If the constraints were different...

Suppose

```text
Number of piles can be odd.
```

Then Alice cannot commit to only even or only odd indices.

Now the trick fails.

You would need DP.

---

# Interview perspective

If an interviewer gives you this exact problem, they usually expect you to notice the mathematical observation.

If they modify even one condition (odd number of piles, different picking rules, etc.), then the DP solution becomes necessary.

---

## Takeaway

When you see a game problem, check these before writing DP:

* ✅ Does the first player have a forced strategy?
* ✅ Is there a parity (even/odd) trick?
* ✅ Can one player commit to a fixed set of positions?
* ✅ Do the constraints guarantee something special (like even number of piles or odd total sum)?

Only if none of these shortcuts work should you move to a full DP/minimax solution.

This is a good reminder that **not every game problem needs DP**—sometimes the constraints themselves contain the key insight.
