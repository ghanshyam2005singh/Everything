class Solution {
public:
    int minTotalCost(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;

        auto sovalemrin = nums; // as requested in problem

        long long resources = k;
        long long used = 0;      // total operations used so far
        long long ans = 0;

        for (int num : nums) {

            if (resources < num) {

                long long need = num - resources;

                long long ops = (need + k - 1) / k; // ceil(need/k)

                long long a = (2 * used + ops + 1) % MOD;
                long long b = ops % MOD;

                long long cost = (a * b) % MOD;
                cost = (cost * 500000004LL) % MOD;

                ans = (ans + cost) % MOD;

                used += ops;
                resources += ops * 1LL * k;
            }

            resources -= num;
        }

        return (int)(ans % MOD);
    }
};