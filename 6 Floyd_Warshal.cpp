
#include<bits/stdc++.h>
using namespace std;
int dist[1000][1000];
int graph[1000][1000];
int n,e;
void floydWarshall ()
{
    int i, j, k;
    for (i = 0; i < e; i++)
        for (j = 0; j < e; j++)
            dist[i][j] = graph[i][j];
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
   for(int i=0;i<n;i++)
   {
      for(int j=0;j<n;j++)
      {
          cout<<dist[i][j]<<" ";
       }
     cout<<endl;
   }
}
int main()
{
    cin>>n>>e;
   for(int i=0;i<n;i++)
   {
      for(int j=0;j<n;j++)
      {
          cin>>graph[i][j];
       }
   }
   floydWarshall();
}
