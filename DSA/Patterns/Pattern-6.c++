// Inverted Number Triangle
// 1 2 3 4
// 1 2 3
// 1 2
// 1

#include <bits/stdc++.h> //#includ<iostream>
using namespace std;

// void invertedTriangle (int n){
//     for(int i=n; i>0; i--){
//         for(int j=1; j<i; j++){
//             cout<<j;
//         }
//         cout<<endl;
//     }
// }

// int main(){
//     int n=4;
//     invertedTriangle(n);
//     return 0;
// }

// 4 3 2 1
// 321
//21
//1
void invertedTriangle(int n){
    for(int i=n; i>0; i--){
        for(int j=i; j>0; j--){
            cout<<j;
        }
        cout<<endl;
    }
}

int main(){
    int n=4;
    invertedTriangle(n);
    return 0;
}