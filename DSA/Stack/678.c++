class Solution {
public:
    bool checkValidString(string s) {
        int open=0;
        int close=0;
        for(char c: s){
            if(c=='('){
                open++;
                close++;
            } else if(c==')'){
                close--;
                open--;
            } else {
                open++;
                close--;
            }
            if(open<0){
                return false;
            }
            if(close<0){
                close=0;
            }
        }
        
        return close==0;
    }
};