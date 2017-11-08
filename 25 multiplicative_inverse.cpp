#include<iostream>
using namespace std;

int gcdExtended(int a,int b,int &x,int &y)
{
	int x1,y1;

	if(a==0)
	{
	x = 0;y = 1;
	return b;
	}
	int gcd = gcdExtended(b%a,a,x1,y1);

	x = y1 - (b/a)*x1;
	y = x1;

	return gcd;
}

int main()
{
	int a,n;
	
	cin>>a>>n;
	
	int x,y;
	int g = gcdExtended(a,n,x,y);

	if(g!=1)
	cout<<"Multiplicative Inverse doesn't exist"<<endl;
	else
	cout<<(x%n+n)%n<<endl;
	
	return 0;
}
