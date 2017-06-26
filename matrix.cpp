#include<iostream>
#include<stdio.h>
using namespace std;
struct matrix{
	int arr[3][3];
};
matrix operator+(matrix,matrix);
matrix operator-(matrix,matrix);
matrix operator*(matrix,matrix);
void print(matrix c);
int main()
{
	matrix a={
			1,2,3,
			4,5,6,
			7,8,9};
	matrix b={
			1,2,3,
			4,5,6,
			7,8,9};
	matrix c,d,e;
	c=a+b;
	print(c);
	d=a-b;
	print(d);
	e=a*b;
	print(e);
	return 0;
}
matrix operator+(matrix a,matrix b)
{
	matrix c;
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			c.arr[i][j]=a.arr[i][j]+b.arr[i][j];
		}
	}
	return c;
}
matrix operator-(matrix a,matrix b)
{
	matrix c;
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			c.arr[i][j]=a.arr[i][j]-b.arr[i][j];
		}
	}
	return c;
}
matrix operator*(matrix a,matrix b)
{
	matrix c;
	int i,j,k;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			c.arr[i][j]=0;
			for(k=0;k<3;k++)
			{
				c.arr[i][j] += a.arr[i][k]*b.arr[k][j];
			}
		}
	}
	return c;
}
void print(matrix c)
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			cout<<c.arr[i][j]<<"	";
		}
		cout<<"\n";
	}
	cout<<"\n";
}
