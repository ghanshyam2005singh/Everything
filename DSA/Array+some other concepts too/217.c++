// Extra space with sort, time complexity O(nlogn) 
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]==nums[i+1]) return true;
        }
        return false;
    }
};

//using set time complexity O(n) and space complexity O(n)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>seen;
        for(int num: nums){
            if(seen.count(num)){
            return true;
            }
        seen.insert(num);
        }
        return false;
    }
};