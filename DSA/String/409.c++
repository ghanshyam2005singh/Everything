class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> frequencyMap;
        for (char c : s) {
            frequencyMap[c]++;
        }
        int res = 0;
        bool hasOddFrequency = false;
        for (auto& entry : frequencyMap) {
            int freq = entry.second;
            if (freq%2==0) {
                res += freq;
            } else {
                res += freq - 1;
                hasOddFrequency = true;
            }
        }
        if (hasOddFrequency) return res+1;
        return res;
    }
};