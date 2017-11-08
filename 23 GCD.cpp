#include<bits/stdc++.h>
using namespace std;
int Euclid(int a, int b)
{
return (b == 0 ? a : __gcd(b, a % b));
}
int main()
{
 int a,b;
 cin>>a>>b;
 cout<<Euclid(a,b)<<endl;
}
