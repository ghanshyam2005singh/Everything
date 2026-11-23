#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        vector<int> p(n + 2), L(n + 2), R(n + 2);
        for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
        vector<int> st;
        for (int i = 1; i <= n; i++) {
            while (!st.empty() && p[st.back()] > p[i]) st.pop_back();
            L[i] = st.empty() ? 0 : st.back();
            st.push_back(i);
        }
        st.clear();
        for (int i = n; i >= 1; i--) {
            while (!st.empty() && p[st.back()] > p[i]) st.pop_back();
            R[i] = st.empty() ? n + 1 : st.back();
            st.push_back(i);
        }
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            long long A = i - L[i], B = R[i] - i;
            if (min(A, B) == 1) ans += max(A, B);
            else ans += 2;
        }
        printf("%lld\n", ans);
    }
    return 0;
}