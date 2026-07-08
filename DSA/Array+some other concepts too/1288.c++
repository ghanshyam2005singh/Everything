// This question is similar to Q56
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
        [](vector<int> &a, vector<int>&b){
            if(a[0]==b[0])
            return a[1]>b[1];
            return a[0]<b[0];
        });
        int count=0;
        int maxEnd=0;
        for(auto &interval: intervals){
            if(interval [1]>maxEnd){
                count++;
                maxEnd=interval[1];
            }
        }
        return count;
    }
};

// Explaination of auto, & and that vector function in the above code:
// These are exactly the kinds of C++ syntax details that often make DSA problems feel harder than they really are. Let's break them down one by one.

// ---

// # 1. What is `&` ?

// In C++, `&` can mean a few things, but here:

// ```cpp
// vector<int>& nums
// ```

// it means **reference**.

// Without `&`:

// ```cpp
// void func(vector<int> nums)
// ```

// A copy of the entire vector is created.

// Example:

// ```cpp
// vector<int> a = {1,2,3};

// func(a);
// ```

// Memory:

// ```text
// a ----> [1,2,3]

// copy ----> [1,2,3]
// ```

// The whole vector gets copied.

// ---

// With `&`:

// ```cpp
// void func(vector<int>& nums)
// ```

// No copy is made.

// `nums` becomes another name for the same vector.

// Memory:

// ```text
// a ------+
//          |
// nums ----+
// ```

// Both refer to the same vector.

// ---

// ## Why use `&`?

// ### Faster

// Instead of copying:

// ```cpp
// 100000 elements
// ```

// you just pass a reference.

// ---

// ### Allows modification

// ```cpp
// void func(vector<int>& nums){
//     nums[0] = 100;
// }
// ```

// Original vector changes.

// ---

// # 2. What is `auto`?

// Suppose:

// ```cpp
// vector<int> nums;
// ```

// Normally:

// ```cpp
// vector<int>::iterator it = nums.begin();
// ```

// That's long.

// Instead:

// ```cpp
// auto it = nums.begin();
// ```

// Compiler automatically figures out the type.

// ---

// Example:

// ```cpp
// auto x = 5;
// ```

// Compiler thinks:

// ```cpp
// int x = 5;
// ```

// ---

// Example:

// ```cpp
// auto name = string("Ghanshyam");
// ```

// Compiler thinks:

// ```cpp
// string name = "Ghanshyam";
// ```

// ---

// ## Common use in DSA

// Instead of:

// ```cpp
// for(vector<int>& interval : intervals)
// ```

// people write:

// ```cpp
// for(auto& interval : intervals)
// ```

// Compiler understands:

// ```cpp
// interval is vector<int>&
// ```

// ---

// # 3. What is this `[]` ?

// This is called a **lambda function**.

// Think:

// ```cpp
// [](arguments){
//     code
// }
// ```

// means

// ```cpp
// a small function written inside another function
// ```

// ---

// # Why do we need it in sort?

// Normally:

// ```cpp
// sort(arr.begin(), arr.end());
// ```

// sorts ascending.

// Example:

// ```cpp
// 1 4 2 3
// ```

// becomes

// ```cpp
// 1 2 3 4
// ```

// ---

// But for intervals we want special sorting rules.

// So we tell sort:

// ```cpp
// sort(... , comparison_function)
// ```

// ---

// # This whole block

// ```cpp
// sort(intervals.begin(), intervals.end(),
// [](vector<int>& a, vector<int>& b) {

//     if(a[0] == b[0])
//         return a[1] > b[1];

//     return a[0] < b[0];
// });
// ```

// means:

// > When comparing two intervals `a` and `b`, use these rules.

// ---

// ## Example

// Suppose:

// ```cpp
// a = [1,5]
// b = [1,4]
// ```

// Check:

// ```cpp
// a[0] == b[0]
// ```

// Both start with 1.

// True.

// So execute:

// ```cpp
// return a[1] > b[1];
// ```

// Check:

// ```cpp
// 5 > 4
// ```

// True.

// Therefore:

// ```cpp
// [1,5]
// ```

// comes before

// ```cpp
// [1,4]
// ```

// ---

// ## Another example

// ```cpp
// a = [2,8]
// b = [1,4]
// ```

// Check:

// ```cpp
// a[0] == b[0]
// ```

// No.

// Execute:

// ```cpp
// return a[0] < b[0];
// ```

// Check:

// ```cpp
// 2 < 1
// ```

// False.

// Meaning:

// ```cpp
// [1,4]
// ```

// comes before

// ```cpp
// [2,8]
// ```

// ---

// # Final meaning of this sort

// ```cpp
// if starts differ
//     smaller start first

// if starts equal
//     larger end first
// ```

// Example:

// Before:

// ```cpp
// [1,4]
// [1,5]
// [2,3]
// ```

// After:

// ```cpp
// [1,5]
// [1,4]
// [2,3]
// ```

// ---

// # One more thing: Why do we need "larger end first"?

// Consider:

// ```cpp
// [1,5]
// [1,4]
// ```

// If we sort:

// ```cpp
// [1,4]
// [1,5]
// ```

// then when scanning, it becomes harder to detect that `[1,4]` is covered.

// By sorting:

// ```cpp
// [1,5]
// [1,4]
// ```

// the bigger interval appears first.

// Then:

// ```cpp
// maxEnd = 5

// current = [1,4]

// 4 <= 5
// ```

// Immediately we know it's covered.

// ---

// A useful rule while learning DSA:

// * `&` → avoid copying, pass by reference.
// * `auto` → let compiler figure out the type.
// * `[](...) {}` → lambda function (small temporary function).
// * `sort(..., lambda)` → custom sorting rule.
