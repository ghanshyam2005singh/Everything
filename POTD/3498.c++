//to find reverse place 'z'-c+1 where c is the character in the string

class Solution {
public:
    int reverseDegree(string s) {
        int sum=0;
        for(int i=0; i<s.length(); i++){
            int reversed='z'-s[i]+1;
            int index=i+1;
            sum+=reversed*index;
        }
        return sum;
    }
};