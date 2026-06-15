/*
 * LeetCode #7 — Reverse Integer
 * https://leetcode.com/problems/reverse-integer/
 *
 * Given a signed 32-bit integer x, return x with its digits reversed.
 * If reversing causes overflow (outside [-2^31, 2^31 - 1]), return 0.
 *
 * Compile & run:
 *   g++ -std=c++17 -Wall -o sol 7.c++ && ./sol
 */

#include <bits/stdc++.h>
using namespace std;

// ── Solution ────────────────────────────────────────────────────────────────

class Solution {
public:
    int reverse(int x) {
        int reversed = 0;
        while (x != 0) {
            int digit = x % 10;
            x /= 10;
            // Check overflow BEFORE multiplying:
            // reversed * 10 + digit > INT_MAX  →  reversed > (INT_MAX - digit) / 10
            // reversed * 10 + digit < INT_MIN  →  reversed < (INT_MIN - digit) / 10
            if (reversed > INT_MAX / 10 || reversed < INT_MIN / 10) return 0;
            reversed = reversed * 10 + digit;
        }
        return reversed;
    }
};

// ── Test Runner ─────────────────────────────────────────────────────────────
//
// HOW TO ADD A TEST CASE:
//   Add a line to the `tests` vector:  { input, expected_output }
//
// HOW TO RUN:
//   g++ -std=c++17 -o sol 7.c++ && ./sol
//
// Exit code: 0 if all pass, 1 if any fail.

int main() {
    Solution sol;

    struct Test {
        int input;
        int expected;
    };

    vector<Test> tests = {
        // Basic cases
        { 123,        321        },
        { -123,      -321        },
        { 120,        21         },
        { 0,          0          },

        // Overflow cases — must return 0
        { INT_MAX,    0          },   // 2147483647 reversed = 7463847412 > INT_MAX
        { INT_MIN,    0          },   // -2147483648 reversed overflows
        { 1534236469, 0          },   // 9646324351 > INT_MAX

        // Edge cases
        { 1,          1          },
        { -1,        -1          },
        { 10,         1          },
        { -10,       -1          },
        { 100,        1          },
    };

    int passed = 0;
    for (int i = 0; i < (int)tests.size(); i++) {
        int got = sol.reverse(tests[i].input);
        bool ok = (got == tests[i].expected);
        cout << "Test " << (i + 1) << ": ";
        if (ok) {
            cout << "PASS";
        } else {
            cout << "FAIL  got=" << got << "  expected=" << tests[i].expected
                 << "  (input=" << tests[i].input << ")";
        }
        cout << "\n";
        if (ok) passed++;
    }

    cout << "\n" << passed << "/" << tests.size() << " tests passed\n";

    // Exit 0 if all pass (useful for scripting: && echo "All good!")
    return (passed == (int)tests.size()) ? 0 : 1;
}
