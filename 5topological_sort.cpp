#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define ll long long int
vector<int>v[5005];
int vis[5005];
stack<int>st;
void topo(int s)
{
     vis[s]=1;
     for(auto i : v[s])
     {
        if(!vis[i])
        topo(i);
	 }
	 st.push(s);
}
int main()
{
	int n,e,a,b;
	cin>>n>>e;
	rep(i,e)
	{
	   cin>>a>>b;
	   v[a].push_back(b);
	}
	rep(i,n)
	{
      	if(!vis[i])
      	topo(i);
	}
	while(!st.empty())
	{
	   cout<<st.top()<<" ";
	   st.pop();
	}
}

