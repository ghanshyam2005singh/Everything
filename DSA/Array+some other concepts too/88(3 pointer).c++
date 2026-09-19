// Noob Approach:
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>ans;
        for(int i=0; i<m; i++){
           ans.push_back(nums1[i]);
        }
        for(int i=0; i<n; i++){
            ans.push_back(nums2[i]);
        }
        sort(ans.begin(), ans.end());
        for(int i=0; i<ans.size(); i++){
            nums1[i]=ans[i];
        }
    }
};

//3 pointer approach (less space)
// Absolutely. This is one of the most useful array techniques you'll learn.

// ---

// # Problem

// ```cpp
// nums1 = [1,2,3,0,0,0]
// m = 3

// nums2 = [2,5,6]
// n = 3
// ```

// Need:

// ```cpp
// [1,2,2,3,5,6]
// ```

// ---

// # First thought

// You already did:

// ```cpp
// copy all elements
// sort
// put back
// ```

// Works.

// But interviewers ask:

// > Can you do it without extra space?

// ---

// # Key Observation

// `nums1` already has extra space.

// ```cpp
// [1,2,3,0,0,0]
// ```

// Those last 3 zeros are empty slots.

// Why create another array?

// Use that space itself.

// ---

// # Why start from the BACK?

// Suppose we start from front.

// ```cpp
// nums1 = [1,2,3,0,0,0]
// nums2 = [2,5,6]
// ```

// We want to place 1 first.

// But if we start writing from front, we may overwrite values we still need.

// That's dangerous.

// ---

// Instead start from back.

// ```cpp
// nums1 = [1,2,3,0,0,0]
//                  ^
// ```

// The back positions are empty.

// We can safely fill them.

// ---

// # Three pointers

// We'll keep:

// ```cpp
// i = m-1
// j = n-1
// k = m+n-1
// ```

// Meaning:

// ```cpp
// i = last valid element in nums1
// j = last element in nums2
// k = last position of answer
// ```

// For example:

// ```cpp
// nums1 = [1,2,3,0,0,0]
// nums2 = [2,5,6]
// ```

// Initially:

// ```cpp
// i = 2  -> nums1[i] = 3
// j = 2  -> nums2[j] = 6
// k = 5
// ```

// ---

// # Compare biggest elements

// ```cpp
// 3 vs 6
// ```

// Bigger is:

// ```cpp
// 6
// ```

// Put it at position `k`.

// ```cpp
// nums1[5] = 6
// ```

// Now:

// ```cpp
// nums1 = [1,2,3,0,0,6]
// ```

// Move:

// ```cpp
// j--
// k--
// ```

// Now:

// ```cpp
// i = 2
// j = 1
// k = 4
// ```

// ---

// # Next comparison

// ```cpp
// 3 vs 5
// ```

// Bigger:

// ```cpp
// 5
// ```

// Put:

// ```cpp
// nums1[4] = 5
// ```

// Array:

// ```cpp
// [1,2,3,0,5,6]
// ```

// Move:

// ```cpp
// j--
// k--
// ```

// Now:

// ```cpp
// i = 2
// j = 0
// k = 3
// ```

// ---

// # Next comparison

// ```cpp
// 3 vs 2
// ```

// Bigger:

// ```cpp
// 3
// ```

// Put:

// ```cpp
// nums1[3] = 3
// ```

// Array:

// ```cpp
// [1,2,3,3,5,6]
// ```

// Move:

// ```cpp
// i--
// k--
// ```

// Now:

// ```cpp
// i = 1
// j = 0
// k = 2
// ```

// ---

// # Next comparison

// ```cpp
// 2 vs 2
// ```

// Take either.

// Let's take nums2.

// ```cpp
// nums1[2] = 2
// ```

// Array:

// ```cpp
// [1,2,2,3,5,6]
// ```

// Move:

// ```cpp
// j--
// k--
// ```

// Now:

// ```cpp
// j = -1
// ```

// ---

// # Stop

// No elements left in nums2.

// Answer:

// ```cpp
// [1,2,2,3,5,6]
// ```

// Done.

// ---

// # Code Structure

// Step 1

// ```cpp
// int i = m - 1;
// int j = n - 1;
// int k = m + n - 1;
// ```

// ---

// Step 2

// While both arrays have elements:

// ```cpp
// while(i >= 0 && j >= 0)
// ```

// compare:

// ```cpp
// nums1[i]
// nums2[j]
// ```

// Put larger one at:

// ```cpp
// nums1[k]
// ```

// ---

// Step 3

// What if nums2 still has elements?

// Example:

// ```cpp
// nums1 = [4,5,6,0,0,0]
// nums2 = [1,2,3]
// ```

// Eventually:

// ```cpp
// nums1 = [4,5,6,4,5,6]
// ```

// and:

// ```cpp
// j still has values
// ```

// Need:

// ```cpp
// while(j >= 0)
// ```

// copy remaining nums2 elements.

// ---

// # Full Code

// ```cpp
// class Solution {
// public:
//     void merge(vector<int>& nums1, int m,
//                vector<int>& nums2, int n) {

//         int i = m - 1;
//         int j = n - 1;
//         int k = m + n - 1;

//         while(i >= 0 && j >= 0) {

//             if(nums1[i] > nums2[j]) {
//                 nums1[k] = nums1[i];
//                 i--;
//             } else {
//                 nums1[k] = nums2[j];
//                 j--;
//             }

//             k--;
//         }

//         while(j >= 0) {
//             nums1[k] = nums2[j];
//             j--;
//             k--;
//         }
//     }
// };
// ```

// ---

// ## Pattern to remember

// Whenever you see:

// * Two sorted arrays
// * Merge them
// * In-place
// * Extra space not allowed

// Think:

// ```text
// Start from the END
// Use 3 pointers
// Compare biggest elements
// Fill from back
// ```

// This same idea appears in many array and linked-list problems. Once you get comfortable with it, you'll start recognizing it immediately.


class Solution {
public:
    void merge(vector<int>& nums1, int m,
               vector<int>& nums2, int n) {

        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while(i >= 0 && j >= 0) {

            if(nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }

            k--;
        }

        while(j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};