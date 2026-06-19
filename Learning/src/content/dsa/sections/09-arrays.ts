import type { DSASection } from '@/types/dsa';

export const arraysSection: DSASection = {
  id: 'arrays',
  slug: 'arrays',
  title: 'Solve Problems on Arrays',
  description: 'Master array manipulation from easy to hard — sliding window, hashing, sorting tricks, matrix problems, and divide-and-conquer counting.',
  icon: '[ ]',
  color: 'from-blue-400 to-blue-600',
  subsections: [
    {
      id: 'easy-array-problems',
      title: 'Easy Array Problems',
      topics: [
        {
          id: 'largest-element',
          slug: 'largest-element',
          title: 'Find Largest Element in Array',
          type: 'problem',
          difficulty: 'easy',
          pattern: 'Linear Scan',
          conceptsRequired: ['arrays', 'linear search'],
          approaches: [
            {
              name: 'Single Pass Linear Scan',
              intuition: 'Keep a running maximum. For each element, if it is greater than the current max, update max.',
              steps: [
                'Initialize max = arr[0].',
                'Iterate from index 1 to n-1.',
                'If arr[i] > max, set max = arr[i].',
                'Return max after the loop.',
              ],
              complexity: { time: 'O(N)', space: 'O(1)' },
              code: `int largestElement(vector<int>& arr) {
    int maxVal = arr[0];
    for (int i = 1; i < arr.size(); i++)
        if (arr[i] > maxVal) maxVal = arr[i];
    return maxVal;
}`,
            },
          ],
          hints: [
            'You do not need to sort; a single pass is enough.',
            'Initialize max with the first element, not 0, to handle all-negative arrays.',
            'STL: *max_element(arr.begin(), arr.end()) does the same in one line.',
          ],
          solution: `int largestElement(vector<int>& arr) {
    int maxVal = arr[0];
    for (int x : arr) maxVal = max(maxVal, x);
    return maxVal;
}`,
        },
        {
          id: 'second-largest',
          slug: 'second-largest',
          title: 'Find Second Largest Element (Without Sorting)',
          type: 'problem',
          difficulty: 'easy',
          pattern: 'Linear Scan',
          conceptsRequired: ['arrays'],
          approaches: [
            {
              name: 'Two-Variable Tracking',
              intuition: 'Maintain the top-two distinct values in a single pass. When a new element beats largest, the old largest becomes second largest.',
              steps: [
                'Initialize largest = INT_MIN, secondLargest = INT_MIN.',
                'For each element x in the array:',
                '  If x > largest: set secondLargest = largest, then largest = x.',
                '  Else if x > secondLargest AND x != largest: set secondLargest = x.',
                'Return secondLargest (-1 if all elements are equal).',
              ],
              complexity: { time: 'O(N)', space: 'O(1)' },
              code: `int secondLargest(vector<int>& arr) {
    int first = INT_MIN, second = INT_MIN;
    for (int x : arr) {
        if (x > first) { second = first; first = x; }
        else if (x > second && x != first) second = x;
    }
    return second == INT_MIN ? -1 : second;
}`,
            },
          ],
          hints: [
            'Track two variables: largest and second largest.',
            'Be careful with duplicate values — second largest must be strictly different from largest.',
            'Use INT_MIN as sentinel so any real value overwrites it.',
          ],
          solution: `int secondLargest(vector<int>& arr) {
    int first = INT_MIN, second = INT_MIN;
    for (int x : arr) {
        if (x > first) { second = first; first = x; }
        else if (x > second && x != first) second = x;
    }
    return second == INT_MIN ? -1 : second;
}`,
        },
        {
          id: 'array-sorted-check',
          slug: 'array-sorted-check',
          title: 'Check if Array is Sorted',
          type: 'problem',
          difficulty: 'easy',
          pattern: 'Linear Scan',
          conceptsRequired: ['arrays'],
          approaches: [
            {
              name: 'Adjacent Pair Check',
              intuition: 'An array is sorted in non-decreasing order iff every adjacent pair satisfies arr[i] <= arr[i+1].',
              steps: [
                'Loop from i = 0 to n-2.',
                'If arr[i] > arr[i+1], return false.',
                'If loop completes, return true.',
              ],
              complexity: { time: 'O(N)', space: 'O(1)' },
              code: `bool isSorted(vector<int>& arr) {
    for (int i = 0; i + 1 < arr.size(); i++)
        if (arr[i] > arr[i + 1]) return false;
    return true;
}`,
            },
          ],
          hints: [
            'Compare each element with the next one.',
            'A single violation disproves sorted order — short-circuit immediately.',
            'An array of size 0 or 1 is trivially sorted.',
          ],
          solution: `bool isSorted(vector<int>& arr) {
    for (int i = 0; i + 1 < (int)arr.size(); i++)
        if (arr[i] > arr[i+1]) return false;
    return true;
}`,
        },
        {
          id: 'remove-duplicates-sorted',
          slug: 'remove-duplicates-sorted',
          title: 'Remove Duplicates from Sorted Array',
          type: 'problem',
          difficulty: 'easy',
          pattern: 'Two Pointers',
          conceptsRequired: ['arrays', 'two pointers'],
          leetcodeUrl: 'https://leetcode.com/problems/remove-duplicates-from-sorted-array/',
          approaches: [
            {
              name: 'Two-Pointer In-Place',
              intuition: 'Use a slow pointer i that marks the boundary of the unique section. The fast pointer j scans ahead. Whenever j finds a new value, copy it to ++i.',
              steps: [
                'If array is empty, return 0.',
                'Set i = 0 (points to last written unique element).',
                'Loop j from 1 to n-1.',
                '  If arr[j] != arr[i]: increment i, set arr[i] = arr[j].',
                'Return i + 1.',
              ],
              complexity: { time: 'O(N)', space: 'O(1)' },
              code: `int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;
    int i = 0;
    for (int j = 1; j < nums.size(); j++)
        if (nums[j] != nums[i]) nums[++i] = nums[j];
    return i + 1;
}`,
            },
          ],
          hints: [
            'Because the array is sorted, duplicates are always adjacent.',
            'Use two pointers: slow for the write position, fast for reading.',
            'You modify the array in-place; the return value is the new length.',
          ],
          solution: `int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;
    int i = 0;
    for (int j = 1; j < (int)nums.size(); j++)
        if (nums[j] != nums[i]) nums[++i] = nums[j];
    return i + 1;
}`,
        },
        {
          id: 'left-rotate-by-one',
          slug: 'left-rotate-by-one',
          title: 'Left Rotate Array by One',
          type: 'problem',
          difficulty: 'easy',
          pattern: 'Array Manipulation',
          conceptsRequired: ['arrays'],
          approaches: [
            {
              name: 'Save First Element and Shift',
              intuition: 'Store the first element, shift all others one position left, then place the stored value at the end.',
              steps: [
                'Store temp = arr[0].',
                'Loop i from 0 to n-2: arr[i] = arr[i+1].',
                'Set arr[n-1] = temp.',
              ],
              complexity: { time: 'O(N)', space: 'O(1)' },
              code: `void leftRotateByOne(vector<int>& arr) {
    int n = arr.size();
    int temp = arr[0];
    for (int i = 0; i < n - 1; i++) arr[i] = arr[i + 1];
    arr[n - 1] = temp;
}`,
            },
          ],
          hints: [
            'Save the first element before overwriting it.',
            'Shift every element one step to the left.',
            'Place the saved element at the last index.',
          ],
          solution: `void leftRotateByOne(vector<int>& arr) {
    int n = arr.size(), temp = arr[0];
    for (int i = 0; i < n - 1; i++) arr[i] = arr[i + 1];
    arr[n - 1] = temp;
}`,
        },
        {
          id: 'left-rotate-k-places',
          slug: 'left-rotate-k-places',
          title: 'Left Rotate Array by K Places',
          type: 'problem',
          difficulty: 'easy',
          pattern: 'Reversal Algorithm',
          conceptsRequired: ['arrays', 'reversal trick'],
          leetcodeUrl: 'https://leetcode.com/problems/rotate-array/',
          approaches: [
            {
              name: 'Three Reversals',
              intuition: 'Reversing the first k elements, then the remaining n-k elements, then the whole array produces a left rotation by k. This avoids extra space.',
              steps: [
                'Normalize k = k % n.',
                'Reverse arr[0..k-1].',
                'Reverse arr[k..n-1].',
                'Reverse the entire array arr[0..n-1].',
              ],
              complexity: { time: 'O(N)', space: 'O(1)' },
              code: `void leftRotateK(vector<int>& arr, int k) {
    int n = arr.size();
    k %= n;
    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.end());
    reverse(arr.begin(), arr.end());
}`,
            },
            {
              name: 'Extra Array Copy',
              intuition: 'Copy the first k elements to a temporary array, shift left by k, then append the saved elements. Simple but uses O(k) space.',
              steps: [
                'Copy arr[0..k-1] into temp.',
                'Shift arr[k..n-1] to arr[0..n-k-1].',
                'Copy temp back to arr[n-k..n-1].',
              ],
              complexity: { time: 'O(N)', space: 'O(K)' },
              code: `void leftRotateK(vector<int>& arr, int k) {
    int n = arr.size(); k %= n;
    vector<int> temp(arr.begin(), arr.begin() + k);
    for (int i = k; i < n; i++) arr[i - k] = arr[i];
    for (int i = 0; i < k; i++) arr[n - k + i] = temp[i];
}`,
            },
          ],
          hints: [
            'Always reduce k modulo n to handle k >= n.',
            'The reversal trick (reverse prefix, suffix, whole) is the O(1) space classic.',
            'Left rotation by k is equivalent to right rotation by n-k.',
          ],
          solution: `void leftRotateK(vector<int>& arr, int k) {
    int n = arr.size(); k %= n;
    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.end());
    reverse(arr.begin(), arr.end());
}`,
        },
        {
          id: 'move-zeros-end',
          slug: 'move-zeros-end',
          title: 'Move All Zeros to End',
          type: 'problem',
          difficulty: 'easy',
          pattern: 'Two Pointers',
          conceptsRequired: ['arrays', 'two pointers'],
          leetcodeUrl: 'https://leetcode.com/problems/move-zeroes/',
          approaches: [
            {
              name: 'Two-Pointer Swap',
              intuition: 'Maintain a pointer j that tracks the next position to place a non-zero element. Swap arr[i] and arr[j] whenever arr[i] is non-zero.',
              steps: [
                'Initialize j = 0.',
                'Loop i from 0 to n-1.',
                '  If arr[i] != 0: swap(arr[i], arr[j]); j++.',
                'All zeros are naturally pushed to the end.',
              ],
              complexity: { time: 'O(N)', space: 'O(1)' },
              code: `void moveZeroes(vector<int>& nums) {
    int j = 0;
    for (int i = 0; i < nums.size(); i++)
        if (nums[i] != 0) swap(nums[i], nums[j++]);
}`,
            },
          ],
          hints: [
            'Think of keeping a write pointer that only advances on non-zero elements.',
            'Swapping preserves relative order of non-zero elements.',
            'This runs in O(N) with O(1) space — no extra array needed.',
          ],
          solution: `void moveZeroes(vector<int>& nums) {
    int j = 0;
    for (int i = 0; i < (int)nums.size(); i++)
        if (nums[i]) swap(nums[i], nums[j++]);
}`,
        },
        {
          id: 'linear-search',
          slug: 'linear-search',
          title: 'Linear Search',
          type: 'problem',
          difficulty: 'easy',
          pattern: 'Linear Scan',
          conceptsRequired: ['arrays'],
          approaches: [
            {
              name: 'Sequential Search',
              intuition: 'Scan each element from left to right. The first match returns its index; if no match, return -1.',
              steps: [
                'Loop i from 0 to n-1.',
                'If arr[i] == target, return i.',
                'After loop, return -1.',
              ],
              complexity: { time: 'O(N)', space: 'O(1)' },
              code: `int linearSearch(vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++)
        if (arr[i] == target) return i;
    return -1;
}`,
            },
          ],
          hints: [
            'No assumptions on the array order are needed.',
            'Return early as soon as the target is found.',
            'Worst case is O(N) when the element is at the end or absent.',
          ],
          solution: `int linearSearch(vector<int>& arr, int target) {
    for (int i = 0; i < (int)arr.size(); i++)
        if (arr[i] == target) return i;
    return -1;
}`,
        },
        {
          id: 'union-sorted-arrays',
          slug: 'union-sorted-arrays',
          title: 'Union of Two Sorted Arrays',
          type: 'problem',
          difficulty: 'easy',
          pattern: 'Two Pointers / Merge',
          conceptsRequired: ['arrays', 'sorting', 'two pointers'],
          approaches: [
            {
              name: 'Two-Pointer Merge',
              intuition: 'Like merge in merge sort but skip duplicates. Compare front elements of both arrays; add the smaller (if not a duplicate of the last added) and advance that pointer.',
              steps: [
                'i = 0, j = 0, result = [].',
                'While i < m and j < n:',
                '  Compare arr1[i] and arr2[j]. Add the smaller if not duplicate of last added.',
                '  Advance the corresponding pointer.',
                'Drain remaining elements from either array, skipping duplicates.',
              ],
              complexity: { time: 'O(M+N)', space: 'O(M+N)' },
              code: `vector<int> unionSorted(vector<int>& a, vector<int>& b) {
    vector<int> res;
    int i = 0, j = 0;
    auto add = [&](int x){ if (res.empty() || res.back() != x) res.push_back(x); };
    while (i < a.size() && j < b.size()) {
        if (a[i] <= b[j]) add(a[i++]);
        else add(b[j++]);
    }
    while (i < a.size()) add(a[i++]);
    while (j < b.size()) add(b[j++]);
    return res;
}`,
            },
          ],
          hints: [
            'Both arrays are already sorted — use the two-pointer merge technique.',
            'Skip duplicates by comparing each candidate with the last element added to result.',
            'Remember to drain whichever array still has remaining elements after the main loop.',
          ],
          solution: `vector<int> unionSorted(vector<int>& a, vector<int>& b) {
    vector<int> res; int i = 0, j = 0;
    auto add = [&](int x){ if (res.empty() || res.back() != x) res.push_back(x); };
    while (i < (int)a.size() && j < (int)b.size())
        a[i] <= b[j] ? add(a[i++]) : add(b[j++]);
    while (i < (int)a.size()) add(a[i++]);
    while (j < (int)b.size()) add(b[j++]);
    return res;
}`,
        },
        {
          id: 'find-missing-number',
          slug: 'find-missing-number',
          title: 'Find Missing Number in 1..N',
          type: 'problem',
          difficulty: 'easy',
          pattern: 'Math / XOR',
          conceptsRequired: ['arrays', 'math', 'XOR'],
          leetcodeUrl: 'https://leetcode.com/problems/missing-number/',
          approaches: [
            {
              name: 'Summation Formula',
              intuition: 'Sum of 1..N is N*(N+1)/2. Subtract the actual array sum to get the missing number.',
              steps: [
                'Compute expected = n*(n+1)/2.',
                'Compute actual = sum of all array elements.',
                'Return expected - actual.',
              ],
              complexity: { time: 'O(N)', space: 'O(1)' },
              code: `int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int expected = n * (n + 1) / 2;
    int actual = 0;
    for (int x : nums) actual += x;
    return expected - actual;
}`,
            },
            {
              name: 'XOR Trick',
              intuition: 'XOR all indices 0..N with all array values. Each number that appears in both cancels out, leaving the missing number.',
              steps: [
                'xorAll = 0.',
                'For i from 0 to n: xorAll ^= i.',
                'For each x in nums: xorAll ^= x.',
                'Return xorAll.',
              ],
              complexity: { time: 'O(N)', space: 'O(1)' },
              code: `int missingNumber(vector<int>& nums) {
    int xorAll = 0, n = nums.size();
    for (int i = 0; i <= n; i++) xorAll ^= i;
    for (int x : nums) xorAll ^= x;
    return xorAll;
}`,
            },
          ],
          hints: [
            'The expected sum of 1..N is N*(N+1)/2; subtract the actual sum.',
            'Alternatively, XOR all values from 0 to N with all array elements.',
            'The summation approach can overflow for large N; use long long or prefer XOR.',
          ],
          solution: `int missingNumber(vector<int>& nums) {
    int n = nums.size(), xorAll = 0;
    for (int i = 0; i <= n; i++) xorAll ^= i;
    for (int x : nums) xorAll ^= x;
    return xorAll;
}`,
        },
        {
          id: 'max-consecutive-ones',
          slug: 'max-consecutive-ones',
          title: 'Maximum Consecutive Ones',
          type: 'problem',
          difficulty: 'easy',
          pattern: 'Linear Scan / Counting',
          conceptsRequired: ['arrays'],
          leetcodeUrl: 'https://leetcode.com/problems/max-consecutive-ones/',
          approaches: [
            {
              name: 'Running Counter',
              intuition: 'Count consecutive 1s with a running variable. Reset to 0 on seeing a 0. Track the global maximum.',
              steps: [
                'Initialize count = 0, maxCount = 0.',
                'For each element x:',
                '  If x == 1: count++, update maxCount = max(maxCount, count).',
                '  Else: count = 0.',
                'Return maxCount.',
              ],
              complexity: { time: 'O(N)', space: 'O(1)' },
              code: `int findMaxConsecutiveOnes(vector<int>& nums) {
    int count = 0, maxCount = 0;
    for (int x : nums) {
        if (x == 1) maxCount = max(maxCount, ++count);
        else count = 0;
    }
    return maxCount;
}`,
            },
          ],
          hints: [
            'Reset your counter every time you see a 0.',
            'Update the global max before or after incrementing.',
            'Edge case: all zeros → answer is 0.',
          ],
          solution: `int findMaxConsecutiveOnes(vector<int>& nums) {
    int count = 0, res = 0;
    for (int x : nums) res = max(res, x ? ++count : (count = 0));
    return res;
}`,
        },
        {
          id: 'single-number',
          slug: 'single-number',
          title: 'Single Number (XOR)',
          type: 'problem',
          difficulty: 'easy',
          pattern: 'Bit Manipulation / XOR',
          conceptsRequired: ['arrays', 'XOR'],
          leetcodeUrl: 'https://leetcode.com/problems/single-number/',
          approaches: [
            {
              name: 'XOR All Elements',
              intuition: 'XOR is self-inverse: a^a = 0 and a^0 = a. XORing all elements cancels every duplicated number, leaving only the unique one.',
              steps: [
                'Initialize result = 0.',
                'For each x in nums: result ^= x.',
                'Return result.',
              ],
              complexity: { time: 'O(N)', space: 'O(1)' },
              code: `int singleNumber(vector<int>& nums) {
    int res = 0;
    for (int x : nums) res ^= x;
    return res;
}`,
            },
          ],
          hints: [
            'XOR of a number with itself is 0; XOR with 0 is the number itself.',
            'Order does not matter in XOR — pairs always cancel.',
            'This runs in O(N) time and O(1) space, which is optimal.',
          ],
          solution: `int singleNumber(vector<int>& nums) {
    int res = 0;
    for (int x : nums) res ^= x;
    return res;
}`,
        },
        {
          id: 'longest-subarray-sum-k-positive',
          slug: 'longest-subarray-sum-k-positive',
          title: 'Longest Subarray with Sum K (Positives Only)',
          type: 'problem',
          difficulty: 'easy',
          pattern: 'Sliding Window',
          conceptsRequired: ['arrays', 'sliding window'],
          approaches: [
            {
              name: 'Variable-Size Sliding Window',
              intuition: 'For non-negative arrays, a sliding window works because adding an element never decreases the sum, and removing elements from the left monotonically decreases the sum.',
              steps: [
                'left = 0, currentSum = 0, maxLen = 0.',
                'For right from 0 to n-1:',
                '  currentSum += arr[right].',
                '  While currentSum > k: currentSum -= arr[left++].',
                '  If currentSum == k: maxLen = max(maxLen, right - left + 1).',
                'Return maxLen.',
              ],
              complexity: { time: 'O(N)', space: 'O(1)' },
              code: `int longestSubarraySumK(vector<int>& arr, int k) {
    int left = 0, sum = 0, maxLen = 0;
    for (int right = 0; right < arr.size(); right++) {
        sum += arr[right];
        while (sum > k) sum -= arr[left++];
        if (sum == k) maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}`,
            },
          ],
          hints: [
            'Since all values are positive, shrinking the window from the left decreases the sum.',
            'Expand the right boundary every iteration; shrink the left boundary while sum exceeds k.',
            'Check for sum == k after each adjustment.',
          ],
          solution: `int longestSubarraySumK(vector<int>& arr, int k) {
    int left = 0, sum = 0, maxLen = 0;
    for (int right = 0; right < (int)arr.size(); right++) {
        sum += arr[right];
        while (sum > k) sum -= arr[left++];
        if (sum == k) maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}`,
        },
        {
          id: 'longest-subarray-sum-k',
          slug: 'longest-subarray-sum-k',
          title: 'Longest Subarray with Sum K (With Negatives)',
          type: 'problem',
          difficulty: 'medium',
          pattern: 'Prefix Sum + Hashing',
          conceptsRequired: ['arrays', 'prefix sum', 'hash map'],
          approaches: [
            {
              name: 'Prefix Sum with Hash Map',
              intuition: 'Track prefix sums. If prefix[j] - prefix[i] == k, then subarray (i+1..j) has sum k. Store the first occurrence index of each prefix sum to maximize length.',
              steps: [
                'Create a map prefixIndex. Set prefixIndex[0] = -1.',
                'Maintain prefixSum = 0, maxLen = 0.',
                'For right from 0 to n-1:',
                '  prefixSum += arr[right].',
                '  If prefixSum - k exists in map: maxLen = max(maxLen, right - map[prefixSum-k]).',
                '  If prefixSum not in map: map[prefixSum] = right. (store first occurrence only)',
                'Return maxLen.',
              ],
              complexity: { time: 'O(N)', space: 'O(N)' },
              code: `int longestSubarrayK(vector<int>& arr, int k) {
    unordered_map<int,int> mp;
    mp[0] = -1;
    int prefixSum = 0, maxLen = 0;
    for (int i = 0; i < arr.size(); i++) {
        prefixSum += arr[i];
        if (mp.count(prefixSum - k))
            maxLen = max(maxLen, i - mp[prefixSum - k]);
        if (!mp.count(prefixSum)) mp[prefixSum] = i;
    }
    return maxLen;
}`,
            },
          ],
          hints: [
            'Sliding window fails with negatives because adding an element could decrease the sum.',
            'Use prefix sums: subarray sum from i+1 to j = prefixSum[j] - prefixSum[i].',
            'Store only the FIRST occurrence of each prefix sum to get the longest subarray.',
          ],
          solution: `int longestSubarrayK(vector<int>& arr, int k) {
    unordered_map<int,int> mp; mp[0] = -1;
    int ps = 0, res = 0;
    for (int i = 0; i < (int)arr.size(); i++) {
        ps += arr[i];
        if (mp.count(ps - k)) res = max(res, i - mp[ps - k]);
        if (!mp.count(ps)) mp[ps] = i;
    }
    return res;
}`,
        },
      ],
    },
    {
      id: 'medium-array-problems',
      title: 'Medium Array Problems',
      topics: [
        {
          id: 'two-sum',
          slug: 'two-sum',
          title: 'Two Sum',
          type: 'problem',
          difficulty: 'easy',
          pattern: 'Hashing',
          conceptsRequired: ['arrays', 'hash map'],
          leetcodeUrl: 'https://leetcode.com/problems/two-sum/',
          approaches: [
            {
              name: 'Hash Map (One Pass)',
              intuition: 'For each element x, check if target - x is already in the hash map. If yes, we found the pair. Otherwise, store x with its index.',
              steps: [
                'Create an empty map: value → index.',
                'For each index i and value nums[i]:',
                '  complement = target - nums[i].',
                '  If complement is in map: return {map[complement], i}.',
                '  Else: map[nums[i]] = i.',
              ],
              complexity: { time: 'O(N)', space: 'O(N)' },
              code: `vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> mp;
    for (int i = 0; i < nums.size(); i++) {
        int comp = target - nums[i];
        if (mp.count(comp)) return {mp[comp], i};
        mp[nums[i]] = i;
    }
    return {};
}`,
            },
          ],
          hints: [
            'For each element, you need to find its complement (target - element) in the array.',
            'A hash map lets you look up the complement in O(1).',
            'Store index as the value in the map so you can return the pair of indices.',
          ],
          solution: `vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> mp;
    for (int i = 0; i < (int)nums.size(); i++) {
        int c = target - nums[i];
        if (mp.count(c)) return {mp[c], i};
        mp[nums[i]] = i;
    }
    return {};
}`,
        },
        {
          id: 'sort-012',
          slug: 'sort-012',
          title: 'Sort Array of 0s, 1s, and 2s',
          type: 'problem',
          difficulty: 'medium',
          pattern: 'Dutch National Flag',
          conceptsRequired: ['arrays', 'three pointers'],
          leetcodeUrl: 'https://leetcode.com/problems/sort-colors/',
          approaches: [
            {
              name: 'Dutch National Flag Algorithm',
              intuition: 'Maintain three regions: [0..low-1] = 0s, [low..mid-1] = 1s, [high+1..n-1] = 2s, [mid..high] = unsorted. Process the unsorted region with pointer mid.',
              steps: [
                'low = 0, mid = 0, high = n-1.',
                'While mid <= high:',
                '  If arr[mid] == 0: swap(arr[low], arr[mid]); low++; mid++.',
                '  If arr[mid] == 1: mid++.',
                '  If arr[mid] == 2: swap(arr[mid], arr[high]); high--. (do NOT increment mid)',
              ],
              complexity: { time: 'O(N)', space: 'O(1)' },
              code: `void sortColors(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size() - 1;
    while (mid <= high) {
        if (nums[mid] == 0) swap(nums[low++], nums[mid++]);
        else if (nums[mid] == 1) mid++;
        else swap(nums[mid], nums[high--]);
    }
}`,
            },
          ],
          hints: [
            'Dutch National Flag: maintain three pointers for three regions.',
            'When swapping with high, do not advance mid — the swapped element is unknown.',
            'When swapping with low, advance both low and mid since we know low is now a 0.',
          ],
          solution: `void sortColors(vector<int>& nums) {
    int lo = 0, mid = 0, hi = (int)nums.size() - 1;
    while (mid <= hi) {
        if (nums[mid] == 0) swap(nums[lo++], nums[mid++]);
        else if (nums[mid] == 1) mid++;
        else swap(nums[mid], nums[hi--]);
    }
}`,
        },
        {
          id: 'majority-element-1',
          slug: 'majority-element-1',
          title: 'Majority Element (> N/2 times)',
          type: 'problem',
          difficulty: 'easy',
          pattern: "Boyer-Moore Voting",
          conceptsRequired: ['arrays', 'voting algorithm'],
          leetcodeUrl: 'https://leetcode.com/problems/majority-element/',
          approaches: [
            {
              name: "Boyer-Moore Voting Algorithm",
              intuition: 'Pair up different elements and cancel them. The element that survives is the majority candidate. Since the majority element appears > N/2 times it can never be completely cancelled.',
              steps: [
                'candidate = nums[0], count = 1.',
                'For i from 1 to n-1:',
                '  If count == 0: candidate = nums[i], count = 1.',
                '  Else if nums[i] == candidate: count++.',
                '  Else: count--.',
                'Return candidate (guaranteed to be the majority).',
              ],
              complexity: { time: 'O(N)', space: 'O(1)' },
              code: `int majorityElement(vector<int>& nums) {
    int candidate = nums[0], count = 1;
    for (int i = 1; i < nums.size(); i++) {
        if (count == 0) { candidate = nums[i]; count = 1; }
        else if (nums[i] == candidate) count++;
        else count--;
    }
    return candidate;
}`,
            },
          ],
          hints: [
            'The majority element appears more than N/2 times, so it cannot be eliminated.',
            "Boyer-Moore voting: cancel one occurrence of a different element with one occurrence of the candidate.",
            'The final candidate is always the majority element when a majority is guaranteed to exist.',
          ],
          solution: `int majorityElement(vector<int>& nums) {
    int cand = nums[0], cnt = 1;
    for (int i = 1; i < (int)nums.size(); i++) {
        if (!cnt) { cand = nums[i]; cnt = 1; }
        else cnt += (nums[i] == cand) ? 1 : -1;
    }
    return cand;
}`,
        },
        {
          id: 'kadanes-algorithm',
          slug: 'kadanes-algorithm',
          title: "Kadane's Algorithm — Maximum Subarray Sum",
          type: 'problem',
          difficulty: 'medium',
          pattern: "Kadane's / DP",
          conceptsRequired: ['arrays', 'dynamic programming'],
          leetcodeUrl: 'https://leetcode.com/problems/maximum-subarray/',
          approaches: [
            {
              name: "Kadane's Algorithm",
              intuition: 'Maintain a running sum. If the running sum becomes negative, it is always better to start fresh from the next element. Track the maximum seen so far.',
              steps: [
                'currentSum = nums[0], maxSum = nums[0].',
                'For i from 1 to n-1:',
                '  currentSum = max(nums[i], currentSum + nums[i]).',
                '  maxSum = max(maxSum, currentSum).',
                'Return maxSum.',
              ],
              complexity: { time: 'O(N)', space: 'O(1)' },
              code: `int maxSubArray(vector<int>& nums) {
    int cur = nums[0], best = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        cur = max(nums[i], cur + nums[i]);
        best = max(best, cur);
    }
    return best;
}`,
            },
          ],
          hints: [
            'A negative prefix sum only hurts any subarray starting after it — reset to 0 when current sum goes negative.',
            'Initialize with nums[0], not 0, to handle all-negative arrays.',
            "This is essentially the DP recurrence: dp[i] = max(nums[i], dp[i-1] + nums[i]).",
          ],
          solution: `int maxSubArray(vector<int>& nums) {
    int cur = nums[0], best = nums[0];
    for (int i = 1; i < (int)nums.size(); i++) {
        cur = max(nums[i], cur + nums[i]);
        best = max(best, cur);
    }
    return best;
}`,
        },
        {
          id: 'max-subarray-print',
          slug: 'max-subarray-print',
          title: 'Print the Maximum Subarray',
          type: 'problem',
          difficulty: 'medium',
          pattern: "Kadane's with Tracking",
          conceptsRequired: ['arrays', "Kadane's algorithm"],
          approaches: [
            {
              name: "Kadane's with Index Tracking",
              intuition: "Extend Kadane's to remember start and end indices of the current and best subarray.",
              steps: [
                'Track start, end, tempStart indices.',
                'When cur + nums[i] < nums[i]: reset tempStart = i.',
                'When maxSum updates: record start = tempStart, end = i.',
                'Print arr[start..end].',
              ],
              complexity: { time: 'O(N)', space: 'O(1)' },
              code: `vector<int> maxSubarrayPrint(vector<int>& nums) {
    int n = nums.size();
    int cur = nums[0], best = nums[0];
    int start = 0, end = 0, tempStart = 0;
    for (int i = 1; i < n; i++) {
        if (nums[i] > cur + nums[i]) { cur = nums[i]; tempStart = i; }
        else cur += nums[i];
        if (cur > best) { best = cur; start = tempStart; end = i; }
    }
    return vector<int>(nums.begin() + start, nums.begin() + end + 1);
}`,
            },
          ],
          hints: [
            'Use a tempStart pointer that resets whenever starting fresh is better.',
            'Update the global start/end only when a new maximum is found.',
            'The subarray is nums[start..end] inclusive.',
          ],
          solution: `vector<int> maxSubarrayPrint(vector<int>& nums) {
    int cur = nums[0], best = nums[0], s = 0, e = 0, ts = 0;
    for (int i = 1; i < (int)nums.size(); i++) {
        if (nums[i] > cur + nums[i]) { cur = nums[i]; ts = i; }
        else cur += nums[i];
        if (cur > best) { best = cur; s = ts; e = i; }
    }
    return {nums.begin() + s, nums.begin() + e + 1};
}`,
        },
        {
          id: 'stock-buy-sell',
          slug: 'stock-buy-sell',
          title: 'Best Time to Buy and Sell Stock (1 Transaction)',
          type: 'problem',
          difficulty: 'easy',
          pattern: 'Greedy / Linear Scan',
          conceptsRequired: ['arrays', 'greedy'],
          leetcodeUrl: 'https://leetcode.com/problems/best-time-to-buy-and-sell-stock/',
          approaches: [
            {
              name: 'Track Minimum and Max Profit',
              intuition: 'For each day, the best profit selling on that day is prices[i] - minSoFar. Update minSoFar as we go.',
              steps: [
                'minPrice = INT_MAX, maxProfit = 0.',
                'For each price p:',
                '  minPrice = min(minPrice, p).',
                '  maxProfit = max(maxProfit, p - minPrice).',
                'Return maxProfit.',
              ],
              complexity: { time: 'O(N)', space: 'O(1)' },
              code: `int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX, maxProfit = 0;
    for (int p : prices) {
        minPrice = min(minPrice, p);
        maxProfit = max(maxProfit, p - minPrice);
    }
    return maxProfit;
}`,
            },
          ],
          hints: [
            'Buy at the cheapest price seen so far.',
            'On each day, compute the profit if you sold today.',
            'You must buy before you sell — tracking minimum from the left handles this.',
          ],
          solution: `int maxProfit(vector<int>& prices) {
    int lo = INT_MAX, best = 0;
    for (int p : prices) { lo = min(lo, p); best = max(best, p - lo); }
    return best;
}`,
        },
        {
          id: 'rearrange-by-sign',
          slug: 'rearrange-by-sign',
          title: 'Rearrange Array Elements by Sign',
          type: 'problem',
          difficulty: 'medium',
          pattern: 'Two Pointers',
          conceptsRequired: ['arrays', 'two pointers'],
          leetcodeUrl: 'https://leetcode.com/problems/rearrange-array-elements-by-sign/',
          approaches: [
            {
              name: 'Separate and Interleave',
              intuition: 'Use two pointers (posIdx, negIdx) for even and odd positions in the result array. Positive numbers go to even indices (0,2,4,...), negatives to odd indices.',
              steps: [
                'Create result array of size n.',
                'posIdx = 0, negIdx = 1.',
                'For each x in nums:',
                '  If x > 0: result[posIdx] = x; posIdx += 2.',
                '  Else: result[negIdx] = x; negIdx += 2.',
                'Return result.',
              ],
              complexity: { time: 'O(N)', space: 'O(N)' },
              code: `vector<int> rearrangeArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n);
    int pos = 0, neg = 1;
    for (int x : nums) {
        if (x > 0) { res[pos] = x; pos += 2; }
        else { res[neg] = x; neg += 2; }
    }
    return res;
}`,
            },
          ],
          hints: [
            'Equal counts of positives and negatives simplifies this: place positives at even indices, negatives at odd indices.',
            'Use two separate index pointers advancing by 2.',
            'This achieves O(N) time and O(N) space.',
          ],
          solution: `vector<int> rearrangeArray(vector<int>& nums) {
    int n = nums.size(); vector<int> res(n); int p = 0, q = 1;
    for (int x : nums) { if (x > 0) { res[p] = x; p += 2; } else { res[q] = x; q += 2; } }
    return res;
}`,
        },
        {
          id: 'next-permutation',
          slug: 'next-permutation',
          title: 'Next Permutation',
          type: 'problem',
          difficulty: 'medium',
          pattern: 'Array / Greedy',
          conceptsRequired: ['arrays', 'permutations'],
          leetcodeUrl: 'https://leetcode.com/problems/next-permutation/',
          approaches: [
            {
              name: 'STL-Equivalent 3-Step Algorithm',
              intuition: 'Find the rightmost "dip" (where arr[i] < arr[i+1]), swap it with the smallest element to its right that is still larger, then reverse the suffix to get the lexicographically smallest suffix.',
              steps: [
                'Find the largest index i such that nums[i] < nums[i+1]. If none, the array is the last permutation — reverse everything.',
                'Find the largest index j > i such that nums[j] > nums[i].',
                'Swap nums[i] and nums[j].',
                'Reverse the subarray from i+1 to end.',
              ],
              complexity: { time: 'O(N)', space: 'O(1)' },
              code: `void nextPermutation(vector<int>& nums) {
    int n = nums.size(), i = n - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) i--;
    if (i >= 0) {
        int j = n - 1;
        while (nums[j] <= nums[i]) j--;
        swap(nums[i], nums[j]);
    }
    reverse(nums.begin() + i + 1, nums.end());
}`,
            },
          ],
          hints: [
            'Scan from the right to find the first element that breaks descending order.',
            'Swap it with the smallest element to its right that is still greater.',
            'Reverse the suffix to get the smallest possible suffix arrangement.',
          ],
          solution: `void nextPermutation(vector<int>& nums) {
    int n = nums.size(), i = n - 2;
    while (i >= 0 && nums[i] >= nums[i+1]) i--;
    if (i >= 0) { int j = n-1; while (nums[j] <= nums[i]) j--; swap(nums[i], nums[j]); }
    reverse(nums.begin() + i + 1, nums.end());
}`,
        },
        {
          id: 'leaders-in-array',
          slug: 'leaders-in-array',
          title: 'Leaders in an Array',
          type: 'problem',
          difficulty: 'easy',
          pattern: 'Right-to-Left Scan',
          conceptsRequired: ['arrays'],
          approaches: [
            {
              name: 'Scan from Right',
              intuition: 'An element is a leader if it is greater than all elements to its right. Scan from right, tracking the running maximum. Each element that exceeds the running maximum is a leader.',
              steps: [
                'Start from the rightmost element (always a leader).',
                'Maintain maxRight = arr[n-1], result = {arr[n-1]}.',
                'For i from n-2 to 0:',
                '  If arr[i] >= maxRight: result.push_back(arr[i]); maxRight = arr[i].',
                'Reverse result and return.',
              ],
              complexity: { time: 'O(N)', space: 'O(1) extra' },
              code: `vector<int> leaders(vector<int>& arr) {
    int n = arr.size();
    vector<int> res;
    int maxRight = arr[n - 1];
    res.push_back(maxRight);
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] >= maxRight) {
            maxRight = arr[i];
            res.push_back(arr[i]);
        }
    }
    reverse(res.begin(), res.end());
    return res;
}`,
            },
          ],
          hints: [
            'The rightmost element is always a leader.',
            'Scan from right to left, tracking the maximum seen so far.',
            'Any element greater than or equal to maxRight from its right is a leader.',
          ],
          solution: `vector<int> leaders(vector<int>& arr) {
    int n = arr.size(); vector<int> res; int mr = arr[n-1];
    res.push_back(mr);
    for (int i = n-2; i >= 0; i--) if (arr[i] >= mr) { mr = arr[i]; res.push_back(mr); }
    reverse(res.begin(), res.end());
    return res;
}`,
        },
        {
          id: 'longest-consecutive-sequence',
          slug: 'longest-consecutive-sequence',
          title: 'Longest Consecutive Sequence',
          type: 'problem',
          difficulty: 'medium',
          pattern: 'Hashing',
          conceptsRequired: ['arrays', 'hash set'],
          leetcodeUrl: 'https://leetcode.com/problems/longest-consecutive-sequence/',
          approaches: [
            {
              name: 'Hash Set with Sequence Start Detection',
              intuition: 'Insert all numbers into a set. For each number that has no left neighbor (x-1 not in set), try to extend the sequence rightward. This ensures each sequence is counted exactly once.',
              steps: [
                'Insert all elements into an unordered_set.',
                'For each x in the set, if x-1 is NOT in set (x is a sequence start):',
                '  Count consecutive: while x++ is in set, increment length.',
                '  Update maxLen.',
                'Return maxLen.',
              ],
              complexity: { time: 'O(N)', space: 'O(N)' },
              code: `int longestConsecutive(vector<int>& nums) {
    unordered_set<int> st(nums.begin(), nums.end());
    int maxLen = 0;
    for (int x : st) {
        if (!st.count(x - 1)) {
            int cur = x, len = 1;
            while (st.count(cur + 1)) { cur++; len++; }
            maxLen = max(maxLen, len);
        }
    }
    return maxLen;
}`,
            },
          ],
          hints: [
            'Put all numbers in a hash set for O(1) lookup.',
            'Only start counting from a number that has no predecessor (x-1 not in set).',
            'This prevents re-counting from the middle of sequences, keeping the total work O(N).',
          ],
          solution: `int longestConsecutive(vector<int>& nums) {
    unordered_set<int> st(nums.begin(), nums.end()); int res = 0;
    for (int x : st) if (!st.count(x-1)) { int c = x, l = 1; while (st.count(++c)) l++; res = max(res, l); }
    return res;
}`,
        },
        {
          id: 'set-matrix-zeroes',
          slug: 'set-matrix-zeroes',
          title: 'Set Matrix Zeroes',
          type: 'problem',
          difficulty: 'medium',
          pattern: 'Matrix / In-place Marking',
          conceptsRequired: ['arrays', 'matrix', 'in-place'],
          leetcodeUrl: 'https://leetcode.com/problems/set-matrix-zeroes/',
          approaches: [
            {
              name: 'Use First Row and Column as Markers',
              intuition: 'Use the first row and first column of the matrix itself as markers for which rows/columns should be zeroed, avoiding extra space.',
              steps: [
                'Check if row 0 or col 0 originally contains a zero (store flags).',
                'For each (i,j) with i>0 and j>0: if matrix[i][j]==0, set matrix[i][0]=0 and matrix[0][j]=0.',
                'For each (i,j) with i>0 and j>0: if matrix[i][0]==0 or matrix[0][j]==0, set matrix[i][j]=0.',
                'Handle row 0 and col 0 separately using the stored flags.',
              ],
              complexity: { time: 'O(M*N)', space: 'O(1)' },
              code: `void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    bool row0 = false, col0 = false;
    for (int j = 0; j < n; j++) if (matrix[0][j] == 0) row0 = true;
    for (int i = 0; i < m; i++) if (matrix[i][0] == 0) col0 = true;
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            if (matrix[i][j] == 0) { matrix[i][0] = 0; matrix[0][j] = 0; }
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
    if (row0) for (int j = 0; j < n; j++) matrix[0][j] = 0;
    if (col0) for (int i = 0; i < m; i++) matrix[i][0] = 0;
}`,
            },
          ],
          hints: [
            'Naively scanning and zeroing simultaneously will wrongly zero elements.',
            'Use a two-pass approach: first mark which rows/columns need zeroing, then zero them.',
            'Use the first row and column as O(1) auxiliary space to avoid extra arrays.',
          ],
          solution: `void setZeroes(vector<vector<int>>& m) {
    int R = m.size(), C = m[0].size(); bool r0=false, c0=false;
    for (int j=0;j<C;j++) if(!m[0][j]) r0=true;
    for (int i=0;i<R;i++) if(!m[i][0]) c0=true;
    for (int i=1;i<R;i++) for (int j=1;j<C;j++) if(!m[i][j]){m[i][0]=0;m[0][j]=0;}
    for (int i=1;i<R;i++) for (int j=1;j<C;j++) if(!m[i][0]||!m[0][j]) m[i][j]=0;
    if(r0) for(int j=0;j<C;j++) m[0][j]=0;
    if(c0) for(int i=0;i<R;i++) m[i][0]=0;
}`,
        },
        {
          id: 'rotate-matrix-90',
          slug: 'rotate-matrix-90',
          title: 'Rotate Matrix by 90 Degrees',
          type: 'problem',
          difficulty: 'medium',
          pattern: 'Matrix / Transpose',
          conceptsRequired: ['arrays', 'matrix', 'in-place'],
          leetcodeUrl: 'https://leetcode.com/problems/rotate-image/',
          approaches: [
            {
              name: 'Transpose then Reverse Rows',
              intuition: 'A 90-degree clockwise rotation equals transposing the matrix (swap matrix[i][j] with matrix[j][i]) and then reversing each row.',
              steps: [
                'Transpose: for i in 0..n-1, for j in i+1..n-1: swap(matrix[i][j], matrix[j][i]).',
                'Reverse each row: for each row, call reverse(row.begin(), row.end()).',
              ],
              complexity: { time: 'O(N²)', space: 'O(1)' },
              code: `void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    // Transpose
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            swap(matrix[i][j], matrix[j][i]);
    // Reverse each row
    for (auto& row : matrix)
        reverse(row.begin(), row.end());
}`,
            },
          ],
          hints: [
            'Clockwise 90 degrees = transpose + reverse each row.',
            'Counter-clockwise 90 degrees = transpose + reverse each column.',
            'Transpose only needs to iterate over the upper triangle (j > i) to avoid double-swapping.',
          ],
          solution: `void rotate(vector<vector<int>>& mat) {
    int n = mat.size();
    for (int i=0;i<n;i++) for (int j=i+1;j<n;j++) swap(mat[i][j],mat[j][i]);
    for (auto& row : mat) reverse(row.begin(), row.end());
}`,
        },
        {
          id: 'spiral-matrix',
          slug: 'spiral-matrix',
          title: 'Spiral Matrix',
          type: 'problem',
          difficulty: 'medium',
          pattern: 'Matrix / Simulation',
          conceptsRequired: ['arrays', 'matrix'],
          leetcodeUrl: 'https://leetcode.com/problems/spiral-matrix/',
          approaches: [
            {
              name: 'Layer Boundaries Simulation',
              intuition: 'Maintain four boundaries: top, bottom, left, right. Traverse the outermost layer in spiral order, then shrink the boundaries inward.',
              steps: [
                'Initialize top=0, bottom=m-1, left=0, right=n-1.',
                'While top <= bottom and left <= right:',
                '  Traverse left→right along top row; top++.',
                '  Traverse top→bottom along right col; right--.',
                '  If top <= bottom: traverse right→left along bottom row; bottom--.',
                '  If left <= right: traverse bottom→top along left col; left++.',
              ],
              complexity: { time: 'O(M*N)', space: 'O(1) extra' },
              code: `vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    int top = 0, bottom = matrix.size()-1, left = 0, right = matrix[0].size()-1;
    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; j++) res.push_back(matrix[top][j]); top++;
        for (int i = top; i <= bottom; i++) res.push_back(matrix[i][right]); right--;
        if (top <= bottom) { for (int j = right; j >= left; j--) res.push_back(matrix[bottom][j]); bottom--; }
        if (left <= right) { for (int i = bottom; i >= top; i--) res.push_back(matrix[i][left]); left++; }
    }
    return res;
}`,
            },
          ],
          hints: [
            'Use four boundary variables: top, bottom, left, right.',
            'After each directional pass, shrink the corresponding boundary.',
            'Always check boundary conditions before traversing bottom and left passes to handle non-square matrices.',
          ],
          solution: `vector<int> spiralOrder(vector<vector<int>>& mat) {
    vector<int> res; int t=0,b=mat.size()-1,l=0,r=mat[0].size()-1;
    while(t<=b&&l<=r){
        for(int j=l;j<=r;j++) res.push_back(mat[t][j]); t++;
        for(int i=t;i<=b;i++) res.push_back(mat[i][r]); r--;
        if(t<=b){for(int j=r;j>=l;j--) res.push_back(mat[b][j]); b--;}
        if(l<=r){for(int i=b;i>=t;i--) res.push_back(mat[i][l]); l++;}
    }
    return res;
}`,
        },
        {
          id: 'count-subarrays-sum',
          slug: 'count-subarrays-sum',
          title: 'Count Subarrays with Given Sum',
          type: 'problem',
          difficulty: 'medium',
          pattern: 'Prefix Sum + Hashing',
          conceptsRequired: ['arrays', 'prefix sum', 'hash map'],
          leetcodeUrl: 'https://leetcode.com/problems/subarray-sum-equals-k/',
          approaches: [
            {
              name: 'Prefix Sum with Frequency Map',
              intuition: 'If prefixSum[j] - prefixSum[i] = k, then subarray [i+1..j] sums to k. Count how many previous prefix sums equal (currentPrefixSum - k).',
              steps: [
                'Map: prefixCount = {0: 1}.',
                'prefixSum = 0, count = 0.',
                'For each x in nums:',
                '  prefixSum += x.',
                '  count += prefixCount[prefixSum - k].',
                '  prefixCount[prefixSum]++.',
                'Return count.',
              ],
              complexity: { time: 'O(N)', space: 'O(N)' },
              code: `int subarraySum(vector<int>& nums, int k) {
    unordered_map<int,int> mp;
    mp[0] = 1;
    int ps = 0, count = 0;
    for (int x : nums) {
        ps += x;
        count += mp[ps - k];
        mp[ps]++;
    }
    return count;
}`,
            },
          ],
          hints: [
            'Use prefix sums and a frequency map.',
            'Initialize the map with {0:1} to handle subarrays starting from index 0.',
            'For each new prefix sum, add the frequency of (prefixSum - k) to the answer.',
          ],
          solution: `int subarraySum(vector<int>& nums, int k) {
    unordered_map<int,int> mp; mp[0]=1; int ps=0,cnt=0;
    for (int x:nums){ps+=x;cnt+=mp[ps-k];mp[ps]++;}
    return cnt;
}`,
        },
      ],
    },
    {
      id: 'hard-array-problems',
      title: 'Hard Array Problems',
      topics: [
        {
          id: 'pascals-triangle',
          slug: 'pascals-triangle',
          title: "Pascal's Triangle",
          type: 'problem',
          difficulty: 'easy',
          pattern: 'Math / DP',
          conceptsRequired: ['arrays', 'combinatorics'],
          leetcodeUrl: 'https://leetcode.com/problems/pascals-triangle/',
          approaches: [
            {
              name: 'Row-by-Row Construction',
              intuition: "Each row is built from the previous: element[j] = prev[j-1] + prev[j]. Edges are always 1.",
              steps: [
                'Start with [[1]].',
                'For each new row r from 1 to numRows-1:',
                '  Build row starting and ending with 1.',
                '  For j from 1 to r-1: row[j] = prev[j-1] + prev[j].',
                '  Append row to result.',
              ],
              complexity: { time: 'O(N²)', space: 'O(N²)' },
              code: `vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res = {{1}};
    for (int i = 1; i < numRows; i++) {
        vector<int> row = {1};
        for (int j = 1; j < i; j++)
            row.push_back(res[i-1][j-1] + res[i-1][j]);
        row.push_back(1);
        res.push_back(row);
    }
    return res;
}`,
            },
          ],
          hints: [
            'Each interior element is the sum of the two elements directly above it.',
            'Every row begins and ends with 1.',
            'To get just the Nth row efficiently, use C(n,0), C(n,1), ..., C(n,n) with the multiplicative formula.',
          ],
          solution: `vector<vector<int>> generate(int n) {
    vector<vector<int>> res={{1}};
    for(int i=1;i<n;i++){
        vector<int> row={1};
        for(int j=1;j<i;j++) row.push_back(res[i-1][j-1]+res[i-1][j]);
        row.push_back(1); res.push_back(row);
    }
    return res;
}`,
        },
        {
          id: 'majority-element-2',
          slug: 'majority-element-2',
          title: 'Majority Element II (> N/3 times)',
          type: 'problem',
          difficulty: 'medium',
          pattern: "Boyer-Moore Voting (Extended)",
          conceptsRequired: ['arrays', 'voting algorithm'],
          leetcodeUrl: 'https://leetcode.com/problems/majority-element-ii/',
          approaches: [
            {
              name: "Extended Boyer-Moore Voting",
              intuition: 'There can be at most 2 elements appearing more than N/3 times. Use two candidates with two counters. Run a second verification pass to confirm both candidates.',
              steps: [
                'Maintain candidate1, candidate2, count1=0, count2=0.',
                'For each x: if x==cand1 count1++, else if x==cand2 count2++, else if count1==0 cand1=x,count1=1, else if count2==0 cand2=x,count2=1, else count1--,count2--.',
                'Verification pass: count actual occurrences of cand1 and cand2.',
                'Add to result if count > n/3.',
              ],
              complexity: { time: 'O(N)', space: 'O(1)' },
              code: `vector<int> majorityElement(vector<int>& nums) {
    int c1 = 0, c2 = 0, cand1 = INT_MIN, cand2 = INT_MIN;
    for (int x : nums) {
        if (x == cand1) c1++;
        else if (x == cand2) c2++;
        else if (c1 == 0) { cand1 = x; c1 = 1; }
        else if (c2 == 0) { cand2 = x; c2 = 1; }
        else { c1--; c2--; }
    }
    c1 = c2 = 0;
    for (int x : nums) { if (x == cand1) c1++; else if (x == cand2) c2++; }
    vector<int> res;
    int n = nums.size();
    if (c1 > n/3) res.push_back(cand1);
    if (c2 > n/3) res.push_back(cand2);
    return res;
}`,
            },
          ],
          hints: [
            'At most 2 elements can appear more than N/3 times.',
            'Use two Boyer-Moore candidates simultaneously.',
            'Always verify candidates in a second pass — the first pass only finds potential candidates.',
          ],
          solution: `vector<int> majorityElement(vector<int>& nums) {
    int c1=0,c2=0,x1=INT_MIN,x2=INT_MIN;
    for(int x:nums){if(x==x1)c1++;else if(x==x2)c2++;else if(!c1){x1=x;c1=1;}else if(!c2){x2=x;c2=1;}else{c1--;c2--;}}
    c1=c2=0; for(int x:nums){if(x==x1)c1++;else if(x==x2)c2++;}
    vector<int> res; int n=nums.size(); if(c1>n/3)res.push_back(x1); if(c2>n/3)res.push_back(x2); return res;
}`,
        },
        {
          id: 'three-sum',
          slug: 'three-sum',
          title: '3Sum — Find All Triplets Summing to Zero',
          type: 'problem',
          difficulty: 'medium',
          pattern: 'Sort + Two Pointers',
          conceptsRequired: ['arrays', 'sorting', 'two pointers'],
          leetcodeUrl: 'https://leetcode.com/problems/3sum/',
          approaches: [
            {
              name: 'Sort + Two Pointer',
              intuition: 'Sort the array. Fix one element and use two pointers on the remaining portion to find pairs summing to -nums[i]. Skip duplicates to avoid repeated triplets.',
              steps: [
                'Sort nums.',
                'For i from 0 to n-3 (skip duplicates: if i>0 && nums[i]==nums[i-1] continue):',
                '  lo = i+1, hi = n-1.',
                '  While lo < hi:',
                '    sum = nums[i] + nums[lo] + nums[hi].',
                '    If sum == 0: add triplet, skip duplicates for lo and hi, advance both.',
                '    If sum < 0: lo++. If sum > 0: hi--.',
              ],
              complexity: { time: 'O(N²)', space: 'O(1) extra' },
              code: `vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    int n = nums.size();
    for (int i = 0; i < n - 2; i++) {
        if (i > 0 && nums[i] == nums[i-1]) continue;
        int lo = i + 1, hi = n - 1;
        while (lo < hi) {
            int s = nums[i] + nums[lo] + nums[hi];
            if (s == 0) {
                res.push_back({nums[i], nums[lo], nums[hi]});
                while (lo < hi && nums[lo] == nums[lo+1]) lo++;
                while (lo < hi && nums[hi] == nums[hi-1]) hi--;
                lo++; hi--;
            } else if (s < 0) lo++;
            else hi--;
        }
    }
    return res;
}`,
            },
          ],
          hints: [
            'Sort first; it makes duplicate skipping and two-pointer both work.',
            'Fix the first element and apply two-sum with two pointers on the rest.',
            'Skip duplicates at all three levels (i, lo, hi) to avoid repeat triplets.',
          ],
          solution: `vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(),nums.end()); vector<vector<int>> res; int n=nums.size();
    for(int i=0;i<n-2;i++){
        if(i&&nums[i]==nums[i-1])continue;
        int l=i+1,r=n-1;
        while(l<r){int s=nums[i]+nums[l]+nums[r];if(!s){res.push_back({nums[i],nums[l],nums[r]});while(l<r&&nums[l]==nums[l+1])l++;while(l<r&&nums[r]==nums[r-1])r--;l++;r--;}else if(s<0)l++;else r--;}
    }
    return res;
}`,
        },
        {
          id: 'four-sum',
          slug: 'four-sum',
          title: '4Sum — Find All Quadruplets',
          type: 'problem',
          difficulty: 'medium',
          pattern: 'Sort + Two Pointers',
          conceptsRequired: ['arrays', 'sorting', 'two pointers'],
          leetcodeUrl: 'https://leetcode.com/problems/4sum/',
          approaches: [
            {
              name: 'Sort + Nested Two Pointers',
              intuition: 'Extend 3Sum. Fix two elements with nested loops (i, j), then apply two-pointer search on the remaining portion. Careful duplicate skipping at all levels.',
              steps: [
                'Sort nums.',
                'For i from 0 to n-3:',
                '  Skip duplicate i. For j from i+1 to n-2:',
                '    Skip duplicate j. lo = j+1, hi = n-1.',
                '    While lo < hi: compute sum. Handle == target (add, skip dups, advance), < target (lo++), > target (hi--).',
              ],
              complexity: { time: 'O(N³)', space: 'O(1) extra' },
              code: `vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res; int n = nums.size();
    for (int i = 0; i < n-3; i++) {
        if (i && nums[i] == nums[i-1]) continue;
        for (int j = i+1; j < n-2; j++) {
            if (j > i+1 && nums[j] == nums[j-1]) continue;
            int lo = j+1, hi = n-1;
            while (lo < hi) {
                long long s = (long long)nums[i]+nums[j]+nums[lo]+nums[hi];
                if (s == target) {
                    res.push_back({nums[i],nums[j],nums[lo],nums[hi]});
                    while (lo<hi && nums[lo]==nums[lo+1]) lo++;
                    while (lo<hi && nums[hi]==nums[hi-1]) hi--;
                    lo++; hi--;
                } else if (s < target) lo++;
                else hi--;
            }
        }
    }
    return res;
}`,
            },
          ],
          hints: [
            'Sort the array first, then use a nested loop for the first two elements.',
            'Use two pointers for the last two elements inside the nested loops.',
            'Use long long for the sum to avoid integer overflow with large values.',
          ],
          solution: `vector<vector<int>> fourSum(vector<int>& nums, int t) {
    sort(nums.begin(),nums.end()); vector<vector<int>> res; int n=nums.size();
    for(int i=0;i<n-3;i++){if(i&&nums[i]==nums[i-1])continue;for(int j=i+1;j<n-2;j++){if(j>i+1&&nums[j]==nums[j-1])continue;int l=j+1,r=n-1;while(l<r){long long s=(long long)nums[i]+nums[j]+nums[l]+nums[r];if(s==t){res.push_back({nums[i],nums[j],nums[l],nums[r]});while(l<r&&nums[l]==nums[l+1])l++;while(l<r&&nums[r]==nums[r-1])r--;l++;r--;}else if(s<t)l++;else r--;}}}return res;
}`,
        },
        {
          id: 'largest-subarray-sum-zero',
          slug: 'largest-subarray-sum-zero',
          title: 'Largest Subarray with Sum 0',
          type: 'problem',
          difficulty: 'medium',
          pattern: 'Prefix Sum + Hashing',
          conceptsRequired: ['arrays', 'prefix sum', 'hash map'],
          approaches: [
            {
              name: 'Prefix Sum First Occurrence',
              intuition: 'If prefix[j] == prefix[i], the subarray (i+1..j) has sum 0. Store the first occurrence of each prefix sum and compute the maximum span.',
              steps: [
                'Map prefixIndex = {0: -1}.',
                'prefixSum = 0, maxLen = 0.',
                'For each i: prefixSum += arr[i]. If in map: maxLen = max(maxLen, i - map[prefixSum]). Else: map[prefixSum] = i.',
                'Return maxLen.',
              ],
              complexity: { time: 'O(N)', space: 'O(N)' },
              code: `int maxLenZeroSum(vector<int>& arr) {
    unordered_map<int,int> mp;
    mp[0] = -1;
    int ps = 0, maxLen = 0;
    for (int i = 0; i < arr.size(); i++) {
        ps += arr[i];
        if (mp.count(ps)) maxLen = max(maxLen, i - mp[ps]);
        else mp[ps] = i;
    }
    return maxLen;
}`,
            },
          ],
          hints: [
            'Same prefix sum at two indices means sum-zero subarray between them.',
            'Store only the FIRST occurrence to maximize subarray length.',
            'Initialize map with {0: -1} to handle subarrays from index 0.',
          ],
          solution: `int maxLenZeroSum(vector<int>& arr) {
    unordered_map<int,int> mp; mp[0]=-1; int ps=0,res=0;
    for(int i=0;i<(int)arr.size();i++){ps+=arr[i];if(mp.count(ps))res=max(res,i-mp[ps]);else mp[ps]=i;}
    return res;
}`,
        },
        {
          id: 'count-subarrays-xor-k',
          slug: 'count-subarrays-xor-k',
          title: 'Count Subarrays with XOR = K',
          type: 'problem',
          difficulty: 'medium',
          pattern: 'Prefix XOR + Hashing',
          conceptsRequired: ['arrays', 'prefix XOR', 'hash map', 'bit manipulation'],
          approaches: [
            {
              name: 'Prefix XOR Frequency Map',
              intuition: 'Analogous to subarray sum = k but with XOR. If prefixXOR[j] ^ prefixXOR[i] == k, then XOR of subarray [i+1..j] == k. Use a XOR property: prefixXOR[i] = prefixXOR[j] ^ k.',
              steps: [
                'Map xorCount = {0: 1}.',
                'prefixXOR = 0, count = 0.',
                'For each x: prefixXOR ^= x. count += xorCount[prefixXOR ^ k]. xorCount[prefixXOR]++.',
                'Return count.',
              ],
              complexity: { time: 'O(N)', space: 'O(N)' },
              code: `int countSubarraysXorK(vector<int>& arr, int k) {
    unordered_map<int,int> mp;
    mp[0] = 1;
    int prefXOR = 0, count = 0;
    for (int x : arr) {
        prefXOR ^= x;
        count += mp[prefXOR ^ k];
        mp[prefXOR]++;
    }
    return count;
}`,
            },
          ],
          hints: [
            'Prefix XOR works just like prefix sum, but with ^ instead of +.',
            'Subarray [i+1..j] has XOR k iff prefixXOR[j] ^ prefixXOR[i] == k, i.e., prefixXOR[i] == prefixXOR[j] ^ k.',
            'Initialize the map with {0:1} to count subarrays starting from index 0.',
          ],
          solution: `int countXorK(vector<int>& arr, int k) {
    unordered_map<int,int> mp; mp[0]=1; int px=0,cnt=0;
    for(int x:arr){px^=x;cnt+=mp[px^k];mp[px]++;}
    return cnt;
}`,
        },
        {
          id: 'merge-overlapping-intervals',
          slug: 'merge-overlapping-intervals',
          title: 'Merge Overlapping Intervals',
          type: 'problem',
          difficulty: 'medium',
          pattern: 'Sorting + Greedy',
          conceptsRequired: ['arrays', 'sorting', 'intervals'],
          leetcodeUrl: 'https://leetcode.com/problems/merge-intervals/',
          approaches: [
            {
              name: 'Sort by Start, Greedy Merge',
              intuition: 'After sorting by start time, intervals that can be merged are always adjacent. Walk through and greedily extend the current interval or start a new one.',
              steps: [
                'Sort intervals by start time.',
                'Initialize result with intervals[0].',
                'For each subsequent interval [s, e]:',
                '  If s <= result.back()[1]: merge by updating end = max(end, e).',
                '  Else: push new interval.',
                'Return result.',
              ],
              complexity: { time: 'O(N log N)', space: 'O(N)' },
              code: `vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> res = {intervals[0]};
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] <= res.back()[1])
            res.back()[1] = max(res.back()[1], intervals[i][1]);
        else res.push_back(intervals[i]);
    }
    return res;
}`,
            },
          ],
          hints: [
            'Sort by start time so overlapping intervals are adjacent.',
            'Two intervals overlap if the next start is <= current end.',
            'When merging, take the maximum of the two end times.',
          ],
          solution: `vector<vector<int>> merge(vector<vector<int>>& iv) {
    sort(iv.begin(),iv.end()); vector<vector<int>> res={iv[0]};
    for(int i=1;i<(int)iv.size();i++) if(iv[i][0]<=res.back()[1])res.back()[1]=max(res.back()[1],iv[i][1]);else res.push_back(iv[i]);
    return res;
}`,
        },
        {
          id: 'merge-sorted-no-extra-space',
          slug: 'merge-sorted-no-extra-space',
          title: 'Merge Two Sorted Arrays Without Extra Space',
          type: 'problem',
          difficulty: 'hard',
          pattern: 'Gap Method / Shell Sort Idea',
          conceptsRequired: ['arrays', 'sorting'],
          leetcodeUrl: 'https://leetcode.com/problems/merge-sorted-array/',
          approaches: [
            {
              name: 'Gap Method (Shell Sort Approach)',
              intuition: 'Treat both arrays as a single virtual array of size m+n. Apply Shell Sort logic: compare elements at gap distance and swap if out of order. Halve the gap each iteration.',
              steps: [
                'gap = ceil((m+n)/2).',
                'While gap > 0:',
                '  Compare pairs (i, i+gap) across both arrays. Swap if needed.',
                '  gap = gap == 1 ? 0 : ceil(gap/2).',
              ],
              complexity: { time: 'O((M+N) log(M+N))', space: 'O(1)' },
              code: `void merge(vector<int>& a, int m, vector<int>& b, int n) {
    int gap = (m + n + 1) / 2;
    while (gap > 0) {
        int i = 0, j = gap;
        while (j < m + n) {
            int ai = i < m ? a[i] : b[i - m];
            int bj = j < m ? a[j] : b[j - m];
            if (ai > bj) {
                if (i < m && j < m) swap(a[i], a[j]);
                else if (i < m) swap(a[i], b[j - m]);
                else swap(b[i - m], b[j - m]);
            }
            i++; j++;
        }
        gap = gap == 1 ? 0 : (gap + 1) / 2;
    }
}`,
            },
          ],
          hints: [
            'Think of both arrays as one virtual array.',
            'Use the Shell Sort gap technique: compare and swap elements at each gap distance.',
            'Halve the gap (rounding up) each iteration until gap reaches 1.',
          ],
          solution: `void mergeNoSpace(vector<int>& a, int m, vector<int>& b, int n) {
    auto get=[&](int i)->int&{return i<m?a[i]:b[i-m];};
    for(int g=(m+n+1)/2;g>0;g=(g==1?0:(g+1)/2)){for(int i=0,j=g;j<m+n;i++,j++) if(get(i)>get(j))swap(get(i),get(j));}
}`,
        },
        {
          id: 'find-repeating-missing',
          slug: 'find-repeating-missing',
          title: 'Find the Repeating and Missing Number',
          type: 'problem',
          difficulty: 'hard',
          pattern: 'Math / XOR',
          conceptsRequired: ['arrays', 'math', 'XOR'],
          approaches: [
            {
              name: 'XOR + Bit Partitioning',
              intuition: 'XOR all array elements and 1..N. Result is repeating^missing. Use a set bit to split numbers into two groups and XOR each group separately to isolate the two values. Then verify.',
              steps: [
                'XOR all elements and all 1..N to get x = repeating ^ missing.',
                'Find any set bit in x (use x & (-x)).',
                'Partition elements (and 1..N) into two groups based on that bit; XOR each group to get two candidates a, b.',
                'Check: count occurrences of a in array. If count==2, a is repeating, b is missing. Else vice versa.',
              ],
              complexity: { time: 'O(N)', space: 'O(1)' },
              code: `pair<int,int> findMissingRepeating(vector<int>& arr) {
    int n = arr.size();
    int xorAll = 0;
    for (int x : arr) xorAll ^= x;
    for (int i = 1; i <= n; i++) xorAll ^= i;
    int bit = xorAll & (-xorAll);
    int a = 0, b = 0;
    for (int x : arr) { if (x & bit) a ^= x; else b ^= x; }
    for (int i = 1; i <= n; i++) { if (i & bit) a ^= i; else b ^= i; }
    int countA = 0;
    for (int x : arr) if (x == a) countA++;
    if (countA == 2) return {a, b}; // a repeating, b missing
    return {b, a};
}`,
            },
          ],
          hints: [
            'XOR all elements with 1..N; the result is repeating XOR missing.',
            'Use any set bit of the XOR result to separate the two distinct values.',
            'After finding the two candidates, count occurrences to determine which is repeating.',
          ],
          solution: `pair<int,int> findRepMiss(vector<int>& arr) {
    int n=arr.size(),xr=0;
    for(int x:arr)xr^=x; for(int i=1;i<=n;i++)xr^=i;
    int bit=xr&(-xr),a=0,b=0;
    for(int x:arr)(x&bit)?a^=x:b^=x; for(int i=1;i<=n;i++)(i&bit)?a^=i:b^=i;
    int ca=0; for(int x:arr)if(x==a)ca++;
    return ca==2?make_pair(a,b):make_pair(b,a);
}`,
        },
        {
          id: 'count-inversions',
          slug: 'count-inversions',
          title: 'Count Inversions Using Merge Sort',
          type: 'problem',
          difficulty: 'hard',
          pattern: 'Divide and Conquer / Merge Sort',
          conceptsRequired: ['arrays', 'merge sort', 'divide and conquer'],
          approaches: [
            {
              name: 'Modified Merge Sort',
              intuition: 'During the merge step, whenever an element from the right half is placed before an element from the left half, all remaining left-half elements form inversions with it.',
              steps: [
                'Divide array into two halves.',
                'Recursively count inversions in left and right halves.',
                'During merge: when right[j] < left[i], all elements left[i..mid] form inversions with right[j]. Add (mid - i + 1) to count.',
                'Merge and return total count.',
              ],
              complexity: { time: 'O(N log N)', space: 'O(N)' },
              code: `long long mergeCount(vector<int>& arr, int l, int r) {
    if (l >= r) return 0;
    int mid = (l + r) / 2;
    long long cnt = mergeCount(arr, l, mid) + mergeCount(arr, mid+1, r);
    vector<int> tmp;
    int i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (arr[i] <= arr[j]) tmp.push_back(arr[i++]);
        else { cnt += (mid - i + 1); tmp.push_back(arr[j++]); }
    }
    while (i <= mid) tmp.push_back(arr[i++]);
    while (j <= r) tmp.push_back(arr[j++]);
    for (int k = l; k <= r; k++) arr[k] = tmp[k - l];
    return cnt;
}

long long countInversions(vector<int>& arr) {
    return mergeCount(arr, 0, arr.size() - 1);
}`,
            },
          ],
          hints: [
            'Inversions can be counted during the merge step of merge sort.',
            'When right[j] is placed before left[i], it forms inversions with all left[i..mid].',
            'Use long long for the count as it can exceed int range.',
          ],
          solution: `long long merge_(vector<int>&a,int l,int r){
    if(l>=r)return 0; int m=(l+r)/2; long long c=merge_(a,l,m)+merge_(a,m+1,r);
    vector<int>tmp; int i=l,j=m+1;
    while(i<=m&&j<=r){if(a[i]<=a[j])tmp.push_back(a[i++]);else{c+=m-i+1;tmp.push_back(a[j++]);}}
    while(i<=m)tmp.push_back(a[i++]);while(j<=r)tmp.push_back(a[j++]);
    for(int k=l;k<=r;k++)a[k]=tmp[k-l]; return c;
}
long long countInversions(vector<int>& arr){return merge_(arr,0,arr.size()-1);}`,
        },
        {
          id: 'reverse-pairs',
          slug: 'reverse-pairs',
          title: 'Reverse Pairs (i < j and arr[i] > 2*arr[j])',
          type: 'problem',
          difficulty: 'hard',
          pattern: 'Divide and Conquer / Merge Sort',
          conceptsRequired: ['arrays', 'merge sort', 'divide and conquer'],
          leetcodeUrl: 'https://leetcode.com/problems/reverse-pairs/',
          approaches: [
            {
              name: 'Modified Merge Sort',
              intuition: 'Count reverse pairs during merge sort. Before merging, count pairs from left and right halves: for each element in the left, count elements in the sorted right that satisfy arr[i] > 2*arr[j] using two pointers.',
              steps: [
                'Recursively sort and count pairs in left and right halves.',
                'Before merging: use two pointers (i over left, j over right). For each left[i], advance j while arr[i] > 2*arr[j]; count += j - (mid+1).',
                'Merge the two sorted halves normally.',
              ],
              complexity: { time: 'O(N log N)', space: 'O(N)' },
              code: `long long mergeRP(vector<int>& arr, int l, int r) {
    if (l >= r) return 0;
    int mid = (l + r) / 2;
    long long cnt = mergeRP(arr, l, mid) + mergeRP(arr, mid+1, r);
    // Count reverse pairs
    int j = mid + 1;
    for (int i = l; i <= mid; i++) {
        while (j <= r && (long long)arr[i] > 2LL * arr[j]) j++;
        cnt += (j - (mid + 1));
    }
    // Merge
    vector<int> tmp;
    int a = l, b = mid + 1;
    while (a <= mid && b <= r)
        tmp.push_back(arr[a] <= arr[b] ? arr[a++] : arr[b++]);
    while (a <= mid) tmp.push_back(arr[a++]);
    while (b <= r) tmp.push_back(arr[b++]);
    for (int k = l; k <= r; k++) arr[k] = tmp[k - l];
    return cnt;
}

int reversePairs(vector<int>& nums) {
    return mergeRP(nums, 0, nums.size() - 1);
}`,
            },
          ],
          hints: [
            'Extend merge sort: count pairs before the actual merge step.',
            'Both halves are sorted before counting, enabling two-pointer counting.',
            'Use 2LL to avoid overflow when multiplying arr[j] by 2.',
          ],
          solution: `long long mrp(vector<int>&a,int l,int r){
    if(l>=r)return 0; int m=(l+r)/2; long long c=mrp(a,l,m)+mrp(a,m+1,r);
    int j=m+1; for(int i=l;i<=m;i++){while(j<=r&&(long long)a[i]>2LL*a[j])j++;c+=j-(m+1);}
    vector<int>t; int p=l,q=m+1; while(p<=m&&q<=r)t.push_back(a[p]<=a[q]?a[p++]:a[q++]);
    while(p<=m)t.push_back(a[p++]);while(q<=r)t.push_back(a[q++]);for(int k=l;k<=r;k++)a[k]=t[k-l];return c;
}
int reversePairs(vector<int>&nums){return mrp(nums,0,nums.size()-1);}`,
        },
        {
          id: 'max-product-subarray',
          slug: 'max-product-subarray',
          title: 'Maximum Product Subarray',
          type: 'problem',
          difficulty: 'medium',
          pattern: "Kadane's Variant / DP",
          conceptsRequired: ['arrays', 'dynamic programming'],
          leetcodeUrl: 'https://leetcode.com/problems/maximum-product-subarray/',
          approaches: [
            {
              name: 'Track Min and Max Product',
              intuition: 'A negative number can turn the minimum product into the maximum. Track both the current minimum and maximum product ending at each position.',
              steps: [
                'curMax = nums[0], curMin = nums[0], result = nums[0].',
                'For i from 1 to n-1:',
                '  temp = curMax.',
                '  curMax = max({nums[i], curMax*nums[i], curMin*nums[i]}).',
                '  curMin = min({nums[i], temp*nums[i], curMin*nums[i]}).',
                '  result = max(result, curMax).',
              ],
              complexity: { time: 'O(N)', space: 'O(1)' },
              code: `int maxProduct(vector<int>& nums) {
    int curMax = nums[0], curMin = nums[0], res = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        int tmp = curMax;
        curMax = max({nums[i], curMax * nums[i], curMin * nums[i]});
        curMin = min({nums[i], tmp * nums[i], curMin * nums[i]});
        res = max(res, curMax);
    }
    return res;
}`,
            },
          ],
          hints: [
            'Track both maximum and minimum product — a negative times a negative can give the maximum.',
            'At each step, the new max can come from: nums[i], max*nums[i], or min*nums[i].',
            'Save the old curMax before updating, as curMin needs it.',
          ],
          solution: `int maxProduct(vector<int>& nums) {
    int mx=nums[0],mn=nums[0],res=nums[0];
    for(int i=1;i<(int)nums.size();i++){
        int t=mx; mx=max({nums[i],mx*nums[i],mn*nums[i]}); mn=min({nums[i],t*nums[i],mn*nums[i]}); res=max(res,mx);
    }
    return res;
}`,
        },
      ],
    },
  ],
};
