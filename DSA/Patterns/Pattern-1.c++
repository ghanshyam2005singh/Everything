// Square of Stars

#include<bits/stdc++.h>
using namespace std;

void star (int n){
for(int i=0; i<n; i++){   //or for(int i=1; i<=n; i++){
    for(int j=0; j<n; j++){   // or  for(int j=1; j<=n; j++){
        cout<<"*";
    }
    cout<<endl;
}
}

int main () {
    int n=4;
    star(n);
    return 0;
}


// Explainations

// You're very close. There are several **syntax errors** and a few **logic errors** in your code.

// Let's go through them one by one.

// ---

// ## 1. Function Declaration

// You wrote:

// ```cpp
// void star{
// ```

// But a function must have parentheses:

// ```cpp
// void star() {
// ```

// Or if you want to pass `n`:

// ```cpp
// void star(int n) {
// ```

// ---

// ## 2. Variable `n` Not Available

// Inside the function you're using:

// ```cpp
// for(int i=1; i<n; i++)
// ```

// But `n` is declared in `main()`.

// Variables inside `main()` are not automatically available inside another function.

// Pass it as a parameter:

// ```cpp
// void star(int n)
// ```

// ---

// ## 3. Missing Parenthesis in Loop

// You wrote:

// ```cpp
// for(int i=1; i<n; i++{
// ```

// Should be:

// ```cpp
// for(int i=1; i<n; i++) {
// ```

// ---

// ## 4. Wrong Output Position

// You wrote:

// ```cpp
// cout << "*" << endl;
// ```

// `endl` moves to the next line immediately.

// So output becomes:

// ```text
// *
// *
// *
// *
// *
// *
// ```

// instead of:

// ```text
// ****
// ****
// ****
// ****
// ```

// Inside the inner loop:

// ```cpp
// cout << "*";
// ```

// After the inner loop finishes:

// ```cpp
// cout << endl;
// ```

// ---

// ## 5. Wrong Closing Brackets

// You wrote:

// ```cpp
// })
// };
// ```

// Should be:

// ```cpp
// }
// }
// ```

// ---

// ## 6. Function Not Called

// You wrote:

// ```cpp
// void();
// ```

// This doesn't call your function.

// Call it like:

// ```cpp
// star(n);
// ```

// ---

// ## Correct Code

// ```cpp
// #include<bits/stdc++.h>
// using namespace std;

// void star(int n)
// {
//     for(int i = 1; i <= n; i++)
//     {
//         for(int j = 1; j <= n; j++)
//         {
//             cout << "*";
//         }
//         cout << endl;
//     }
// }

// int main()
// {
//     int n = 4;

//     star(n);

//     return 0;
// }
// ```

// Output:

// ```text
// ****
// ****
// ****
// ****
// ```

// ---

// ### Small DSA Tip

// For pattern problems always remember:

// * Outer loop = Rows
// * Inner loop = Columns

// For a square:

// ```text
// ****
// ****
// ****
// ****
// ```

// Rows = 4

// Columns = 4

// So:

// ```cpp
// for(rows)
// {
//     for(columns)
//     {
//         print("*");
//     }
//     next line;
// }
// ```

// This "outer loop = rows, inner loop = columns" rule works for almost every beginner pattern question.

// This is actually one of the most important beginner DSA questions. You're thinking correctly.

// Let's understand **exactly what `i++` and `i <= n` mean**.

// Suppose:

// ```cpp
// n = 4;
// ```

// and loop:

// ```cpp
// for(int i = 1; i <= n; i++)
// ```

// ### Iteration by Iteration

// | Step | i Value | i <= 4 ? | Execute Loop? |
// | ---- | ------- | -------- | ------------- |
// | 1    | 1       | Yes      | ✅             |
// | 2    | 2       | Yes      | ✅             |
// | 3    | 3       | Yes      | ✅             |
// | 4    | 4       | Yes      | ✅             |
// | 5    | 5       | No       | ❌ Stop        |

// Notice something:

// When `i` becomes 4, the loop runs.

// Then `i++` makes it 5.

// Now the condition is checked again:

// ```cpp
// 5 <= 4
// ```

// which is false.

// So the loop stops.

// That's why it doesn't print 5 rows.

// ---

// ## Why Not `i < n`?

// If we write:

// ```cpp
// for(int i = 1; i < n; i++)
// ```

// with `n = 4`

// | i |
// | - |
// | 1 |
// | 2 |
// | 3 |

// Only 3 iterations happen.

// Because:

// ```cpp
// 4 < 4
// ```

// is false.

// So row 4 never executes.

// ---

// ## Why Not Start From 0?

// Actually, we can.

// This is also correct:

// ```cpp
// for(int i = 0; i < n; i++)
// ```

// Let's see:

// | i |
// | - |
// | 0 |
// | 1 |
// | 2 |
// | 3 |

// Total = 4 iterations.

// So output is still:

// ```text
// ****
// ****
// ****
// ****
// ```

// ---

// ## Which One Is Better?

// These two are equivalent:

// ```cpp
// for(int i = 1; i <= n; i++)
// ```

// and

// ```cpp
// for(int i = 0; i < n; i++)
// ```

// Both run exactly `n` times.

// For `n = 4`

// ```cpp
// 1 2 3 4
// ```

// = 4 iterations

// and

// ```cpp
// 0 1 2 3
// ```

// = 4 iterations

// ---

// ## What Do Professionals Use?

// Most DSA and competitive programming code uses:

// ```cpp
// for(int i = 0; i < n; i++)
// ```

// because arrays start at index 0.

// Example:

// ```cpp
// int arr[5];
// ```

// Indexes are:

// ```text
// 0 1 2 3 4
// ```

// not

// ```text
// 1 2 3 4 5
// ```

// So programmers naturally think in 0-based indexing.

// ---

// ## For Pattern Problems?

// Many beginners prefer:

// ```cpp
// for(int row = 1; row <= n; row++)
// ```

// because rows are easier to visualize as:

// ```text
// Row 1
// Row 2
// Row 3
// Row 4
// ```

// instead of:

// ```text
// Row 0
// Row 1
// Row 2
// Row 3
// ```

// So both are fine.

// ---

// ### Rule to Remember

// To run a loop exactly **n times**:

// ```cpp
// for(int i = 0; i < n; i++)
// ```

// or

// ```cpp
// for(int i = 1; i <= n; i++)
// ```

// Both execute exactly **n times**.

// Most DSA code uses the first version because it matches array indexing. Pattern questions often use the second version because it's easier to think in terms of rows and columns.
