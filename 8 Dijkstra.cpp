#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> >v[1000];
int d[1000];
int n;
void dij(int s)
{
    for(int i=0;i<n;i++)
    {
        d[i]=INT_MAX;
     }
    d[0]=0;
    priority_queue<pair<int,int> ,vector<pair<int,int> >, greater<pair<int, int > > >pq;
    pq.push(make_pair(0,s));
    while(!pq.empty())
    {
         pair<int,int>p=pq.top();
         int u=pq.top().second;
         pq.pop();
         for(int i=0;i<v[u].size();i++)
         {
              int w=v[u][i].second;
                 if(d[v[u][i].first]>d[u]+w)
                 {
                      d[v[u][i].first]=d[u]+w;
                      pq.push(make_pair(d[v[u][i].first],v[u][i].first));
                  }
          }
     }
}

int main()
{
    int e,a,b,w;
    cin>>n>>e;
    for(int i=0;i<e;i++)
    {
       cin>>a>>b>>w;
       v[a].push_back(make_pair(b,w));
     }
   dij(0);
   for(int i=0;i<n;i++)
   cout<<d[i]<<" ";
   cout<<endl;
}
