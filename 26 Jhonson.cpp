#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,e;
    cout<<"Enter number of vertices: ";
    cin>>n;
    cout<<"Enter number of edges: ";
    cin>>e;
     vector<vector<pair<int,int> > > g(n);
    int h[n];
   
    cout<<"Enter vertex weights: "<<endl;
   
    for(int i=0;i<n;i++)
    cin>>h[i];
    int u,v,w;
    cout<<"Enter graph:"<<endl;
    for(int i=0;i<e;i++)
    {
        cin>>u>>v>>w;
        g[u].push_back(make_pair(v,w + h[u]-h[v]));
    }
 /*   for(int i=0;i<n;i++)
    {
       for(int j=0;j<g[i].size();j++)
       cout<<g[i][j].first<<" "<<"vai "<<g[i][j].second<<" ";
       cout<<endl;
     }
     */
    for(int i=0;i<n;i++)
    {
        int s = i;
       
        priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
        vector<int> dist(n);
       
        for(int j=0;j<n;j++)
        dist[j] = INT_MAX;
       
        dist[s] = 0;
        pq.push(make_pair(dist[s],s));
       
        while(!pq.empty())
        {
            pair<int,int> t = pq.top();
            pq.pop();
           
            int u = t.second;
            
            for(int k=0;k<g[u].size();k++)
            {
                int v = g[u][k].first;
                int w = g[u][k].second;
               
                if(dist[v] > dist[u]+w)
                {
                    dist[v] = dist[u] + w;
                    pq.push(make_pair(dist[u]+w,v));
                }
            }
        }
       
        cout<<"shortest distance from source "<<s<<":"<<endl;
       
        for(int i=0;i<n;i++)
        {
            if(dist[i]==INT_MAX)
            cout<<"inf ";
            else
            cout<<dist[i]<<" ";
        }
       
        cout<<endl;
    }
}
