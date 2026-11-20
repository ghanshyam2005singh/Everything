class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int count=0;
        for(int x: arr1){
            bool ok=true;
            for(int y: arr2){
                ok &= (abs(x-y)>d);
            }
            count+=ok;
        }
        return count;
    }
};