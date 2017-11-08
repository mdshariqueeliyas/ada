#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,i,k,j,p;
    float a[10][10],l[10][10]={0},u[10][10]={0},sum;
    cin>>n;
    for(i=1;i<=n;i++) for(j=1;j<=n;j++) cin>>a[i][j];
    for(k=1;k<=n;k++)
    {   u[k][k]=1;
        for(i=k;i<=n;i++)
        {   sum=0;
            for(p=1;p<=k-1;p++)
                sum+=l[i][p]*u[p][k];
            l[i][k]=a[i][k]-sum;
        }
        for(j=k+1;j<=n;j++)
        {   sum=0;
            for(p=1;p<=k-1;p++)
                sum+=l[k][p]*u[p][j];
            u[k][j]=(a[k][j]-sum)/l[k][k];
        }
    }
    for(i=1;i<=n;i++)
    {   for(j=1;j<=n;j++)
            cout<<l[i][j]<<"  ";
        cout<<endl;
    }
    cout<<endl;
    for(i=1;i<=n;i++)
    {   for(j=1;j<=n;j++)
            cout<<u[i][j]<<"  ";
        cout<<endl;
    }
}
