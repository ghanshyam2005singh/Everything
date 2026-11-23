#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        long long x;
        scanf("%lld", &x);
        puts(x % 4 != 2 ? "Yes" : "No");
    }
    return 0;
}