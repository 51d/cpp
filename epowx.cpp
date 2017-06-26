#include<iostream>
#include<math.h>
using namespace std;
class evaluate{
	private:
		int x,n,fac;
		float e;
	public:
		evaluate()
		{
		};
		evaluate(int a,int b)
		{
			x=a;
			n=b;
		}
		void solve()
		{
			int i;
			fac=1;
			for(i=2;i<n;i++)
			{
				fac=fac*i;
				e+=pow(x,n)/fac;
			}
			cout<<e<<endl;
		}
};
int main()
{
	evaluate e1(2,1);
	e1.solve();
}
