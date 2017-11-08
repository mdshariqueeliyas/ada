#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define ll long long int
vector<pair<int,int> >v[5005];
int vis[5005],n;
stack<int>st;
int dist[5005];
void topo(int s)
{
     vis[s]=1;
     for(int i=0;i<v[s].size();i++)
     {
        if(!vis[v[s][i].first])
        topo(v[s][i].first);
      }
  st.push(s);
}
void solve(int s)
{
      for (int i = 0; i < n; i++)
      dist[i] = -1005;
      dist[s] = 0;
      
      while (!st.empty())
      {
        int u = st.top();
        //cout<<u<<endl;
        st.pop();
        if (dist[u] != -1005)
        {
          for (int i=0;i<v[u].size();i++)
             if (dist[v[u][i].first] < dist[u] + v[u][i].second)
                dist[v[u][i].first] = dist[u] + v[u][i].second;
        }
      }
 
    for (int i = 0; i < n; i++)
        (dist[i] == -1005)? cout << -1005: cout << dist[i] << " ";
        
}
 
int main()
{
  int e,a,b,w;
  cin>>n>>e;
  rep(i,e)
  {
    cin>>a>>b>>w;
    v[a].push_back(make_pair(b,w));
  }
  rep(i,n)
  {
      if(!vis[i])
      topo(i);
  }
  solve(0);
 
}

