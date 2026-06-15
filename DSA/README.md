# DSA — Data Structures & Algorithms

This folder is the core of algorithm learning. It contains a complete STL reference, solutions to foundational problems, and is the place to practice until patterns become instinct.

---

## Folder Layout

```
DSA/
├── STL.c++       # Complete STL containers + algorithm cheatsheet (runnable)
└── basics/       # LeetCode solutions with test runners
```

---

## Step-by-Step Learning Path

### Week 1-2: STL Mastery
- Read through `STL.c++` top to bottom — compile and run it
- Know every container's time complexity cold
- Practice: vector, map, set, priority_queue without looking up syntax

### Week 3-4: Arrays & Strings
- Two pointers, sliding window, prefix sums
- Problems: LeetCode Easy/Medium on arrays
- Key patterns: subarray sum, longest substring, rotation

### Week 5-6: Linked Lists & Stacks/Queues
- Fast/slow pointers, reverse in groups
- Monotonic stack, next greater element

### Week 7-8: Binary Search
- Search in rotated array, find peak, on answer space
- Template: `lo=0, hi=n-1, while(lo<=hi), mid=lo+(hi-lo)/2`

### Week 9-10: Trees & Recursion
- Inorder/Preorder/Postorder iteratively and recursively
- Height, diameter, LCA, path sum
- BST operations: insert, delete, validate

### Week 11-12: Graphs
- BFS (shortest path), DFS (connected components, cycle)
- Topological sort, Union-Find
- Dijkstra, Bellman-Ford

### Week 13-16: Dynamic Programming
- 1D DP: climbing stairs, house robber, coin change
- 2D DP: LCS, edit distance, 0/1 knapsack
- DP on trees and intervals

---

## Core Data Structures — Time Complexities

| Structure        | Access | Search | Insert | Delete |
|------------------|--------|--------|--------|--------|
| Array            | O(1)   | O(n)   | O(n)   | O(n)   |
| Linked List      | O(n)   | O(n)   | O(1)   | O(1)   |
| Stack/Queue      | O(n)   | O(n)   | O(1)   | O(1)   |
| Hash Map         | -      | O(1)*  | O(1)*  | O(1)*  |
| BST (balanced)   | -      | O(log n)| O(log n)| O(log n)|
| Heap             | O(1) top| O(n)  | O(log n)| O(log n)|
| Trie             | -      | O(L)   | O(L)   | O(L)   |

*amortized; L = string length

---

## Algorithm Patterns

### 1. Two Pointers
Use when: sorted array, pair/triplet sum, palindrome check.
```cpp
int l = 0, r = n - 1;
while (l < r) {
    if (condition) l++;
    else r--;
}
```

### 2. Sliding Window
Use when: subarray/substring of fixed or variable size.
```cpp
int l = 0, sum = 0, ans = 0;
for (int r = 0; r < n; r++) {
    sum += a[r];
    while (sum > target) sum -= a[l++];
    ans = max(ans, r - l + 1);
}
```

### 3. Binary Search
Use when: monotone condition, sorted input, "minimum maximum" type.
```cpp
int lo = 0, hi = n - 1, ans = -1;
while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    if (check(mid)) { ans = mid; hi = mid - 1; }
    else lo = mid + 1;
}
```

### 4. BFS (Shortest Path / Level Order)
```cpp
queue<int> q;
vector<bool> visited(n, false);
q.push(start); visited[start] = true;
while (!q.empty()) {
    int node = q.front(); q.pop();
    for (int nb : adj[node]) {
        if (!visited[nb]) { visited[nb] = true; q.push(nb); }
    }
}
```

### 5. DFS (Recursion / Stack)
```cpp
void dfs(int node, vector<bool>& vis) {
    vis[node] = true;
    for (int nb : adj[node])
        if (!vis[nb]) dfs(nb, vis);
}
```

### 6. Dynamic Programming — 1D
```cpp
vector<int> dp(n + 1, 0);
dp[0] = base_case;
for (int i = 1; i <= n; i++)
    dp[i] = /* recurrence */;
```

### 7. Dynamic Programming — 2D (e.g., LCS)
```cpp
vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
        dp[i][j] = (a[i-1] == b[j-1]) ? dp[i-1][j-1] + 1
                                       : max(dp[i-1][j], dp[i][j-1]);
```

### 8. Backtracking
```cpp
void solve(int idx, vector<int>& current) {
    if (base_case) { results.push_back(current); return; }
    for (each choice) {
        current.push_back(choice);
        solve(idx + 1, current);
        current.pop_back();  // undo
    }
}
```

### 9. Union-Find (Disjoint Set)
```cpp
vector<int> parent, rank;
int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }
void unite(int x, int y) {
    x = find(x); y = find(y);
    if (rank[x] < rank[y]) swap(x, y);
    parent[y] = x;
    if (rank[x] == rank[y]) rank[x]++;
}
```

### 10. Topological Sort (Kahn's BFS)
```cpp
vector<int> indegree(n, 0);
for (auto& [u, v] : edges) indegree[v]++;
queue<int> q;
for (int i = 0; i < n; i++) if (indegree[i] == 0) q.push(i);
vector<int> order;
while (!q.empty()) {
    int u = q.front(); q.pop(); order.push_back(u);
    for (int v : adj[u]) if (--indegree[v] == 0) q.push(v);
}
```

---

## Running Solutions

See `basics/7.c++` for the test runner pattern. Every solution in `basics/` should follow this structure:
1. Write your `Solution` class
2. Add a `main()` with labeled test cases
3. Compile: `g++ -std=c++17 -o sol file.c++ && ./sol`

---

## Resources

- [CP-Algorithms](https://cp-algorithms.com) — detailed algorithm explanations
- [USACO Guide](https://usaco.guide) — structured learning from easy to hard
- [NeetCode 150](https://neetcode.io/practice) — best curated problem list
- [Striver's A2Z Sheet](https://takeuforward.org/strivers-a2z-dsa-course) — 450+ problems with video
- [Visualgo](https://visualgo.net) — visual algorithm animations
