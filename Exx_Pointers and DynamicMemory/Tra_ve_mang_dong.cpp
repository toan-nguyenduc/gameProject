#include<bits/stdc++.h>
using namespace std;

char* concat(const char* a, const char* b)
{
    char* res = new char[strlen(a)+strlen(b)];
    strcpy(res,a);
    strcat(res,b);
    return res;
}

int main()
{
    char a[]="Hello";
    char b[]="World";
    char* s = concat(a,b);
    cout<<(void*)&(*(s+4))<<endl<<*(s+4);
}