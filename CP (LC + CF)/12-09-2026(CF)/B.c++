#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        if (k<n || k>2*n-1) {
            cout<<-1<<'\n';
            continue;
        }
        vector<vector<int>> a(n, vector<int>(n, 0));
        vector<bool> used(n * n + 1, false);
        for (int i = 0; i < n; i++) {
            a[i][0] = i + 1;
            used[i + 1] = true;
        }
        int extra = k-n;
        for (int j=0; j<extra; j++) {
            int val = n + j + 1;
            a[0][j + 1] = val;
            used[val] = true;
        }
        int cur = n * n;
        for (int i=0; i<n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == 0) {
                    while (used[cur]) {
                        cur--;
                    }
                    a[i][j] = cur;
                    used[cur] = true;
                    cur--;
                }
            }
        }
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                cout<<a[i][j]<< " ";
            }
            cout<<'\n';
        }
    }
    return 0;
}