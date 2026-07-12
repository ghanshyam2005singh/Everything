# CP — Competitive Programming

Templates, techniques, and solutions for competitive programming contests (Codeforces, AtCoder, CSES, etc.).

---

## Folder Structure (as it grows)

```
CP/
├── README.md            ← you are here
├── template.c++         ← base template for every contest problem
├── codeforces/          ← CF problem solutions by round
├── atcoder/             ← AtCoder solutions
└── cses/                ← CSES Problem Set solutions
```

---

## Contest Template

Create `template.c++` and use it as the starting point for every problem:

```cpp
#include <bits/stdc++.h>
using namespace std;

#define ll   long long
#define ld   long double
#define pb   push_back
#define all(x) (x).begin(), (x).end()
#define sz(x)  (int)(x).size()
#define rep(i,a,b) for(int i=(a);i<(b);i++)

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll  LINF = 2e18;

void solve() {
    // your solution here
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;   // uncomment for multi-test-case problems
    while (t--) solve();
    return 0;
}
```

---

## Essential CP Techniques

### Two Pointers — O(n)
Best for: sorted arrays, pair sums, palindrome check.

### Prefix Sum — O(n) build, O(1) query
Best for: range sum queries, subarray sum problems.
```cpp
vector<ll> pre(n + 1, 0);
for (int i = 0; i < n; i++) pre[i+1] = pre[i] + a[i];
// sum [l, r] = pre[r+1] - pre[l]
```

### Binary Search on Answer — O(n log MAXVAL)
Best for: "minimum maximum" / "maximum minimum" problems.
```cpp
ll lo = 0, hi = LINF, ans = -1;
while (lo <= hi) {
    ll mid = lo + (hi - lo) / 2;
    if (feasible(mid)) { ans = mid; hi = mid - 1; }
    else lo = mid + 1;
}
```

### Segment Tree — O(log n) update & query
Best for: range min/max/sum with point updates.

### Fenwick Tree (BIT) — O(log n) update & prefix query
Best for: prefix sums with updates.
```cpp
vector<int> bit(n + 1, 0);
void update(int i, int delta) { for (; i <= n; i += i & -i) bit[i] += delta; }
int query(int i) { int s = 0; for (; i > 0; i -= i & -i) s += bit[i]; return s; }
// range [l, r] = query(r) - query(l - 1)
```

### Sparse Table — O(n log n) build, O(1) range min/max
Best for: static arrays, RMQ (Range Minimum Query).

### Dijkstra — O((V + E) log V)
Best for: shortest path, non-negative weights.
```cpp
vector<ll> dist(n, LLONG_MAX);
priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
dist[src] = 0; pq.push({0, src});
while (!pq.empty()) {
    auto [d, u] = pq.top(); pq.pop();
    if (d > dist[u]) continue;
    for (auto [v, w] : adj[u])
        if (dist[u] + w < dist[v]) { dist[v] = dist[u] + w; pq.push({dist[v], v}); }
}
```

### Union-Find — O(α(n)) ≈ O(1) per operation
Best for: connected components, Kruskal's MST, cycle detection.

### KMP / Z-Function — O(n + m) string matching
Best for: find pattern in text.

---

## Step-by-Step Learning Path

### Beginner (Codeforces Div. 2 A/B)
1. Master STL → `DSA/STL.c++`
2. Solve CSES Introductory Problems (10 problems)
3. Solve CF Div. 2 A problems → aim for consistent solve in < 10 min

### Intermediate (CF Div. 2 C/D)
1. Two pointers, sliding window, binary search on answer
2. BFS/DFS, basic graph problems
3. Greedy problems
4. Solve CSES Sorting & Searching section

### Advanced (CF Div. 1 / ICPC)
1. Segment trees, Fenwick trees
2. DP optimization (divide & conquer, convex hull trick)
3. Advanced graph: flows, SCC, LCA, centroid decomp
4. String algorithms: KMP, Z, suffix array

---

## Resources

- [Codeforces](https://codeforces.com) — main competitive programming platform
- [AtCoder](https://atcoder.jp) — high-quality problems, beginner-friendly
- [CSES Problem Set](https://cses.fi/problemset/) — 300 essential CP problems with editorial
- [CP-Algorithms](https://cp-algorithms.com) — in-depth algorithm explanations
- [KACTL](https://github.com/kth-competitive-programming/kactl) — KTH's contest notebook
- [Codeforces EDU section](https://codeforces.com/edu/courses) — segment trees, DSU, etc.
- [Competitive Programmer's Handbook](https://cses.fi/book/book.pdf) — free book by CSES author
