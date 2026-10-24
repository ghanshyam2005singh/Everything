class Solution {
public:
    int minOperations(string s) {
        char maxx='a', minn='z';
        int n=s.length();
        for (int i=0; i<n; i++) {
            maxx = max(maxx, s[i]);
            minn = min(minn, s[i]);
        }
        if (ranges::is_sorted(s)) {
            return 0;
        }
        if (n== 2) {
            return -1;
        }
        if (s[0]==minn || s[n-1] == maxx) {
            return 1;
        }
        for (int i=1; i<n-1; i++) {
            if (s[i]==minn || s[i]==maxx) {
                return 2;
            }
        }
        return 3;
    }
};