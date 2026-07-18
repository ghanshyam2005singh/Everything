class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size()-1;
        return nums[0]^nums[n];
    }
};