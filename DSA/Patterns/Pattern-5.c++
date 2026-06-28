// Inverted right angle triangle

#include <bits/stdc++.h> // <iostream>
using namespace std;

void invertedStar(int n){
for (int i=n; i>0; i--){
    for(int j=0; j<i; j++){
        cout<<"*";
    }
    cout<<endl;
}
}

int main () {
    int n=4;
    invertedStar(n);
    return 0;
}