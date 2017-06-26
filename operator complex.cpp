#include<iostream>
using namespace std;
class op_com{
	private:
		int real, img;
	public:
		op_com()
		{
		};
		op_com(int a, int b)
		{
			real=a;
			img=b;
		}
		 void operator+(op_com c)
		 {
		 	op_com t;
		 	t.real=real+c.real;
		 	t.img=img+c.img;
		 	cout<<t.real<<"+i("<<t.img<<")"<<endl;
		 }
		 void operator-(op_com c)
		 {
		 	op_com t;
		 	t.real=real-c.real;
		 	t.img=img-c.img;
		 	cout<<t.real<<"+i("<<t.img<<")"<<endl;
		 }
		 void operator=(op_com c)
		 {
		 	if(real==c.real && img==c.img)
		 		cout<<"equal"<<endl;
		 	else
				cout<<"not equal;"<<endl;
		 }
};
int main()
{
	op_com c1(1,2),c2(4,5),c3(1,2);
	c1+c2;
	c1-c2;
	c1=c2;
	c1=c3;
}
