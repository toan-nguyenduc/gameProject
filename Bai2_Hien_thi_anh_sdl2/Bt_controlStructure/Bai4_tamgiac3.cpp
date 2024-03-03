#include<iostream>

using namespace std;

void print(int n){
    for(int i=0; i<n; i++) cout<<" ";
}

void print1(int n){
    for(int i=1; i<=n; i++) cout<<'*';
    cout<<endl;
}

int main()
{
    int n; cin >> n;
    string s="";
    for(int i=0; i<n; i++) s+="*"; 
    int step=n;
    while(n != 0){
        print(step-n);
        print1(n*2-1);
        n--;
    }
}