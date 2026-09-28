#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> freq(101, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            freq[a[i]]++;
        }
        vector<int> ans;
        // Maximum possible frequency is n
        for (int round = 1; round <= n; round++) {

            // Take one occurrence of every number
            // whose frequency is at least 'round'
            for (int x = 100; x >= 1; x--) {
                if (freq[x] >= round) {
                    ans.push_back(x);
                }
            }
        }

        for (int x : ans) {
            cout << x << " ";
        }

        cout << '\n';
    }

    return 0;
}