#include<iostream>

using namespace std;

void print(int n){
    for(int i=1; i<n; i++) cout<<" ";
}

int main()
{
   int n; cin >> n;
   string s="*";
    while(n!=0){
        print(n);
        cout<<s<<endl;
        s+="**";
        n--;
    }
}