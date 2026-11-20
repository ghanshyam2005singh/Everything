class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0]<=ans.back()[1]){
                ans.back()[1]=max(ans.back()[1], intervals[i][1]);
            } else {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};

// Code explaination:

// Good. Your issue is not the algorithm anymore. It's understanding **how to work with `vector<vector<int>>` in C++**. Let's break it down from scratch.

// ---

// ## What is `vector<vector<int>>` ?

// Suppose:

// ```cpp
// vector<vector<int>> intervals = {
//     {1,3},
//     {2,6},
//     {8,10}
// };
// ```

// Think of it like a table:

// | index | value  |
// | ----- | ------ |
// | 0     | {1,3}  |
// | 1     | {2,6}  |
// | 2     | {8,10} |

// So:

// ```cpp
// intervals[0]
// ```

// gives

// ```cpp
// {1,3}
// ```

// and

// ```cpp
// intervals[0][0]
// ```

// gives

// ```cpp
// 1
// ```

// because:

// ```cpp
// {1,3}
//  ^
//  index 0
// ```

// Similarly:

// ```cpp
// intervals[0][1]
// ```

// gives

// ```cpp
// 3
// ```

// ---

// ## What does this do?

// ```cpp
// vector<vector<int>> ans;
// ```

// Creates an empty answer.

// Currently:

// ```cpp
// ans = {}
// ```

// ---

// ## What does this do?

// ```cpp
// ans.push_back(intervals[0]);
// ```

// Remember:

// ```cpp
// intervals[0] = {1,3}
// ```

// So:

// ```cpp
// ans.push_back({1,3});
// ```

// Now:

// ```cpp
// ans = {
//     {1,3}
// }
// ```

// Think:

// | index | value |
// | ----- | ----- |
// | 0     | {1,3} |

// ---

// ## What is `ans.back()`?

// `back()` means:

// > Give me the last element.

// Example:

// ```cpp
// ans = {
//     {1,6},
//     {8,10}
// };
// ```

// Then:

// ```cpp
// ans.back()
// ```

// returns:

// ```cpp
// {8,10}
// ```

// the last interval.

// ---

// ## What is `ans.back()[1]`?

// First:

// ```cpp
// ans.back()
// ```

// ↓

// ```cpp
// {8,10}
// ```

// Then:

// ```cpp
// ans.back()[1]
// ```

// ↓

// ```cpp
// 10
// ```

// because index 1 is second element.

// ---

// ## Understanding the if condition

// Suppose:

// ```cpp
// ans = {
//     {1,3}
// };
// ```

// Current interval:

// ```cpp
// {2,6}
// ```

// Check:

// ```cpp
// intervals[i][0] <= ans.back()[1]
// ```

// Substitute values:

// ```cpp
// 2 <= 3
// ```

// True.

// So overlap exists.

// ---

// ## Now this line

// ```cpp
// ans.back()[1] =
// max(ans.back()[1], intervals[i][1]);
// ```

// Let's substitute values.

// Current merged interval:

// ```cpp
// {1,3}
// ```

// Current new interval:

// ```cpp
// {2,6}
// ```

// So:

// ```cpp
// ans.back()[1]
// ```

// ↓

// ```cpp
// 3
// ```

// and

// ```cpp
// intervals[i][1]
// ```

// ↓

// ```cpp
// 6
// ```

// Thus:

// ```cpp
// ans.back()[1] = max(3,6);
// ```

// ↓

// ```cpp
// ans.back()[1] = 6;
// ```

// Now interval becomes:

// ```cpp
// {1,6}
// ```

// ---

// ## Visualizing memory

// Before:

// ```cpp
// ans = {
//     {1,3}
// }
// ```

// After:

// ```cpp
// ans.back()[1] = 6;
// ```

// Result:

// ```cpp
// ans = {
//     {1,6}
// }
// ```

// We directly modified the last interval.

// ---

// ## What happens in else?

// Suppose:

// ```cpp
// ans = {
//     {1,6}
// }
// ```

// Current interval:

// ```cpp
// {8,10}
// ```

// Check:

// ```cpp
// 8 <= 6
// ```

// False.

// No overlap.

// So:

// ```cpp
// ans.push_back(intervals[i]);
// ```

// means:

// ```cpp
// ans.push_back({8,10});
// ```

// Now:

// ```cpp
// ans = {
//     {1,6},
//     {8,10}
// }
// ```

// ---

// ## The most important thing to understand

// This:

// ```cpp
// ans.back()
// ```

// is exactly equivalent to:

// ```cpp
// ans[ans.size()-1]
// ```

// So these are same:

// ```cpp
// ans.back()[1]
// ```

// and

// ```cpp
// ans[ans.size()-1][1]
// ```

// We use `back()` because it is shorter and cleaner.

// ---

// ### Dry Run

// Input:

// ```cpp
// [[1,3],[2,6],[8,10]]
// ```

// Start:

// ```cpp
// ans = {{1,3}}
// ```

// Next interval:

// ```cpp
// {2,6}
// ```

// Overlap:

// ```cpp
// 2 <= 3
// ```

// Merge:

// ```cpp
// ans = {{1,6}}
// ```

// Next interval:

// ```cpp
// {8,10}
// ```

// Overlap?

// ```cpp
// 8 <= 6
// ```

// No.

// Push:

// ```cpp
// ans = {
//     {1,6},
//     {8,10}
// }
// ```

// Done.

// ---

// The bigger lesson here is that you should spend some time practicing:

// ```cpp
// vector<int>
// vector<vector<int>>
// push_back()
// back()
// ```

// because most of the difficulty you're hitting is not the algorithm itself—it's being comfortable manipulating nested vectors in C++. Once `vector<vector<int>>` feels natural, interval problems become much easier to code.
