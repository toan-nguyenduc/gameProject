//Con tro chua khoi tao
/*#include<iostream>

using namespace std;

int main()
{
    int *pX;
    cout<<pX<<endl;
    cout<<*pX;
    *pX=0;
    return 0;
}*/

//Truy nhap con tro Null
/*#include<iostream>

using namespace std;

int main()
{
    int *pX = NULL;
    cout<<pX<<endl;
    cout<<*pX;
    *pX=0;
    return 0;
}*/

//Loi dangling references
/*#include<iostream>

using namespace std;

int* weird_sum(int a, int b){
	int c;
	c= a+b;
	return &c;
}

int main()
{
    int a=1,b=2;
    int* sum=weird_sum(a,b);
    cout<<*sum;
}*/
