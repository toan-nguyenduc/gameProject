#include<iostream>
using namespace std;

bool searchBinary(int* a, int* B,int n){
    int left=0;
    int right=n;
    while(left < right){
        int mid=(left+right)/2;
        cout<<*(B+mid)<<endl;
        if(*(B+mid) == *a) return true;
        else if(*(B+mid) > *a){
            right=mid-1;
        }
        else left=mid+1;
    }
    return false;
}

int main()
{
    int x;
    cin >> x;
    int A[11]={1,2,3,4,5,5,6,7,8,9,10};
    int* B=A;
    if(searchBinary(&x,B,10)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
}