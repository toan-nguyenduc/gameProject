#include<bits/stdc++.h>
using namespace std;

int main()
{
int* p = new int;
int* p2 = p;
*p = 10;
delete p;  //khong gan cho p =nullptr
*p2 = 100; // lỗi gán giá trị cho vùng nhớ đã giải phóng 
cout << *p2 <<endl; 
delete p2;
}