#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    string s; cin >>s;
    bool check=true;
    /*if(s.size() % 2==0){
        for(int i=0; i<=s.size()/2; i++){
            if(s[i] != s[s.size()-i-1]){
                check=false;
                break;
            }
        }
    }
    else{*/
        for(int i=0; i<s.size()/2; i++){
            if(s[i] != s[s.size()-i-1]){
                check=false;
                break;
            }
        }
    if(!check) cout<<"No";
    else cout<<"Yes";

}
