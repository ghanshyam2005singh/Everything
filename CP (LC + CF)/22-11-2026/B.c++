#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        vector<int> a(n + 2), run(n + 2, 0);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for (int i = n; i >= 1; i--) {
            if (i < n && a[i] == a[i + 1]) run[i] = run[i + 1] + 1;
            else run[i] = 1;
        }
        int w = n - k + 1, ans = 0;
        for (int i = 1; i <= k; i++)
            if (run[i] >= w) ans++;
        printf("%d\n", ans);
    }
    return 0;
}