#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        long long a,b,c;
        cin>>a>>b>>c;
        long long d=a-b;
        cout<<max(abs(d), abs(d+c))<<'\n';
    }
    return 0;
}