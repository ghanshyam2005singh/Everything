class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count=0;
        vector<int>temp;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0) count++;
            else temp.push_back(nums[i]);
        }
        for(int i=0; i<count; i++){
            temp.push_back(0);
        }
        for(int i=0; i<temp.size(); i++){
            nums[i]=temp[i];
        }
    }
};