#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a,b;
    getline(cin,a);
    getline(cin,b);
    int count=0;
    int i=0;
    while(a.size()+i <= b.size()){
        string s=b.substr(i,a.size()+i);
        if(strcmp(s.c_str(),a.c_str())==0) count++;
        i++;
    }
    cout<<count;
}
