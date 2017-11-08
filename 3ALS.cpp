#include<bits/stdc++.h>
using namespace std;
int n,a[2][1000];
int ts[2][1000];
int e1,e2,x1,x2;
int dp[2][1000];
int calc()
{
    dp[0][0]=e1+a[0][0];
    dp[1][0]=e2+a[1][0];
    for(int i=1;i<n;i++)
    {
       dp[0][i]=min(dp[0][i-1],dp[1][i-1]+ts[1][i])+a[0][i];
       dp[1][i]=min(dp[1][i-1],dp[0][i-1]+ts[0][i])+a[1][i];
    }
    for(int i=0;i<n-1;i++)
    {
       if(dp[0][i]>dp[1][i])
       cout<<"1"<<" ";
       else
       cout<<"0"<<" ";
    }
    int ans=min(dp[0][n-1]+x1,dp[1][n-1]+x2);
    if(dp[0][n-1]+x1>dp[1][n-1]+x2)
    cout<<"1"<<" ";
    else
    cout<<"0"<<" ";
    cout<<endl;
    return ans;
}
int main()
{
   cin>>n;
   for(int i =0;i<n;i++)
   cin>>a[0][i];
   for(int i=0;i<n;i++)
   cin>>a[1][i];
   for(int i =1;i<n;i++)
   cin>>ts[0][i];
   for(int i=1;i<n;i++)
   cin>>ts[1][i];
   cin>>e1>>e2>>x1>>x2;
   int ans=calc();
   cout<<ans;
 }
