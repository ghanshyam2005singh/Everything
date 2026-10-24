#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        int minn=INT_MAX;
        for (int i=0; i<n; i++) {
            int x;
            scanf("%d", &x);
            minn=min(minn, x);
        }
        printf("%d\n", minn<= n-1 ? n : 0);
    }
    return 0;
}