// Check if array is sorted and rotated
class Solution {
    public:
    bool sortedAndRotatedArray(vector<int> nums){
        int count=0;
        int n=nums.size();
        for(int i=0; i<n; i++){
            if (nums[i]<nums[i+1]){
              n++;
            } else {
              count++;
              n++;
            }
        }
        return count<=1;
    }
}