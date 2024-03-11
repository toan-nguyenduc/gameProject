#include<iostream>
#include<cstring>

using namespace std;
string s;
//char c[3]="abcs";
char c[5]="abcs";
char a[]="abc555";
int main()
{
cout<<s<<endl;
for(int i=0; i<s.size();i++) cout<<s[i];
cout<<endl;
for(int i=0; i<5; i++) cout<<c[i];
cout<<endl;
cout<<sizeof(a);
}
