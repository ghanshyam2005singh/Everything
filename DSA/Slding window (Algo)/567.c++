class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        if(n>m) return false;
        vector<int>need(26,0);
        vector<int>window(26,0);
        for(char c:s1)
        need[c-'a']++;
        for(int i=0; i<n; i++)
            window[s2[i]-'a']++;
            if(need==window)
            return true;
            for(int i=n; i<m; i++){
                window[s2[i]-'a']++;
                window[s2[i-n]-'a']--;
                if(need==window)
                return true;
            }
        return false;
    }
};