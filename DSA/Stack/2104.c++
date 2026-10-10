// Monotonic stack solution

class Solution {
public:
    long long sumMax(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n), right(n);
        stack<int> st;

        // Previous strictly greater element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }

            left[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next greater than or equal element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }

            right[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            ans += 1LL * nums[i] * left[i] * right[i];
        }

        return ans;
    }

    long long sumMin(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n), right(n);
        stack<int> st;

        // Previous strictly smaller element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }

            left[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next smaller than or equal element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }

            right[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            ans += 1LL * nums[i] * left[i] * right[i];
        }

        return ans;
    }

    long long subArrayRanges(vector<int>& nums) {
        return sumMax(nums) - sumMin(nums);
    }
};