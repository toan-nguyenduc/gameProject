#include<iostream>
#include<ctime>

using namespace std;

int main()
{
    int a[20];
    srand( time(NULL));
    for(int i=0; i<20; i++){
            a[i]=rand()%100;
    }
    //chua sap xep
    for(int i:a){
        cout<<i<<" ";
    }
    cout<<endl;

    //sau khi sap xep
    for(int i=0; i<20; i++){
        for(int j=i+1; j<20; j++){
            if(a[j] <a[i]){
                swap(a[i],a[j]);
            }
        }
    }

    for(int i=0; i<20; i++){
        cout<<a[i]<<" ";
    }
}
