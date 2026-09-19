class Solution {
public:
    int totalNumbers(vector<int>& digits) {
       int freq[10]={};
       for(int d:digits){
        freq[d]++;
       }
       int ans=0;
       for(int n=100; n<=999; n++){
        if(n%2!=0)
        continue;
        int a=n/100;
        int b=(n/10)%10;
        int c=n%10;
        int need[10]={};
        need[a]++;
        need[b]++;
        need[c]++;
        bool possible = true;
        for(int d=0; d<=9; d++){
            if(need[d]>freq[d]){
                possible=false;
                break;
            }
        }
        if(possible)
        ans++;
       }
       return ans;
    }
};