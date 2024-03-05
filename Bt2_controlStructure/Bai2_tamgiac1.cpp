#include<iostream>

using namespace std;

void print(int n){
    for(int i=0; i<n; i++) cout<<"*";
}

void print1(int n){
    for(int i=0; i<n; i++) cout<<" ";
}
int main()
{
 int n; cin >> n;
 int x=n;
 while(n!= 0){
    print1(x-n);
    print(n);
    cout<<endl;
    n--;
 }   
}