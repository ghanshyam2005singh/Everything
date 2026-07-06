class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-1; i+=2){
            if(nums[i]!=nums[i+1]){
                return nums[i];
        }
        }
        return nums.back();
    }
};

//Optimised solution with XOR

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int x:nums){
            ans^=x;
        }
        return ans;
    }
};

// Example:

// [4,1,2,1,2]

// 0^4^1^2^1^2

// = 4^(1^1)^(2^2)

// = 4^0^0

// = 4