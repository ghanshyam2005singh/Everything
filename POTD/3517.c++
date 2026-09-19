class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int>freq(26,0);
        for(char c:s)
        freq[c-'a']++;
        string left="";
        string middle="";
        for(int i=0; i<26; i++){
            left.append(freq[i]/2, char('a'+i));
            if(freq[i]%2==1)
            middle=char('a'+i);
        }
        string right=left;
        reverse(right.begin(), right.end());
        return left+middle+right;
    }
};

// Explaination of code:

// We'll use

// ```text
// s = "babab"
// ```

// throughout.

// ---

// # Step 1

// ```cpp
// vector<int> freq(26, 0);
// ```

// ## What is vector?

// You've already seen

// ```cpp
// vector<int> nums;
// ```

// which creates an empty vector.

// But here,

// ```cpp
// vector<int> freq(26,0);
// ```

// means

// > Make a vector of size **26**
// > and fill every position with **0**.

// So it becomes

// | Index | Value |
// | ----- | ----- |
// | 0     | 0     |
// | 1     | 0     |
// | 2     | 0     |
// | 3     | 0     |
// | ...   | ...   |
// | 25    | 0     |

// Think of it like

// ```cpp
// int freq[26]={0};
// ```

// but vectors are safer.

// ---

// ## Why 26?

// Because there are

// ```
// 26 letters

// a b c d ... z
// ```

// Every letter gets one index.

// ```
// a -> 0
// b -> 1
// c -> 2
// ...
// z -> 25
// ```

// ---

// # Step 2

// ```cpp
// for(char c : s)
// ```

// You asked this before.

// This is called a **range-based loop**.

// Instead of

// ```cpp
// for(int i=0;i<s.size();i++)
// ```

// it directly gives every character.

// Example

// ```
// s="babab"
// ```

// Iteration

// ```
// c='b'

// c='a'

// c='b'

// c='a'

// c='b'
// ```

// No index.

// ---

// # Step 3

// ```cpp
// freq[c-'a']++;
// ```

// This is the line most beginners fear.

// Let's break it.

// ---

// Suppose

// ```
// c='a'
// ```

// Then

// ```
// 'a'-'a'
// ```

// becomes

// ```
// 97-97
// ```

// because internally

// ```
// 'a'=97
// 'b'=98
// 'c'=99
// ...
// 'z'=122
// ```

// ASCII values.

// So

// ```
// 'a'-'a'

// =97-97

// =0
// ```

// Therefore

// ```
// freq[0]++
// ```

// means

// ```
// Increase count of 'a'
// ```

// ---

// Now suppose

// ```
// c='b'
// ```

// Then

// ```
// 'b'-'a'

// 98-97

// =1
// ```

// So

// ```
// freq[1]++
// ```

// Increase count of b.

// ---

// Suppose

// ```
// c='d'
// ```

// ```
// 'd'-'a'

// 100-97

// =3
// ```

// So

// ```
// freq[3]++
// ```

// ---

// ### Entire example

// ```
// s="babab"
// ```

// Initially

// ```
// freq

// a 0

// b 0

// c 0

// d 0
// ```

// First character

// ```
// c='b'
// ```

// ```
// 'b'-'a'

// =1
// ```

// So

// ```
// freq[1]++
// ```

// Now

// ```
// a 0

// b 1
// ```

// ---

// Second character

// ```
// 'a'
// ```

// ```
// 'a'-'a'

// =0
// ```

// ```
// freq[0]++
// ```

// Now

// ```
// a 1

// b 1
// ```

// ---

// Third character

// ```
// 'b'
// ```

// ```
// freq[1]++
// ```

// Now

// ```
// a 1

// b 2
// ```

// ---

// Fourth

// ```
// a
// ```

// Now

// ```
// a2

// b2
// ```

// ---

// Fifth

// ```
// b
// ```

// Now

// ```
// a2

// b3
// ```

// Finished.

// So vector becomes

// ```
// Index

// 0 2

// 1 3

// 2 0

// 3 0

// ...

// 25 0
// ```

// ---

// # Step 4

// ```cpp
// string left="";
// ```

// Creates an empty string.

// Initially

// ```
// left=""
// ```

// ---

// # Step 5

// ```cpp
// string middle="";
// ```

// Again empty.

// ```
// middle=""
// ```

// ---

// # Step 6

// ```cpp
// for(int i=0;i<26;i++)
// ```

// Now we're checking

// ```
// a

// b

// c

// ...

// z
// ```

// one by one.

// ---

// # Step 7

// ```cpp
// left.append(freq[i]/2, char('a'+i));
// ```

// This line has TWO new things.

// Let's split them.

// ---

// ## Part 1

// ```
// char('a'+i)
// ```

// Suppose

// ```
// i=0
// ```

// ```
// 'a'+0

// ='a'
// ```

// Suppose

// ```
// i=1
// ```

// ```
// 'a'+1

// ='b'
// ```

// Suppose

// ```
// i=2
// ```

// ```
// 'a'+2

// ='c'
// ```

// Suppose

// ```
// i=25
// ```

// ```
// 'a'+25

// ='z'
// ```

// So

// ```
// char('a'+i)
// ```

// means

// > Convert index back into character.

// Exactly opposite of

// ```
// c-'a'
// ```

// Think of them as inverse operations:

// ```
// Character → Index
// 'a' -> 0
// 'b' -> 1
// ...
// ```

// uses

// ```cpp
// c - 'a'
// ```

// while

// ```
// Index → Character
// 0 -> 'a'
// 1 -> 'b'
// ...
// ```

// uses

// ```cpp
// char('a' + i)
// ```

// ---

// ## Part 2

// ```
// append(count,character)
// ```

// Suppose

// ```
// left=""
// ```

// Now

// ```cpp
// left.append(3,'a');
// ```

// Result

// ```
// aaa
// ```

// Another example

// ```cpp
// left.append(2,'c');
// ```

// Result

// ```
// cc
// ```

// ---

// Example

// Suppose

// ```
// freq[a]=2
// ```

// Then

// ```
// freq[i]/2

// =2/2

// =1
// ```

// So

// ```
// append(1,'a')
// ```

// Left becomes

// ```
// a
// ```

// Now

// ```
// freq[b]=3
// ```

// ```
// 3/2=1
// ```

// append

// ```
// b
// ```

// Now

// ```
// left

// ab
// ```

// ---

// # Step 8

// ```cpp
// if(freq[i]%2==1)
// ```

// Remember

// ```
// %

// means remainder
// ```

// ```
// 2%2=0

// 4%2=0

// 6%2=0
// ```

// Even.

// ```
// 3%2=1

// 5%2=1

// 7%2=1
// ```

// Odd.

// So this checks

// ```
// Does this letter occur odd times?
// ```

// ---

// # Step 9

// ```cpp
// middle=char('a'+i);
// ```

// If

// ```
// b occurs 3 times
// ```

// then

// ```
// middle='b'
// ```

// ---

// # Step 10

// ```cpp
// string right=left;
// ```

// Copy.

// Suppose

// ```
// left

// ab
// ```

// Now

// ```
// right

// ab
// ```

// ---

// # Step 11

// ```cpp
// reverse(right.begin(),right.end());
// ```

// Before

// ```
// ab
// ```

// After

// ```
// ba
// ```

// ---

// # Step 12

// ```cpp
// return left+middle+right;
// ```

// Suppose

// ```
// left

// ab
// ```

// middle

// ```
// b
// ```

// right

// ```
// ba
// ```

// Return

// ```
// ab

// +

// b

// +

// ba

// =

// abbba
// ```

// ---

// # The two most important conversions

// These two lines are used everywhere in competitive programming.

// ## Character → Index

// ```cpp
// int index = c - 'a';
// ```

// | Character | Index |
// | --------- | ----- |
// | 'a'       | 0     |
// | 'b'       | 1     |
// | 'c'       | 2     |
// | 'z'       | 25    |

// Used for frequency arrays.

// ---

// ## Index → Character

// ```cpp
// char ch = 'a' + index;
// ```

// | Index | Character |
// | ----- | --------- |
// | 0     | 'a'       |
// | 1     | 'b'       |
// | 2     | 'c'       |
// | 25    | 'z'       |

// Used when reconstructing strings.

// ---

// ## My suggestion for you

// From all our previous conversations, I've noticed that your biggest difficulty isn't algorithms—it's C++ syntax. You often understand *what* the algorithm should do but get stuck on expressions like `c - 'a'`, `char('a' + i)`, `append()`, references (`&`), lambdas, or range-based loops.

// I think the most helpful next step would be a dedicated **"C++ for DSA" series** where we cover every important syntax feature used in LeetCode, one at a time, with examples and small practice problems. Once those become familiar, you'll spend much less time decoding the language and much more time solving the actual problem.
