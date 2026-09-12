class solution{
    public:
    int maxProduct(vector<int>&nums){
        int currentMax=nums[0];
        int currentMin=nums[0];
        int ans=nums[0];
        for(int i=1; i<nums.size(); i++){
            int num=nums[i];
            int oldMin=currentMin;
            int oldMax=currentMax;
            currentMax=max(nums, max(oldMin*num, oldMax*num));
            currentMin=min(nums, min(oldMin*num, oldMax*num));
            ans=max(ans, currentMax);
        }
        return ans;
    }
}