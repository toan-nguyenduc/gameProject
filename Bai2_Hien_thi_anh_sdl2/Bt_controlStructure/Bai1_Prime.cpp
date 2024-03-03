#include<iostream>

using namespace std;

bool prime(int n)
{
    if(n<2) return false;
    if(n<4) return true;
    for(int i=2; i<=n/2; i++)
    {
        if(n % i==0) return false;
    }
    return true;
}

int main(){
    int n; cin >> n;
    if(prime(n)==0) cout<<"no";
    else cout<<"yes";
}