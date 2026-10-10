#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 LL;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n; ll k;
        scanf("%d %lld", &n, &k);
        vector<ll> s(n), e(n);
        ll mn = LLONG_MAX;
        for (int i=0; i<n; i++) {
            ll a, b, c;
            scanf("%lld %lld %lld", &a, &b, &c);
            s[i]=a+b+c;
            mn=min(mn, s[i]);
            if (a>b || a>c || b>c) e[i]=-1;
            else if (a==b && b==c) e[i] = -2;
            else {
                ll x=b-a+1;
                if (a<b) x=min(x, c-b+1);
                e[i]=x;
            }
        }
        auto ok = [&](ll T) {
            LL tot=0;
            for (int i=0; i<n; i++) {
                if (T<=s[i]) continue;
                if (e[i]==-2) return false;
                LL cost=T-s[i];
                if (e[i]>0) cost += 2 * (LL)e[i];
                tot+=cost;
                if (tot > k) return false;
            }
            return true;
        };
        ll lo = mn, hi = mn + k;
        while (lo<hi) {
            ll mid=lo+(hi - lo + 1) / 2;
            if (ok(mid)) lo = mid;
            else hi = mid - 1;
        }
        printf("%lld\n", lo);
    }
    return 0;
}