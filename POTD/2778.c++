class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        int product=0;
        for(int i=0; i<n; i++){
            if(n%(i+1)==0){
                product=(nums[i]*nums[i]);
                sum+=product;
            }
        }
        return sum;
    }
};