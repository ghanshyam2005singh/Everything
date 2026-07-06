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

//More Vooting algo
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int candidate=0;
        for(int num: nums){
            if(candidate==0){
                candidate=num;
            }
            if(num==candidate){
                count++;
            } else{
                count--;
            }
        }
        return candidate;
    }
};

// Perfect. Before learning **Q229**, you should first understand **Moore's Voting Algorithm** through **Q169**, because Q229 is just an extension of it.

// ---

// # Step 1: LeetCode 169 - Majority Element

// Problem:

// ```cpp
// nums = [2,2,1,1,1,2,2]
// ```

// Find the element that appears **more than n/2 times**.

// Here:

// ```cpp
// n = 7

// n/2 = 3
// ```

// Frequency:

// ```cpp
// 2 -> 4 times
// 1 -> 3 times
// ```

// Answer:

// ```cpp
// 2
// ```

// ---

// # Brute Force

// Use hashmap:

// ```cpp
// unordered_map<int,int> freq;
// ```

// Count frequencies.

// Complexity:

// ```cpp
// O(n) time
// O(n) space
// ```

// Accepted.

// ---

// # Moore's Voting Idea

// Instead of counting everything, let's think differently.

// Suppose:

// ```cpp
// 2 2 1 1 1 2 2
// ```

// The majority element appears more than half the time.

// That means:

// > Even if every non-majority element "cancels" one majority element, the majority element will still survive.

// ---

// ## Example

// ```cpp
// 2 2 1 1 1 2 2
// ```

// Pair and cancel:

// ```cpp
// 2 1  -> cancel
// 2 1  -> cancel
// 1 2  -> cancel
// ```

// Remaining:

// ```cpp
// 2
// ```

// Majority survives.

// ---

// # How do we simulate cancellation?

// Keep:

// ```cpp
// candidate
// count
// ```

// Initially:

// ```cpp
// candidate = ?
// count = 0
// ```

// ---

// ## Rule 1

// If count becomes 0:

// ```cpp
// candidate = current number
// count = 1
// ```

// ---

// ## Rule 2

// If current number equals candidate:

// ```cpp
// count++
// ```

// ---

// ## Rule 3

// Otherwise:

// ```cpp
// count--
// ```

// because we cancel one occurrence.

// ---

// # Dry Run

// ```cpp
// nums = [2,2,1,1,1,2,2]
// ```

// ---

// ### First 2

// ```cpp
// count=0

// candidate=2
// count=1
// ```

// ---

// ### Second 2

// Same candidate:

// ```cpp
// count=2
// ```

// ---

// ### 1

// Different:

// ```cpp
// count=1
// ```

// ---

// ### 1

// Different:

// ```cpp
// count=0
// ```

// Everything cancelled.

// ---

// ### 1

// Count is zero.

// ```cpp
// candidate=1
// count=1
// ```

// ---

// ### 2

// Different.

// ```cpp
// count=0
// ```

// Cancelled.

// ---

// ### 2

// ```cpp
// candidate=2
// count=1
// ```

// Finished.

// Answer:

// ```cpp
// candidate=2
// ```

// Correct.

// ---

// # Code for Q169

// ```cpp
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {

//         int candidate = 0;
//         int count = 0;

//         for(int num : nums){

//             if(count == 0){
//                 candidate = num;
//             }

//             if(num == candidate){
//                 count++;
//             }
//             else{
//                 count--;
//             }
//         }

//         return candidate;
//     }
// };
// ```

// ---

// # Why does this work?

// Because the problem GUARANTEES:

// ```cpp
// majority element exists
// ```

// and appears:

// ```cpp
// > n/2 times
// ```

// No matter how many cancellations happen, it cannot completely disappear.

// ---

// # Now Let's Move To Q229

// Problem:

// Find all elements appearing:

// ```cpp
// > n/3 times
// ```

// ---

// # Most Important Observation

// Can there be 3 such elements?

// Suppose:

// ```cpp
// A appears > n/3
// B appears > n/3
// C appears > n/3
// ```

// Then:

// ```cpp
// A+B+C > n
// ```

// Impossible.

// ---

// Therefore:

// ```cpp
// At most 2 answers.
// ```

// This is the key.

// ---

// # Moore Voting Extension

// For Q169:

// ```cpp
// 1 candidate
// ```

// For Q229:

// ```cpp
// 2 candidates
// ```

// because at most 2 majority elements can exist.

// Keep:

// ```cpp
// candidate1
// candidate2

// count1
// count2
// ```

// ---

// # Example

// ```cpp
// nums = [3,2,3]
// ```

// Need elements > n/3

// ```cpp
// n=3

// n/3=1
// ```

// Answer:

// ```cpp
// 3
// ```

// ---

// # Rules

// For every number:

// ---

// ### Case 1

// Matches candidate1

// ```cpp
// count1++
// ```

// ---

// ### Case 2

// Matches candidate2

// ```cpp
// count2++
// ```

// ---

// ### Case 3

// count1 == 0

// ```cpp
// candidate1 = num
// count1 = 1
// ```

// ---

// ### Case 4

// count2 == 0

// ```cpp
// candidate2 = num
// count2 = 1
// ```

// ---

// ### Case 5

// Matches neither candidate

// ```cpp
// count1--
// count2--
// ```

// This is the cancellation step.

// ---

// # Dry Run

// ```cpp
// [1,2,3,1,2,1,2]
// ```

// ---

// 1:

// ```cpp
// c1=1
// count1=1
// ```

// ---

// 2:

// ```cpp
// c2=2
// count2=1
// ```

// ---

// 3:

// Neither.

// ```cpp
// count1--
// count2--

// 0
// 0
// ```

// Cancelled.

// ---

// 1:

// ```cpp
// c1=1
// count1=1
// ```

// ---

// 2:

// ```cpp
// c2=2
// count2=1
// ```

// ---

// 1:

// ```cpp
// count1=2
// ```

// ---

// 2:

// ```cpp
// count2=2
// ```

// Finish.

// Candidates:

// ```cpp
// 1
// 2
// ```

// ---

// # Important

// After Moore Voting:

// ```cpp
// candidate1
// candidate2
// ```

// are only POSSIBLE answers.

// Not guaranteed.

// So count frequencies again.

// ---

// # Verification Pass

// ```cpp
// count1=0;
// count2=0;
// ```

// Count actual occurrences.

// If:

// ```cpp
// count > n/3
// ```

// add to answer.

// ---

// # Full Logic Summary

// ### Q169

// ```text
// More than n/2
// ↓
// Only 1 majority element possible
// ↓
// Keep 1 candidate
// ```

// ### Q229

// ```text
// More than n/3
// ↓
// At most 2 majority elements possible
// ↓
// Keep 2 candidates
// ```

// This pattern generalizes:

// ```text
// More than n/k times
// ↓
// At most k-1 answers
// ↓
// Keep k-1 candidates
// ```

// This is the deep idea behind Moore's Voting Algorithm. Once Q169 clicks, Q229 becomes much easier because it's the exact same cancellation concept, just with two candidates instead of one.
