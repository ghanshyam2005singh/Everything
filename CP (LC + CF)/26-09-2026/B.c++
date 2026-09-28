#include <bits/stdc++.h>
using namespace std;

int digitSquareSum(int x) {
    int sum = 0;

    while (x > 0) {
        int d = x % 10;
        sum += d * d;
        x /= 10;
    }

    return sum;
}

int main() {
    int t;
    cin >> t;

    // root[x] = canonical cycle representative of x
    vector<int> root(811, 0);

    function<int(int)> solve = [&](int x) -> int {
        if (root[x] != 0) {
            return root[x];
        }

        vector<int> path;
        unordered_map<int, int> pos;

        int cur = x;

        while (root[cur] == 0 && !pos.count(cur)) {
            pos[cur] = path.size();
            path.push_back(cur);
            cur = digitSquareSum(cur);
        }

        int r;

        if (root[cur] != 0) {
            r = root[cur];
        } else {
            // cur is inside a cycle.
            r = cur;

            for (int i = pos[cur]; i < path.size(); i++) {
                r = min(r, path[i]);
            }
        }

        for (int v : path) {
            root[v] = r;
        }

        return r;
    };

    while (t--) {
        int n;
        cin >> n;

        unordered_map<int, int> freq;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;

            x = digitSquareSum(x);
            int r = solve(x);

            freq[r]++;
        }

        long long ans = 0;

        for (auto [r, cnt] : freq) {
            ans += 1LL*cnt * (cnt - 1) / 2;
        }

        cout << ans << '\n';
    }

    return 0;
}