class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>temp=arr;
        sort(temp.begin(), temp.end());
        unordered_map<int, int> rank;
        int r=1;
        for(int num: temp){
            if(rank.find(num)==rank.end()){
                rank[num]=r;
                r++;
            }
        }
        for(int i=0; i<arr.size(); i++){
            arr[i]=rank[arr[i]];
        }
        return arr;
    }
};

// New things you should learn
// unordered_map<int,int>

// Think of it like:

// key -> value

// Example:

// unordered_map<int,int> mp;

// mp[10] = 1;
// mp[20] = 2;

// Now:

// mp[10]

// returns:

// 1
// rank.find(num)

// Checks if key exists.

// Example:

// mp.find(10)

// Found.

// But:

// mp.find(50)

// Not found.

// Then:

// mp.find(50) == mp.end()

// is true.

// Meaning:

// 50 does not exist in map
// Range-based for loop

// You often ask about:

// for(int num : temp)

// This means:

// Take every element of temp one by one
// Store it in variable num

// Equivalent to:

// for(int i = 0; i < temp.size(); i++) {
//     int num = temp[i];
// }

// Just shorter.

// Complexity

// Sorting:

// O(n log n)

// Map operations:

// O(n)

// Total:

// O(n log n)

// which is optimal for this problem.