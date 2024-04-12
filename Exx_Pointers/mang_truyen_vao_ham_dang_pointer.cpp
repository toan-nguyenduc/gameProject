#include<iostream>

using namespace std;

int f(int* a){
	return sizeof(a);
}

int main()
{
    int A[5]={1,2,3,4,5};
    int B[]={1,2,3,4,5,6,7};
    cout<<sizeof(A)<<endl;
    cout<<f(A)<<endl;
    cout<<sizeof(B)<<endl;
    cout<<f(B);
}
