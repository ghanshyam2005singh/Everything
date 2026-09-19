#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
    int ones=0;
    for(int i=0; i<x; i++){
        int n;
        cin>>n;
        ones+=n;
    }
    if(ones>=(x+1)/2)
    cout<<"Bessie\n";
    else
    cout<<"Elsie\n";
}
return 0;
}