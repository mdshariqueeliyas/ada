
#include<bits/stdc++.h>
using namespace std;

typedef complex<double> Complex;
const double PI = 3.141592653589793238460;

int reverseBits(int num)
{
    unsigned int count = sizeof(num) * 8 - 1;
    unsigned int reverse_num = num;
     
    num >>= 1;
    while(num)
    {
       reverse_num <<= 1;      
       reverse_num |= num & 1;
       num >>= 1;
       count--;
    }
    reverse_num <<= count;
    return reverse_num;
}

valarray<Complex> ifft(valarray<Complex> primal,int absP)
{
    int i,j,k,p,n = primal.size(),offset;
    valarray<Complex> dual(n);
    for(i = 0;i<n;i++)
    {
        dual[i] = primal[reverseBits(i)>>(32-absP)];
    }
    for(p = 1;p<=absP;p++)
    {
        int unityStep = (1<<p);
        double theta = 2*M_PI/unityStep;
        Complex unityRoot(cos(theta),sin(theta));
        for(offset = 0;offset<n;offset += unityStep)
        {
            Complex omega = 1;
            for(k = 0;k<unityStep/2;k++)
            {
                Complex u = dual[offset+k];
                Complex t = omega*dual[offset+k+unityStep/2];
                omega = omega*unityRoot;
                dual[offset+k] = u+t;
                dual[offset+k+unityStep/2] = u-t;
            }
        }
    }
    return dual;
}

int main()
{
    
    double n,i,j,k;
    cout<<"Enter no. of coefficients\n";
    cin>>n;
    valarray<Complex> primal(n);
    for(i = 0;i<n;i++)
    {
        primal[i] = 1+rand()%100;
    }
    //cout<<"Input done\n";
    int p = log2(n);
    //cout<<p<<"\n";
    if(pow(2,p) != n)
    {
        cout<<"n should be power of 2\n";
        exit(1);
    }
    
    valarray<Complex> y = ifft(primal,p);
    //cout<<"Here";
    for(i = 0;i<n;i++)
    {
        cout<<y[i]<<"\n";
    }
}


