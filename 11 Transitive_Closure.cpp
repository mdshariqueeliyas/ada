#include<bits/stdc++.h>
using namespace std;
int graph[105][105],n;
int a[105][105];
void solve()
{
     int i, j, k;
     for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            a[i][j] = graph[i][j];
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                a[i][j] = a[i][j] || (a[i][k] && a[k][j]);
            }
        }
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
       for(int j=0;j<n;j++)
       {
             cin>>graph[i][j];
       }
     }
   solve();
   for(int i=0;i<n;i++)
   {
      for(int j=0;j<n;j++)
      {
             cout<<a[i][j]<<"  ";
       }
      cout<<endl;
    }
}
