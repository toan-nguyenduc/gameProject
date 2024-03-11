#include<iostream>

using namespace std;

int main()
{
    //input
    int n; cin >>n;
    int a[n][n];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            a[i][j]=0;
        }
    }
    a[0][n/2]=1;
    int dem=2;
    int i=0,j=n/2;

    //write code
    while(dem <= n*n){
        if(i==0){
            if(j<n-1){
                i=n-1;
                j++;
            }
            else{
                i++;
            }
        }
        else if(j==n-1){
            i--;
            j=0;
        }
        else if(a[i-1][j+1] != 0){
            i++;
        }
        else{
            i--;
            j++;
        }
        if(a[i][j]==0){
            a[i][j]=dem;
            dem++;
        }
    }

    //print
   for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<'\n';
    }
}
