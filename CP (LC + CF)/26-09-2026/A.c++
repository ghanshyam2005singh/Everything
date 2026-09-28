#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        long long ans = (1LL << (n - k + 1)) + 2LL * (k - 1);

        cout << ans << '\n';
    }

    return 0;
}