class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b){
            return abs(a)<abs(b);
        });
        int n=nums.size();
        long long smallSum=0;
        long long bigSum=0;
        for(int i=0; i<n/2; i++){
            long long smallSquare= 1LL*nums[i]*nums[i];
            smallSum+=smallSquare;
        }
        for(int i=n/2; i<n; i++){
            long long bigSquare= 1LL*nums[i]*nums[i];
            bigSum+=bigSquare;
        }
        return bigSum-smallSum;
    }
};


class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return abs(a) < abs(b);
        });

        int n = nums.size();
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            long long square = 1LL * nums[i] * nums[i];

            if (i < n / 2)
                ans -= square;
            else
                ans += square;
        }
        return ans;
    }
};
