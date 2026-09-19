/*
 * COMPLETE C++ STL REFERENCE
 * Compile: g++ -std=c++17 -o stl STL.c++ && ./stl
 *
 * Sections:
 *  1.  Basics           — I/O, macros, types
 *  2.  vector           — dynamic array
 *  3.  array            — fixed-size array
 *  4.  deque            — double-ended queue
 *  5.  list             — doubly linked list
 *  6.  stack            — LIFO
 *  7.  queue            — FIFO
 *  8.  priority_queue   — heap (max by default)
 *  9.  set / multiset   — sorted unique / sorted with dupes
 * 10.  unordered_set    — hash set
 * 11.  map / multimap   — sorted key-value / with dupes
 * 12.  unordered_map    — hash map
 * 13.  pair / tuple     — compound values
 * 14.  string           — string operations
 * 15.  STL Algorithms   — sort, binary_search, lower/upper_bound, etc.
 * 16.  Bit Manipulation — common tricks
 * 17.  Math utilities   — GCD, LCM, pow, log
 */

#include <bits/stdc++.h>
using namespace std;

// ─────────────────────────────────────────────
// SECTION 1: BASICS
// ─────────────────────────────────────────────

// Common macros (use in competitive programming)
#define ll   long long
#define ull  unsigned long long
#define ld   long double
#define pb   push_back
#define ppb  pop_back
#define pf   push_front
#define ppf  pop_front
#define mp   make_pair
#define mt   make_tuple
#define fi   first
#define se   second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x)  (int)(x).size()
#define rep(i,a,b) for(int i=(a);i<(b);i++)

// Limits
// INT_MAX  = 2147483647  (~2e9)
// INT_MIN  = -2147483648
// LLONG_MAX = 9223372036854775807 (~9e18)
// 1e9+7 is a common prime modulus

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll  LINF = 1e18;

// Fast I/O
void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

// ─────────────────────────────────────────────
// SECTION 2: VECTOR
// ─────────────────────────────────────────────

void demo_vector() {
    cout << "\n=== VECTOR ===\n";

    // Declare & initialize
    vector<int> v;                        // empty
    vector<int> v2(5, 0);                // [0,0,0,0,0]
    vector<int> v3 = {1, 2, 3, 4, 5};   // initializer list
    vector<int> v4(v3);                  // copy
    vector<vector<int>> grid(3, vector<int>(4, 0)); // 2D: 3 rows, 4 cols

    // Insert / remove
    v3.push_back(6);        // append: O(1) amortized
    v3.pop_back();          // remove last: O(1)
    v3.insert(v3.begin() + 1, 99); // insert at index 1: O(n)
    v3.erase(v3.begin() + 1);      // erase at index 1: O(n)
    v3.erase(v3.begin(), v3.begin() + 2); // erase range [0,2)

    // Access
    int a = v3[0];          // O(1), no bounds check
    int b = v3.at(0);       // O(1), throws out_of_range
    int front = v3.front(); // first element
    int back  = v3.back();  // last element
    int* ptr  = v3.data();  // raw pointer

    // Size / capacity
    cout << "size: " << v3.size() << "\n";
    cout << "capacity: " << v3.capacity() << "\n";
    v3.reserve(100);        // reserve capacity (no resize)
    v3.resize(3);           // resize to 3 (truncates)
    v3.shrink_to_fit();     // release excess capacity
    cout << "empty? " << v3.empty() << "\n";
    v3.clear();             // remove all elements, size=0

    // Iterate
    vector<int> nums = {10, 20, 30, 40};
    for (int x : nums) cout << x << " ";
    cout << "\n";
    for (auto it = nums.begin(); it != nums.end(); ++it) cout << *it << " ";
    cout << "\n";
    for (int i = 0; i < (int)nums.size(); i++) cout << nums[i] << " ";
    cout << "\n";

    // Sorting
    sort(nums.begin(), nums.end());             // ascending
    sort(nums.begin(), nums.end(), greater<int>()); // descending
    sort(nums.begin(), nums.end(), [](int a, int b){ return a > b; }); // lambda

    // Reverse
    reverse(nums.begin(), nums.end());

    // Find
    auto it = find(nums.begin(), nums.end(), 20);
    if (it != nums.end()) cout << "found at index " << (it - nums.begin()) << "\n";

    // Sum / min / max
    int total = accumulate(nums.begin(), nums.end(), 0);
    int mn = *min_element(nums.begin(), nums.end());
    int mx = *max_element(nums.begin(), nums.end());
    cout << "sum=" << total << " min=" << mn << " max=" << mx << "\n";

    // Unique (remove consecutive duplicates, must sort first)
    vector<int> dup = {1,1,2,3,3,4};
    sort(dup.begin(), dup.end());
    dup.erase(unique(dup.begin(), dup.end()), dup.end());
    // dup = {1,2,3,4}

    // Prefix sum
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> prefix(arr.size() + 1, 0);
    for (int i = 0; i < (int)arr.size(); i++)
        prefix[i+1] = prefix[i] + arr[i];
    // range sum [l, r] = prefix[r+1] - prefix[l]
}

// ─────────────────────────────────────────────
// SECTION 3: ARRAY (fixed size)
// ─────────────────────────────────────────────

void demo_array() {
    cout << "\n=== ARRAY ===\n";
    array<int, 5> a = {3, 1, 4, 1, 5};
    a[0] = 10;
    cout << "size: " << a.size() << "\n";
    sort(a.begin(), a.end());
    for (int x : a) cout << x << " ";
    cout << "\n";
}

// ─────────────────────────────────────────────
// SECTION 4: DEQUE
// ─────────────────────────────────────────────

void demo_deque() {
    cout << "\n=== DEQUE ===\n";
    deque<int> dq = {2, 3, 4};
    dq.push_front(1);   // [1,2,3,4]
    dq.push_back(5);    // [1,2,3,4,5]
    dq.pop_front();     // [2,3,4,5]
    dq.pop_back();      // [2,3,4]
    cout << "front=" << dq.front() << " back=" << dq.back() << "\n";
    cout << "size=" << dq.size() << "\n";
    // Random access: O(1)
    cout << "dq[1]=" << dq[1] << "\n";
}

// ─────────────────────────────────────────────
// SECTION 5: LIST (doubly linked list)
// ─────────────────────────────────────────────

void demo_list() {
    cout << "\n=== LIST ===\n";
    list<int> l = {1, 2, 3};
    l.push_back(4);
    l.push_front(0);
    l.pop_back();
    l.pop_front();
    auto it = l.begin();
    advance(it, 1);
    l.insert(it, 99);     // insert before position
    l.erase(it);          // erase at position
    l.sort();
    l.reverse();
    l.remove(99);         // remove all elements == 99
    l.unique();           // remove consecutive duplicates
    for (int x : l) cout << x << " ";
    cout << "\n";
}

// ─────────────────────────────────────────────
// SECTION 6: STACK (LIFO)
// ─────────────────────────────────────────────

void demo_stack() {
    cout << "\n=== STACK ===\n";
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout << "top: " << st.top() << "\n";   // 3
    st.pop();                               // remove top
    cout << "size: " << st.size() << "\n"; // 2
    cout << "empty: " << st.empty() << "\n";

    // Pattern: Monotonic stack (next greater element)
    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> nge(arr.size(), -1);
    stack<int> mono;
    for (int i = 0; i < (int)arr.size(); i++) {
        while (!mono.empty() && arr[mono.top()] < arr[i]) {
            nge[mono.top()] = arr[i];
            mono.pop();
        }
        mono.push(i);
    }
    cout << "Next Greater Elements: ";
    for (int x : nge) cout << x << " ";
    cout << "\n";
}

// ─────────────────────────────────────────────
// SECTION 7: QUEUE (FIFO)
// ─────────────────────────────────────────────

void demo_queue() {
    cout << "\n=== QUEUE ===\n";
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << "front: " << q.front() << "\n"; // 1
    cout << "back: "  << q.back()  << "\n"; // 3
    q.pop();                                 // remove front
    cout << "size: " << q.size() << "\n";   // 2
}

// ─────────────────────────────────────────────
// SECTION 8: PRIORITY QUEUE (heap)
// ─────────────────────────────────────────────

void demo_priority_queue() {
    cout << "\n=== PRIORITY QUEUE ===\n";

    // Max-heap (default)
    priority_queue<int> maxpq;
    maxpq.push(3);
    maxpq.push(1);
    maxpq.push(4);
    cout << "max: " << maxpq.top() << "\n"; // 4
    maxpq.pop();
    cout << "next max: " << maxpq.top() << "\n"; // 3

    // Min-heap
    priority_queue<int, vector<int>, greater<int>> minpq;
    minpq.push(3); minpq.push(1); minpq.push(4);
    cout << "min: " << minpq.top() << "\n"; // 1

    // Custom comparator (pairs: sort by second element descending)
    using P = pair<int,int>;
    auto cmp = [](P a, P b){ return a.second < b.second; };
    priority_queue<P, vector<P>, decltype(cmp)> pq(cmp);
    pq.push({1, 5});
    pq.push({2, 3});
    pq.push({3, 8});
    cout << "top pair: " << pq.top().first << "," << pq.top().second << "\n"; // 3,8

    // Build heap from vector: O(n)
    vector<int> v = {3,1,4,1,5,9};
    priority_queue<int> built(v.begin(), v.end());
    cout << "heap top: " << built.top() << "\n"; // 9
}

// ─────────────────────────────────────────────
// SECTION 9: SET & MULTISET
// ─────────────────────────────────────────────

void demo_set() {
    cout << "\n=== SET ===\n";

    set<int> s;
    s.insert(3);
    s.insert(1);
    s.insert(4);
    s.insert(1);  // duplicate — ignored
    // s = {1, 3, 4}  (always sorted)

    cout << "size: " << s.size() << "\n"; // 3

    // Search: O(log n)
    if (s.count(3)) cout << "3 is in set\n";
    auto it = s.find(4);
    if (it != s.end()) cout << "found: " << *it << "\n";

    // Erase
    s.erase(3);           // by value
    s.erase(s.begin());   // by iterator

    // Bounds
    s = {1, 3, 5, 7, 9};
    auto lb = s.lower_bound(4); // first >= 4: points to 5
    auto ub = s.upper_bound(5); // first >  5: points to 7
    cout << "lower_bound(4)=" << *lb << "\n";
    cout << "upper_bound(5)=" << *ub << "\n";

    // Iterate
    for (int x : s) cout << x << " ";
    cout << "\n";
    // Reverse iterate
    for (auto rit = s.rbegin(); rit != s.rend(); ++rit) cout << *rit << " ";
    cout << "\n";

    // Multiset (allows duplicates)
    multiset<int> ms;
    ms.insert(2); ms.insert(2); ms.insert(3);
    cout << "multiset count(2)=" << ms.count(2) << "\n"; // 2
    ms.erase(ms.find(2)); // erase only ONE occurrence
    cout << "after erase one 2, count(2)=" << ms.count(2) << "\n"; // 1
}

// ─────────────────────────────────────────────
// SECTION 10: UNORDERED_SET (hash set)
// ─────────────────────────────────────────────

void demo_unordered_set() {
    cout << "\n=== UNORDERED_SET ===\n";
    unordered_set<int> us;
    us.insert(5);
    us.insert(1);
    us.insert(3);
    cout << "contains 3? " << us.count(3) << "\n";  // 1
    us.erase(3);
    cout << "contains 3? " << us.count(3) << "\n";  // 0
    // Average O(1) insert/find/erase, worst O(n)
    // No ordering guarantee
    us.reserve(100);        // reserve buckets to reduce rehashing
}

// ─────────────────────────────────────────────
// SECTION 11: MAP & MULTIMAP
// ─────────────────────────────────────────────

void demo_map() {
    cout << "\n=== MAP ===\n";

    map<string, int> freq;
    freq["apple"] = 3;
    freq["banana"] = 1;
    freq["cherry"] = 2;
    freq["apple"]++;   // increment

    // Access / insert
    cout << "apple: " << freq["apple"] << "\n";      // 4 (creates if missing!)
    cout << "apple: " << freq.at("apple") << "\n";   // safe (throws if missing)

    // Check existence
    if (freq.count("banana")) cout << "banana exists\n";
    if (freq.find("fig") == freq.end()) cout << "fig not found\n";

    // Erase
    freq.erase("banana");

    // Iterate (keys are always sorted)
    for (auto& [key, val] : freq)
        cout << key << " -> " << val << "\n";

    // Bounds
    auto lb = freq.lower_bound("b"); // first key >= "b"
    auto ub = freq.upper_bound("c"); // first key >  "c"

    // Frequency counter pattern
    vector<int> arr = {1, 2, 2, 3, 1, 1};
    map<int, int> cnt;
    for (int x : arr) cnt[x]++;
    for (auto& [k, v] : cnt) cout << k << ":" << v << " ";
    cout << "\n";

    // Multimap
    multimap<int, string> mm;
    mm.insert({1, "one"});
    mm.insert({1, "uno"});
    mm.insert({2, "two"});
    auto range = mm.equal_range(1);
    for (auto it = range.first; it != range.second; ++it)
        cout << it->first << "->" << it->second << " ";
    cout << "\n";
}

// ─────────────────────────────────────────────
// SECTION 12: UNORDERED_MAP (hash map)
// ─────────────────────────────────────────────

void demo_unordered_map() {
    cout << "\n=== UNORDERED_MAP ===\n";
    unordered_map<string, int> um;
    um["a"] = 1;
    um["b"] = 2;
    um.insert({"c", 3});

    cout << "a=" << um["a"] << "\n";
    um.erase("b");
    cout << "size=" << um.size() << "\n";

    for (auto& [k, v] : um) cout << k << ":" << v << " ";
    cout << "\n";

    um.reserve(100);  // pre-allocate buckets
}

// ─────────────────────────────────────────────
// SECTION 13: PAIR & TUPLE
// ─────────────────────────────────────────────

void demo_pair_tuple() {
    cout << "\n=== PAIR & TUPLE ===\n";

    // Pair
    pair<int, string> p = {1, "hello"};
    cout << p.first << " " << p.second << "\n";
    auto p2 = make_pair(2, "world");
    if (p < p2) cout << "p < p2\n";  // lexicographic comparison

    // Sort vector of pairs (sorts by first, then second)
    vector<pair<int,int>> vp = {{3,1},{1,2},{2,3}};
    sort(vp.begin(), vp.end());
    for (auto& [a,b] : vp) cout << a << "," << b << " ";
    cout << "\n";

    // Sort by second element
    sort(vp.begin(), vp.end(), [](auto& a, auto& b){ return a.second < b.second; });

    // Tuple
    tuple<int, string, double> t = {1, "hi", 3.14};
    cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << "\n";
    auto [x, y, z] = t;  // structured binding (C++17)
    cout << x << " " << y << " " << z << "\n";
}

// ─────────────────────────────────────────────
// SECTION 14: STRING
// ─────────────────────────────────────────────

void demo_string() {
    cout << "\n=== STRING ===\n";

    string s = "hello world";
    cout << "length: " << s.length() << "\n"; // same as s.size()
    cout << "s[0]: " << s[0] << "\n";
    cout << "front: " << s.front() << "\n";
    cout << "back: " << s.back() << "\n";

    // Substring
    string sub = s.substr(6, 5); // start=6, len=5 → "world"
    cout << "substr: " << sub << "\n";

    // Find
    size_t pos = s.find("world");      // returns string::npos if not found
    if (pos != string::npos) cout << "found at " << pos << "\n";
    size_t last = s.rfind('l');        // find last occurrence

    // Replace
    s.replace(6, 5, "C++");            // replace "world" with "C++"
    cout << "after replace: " << s << "\n";

    // Erase
    s.erase(5, 4);                     // erase 4 chars from index 5

    // Append / insert
    s += "!";
    s.append(" bye");
    s.insert(0, ">> ");

    // Compare
    string a = "abc", b = "abd";
    if (a < b) cout << "a < b\n";
    if (a.compare(b) < 0) cout << "a < b (compare)\n";

    // Case conversion
    string lower = "HELLO";
    transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    cout << "lower: " << lower << "\n";
    transform(lower.begin(), lower.end(), lower.begin(), ::toupper);

    // Check character type
    cout << isdigit('5') << isalpha('a') << isalnum('z') << "\n";

    // Split by delimiter (no built-in, use stringstream)
    string csv = "one,two,three";
    stringstream ss(csv);
    string token;
    while (getline(ss, token, ',')) cout << token << " ";
    cout << "\n";

    // String to int / double
    string num = "42";
    int n = stoi(num);
    double d = stod("3.14");
    cout << n << " " << d << "\n";

    // Int to string
    string ns = to_string(123);
    cout << ns << "\n";

    // Sort string
    string sorted = "dcba";
    sort(sorted.begin(), sorted.end());
    cout << "sorted: " << sorted << "\n";

    // Reverse string
    string rev = "hello";
    reverse(rev.begin(), rev.end());
    cout << "reversed: " << rev << "\n";

    // Count character occurrences
    string text = "banana";
    int cnt = count(text.begin(), text.end(), 'a');
    cout << "count 'a': " << cnt << "\n";
}

// ─────────────────────────────────────────────
// SECTION 15: STL ALGORITHMS
// ─────────────────────────────────────────────

void demo_algorithms() {
    cout << "\n=== STL ALGORITHMS ===\n";

    vector<int> v = {5, 3, 1, 4, 2};

    // sort / stable_sort / partial_sort
    sort(v.begin(), v.end());                         // O(n log n)
    stable_sort(v.begin(), v.end(), greater<int>());  // stable, descending
    partial_sort(v.begin(), v.begin() + 3, v.end());  // smallest 3 sorted

    // binary_search (requires sorted)
    sort(v.begin(), v.end());
    bool found = binary_search(v.begin(), v.end(), 3); // O(log n)
    cout << "binary_search(3): " << found << "\n";

    // lower_bound / upper_bound (requires sorted)
    // lower_bound: first element >= val
    // upper_bound: first element >  val
    auto lo = lower_bound(v.begin(), v.end(), 3);
    auto hi = upper_bound(v.begin(), v.end(), 3);
    cout << "lower_bound(3) index: " << (lo - v.begin()) << "\n";
    cout << "upper_bound(3) index: " << (hi - v.begin()) << "\n";
    cout << "count of 3s: " << (hi - lo) << "\n";

    // nth_element — O(n) average, puts kth smallest at position k
    vector<int> v2 = {5, 3, 1, 4, 2};
    nth_element(v2.begin(), v2.begin() + 2, v2.end()); // v2[2] = 3rd smallest
    cout << "3rd smallest: " << v2[2] << "\n";

    // min_element / max_element / minmax_element
    auto [minit, maxit] = minmax_element(v.begin(), v.end());
    cout << "min=" << *minit << " max=" << *maxit << "\n";

    // count / count_if
    vector<int> v3 = {1, 2, 2, 3, 2};
    cout << "count(2): " << count(v3.begin(), v3.end(), 2) << "\n";
    cout << "count even: " << count_if(v3.begin(), v3.end(), [](int x){ return x % 2 == 0; }) << "\n";

    // find / find_if
    auto it = find_if(v3.begin(), v3.end(), [](int x){ return x > 2; });
    if (it != v3.end()) cout << "first > 2: " << *it << "\n";

    // accumulate (sum, product, etc.)
    int sum = accumulate(v.begin(), v.end(), 0);
    int product = accumulate(v.begin(), v.end(), 1, multiplies<int>());
    cout << "sum=" << sum << " product=" << product << "\n";

    // fill / fill_n / iota
    vector<int> filled(5);
    fill(filled.begin(), filled.end(), 7);           // [7,7,7,7,7]
    iota(filled.begin(), filled.end(), 1);           // [1,2,3,4,5]

    // copy / copy_if / copy_n
    vector<int> dst(5);
    copy(v.begin(), v.end(), dst.begin());

    // transform (apply function to each element)
    vector<int> doubled(v.size());
    transform(v.begin(), v.end(), doubled.begin(), [](int x){ return x * 2; });

    // replace / replace_if
    replace(v.begin(), v.end(), 3, 99);  // replace all 3 with 99

    // remove / remove_if (moves elements, returns new end)
    vector<int> rv = {1, 2, 3, 2, 4};
    auto new_end = remove(rv.begin(), rv.end(), 2);
    rv.erase(new_end, rv.end()); // {1, 3, 4}

    // unique (remove consecutive duplicates)
    vector<int> u = {1,1,2,3,3};
    u.erase(unique(u.begin(), u.end()), u.end()); // {1,2,3}

    // reverse
    reverse(v.begin(), v.end());

    // rotate (bring element at position k to front)
    rotate(v.begin(), v.begin() + 2, v.end());

    // shuffle
    vector<int> shuf = {1,2,3,4,5};
    auto rng = default_random_engine{};
    shuffle(shuf.begin(), shuf.end(), rng);

    // next_permutation / prev_permutation
    vector<int> perm = {1, 2, 3};
    do {
        // process permutation
    } while (next_permutation(perm.begin(), perm.end()));

    // merge (two sorted ranges into one sorted range)
    vector<int> a = {1,3,5}, b = {2,4,6}, merged(6);
    merge(a.begin(), a.end(), b.begin(), b.end(), merged.begin());

    // set operations (on sorted ranges)
    vector<int> s1 = {1,2,3,4}, s2 = {3,4,5,6}, res;
    set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), back_inserter(res)); // {3,4}
    res.clear();
    set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), back_inserter(res));        // {1,2,3,4,5,6}
    res.clear();
    set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), back_inserter(res));   // {1,2}

    // any_of / all_of / none_of
    bool any_neg = any_of(v.begin(), v.end(), [](int x){ return x < 0; });
    bool all_pos = all_of(v.begin(), v.end(), [](int x){ return x > 0; });
    cout << "any_neg=" << any_neg << " all_pos=" << all_pos << "\n";

    // adjacent_find
    vector<int> consec = {1,2,2,3};
    auto adj = adjacent_find(consec.begin(), consec.end());
    if (adj != consec.end()) cout << "first duplicate: " << *adj << "\n";
}

// ─────────────────────────────────────────────
// SECTION 16: BIT MANIPULATION
// ─────────────────────────────────────────────

void demo_bits() {
    cout << "\n=== BIT MANIPULATION ===\n";

    int n = 12;  // 1100 in binary
    int k = 2;

    // Set bit k
    int set_k = n | (1 << k);       // set bit 2 → 1110 = 14
    // Clear bit k
    int clr_k = n & ~(1 << k);      // clear bit 2 → 1000 = 8
    // Toggle bit k
    int tog_k = n ^ (1 << k);       // toggle bit 2 → 1000 = 8
    // Check bit k
    bool is_set = (n >> k) & 1;     // true if bit k is 1
    cout << "set=" << set_k << " clear=" << clr_k << " toggle=" << tog_k << " check=" << is_set << "\n";

    // Count set bits
    cout << "__builtin_popcount(12): " << __builtin_popcount(12) << "\n"; // 2
    cout << "__builtin_popcountll: "   << __builtin_popcountll(12LL) << "\n";

    // Count leading zeros / trailing zeros
    cout << "__builtin_clz(4): "  << __builtin_clz(4)  << "\n"; // leading zeros in int
    cout << "__builtin_ctz(12): " << __builtin_ctz(12) << "\n"; // trailing zeros = lowest set bit pos

    // Power of 2 check
    auto isPow2 = [](int x){ return x > 0 && (x & (x - 1)) == 0; };
    cout << "isPow2(8)=" << isPow2(8) << " isPow2(7)=" << isPow2(7) << "\n";

    // Lowest set bit
    int lsb = n & (-n);  // isolate lowest set bit
    cout << "lowest set bit of 12: " << lsb << "\n"; // 4

    // Turn off lowest set bit
    int off_lsb = n & (n - 1);
    cout << "turn off lsb of 12: " << off_lsb << "\n"; // 8

    // XOR tricks
    // a ^ a = 0
    // a ^ 0 = a
    // Find single non-duplicate in array where all others appear twice:
    vector<int> arr = {1, 2, 3, 2, 1};
    int single = 0;
    for (int x : arr) single ^= x;
    cout << "single element: " << single << "\n"; // 3

    // Swap without temp
    int a = 5, b = 7;
    a ^= b; b ^= a; a ^= b;
    cout << "a=" << a << " b=" << b << "\n";

    // Bitset
    bitset<8> bs(42);           // 00101010
    cout << "bitset: " << bs << "\n";
    bs.set(0);                  // set bit 0
    bs.reset(1);                // clear bit 1
    bs.flip(2);                 // toggle bit 2
    cout << "count: " << bs.count() << "\n";
    cout << "all: " << bs.all() << " any: " << bs.any() << " none: " << bs.none() << "\n";
}

// ─────────────────────────────────────────────
// SECTION 17: MATH UTILITIES
// ─────────────────────────────────────────────

void demo_math() {
    cout << "\n=== MATH ===\n";

    // GCD / LCM (C++17)
    cout << "gcd(12,8)=" << __gcd(12, 8) << "\n";   // 4  (also: gcd() in C++17)
    // LCM manually:
    auto lcm = [](long long a, long long b){ return a / __gcd(a, b) * b; };
    cout << "lcm(4,6)=" << lcm(4, 6) << "\n"; // 12

    // Power: O(log n)
    auto powmod = [](long long base, long long exp, long long mod) -> long long {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp & 1) result = result * base % mod;
            base = base * base % mod;
            exp >>= 1;
        }
        return result;
    };
    cout << "2^10 mod 1e9+7 = " << powmod(2, 10, 1e9+7) << "\n"; // 1024

    // Sieve of Eratosthenes — O(n log log n)
    auto sieve = [](int n) {
        vector<bool> is_prime(n + 1, true);
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i * i <= n; i++)
            if (is_prime[i])
                for (int j = i * i; j <= n; j += i)
                    is_prime[j] = false;
        return is_prime;
    };
    auto primes = sieve(30);
    cout << "primes up to 30: ";
    for (int i = 2; i <= 30; i++) if (primes[i]) cout << i << " ";
    cout << "\n";

    // Abs, ceil, floor, round
    cout << "abs(-5)=" << abs(-5) << "\n";
    cout << "ceil(3.2)=" << ceil(3.2) << "\n";
    cout << "floor(3.9)=" << floor(3.9) << "\n";
    cout << "round(3.5)=" << round(3.5) << "\n";

    // Sqrt, log
    cout << "sqrt(16)=" << sqrt(16) << "\n";
    cout << "log2(8)=" << log2(8) << "\n";
    cout << "log10(1000)=" << log10(1000) << "\n";
}

// ─────────────────────────────────────────────
// MAIN
// ─────────────────────────────────────────────

int main() {
    fastio();

    demo_vector();
    demo_array();
    demo_deque();
    demo_list();
    demo_stack();
    demo_queue();
    demo_priority_queue();
    demo_set();
    demo_unordered_set();
    demo_map();
    demo_unordered_map();
    demo_pair_tuple();
    demo_string();
    demo_algorithms();
    demo_bits();
    demo_math();

    cout << "\nAll sections done.\n";
    return 0;
}
