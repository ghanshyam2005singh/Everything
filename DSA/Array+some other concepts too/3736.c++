class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum=0;
        int mx=*max_element(nums.begin(), nums.end());
        for(int x: nums){
            sum+=abs(x-mx);
        }
        return sum;
    }
};