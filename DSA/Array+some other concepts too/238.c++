class solution {
    public:
    vector<int>productExceptSelf(vector<int>& nums){
        vector<int>ans(n,1);
        int n=nums.size();
        int left=1;
        for(int i=0; i<n; i++){
            ans[i]*=left;
            left[i]*=nums[i];
        }
        int right=1;
        for(int i=n-1; i>=0; i--){
            ans[i]*=right;
            right*nums[i];
        }
        return ans;
    }
}