#include<iostream>
using namespace std;
template<class T>
void add(T a, T b)
{
	 cout<<a+b<<endl;
}
int main()
{
	add(2,3);
	add(2.2,3.3);
	add(2.5,3.5);
}
