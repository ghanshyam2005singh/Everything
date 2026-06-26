// Right Triangle (Stars)

#include<bits/stdc++.h>
using namespace std;

void star (int n){
    for (int i=1; i<=n; i++){
        for(int j=0; j<i; j++){
            cout<<"*";
        }
        cout<<endl;
    }
}

int main(){
    int n=4;
    star(n);
    return 0;
}

// Explaination

// Excellent question. This is exactly the kind of thing that confuses people when learning patterns.

// Let's trace your code carefully.

// ```cpp
// for (int i=0; i<=n; i++)
// ```

// Suppose:

// ```cpp
// n = 4
// ```

// Then `i` values are:

// ```text
// i = 0
// i = 1
// i = 2
// i = 3
// i = 4
// ```

// That's **5 iterations**, not 4.

// ---

// Now look at the inner loop:

// ```cpp
// for(int j=0; j<i; j++)
// ```

// ### Row 0

// ```cpp
// i = 0
// ```

// Condition:

// ```cpp
// j < 0
// ```

// is immediately false.

// So nothing is printed.

// Output:

// ```text
// ```

// (just a blank line)

// ---

// ### Row 1

// ```cpp
// i = 1
// ```

// ```text
// *
// ```

// ---

// ### Row 2

// ```cpp
// i = 2
// ```

// ```text
// **
// ```

// ---

// ### Row 3

// ```cpp
// i = 3
// ```

// ```text
// ***
// ```

// ---

// ### Row 4

// ```cpp
// i = 4
// ```

// ```text
// ****
// ```

// ---

// Final output:

// ```text

// *
// **
// ***
// ****
// ```

// Notice the first blank line?

// That's because of:

// ```cpp
// i = 0
// ```

// ---

// ## Better Version

// Most people write:

// ```cpp
// for(int i=1; i<=n; i++)
// ```

// Then:

// ```text
// *
// **
// ***
// ****
// ```

// No extra blank line.

// ---

// ## Or Use Pure 0-Based Indexing

// This is also common:

// ```cpp
// for(int i=0; i<n; i++)
// {
//     for(int j=0; j<=i; j++)
//     {
//         cout<<"*";
//     }
//     cout<<endl;
// }
// ```

// Let's trace:

// | i | Stars |
// | - | ----- |
// | 0 | *     |
// | 1 | **    |
// | 2 | ***   |
// | 3 | ****  |

// Output:

// ```text
// *
// **
// ***
// ****
// ```

// ---

// ### Why `<=` Here?

// Because you're using:

// ```cpp
// j <= i
// ```

// not

// ```cpp
// j < i
// ```

// For example:

// ```cpp
// i = 3
// ```

// Then:

// ```text
// j = 0
// j = 1
// j = 2
// j = 3
// ```

// Total = 4 stars.

// ---

// ### Pattern Rule

// For patterns, always think:

// > "How many stars should this row print?"

// For row 4:

// ```text
// ****
// ```

// Need 4 stars.

// So either:

// ```cpp
// i = 4
// j < i
// ```

// or

// ```cpp
// i = 3
// j <= i
// ```

// Both give 4 stars.

// That's why these two versions are equivalent:

// ```cpp
// for(int i=1; i<=n; i++)
// {
//     for(int j=1; j<=i; j++)
// ```

// and

// ```cpp
// for(int i=0; i<n; i++)
// {
//     for(int j=0; j<=i; j++)
// ```

// Both produce:

// ```text
// *
// **
// ***
// ****
// ```

// As you do more pattern problems, you'll notice that the actual trick is not remembering `<` or `<=`, but figuring out:

// > Row `i` needs how many stars?

// Once you know that, writing the loop becomes much easier.
