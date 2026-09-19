This is one of the **most important Stack problems** on LeetCode.

It teaches something called a **Monotonic Stack**, which appears in many problems like:

* ✅ 739. Daily Temperatures
* ✅ 496. Next Greater Element I
* ✅ 503. Next Greater Element II
* ✅ 84. Largest Rectangle in Histogram
* ✅ 42. Trapping Rain Water (one solution)
* ✅ 901. Online Stock Span

Since you've recently learned stacks, let's build this from scratch instead of jumping to the code.

---

# Step 1: Understand the question

Given

```text
[73,74,75,71,69,72,76,73]
```

For every day, we want to know:

> "After how many days will I see a **warmer** temperature?"

Example:

```
73
 ^
```

Next warmer is

```
74
```

1 day later.

Answer = 1

---

For

```
75
```

Look ahead.

```
71
69
72
76
```

The first warmer temperature is

```
76
```

which is 4 days later.

Answer = 4

---

For

```
76
```

There is nothing warmer.

Answer = 0

---

Final answer

```
[1,1,4,2,1,1,0,0]
```

---

# Step 2: The brute force

The first thing almost everyone writes is:

```cpp
for(i)
{
    for(j=i+1)
    {
        if(temp[j]>temp[i])
        {
            ans[i]=j-i;
            break;
        }
    }
}
```

Time Complexity

```
O(n²)
```

For

```
100000
```

elements

```
100000²

=

10^10
```

Too slow.

---

# Step 3: Think differently

Suppose

```
73 74 75 71 69 72 76
```

When we reach

```
72
```

Who gets happy?

Only temperatures **smaller than 72** waiting behind it.

Those are

```
69
71
```

Not

```
75
```

because

```
72 is NOT warmer than 75
```

So we only care about unresolved smaller temperatures.

This is exactly what a stack helps us track.

---

# Step 4: What do we store?

This is where many beginners get confused.

Should we store

```
73
74
75
```

?

No.

We store **indices**.

```
0
1
2
...
```

Why?

Because the answer needs

```
days difference

=

currentIndex - previousIndex
```

If we only store temperatures,

```
73
```

we don't know where it came from.

---

So stack contains

```
0
1
2
```

not

```
73
74
75
```

---

# Step 5: Dry Run

Temperatures

```
Index

0 1 2 3 4 5 6 7

73 74 75 71 69 72 76 73
```

Initially

```
Stack = empty
```

Answer

```
0 0 0 0 0 0 0 0
```

---

## Day 0

```
73
```

Nobody before it.

Push index.

Stack

```
0
```

---

## Day 1

```
74
```

Top is

```
73
```

Is

```
74 >73 ?

Yes
```

Now we found the next warmer day.

Answer for index 0

```
1-0

=

1
```

Answer

```
1 0 0 0 0 0 0 0
```

Pop 0.

Stack empty.

Push 1.

Stack

```
1
```

---

## Day 2

```
75
```

Compare

```
75>74

Yes
```

Answer

```
2-1

=

1
```

Pop.

Push 2.

Stack

```
2
```

---

## Day 3

```
71
```

Compare

```
71>75?

No
```

Push.

Stack

```
2
3
```

Notice stack temperatures

```
75
71
```

---

## Day 4

```
69
```

Compare

```
69>71?

No
```

Push.

Stack

```
2
3
4
```

Temperatures

```
75
71
69
```

---

## Day 5

```
72
```

Compare with top.

Top

```
69
```

Is

```
72>69

Yes
```

Answer

```
5-4

=

1
```

Pop.

Stack

```
2
3
```

Again

Top

```
71
```

Is

```
72>71

Yes
```

Answer

```
5-3

=

2
```

Pop.

Stack

```
2
```

Now compare

```
72>75?

No
```

Stop.

Push 5.

Stack

```
2
5
```

---

## Day 6

```
76
```

Top

```
72
```

Warmer.

Answer

```
6-5=1
```

Pop.

Top

```
75
```

Warmer again.

Answer

```
6-2=4
```

Pop.

Push 6.

---

Done.

Remaining stack

```
6
7
```

Never found warmer day.

They stay

```
0
```

---

# Step 6: The Algorithm

For every temperature

```
while(stack not empty
      &&
      current temperature
      >
      temperature at stack top)
{
     answer[top]=currentIndex-top;

     pop
}

push(currentIndex)
```

---

# Step 7: Code

```cpp
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        int n = temperatures.size();

        vector<int> ans(n, 0);

        stack<int> st;          // stores indices

        for (int i = 0; i < n; i++) {

            while (!st.empty() &&
                   temperatures[i] > temperatures[st.top()]) {

                int prev = st.top();
                st.pop();

                ans[prev] = i - prev;
            }

            st.push(i);
        }

        return ans;
    }
};
```

---

# Line-by-line explanation

## Create answer array

```cpp
vector<int> ans(n,0);
```

Initially

```
0 0 0 0 0 0 0 0
```

---

## Create stack

```cpp
stack<int> st;
```

Stores indices

```
0
1
2
```

not temperatures.

---

## Traverse all days

```cpp
for(int i=0;i<n;i++)
```

Current day

```
i
```

---

## Main condition

```cpp
while(!st.empty() &&
      temperatures[i] >
      temperatures[st.top()])
```

Read it in English:

> "As long as the stack is not empty, and today's temperature is warmer than the temperature of the day on top of the stack..."

---

## Save index

```cpp
int prev = st.top();
```

Suppose stack

```
2
```

Then

```
prev=2
```

---

## Remove it

```cpp
st.pop();
```

Because we've now found its answer.

---

## Fill answer

```cpp
ans[prev]=i-prev;
```

Example

```
prev=2

current=6
```

Answer

```
6-2

=

4
```

---

## Push current day

```cpp
st.push(i);
```

Because maybe a future day will be warmer than today's.

---

# Why does this work?

Each index is:

* pushed exactly **once**
* popped exactly **once**

So even though there is a `while` loop, every element can only be removed one time.

Therefore:

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(n)`

---

# How do I know this is a stack problem?

These clues usually point to a **monotonic stack**:

* "Next greater element"
* "Next warmer day"
* "Previous smaller element"
* "Nearest greater/smaller"
* "First bigger value on the left/right"
* You're looking for the **first** future (or past) element satisfying a condition.

Whenever you see those patterns, think: **"Can I keep unresolved elements in a stack until I find their answer?"**

---

## Practice these next (in this exact order)

1. ✅ 496. Next Greater Element I
2. ✅ 503. Next Greater Element II
3. ✅ 844. Backspace String Compare
4. ✅ 71. Simplify Path
5. ✅ 402. Remove K Digits
6. ✅ 901. Online Stock Span

These problems build directly on the same stack concepts and will make monotonic stacks feel much more natural.
