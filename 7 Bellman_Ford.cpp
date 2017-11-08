#include<bits/stdc++.h>
using namespace std;
int dist[1000];
vector<pair<int,pair<int, int> > > vec;
int n,e;
void BellmanFord(int src)
{

    for (int i = 0; i < n; i++)
        dist[i]   = INT_MAX;
    dist[src] = 0;
    for (int i = 1; i <= n-1; i++)
    {
        for (int j = 0; j <e; j++)
        {
            int u = vec[j].first;
            int v = vec[j].second.first;
            int weight = vec[j].second.second;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    for (int i = 0; i < e; i++)
    {
         int u = vec[i].first;
            int v = vec[i].second.first;
            int weight = vec[i].second.second;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
            printf("Graph contains negative weight cycle");
    }
 
   for(int i=0;i<n;i++)
   cout<<dist[i]<<" ";
 
    return;
}
 
int main()
{
  cin>>n>>e;
  int a,b,w;
  for(int i=0;i<e;i++)
  {
     cin>>a>>b>>w;
     vec.push_back(make_pair(a,make_pair(b,w) ) );
   }
  BellmanFord(0);
}
