#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin>>n;
        string s;
        cin >> s;
        stack<int> st;
        vector<bool> printed(n + 1, false);
        for (int i = 0; i < n; i++) {
            int doc = i + 1;
            if (s[i]=='1'){
                st.push(doc);
            }
            else if (s[i] == '2') {
                if (!st.empty()) {
                    int topDoc = st.top();
                    st.pop();
                    printed[topDoc] = true;
                }
                else{
                    printed[doc] = true;
                }
            }
            else {
                printed[doc] = true;
            }
        }
        vector<int> notPrinted;
        for (int i = 1; i <= n; i++) {
            if (!printed[i]) {
                notPrinted.push_back(i);
            }
        }
        cout << notPrinted.size() << '\n';
        for (int doc : notPrinted) {
            cout << doc << ' ';
        }
        cout << '\n';
    }
    return 0;
}