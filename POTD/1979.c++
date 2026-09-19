class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size()-1;
        return gcd(nums[0], nums[n]);
    }
};

// sorting cost 0(nlogn)
// we only need min and max, so we can do it in O(n) time complexity

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mn=*min_element(nums.begin(), nums.end());
        int mx=*max_element(nums.begin(), nums.end());
        return gcd(mn, mx);
    }
};