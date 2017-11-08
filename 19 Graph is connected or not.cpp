#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define repp(i,a,b) for(int i=a;i<=b;i++)
vector<int>v[100005];
int vis[100005];
void dfs(int s)
{
   vis[s]=1;
   for(int i=0;i<v[s].size();i++)
   {
      if(!vis[v[s][i]])
      dfs(v[s][i]);
   }
}
int main()
{
    int n,e,x,y;
    cin>>n>>e; 
    rep(i,e)
    {
      cin>>x>>y;
      v[x].push_back(y);
    }
    dfs(1);
    int f=0;
    repp(i,1,n)
    {
       if(!vis[i])
       f=1;
    }
    if(f)
    cout<<"Not Connected";
    else
    cout<<"Connected";
}   


