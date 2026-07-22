class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>result;
        for(string op: operations){
            if(op=="C"){
                result.pop();
            } else if (op=="D"){
                result.push(result.top()*2);
            } else if(op=="+"){
                int first=result.top();
                result.pop();
                int second=result.top();
                result.push(first);
                result.push(first+second);
            } else {
                result.push(stoi(op));
            }
        }
        int sum=0;
        while(!result.empty()){
            sum+=result.top();
            result.pop();
        }
        return sum;
    }
};