#include<stdio.h>
#include<iostream>
using namespace std;
class complex{
	private:
		int real,img;
	public:	
	complex()
	{
	}
	complex(float r, float i)
	{
		real=r;
		img=i;
	}
	void getvalues(float r,float i)
	{
		real=r;
		img=i;
	}
	void getdata()
	{
		float r,i;
		cout<<"enter value of real and img part of complex no."<<"\n";
		cin>>r>>i;
		real=r;
		img=i;
	}
	void add(complex c1,complex c2)
	{
		real=c1.real+c2.real;
		img=c1.img+c2.img;
	}
	void multi(complex c1,complex c2)
	{
		real=c1.real*c2.real-c1.img*c2.img;
		img=c1.real*c2.img+c1.img*c2.real;
	}
	~complex()
	{
	}
	void print()
	{
		cout<<real<<" +i("<<img<<")"<<endl;
	}
};
int main()
{
	complex c1(2.0,1.0),c2(3.0,2.0),c3,c4,c5;
	c3.add(c1,c2);
	c3.print();
	cout<<"Enter values of some other coplex no."<<endl;
	c4.getdata();
	c5.multi(c1,c2);
	c5.print();
	return 0;
}
