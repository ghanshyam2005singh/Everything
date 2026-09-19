# DSA/basics — LeetCode Problem Solutions

This folder stores individual LeetCode problem solutions. Each file is a self-contained `.c++` file with the solution class **and** a test runner in `main()` so you can compile and verify locally without the LeetCode UI.

---

## File Naming Convention

```
<problem-number>.c++        e.g.  7.c++   (LeetCode #7 Reverse Integer)
<problem-number>.c++              3838.c++ (LeetCode #3838)
```

---

## How to Write a Solution

Every file follows this exact structure:

```cpp
#include <bits/stdc++.h>
using namespace std;

// ── 1. Your solution class ──────────────────
class Solution {
public:
    int yourMethod(/* params */) {
        // your code
    }
};

// ── 2. Test runner ──────────────────────────
int main() {
    Solution sol;

    // Test case format:
    //   auto result = sol.method(input);
    //   bool pass   = (result == expected);
    //   cout << "Test N: " << (pass ? "PASS" : "FAIL") << "\n";

    struct Test { /* input */; /* expected */; };
    vector<Test> tests = {
        // { input, expected }
    };

    int passed = 0;
    for (int i = 0; i < (int)tests.size(); i++) {
        auto got = sol.yourMethod(tests[i]./* input */);
        bool ok  = (got == tests[i]./* expected */);
        cout << "Test " << i+1 << ": " << (ok ? "PASS" : "FAIL");
        if (!ok) cout << "  got=" << got << " expected=" << tests[i]./* expected */;
        cout << "\n";
        if (ok) passed++;
    }
    cout << passed << "/" << tests.size() << " tests passed\n";
    return passed == (int)tests.size() ? 0 : 1;
}
```

See `7.c++` for a working example.

---

## How to Compile and Run

```bash
# One-liner
g++ -std=c++17 -o sol 7.c++ && ./sol

# With warnings (recommended)
g++ -std=c++17 -Wall -Wextra -o sol 7.c++ && ./sol

# With debug info (for gdb)
g++ -std=c++17 -g -o sol 7.c++ && ./sol
```

The binary exits with code `0` if all tests pass, `1` if any fail — so you can chain it:
```bash
g++ -std=c++17 -o sol 7.c++ && ./sol && echo "All good!"
```

---

## Tips

- Always test edge cases: empty input, single element, negative numbers, overflow, duplicates.
- For integer problems, watch for `INT_MAX / INT_MIN` overflow — use `long long` or check before multiplying.
- Use `assert()` for quick sanity checks in development.
- The LeetCode judge uses C++17 by default — `-std=c++17` matches that.
