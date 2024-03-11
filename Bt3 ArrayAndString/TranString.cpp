#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    string s[3];
    for(int i=0; i<3; i++){
        cin>>s[i];
    }
    for(int i=0; i<3; i++) cout<<s[i];
    cout<<"_"<<endl;
}
