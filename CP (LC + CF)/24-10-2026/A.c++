#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, k;
        scanf("%d %d", &n, &k);
        vector<int> count(n+2, 0);
        for (int i=0; i<n; i++) {
            int x;
            scanf("%d", &x);
            count[x]++;
        }
        int ans=0, pref=0;
        for (int v=0; v<=n; v++) {
            pref+=count[v];
            if(count[v]>=1 && pref>=k*(v+1)) ans=v+1;
            else break;
        }
        printf("%d\n", ans);
    }
    return 0;
}