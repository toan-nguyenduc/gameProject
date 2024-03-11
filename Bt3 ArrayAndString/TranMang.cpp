#include<iostream>
using namespace std;

int main()
{   int n=4;
    //char a[-1]={'a','b','c','d'};
    char a[n+1]={'a','b','c','d'};

    char b[3][4];
    for(int i=0; i<5; i++){
        for(int j=0; j<4; i++){
            b[i][j]='a';
        }
    }

    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }


}
