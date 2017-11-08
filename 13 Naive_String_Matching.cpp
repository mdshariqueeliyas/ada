#include<bits/stdc++.h>
using namespace std;
int main()
{
     string text,pat;
     int n,m;
     cin>>text>>pat;
     n=text.size();
     m=pat.size();
     int i,j;
     for(i=0;i<n-m;i++)
     {
        for(j=0;j<m;j++)
        {
           if(pat[j]!=text[i+j])
           break;
         }
   if(j==m)
    {
     cout<<"text found = "<<i<<endl;
     return 0;
    }
  }
  cout<<"No match";
}
