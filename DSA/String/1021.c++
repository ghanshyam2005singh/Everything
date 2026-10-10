class Solution {
    public:
    string removeOuterParatheses(string s){
        string result="";
        int depth=0;
        for(char c: s){
            if(c=='('){
                if(depth>0) result+=c;
                depht++;
            } else {
                depht--;
                if(dephth>0) result+=c;
            }
        }
        return result;
    }
}