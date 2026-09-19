// Inverted Pyramid

#include<iostream>
using namespace std;

void invertedPyramid(int n){
    for(int i=n; i>0; i--){
        for(int j=1; j<=n-i; j++) cout<<" ";
        for(int j=1; j<=i; j++) cout<<"* ";
        cout<<"\n";
    }
}

int main(){
    int n=4;
    invertedPyramid(n);
    return 0;
}