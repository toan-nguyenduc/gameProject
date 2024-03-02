#include<iostream>

using namespace std;

struct Point
{
	int x, y;


};
void print( Point a)
	{
		cout<<a.x<<" "<<a.y;
	}

Point mid_point(const Point a, const Point b)
{
	Point res;
	res.x= (a.x + b.x)/2;
	res.y= (a.y + b.y)/2;
	return res;
}
int main(int argc, char const *argv[])
{
	Point point;
	point.x=10;
	point.y=12;
	print(point);
	cout<<endl;
	Point point2;
	point2.x=20; point2.y=18;
	print(mid_point(point,point2) );
	return 0;
}