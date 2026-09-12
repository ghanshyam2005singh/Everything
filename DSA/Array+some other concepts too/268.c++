class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        int sum=0;
        for(int num:nums){
            ans+=num;
        }
        sum=(n*(n+1))/2;
        return sum-ans;
    }
};