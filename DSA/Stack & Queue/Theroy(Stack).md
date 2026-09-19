These are exactly the right questions to ask. Don't memorize stack problems. Understand **why** a stack exists.

---

# 1. How do I know when to use a Stack?

Think of a stack as:

```text
Last thing added
=
First thing removed
```

This is called:

```text
LIFO
(Last In First Out)
```

Example:

```text
Books:

Top -> Book 3
       Book 2
       Book 1
```

If you remove a book:

```text
Book 3 comes out first
```

not Book 1.

---

## Common Stack Clues

### Clue 1: "Previous element"

Question says:

```text
Use previous score
Use last operation
Undo last action
```

Example:

```text
682. Baseball Game
```

Need previous scores.

Stack.

---

### Clue 2: "Undo"

Example:

```text
Ctrl + Z
Browser back button
```

Need most recent action.

Stack.

---

### Clue 3: Matching pairs

Example:

```text
()
[]
{}
```

Question:

```text
20. Valid Parentheses
```

Open bracket goes into stack.

When closing bracket comes, check top.

Stack.

---

### Clue 4: Next Greater Element

Example:

```text
2 1 5 3
```

Need nearest greater element.

Monotonic Stack.

---

### Clue 5: Expression evaluation

```text
2 + 3 * 4
```

Stack.

---

# 2. Why `st.pop();` and not `st.pop`?

Because `pop` is a **function**.

Functions need parentheses.

Example:

```cpp
max(5,10);
```

not

```cpp
max;
```

---

Think:

```cpp
st.pop();
```

means:

```text
"Execute pop operation"
```

while:

```cpp
st.pop
```

means:

```text
Just referring to pop function
Not calling it
```

---

Same for:

```cpp
st.push(5);
st.top();
st.empty();
```

All are functions.

---

# 3. What is this?

```cpp
st.push(stoi(op));
```

Break it apart.

---

Suppose:

```cpp
op = "123"
```

Notice:

```cpp
"123"
```

is a string.

Not an integer.

---

You cannot do:

```cpp
st.push(op);
```

because stack stores:

```cpp
stack<int>
```

---

Need conversion.

```cpp
stoi("123")
```

returns:

```cpp
123
```

(integer)

---

Example:

```cpp
string s = "45";

int x = stoi(s);

cout << x;
```

Output:

```text
45
```

---

Then:

```cpp
st.push(stoi(op));
```

becomes:

```cpp
st.push(123);
```

---

# 4. Why not

```cpp
st.push[i]
```

or

```cpp
st.push = st[i]
```

?

Because stack is NOT an array.

---

Array:

```cpp
vector<int> arr;
```

supports:

```cpp
arr[i]
```

because elements have indexes.

---

Stack:

```cpp
stack<int> st;
```

looks like:

```text
Top
 5
 3
 2
```

No indexing exists.

You cannot access:

```cpp
st[0]
st[1]
```

---

C++ stack only allows:

```cpp
st.push(x)
st.pop()
st.top()
```

---

Think:

```text
Pile of plates
```

Can you directly grab the middle plate?

No.

Only top plate.

Same with stack.

---

# Important Difference

### Vector

```cpp
vector<int> v = {10,20,30};
```

Can do:

```cpp
v[0]
v[1]
v[2]
```

---

### Stack

```cpp
stack<int> st;
```

Can only do:

```cpp
st.top()
```

No indexing.

---

# Stack Functions You Must Know

### Push

Add element

```cpp
st.push(5);
```

Stack:

```text
5
```

---

### Push again

```cpp
st.push(10);
```

Stack:

```text
10
 5
```

---

### Top

```cpp
cout << st.top();
```

Output:

```text
10
```

---

### Pop

```cpp
st.pop();
```

Stack becomes:

```text
5
```

---

### Empty

```cpp
st.empty()
```

returns:

```cpp
true
```

if stack has no elements.

---

### Size

```cpp
st.size()
```

returns number of elements.

---

# Very Important

Many beginners think:

```cpp
int x = st.pop();
```

works.

It DOES NOT.

---

Wrong:

```cpp
int x = st.pop();
```

because:

```cpp
pop()
```

returns nothing.

---

Correct:

```cpp
int x = st.top();
st.pop();
```

Example:

```cpp
int x = st.top();
st.pop();
```

means:

```text
Take top value
Store in x
Remove it
```

---

# Example

```cpp
stack<int> st;

st.push(5);
st.push(10);
st.push(20);
```

Stack:

```text
20
10
 5
```

---

```cpp
cout << st.top();
```

Output:

```text
20
```

---

```cpp
st.pop();
```

Stack:

```text
10
 5
```

---

```cpp
cout << st.top();
```

Output:

```text
10
```

---

# Before Starting Stack Problems

You should be comfortable with:

```cpp
push()
pop()
top()
empty()
size()
```

And understand:

```text
Stack = LIFO
Only top element accessible
No indexing
Perfect for:
- Undo operations
- Previous element tracking
- Parentheses matching
- Next Greater Element
- Monotonic Stack problems
```

A great learning order is:

1. 682. Baseball Game
2. 20. Valid Parentheses
3. 1047. Remove All Adjacent Duplicates In String
4. 496. Next Greater Element I
5. 739. Daily Temperatures
6. 155. Min Stack

After those, stacks will feel much more natural.
