#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,a1,a2,a3;
        cin>>n>>a1>>a2>>a3;
        int strong=min({a1,a2,a3});
        cout<<n-strong<<"\n";
    }
    return 0;
}