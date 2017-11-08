#include<bits/stdc++.h>
using namespace std;

const double pi = 3.14159;

void fastfourierTrans(valarray<complex<double> > &x)
{
    int n = x.size();
    
    if(n<=1) return;
    
    valarray<complex<double> > CAE = x[slice(0,n/2,2)];
    valarray<complex<double> > CAO = x[slice(1,n/2,2)];
    
    fastfourierTrans(CAE);
    fastfourierTrans(CAO);
    
    for(int k=0;k<n/2;k++)
    {
        complex<double> t = polar(1.0,-2*pi*k/(double)n)*CAO[k];
        x[k] = CAE[k] + t;
        x[k+n/2] = CAE[k] - t;
    }
}

int main()
{
    int n;
    cin>>n;
    
    complex<double> in[n];
    double x;
    for(int i=0;i<n;i++)
    {
        cin>>in[i];
    }
    
    valarray<complex<double> > CA(in,n);
    
    fastfourierTrans(CA);
    
    for(int i=0;i<n;i++)
    {
        cout<<CA[i]<<endl;
    }
}
