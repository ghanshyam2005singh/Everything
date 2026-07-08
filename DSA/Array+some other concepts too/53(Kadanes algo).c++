class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        for(int i=n/2; i<n; i++){
            if(nums[i]==nums[i+1]) return nums[i];
        }
        return 0;
    }
};

// **Kadane's Algorithm** is one of the most important DSA algorithms.

// It solves:

// > **Q53. Maximum Subarray**
// >
// > Find the contiguous subarray with the largest sum.

// Example:

// ```cpp
// nums = [-2,1,-3,4,-1,2,1,-5,4]
// ```

// Answer:

// ```cpp
// [4,-1,2,1]
// sum = 6
// ```

// ---

// # Brute Force Thinking

// Try every subarray.

// ```cpp
// [-2]
// [-2,1]
// [-2,1,-3]
// ...
// [4,-1,2,1]
// ...
// ```

// Total subarrays:

// ```cpp
// n*(n+1)/2
// ```

// Time:

// ```cpp
// O(n²)
// ```

// or

// ```cpp
// O(n³)
// ```

// depending on implementation.

// Too slow.

// ---

// # The Main Idea

// Suppose you're building a subarray.

// Current sum:

// ```cpp
// sum = -5
// ```

// Next element:

// ```cpp
// nums[i] = 10
// ```

// Should we keep `-5`?

// ```cpp
// -5 + 10 = 5
// ```

// or start fresh?

// ```cpp
// 10
// ```

// Obviously:

// ```cpp
// 10 > 5
// ```

// So throw away the negative sum and start again.

// This is Kadane's entire idea:

// > If the running sum becomes negative, it can only hurt future answers.

// ---

// # Example Step by Step

// ```cpp
// nums = [-2,1,-3,4,-1,2,1,-5,4]
// ```

// Maintain:

// ```cpp
// currentSum
// maxSum
// ```

// Initially:

// ```cpp
// currentSum = 0
// maxSum = -∞
// ```

// ---

// ### i = 0

// ```cpp
// -2
// ```

// Add:

// ```cpp
// currentSum = -2
// ```

// Update max:

// ```cpp
// maxSum = -2
// ```

// Negative?

// ```cpp
// yes
// ```

// Reset:

// ```cpp
// currentSum = 0
// ```

// ---

// ### i = 1

// ```cpp
// 1
// ```

// Add:

// ```cpp
// currentSum = 1
// ```

// Update:

// ```cpp
// maxSum = 1
// ```

// ---

// ### i = 2

// ```cpp
// -3
// ```

// Add:

// ```cpp
// currentSum = -2
// ```

// Negative?

// ```cpp
// yes
// ```

// Reset:

// ```cpp
// currentSum = 0
// ```

// ---

// ### i = 3

// ```cpp
// 4
// ```

// Add:

// ```cpp
// currentSum = 4
// ```

// Update:

// ```cpp
// maxSum = 4
// ```

// ---

// ### i = 4

// ```cpp
// -1
// ```

// ```cpp
// currentSum = 3
// maxSum = 4
// ```

// ---

// ### i = 5

// ```cpp
// 2
// ```

// ```cpp
// currentSum = 5
// maxSum = 5
// ```

// ---

// ### i = 6

// ```cpp
// 1
// ```

// ```cpp
// currentSum = 6
// maxSum = 6
// ```

// ---

// ### i = 7

// ```cpp
// -5
// ```

// ```cpp
// currentSum = 1
// maxSum = 6
// ```

// ---

// ### i = 8

// ```cpp
// 4
// ```

// ```cpp
// currentSum = 5
// maxSum = 6
// ```

// Done.

// Answer:

// ```cpp
// 6
// ```

// ---

// # Visual Intuition

// Imagine carrying a backpack.

// Positive numbers:

// ```cpp
// +5 +3 +2
// ```

// are profits.

// Negative numbers:

// ```cpp
// -10
// ```

// are losses.

// If your backpack total becomes negative:

// ```cpp
// currentSum < 0
// ```

// then carrying it forward only makes future sums worse.

// So you drop it and start a new backpack.

// ---

// # Code

// ```cpp
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int currentSum = 0;
//         int maxSum = nums[0];

//         for(int i = 0; i < nums.size(); i++) {
//             currentSum += nums[i];

//             maxSum = max(maxSum, currentSum);

//             if(currentSum < 0) {
//                 currentSum = 0;
//             }
//         }

//         return maxSum;
//     }
// };
// ```

// ---

// # Important Edge Case

// What if:

// ```cpp
// nums = [-5,-2,-8]
// ```

// There is no positive number.

// Answer should be:

// ```cpp
// -2
// ```

// (the largest element)

// That's why we initialize:

// ```cpp
// maxSum = nums[0];
// ```

// instead of:

// ```cpp
// maxSum = 0;
// ```

// Otherwise you'd incorrectly return `0`.

// ---

// # Another Version (More Elegant)

// Think:

// At each index,

// > Is it better to extend the previous subarray or start a new one?

// ```cpp
// currentSum = max(nums[i], currentSum + nums[i]);
// ```

// Code:

// ```cpp
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int currentSum = nums[0];
//         int maxSum = nums[0];

//         for(int i = 1; i < nums.size(); i++) {
//             currentSum = max(nums[i], currentSum + nums[i]);
//             maxSum = max(maxSum, currentSum);
//         }

//         return maxSum;
//     }
// };
// ```

// This is the dynamic programming form of Kadane's Algorithm.

// ---

// ### Interview takeaway

// When you see:

// * Maximum subarray sum
// * Largest contiguous sum
// * Best segment sum

// Think:

// **Kadane's Algorithm = O(n)**

// Core idea:

// ```text
// If the running sum becomes harmful (negative),
// discard it and start a new subarray.
// ```

// This single idea is what makes Q53 go from **O(n²)** to **O(n)**.
