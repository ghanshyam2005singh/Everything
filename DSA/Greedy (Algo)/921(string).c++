class Solution {
public:
    int minAddToMakeValid(string s) {
        int count=0;
        int ans=0;
        for(char c: s){
            if(c=='('){
                count++;
            } else if(c==')' && count>0) {
                count--;
            } else {
                ans++;
            }
        }
        return count+ans;
    }
};