#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    const int OFF = 30000;
    vector<int> cnt(2 * OFF + 1, 0);
    while (t--) {
        int n;
        scanf("%d", &n);
        vector<int> a(n);
        for (auto &x : a) scanf("%d", &x);
        int m = n - 4;
        vector<int> v(m);
        long long ans = 0;
        for (int i = 0; i < m; i++) {
            v[i] = a[i] + a[i + 2] - a[i + 4];
            ans += cnt[v[i] + OFF];
            cnt[v[i] + OFF]++;
        }
        for (int i = 0; i < m; i++) {
            if (i + 2 < m && v[i] == v[i + 2]) ans--;
            if (i + 4 < m && v[i] == v[i + 4]) ans--;
        }
        for (int i = 0; i < m; i++) cnt[v[i] + OFF] = 0;
        printf("%lld\n", ans);
    }
    return 0;
}