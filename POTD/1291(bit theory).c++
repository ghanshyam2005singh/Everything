class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s="123456789";
        vector<int>ans;
        for(int len=2; len<=9; len++){
            for(int start=0; start+len<=9; start++){
                int num=stoi(s.substr(start, len));
                if(num>=low && num<=high){
                    ans.push_back(num);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

// Things you should learn from this code

// substr(start, length)
// string s = "123456789";

// s.substr(2,3);

// Start at index 2:

// 1 2 3 4 5 6 7 8 9
//     ^

// Take 3 characters:

// 345

// Returns:

// "345"
// 2. stoi()

// String → Integer

// stoi("345")

// returns

// 345
// Complexity

// At most:

// 8 + 7 + 6 + ... + 1
// = 36 numbers

// So:

// O(1)

// effectively constant time.