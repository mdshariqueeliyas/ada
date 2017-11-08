#include<bits/stdc++.h>
using namespace std;
int ECULID(int a, int b, int *x, int *y)
{
    if (a == 0)
    {
        *x = 0;
        *y = 1;
         cout<<a<<" "<<b<<" "<<b<<" "<<" "<<*x<<" "<<" "<<*y<<endl;
        return b;
    }
 
    int x1, y1;
    int gc = ECULID(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;
    cout<<a<<" "<<b<<" "<<gc<<" "<<" "<<*x<<" "<<" "<<*y<<endl;
    return gc;
}
int main()
{
   int A,B,x,y;
   cin>>A>>B;
   cout<<"A"<<" " <<"B"<<" "<<"gc"<<" "<<"x"<<" "<<"y"<<endl;
   int gc=ECULID(A,B,&x,&y);
   cout<<"gcd of A and B = "<<gc<<endl;
   cout<<"val of x : "<<x<<endl;
   cout<<"val of y : "<<y<<endl;
}

